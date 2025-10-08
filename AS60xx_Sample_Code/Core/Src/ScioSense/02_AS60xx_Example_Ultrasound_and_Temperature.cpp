#include "02_AS60xx_Example_Ultrasound_and_Temperature.h"
#include "src/ScioSense_AS60XX.h"
#include <cstdio>
#include <cstring>

static char messageBuffer[128];         // Buffer for sending data through Serial
static UART_HandleTypeDef huart;

static AS60xx as60xx;

static Result SerialPrint(const char str[]);

extern "C" void AS60xx_Example_Setup(UART_HandleTypeDef *uart, SPI_HandleTypeDef *spi)
{
    huart = *uart;
    // Wait to allow terminal software to capture the output
    HAL_Delay(2000);

    SerialPrint("Starting AS60xx 02_AS60xx_Example_Ultrasound_and_Temperature demo on STM32...\n");

    HAL_Delay(AS60XX_BOOTUP_COMM_RELEASE_TIME_MAX_MS);

    as60xx.begin(spi, SSN_Pin, SSN_GPIO_Port);

    if( as60xx.init() )
    {
        SerialPrint("AS60xx initialized properly\n");
    }
    else
    {
        SerialPrint("AS60xx initialization failed\n");
    }

    sprintf(messageBuffer, "High Speed Clock Frequency: %0.3f MHz\n", as60xx.getHighSpeedClockFrequencyHz() / 1000000.0);
    SerialPrint(messageBuffer);

    sprintf(messageBuffer, "Supply Voltage: %ld mV\n", as60xx.getSupplyVoltageMv() );
    SerialPrint(messageBuffer);

    uint32_t configurationRegistersUsAndT[] = {
        0x48DBA399,     // 0x0C0
        0x00800401,     // 0x0C1
        0x00000000,     // 0x0C2
        0x00000001,     // 0x0C3
        0x0011FFFF,     // 0x0C4
        0x4046EE08,     // 0x0C5
        0x01012100,     // 0x0C6
        0x00246008,     // 0x0C7
        0x006C07E4,     // 0x0C8
        0x60160204,     // 0x0C9
        0x010FEA10,     // 0x0CA
        0x23A0DE71,     // 0x0CB
        0x94A0C46C,     // 0x0CC
        0x401100C4,     // 0x0CD
        0x00A7400F,     // 0x0CE
        0x00000001,     // 0x0D0
        0x000015E0,     // 0x0D1
        0x000015E0,     // 0x0D2
        0x00000023,     // 0x0DA
        0x00000023      // 0x0DB
    };
    as60xx.setConfigurationRegisters(configurationRegistersUsAndT);

    if( as60xx.writeConfig() == RESULT_OK )
    {
        SerialPrint("Configuration properly written\n");
    }
    else
    {
        SerialPrint("Error! Configuration read doesn't match the values written\n");
    }
    
    if( as60xx.startMeasurement() == RESULT_OK )
    {
        SerialPrint("Measurements started\n");
    }
    else
    {
        SerialPrint("Error! Measurements didn't start properly\n");
    }
}

extern "C" void AS60xx_Example_Loop()
{
    float measuredTemperatures[2];
    AS60xx_Measure_Type measurementsReady = AS60XX_NO_MEASUREMENT;
    As60xx_ErrorFlag errorsToCheck[] = {ERR_TOF_TMO, ERR_TM_OC_ERR, ERR_TM_SC_ERR, ERR_TM_SQC_TMO, ERR_CHP_ERR};
    uint8_t amountErrorsToCheck = (uint8_t)( sizeof(errorsToCheck) / sizeof(errorsToCheck[0]) );

    while( 1 )
    {
        if( !HAL_GPIO_ReadPin(INTN_GPIO_Port, INTN_Pin) )
        {
            measurementsReady |= as60xx.update();
            
            if( (measurementsReady & AS60XX_TEMPERATURE_MEASUREMENT) && (measurementsReady & AS60XX_TOF_MEASUREMENT) )
            {
                // Print the timestamp
                As60xx_Timestamp timestamp = as60xx.getTimestamp();
                sprintf(messageBuffer, "Timestamp[hh:mm:ss]:%ld:%02d:%02d\t", timestamp.hours, timestamp.minutes, timestamp.seconds);
                SerialPrint(messageBuffer);

                // Print the ToF sum upstream and downstream
                uint32_t avgTofUp = as60xx.getSumTofUp() / as60xx.getAmountHitsForSumToF();
                uint32_t avgTofDn = as60xx.getSumTofDown() / as60xx.getAmountHitsForSumToF();
                float avgTofUp_ns = as60xx.calculateTimeNs(avgTofUp);
                float avgTofDn_ns = as60xx.calculateTimeNs(avgTofDn);

                sprintf(messageBuffer, "AvgTofSumUp[ns]:%0.2f\tAvgTofSumDn[ns]:%0.2f\t", avgTofUp_ns, avgTofDn_ns);
                SerialPrint(messageBuffer);

                // Print the ToF difference
                sprintf(messageBuffer, "TofDiff[ns]:%0.2f\t", avgTofUp_ns - avgTofDn_ns );
                SerialPrint(messageBuffer);

                // Print the temperatures measured with the 2-wire RTD
                as60xx.getTemperatures2WireDegC(measuredTemperatures);
                sprintf(messageBuffer, "TempH[degC]:%0.3f\tTempC[degC]:%0.3f\t", measuredTemperatures[1], measuredTemperatures[0]);
                SerialPrint(messageBuffer);

                // Print the internal temperature of the AS60xx sensor
                sprintf(messageBuffer, "TempInt[degC]:%0.3f\t", as60xx.getInternalTemperatureDegC());
                SerialPrint(messageBuffer);

                SerialPrint("\n");
            }

            for( uint8_t errorIdx = 0; errorIdx < amountErrorsToCheck; errorIdx++ )
            {
                if( as60xx.hasErrorFlag(errorsToCheck[errorIdx]) )
                {
                    SerialPrint("Error detected: ");
                    SerialPrint( as60xx.errorToString(errorsToCheck[errorIdx]) );
                    SerialPrint("\n");
                }
            }
            
        }
        HAL_Delay(20);
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
