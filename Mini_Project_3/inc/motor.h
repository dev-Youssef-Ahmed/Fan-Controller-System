/*
 * motor.h
 *
 *  Created on: Mar 8, 2024
 *      Author: Youssef
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "std_types.h"
#include "gpio.h"
#include "pwm.h"
#include "common_macros.h"

typedef enum
{
	MOTOR_STOP	,
	MOTOR_CW	,
	MOTOR_A_CW
}	DcMotor_State_t;

typedef enum
{
	FAN_OFF		= 0,
	FAN_ON_25 	= 25,
	FAN_ON_50 	= 50,
	FAN_ON_75 	= 75,
	FAN_ON_100	= 100
}	DcMotor_Speed_t;

void DcMotor_Init(void);

void DcMotor_Rotate(DcMotor_State_t state,DcMotor_Speed_t speed);

#endif /* INC_MOTOR_H_ */
