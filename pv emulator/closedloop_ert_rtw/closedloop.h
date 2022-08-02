/*
 * closedloop.h
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

#ifndef RTW_HEADER_closedloop_h_
#define RTW_HEADER_closedloop_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef closedloop_COMMON_INCLUDES_
#define closedloop_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_AnalogIn.h"
#include "MW_PWM.h"
#endif                                 /* closedloop_COMMON_INCLUDES_ */

#include "closedloop_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T IC;                           /* '<S2>/IC' */
  real_T IntegralGain;                 /* '<S31>/Integral Gain' */
} B_closedloop_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input2' */
  codertarget_arduinobase_inter_T obj_g;/* '<Root>/Analog Input' */
  codertarget_arduinobase_int_b_T obj_j;/* '<Root>/PWM' */
  real_T IC_FirstOutputTime;           /* '<S2>/IC' */
  boolean_T objisempty;                /* '<Root>/PWM' */
  boolean_T objisempty_g;              /* '<Root>/Analog Input2' */
  boolean_T objisempty_n;              /* '<Root>/Analog Input' */
} DW_closedloop_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S34>/Integrator' */
} X_closedloop_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S34>/Integrator' */
} XDot_closedloop_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S34>/Integrator' */
} XDis_closedloop_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_closedloop_T_ {
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S31>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S34>/Integrator'
                               */
  real_T PIDController_LowerSaturationLi;
                              /* Mask Parameter: PIDController_LowerSaturationLi
                               * Referenced by: '<S41>/Saturation'
                               */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S39>/Proportional Gain'
                                        */
  real_T PIDController_UpperSaturationLi;
                              /* Mask Parameter: PIDController_UpperSaturationLi
                               * Referenced by: '<S41>/Saturation'
                               */
  real_T AnalogInput_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T AnalogInput2_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input2'
                                        */
  real_T Constant8_Value;              /* Expression: 1000
                                        * Referenced by: '<S2>/Constant8'
                                        */
  real_T Constant9_Value;              /* Expression: 25
                                        * Referenced by: '<S2>/Constant9'
                                        */
  real_T Constant_Value;               /* Expression: 0.5196
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 4*2.69
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 1.3
                                        * Referenced by: '<S2>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 1.3
                                        * Referenced by: '<S2>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 362
                                        * Referenced by: '<S2>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 4
                                        * Referenced by: '<S2>/Constant6'
                                        */
  real_T Constant1_Value;              /* Expression: 0.36e-3
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant7_Value;              /* Expression: -6.7e-3
                                        * Referenced by: '<S2>/Constant7'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 0.5
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T IC_Value;                     /* Expression: 0
                                        * Referenced by: '<S2>/IC'
                                        */
  real_T Gain2_Gain;                   /* Expression: 255
                                        * Referenced by: '<Root>/Gain2'
                                        */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  uint16_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_closedloop_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_closedloop_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[1];
  real_T odeF[3][1];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_closedloop_T closedloop_P;

/* Block signals (default storage) */
extern B_closedloop_T closedloop_B;

/* Continuous states (default storage) */
extern X_closedloop_T closedloop_X;

/* Block states (default storage) */
extern DW_closedloop_T closedloop_DW;

/* Model entry point functions */
extern void closedloop_initialize(void);
extern void closedloop_step(void);
extern void closedloop_terminate(void);

/* Real-time Model object */
extern RT_MODEL_closedloop_T *const closedloop_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Data Type Conversion1' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'closedloop'
 * '<S1>'   : 'closedloop/PID Controller'
 * '<S2>'   : 'closedloop/PV Model'
 * '<S3>'   : 'closedloop/PID Controller/Anti-windup'
 * '<S4>'   : 'closedloop/PID Controller/D Gain'
 * '<S5>'   : 'closedloop/PID Controller/Filter'
 * '<S6>'   : 'closedloop/PID Controller/Filter ICs'
 * '<S7>'   : 'closedloop/PID Controller/I Gain'
 * '<S8>'   : 'closedloop/PID Controller/Ideal P Gain'
 * '<S9>'   : 'closedloop/PID Controller/Ideal P Gain Fdbk'
 * '<S10>'  : 'closedloop/PID Controller/Integrator'
 * '<S11>'  : 'closedloop/PID Controller/Integrator ICs'
 * '<S12>'  : 'closedloop/PID Controller/N Copy'
 * '<S13>'  : 'closedloop/PID Controller/N Gain'
 * '<S14>'  : 'closedloop/PID Controller/P Copy'
 * '<S15>'  : 'closedloop/PID Controller/Parallel P Gain'
 * '<S16>'  : 'closedloop/PID Controller/Reset Signal'
 * '<S17>'  : 'closedloop/PID Controller/Saturation'
 * '<S18>'  : 'closedloop/PID Controller/Saturation Fdbk'
 * '<S19>'  : 'closedloop/PID Controller/Sum'
 * '<S20>'  : 'closedloop/PID Controller/Sum Fdbk'
 * '<S21>'  : 'closedloop/PID Controller/Tracking Mode'
 * '<S22>'  : 'closedloop/PID Controller/Tracking Mode Sum'
 * '<S23>'  : 'closedloop/PID Controller/Tsamp - Integral'
 * '<S24>'  : 'closedloop/PID Controller/Tsamp - Ngain'
 * '<S25>'  : 'closedloop/PID Controller/postSat Signal'
 * '<S26>'  : 'closedloop/PID Controller/preSat Signal'
 * '<S27>'  : 'closedloop/PID Controller/Anti-windup/Passthrough'
 * '<S28>'  : 'closedloop/PID Controller/D Gain/Disabled'
 * '<S29>'  : 'closedloop/PID Controller/Filter/Disabled'
 * '<S30>'  : 'closedloop/PID Controller/Filter ICs/Disabled'
 * '<S31>'  : 'closedloop/PID Controller/I Gain/Internal Parameters'
 * '<S32>'  : 'closedloop/PID Controller/Ideal P Gain/Passthrough'
 * '<S33>'  : 'closedloop/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S34>'  : 'closedloop/PID Controller/Integrator/Continuous'
 * '<S35>'  : 'closedloop/PID Controller/Integrator ICs/Internal IC'
 * '<S36>'  : 'closedloop/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S37>'  : 'closedloop/PID Controller/N Gain/Disabled'
 * '<S38>'  : 'closedloop/PID Controller/P Copy/Disabled'
 * '<S39>'  : 'closedloop/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S40>'  : 'closedloop/PID Controller/Reset Signal/Disabled'
 * '<S41>'  : 'closedloop/PID Controller/Saturation/Enabled'
 * '<S42>'  : 'closedloop/PID Controller/Saturation Fdbk/Disabled'
 * '<S43>'  : 'closedloop/PID Controller/Sum/Sum_PI'
 * '<S44>'  : 'closedloop/PID Controller/Sum Fdbk/Disabled'
 * '<S45>'  : 'closedloop/PID Controller/Tracking Mode/Disabled'
 * '<S46>'  : 'closedloop/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S47>'  : 'closedloop/PID Controller/Tsamp - Integral/Passthrough'
 * '<S48>'  : 'closedloop/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S49>'  : 'closedloop/PID Controller/postSat Signal/Forward_Path'
 * '<S50>'  : 'closedloop/PID Controller/preSat Signal/Forward_Path'
 * '<S51>'  : 'closedloop/PV Model/PV Module Mathematical Model'
 */
#endif                                 /* RTW_HEADER_closedloop_h_ */
