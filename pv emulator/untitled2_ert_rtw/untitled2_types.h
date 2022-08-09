/*
 * untitled2_types.h
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

#ifndef RTW_HEADER_untitled2_types_h_
#define RTW_HEADER_untitled2_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */

/* Custom Type definition for MATLABSystem: '<Root>/PWM' */
#include "MW_SVD.h"
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

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_lMInmD9zWRzKpUCrv0OfsC codertarget_arduinobase_inter_T;

#endif                               /*typedef_codertarget_arduinobase_inter_T*/

/* Parameters (default storage) */
typedef struct P_untitled2_T_ P_untitled2_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_untitled2_T RT_MODEL_untitled2_T;

#endif                                 /* RTW_HEADER_untitled2_types_h_ */
