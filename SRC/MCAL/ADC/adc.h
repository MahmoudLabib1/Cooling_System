/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Mahmoud_Labib
 *
 *******************************************************************************/

#ifndef SRC_MCAL_ADC_ADC_H_
#define SRC_MCAL_ADC_ADC_H_

#include "../../utils/std_types.h"

/*******************************************************************************
 *                                  TYPES
 * *****************************************************************************/
typedef enum {
	EXTRNAL_AREF,AVCC,RES,INTERNAL_Vref
}ADC_VrefTypes;

typedef enum {
     defult,prescaler_2_,prescaler_4_,prescaler_8_,prescaler_16_,prescaler_32_,prescaler_64_,prescaler_128_
}ADC_PrescalerTypes;


typedef struct
{
	ADC_VrefTypes ref_volt;
	ADC_PrescalerTypes prescaler;
}ADC_ConfigType;


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern Public global variables to be used by other modules */
extern volatile uint16 g_adcResult;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* SRC_MCAL_ADC_ADC_H_ */
