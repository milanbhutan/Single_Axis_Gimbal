/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PID_Controller.c
 *
 * Code generated for Simulink model 'PID_Controller'.
 *
 * Model version                  : 4.6
 * Simulink Coder version         : 26.1 (R2026a) 20-Nov-2025
 * C/C++ source code generated on : Sat Aug 22 16:41:52 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PID_Controller.h"
#include "rtwtypes.h"
#include "PID_Controller_private.h"

/* Block states (default storage) */
DW_PID_Controller_T PID_Controller_DW;

/* External inputs (root inport signals with default storage) */
ExtU_PID_Controller_T PID_Controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_PID_Controller_T PID_Controller_Y;

/* Real-time model */
static RT_MODEL_PID_Controller_T PID_Controller_M_;
RT_MODEL_PID_Controller_T *const PID_Controller_M = &PID_Controller_M_;

/* Output and update for atomic system: '<Root>/PID_Controller' */
real_T PID_Controller_PID_Controller(real_T rtu_Theta_ref, real_T rtu_Theta_meas,
  DW_PID_Controller_PID_Control_T *localDW)
{
  real_T rty_Out1_0;
  real_T rtb_FilterCoefficient;
  real_T rtb_Sum_a;

  /* Sum: '<S1>/Sum' */
  rtb_Sum_a = rtu_Theta_ref - rtu_Theta_meas;

  /* Gain: '<S40>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S32>/Filter'
   *  Sum: '<S32>/SumD'
   */
  rtb_FilterCoefficient = (rtb_Sum_a - localDW->Filter_DSTATE) * 100.0;

  /* Sum: '<S46>/Sum' incorporates:
   *  DiscreteIntegrator: '<S37>/Integrator'
   *  Gain: '<S42>/Proportional Gain'
   */
  rty_Out1_0 = (120.0 * rtb_Sum_a + localDW->Integrator_DSTATE);

  /* Update for DiscreteIntegrator: '<S32>/Filter' */
  localDW->Filter_DSTATE += 0.01 * rtb_FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S37>/Integrator' */
  localDW->Integrator_DSTATE += 0.01 * rtb_Sum_a;
  return rty_Out1_0;
}

/* Model step function */
void PID_Controller_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/PID_Controller' */

  /* Outport: '<Root>/Out1' incorporates:
   *  Inport: '<Root>/Theta_meas'
   *  Inport: '<Root>/Theta_ref'
   */
  PID_Controller_Y.Out1 = PID_Controller_PID_Controller
    (PID_Controller_U.Theta_ref, PID_Controller_U.Theta_meas,
     &PID_Controller_DW.PID_Controller_p);

  /* End of Outputs for SubSystem: '<Root>/PID_Controller' */
}

/* Model initialize function */
void PID_Controller_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void PID_Controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
