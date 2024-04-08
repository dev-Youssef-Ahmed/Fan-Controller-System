 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include <std_types.h>
#include <common_macros.h>

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

typedef enum
{
	AREF_TURNOFF = 0,
	AREF_AVCC	 = 1,
	AREF_INTERNAL= 3
}ADC_ReferenceVolatge;

typedef enum
{
	PSK_2_FCLK  = 1,
	PSK_4_FCLK  ,
	PSK_8_FCLK  ,
	PSK_16_FCLK ,
	PSK_32_FCLK ,
	PSK_64_FCLK ,
	PSK_128_FCLK
}ADC_Prescaler;

typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler		 prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/**
 * \brief Function responsible for initialize the ADC driver.
 *
 * \param adc_config_struct configuration struct for the ADC initiation
 */
void ADC_init(const ADC_ConfigType* adc_config_struct);

/**
 * \brief Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 *
 * \param channel_num ADC channel to read analog value from
 * \return ADC Analog value after conversion
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
