#include "03_AS6031F1_Example.h"
#include "src/ScioSense_AS60XX.h"
#include <cstdio>
#include <cstring>

static char messageBuffer[128];         // Buffer for sending data through Serial
static UART_HandleTypeDef huart;

static AS6031f1 as6031f1;

static Result SerialPrint(const char str[]);

extern "C" void AS60xx_Example_Setup(UART_HandleTypeDef *uart, SPI_HandleTypeDef *spi)
{
    huart = *uart;
    // Wait to allow terminal software to capture the output
    HAL_Delay(2000);

    SerialPrint("Starting AS6031F1 03_AS6031F1_Example demo on STM32...\n");

    HAL_Delay(AS60XX_BOOTUP_COMM_RELEASE_TIME_MAX_MS);

    as6031f1.begin(spi, SSN_Pin, SSN_GPIO_Port);

    if( as6031f1.reset() == RESULT_OK )
    {
        SerialPrint("AS6031F1 initialized properly\n");
    }
    else
    {
        SerialPrint("AS6031F1 initialization failed\n");
    }
    HAL_Delay(1000);
}

extern "C" void AS60xx_Example_Loop()
{
    As6031F1_ErrorFlag errorsToCheck[] = {FW_ERR_MEAS_NOT_OK, FW_ERR_BUBBLE};
    uint8_t amountErrorsToCheck = (uint8_t)( sizeof(errorsToCheck) / sizeof(errorsToCheck[0]) );

    while( 1 )
    {
        if( !HAL_GPIO_ReadPin(INTN_GPIO_Port, INTN_Pin) )
        {
            as6031f1.updateF1();
            
            // Print the accumulated flow in cubic meters
            sprintf(messageBuffer, "AccumulatedVolume[m3]:%0.6f\t", as6031f1.getF1VolumeM3());
            SerialPrint(messageBuffer);
            
            // Print the current flow rate in litres per hour
            sprintf(messageBuffer, "FlowRate[l_per_hr]:%0.3f\t",    as6031f1.getF1InstantFlowLPerHr());
            SerialPrint(messageBuffer);
            
            // Print the temperature in degrees celsius
            sprintf(messageBuffer, "Temperature[degC]:%0.2f\t",     as6031f1.getF1TemperatureDegC());
            SerialPrint(messageBuffer);

            for( uint8_t errorIdx = 0; errorIdx < amountErrorsToCheck; errorIdx++ )
            {
                if( as6031f1.hasF1ErrorFlag(errorsToCheck[errorIdx]) )
                {
                    SerialPrint("\tError detected: ");
                    SerialPrint( as6031f1.errorF1ToString(errorsToCheck[errorIdx]) );
                }
            }
            SerialPrint("\n");
        }
    }
}

static Result SerialPrint(const char str[])
{
  uint8_t result = 1;
  HAL_StatusTypeDef stmResult = HAL_UART_Transmit(&huart, (uint8_t*)str, strlen(str), 10);
               
  switch( stmResult)
  {
    case HAL_OK:
      result = RESULT_OK;
      break;
    case HAL_ERROR:
      result = RESULT_IO_ERROR;
      break;
    case HAL_BUSY:
      result = RESULT_IO_ERROR;
      break;
    case HAL_TIMEOUT:
      result = RESULT_TIMEOUT;
      break;
    default:
      result = RESULT_INVALID;
  }
  return result;
}
