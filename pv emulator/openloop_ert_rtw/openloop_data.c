/*
 * openloop_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "openloop".
 *
 * Model version              : 1.8
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Wed Aug  3 16:15:19 2022
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "openloop.h"
#include "openloop_private.h"

/* Block parameters (default storage) */
P_openloop_T openloop_P = {
  /* Mask Parameter: SliderGain_gain
   * Referenced by: '<S1>/Slider Gain'
   */
  1.5,

  /* Expression: -1
   * Referenced by: '<Root>/Analog Input'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Analog Input2'
   */
  -1.0,

  /* Expression: (5/2)*(9.99/9.836)
   * Referenced by: '<Root>/Gain2'
   */
  2.5391419276128508,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 3.63/3.519
   * Referenced by: '<Root>/Gain3'
   */
  1.03154305200341,

  /* Expression: 0.5
   * Referenced by: '<Root>/Saturation1'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation1'
   */
  0.0,

  /* Expression: 128
   * Referenced by: '<Root>/Constant1'
   */
  128.0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<Root>/Gain'
   */
  41000U,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<Root>/Gain1'
   */
  41000U
};
