/*
 * timer0.h
 *
 *  Created on: Feb 22, 2022
 *      Author: MahmoudLabib
 */

#ifndef SRC_MCAL_TIMER0_TIMER0_H_
#define SRC_MCAL_TIMER0_TIMER0_H_
#include "../../utils/std_types.h"


/*******************************************************************************
 *                                  Types
 * *****************************************************************************/
typedef enum {
     NO_CLOCK,NO_Precaling,prescaler_8,prescaler_16,prescaler_32,prescaler_64,prescaler_128
}TIMER0_PrescalerTypes;


/*******************************************************************************
 *                           Functions Prototype
 ********************************************************************************/
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* SRC_MCAL_TIMER0_TIMER0_H_ */
