/*
 * closedloop.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "closedloop".
 *
 * Model version              : 1.3
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Tue Aug  2 11:43:01 2022
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "closedloop.h"
#include "closedloop_private.h"
#include "closedloop_dt.h"

/* Block signals (default storage) */
B_closedloop_T closedloop_B;

/* Continuous states */
X_closedloop_T closedloop_X;

/* Block states (default storage) */
DW_closedloop_T closedloop_DW;

/* Real-time model */
static RT_MODEL_closedloop_T closedloop_M_;
RT_MODEL_closedloop_T *const closedloop_M = &closedloop_M_;

/* Forward declaration for local functions */
static void closedloop_SystemCore_release(codertarget_arduinobase_int_b_T *obj);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  closedloop_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  closedloop_step();
  closedloop_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  closedloop_step();
  closedloop_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

static void closedloop_SystemCore_release(codertarget_arduinobase_int_b_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(obj->PinPWM);
    MW_PWM_SetDutyCycle(obj->MW_PWM_HANDLE, -0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(obj->PinPWM);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

/* Model step function */
void closedloop_step(void)
{
  codertarget_arduinobase_int_b_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  real_T Isc_T;
  real_T rtb_Sum;
  real_T rtb_Sum_tmp;
  real_T vt;
  uint16_T rtb_AnalogInput2_0;
  uint16_T rtb_AnalogInput_0;
  if (rtmIsMajorTimeStep(closedloop_M)) {
    /* set solver stop time */
    if (!(closedloop_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&closedloop_M->solverInfo,
                            ((closedloop_M->Timing.clockTickH0 + 1) *
        closedloop_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&closedloop_M->solverInfo,
                            ((closedloop_M->Timing.clockTick0 + 1) *
        closedloop_M->Timing.stepSize0 + closedloop_M->Timing.clockTickH0 *
        closedloop_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(closedloop_M)) {
    closedloop_M->Timing.t[0] = rtsiGetT(&closedloop_M->solverInfo);
  }

  /* MATLABSystem: '<Root>/Analog Input' */
  if (closedloop_DW.obj_g.SampleTime != closedloop_P.AnalogInput_SampleTime) {
    closedloop_DW.obj_g.SampleTime = closedloop_P.AnalogInput_SampleTime;
  }

  obj = &closedloop_DW.obj_g;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(18UL);
  MW_AnalogInSingle_ReadResult
    (closedloop_DW.obj_g.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &rtb_AnalogInput_0, 3);

  /* MATLABSystem: '<Root>/Analog Input2' */
  if (closedloop_DW.obj.SampleTime != closedloop_P.AnalogInput2_SampleTime) {
    closedloop_DW.obj.SampleTime = closedloop_P.AnalogInput2_SampleTime;
  }

  obj = &closedloop_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(19UL);
  MW_AnalogInSingle_ReadResult
    (closedloop_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_AnalogInput2_0,
     3);

  /* Gain: '<Root>/Gain3' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain1'
   *  MATLABSystem: '<Root>/Analog Input2'
   *  Sum: '<Root>/Sum1'
   */
  rtb_Sum = ((real_T)((uint32_T)closedloop_P.Gain1_Gain * rtb_AnalogInput2_0) *
             1.1920928955078125E-7 - closedloop_P.Constant_Value_c) *
    closedloop_P.Gain3_Gain;

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_Sum > closedloop_P.Saturation1_UpperSat) {
    rtb_Sum = closedloop_P.Saturation1_UpperSat;
  } else {
    if (rtb_Sum < closedloop_P.Saturation1_LowerSat) {
      rtb_Sum = closedloop_P.Saturation1_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* InitialCondition: '<S2>/IC' */
  vt = closedloop_M->Timing.t[0];
  if ((closedloop_DW.IC_FirstOutputTime == (rtMinusInf)) ||
      (closedloop_DW.IC_FirstOutputTime == vt)) {
    closedloop_DW.IC_FirstOutputTime = vt;

    /* InitialCondition: '<S2>/IC' */
    closedloop_B.IC = closedloop_P.IC_Value;
  } else {
    /* InitialCondition: '<S2>/IC' */
    closedloop_B.IC = rtb_Sum;
  }

  /* End of InitialCondition: '<S2>/IC' */

  /* MATLAB Function: '<S2>/PV Module Mathematical Model' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant3'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant6'
   *  Constant: '<S2>/Constant9'
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Gain: '<Root>/Gain'
   *  MATLABSystem: '<Root>/Analog Input'
   */
  vt = closedloop_P.Constant3_Value * 1.38E-23 * (closedloop_P.Constant9_Value +
    273.0) * closedloop_P.Constant6_Value / 1.6E-19;
  Isc_T = closedloop_P.Constant1_Value / 100.0 * closedloop_P.Constant_Value *
    (closedloop_P.Constant9_Value - 25.0) + closedloop_P.Constant_Value;
  rtb_Sum_tmp = closedloop_B.IC * closedloop_P.Constant4_Value + (real_T)
    ((uint32_T)closedloop_P.Gain_Gain * rtb_AnalogInput_0) * 4.76837158203125E-7;

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant5'
   *  Constant: '<S2>/Constant7'
   *  Constant: '<S2>/Constant8'
   *  Constant: '<S2>/Constant9'
   *  MATLAB Function: '<S2>/PV Module Mathematical Model'
   */
  rtb_Sum = ((closedloop_P.Constant8_Value / 1000.0 * Isc_T - Isc_T / (exp
    ((closedloop_P.Constant7_Value / 100.0 * closedloop_P.Constant2_Value *
      (closedloop_P.Constant9_Value - 25.0) + closedloop_P.Constant2_Value) / vt)
    - 1.0) * (exp(rtb_Sum_tmp / vt) - 1.0)) - rtb_Sum_tmp /
             closedloop_P.Constant5_Value) - rtb_Sum;

  /* MATLABSystem: '<Root>/PWM' */
  obj_0 = &closedloop_DW.obj_j;

  /* Sum: '<S43>/Sum' incorporates:
   *  Gain: '<S39>/Proportional Gain'
   *  Integrator: '<S34>/Integrator'
   */
  vt = closedloop_P.PIDController_P * rtb_Sum + closedloop_X.Integrator_CSTATE;

  /* Saturate: '<S41>/Saturation' */
  if (vt > closedloop_P.PIDController_UpperSaturationLi) {
    vt = closedloop_P.PIDController_UpperSaturationLi;
  } else {
    if (vt < closedloop_P.PIDController_LowerSaturationLi) {
      vt = closedloop_P.PIDController_LowerSaturationLi;
    }
  }

  /* End of Saturate: '<S41>/Saturation' */

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Gain: '<Root>/Gain2'
   */
  vt = floor(closedloop_P.Gain2_Gain * vt);
  if (rtIsNaN(vt) || rtIsInf(vt)) {
    vt = 0.0;
  } else {
    vt = fmod(vt, 65536.0);
  }

  /* MATLABSystem: '<Root>/PWM' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  vt = vt < 0.0 ? -(int16_T)(uint16_T)-vt : (int16_T)(uint16_T)vt;
  if (!(vt < 255.0)) {
    vt = 255.0;
  }

  obj_0->MW_PWM_HANDLE = MW_PWM_GetHandle(closedloop_DW.obj_j.PinPWM);
  if (!(vt > 0.0)) {
    vt = 0.0;
  }

  MW_PWM_SetDutyCycle(closedloop_DW.obj_j.MW_PWM_HANDLE, -(vt * 255.0 / 255.0));

  /* Gain: '<S31>/Integral Gain' */
  closedloop_B.IntegralGain = closedloop_P.PIDController_I * rtb_Sum;
  if (rtmIsMajorTimeStep(closedloop_M)) {
    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, (real_T)closedloop_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(closedloop_M)) {/* Sample time: [0.2s, 0.0s] */
      rtExtModeUpload(1, (real_T)(((closedloop_M->Timing.clockTick1+
        closedloop_M->Timing.clockTickH1* 4294967296.0)) * 0.2));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(closedloop_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(closedloop_M)!=-1) &&
          !((rtmGetTFinal(closedloop_M)-(((closedloop_M->Timing.clockTick1+
               closedloop_M->Timing.clockTickH1* 4294967296.0)) * 0.2)) >
            (((closedloop_M->Timing.clockTick1+closedloop_M->Timing.clockTickH1*
               4294967296.0)) * 0.2) * (DBL_EPSILON))) {
        rtmSetErrorStatus(closedloop_M, "Simulation finished");
      }

      if (rtmGetStopRequested(closedloop_M)) {
        rtmSetErrorStatus(closedloop_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&closedloop_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++closedloop_M->Timing.clockTick0)) {
      ++closedloop_M->Timing.clockTickH0;
    }

    closedloop_M->Timing.t[0] = rtsiGetSolverStopTime(&closedloop_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.2s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.2, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      closedloop_M->Timing.clockTick1++;
      if (!closedloop_M->Timing.clockTick1) {
        closedloop_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void closedloop_derivatives(void)
{
  XDot_closedloop_T *_rtXdot;
  _rtXdot = ((XDot_closedloop_T *) closedloop_M->derivs);

  /* Derivatives for Integrator: '<S34>/Integrator' */
  _rtXdot->Integrator_CSTATE = closedloop_B.IntegralGain;
}

/* Model initialize function */
void closedloop_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)closedloop_M, 0,
                sizeof(RT_MODEL_closedloop_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&closedloop_M->solverInfo,
                          &closedloop_M->Timing.simTimeStep);
    rtsiSetTPtr(&closedloop_M->solverInfo, &rtmGetTPtr(closedloop_M));
    rtsiSetStepSizePtr(&closedloop_M->solverInfo,
                       &closedloop_M->Timing.stepSize0);
    rtsiSetdXPtr(&closedloop_M->solverInfo, &closedloop_M->derivs);
    rtsiSetContStatesPtr(&closedloop_M->solverInfo, (real_T **)
                         &closedloop_M->contStates);
    rtsiSetNumContStatesPtr(&closedloop_M->solverInfo,
      &closedloop_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&closedloop_M->solverInfo,
      &closedloop_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&closedloop_M->solverInfo,
      &closedloop_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&closedloop_M->solverInfo,
      &closedloop_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&closedloop_M->solverInfo, (&rtmGetErrorStatus
      (closedloop_M)));
    rtsiSetRTModelPtr(&closedloop_M->solverInfo, closedloop_M);
  }

  rtsiSetSimTimeStep(&closedloop_M->solverInfo, MAJOR_TIME_STEP);
  closedloop_M->intgData.y = closedloop_M->odeY;
  closedloop_M->intgData.f[0] = closedloop_M->odeF[0];
  closedloop_M->intgData.f[1] = closedloop_M->odeF[1];
  closedloop_M->intgData.f[2] = closedloop_M->odeF[2];
  closedloop_M->contStates = ((X_closedloop_T *) &closedloop_X);
  rtsiSetSolverData(&closedloop_M->solverInfo, (void *)&closedloop_M->intgData);
  rtsiSetSolverName(&closedloop_M->solverInfo,"ode3");
  rtmSetTPtr(closedloop_M, &closedloop_M->Timing.tArray[0]);
  rtmSetTFinal(closedloop_M, -1);
  closedloop_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  closedloop_M->Sizes.checksums[0] = (3343810246U);
  closedloop_M->Sizes.checksums[1] = (1446559692U);
  closedloop_M->Sizes.checksums[2] = (1578106943U);
  closedloop_M->Sizes.checksums[3] = (3913370461U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    closedloop_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(closedloop_M->extModeInfo,
      &closedloop_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(closedloop_M->extModeInfo, closedloop_M->Sizes.checksums);
    rteiSetTPtr(closedloop_M->extModeInfo, rtmGetTPtr(closedloop_M));
  }

  /* block I/O */
  (void) memset(((void *) &closedloop_B), 0,
                sizeof(B_closedloop_T));

  /* states (continuous) */
  {
    (void) memset((void *)&closedloop_X, 0,
                  sizeof(X_closedloop_T));
  }

  /* states (dwork) */
  (void) memset((void *)&closedloop_DW, 0,
                sizeof(DW_closedloop_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    closedloop_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    codertarget_arduinobase_int_b_T *obj_0;
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    closedloop_DW.obj_g.matlabCodegenIsDeleted = true;
    closedloop_DW.obj_g.isInitialized = 0L;
    closedloop_DW.obj_g.SampleTime = -1.0;
    closedloop_DW.obj_g.matlabCodegenIsDeleted = false;
    closedloop_DW.objisempty_n = true;
    closedloop_DW.obj_g.SampleTime = closedloop_P.AnalogInput_SampleTime;
    obj = &closedloop_DW.obj_g;
    closedloop_DW.obj_g.isSetupComplete = false;
    closedloop_DW.obj_g.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(18UL);
    closedloop_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input2' */
    closedloop_DW.obj.matlabCodegenIsDeleted = true;
    closedloop_DW.obj.isInitialized = 0L;
    closedloop_DW.obj.SampleTime = -1.0;
    closedloop_DW.obj.matlabCodegenIsDeleted = false;
    closedloop_DW.objisempty_g = true;
    closedloop_DW.obj.SampleTime = closedloop_P.AnalogInput2_SampleTime;
    obj = &closedloop_DW.obj;
    closedloop_DW.obj.isSetupComplete = false;
    closedloop_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(19UL);
    closedloop_DW.obj.isSetupComplete = true;

    /* Start for InitialCondition: '<S2>/IC' */
    closedloop_B.IC = closedloop_P.IC_Value;

    /* Start for InitialCondition: '<S2>/IC' */
    closedloop_DW.IC_FirstOutputTime = (rtMinusInf);

    /* Start for MATLABSystem: '<Root>/PWM' */
    closedloop_DW.obj_j.matlabCodegenIsDeleted = true;
    closedloop_DW.obj_j.isInitialized = 0L;
    closedloop_DW.obj_j.matlabCodegenIsDeleted = false;
    closedloop_DW.objisempty = true;
    closedloop_DW.obj_j.PinPWM = 11UL;
    obj_0 = &closedloop_DW.obj_j;
    closedloop_DW.obj_j.isSetupComplete = false;
    closedloop_DW.obj_j.isInitialized = 1L;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(closedloop_DW.obj_j.PinPWM, 2.0, 255.0);
    obj_0->MW_PWM_HANDLE = MW_PWM_GetHandle(closedloop_DW.obj_j.PinPWM);
    MW_PWM_Start(closedloop_DW.obj_j.MW_PWM_HANDLE);
    closedloop_DW.obj_j.isSetupComplete = true;
  }

  /* InitializeConditions for Integrator: '<S34>/Integrator' */
  closedloop_X.Integrator_CSTATE = closedloop_P.PIDController_InitialConditionF;
}

/* Model terminate function */
void closedloop_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  obj = &closedloop_DW.obj_g;
  if (!closedloop_DW.obj_g.matlabCodegenIsDeleted) {
    closedloop_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((closedloop_DW.obj_g.isInitialized == 1L) &&
        closedloop_DW.obj_g.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(18UL);
      MW_AnalogIn_Close(obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input2' */
  obj = &closedloop_DW.obj;
  if (!closedloop_DW.obj.matlabCodegenIsDeleted) {
    closedloop_DW.obj.matlabCodegenIsDeleted = true;
    if ((closedloop_DW.obj.isInitialized == 1L) &&
        closedloop_DW.obj.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(19UL);
      MW_AnalogIn_Close(obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input2' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!closedloop_DW.obj_j.matlabCodegenIsDeleted) {
    closedloop_DW.obj_j.matlabCodegenIsDeleted = true;
    closedloop_SystemCore_release(&closedloop_DW.obj_j);
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
}
