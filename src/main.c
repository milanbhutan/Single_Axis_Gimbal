/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/sensor.h>

#define CONTROL_TASK_STACK_SIZE 1024
#define CONTROL_TASK_PRIORITY 3

#define IMU_READ_TASK_SIZE 1024
#define IMU_READ_TASK_PRIORITY 5

void Control_Task(void *p1, void *p2, void *p3);
void IMU_Read_Task(void *p1, void *p2, void *p3);

struct k_thread Control_Task_TCB;
k_tid_t Control_Task_ID;

struct k_thread IMU_Read_Task_TCB;
k_tid_t IMU_Read_Task_ID;

typedef struct{
 	uint32_t data;
} imu;

imu myIMU = {0};

const struct device *imu_dev = DEVICE_DT_GET_ONE(invensense_mpu6050);

K_THREAD_STACK_DEFINE(Control_Task_Stack, CONTROL_TASK_STACK_SIZE);
K_THREAD_STACK_DEFINE(IMU_Read_Task_Stack, 1024);

int main(void)
{
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

	return 0;
}

void Control_Task(void *p1, void *p2, void *p3){
for(;;){
	
	printf("Control Task\n");
	k_msleep(1000);
}

}


void IMU_Read_Task(void *p1, void *p2, void *p3){
for(;;){
	//DEVICE_DT_GET_ONE(imu, inverse_imu)
	sensor_sample_fetch(imu_dev);
	printf("IMU Read Task\n");
	k_msleep(2000);
}

}



