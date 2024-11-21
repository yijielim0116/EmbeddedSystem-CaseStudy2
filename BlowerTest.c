/*
 * BlowerTest.c
 *
 */
#define TESTMODE

#ifdef TESTMODE
#include "BlowerTest.h"
void runBlowerTest(void)
{


//TIMER_STATUS_t timer_status;
//uint32_t elapsed_time;

volatile static uint8_t simBlowerSpeedCmd;
volatile static uint8_t simRightTempCmd;
volatile static uint8_t simLeftTempCmd;

CAN_NODE_STATUS_t status;
uint8_t can_data_arr[8];

can_data_arr[4] = simLeftTempCmd;
can_data_arr[5] = simRightTempCmd;
can_data_arr[6] = simBlowerSpeedCmd;

//timer_status = TIMER_Clear(&TIMER_0);
//timer_status = TIMER_Start(&TIMER_0);

status = CAN_NODE_MO_UpdateData(&TestNode_LMO_01_Config, can_data_arr);
if (status == CAN_NODE_STATUS_SUCCESS)
    {
        CAN_NODE_MO_Transmit(&TestNode_LMO_01_Config);
    }
//timer_status = TIMER_Stop(&TIMER_0);
//elapsed_time = TIMER_GetTime(&TIMER_0);
}

#endif

