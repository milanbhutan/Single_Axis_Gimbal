# Single Axis Gimbal

Used an STM32 to run a 100 Hz digital PI controller for stabilizing an IMU using accelerometer feedback and servo actuation. Zephyr RTOS was also used to configure peripherials using the device tree and interface with them by using their device APIs. The PI controller was first designed in Simulink, after which the Embedded Coder tool was used to generate code for this controller which would then be deployed on the STM32.

## Simulink Model
Shown above is the Simulink model of a simple PI controller. A plant is used to represent the dynamics of the servo arm and IMU.

## Hardware

## Software Layout
