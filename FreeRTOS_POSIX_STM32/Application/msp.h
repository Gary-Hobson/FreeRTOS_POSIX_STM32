#ifndef MSP_H_
#define MSP_H_

#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "main.h" 

#define TRACE(fmt, ...)  \
				do { \
						printf(fmt,##__VA_ARGS__);fflush(stdout);\
				} while(0)

#define TRACE_INFO(fmt, ...)  \
				do { \
						printf("%ld,%s,%d::"fmt,HAL_GetTick(), __func__,__LINE__,##__VA_ARGS__);\
				} while(0)


uint32_t millis(void);

static inline void delay(uint32_t ms)
{
	HAL_Delay(ms);
}
				
#endif
