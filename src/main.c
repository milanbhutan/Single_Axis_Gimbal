/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <math.h>
#include "PID_Controller.h"
#include <zephyr/kernel.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/drivers/pwm.h>

#define RAD_TO_DEG(rad) (rad/(M_PI)) * 180

#define CONTROL_TASK_STACK_SIZE 1024
#define CONTROL_TASK_PRIORITY 3

#define IMU_READ_TASK_SIZE 1024
#define IMU_READ_TASK_PRIORITY 5

#define PRINT_TASK_SIZE 1024
#define PRINT_TASK_PRIORITY 7

void Control_Task(void *p1, void *p2, void *p3);
void IMU_Read_Task(void *p1, void *p2, void *p3);
void Print_Task(void *p1, void *p2, void *p3);

struct k_thread Control_Task_TCB;
k_tid_t Control_Task_ID;

struct k_thread IMU_Read_Task_TCB;
k_tid_t IMU_Read_Task_ID;

struct k_thread Print_Task_TCB;
k_tid_t Print_Task_ID;

typedef struct{
	struct sensor_value gyro[3];
	struct sensor_value acc[3];
}imu;

imu myIMU = {0};
imu myIMU_old = {0};

const struct device *imu_dev = DEVICE_DT_GET_ONE(invensense_mpu6050);
const struct device *pwm_dev = DEVICE_DT_GET(DT_NODELABEL(pwm2));

K_THREAD_STACK_DEFINE(Control_Task_Stack, CONTROL_TASK_STACK_SIZE);
K_THREAD_STACK_DEFINE(IMU_Read_Task_Stack, IMU_READ_TASK_SIZE);
K_THREAD_STACK_DEFINE(Print_Task_Stack, PRINT_TASK_SIZE);

uint32_t period = PWM_HZ(50);
int servo_duty = 1500;

int main(void)
{
	PID_Controller_initialize();

	Control_Task_ID = k_thread_create(
		&Control_Task_TCB,
		Control_Task_Stack,
		K_THREAD_STACK_SIZEOF(Control_Task_Stack),
		Control_Task,
		NULL,
		NULL,
		NULL,
		CONTROL_TASK_PRIORITY,
		0,
		K_NO_WAIT
	);

	IMU_Read_Task_ID = k_thread_create(
		&IMU_Read_Task_TCB,
		IMU_Read_Task_Stack,
		K_THREAD_STACK_SIZEOF(IMU_Read_Task_Stack),
		IMU_Read_Task,
		NULL,
		NULL,
		NULL,
		IMU_READ_TASK_PRIORITY,
		0,
		K_NO_WAIT
	);

	Print_Task_ID = k_thread_create(
		&Print_Task_TCB,
		Print_Task_Stack,
		K_THREAD_STACK_SIZEOF(Print_Task_Stack),
		Print_Task,
		NULL,
		NULL,
		NULL,
		PRINT_TASK_PRIORITY,
		0,
		K_NO_WAIT
	);


	pwm_set(
		pwm_dev,
		1,
		period,
		PWM_USEC(1500),
		PWM_POLARITY_NORMAL
	);


	return 0;
}

void Control_Task(void *p1, void *p2, void *p3){

double filtered_acc = 0;

	for(;;){
	
	int64_t start = k_uptime_get();
	
	
	
	filtered_acc = (0.9 * filtered_acc) + 0.1 * (sensor_value_to_double(&myIMU.acc[1]) + 0.5);

	PID_Controller_U.Theta_ref = 0;
	PID_Controller_U.Theta_meas = filtered_acc;
	
	PID_Controller_step();

	servo_duty = 1500 - PID_Controller_Y.Out1;

	if(servo_duty > 1900){
		servo_duty = 1900;
	}

	if(servo_duty < 1100){
		servo_duty = 1100;
	}


	pwm_set(
		pwm_dev,
		1,
		period,
		PWM_USEC(servo_duty),
		PWM_POLARITY_NORMAL
	);

	int64_t end = k_uptime_get();


	k_msleep(10 - (end - start));
}

}


void IMU_Read_Task(void *p1, void *p2, void *p3){
for(;;){

	if(sensor_sample_fetch(imu_dev) == 0){
		
		memcpy(&myIMU_old, &myIMU, sizeof(myIMU));

		sensor_channel_get(
			imu_dev,
			SENSOR_CHAN_GYRO_XYZ,
			myIMU.gyro
		);
		sensor_channel_get(
			imu_dev,
			SENSOR_CHAN_ACCEL_XYZ,
			myIMU.acc
		);

	}

	k_msleep(10);
}

}

void Print_Task(void *p1, void *p2, void *p3){
for(;;){

	printf("Servo Duty Cycle: %d us\n", servo_duty);

	k_msleep(1000);

}

}


