/*
 * main.c
 *
 */



#include "DAVE.h"                 //Declarations from DAVE Code Generation (includes SFR declaration)

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

#define TESTMODE

#ifdef TESTMODE
#include "BlowerTest.h"
int main(void)
{
  DAVE_STATUS_t status;
  //uint32_t elapsed_time;

  /* Initialisation of DAVE APPs  */
  status = DAVE_Init();
  uint32_t TimerId;
  TIMER_STATUS_t timerStatus;



  if (status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialisation failed\n");

    while(1U)
    {

    }
  }

  TimerId = SYSTIMER_CreateTimer(SYSTIMER_TICK_PERIOD_US,SYSTIMER_MODE_PERIODIC,(void*)runBlowerTest,NULL);
  if(TimerId != 0U)
  {
	  timerStatus = SYSTIMER_StartTimer(TimerId);
	  if(timerStatus == SYSTIMER_STATUS_SUCCESS)
	  {

	  }
	  else {

	  }
   }

 // timer_status = TIMER_Start(&TIMER_0);
  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {
//	  timer_status = TIMER_Clear(&TIMER_0);
//	  timer_status = TIMER_Start(&TIMER_0);
	  runBlowerTest();
      DIGITAL_IO_SetOutputHigh(&LED_0);
      DIGITAL_IO_SetOutputHigh(&LED_1);
      DIGITAL_IO_SetOutputHigh(&LED_2);
	  runBlowerSpeedCtrl();
//	  timer_status = TIMER_Stop(&TIMER_0);
//	  elapsed_time = TIMER_GetTime(&TIMER_0);


  }

}

#endif

#ifndef TESTMODE
int main(void)
{
  DAVE_STATUS_t status;
  //uint32_t elapsed_time;

  /* Initialisation of DAVE APPs  */
  status = DAVE_Init();

  if (status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialisation failed\n");

    while(1U)
    {

    }
  }


 // timer_status = TIMER_Start(&TIMER_0);
  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {
//	  timer_status = TIMER_Clear(&TIMER_0);
//	  timer_status = TIMER_Start(&TIMER_0);
	  DIGITAL_IO_SetOutputHigh(&LED_0);
	  DIGITAL_IO_SetOutputHigh(&LED_1);
	  DIGITAL_IO_SetOutputHigh(&LED_2);
	  runBlowerSpeedCtrl();
//	  timer_status = TIMER_Stop(&TIMER_0);
//	  elapsed_time = TIMER_GetTime(&TIMER_0);


  }

}
#endif





