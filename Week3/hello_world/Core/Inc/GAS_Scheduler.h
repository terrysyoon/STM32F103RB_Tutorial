#ifndef INC_GAS_SCHEDULER_H_
#define INC_GAS_SCHEDULER_H_

#include "stm32f1xx_hal.h"

typedef struct{
	volatile uint8_t flag_1ms;
	volatile uint8_t flag_10ms;
	volatile uint8_t flag_100ms;
	volatile uint8_t flag_1000ms;

	uint8_t flag_initialized;
}Scheduler_task;

extern Scheduler_task gTask;

extern void GAS_Scheduler_init(void);
extern void GAS_Scheduler(void);
#endif /* INC_GAS_SCHEDULER_H_ */
