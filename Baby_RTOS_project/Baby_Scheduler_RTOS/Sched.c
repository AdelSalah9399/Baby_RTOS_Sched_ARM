/*********************************************************************************************************************************
* AUTHOR           	  				VERSION									DATE 						DESCRIPTION 	   	 	 *
* Adel Salah El-Din	  				1.0.0 								14 Jun,2023					- Initial Creation			 *
**********************************************************************************************************************************/
/**********************************************************************************************************************************
* ! Title      	: Baby_Scheduler_RTOS Driver                                                        						      *
* ! File Name	: Sched.c                                                       							              	  	  *
* ! Description : This file has the implementation of Baby_Scheduler_RTOS functions                 							  *
* ! Compiler  	: GNU ARM cross Compiler                                            							                  *
* ! Target 	  	: STM32F401 (M-4) Micro-Controller                                         							              *
* ! Layer 	  	: Baby_Scheduler_RTOS -Driver Layer-                  						                            		  *
**********************************************************************************************************************************/

/************************************************includes*************************************************************************/
#include "../Baby_Scheduler_RTOS/Sched.h"
#include "../Baby_Scheduler_RTOS/Sched_cfg.h"
#include "../MCAL/SYSTICK_PP/SYSTICK_Driver.h"
/*********************************************************************************************************************************/
/************************************************Data Types***********************************************************************/
/*********************************************************************************************************************************/
/*create a struct to list array of ___ptr to runnables___ inside it and create an object from it */
static struct {
	u8 size;
	Runnable_t * Runnable_Task[Max_Task];
}Runnables;
/************************************************Global_Flag***********************************************************************/
u8 SchedIsReady;
/***********************************************************************************************************************************/
/************************************************static functions prototypes********************************************************/
/***********************************************************************************************************************************/
static void Scheduler(void);
static void SCHED_voidREADY(void);
/***********************************************************************************************************************************/
/***********************************************interface functions implementation**************************************************/
/***********************************************************************************************************************************/
void SCHED_voidRegRunnable(const Runnable_t* User_Runnable)
{
	if(User_Runnable != ((void *)0))
	{
		if(Runnables.size <= Max_Task)
		{
			Runnables.Runnable_Task[User_Runnable->priority]=User_Runnable;
			Runnables.size++;
		}
	}
}



/*Function used systick*/
void SCHED_voidInit(void)
{
	STK_voidPeriodMs(SysTickMs);
	STK_voidSetCallBack(SCHED_voidREADY);
}

/*start the systick timer and go into while(1)*/
void SCHED_voidStart(void)
{
	STK_voidStart();
	while(1){
		if(SchedIsReady)
		{
			SchedIsReady=0;
			Scheduler();
		}
	};
}

/***********************************************************************************************************************************/
/*************************************************static functions implementations**************************************************/
/***********************************************************************************************************************************/
static void SCHED_voidREADY(void)
{
	SchedIsReady=1;
}

/*Runs every sys_tick_time to tell the systick timer about the required runnable to be executer*/
static void Scheduler(void)
{	/*time stamp variable it is our scheduler watch */
	static u32 TimeStampMs;
	u32 index;
	if(TimeStampMs)
	{
	for(index=0;index<Max_Task;index++)
	{
		if(Runnables.Runnable_Task[index]!= ((void*)0) && (  (TimeStampMs%(Runnables.Runnable_Task[index]->priodeMs))==0  ) )
		{	//execute user runnable
			Runnables.Runnable_Task[index]->runnable();
		}
	}
	}
	TimeStampMs+= SysTickMs;
}

