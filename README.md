# marlin_ender3_laser
Marlin firmware for Ender3 Pro with laser conversion

1. Based on Marlin bugfix 2.0.x
2. For Ender3 Pro with CREALITY v422 and "C" motordrive (same as A4988 in terms of the firmware)
3. changes made according to https://github.com/MarlinFirmware/Marlin/issues/20638
4. The code and hardwarelayout for the PWM conversion board (FAN 24V to Laser 5V) is in the folder laserPWM

Changes made from the stock firmware
1. Set {PA_0,       TIM5, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 1, 0)}, // TIM2_CH1  //  Line 114 in /Users/%USERPROFILE%/.platformio/packages/framework-arduinoststm32/variants/STM32F1xx/F103R(C-D-E)T/PeripheralPins.c Note this is stored in your particular build environment, not in this repo.
2. Commented #define FAN_SOFT_PWM in Marlin/src/pins/stm32f1/pins_CREALITY_V4.h
3. Uncommented #define FAST_PWM_FAN in Marlin/Configuration.h
4. Commented #define FAN_SOFT_PWM in Marlin/Configuration.h (DO NOT comment out #define SOFT_PWM_SCALE 0)
5. Set #define STEP_TIMER_NUM 4 // for other boards, five is fine. in Marlin/src/HAL/STM32F1/timers.h
6. #define FAN_MIN_PWM 0 in Marlin/Configuration_adv.h // unconstrain lower Laser power
7. #define LASER_SYNCHRONOUS_M106_M107 //laser synchronous with the XY movement, solves misalignment and laser power on delay problem
