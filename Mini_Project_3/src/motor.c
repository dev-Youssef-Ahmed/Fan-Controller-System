/*
 * motor.c
 *
 *  Created on: Mar 8, 2024
 *      Author: Youssef
 */

#include "motor.h"

static DcMotor_State_t motor_state;
static DcMotor_Speed_t motor_speed;

void DcMotor_Init(void)
{
	/* initialize motor EN1 pin */
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);
	GPIO_writePin(PORTB_ID, PIN3_ID, LOGIC_LOW);

	/* initialize IN1 pin */
	GPIO_setupPinDirection(PORTB_ID, PIN4_ID, PIN_OUTPUT);
	GPIO_writePin(PORTB_ID, PIN4_ID, LOGIC_LOW);

	/* initialize IN2 pin */
	GPIO_setupPinDirection(PORTB_ID, PIN5_ID, PIN_OUTPUT);
	GPIO_writePin(PORTB_ID, PIN5_ID, LOGIC_LOW);

	/* Set timer to 0 duty cycle */
	Timer0_PWM_Init(STOP);

	/* set the initial motor state as STOP */
	motor_state = MOTOR_STOP;
	motor_speed = FAN_OFF;
	DcMotor_Rotate(motor_state, motor_speed);
}

/* This function will rotate the motor with a direction and speed which are passed to it as inputs*/
/* The states are: stop, clockwise (CW), and anti-clockwise (A_CW), A_CW will not be used in our application */
void DcMotor_Rotate(DcMotor_State_t state, DcMotor_Speed_t speed)
{
	/* check if current state was changed that that stored in the global variable */
	if (state != motor_state)
	{
		/* Now the motor state changed, so lets check to which state exactly */
		switch(state)
		{
			case MOTOR_CW:
			{
				/* start PWM with the given speed */
				Timer0_PWM_Init(speed);

				/* Rotate the motor CW */
				GPIO_writePin(PORTB_ID, PIN4_ID, LOGIC_HIGH);
				GPIO_writePin(PORTB_ID, PIN5_ID, LOGIC_LOW);

				/* Change the current state of the global variable */
				motor_state = MOTOR_CW;

				break;
			}

			case MOTOR_A_CW:
			{
				/* start PWM with the given speed */
				Timer0_PWM_Init(speed);

				/* Rotate the motor A-CW */
				GPIO_writePin(PORTB_ID, PIN4_ID, LOGIC_LOW);
				GPIO_writePin(PORTB_ID, PIN5_ID, LOGIC_HIGH);

				/* Change the current state of the global variable */
				motor_state = MOTOR_A_CW;
				break;
			}
			/* Add this empty default here so if any undefined state occurs,
			 * then the motor will go to stop case directly */
			default:

			case MOTOR_STOP:
			{
				/* stop the PWM and the EN1 */
				Timer0_PWM_Init(STOP);
				/* Stop the motor by applying HIGH on both of its INs
				 * Note:	Applying LOW works too! but HIGH is better to
				 * 			be not care to any noise signals may occur */
				GPIO_writePin(PORTB_ID, PIN4_ID, LOGIC_HIGH);
				GPIO_writePin(PORTB_ID, PIN5_ID, LOGIC_HIGH);

				/* Change the current state of the global variable */
				motor_state = MOTOR_STOP;
				break;
			}
		}
	}
	/* if the state not changed, keep rotating the motor with the required speed */
	else
	{
		Timer0_PWM_Init(speed);
	}
}
