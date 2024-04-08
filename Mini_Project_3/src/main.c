/*
 * Mini-Project 3	:	Fan Controller System
 * Facebook Name	:	Youssef Ahmed
 * Diploma Number	:	85
 */

/*
 * Note 1:	MISRA rules were applied to some extent in this project!
 * Note 2:	The project consists of seven .c files and nine .h files
 * Note 3:	Don't forget to assign "inc" folder as the include path to use <main.h>
 */

/*
 * I.	Project Properties
 * II.	C/C++ Build
 * III.	Settings
 * IV.	Tool Settings
 * V.	AVR Compiler
 * VI.	Directories
 * VII.	Include Paths (-|): should be "${workspace_loc:/${ProjName}/inc}"
 */

#include <main.h>

int main( void )
{
	/* Initiate the ADC using its configurable reference voltage and pre-scaler */
	ADC_ConfigType ADC_parameters = {AREF_INTERNAL, PSK_8_FCLK};
	ADC_init(&ADC_parameters);

	/* Calculate temperature */
	g_current_temp = LM35_getTemperature();

	/* Set the motor initial value */
	DcMotor_Init();

	/* Initialize LCD */
	LCD_init();

	/*
	 * The LCD should always display as following:
	 * Temp = VVV deg C
	 * Fan: OSS  (PPPP)
	 *
	 * where	VVV :	3-digit temperature
	 * 			SS 	:	2-digit N or FF as ON / OFF state
	 * 			PPPP:	3-digit fan speed + % symbol
	 * 				or	4-digit "STOP" word as speed = ZERO
	 * All other characters are fixed
	 */

	LCD_moveCursor(ROW_0,COL_0);
	LCD_displayString("Temp =     deg C");

	LCD_moveCursor(ROW_1,COL_0);
	LCD_displayString("Fan: O    (    )");

	/* For the 1st milliseconds, OFF state will appear */
	LCD_moveCursor(ROW_1,COL_6);
	LCD_displayString("FF");
	LCD_moveCursor(ROW_1,COL_11);
	LCD_displayString("STOP");

	while(TRUE)
	{
		/* continuously calculate the temperature */
		g_current_temp = LM35_getTemperature();

		/* check if temperature value changed.
		 * purpose: to update VVV only if changed, this will decrease blinking */
		if(g_current_temp != g_displayed_temp)
		{
			/* free 3-digit space for VVV */
			LCD_moveCursor(ROW_0,COL_7);
			LCD_displayString("   ");
			/* print the new VVV */
			LCD_moveCursor(ROW_0,COL_7);
			LCD_intgerToString(g_current_temp);
			/* update the displayed temperature value */
			g_displayed_temp = g_current_temp;
		}

		/* check the range of the temperature to set the state
		 * and speed then rotate the motor accordingly */
		if		(g_current_temp >= TEMP_0 && g_current_temp < TEMP_30)
		{
			g_current_speed = FAN_OFF;
			g_current_state = MOTOR_STOP;
			DcMotor_Rotate(g_current_state, g_current_speed);

			/* check if temperature value changed.
			 * purpose: to update VVV only if changed, this will decrease blinking */
			if(g_current_state != g_displayed_state)
			{
				/* free 2-digit space for SS */
				LCD_moveCursor(ROW_1,COL_6);
				LCD_displayString("  ");
				/* print the new SS */
				LCD_moveCursor(ROW_1,COL_6);
				LCD_displayString("FF");
				g_displayed_state = g_current_state;
			}

			/* check if temperature value changed.
			 * purpose: to update VVV only if changed, this will decrease blinking */
			if(g_current_speed != g_displayed_speed)
			{
				/* free 4-digit space for PPPP */
				LCD_moveCursor(ROW_1,COL_11);
				LCD_displayString("  ");
				/* print the new PPPP */
				LCD_moveCursor(ROW_1,COL_11);
				LCD_displayString("STOP");
				g_displayed_speed = g_current_speed;
			}
		}


		else if (g_current_temp >= TEMP_30 && g_current_temp < TEMP_60)
		{
			g_current_speed = FAN_ON_25;
			g_current_state = MOTOR_CW;
			DcMotor_Rotate(g_current_state, g_current_speed);

			if(g_current_state != g_displayed_state)
			{
				/* free 2-digit space for SS */
				LCD_moveCursor(ROW_1,COL_6);
				LCD_displayString("  ");
				/* print the new SS */
				LCD_moveCursor(ROW_1,COL_6);
				LCD_displayString("N ");
				g_displayed_state = g_current_state;
			}

			if(g_current_speed != g_displayed_speed)
			{
				/* free 4-digit space for PPPP */
				LCD_moveCursor(ROW_1,COL_11);
				LCD_displayString("  ");
				/* print the new PPPP */
				LCD_moveCursor(ROW_1,COL_11);
				LCD_displayString(" 25%");
				g_displayed_speed = g_current_speed;
			}
		}

		else if (g_current_temp >= TEMP_60 && g_current_temp < TEMP_90)
		{
			g_current_speed = FAN_ON_50;
			g_current_state = MOTOR_CW;
			DcMotor_Rotate(g_current_state, g_current_speed);

			if(g_current_state != g_displayed_state)
			{
				/* free 2-digit space for SS */
				LCD_moveCursor(ROW_1,COL_6);
				LCD_displayString("  ");
				/* print the new SS */
				LCD_moveCursor(ROW_1,COL_6);
				LCD_displayString("N ");
				g_displayed_state = g_current_state;
			}

			if(g_current_speed != g_displayed_speed)
			{
				/* free 4-digit space for PPPP */
				LCD_moveCursor(ROW_1,COL_11);
				LCD_displayString("  ");
				/* print the new PPPP */
				LCD_moveCursor(ROW_1,COL_11);
				LCD_displayString(" 50%");
				g_displayed_speed = g_current_speed;
			}
		}

		else if (g_current_temp >= TEMP_90 && g_current_temp < TEMP_120)
		{
			g_current_speed = FAN_ON_75;
			g_current_state = MOTOR_CW;
			DcMotor_Rotate(g_current_state, g_current_speed);

			if(g_current_state != g_displayed_state)
			{
				/* free 2-digit space for SS */
				LCD_moveCursor(ROW_1,COL_6);
				LCD_displayString("  ");
				/* print the new SS */
				LCD_moveCursor(ROW_1,COL_6);
				LCD_displayString("N ");
				g_displayed_state = g_current_state;
			}

			if(g_current_speed != g_displayed_speed)
			{
				/* free 4-digit space for PPPP */
				LCD_moveCursor(ROW_1,COL_11);
				LCD_displayString("  ");
				/* print the new PPPP */
				LCD_moveCursor(ROW_1,COL_11);
				LCD_displayString(" 75%");
				g_displayed_speed = g_current_speed;
			}
		}

		else
		{
			g_current_speed = FAN_ON_100;
			g_current_state = MOTOR_CW;
			DcMotor_Rotate(g_current_state, g_current_speed);

			if(g_current_state != g_displayed_state)
			{
				/* free 2-digit space for SS */
				LCD_moveCursor(ROW_1,COL_6);
				LCD_displayString("  ");
				/* print the new SS */
				LCD_moveCursor(ROW_1,COL_6);
				LCD_displayString("N ");
				g_displayed_state = g_current_state;
			}

			if(g_current_speed != g_displayed_speed)
			{
				/* free 4-digit space for PPPP */
				LCD_moveCursor(ROW_1,COL_11);
				LCD_displayString("  ");
				/* print the new PPPP */
				LCD_moveCursor(ROW_1,COL_11);
				LCD_displayString("100%");
				g_displayed_speed = g_current_speed;
			}

		}
		/* Add delay to ensure LCD works properly */
		_delay_ms(100);
	}
}
