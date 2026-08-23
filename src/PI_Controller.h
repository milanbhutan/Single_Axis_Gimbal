/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PI_Controller.h
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

#ifndef PI_Controller_h_
#define PI_Controller_h_
#ifndef PI_Controller_COMMON_INCLUDES_
#define PI_Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* PI_Controller_COMMON_INCLUDES_ */

#include "PI_Controller_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>/PI_Controller' */
typedef struct {
  real_T Filter_DSTATE;                /* '<S32>/Filter' */
  real_T Integrator_DSTATE;            /* '<S37>/Integrator' */
} DW_PI_Controller_PI_Controlle_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  DW_PI_Controller_PI_Controlle_T PI_Controller_p;/* '<Root>/PI_Controller' */
} DW_PI_Controller_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Gravity_ref;                  /* '<Root>/Gravity_ref' */
  real_T Gravity_meas;                 /* '<Root>/Gravity_meas' */
} ExtU_PI_Controller_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_PI_Controller_T;

/* Real-time Model Data Structure */
struct tag_RTM_PI_Controller_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_PI_Controller_T PI_Controller_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_PI_Controller_T PI_Controller_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_PI_Controller_T PI_Controller_Y;

/* Model entry point functions */
extern void PI_Controller_initialize(void);
extern void PI_Controller_step(void);
extern void PI_Controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PI_Controller_T *const PI_Controller_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
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
 * hilite_system('Gimbal_PI/PI_Controller')    - opens subsystem Gimbal_PI/PI_Controller
 * hilite_system('Gimbal_PI/PI_Controller/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Gimbal_PI'
 * '<S1>'   : 'Gimbal_PI/PI_Controller'
 * '<S2>'   : 'Gimbal_PI/PI_Controller/PID Controller'
 * '<S3>'   : 'Gimbal_PI/PI_Controller/PID Controller/Anti-windup'
 * '<S4>'   : 'Gimbal_PI/PI_Controller/PID Controller/D Gain'
 * '<S5>'   : 'Gimbal_PI/PI_Controller/PID Controller/External Derivative'
 * '<S6>'   : 'Gimbal_PI/PI_Controller/PID Controller/Filter'
 * '<S7>'   : 'Gimbal_PI/PI_Controller/PID Controller/Filter ICs'
 * '<S8>'   : 'Gimbal_PI/PI_Controller/PID Controller/I Gain'
 * '<S9>'   : 'Gimbal_PI/PI_Controller/PID Controller/Ideal P Gain'
 * '<S10>'  : 'Gimbal_PI/PI_Controller/PID Controller/Ideal P Gain Fdbk'
 * '<S11>'  : 'Gimbal_PI/PI_Controller/PID Controller/Integrator'
 * '<S12>'  : 'Gimbal_PI/PI_Controller/PID Controller/Integrator ICs'
 * '<S13>'  : 'Gimbal_PI/PI_Controller/PID Controller/N Copy'
 * '<S14>'  : 'Gimbal_PI/PI_Controller/PID Controller/N Gain'
 * '<S15>'  : 'Gimbal_PI/PI_Controller/PID Controller/P Copy'
 * '<S16>'  : 'Gimbal_PI/PI_Controller/PID Controller/Parallel P Gain'
 * '<S17>'  : 'Gimbal_PI/PI_Controller/PID Controller/Reset Signal'
 * '<S18>'  : 'Gimbal_PI/PI_Controller/PID Controller/Saturation'
 * '<S19>'  : 'Gimbal_PI/PI_Controller/PID Controller/Saturation Fdbk'
 * '<S20>'  : 'Gimbal_PI/PI_Controller/PID Controller/Sum'
 * '<S21>'  : 'Gimbal_PI/PI_Controller/PID Controller/Sum Fdbk'
 * '<S22>'  : 'Gimbal_PI/PI_Controller/PID Controller/Tracking Mode'
 * '<S23>'  : 'Gimbal_PI/PI_Controller/PID Controller/Tracking Mode Sum'
 * '<S24>'  : 'Gimbal_PI/PI_Controller/PID Controller/Tsamp - Integral'
 * '<S25>'  : 'Gimbal_PI/PI_Controller/PID Controller/Tsamp - Ngain'
 * '<S26>'  : 'Gimbal_PI/PI_Controller/PID Controller/postSat Signal'
 * '<S27>'  : 'Gimbal_PI/PI_Controller/PID Controller/preInt Signal'
 * '<S28>'  : 'Gimbal_PI/PI_Controller/PID Controller/preSat Signal'
 * '<S29>'  : 'Gimbal_PI/PI_Controller/PID Controller/Anti-windup/Passthrough'
 * '<S30>'  : 'Gimbal_PI/PI_Controller/PID Controller/D Gain/Internal Parameters'
 * '<S31>'  : 'Gimbal_PI/PI_Controller/PID Controller/External Derivative/Error'
 * '<S32>'  : 'Gimbal_PI/PI_Controller/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S33>'  : 'Gimbal_PI/PI_Controller/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S34>'  : 'Gimbal_PI/PI_Controller/PID Controller/I Gain/Internal Parameters'
 * '<S35>'  : 'Gimbal_PI/PI_Controller/PID Controller/Ideal P Gain/Passthrough'
 * '<S36>'  : 'Gimbal_PI/PI_Controller/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S37>'  : 'Gimbal_PI/PI_Controller/PID Controller/Integrator/Discrete'
 * '<S38>'  : 'Gimbal_PI/PI_Controller/PID Controller/Integrator ICs/Internal IC'
 * '<S39>'  : 'Gimbal_PI/PI_Controller/PID Controller/N Copy/Disabled'
 * '<S40>'  : 'Gimbal_PI/PI_Controller/PID Controller/N Gain/Internal Parameters'
 * '<S41>'  : 'Gimbal_PI/PI_Controller/PID Controller/P Copy/Disabled'
 * '<S42>'  : 'Gimbal_PI/PI_Controller/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S43>'  : 'Gimbal_PI/PI_Controller/PID Controller/Reset Signal/Disabled'
 * '<S44>'  : 'Gimbal_PI/PI_Controller/PID Controller/Saturation/Passthrough'
 * '<S45>'  : 'Gimbal_PI/PI_Controller/PID Controller/Saturation Fdbk/Disabled'
 * '<S46>'  : 'Gimbal_PI/PI_Controller/PID Controller/Sum/Sum_PID'
 * '<S47>'  : 'Gimbal_PI/PI_Controller/PID Controller/Sum Fdbk/Disabled'
 * '<S48>'  : 'Gimbal_PI/PI_Controller/PID Controller/Tracking Mode/Disabled'
 * '<S49>'  : 'Gimbal_PI/PI_Controller/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S50>'  : 'Gimbal_PI/PI_Controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S51>'  : 'Gimbal_PI/PI_Controller/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S52>'  : 'Gimbal_PI/PI_Controller/PID Controller/postSat Signal/Forward_Path'
 * '<S53>'  : 'Gimbal_PI/PI_Controller/PID Controller/preInt Signal/Internal PreInt'
 * '<S54>'  : 'Gimbal_PI/PI_Controller/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* PI_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
