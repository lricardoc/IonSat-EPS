/*
 * closedloop_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(uint16_T),
  sizeof(uint32_T),
  sizeof(uint16_T),
  sizeof(uint32_T),
  sizeof(codertarget_arduinobase_inter_T),
  sizeof(codertarget_arduinobase_int_b_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "uint16_T",
  "uint32_T",
  "uint16_T",
  "uint32_T",
  "codertarget_arduinobase_inter_T",
  "codertarget_arduinobase_int_b_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&closedloop_B.IC), 0, 0, 2 }
  ,

  { (char_T *)(&closedloop_DW.obj), 18, 0, 2 },

  { (char_T *)(&closedloop_DW.obj_j), 19, 0, 1 },

  { (char_T *)(&closedloop_DW.IC_FirstOutputTime), 0, 0, 1 },

  { (char_T *)(&closedloop_DW.objisempty), 8, 0, 3 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  5U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&closedloop_P.PIDController_I), 0, 0, 23 },

  { (char_T *)(&closedloop_P.Gain_Gain), 14, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  2U,
  rtPTransitions
};

/* [EOF] closedloop_dt.h */
