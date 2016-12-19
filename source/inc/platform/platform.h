#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include <stdint.h>

#include "brandonware/btypes.h"

/**
 * This is for platform specific, non interface code
 */

typedef struct TaskHandle_str * TaskHandle;

/**
 * Registers a task to be periodically run
 * @param func Function pointer for task to be run
 * @param func Period for task to be run in microseconds
 * @return A handle for the task info. Used to be passed to maintenance functions
 */
TaskHandle PeriodicTask_Register( void * func(void), uint32_t period );


void PeriodicTask_Start( TaskHandle handle );
void PeriodicTask_Stop( TaskHandle handle );


/**
 * Terminates a task from the TaskHandle returned by the _Register function
 */
void PeriodicTask_Terminate( TaskHandle handle );


uint32_t Random32(void);


#endif // __PLATFORM_H__
