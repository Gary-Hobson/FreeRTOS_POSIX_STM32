#include "msp.h"

extern UART_HandleTypeDef huart1;

UART_HandleTypeDef *debugout=&huart1;

#ifdef __GNUC__
  int _write(int file, char *ptr, int len)
  {
      HAL_UART_Transmit((UART_HandleTypeDef *)debugout, (uint8_t *)ptr, len, 1000*len);
      return len;
  }
#else
  int fputc(int ch, FILE *f)
  {
    HAL_UART_Transmit((UART_HandleTypeDef *)debugout, (uint8_t *)&ch, 1, 1000);
    return ch;
  }
#endif 

#if 1
void HAL_IncTick(void)
{

  extern __IO uint32_t uwTick;

  #if defined(STM32F1) || defined(STM32L0)
  uwTick += uwTickFreq;
  #endif
  
  if((uwTick&(uint32_t)0x1ff)==0){
     HAL_GPIO_TogglePin(GPIOE,GPIO_PIN_5);
  }
}
#endif

uint32_t millis(void)
{
    return HAL_GetTick();  
}


