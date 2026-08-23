/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PI_Controller.c
 *
 * Code generated for Simulink model 'PI_Controller'.
 *
 * Model version                  : 4.7
 * Simulink Coder version         : 26.1 (R2026a) 20-Nov-2025
 * C/C++ source code generated on : Sun Aug 23 11:51:17 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PI_Controller.h"
#include "rtwtypes.h"
#include "PI_Controller_private.h"

/* Block states (default storage) */
DW_PI_Controller_T PI_Controller_DW;

/* External inputs (root inport signals with default storage) */
ExtU_PI_Controller_T PI_Controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_PI_Controller_T PI_Controller_Y;

/* Real-time model */
static RT_MODEL_PI_Controller_T PI_Controller_M_;
RT_MODEL_PI_Controller_T *const PI_Controller_M = &PI_Controller_M_;

/* Output and update for atomic system: '<Root>/PI_Controller' */
real_T PI_Controller_PI_Controller(real_T rtu_Gravity_ref, real_T
  rtu_Gravity_meas, DW_PI_Controller_PI_Controlle_T *localDW)
{
  real_T rty_Out1_0;
  real_T rtb_FilterCoefficient;
  real_T rtb_Sum_a;

  /* Sum: '<S1>/Sum' */
  rtb_Sum_a = rtu_Gravity_ref - rtu_Gravity_meas;

  /* Gain: '<S40>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S32>/Filter'
   *  Gain: '<S30>/Derivative Gain'
   *  Sum: '<S32>/SumD'
   */
  rtb_FilterCoefficient = (0.0 * rtb_Sum_a - localDW->Filter_DSTATE) * 100.0;

  /* Sum: '<S46>/Sum' incorporates:
   *  DiscreteIntegrator: '<S37>/Integrator'
   *  Gain: '<S42>/Proportional Gain'
   */
  rty_Out1_0 = (120.0 * rtb_Sum_a + localDW->Integrator_DSTATE) +
    rtb_FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S32>/Filter' */
  localDW->Filter_DSTATE += 0.01 * rtb_FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S37>/Integrator' */
  localDW->Integrator_DSTATE += 0.01 * rtb_Sum_a;
  return rty_Out1_0;
}

/* Model step function */
void PI_Controller_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/PI_Controller' */

  /* Outport: '<Root>/Out1' incorporates:
   *  Inport: '<Root>/Gravity_meas'
   *  Inport: '<Root>/Gravity_ref'
   */
  PI_Controller_Y.Out1 = PI_Controller_PI_Controller(PI_Controller_U.Gravity_ref,
    PI_Controller_U.Gravity_meas, &PI_Controller_DW.PI_Controller_p);

  /* End of Outputs for SubSystem: '<Root>/PI_Controller' */
}

/* Model initialize function */
void PI_Controller_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void PI_Controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
