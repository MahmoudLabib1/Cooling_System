/*
 * dc_motor.h
 *
 *  Created on: Feb 22, 2022
 *      Author: MahmoudLabib
 */

#ifndef SRC_EHAL_DC_MOTOR_DC_MOTOR_H_
#define SRC_EHAL_DC_MOTOR_DC_MOTOR_H_

#include "../../utils/std_types.h"

/*******************************************************************************
 *                                  Types
 * *****************************************************************************/
typedef enum {
	DC_Motor_stop,DC_Motor_CW,DC_Motor_ACW
}DC_MOTOR_State;
/*******************************************************************************
 *                           Functions Prototype
 ********************************************************************************/
void DcMotor_Init(void);
void DcMotor_Rotate(DC_MOTOR_State state,uint8 speed);
#endif /* SRC_EHAL_DC_MOTOR_DC_MOTOR_H_ */
