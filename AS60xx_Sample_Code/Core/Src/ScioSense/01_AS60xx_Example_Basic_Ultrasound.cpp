#include "01_AS60xx_Example_Basic_Ultrasound.h"
#include "src/ScioSense_AS60XX.h"
#include <cstdio>
#include <cstring>

static char messageBuffer[128];         // Buffer for sending data through Serial
static UART_HandleTypeDef huart;

static AS60xx as60xx;

static Result SerialPrint(const char str[]);
void SetConfigurationAS60XX_Demo_1MHz_water_meter_FHL(AS60xx* as60xx);

extern "C" void AS60xx_Example_Setup(UART_HandleTypeDef *uart, SPI_HandleTypeDef *spi)
{
    huart = *uart;
    /* Wait to allow terminal software to capture the output */
    HAL_Delay(2000);

    SerialPrint("Starting AS60xx 01_AS60xx_Example_Basic_Ultrasound demo on STM32...\n");

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

    SetConfigurationAS60XX_Demo_1MHz_water_meter_FHL(&as60xx);

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
    while( 1 )
    {
        if( !HAL_GPIO_ReadPin(INTN_GPIO_Port, INTN_Pin) )
        {
            as60xx.update();
            
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

            // Print the amplitude from the pulse measured upstream and downstream
            sprintf(messageBuffer, "AmpUp[mV]:%ld\tAmpDn[mV]:%ld\t", as60xx.getAmplitudeUp(), as60xx.getAmplitudeDown());
            SerialPrint(messageBuffer);

            // Print the Pulse Width Ratio measured upstream and downstream
            sprintf(messageBuffer, "PWRUp[]:%0.3f\tPWRDn[]:%0.3f\t", as60xx.getPulseWidthRatioUp(), as60xx.getPulseWidthRatioDown());
            SerialPrint(messageBuffer);
            
            SerialPrint("\n");
        }

        HAL_Delay(20);
    }
}

