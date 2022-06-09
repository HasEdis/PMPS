#include "main.h"

extern TIM_HandleTypeDef htim1;

#define stepsperrev 4096

void delay(uint16_t us);

void stepper_set_rpm(int rpm);

void stepper_half_drive(int step);

void stepper_step_angle(float angle, int direction, int rpm);

void open();

void close();
