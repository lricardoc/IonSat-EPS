/*
 * openloop_types.h
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

#ifndef RTW_HEADER_openloop_types_h_
#define RTW_HEADER_openloop_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */

/* Custom Type definition for MATLABSystem: '<Root>/PWM' */
#include "MW_SVD.h"
#ifndef struct_tag_Gc8EcsaAa6B4PVRJCSARvB
#define struct_tag_Gc8EcsaAa6B4PVRJCSARvB

struct tag_Gc8EcsaAa6B4PVRJCSARvB
{
  MW_Handle_Type MW_ANALOGIN_HANDLE;
};

#endif                                 /*struct_tag_Gc8EcsaAa6B4PVRJCSARvB*/

#ifndef typedef_f_arduinodriver_ArduinoAnalog_T
#define typedef_f_arduinodriver_ArduinoAnalog_T

typedef struct tag_Gc8EcsaAa6B4PVRJCSARvB f_arduinodriver_ArduinoAnalog_T;

#endif                               /*typedef_f_arduinodriver_ArduinoAnalog_T*/

#ifndef struct_tag_IH4ZAEwYd2ouei4lGVnLsG
#define struct_tag_IH4ZAEwYd2ouei4lGVnLsG

struct tag_IH4ZAEwYd2ouei4lGVnLsG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_arduinodriver_ArduinoAnalog_T AnalogInDriverObj;
  real_T SampleTime;
};

#endif                                 /*struct_tag_IH4ZAEwYd2ouei4lGVnLsG*/

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_IH4ZAEwYd2ouei4lGVnLsG codertarget_arduinobase_inter_T;

#endif                               /*typedef_codertarget_arduinobase_inter_T*/

#ifndef struct_tag_lMInmD9zWRzKpUCrv0OfsC
#define struct_tag_lMInmD9zWRzKpUCrv0OfsC

struct tag_lMInmD9zWRzKpUCrv0OfsC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_PWM_HANDLE;
  uint32_T PinPWM;
};

#endif                                 /*struct_tag_lMInmD9zWRzKpUCrv0OfsC*/

#ifndef typedef_codertarget_arduinobase_int_a_T
#define typedef_codertarget_arduinobase_int_a_T

typedef struct tag_lMInmD9zWRzKpUCrv0OfsC codertarget_arduinobase_int_a_T;

#endif                               /*typedef_codertarget_arduinobase_int_a_T*/

/* Parameters (default storage) */
typedef struct P_openloop_T_ P_openloop_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_openloop_T RT_MODEL_openloop_T;

#endif                                 /* RTW_HEADER_openloop_types_h_ */
