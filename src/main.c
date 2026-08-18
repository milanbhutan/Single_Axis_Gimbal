/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr/kernel.h>

void Control_Task(void *p1, void *p2, void *p3);

struct k_thread Control_Task_TCB;
k_tid_t Control_Task_ID;

#define CONTROL_TASK_STACK_SIZE 1024
#define CONTROL_TASK_PRIORITY 3

 
K_THREAD_STACK_DEFINE(Control_Task_Stack, CONTROL_TASK_STACK_SIZE);

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

	return 0;
}

void Control_Task(void *p1, void *p2, void *p3){
for(;;){
	printf("Control Task\n");
	k_msleep(1000);
}


}


