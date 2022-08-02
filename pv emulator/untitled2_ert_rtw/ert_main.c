#include "untitled2.h"
#include "rtwtypes.h"
#include <ext_work.h>
#include <ext_svr.h>
#include <ext_share.h>
#include <updown.h>

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  untitled2_step();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  cli();

#endif;

  OverrunFlag--;
  rtExtModeCheckEndTrigger();
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.2;
  float systemClock = 0;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(untitled2_M, 0);

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  untitled2_initialize();
  cli();
  sei ();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(untitled2_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(untitled2_M->extModeInfo, 1, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(untitled2_M, true);
    }
  }

  rtERTExtModeStartMsg();
  cli();
  configureArduinoAVRTimer();
  runModel =
    (rtmGetErrorStatus(untitled2_M) == (NULL)) && !rtmGetStopRequested
    (untitled2_M);

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  sei ();
  while (runModel) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(untitled2_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(untitled2_M, true);
      }
    }

    stopRequested = !(
                      (rtmGetErrorStatus(untitled2_M) == (NULL)) &&
                      !rtmGetStopRequested(untitled2_M));
    runModel = !(stopRequested);
    MW_Arduino_Loop();
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  untitled2_terminate();
  rtExtModeShutdown(1);
  cli();
  return 0;
}
