/*******************************************************************************
 * Module: Mini_Project3
 *
 * File Name: mini_Project_3.c
 *
 * Description: Source File for mini_project3 to control the speed of fan motor
 *              Depend on LM35 temperature sensor and display the degree and
 *              State of motor on LCD using Atmega16 MCU
 *
 * Author: Mahmoud_Labib
 *
 *******************************************************************************/
#include "../../SRC/MCAL/ADC/adc.h"
#include "../../SRC/MCAL/GPIO/gpio.h"
#include "../../SRC/MCAL/TIMER0/timer0.h"
#include "../../SRC/EHAL/TEMP_LM35/lm35.h"
#include "../../SRC/EHAL/LCD/lcd.h"
#include "../../SRC/EHAL/DC_MOTOR/dc_motor.h"



void mini_project_3(){
	/* Configure the Prescaler clk/8
	 *  And set Internal_Vref 2.56V */
	ADC_ConfigType config ={INTERNAL_Vref,prescaler_8_};

	/* initialize GPIO Pins that the DC_Motor will use it */
	DcMotor_Init();

	/* initialize GPIO Pins LCD
	 * Choose LCD_DATA_BITS_MODE */
	LCD_init();

	/* initialize ADC module to work with a specific ref_volt and Prescaler  */
	ADC_init(&config);

	while(1){

		if((LM35_getTemperature())<30){
			DcMotor_Rotate(DC_Motor_stop,0);  // 0 step -> 0% duty_cycle

			// Move the Cursor to specific position on LCD Here Row:0 , COL:3
			LCD_moveCursor(0,3);

			// Write The String in the Position of Cursor
			LCD_displayString("FAN IS OFF");

			// Move the Cursor to other position on LCD Here Row:1 , COL:3
			LCD_moveCursor(1,3);

			// Write The String in the new Position of Cursor
			LCD_displayString("Temp =    C");

			// Move the Cursor to the Space Position
			LCD_moveCursor(1,10);

			// Write in the cursor position the degree of Temperature
			LCD_intgerToString(LM35_getTemperature());
		}
		else if(((LM35_getTemperature())>=30) && ((LM35_getTemperature())<60)){
			DcMotor_Rotate(DC_Motor_CW,64);  // 64 step -> 25% duty_cycle

			LCD_moveCursor(0,3);
			LCD_displayString("FAN IS ON ");

			LCD_moveCursor(1,3);
			LCD_displayString("Temp =    C");
			LCD_moveCursor(1,10);
			LCD_intgerToString(LM35_getTemperature());
		}
		else if(((LM35_getTemperature()))>=60 && ((LM35_getTemperature())<90)){
			DcMotor_Rotate(DC_Motor_CW,128);  // 128 step -> 50% duty_cycle

			LCD_moveCursor(0,3);
			LCD_displayString("FAN IS ON ");
			LCD_moveCursor(1,3);
			LCD_displayString("Temp =    C");
			LCD_moveCursor(1,10);
			LCD_intgerToString(LM35_getTemperature());
		}
		else if(((LM35_getTemperature())>=90) && ((LM35_getTemperature())<120)){
			DcMotor_Rotate(DC_Motor_CW,191);  // 191 step -> 75% duty_cycle

			LCD_moveCursor(0,3);
			LCD_displayString("FAN IS ON ");
			LCD_moveCursor(1,3);
			LCD_displayString("Temp =    C");
			LCD_moveCursor(1,10);
			LCD_intgerToString(LM35_getTemperature());
		}
		else{
			DcMotor_Rotate(DC_Motor_CW,255);  // 255 step -> 100% duty_cycle

			LCD_moveCursor(0,3);
			LCD_displayString("FAN IS ON ");
			LCD_moveCursor(1,3);
			LCD_displayString("Temp =    C");
			LCD_moveCursor(1,10);
			LCD_intgerToString(LM35_getTemperature());
		}
	}
}
