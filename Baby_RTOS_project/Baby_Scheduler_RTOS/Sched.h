/*********************************************************************************************************************************
* AUTHOR           	  				VERSION									DATE 						DESCRIPTION 	   	 	 *
* Adel Salah El-Din	  				1.0.0 								14 Jun,2023					- Initial Creation			 *
**********************************************************************************************************************************/
/**********************************************************************************************************************************
* ! Title      	: Baby_Scheduler_RTOS Driver                                                        						      *
* ! File Name	: Sched.h                                                       							              	  	  *
* ! Description : This file has the Baby_Scheduler functions prototypes and Options Macros for function Arguments                 *
* ! Compiler  	: GNU ARM cross Compiler                                            							                  *
* ! Target 	  	: STM32F401 (M-4) Micro-Controller                                         							              *
* ! Layer 	  	: Baby_Scheduler_RTOS -Driver Layer-                  						                            		  *
**********************************************************************************************************************************/
#ifndef SCHED_H_
#define SCHED_H_

/************************************************includes**************************************************************************/
#include "../Baby_Scheduler_RTOS/Sched_cfg.h"
#include "../common/STD_TYPE.h"
/************************************************Data_Types*************************************************************************/
typedef struct
{
	void (*runnable)(void);
	u32 priodeMs;
	u8 priority;
	char * Name;

}Runnable_t;
/***********************************************************************************************************************************/
/************************************************Functions Prototypes***************************************************************/
/***********************************************************************************************************************************/

/***************************************************************************
* Function Name		: SCHED_voidInit
* Parameters (in)	: NONE
* Parameters (out)	: NONE
* Return value		: void
* Description		: Function used to Init scheduler
* Constrains		: NONE
* *************************************************************************/
extern void SCHED_voidInit(void);

/***************************************************************************
* Function Name		: SCHED_voidStart
* Parameters (in)	: NONE
* Parameters (out)	: NONE
* Return value		: void
* Description		: Function used to Start scheduler
* Constrains		: NONE
* *************************************************************************/
extern void SCHED_voidStart(void);

/***************************************************************************
* Function Name		: GPIO_SetAlternativeFunction
* Parameters (in)	: address of [Runnable_t] data type
* Parameters (out)	: NONE
* Return value		: void
* Description		: Function used to Add Runnable Task
* Constrains		: NONE
* *************************************************************************/
extern void SCHED_voidRegRunnable(const Runnable_t* User_Runnable);

#endif /* SCHED_H_ */
