/*
 * openloop.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "openloop".
 *
 * Model version              : 1.9
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Thu Aug  4 09:21:51 2022
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "openloop.h"
#include "openloop_private.h"
#include "openloop_dt.h"

/* Block signals (default storage) */
B_openloop_T openloop_B;

/* Block states (default storage) */
DW_openloop_T openloop_DW;

/* Real-time model */
static RT_MODEL_openloop_T openloop_M_;
RT_MODEL_openloop_T *const openloop_M = &openloop_M_;

/* Forward declaration for local functions */
static void openloop_SystemCore_release(codertarget_arduinobase_int_a_T *obj);
static void openloop_SystemCore_release(codertarget_arduinobase_int_a_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(obj->PinPWM);
    MW_PWM_SetDutyCycle(obj->MW_PWM_HANDLE, -0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(obj->PinPWM);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

/* Model step function */
void openloop_step(void)
{
  codertarget_arduinobase_int_a_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  real_T u0;
  uint16_T rtb_AnalogInput_0;

  /* MATLABSystem: '<Root>/Analog Input' */
  if (openloop_DW.obj_h.SampleTime != openloop_P.AnalogInput_SampleTime) {
    openloop_DW.obj_h.SampleTime = openloop_P.AnalogInput_SampleTime;
  }

  obj = &openloop_DW.obj_h;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(18UL);
  MW_AnalogInSingle_ReadResult
    (openloop_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_AnalogInput_0,
     3);

  /* Gain: '<Root>/Gain2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Gain: '<Root>/Gain'
   *  MATLABSystem: '<Root>/Analog Input'
   */
  openloop_B.Gain2 = (real_T)((uint32_T)openloop_P.Gain_Gain * rtb_AnalogInput_0)
    * 1.1920928955078125E-7 * openloop_P.Gain2_Gain;

  /* MATLABSystem: '<Root>/Analog Input2' */
  if (openloop_DW.obj.SampleTime != openloop_P.AnalogInput2_SampleTime) {
    openloop_DW.obj.SampleTime = openloop_P.AnalogInput2_SampleTime;
  }

  obj = &openloop_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(19UL);
  MW_AnalogInSingle_ReadResult
    (openloop_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_AnalogInput_0, 3);

  /* Gain: '<Root>/Gain3' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain1'
   *  MATLABSystem: '<Root>/Analog Input2'
   *  Sum: '<Root>/Sum1'
   */
  openloop_B.DataTypeConversion1 = ((real_T)((uint32_T)openloop_P.Gain1_Gain *
    rtb_AnalogInput_0) * 1.1920928955078125E-7 - openloop_P.Constant_Value) *
    openloop_P.Gain3_Gain;

  /* Saturate: '<Root>/Saturation1' */
  if (openloop_B.DataTypeConversion1 > openloop_P.Saturation1_UpperSat) {
    /* Gain: '<Root>/Gain3' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion1'
     */
    openloop_B.DataTypeConversion1 = openloop_P.Saturation1_UpperSat;
  } else {
    if (openloop_B.DataTypeConversion1 < openloop_P.Saturation1_LowerSat) {
      /* Gain: '<Root>/Gain3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion1'
       */
      openloop_B.DataTypeConversion1 = openloop_P.Saturation1_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* MATLABSystem: '<Root>/PWM' */
  obj_0 = &openloop_DW.obj_p;

  /* Gain: '<S1>/Slider Gain' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  u0 = openloop_P.SliderGain_gain * openloop_P.Constant1_Value;

  /* MATLABSystem: '<Root>/PWM' */
  if (!(u0 < 255.0)) {
    u0 = 255.0;
  }

  obj_0->MW_PWM_HANDLE = MW_PWM_GetHandle(openloop_DW.obj_p.PinPWM);
  if (!(u0 > 0.0)) {
    u0 = 0.0;
  }

  MW_PWM_SetDutyCycle(openloop_DW.obj_p.MW_PWM_HANDLE, -(u0 * 255.0 / 255.0));

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.2s, 0.0s] */
    rtExtModeUpload(0, (real_T)openloop_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.2s, 0.0s] */
    if ((rtmGetTFinal(openloop_M)!=-1) &&
        !((rtmGetTFinal(openloop_M)-openloop_M->Timing.taskTime0) >
          openloop_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(openloop_M, "Simulation finished");
    }

    if (rtmGetStopRequested(openloop_M)) {
      rtmSetErrorStatus(openloop_M, "Simulation finished");
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
  if (!(++openloop_M->Timing.clockTick0)) {
    ++openloop_M->Timing.clockTickH0;
  }

  openloop_M->Timing.taskTime0 = openloop_M->Timing.clockTick0 *
    openloop_M->Timing.stepSize0 + openloop_M->Timing.clockTickH0 *
    openloop_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void openloop_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)openloop_M, 0,
                sizeof(RT_MODEL_openloop_T));
  rtmSetTFinal(openloop_M, -1);
  openloop_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  openloop_M->Sizes.checksums[0] = (1110955545U);
  openloop_M->Sizes.checksums[1] = (1942524069U);
  openloop_M->Sizes.checksums[2] = (254484282U);
  openloop_M->Sizes.checksums[3] = (80300889U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    openloop_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(openloop_M->extModeInfo,
      &openloop_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(openloop_M->extModeInfo, openloop_M->Sizes.checksums);
    rteiSetTPtr(openloop_M->extModeInfo, rtmGetTPtr(openloop_M));
  }

  /* block I/O */
  (void) memset(((void *) &openloop_B), 0,
                sizeof(B_openloop_T));

  /* states (dwork) */
  (void) memset((void *)&openloop_DW, 0,
                sizeof(DW_openloop_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    openloop_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    codertarget_arduinobase_int_a_T *obj_0;
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    openloop_DW.obj_h.matlabCodegenIsDeleted = true;
    openloop_DW.obj_h.isInitialized = 0L;
    openloop_DW.obj_h.SampleTime = -1.0;
    openloop_DW.obj_h.matlabCodegenIsDeleted = false;
    openloop_DW.objisempty_g = true;
    openloop_DW.obj_h.SampleTime = openloop_P.AnalogInput_SampleTime;
    obj = &openloop_DW.obj_h;
    openloop_DW.obj_h.isSetupComplete = false;
    openloop_DW.obj_h.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(18UL);
    openloop_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input2' */
    openloop_DW.obj.matlabCodegenIsDeleted = true;
    openloop_DW.obj.isInitialized = 0L;
    openloop_DW.obj.SampleTime = -1.0;
    openloop_DW.obj.matlabCodegenIsDeleted = false;
    openloop_DW.objisempty_a = true;
    openloop_DW.obj.SampleTime = openloop_P.AnalogInput2_SampleTime;
    obj = &openloop_DW.obj;
    openloop_DW.obj.isSetupComplete = false;
    openloop_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(19UL);
    openloop_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM' */
    openloop_DW.obj_p.matlabCodegenIsDeleted = true;
    openloop_DW.obj_p.isInitialized = 0L;
    openloop_DW.obj_p.matlabCodegenIsDeleted = false;
    openloop_DW.objisempty = true;
    openloop_DW.obj_p.PinPWM = 11UL;
    obj_0 = &openloop_DW.obj_p;
    openloop_DW.obj_p.isSetupComplete = false;
    openloop_DW.obj_p.isInitialized = 1L;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(openloop_DW.obj_p.PinPWM, 2.0, 255.0);
    obj_0->MW_PWM_HANDLE = MW_PWM_GetHandle(openloop_DW.obj_p.PinPWM);
    MW_PWM_Start(openloop_DW.obj_p.MW_PWM_HANDLE);
    openloop_DW.obj_p.isSetupComplete = true;
  }
}

/* Model terminate function */
void openloop_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  obj = &openloop_DW.obj_h;
  if (!openloop_DW.obj_h.matlabCodegenIsDeleted) {
    openloop_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((openloop_DW.obj_h.isInitialized == 1L) &&
        openloop_DW.obj_h.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(18UL);
      MW_AnalogIn_Close(obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input2' */
  obj = &openloop_DW.obj;
  if (!openloop_DW.obj.matlabCodegenIsDeleted) {
    openloop_DW.obj.matlabCodegenIsDeleted = true;
    if ((openloop_DW.obj.isInitialized == 1L) && openloop_DW.obj.isSetupComplete)
    {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(19UL);
      MW_AnalogIn_Close(obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input2' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!openloop_DW.obj_p.matlabCodegenIsDeleted) {
    openloop_DW.obj_p.matlabCodegenIsDeleted = true;
    openloop_SystemCore_release(&openloop_DW.obj_p);
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
}
