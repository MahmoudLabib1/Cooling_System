/*******************************************************************************
 * Module: DC Motor
 *
 * File Name: dc_motor.c
 *
 * Description: Source File for the DC Motor driver
 *
 * Author: Mahmoud_Labib
 *
 *******************************************************************************/

#include "../../MCAL/GPIO/gpio.h"
#include "../../EHAL/DC_MOTOR/dc_motor.h"
#include "../../MCAL/TIMER0/timer0.h"

//extern uint8 g_speed;

void DcMotor_Init(void)
{    /* Set the direction pins for DC Motor as Output Pins from PORTB */
	GPIO_setPinDir(PORTB_ID,PIN0_ID,OUTPUT_PIN);
	GPIO_setPinDir(PORTB_ID,PIN1_ID,OUTPUT_PIN);
	GPIO_setPinDir(PORTB_ID,PIN3_ID,OUTPUT_PIN);
	/* Write Zero On Pins To Output 0V */
	GPIO_writePin(PORTB_ID,PIN0_ID , LOGIC_LOW);
	GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
	GPIO_writePin(PORTB_ID, PIN3_ID, LOGIC_LOW);
}


void DcMotor_Rotate(DC_MOTOR_State state,uint8 speed)
{
		//g_speed =speed;
	    /* Pass the Speed value to the PWM function as parameter
	     * And PWM function will calculate the duty_cycle
	     *   */
		PWM_Timer0_Start(speed);

	switch(state){
	case DC_Motor_stop:
		GPIO_writePin(PORTB_ID,PIN0_ID , LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);

		break;
	case DC_Motor_CW:
		GPIO_writePin(PORTB_ID,PIN0_ID , LOGIC_HIGH);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);

		break;
	case DC_Motor_ACW:
		GPIO_writePin(PORTB_ID,PIN0_ID , LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_HIGH);

		break;
	}
}
