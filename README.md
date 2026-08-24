# Single Axis Gimbal

Used an STM32 to run a 100 Hz digital PI controller for stabilizing an IMU using accelerometer feedback and servo actuation. Zephyr RTOS was also used to configure peripherals using the Devicetree and interface with them by using their device APIs. The PI controller was first designed in Simulink, after which the Embedded Coder tool was used to generate code for this controller which would then be deployed on the STM32.

## Model Dynamics and Simulink Model
The figure below shows the IMU in the upright orientation, which is assumed to be when the IMU's measured acceleration along the y-axis, $a_y$, equals 0

<img width="1745" height="959" alt="image" src="https://github.com/user-attachments/assets/5fd0655c-34a3-4f79-bf26-bf4015993b6d" />

<br><br>
The figure below will then show the resulting change in the $a_y$ as a result of some rotation about the z-axis

<img width="1511" height="814" alt="image" src="https://github.com/user-attachments/assets/16ffbb9f-9adb-4b38-a7e2-387d097dbccd" />



Any rotation about the z axis will lead to a non-zero change in $a_y$ whose sign depends on the direction of rotation. The PI controller will then produce a PWM output in response to the error signal

$e(\theta) = a_{y,ref} - a_{y,meas}(\theta)$ 

where $a_{y,ref} = 0$, since this is the acceleration where the IMU is upright. The controller output is fed into a first-order plant which approximates the lag associated with the servo movement. The plant will then output $a_{y,meas}(\theta)$ which is negatively fed back into the PI controller, creating a closed loop system which is shown below

<img width="1857" height="517" alt="image" src="https://github.com/user-attachments/assets/8e748a41-85bc-4a24-ae55-6cf9e759b705" />

<br><br>

The figure below shows the simulated step response of the closed-loop system

<img width="2553" height="1452" alt="image" src="https://github.com/user-attachments/assets/45527c5d-8f80-46a0-8cc6-aba99115c5f8" />


## Software Layout
<img width="2204" height="718" alt="image" src="https://github.com/user-attachments/assets/a819f6c6-eee7-4e1d-82c3-e8fda082111b" />

