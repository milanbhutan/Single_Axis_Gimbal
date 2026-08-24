/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include "PI_Controller.h"
#include <zephyr/kernel.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/drivers/pwm.h>

#define CONTROL_TASK_STACK_SIZE 1024
#define CONTROL_TASK_PRIORITY 3

#define PRINT_TASK_SIZE 1024
#define PRINT_TASK_PRIORITY 7

void Control_Task(void *p1, void *p2, void *p3);
void Print_Task(void *p1, void *p2, void *p3);

struct k_thread Control_Task_TCB;
k_tid_t Control_Task_ID;

struct k_thread Print_Task_TCB;
k_tid_t Print_Task_ID;

typedef struct{
	struct sensor_value gyro[3];
	struct sensor_value acc[3];
}imu;

imu myIMU = {0};

const struct device *imu_dev = DEVICE_DT_GET_ONE(invensense_mpu6050);
const struct device *pwm_dev = DEVICE_DT_GET(DT_NODELABEL(pwm2));

K_THREAD_STACK_DEFINE(Control_Task_Stack, CONTROL_TASK_STACK_SIZE);
K_THREAD_STACK_DEFINE(Print_Task_Stack, PRINT_TASK_SIZE);

uint32_t period = PWM_HZ(50);
int pulse_width_us = 1500;

int main(void)
{
	PI_Controller_initialize();

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

double filtered_acc = sensor_value_to_double(&myIMU.acc[1]);

	for(;;){

	int64_t start = k_uptime_get();
	
	//Check if IMU read is successful
	if(sensor_sample_fetch(imu_dev) == 0){
		
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

	
	
	filtered_acc = (0.9 * filtered_acc) + 0.1 * (sensor_value_to_double(&myIMU.acc[1]) + 0.5);

	PI_Controller_U.Gravity_ref = 0;
	PI_Controller_U.Gravity_meas = filtered_acc;
	
	PI_Controller_step();

	pulse_width_us = 1500 - PI_Controller_Y.Out1;

	if(pulse_width_us > 1900){
		pulse_width_us = 1900;
	}

	if(pulse_width_us < 1100){
		pulse_width_us = 1100;
	}

	pwm_set(
		pwm_dev,
		1,
		period,
		PWM_USEC(pulse_width_us),
		PWM_POLARITY_NORMAL
	);
	
	}

	int64_t end = k_uptime_get();

	k_msleep(10 - (end - start));
}

}





void Print_Task(void *p1, void *p2, void *p3){
for(;;){

	printf("Pulse Width: %d us \n", pulse_width_us);

	k_msleep(1000);

}

}


