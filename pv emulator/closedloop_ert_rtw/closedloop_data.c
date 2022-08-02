/*
 * closedloop_data.c
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

/* Block parameters (default storage) */
P_closedloop_T closedloop_P = {
  /* Mask Parameter: PIDController_I
   * Referenced by: '<S31>/Integral Gain'
   */
  0.003,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S34>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_LowerSaturationLi
   * Referenced by: '<S41>/Saturation'
   */
  0.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S39>/Proportional Gain'
   */
  7.0,

  /* Mask Parameter: PIDController_UpperSaturationLi
   * Referenced by: '<S41>/Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Analog Input'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Analog Input2'
   */
  -1.0,

  /* Expression: 1000
   * Referenced by: '<S2>/Constant8'
   */
  1000.0,

  /* Expression: 25
   * Referenced by: '<S2>/Constant9'
   */
  25.0,

  /* Expression: 0.5196
   * Referenced by: '<S2>/Constant'
   */
  0.5196,

  /* Expression: 4*2.69
   * Referenced by: '<S2>/Constant2'
   */
  10.76,

  /* Expression: 1.3
   * Referenced by: '<S2>/Constant3'
   */
  1.3,

  /* Expression: 1.3
   * Referenced by: '<S2>/Constant4'
   */
  1.3,

  /* Expression: 362
   * Referenced by: '<S2>/Constant5'
   */
  362.0,

  /* Expression: 4
   * Referenced by: '<S2>/Constant6'
   */
  4.0,

  /* Expression: 0.36e-3
   * Referenced by: '<S2>/Constant1'
   */
  0.00036,

  /* Expression: -6.7e-3
   * Referenced by: '<S2>/Constant7'
   */
  -0.0067,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Gain3'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<Root>/Saturation1'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/IC'
   */
  0.0,

  /* Expression: 255
   * Referenced by: '<Root>/Gain2'
   */
  255.0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<Root>/Gain'
   */
  56375U,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<Root>/Gain1'
   */
  41000U
};
