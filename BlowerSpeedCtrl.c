/*
 * BlowerSpeedCtrl.c
 *
 *  Created on: Sep 26, 2024
 *      Author: YiJie
 */

#include "BlowerSpeedCtrl.h"

void runBlowerSpeedCtrl(void)
{
    static uint8_t inBlowerSpeedCmd;
    static uint8_t inRightTempCmd;
    static uint8_t inLeftTempCmd;
    int32_t CANstatus;

    //	TIMER_STATUS_t timer_status;
//    timer_status = TIMER_Clear(&TIMER_0);
//	timer_status = TIMER_Start(&TIMER_0);
    //	uint32_t elapsed_time;

    /* Check if a new CAN message was received in message object 1 */
    CANstatus = CAN_NODE_MO_GetStatus(&BcmNode_LMO_01_Config);


    if (CANstatus & XMC_CAN_MO_STATUS_RX_PENDING)
    {
        CAN_NODE_MO_ClearStatus(&BcmNode_LMO_01_Config, XMC_CAN_MO_RESET_STATUS_RX_PENDING);
        CAN_NODE_MO_Receive(&BcmNode_LMO_01_Config);
        inLeftTempCmd = BcmNode_LMO_01_Config.mo_ptr->can_data_byte[4] & 0x3F;
        inRightTempCmd = BcmNode_LMO_01_Config.mo_ptr->can_data_byte[5] & 0x3F;
        inBlowerSpeedCmd = BcmNode_LMO_01_Config.mo_ptr->can_data_byte[6] & 0x0F;
        if (inBlowerSpeedCmd & 1) {
        	DIGITAL_IO_SetOutputLow(&LED_0);
        }
        if (inBlowerSpeedCmd & 2) {
        	DIGITAL_IO_SetOutputLow(&LED_1);
        }
        if (inBlowerSpeedCmd & 4) {
        	DIGITAL_IO_SetOutputLow(&LED_2);
        }
        PWM_SetDutyCycle(&BlowerPWM, inBlowerSpeedCmd * 1400);

    }
//    timer_status = TIMER_Stop(&TIMER_0);
//    elapsed_time = TIMER_GetTime(&TIMER_0);



}
