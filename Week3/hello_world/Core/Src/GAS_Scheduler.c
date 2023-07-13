#include "GAS_Scheduler.h"

#define False 0
#define True 1

volatile int gTimerCnt;
Scheduler_task gTask;

void GAS_Scheduler_init(void);
void GAS_Scheduler_taskCounter_1ms(void);
void GAS_Scheduler_taskCounter_10ms(void);
void GAS_Scheduler_taskCounter_100ms(void);
void GAS_Scheduler_taskCounter_1000ms(void);
void GAS_Scheduler(void);

void GAS_Scheduler_init(void)
{
	/*
	uint32_t systemClockFreq = GAS_getSystemCoreClock(); //HCLK in HZ

	SysTick_Config(systemClockFreq/1000);
*/
	SysTick_Config(72000000/1000);
	gTask.flag_initialized = True;

}

void GAS_Scheduler_taskCounter_1ms(void)
{
	//GAS_Adc_getValue();
}

void GAS_Scheduler_taskCounter_10ms(void)
{
	//GAS_Can_sendMessage();
}

void GAS_Scheduler_taskCounter_100ms(void)
{
	//HAL_GPIO_TogglePin(GPIOB, BlueLED_Pin);
	// HAL_GPIO_WritePin(GPIOB, LED03_Pin|LED02_Pin|LED01_Pin|LED00_Pin, GPIO_PIN_RESET);
	//HAL_GPIO_TogglePin(GPIOB, LED00_Pin/*|LED02_Pin|LED01_Pin|LED00_Pin*/);
	//HAL_GPIO_TogglePin(GPIOC, LED10_Pin|LED11_Pin);

	//LED03이 Reset LED
}

void GAS_Scheduler_taskCounter_1000ms(void)
{
	//HAL_GPIO_WritePin(LED2_Port, LED2_Pin, GPIO_PIN_RESET);
}

//Ref: https://jexe.tistory.com/4
void HAL_SYSTICK_Callback(void)
{

	gTimerCnt++;
	gTask.flag_1ms = True;
	if(gTimerCnt % 10 == 0)
	{
		gTask.flag_10ms = True;
	}
	if(gTimerCnt % 100 == 0)
	{
		gTask.flag_100ms = True;
	}
	if(gTimerCnt % 1000 == 0)
	{
		gTask.flag_1000ms = True;
	}

	/*
	a++;
	if(a  % 10 == 0) { //10ms past

	}
	if(a % 100 == 0) { //100ms past
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
	}
	if(a % 1000 == 0) { //1000ms past
		a = 0;
	}*/
}

void GAS_Scheduler(void)
{
	if(gTask.flag_1ms == True)
	{
		gTask.flag_1ms = False;
		GAS_Scheduler_taskCounter_1ms();
	}

	if(gTask.flag_10ms == True)
	{
		gTask.flag_10ms = False;
		GAS_Scheduler_taskCounter_10ms();
	}

	if(gTask.flag_100ms == True)
	{
		gTask.flag_100ms = False;
		GAS_Scheduler_taskCounter_100ms();
	}

	if(gTask.flag_1000ms == True)
	{
		gTask.flag_1000ms = False;
		GAS_Scheduler_taskCounter_1000ms();
	}
}
