/*
 * main.h
 *
 *  Created on: Feb 28, 2024
 *      Author: Youssef
 */

#ifndef INC_MAIN_H_
#define INC_MAIN_H_

#include <std_types.h>
#include <util/delay.h>
#include <common_macros.h>
#include <gpio.h>
#include <adc.h>
#include <lcd.h>
#include <lm35_sensor.h>
#include <motor.h>

#define TEMP_0		0
#define TEMP_30		30
#define TEMP_60		60
#define TEMP_90		90
#define TEMP_120	120

uint8 g_current_temp;
uint8 g_displayed_temp;

DcMotor_State_t g_current_state;
DcMotor_State_t g_displayed_state;

DcMotor_Speed_t g_current_speed;
DcMotor_Speed_t g_displayed_speed;

#endif /* INC_MAIN_H_ */