void SetConfigurationAS60XX_Demo_1MHz_water_meter_FHL(AS60xx* as60xx)
{
    /* 0x48DBA399 */
    as60xx->Param.CR0.WS_DIS               = AS60XX_C0_WS_DIS;

    /* 0x00800401 */
    as60xx->Param.CR1.PI_TPW               = AS60XX_C1_PI_TPW_0;
    as60xx->Param.CR1.PI_UPD_MODE          = AS60XX_C1_PI_UPD_MODE_ENABLED;
    as60xx->Param.CR1.PI_EN                = AS60XX_C1_PI_EN_DISABLE;
    as60xx->Param.CR1.PI_OUT_MODE          = AS60XX_C1_PI_OUT_MODE_ONE_LINE;
    as60xx->Param.CR1.SPI_INPORT_CFG       = AS60XX_C1_SPI_INPORT_CFG_PULL_DN;

    /* 0x00000000 */
    as60xx->Param.CR2.GP0_DIR              = AS60XX_C2_GP0_DIR_OUTPUT;
    as60xx->Param.CR2.GP0_SEL              = AS60XX_C2_GP0_SEL_GENERAL_PURPOSE_OUT;
    as60xx->Param.CR2.GP1_DIR              = AS60XX_C2_GP1_DIR_OUTPUT;
    as60xx->Param.CR2.GP1_SEL              = AS60XX_C2_GP1_SEL_GENERAL_PURPOSE_OUT;
    as60xx->Param.CR2.GP2_DIR              = AS60XX_C2_GP2_DIR_OUTPUT;
    as60xx->Param.CR2.GP2_SEL              = AS60XX_C2_GP2_SEL_GENERAL_PURPOSE_OUT;
    as60xx->Param.CR2.GP3_DIR              = AS60XX_C2_GP3_DIR_OUTPUT;
    as60xx->Param.CR2.GP3_SEL              = AS60XX_C2_GP3_SEL_GENERAL_PURPOSE_OUT;
    as60xx->Param.CR2.GP4_DIR              = AS60XX_C2_GP4_DIR_OUTPUT;
    as60xx->Param.CR2.GP4_SEL              = AS60XX_C2_GP4_SEL_GENERAL_PURPOSE_OUT;
    as60xx->Param.CR2.GP5_DIR              = AS60XX_C2_GP5_DIR_OUTPUT;
    as60xx->Param.CR2.GP5_SEL              = AS60XX_C2_GP5_SEL_GENERAL_PURPOSE_OUT;
    as60xx->Param.CR2.NOT_USED_31_24       = 0;

    /* 0x00000001 */
    as60xx->Param.CR3.USM_OPT              = AS60XX_C3_USM_OPT_0;

    /* 0x0011FFFF */
    as60xx->Param.CR4.EF_EN_TDC_TMO        = AS60XX_C4_EF_EN_TDC_TMO;
    as60xx->Param.CR4.EF_EN_TOF_TMO        = AS60XX_C4_EF_EN_TOF_TMO;
    as60xx->Param.CR4.EF_EN_AM_TMO         = AS60XX_C4_EF_EN_AM_TMO;
    as60xx->Param.CR4.EF_EN_TM_OC          = AS60XX_C4_EF_EN_TM_OC;
    as60xx->Param.CR4.EF_EN_TM_SC          = AS60XX_C4_EF_EN_TM_SC;
    as60xx->Param.CR4.EF_EN_ZCC_ERR        = AS60XX_C4_EF_EN_ZCC_ERR;
    as60xx->Param.CR4.EF_EN_LBD_ERR        = AS60XX_C4_EF_EN_LBD_ERR;
    as60xx->Param.CR4.EF_EN_USM_SQC_TMO    = AS60XX_C4_EF_EN_USM_SQC_TMO;
    as60xx->Param.CR4.EF_EN_TM_SQC_TMO     = AS60XX_C4_EF_EN_TM_SQC_TMO;
    as60xx->Param.CR4.EF_EN_TSQ_TMO        = AS60XX_C4_EF_EN_TSQ_TMO;
    as60xx->Param.CR4.EF_EN_I2C_ACK_ERR    = AS60XX_C4_EF_EN_I2C_ACK_ERR;
    as60xx->Param.CR4.EF_EN_CHP_ERR        = AS60XX_C4_EF_EN_CHP_ERR;
    as60xx->Param.CR4.EF_EN_NVM_FWCU_ERR   = AS60XX_C4_EF_EN_NVM_FWCU_ERR;
    as60xx->Param.CR4.EF_EN_NVM_FWDU_ERR   = AS60XX_C4_EF_EN_NVM_FWDU_ERR;
    as60xx->Param.CR4.EF_EN_NVM_FWA_ERR    = AS60XX_C4_EF_EN_NVM_FWA_ERR;
    as60xx->Param.CR4.EF_EN_CPU_ERR        = AS60XX_C4_EF_EN_CPU_ERR;
    as60xx->Param.CR4.IRQ_EN_TSQ_FNS       = AS60XX_C4_IRQ_EN_TSQ_FNS;
    as60xx->Param.CR4.IRQ_EN_FW_S          = AS60XX_C4_IRQ_EN_FW_S;
    as60xx->Param.CR4.NOT_USED_26_24       = 0;
    as60xx->Param.CR4.TS_GPT_RATE          = AS60XX_C4_TS_GPT_RATE_DISABLED;

    /* 0x4046EE08 */
    as60xx->Param.CR5.HSC_DIV_MODE         = AS60XX_C5_HSC_DIV_MODE_4MHZ;
    as60xx->Param.CR5.NOT_USED_1           = 0;
    as60xx->Param.CR5.HSC_CLK_ST           = AS60XX_C5_HSC_CLK_ST_135_USEC;
    as60xx->Param.CR5.NOT_USED_7_5         = 0;
    as60xx->Param.CR5.HSC_DIV              = AS60XX_C5_HSC_DIV_4MHZ;
    as60xx->Param.CR5.HSC_RATE             = AS60XX_C5_HSC_RATE_EVERY_100;
    as60xx->Param.CR5.HSC_MODE_CPU         = AS60XX_C5_HSC_MODE_CPU_4MHZ;
    as60xx->Param.CR5.VM_RATE              = AS60XX_C5_VM_RATE_EVERY_100;
    uint16_t lowBatteryDetectionThMv     = 2300;
    as60xx->Param.CR5.LBD_TH               = (uint8_t)( ( lowBatteryDetectionThMv - 2150 ) / 25);
    as60xx->Param.CR5.TSV_UPD_MODE         = AS60XX_C5_TSV_UPD_MODE_AUTOMATIC;
    as60xx->Param.CR5.BF_SEL               = AS60XX_C5_BF_SEL_50_HZ;
    uint16_t chargePumpVoltageMv         = 5600;
    as60xx->Param.CR5.CHP_HV_SEL           = (uint8_t)( ( (chargePumpVoltageMv - 5600) / 900 ) & 0x0F );
    as60xx->Param.CR5.NOT_USED_28          = 0;
    as60xx->Param.CR5.TI_PATH_SEL          = AS60XX_C5_TI_PATH_SEL_350_OHM_BUFFER;
    as60xx->Param.CR5.NOT_USED_31          = 0;

    /* 0x01012100 */
    as60xx->Param.CR6.MR_CT                = AS60XX_C6_MR_CT_8;
    as60xx->Param.CR6.TS_MCM               = AS60XX_C6_TS_PP_F_EN;
    as60xx->Param.CR6.TS_PP_MODE           = AS60XX_C6_TS_PP_MODE_ON_MEASUREMENT;
    as60xx->Param.CR6.TS_CST_RATE          = AS60XX_C6_TS_CST_RATE_DISABLED;
    as60xx->Param.CR6.TS_NVR_RATE          = AS60XX_C6_TS_NVR_RATE_DISABLED;
    as60xx->Param.CR6.NOT_USED_25_24       = AS60XX_C6_NOT_USED_25_24;
    as60xx->Param.CR6.TS_CHP_MODE          = AS60XX_C6_TS_CHP_MODE_DISABLED;
    as60xx->Param.CR6.TS_CHP_WT            = AS60XX_C6_TS_CHP_WT_520_USEC;
    as60xx->Param.CR6.NOT_USED_30          = 0;
    as60xx->Param.CR6.TS_CST_MODE          = AS60XX_C6_TS_CST_MODE_ALWAYS;

    /* 0x00240000 */
    as60xx->Param.CR7.TM_RATE              = AS60XX_C7_TM_RATE_DISABLED;
    as60xx->Param.CR7.TPM_PAUSE            = AS60XX_C7_TPM_PAUSE_DISABLED;
    as60xx->Param.CR7.TM_MODE              = AS60XX_C7_TM_MODE_OFF;
    as60xx->Param.CR7.NOT_USED_16          = 0;
    as60xx->Param.CR7.TPM_PORT_MODE        = AS60XX_C7_TPM_PORT_MODE_UNUSED_TO_GND;
    as60xx->Param.CR7.TM_PORT_ORDER        = AS60XX_C7_TM_PORT_ORDER_1ST_MEASUREMENT;
    as60xx->Param.CR7.TPM_CLOAD_TRIM       = AS60XX_C7_TPM_CLOAD_TRIM_1;
    as60xx->Param.CR7.TPM_CYCLE_SEL        = AS60XX_C7_TPM_CYCLE_SEL_512_USEC;
    as60xx->Param.CR7.TPM_FAKE_NO          = AS60XX_C7_TPM_FAKE_NO_2;
    as60xx->Param.CR7.NOT_USED_31_24       = 0;

    /* 0x046807E4 */
    as60xx->Param.CR8.USM_PAUSE            = AS60XX_C8_USM_PAUSE_2;
    as60xx->Param.CR8.TI_PGA_AZ_DIS        = AS60XX_C8_TI_PGA_AZ_DIS_ENABLED;
    as60xx->Param.CR8.USM_DIR_MODE         = AS60XX_C8_USM_DIR_MODE_VIA_TOGGLE;
    as60xx->Param.CR8.USM_NOISE_MASK_WIN   = 31;
    as60xx->Param.CR8.USM_TO               = AS60XX_C8_USM_TO_128_USEC;
    as60xx->Param.CR8.NOT_USED_18          = 0;
    as60xx->Param.CR8.USM_RLS_MODE         = AS60XX_C8_USM_RLS_MODE_COMBINED;
    as60xx->Param.CR8.ZCC_RATE             = AS60XX_C8_ZCC_RATE_EVERY_50;
    as60xx->Param.CR8.NOT_USED_29_23       = 8;
    as60xx->Param.CR8.TI_PGA_CON_MODE      = AS60XX_C8_TI_PGA_CON_MODE_NO_EXTERNAL;

    /* 0x60160204 */
    as60xx->Param.CR9.FBG_CLK_DIV          = 4;
    as60xx->Param.CR9.FBG_MODE             = AS60XX_C9_FBG_MODE_LOW_PHASE_INSERTION;
    as60xx->Param.CR9.FBG_PHASE_INS        = AS60XX_C9_FBG_PHASE_INS_1;
    as60xx->Param.CR9.FBG_BURST_PRE        = 22;
    as60xx->Param.CR9.FBG_BURST_POST       = 0;                              // THIS IS NOT ALLOWED!! Should be 1 to 63!!
    as60xx->Param.CR9.NOT_USED_28          = 0;
    as60xx->Param.CR9.NOT_USED_29          = AS60XX_C9_NOT_USED_29;
    as60xx->Param.CR9.TOF_HIT_MODE         = AS60XX_C9_TOF_HIT_MODE_GP30;
    as60xx->Param.CR9.NOT_USED_31          = 0;

    /* 0x010FEA10 */
    as60xx->Param.CR10.NOT_USED_0          = 0;
    as60xx->Param.CR10.TOF_HIT_START       = 8;
    as60xx->Param.CR10.TOF_HIT_IGN         = AS60XX_CA_TOF_HIT_IGN_0_HITS;
    as60xx->Param.CR10.TOF_HIT_SUM_NO      = 10;
    as60xx->Param.CR10.TOF_HIT_END         = 127;                            // Because CR9.TOF_HIT_MODE was set to GP30, has to be put to 127
    as60xx->Param.CR10.NOT_USED_21_20      = 0;
    as60xx->Param.CR10.TOF_EDGE_MODE       = AS60XX_CA_TOF_EDGE_MODE_POS_EDGE;
    as60xx->Param.CR10.TOF_RATE_INIT       = 1;
    as60xx->Param.CR10.NOT_USED_31_30      = 0;

    /* 0x23A0DE71 */
    as60xx->Param.CR11.AM_RATE             = AS60XX_CB_AM_RATE_EVERY_1;
    as60xx->Param.CR11.NOT_USED_3          = 0;
    as60xx->Param.CR11.AM_PD_END           = 7;
    as60xx->Param.CR11.NOT_USED_11_9       = AS60XX_CB_NOT_USED_11_9;
    as60xx->Param.CR11.AMC_RATE            = AS60XX_CB_AMC_RATE_EVERY_20;
    as60xx->Param.CR11.PWD_EN              = AS60XX_CB_PWD_EN;
    as60xx->Param.CR11.PGA_TRIM            = AS60XX_CB_PGA_TRIM_2_V_PER_V;
    as60xx->Param.CR11.PGA_EN_MODE         = 0;
    as60xx->Param.CR11.PGA_MODE            = AS60XX_CB_PGA_MODE_ENABLED;
    as60xx->Param.CR11.NOT_USED_22         = 0;                              // AS6030 says it should be 0, AS6040 says it should be 1
    as60xx->Param.CR11.AM_PD_START_MODE    = AS60XX_CB_AM_PD_START_MODE_US_RELEASE;
    as60xx->Param.CR11.ZCD_FHL_INIT        = 35;

    /* 0x94A0C46C */
    as60xx->Param.CR12.TRIM1               = AS60XX_CC_TRIM1_DEFAULT;

    /* 0x401100C4 */
    as60xx->Param.CR13.TRIM2               = AS60XX_CD_TRIM2_DEFAULT;

    /* 0x00A7400F */
    as60xx->Param.CR14.TRIM3               = AS60XX_CE_TRIM3_DEFAULT;

    /* 0x00000001 */
    as60xx->Param.CR15.TOF_RATE            = AS60XX_D0_TOF_RATE_0;
    as60xx->Param.CR15.NOT_USED_31_6       = 0;

    /* 0x000015E0 */
    float delayWindowNs = 43750;
    uint32_t delayWindowRegisterContent = As60xx_CalculateDelayWindowRegisterValue(delayWindowNs);
    as60xx->Param.CR16.USM_RLS_DLY_U       = delayWindowRegisterContent;
    as60xx->Param.CR16.NOT_USED_31_19      = 0;

    /* 0x000015E0 */
    as60xx->Param.CR17.USM_RLS_DLY_D       = delayWindowRegisterContent;
    as60xx->Param.CR17.NOT_USED_31_19      = 0;

    /* 0x00000023 */
    float zeroCrossDetectionLevelMv = 31.0;
    uint32_t zeroCrossDetectionLevelRegisterValue = As60xx_CalculateFirstHitLevelRegisterValue(zeroCrossDetectionLevelMv);
    as60xx->Param.CR18.ZCD_FHL_U           = zeroCrossDetectionLevelRegisterValue;
    as60xx->Param.CR18.NOT_USED_31_8       = 0;

    /* 0x00000023 */
    as60xx->Param.CR19.ZCD_FHL_D           = zeroCrossDetectionLevelRegisterValue;
    as60xx->Param.CR19.NOT_USED_31_8       = 0;

    as60xx->updateConfiguration();
}

static Result SerialPrint(const char str[])
{
  uint8_t result = 1;
  uint16_t i = 0;
  while(str[i] != 0)
  {
    i++;
  }
  HAL_StatusTypeDef stmResult = HAL_UART_Transmit(&huart, (uint8_t*)str, i, 10);
               
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
