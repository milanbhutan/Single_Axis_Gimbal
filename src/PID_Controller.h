/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PID_Controller.h
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

#ifndef PID_Controller_h_
#define PID_Controller_h_
#ifndef PID_Controller_COMMON_INCLUDES_
#define PID_Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* PID_Controller_COMMON_INCLUDES_ */

#include "PID_Controller_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>/PID_Controller' */
typedef struct {
  real_T Filter_DSTATE;                /* '<S32>/Filter' */
  real_T Integrator_DSTATE;            /* '<S37>/Integrator' */
} DW_PID_Controller_PID_Control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  DW_PID_Controller_PID_Control_T PID_Controller_p;/* '<Root>/PID_Controller' */
} DW_PID_Controller_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Theta_ref;                    /* '<Root>/Theta_ref' */
  real_T Theta_meas;                   /* '<Root>/Theta_meas' */
} ExtU_PID_Controller_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_PID_Controller_T;

/* Real-time Model Data Structure */
struct tag_RTM_PID_Controller_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_PID_Controller_T PID_Controller_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_PID_Controller_T PID_Controller_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_PID_Controller_T PID_Controller_Y;

/* Model entry point functions */
extern void PID_Controller_initialize(void);
extern void PID_Controller_step(void);
extern void PID_Controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PID_Controller_T *const PID_Controller_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S30>/Derivative Gain' : Eliminated nontunable gain of 1
 * Block '<S34>/Integral Gain' : Eliminated nontunable gain of 1
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('QuadCopter_Cascade_PID/PID_Controller')    - opens subsystem QuadCopter_Cascade_PID/PID_Controller
 * hilite_system('QuadCopter_Cascade_PID/PID_Controller/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'QuadCopter_Cascade_PID'
 * '<S1>'   : 'QuadCopter_Cascade_PID/PID_Controller'
 * '<S2>'   : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller'
 * '<S3>'   : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Anti-windup'
 * '<S4>'   : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/D Gain'
 * '<S5>'   : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/External Derivative'
 * '<S6>'   : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Filter'
 * '<S7>'   : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Filter ICs'
 * '<S8>'   : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/I Gain'
 * '<S9>'   : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Ideal P Gain'
 * '<S10>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Ideal P Gain Fdbk'
 * '<S11>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Integrator'
 * '<S12>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Integrator ICs'
 * '<S13>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/N Copy'
 * '<S14>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/N Gain'
 * '<S15>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/P Copy'
 * '<S16>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Parallel P Gain'
 * '<S17>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Reset Signal'
 * '<S18>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Saturation'
 * '<S19>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Saturation Fdbk'
 * '<S20>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Sum'
 * '<S21>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Sum Fdbk'
 * '<S22>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Tracking Mode'
 * '<S23>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Tracking Mode Sum'
 * '<S24>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Tsamp - Integral'
 * '<S25>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Tsamp - Ngain'
 * '<S26>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/postSat Signal'
 * '<S27>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/preInt Signal'
 * '<S28>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/preSat Signal'
 * '<S29>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Anti-windup/Passthrough'
 * '<S30>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/D Gain/Internal Parameters'
 * '<S31>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/External Derivative/Error'
 * '<S32>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S33>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S34>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/I Gain/Internal Parameters'
 * '<S35>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Ideal P Gain/Passthrough'
 * '<S36>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S37>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Integrator/Discrete'
 * '<S38>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Integrator ICs/Internal IC'
 * '<S39>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/N Copy/Disabled'
 * '<S40>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/N Gain/Internal Parameters'
 * '<S41>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/P Copy/Disabled'
 * '<S42>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S43>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Reset Signal/Disabled'
 * '<S44>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Saturation/Passthrough'
 * '<S45>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Saturation Fdbk/Disabled'
 * '<S46>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Sum/Sum_PID'
 * '<S47>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Sum Fdbk/Disabled'
 * '<S48>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Tracking Mode/Disabled'
 * '<S49>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S50>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S51>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S52>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/postSat Signal/Forward_Path'
 * '<S53>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/preInt Signal/Internal PreInt'
 * '<S54>'  : 'QuadCopter_Cascade_PID/PID_Controller/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* PID_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
