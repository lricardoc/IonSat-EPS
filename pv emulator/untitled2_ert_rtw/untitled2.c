/*
 * untitled2.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "untitled2".
 *
 * Model version              : 1.3
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Thu Aug  4 17:49:10 2022
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled2.h"
#include "untitled2_private.h"
#include "untitled2_dt.h"

/* Block states (default storage) */
DW_untitled2_T untitled2_DW;

/* Real-time model */
static RT_MODEL_untitled2_T untitled2_M_;
RT_MODEL_untitled2_T *const untitled2_M = &untitled2_M_;

/* Forward declaration for local functions */
static void untitled2_SystemCore_release(codertarget_arduinobase_inter_T *obj);
static void untitled2_SystemCore_release(codertarget_arduinobase_inter_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(obj->PinPWM);
    MW_PWM_SetDutyCycle(obj->MW_PWM_HANDLE, -0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(obj->PinPWM);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

/* Model step function */
void untitled2_step(void)
{
  codertarget_arduinobase_inter_T *obj;
  real_T y;

  /* MATLABSystem: '<Root>/PWM' incorporates:
   *  Constant: '<Root>/Constant'
   */
  obj = &untitled2_DW.obj;
  if (untitled2_P.Constant_Value < 255.0) {
    y = untitled2_P.Constant_Value;
  } else {
    y = 255.0;
  }

  obj->MW_PWM_HANDLE = MW_PWM_GetHandle(untitled2_DW.obj.PinPWM);
  if (!(y > 0.0)) {
    y = 0.0;
  }

  MW_PWM_SetDutyCycle(untitled2_DW.obj.MW_PWM_HANDLE, -(y * 255.0 / 255.0));

  /* End of MATLABSystem: '<Root>/PWM' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.2s, 0.0s] */
    rtExtModeUpload(0, (real_T)untitled2_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.2s, 0.0s] */
    if ((rtmGetTFinal(untitled2_M)!=-1) &&
        !((rtmGetTFinal(untitled2_M)-untitled2_M->Timing.taskTime0) >
          untitled2_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(untitled2_M, "Simulation finished");
    }

    if (rtmGetStopRequested(untitled2_M)) {
      rtmSetErrorStatus(untitled2_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++untitled2_M->Timing.clockTick0)) {
    ++untitled2_M->Timing.clockTickH0;
  }

  untitled2_M->Timing.taskTime0 = untitled2_M->Timing.clockTick0 *
    untitled2_M->Timing.stepSize0 + untitled2_M->Timing.clockTickH0 *
    untitled2_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void untitled2_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)untitled2_M, 0,
                sizeof(RT_MODEL_untitled2_T));
  rtmSetTFinal(untitled2_M, -1);
  untitled2_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  untitled2_M->Sizes.checksums[0] = (1347239210U);
  untitled2_M->Sizes.checksums[1] = (716849432U);
  untitled2_M->Sizes.checksums[2] = (1553421174U);
  untitled2_M->Sizes.checksums[3] = (621241239U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    untitled2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled2_M->extModeInfo,
      &untitled2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled2_M->extModeInfo, untitled2_M->Sizes.checksums);
    rteiSetTPtr(untitled2_M->extModeInfo, rtmGetTPtr(untitled2_M));
  }

  /* states (dwork) */
  (void) memset((void *)&untitled2_DW, 0,
                sizeof(DW_untitled2_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    untitled2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<Root>/PWM' */
    untitled2_DW.obj.matlabCodegenIsDeleted = true;
    untitled2_DW.obj.isInitialized = 0L;
    untitled2_DW.obj.matlabCodegenIsDeleted = false;
    untitled2_DW.objisempty = true;
    untitled2_DW.obj.PinPWM = 11UL;
    obj = &untitled2_DW.obj;
    untitled2_DW.obj.isSetupComplete = false;
    untitled2_DW.obj.isInitialized = 1L;
    obj->MW_PWM_HANDLE = MW_PWM_Open(untitled2_DW.obj.PinPWM, 2.0, 255.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(untitled2_DW.obj.PinPWM);
    MW_PWM_Start(untitled2_DW.obj.MW_PWM_HANDLE);
    untitled2_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void untitled2_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!untitled2_DW.obj.matlabCodegenIsDeleted) {
    untitled2_DW.obj.matlabCodegenIsDeleted = true;
    untitled2_SystemCore_release(&untitled2_DW.obj);
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
}
