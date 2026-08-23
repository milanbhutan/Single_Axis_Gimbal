# Single Axis Gimbal

Used an STM32 to run a 100 Hz digital PI controller for stabilizing an IMU using accelerometer feedback and servo actuation. Zephyr RTOS was also used to configure peripherials using the device tree and interface with them by using their device APIs. The PI controller was first designed in Simulink, after which the Embedded Coder tool was used to generate code for this controller which would then be deployed on the STM32.

## Simulink Model

The figure below will then show the resulting change in the acceleration measured by the IMU along the y axis


Any rotation about the z axis will lead to a non-zero change with $a_y$ whose sign depends on the direction of rotation. The PI controller will then act upon the error signal,
$e(\theta) = a_{y,meas} - a_{y,ref}$ and produce an output which will be fed into a plant. This plant represents the dynamics of the servo arm, so

## Software Layout
