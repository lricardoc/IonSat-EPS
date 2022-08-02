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
 * C source code generated on : Tue Aug  2 11:44:46 2022
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

/* Block signals (default storage) */
B_untitled2_T untitled2_B;

/* Block states (default storage) */
DW_untitled2_T untitled2_DW;

/* Real-time model */
static RT_MODEL_untitled2_T untitled2_M_;
RT_MODEL_untitled2_T *const untitled2_M = &untitled2_M_;

/* Forward declaration for local functions */
static void untitled2_SystemCore_release(codertarget_arduinobase_int_i_T *obj);
static void untitled2_SystemCore_release(codertarget_arduinobase_int_i_T *obj)
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
  codertarget_arduinobase_int_i_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  real_T u0;
  uint16_T rtb_AnalogInput_0;

  /* MATLABSystem: '<Root>/Analog Input' */
  if (untitled2_DW.obj_h.SampleTime != untitled2_P.AnalogInput_SampleTime) {
    untitled2_DW.obj_h.SampleTime = untitled2_P.AnalogInput_SampleTime;
  }

  obj = &untitled2_DW.obj_h;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(18UL);
  MW_AnalogInSingle_ReadResult
    (untitled2_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_AnalogInput_0,
     3);

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Gain: '<Root>/Gain'
   *  MATLABSystem: '<Root>/Analog Input'
   */
  untitled2_B.DataTypeConversion = (real_T)((uint32_T)untitled2_P.Gain_Gain *
    rtb_AnalogInput_0) * 1.1920928955078125E-7;

  /* MATLABSystem: '<Root>/Analog Input2' */
  if (untitled2_DW.obj.SampleTime != untitled2_P.AnalogInput2_SampleTime) {
    untitled2_DW.obj.SampleTime = untitled2_P.AnalogInput2_SampleTime;
  }

  obj = &untitled2_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(19UL);
  MW_AnalogInSingle_ReadResult
    (untitled2_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_AnalogInput_0,
     3);

  /* Gain: '<Root>/Gain3' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain1'
   *  MATLABSystem: '<Root>/Analog Input2'
   *  Sum: '<Root>/Sum1'
   */
  untitled2_B.DataTypeConversion1 = ((real_T)((uint32_T)untitled2_P.Gain1_Gain *
    rtb_AnalogInput_0) * 1.1920928955078125E-7 - untitled2_P.Constant_Value) *
    untitled2_P.Gain3_Gain;

  /* Saturate: '<Root>/Saturation1' */
  if (untitled2_B.DataTypeConversion1 > untitled2_P.Saturation1_UpperSat) {
    /* Gain: '<Root>/Gain3' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion1'
     */
    untitled2_B.DataTypeConversion1 = untitled2_P.Saturation1_UpperSat;
  } else {
    if (untitled2_B.DataTypeConversion1 < untitled2_P.Saturation1_LowerSat) {
      /* Gain: '<Root>/Gain3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion1'
       */
      untitled2_B.DataTypeConversion1 = untitled2_P.Saturation1_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* MATLABSystem: '<Root>/PWM' */
  obj_0 = &untitled2_DW.obj_p;

  /* Gain: '<S1>/Slider Gain' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  u0 = untitled2_P.SliderGain_gain * untitled2_P.Constant1_Value;

  /* MATLABSystem: '<Root>/PWM' */
  if (!(u0 < 255.0)) {
    u0 = 255.0;
  }

  obj_0->MW_PWM_HANDLE = MW_PWM_GetHandle(untitled2_DW.obj_p.PinPWM);
  if (!(u0 > 0.0)) {
    u0 = 0.0;
  }

  MW_PWM_SetDutyCycle(untitled2_DW.obj_p.MW_PWM_HANDLE, -(u0 * 255.0 / 255.0));

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
  untitled2_M->Sizes.checksums[0] = (3395530146U);
  untitled2_M->Sizes.checksums[1] = (980422992U);
  untitled2_M->Sizes.checksums[2] = (4018196740U);
  untitled2_M->Sizes.checksums[3] = (1187743580U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    untitled2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled2_M->extModeInfo,
      &untitled2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled2_M->extModeInfo, untitled2_M->Sizes.checksums);
    rteiSetTPtr(untitled2_M->extModeInfo, rtmGetTPtr(untitled2_M));
  }

  /* block I/O */
  (void) memset(((void *) &untitled2_B), 0,
                sizeof(B_untitled2_T));

  /* states (dwork) */
  (void) memset((void *)&untitled2_DW, 0,
                sizeof(DW_untitled2_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    untitled2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    codertarget_arduinobase_int_i_T *obj_0;
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    untitled2_DW.obj_h.matlabCodegenIsDeleted = true;
    untitled2_DW.obj_h.isInitialized = 0L;
    untitled2_DW.obj_h.SampleTime = -1.0;
    untitled2_DW.obj_h.matlabCodegenIsDeleted = false;
    untitled2_DW.objisempty_g = true;
    untitled2_DW.obj_h.SampleTime = untitled2_P.AnalogInput_SampleTime;
    obj = &untitled2_DW.obj_h;
    untitled2_DW.obj_h.isSetupComplete = false;
    untitled2_DW.obj_h.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(18UL);
    untitled2_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input2' */
    untitled2_DW.obj.matlabCodegenIsDeleted = true;
    untitled2_DW.obj.isInitialized = 0L;
    untitled2_DW.obj.SampleTime = -1.0;
    untitled2_DW.obj.matlabCodegenIsDeleted = false;
    untitled2_DW.objisempty_a = true;
    untitled2_DW.obj.SampleTime = untitled2_P.AnalogInput2_SampleTime;
    obj = &untitled2_DW.obj;
    untitled2_DW.obj.isSetupComplete = false;
    untitled2_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(19UL);
    untitled2_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM' */
    untitled2_DW.obj_p.matlabCodegenIsDeleted = true;
    untitled2_DW.obj_p.isInitialized = 0L;
    untitled2_DW.obj_p.matlabCodegenIsDeleted = false;
    untitled2_DW.objisempty = true;
    untitled2_DW.obj_p.PinPWM = 11UL;
    obj_0 = &untitled2_DW.obj_p;
    untitled2_DW.obj_p.isSetupComplete = false;
    untitled2_DW.obj_p.isInitialized = 1L;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(untitled2_DW.obj_p.PinPWM, 2.0, 255.0);
    obj_0->MW_PWM_HANDLE = MW_PWM_GetHandle(untitled2_DW.obj_p.PinPWM);
    MW_PWM_Start(untitled2_DW.obj_p.MW_PWM_HANDLE);
    untitled2_DW.obj_p.isSetupComplete = true;
  }
}

/* Model terminate function */
void untitled2_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  obj = &untitled2_DW.obj_h;
  if (!untitled2_DW.obj_h.matlabCodegenIsDeleted) {
    untitled2_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((untitled2_DW.obj_h.isInitialized == 1L) &&
        untitled2_DW.obj_h.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(18UL);
      MW_AnalogIn_Close(obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input2' */
  obj = &untitled2_DW.obj;
  if (!untitled2_DW.obj.matlabCodegenIsDeleted) {
    untitled2_DW.obj.matlabCodegenIsDeleted = true;
    if ((untitled2_DW.obj.isInitialized == 1L) &&
        untitled2_DW.obj.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(19UL);
      MW_AnalogIn_Close(obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input2' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!untitled2_DW.obj_p.matlabCodegenIsDeleted) {
    untitled2_DW.obj_p.matlabCodegenIsDeleted = true;
    untitled2_SystemCore_release(&untitled2_DW.obj_p);
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
}
