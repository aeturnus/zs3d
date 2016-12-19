#include <stdlib.h>

#include <SDL2/SDL.h>

#include "platform/platform.h"

#include "sdl.h"

int Systems_Init(void)
{
    sdl_init();
}

typedef struct TaskHandle_str
{
    int valid;
    int enabled;
    uint32_t period;
    void (*function)(void*);
    void * param;
    SDL_Thread *thread;
} TaskHandle_Rec;

#define NUM_TASKHANDLE 4
static TaskHandle_Rec table[NUM_TASKHANDLE] = {{0,0},{0,0},{0,0},{0,0}};

static allocs = 0;

static int PeriodicTask_Runner(void * param)
{
    TaskHandle handle = (TaskHandle) param;
    while(handle->valid)
    {
        if(handle->enabled)
        {
            handle->function(handle->param);
        }
        SDL_Delay(handle->period/1000);
    }
    return 0;
}

TaskHandle PeriodicTask_Register( void * func(void *), void * param, uint32_t period )
{
    for(int i = 0; i < NUM_TASKHANDLE; i++)
    {
        if(!table[i].valid)
        {
            table[i].valid = 1;
            table[i].enabled= 0;
            table[i].period = period;
            table[i].function = func;
            table[i].param = param;
            // create thread
            table[i].thread = SDL_CreateThread(PeriodicTask_Runner, "", &table[i]);

            return &table[i];
        }
    }
    return NULL;
}

void PeriodicTask_Start( TaskHandle handle )
{
    handle->enabled = 1;
}

void PeriodicTask_Stop( TaskHandle handle )
{
    handle->enabled = 0;
}

void PeriodicTask_Terminate( TaskHandle handle )
{
    handle->valid = 0;
}

void Random_Init(uint32_t seed)
{
    srand(seed);
}

uint32_t Random32(void)
{
    uint16_t output = Random16() << 16 | Random16();
    return output;
}

uint16_t Random16(void)
{
    return rand() & 0xFFFF;
}

uint8_t Random8(void)
{
    return rand() & 0xFF;
}
