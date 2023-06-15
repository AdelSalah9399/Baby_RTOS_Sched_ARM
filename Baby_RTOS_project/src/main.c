
#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"

#include "../MCAL/RCC/RCC_Driver.h"
#include "../MCAL/GPIO/GPIO_Driver.h"
#include "../MCAL/SYSTICK_PP/SYSTICK_Driver.h"
#include "../Baby_Scheduler_RTOS/Sched.h"


void Task1(void);
void Task2(void);
void Task3(void);


/*__________________________________Creat_Runnables_Tasks____________________________________________*/
const Runnable_t Task1_Runnable={
		.Name="APP1",
		.priodeMs=1000,
		.priority=0,
		.runnable=Task1,
};

const Runnable_t Task2_Runnable={
		.Name="APP2",
		.priodeMs=4000,
		.priority=1,
		.runnable=Task2,
};

const Runnable_t Task3_Runnable={
		.Name="APP3",
		.priodeMs=6000,
		.priority=2,
		.runnable=Task3,
};

/*___________________________________________________main_____________________________________________________________*/
void main()
{
	/*GPIO_INIT*/
	MRCC_ret_tEnablePeripheralClk(peri_AHB1_GPIOA,peri_busAHB1);
	GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_MODE_OUTPUT);
	GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_MODE_OUTPUT);
	GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN2,GPIO_MODE_OUTPUT);

	/*Adding_Tasks_to_scheduler*/
	SCHED_voidRegRunnable(&Task1_Runnable);
	SCHED_voidRegRunnable(&Task2_Runnable);
	SCHED_voidRegRunnable(&Task3_Runnable);


	/*Scheduler_INIT*/
	SCHED_voidInit();

	/*Scheduler_START*/
	SCHED_voidStart();

}
/*__________________________________Creat_Runnables_Functions_Implementation____________________________________________*/
void Task1(void)
{	static u32 counter;
	if(counter%2==0)
	{
		GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_VALUE_HIGH);
	}
	else
	{
		GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_VALUE_LOW);
	}
	counter++;
}

void Task2(void)
{	static u32 counter;
	if(counter%2==0)
	{
		GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_VALUE_HIGH);
	}
	else
	{
		GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_VALUE_LOW);
	}
	counter++;
}

void Task3(void)
{	static u32 counter;
	if(counter%2==0)
	{
		GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_VALUE_HIGH);
	}
	else
	{
		GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_VALUE_LOW);
	}
	counter++;
}
