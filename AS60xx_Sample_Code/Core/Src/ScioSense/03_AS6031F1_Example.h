#ifndef AS6031F1_EXAMPLE_H
#define AS6031F1_EXAMPLE_H

#include <inttypes.h>
#include "stm32u3xx_hal.h"

#ifndef AS60XX_PIN_DEFINITIONS
#define SCK_Pin             GPIO_PIN_5
#define SCK_GPIO_Port       GPIOA
#define MISO_Pin            GPIO_PIN_6
#define MISO_GPIO_Port      GPIOA
#define MOSI_Pin            GPIO_PIN_7
#define MOSI_GPIO_Port      GPIOA
#define INTN_Pin            GPIO_PIN_7
#define INTN_GPIO_Port      GPIOC
#define SSN_Pin             GPIO_PIN_9
#define SSN_GPIO_Port       GPIOC
#endif // AS60XX_PIN_DEFINITIONS

#ifdef __cplusplus
extern "C" {
#endif

void AS60xx_Example_Setup(UART_HandleTypeDef *uart, SPI_HandleTypeDef *spi);
void AS60xx_Example_Loop();

#ifdef __cplusplus
}
#endif

#endif // AS6031F1_EXAMPLE_H