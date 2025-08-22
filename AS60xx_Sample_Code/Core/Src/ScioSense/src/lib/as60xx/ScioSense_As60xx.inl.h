#ifndef SCIOSENSE_AS60XX_C
#define SCIOSENSE_AS60XX_C

#include "ScioSense_As60xx.h"
#include "ScioSense_As60xx_defines.h"
#include "ScioSense_As60xx_Macros.h"

#define read(dataToWrite, lenToWrite, dataToRead, lenToRead)    as60xx->io.read(as60xx->io.config, (uint8_t*)(dataToWrite), (lenToWrite), (uint8_t*)(dataToRead), (lenToRead))
#define write(data, len)                                        as60xx->io.write(as60xx->io.config, (uint8_t*)(data), (len))
#define wait(ms)                                                as60xx->io.wait(ms)

// Speed of sound in water (col2) in m/s as a function of temperature (col1) in degC. Data from https://www.engineeringtoolbox.com/sound-speed-water-d_598.html
static float as60xxSpeedSoundWaterFromTemperature[AS60XX_AMOUNT_POINTS_SPEED_SOUND_TABLE][2] = {
    {0.0,   1403.0},
    {5.0,   1427.0},
    {10.0,  1447.0},
    {20.0,  1481.0},
    {30.0,  1507.0},
    {40.0,  1526.0},
    {50.0,  1541.0},
    {60.0,  1552.0},
    {70.0,  1555.0},
    {80.0,  1555.0},
    {90.0,  1550.0},
    {100.0, 1543.0},
};

static inline void As60xx_Set_State(ScioSense_As60xx* as60xx, AS60XX_StateTypeDef newState)
{
    as60xx->State = newState;
}

static inline uint8_t As60xx_Get_Amount_Configuration_Registers()
{
    return AS60XX_AMOUNT_CONFIGURATION_REGISTERS;
}

static inline uint16_t As60xx_Get_Configuration_Register_Address(ScioSense_As60xx* as60xx, uint8_t idx)
{
    if ( idx >= AS60XX_AMOUNT_CONFIGURATION_REGISTERS)
    {
        return 0;
    }
    return as60xx->Addresses[idx];
}

static inline uint32_t As60xx_Get_Configuration_Register_Setting(ScioSense_As60xx* as60xx, uint8_t idx)
{
    if ( idx >= AS60XX_AMOUNT_CONFIGURATION_REGISTERS)
    {
        return 0;
    }
    return as60xx->CR[idx];
}

static inline uint32_t As60xx_CalculateDelayWindowRegisterValue(float delayWindowNs)
{

    if ( delayWindowNs < 0 )
    {
      delayWindowNs = 0;
    }
    
    return (((uint32_t)( delayWindowNs / AS60XX_DELAY_WINDOW_LSB_TO_NS )) & AS60XX_D1_USM_RLS_DLY_U_Msk);
}

static inline uint32_t As60xx_CalculateFirstHitLevelRegisterValue(float thresholdMv)
{
    if ( thresholdMv > AS60XX_MAX_ZERO_CROSS_DETECTION_VALUE_MV )
    {
      thresholdMv = AS60XX_MAX_ZERO_CROSS_DETECTION_VALUE_MV;
    }

    if ( thresholdMv < 0 )
    {
      thresholdMv = 0;
    }
    
    return(uint32_t)( thresholdMv / AS60XX_ZERO_CROSS_DETECTION_LSB_TO_MV );
}

static inline Result As60xx_Write_Opcode(ScioSense_As60xx* as60xx, uint8_t opcode)
{
    uint8_t valuesToWrite[1];
    valuesToWrite[0] = opcode;

    return (Result)write(&valuesToWrite, 1);
}

static inline Result As60xx_Write_Extended_Opcode(ScioSense_As60xx* as60xx, uint8_t opcode, uint8_t extendedOpcode)
{
    uint8_t valuesToWrite[2];
    valuesToWrite[0] = opcode;
    valuesToWrite[1] = extendedOpcode;

    return (Result)write(valuesToWrite, 2);
}

static inline Result As60xx_Write_8_Bit_Address_Register(ScioSense_As60xx* as60xx, uint8_t opcode, uint8_t address, uint32_t dataToWrite)
{
    uint8_t valuesToWrite[6];
    valuesToWrite[0] = opcode;
    valuesToWrite[1] = address;
    valuesToWrite[2] = (uint8_t)(dataToWrite>>24);
    valuesToWrite[3] = (uint8_t)(dataToWrite>>16);
    valuesToWrite[4] = (uint8_t)(dataToWrite>>8);
    valuesToWrite[5] = (uint8_t)(dataToWrite);

    return (Result)write(valuesToWrite, 6);
}

static inline Result As60xx_Write_16_Bit_Address_Register(ScioSense_As60xx* as60xx, uint8_t opcode, uint16_t address, uint32_t dataToWrite)
{
    uint8_t valuesToWrite[7];
    valuesToWrite[0] = opcode;
    valuesToWrite[1] = (uint8_t)(address>>8);
    valuesToWrite[2] = (uint8_t)(address);
    valuesToWrite[3] = (uint8_t)(dataToWrite>>24);
    valuesToWrite[4] = (uint8_t)(dataToWrite>>16);
    valuesToWrite[5] = (uint8_t)(dataToWrite>>8);
    valuesToWrite[6] = (uint8_t)(dataToWrite);

    return (Result)write(valuesToWrite, 7);
}

static inline Result As60xx_Write_N_Registers(ScioSense_As60xx* as60xx, uint8_t opcode, uint8_t address, uint32_t* dataToWrite, uint16_t len)
{
    uint8_t valuesToWrite[2];
    valuesToWrite[0] = opcode;
    valuesToWrite[1] = address;
    Result result = (Result)write(valuesToWrite, 2);

    if( result == RESULT_OK )
    {
        result = (Result)write(dataToWrite, len);
    }

    return result;
}

static inline uint8_t As60xx_Read_1_Byte(ScioSense_As60xx* as60xx, uint8_t opcode)
{
    uint8_t dataToWrite[1];
    uint8_t dataRead[1];

    dataToWrite[0] = opcode;

    Result result = (Result)read(dataToWrite, 1, dataRead, 1);

    uint8_t readValue = 0;

    if ( result == RESULT_OK )
    {
        readValue = dataRead[0];
    }

    return readValue;
}

static inline uint32_t As60xx_Read_1_Dword(ScioSense_As60xx* as60xx, uint8_t opcode)
{
    uint8_t dataToWrite[1];
    uint8_t dataRead[4];

    dataToWrite[0] = opcode;

    Result result = (Result)read(dataToWrite, 1, dataRead, 4);

    uint32_t readValue = 0;

    if ( result == RESULT_OK )
    {
        readValue = (dataRead[0]<<24) + (dataRead[1]<<16) + (dataRead[2]<<8) + (dataRead[3]);
    }

    return readValue;
}

static inline uint32_t As60xx_Read_Register_1_Dword(ScioSense_As60xx* as60xx, uint8_t opcode, uint8_t address)
{
    uint8_t dataToWrite[2];
    uint8_t dataRead[4];

    dataToWrite[0] = opcode;
    dataToWrite[1] = address;

    Result result = (Result)read(dataToWrite, 2, dataRead, 4);

    uint32_t readValue = 0;

    if ( result == RESULT_OK )
    {
        readValue = (dataRead[0]<<24) + (dataRead[1]<<16) + (dataRead[2]<<8) + (dataRead[3]);
    }

    return readValue;
}

static inline void As60xx_Read_Register_N_Dword(ScioSense_As60xx* as60xx, uint8_t opcode, uint8_t address, uint32_t* outputData, uint16_t amountRegistersToRead)
{
    for( uint16_t i=0; i<amountRegistersToRead; i++ )
    {
        outputData[i] = As60xx_Read_Register_1_Dword(as60xx, opcode, address+i);
    }
}

static inline Result As60xx_Reset(ScioSense_As60xx* as60xx)
{
    Result result = RESULT_IO_ERROR;

    As60xx_Write_Opcode(as60xx, RC_BM_REQ);
    wait(25);
    
    As60xx_Write_Opcode(as60xx, RC_SYS_RST);
    wait(25);

    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR, AS60XX_SHR_EXC_ADDRESS, AS60XX_DD_IF_CLR_CLEAR | AS60XX_DD_EF_CLR_CLEAR );
    wait(25);

    As60xx_Write_Opcode(as60xx, RC_BM_RLS);
    wait(AS60XX_BOOTUP_COMM_RELEASE_TIME_MAX_MS);

    uint8_t sysStatus = As60xx_Read_1_Byte(as60xx, RC_RD_STATUS);
    if( sysStatus & AS60XX_SYS_STATUS_RST_FLAG_Msk )
    {
        as60xx->State = AS60XX_STATE_RESET;
        result = RESULT_OK;
    }
    
    return result;
}

static inline Result As60xx_Init(ScioSense_As60xx* as60xx)
{
    As6xx_Initialize_Configuration(as60xx);
    return As60xx_Reset(as60xx);
}

uint8_t As60xx_isConnected(ScioSense_As60xx* as60xx)
{
    return (as60xx->State != AS60XX_STATE_NOT_CONNECTED);
}

static inline Result As60xx_Write_Config(ScioSense_As60xx* as60xx)
{
    Result result = RESULT_IO_ERROR;

    As60xx_Write_Opcode(as60xx, RC_BM_REQ);
    As60xx_Write_Opcode(as60xx, RC_MCT_OFF);

    As60xx_Write_Opcode(as60xx, RC_IF_CLR);

    // Write Configuration (0xC0 - 0xCE, 0xD0 - 0xD2, 0xDA - 0xDB)
    uint8_t registersToWrite = As60xx_Get_Amount_Configuration_Registers();
    for ( uint8_t idx=0; idx<registersToWrite; idx++ )
    {
	As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR, As60xx_Get_Configuration_Register_Address(as60xx, idx), As60xx_Get_Configuration_Register_Setting(as60xx, idx));
    }

    uint8_t configurationCorrect = 1;
    for ( uint8_t idx=1; idx<registersToWrite; idx++ )
    {
        configurationCorrect &= ( As60xx_Get_Configuration_Register_Setting(as60xx, idx) == As60xx_Read_Register_1_Dword(as60xx, RC_RAA_RD, As60xx_Get_Configuration_Register_Address(as60xx, idx)) );
    }

    As60xx_Write_Opcode(as60xx, RC_IF_CLR);

    As60xx_Write_Opcode(as60xx, RC_BM_RLS);

    As60xx_Write_Opcode(as60xx, RC_SYS_INIT);
    wait(AS60XX_CHARGE_PUMP_UPLOADING);
    As60xx_Write_Opcode(as60xx, RC_RF_CLR);

    if( configurationCorrect )
    {
        as60xx->State = AS60XX_STATE_READY;
        result = RESULT_OK;
    }

    return result;
}

static inline Result As60xx_Start_Measurements(ScioSense_As60xx* as60xx)
{
    Result result = RESULT_IO_ERROR;
    As60xx_Write_Opcode(as60xx, RC_IF_CLR);
    As60xx_Write_Opcode(as60xx, RC_SYS_INIT);
    wait(AS60XX_CHARGE_PUMP_UPLOADING);

    As60xx_Write_Opcode(as60xx, RC_RF_CLR);
    As60xx_Write_Opcode(as60xx, RC_MCT_ON);

    wait(120);

    uint8_t sysStatus = As60xx_Read_1_Byte(as60xx, RC_RD_STATUS);
    if( sysStatus & AS60XX_SYS_STATUS_MCT_STATE_Msk )
    {
        result = RESULT_OK;
    }
    return result;
}

static inline Result As60xx_Stop_Measurements(ScioSense_As60xx* as60xx)
{
  Result result = RESULT_IO_ERROR;
  As60xx_Write_Opcode(as60xx, RC_MCT_OFF);
  As60xx_Write_Opcode(as60xx, RC_IF_CLR);
  As60xx_Write_Opcode(as60xx, RC_SYS_INIT);
  wait(AS60XX_SOFTWARE_RESET_TIME_MS);

  As60xx_Write_Opcode(as60xx, RC_RF_CLR);
  uint8_t sysStatus = As60xx_Read_1_Byte(as60xx, RC_RD_STATUS);
  if( sysStatus & AS60XX_SYS_STATUS_MCT_STATE_Msk )
  {
    result = RESULT_OK;
  }
  return result;
}

static inline uint32_t As60xx_GetSupplyVoltageMv(ScioSense_As60xx* as60xx)
{
  As60xx_Write_Extended_Opcode(as60xx, RC_MT_REQ, AS60XX_EC_MT_REQ_VCC_VOLTAGE_MEASUREMENT);
  
  wait(110);     // Wait for the measurement to complete
  
  uint32_t measurement = As60xx_Read_Register_1_Dword(as60xx, RC_RAA_RD, AS60XX_SRR_VCC_VAL_ADDRESS);
  
  return (2150 + measurement * 25);
}

static inline float As60xx_GetHsClkFreqHz(ScioSense_As60xx* as60xx)
{
  As60xx_Write_Extended_Opcode(as60xx, RC_MT_REQ, AS60XX_EC_MT_REQ_HIGH_SPEED_CLOCK_CAL);
  
  wait(110);     // Wait for the measurement to complete
  
  float highSpeedClockCalibration = (float)As60xx_Read_Register_1_Dword(as60xx, RC_RAA_RD, AS60XX_SRR_HCC_VAL_ADDRESS);
  
  return (highSpeedClockCalibration / 8.0);
}

static inline As60xx_Timestamp As60xx_GetTimestamp(ScioSense_As60xx* as60xx)
{
  As60xx_Timestamp timestamp;
  timestamp.hours   =           (as60xx->Status[AS60XX_STATUS_SRR_TS_HOUR_INDEX]     & AS60XX_E6_TS_HOUR_Msk)   >> AS60XX_E6_TS_HOUR_Pos;
  timestamp.minutes = (uint8_t)((as60xx->Status[AS60XX_STATUS_SRR_TS_MIN_SEC_INDEX]  & AS60XX_E7_TS_MIN_Msk)    >> AS60XX_E7_TS_MIN_Pos);
  timestamp.seconds = (uint8_t)((as60xx->Status[AS60XX_STATUS_SRR_TS_MIN_SEC_INDEX]  & AS60XX_E7_TS_SEC_Msk)    >> AS60XX_E6_TS_HOUR_Pos);
  
  return timestamp;
}

static inline uint8_t As60xx_HasAnyError(ScioSense_As60xx* as60xx)
{
    return (as60xx->Status[AS60XX_STATUS_SRR_IRQ_FLAG_INDEX] & AS60XX_E0_ERR_FLAG_Msk) >> AS60XX_E0_ERR_FLAG_Pos;
}

static inline uint32_t As60xx_GetRawErrorFlags(ScioSense_As60xx* as60xx)
{
    return as60xx->Status[AS60XX_STATUS_SRR_ERR_FLAG_INDEX];
}

static inline uint8_t As60xx_HasErrorFlag(ScioSense_As60xx* as60xx, As60xx_ErrorFlag errorFlag)
{
    return (as60xx->Status[AS60XX_STATUS_SRR_ERR_FLAG_INDEX]  >> errorFlag ) & 1;
}

static inline void As60xx_Write_Fw(ScioSense_As60xx* as60xx, uint8_t* FWC, int32_t FWC_Length)
{
    // FW Handling Procedures
    // Datasheet Appendix, section 15.7
    // Phase 1: Wait time (dependent on start option)
    // Phase 2: Preparation (common for all procedures)
    // Phase 3: FW Update (different for procedures [A], [B], [C], [D] )
    // Phase 4: FW Retention Check (common for all procedures)

    // Phase1: Initial Wait Time
    As60xx_Write_Opcode(as60xx, RC_BM_REQ);
    As60xx_Write_Opcode(as60xx, RC_SYS_RST);
    wait(AS60XX_SOFTWARE_RESET_TIME_MS);

    // Phase 2: Preparation
    As60xx_Write_Opcode(as60xx, RC_BM_REQ);
    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR, 0xC0, 0x48DBA399);
    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR, 0xCD, 0x40100000);
    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR, 0xC6, 0x00001000);
    As60xx_Write_Opcode(as60xx, RC_SV_INIT);
    wait(1);
    As60xx_Write_Extended_Opcode(as60xx, RC_MT_REQ, 0x00);
    wait(1);
    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR, 0xDD, 0x00000007);
    As60xx_Write_Opcode(as60xx, RC_RF_CLR);
    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR, 0xC4, 0x000AF000);
    As60xx_Write_Opcode(as60xx, RC_BM_RLS);

    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR, 0xDF, 0x50F5B8CA);
    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR, 0xDE, 0x00100000);
    while( ( As60xx_Read_Register_1_Dword(as60xx, RC_RAA_RD, AS60XX_SRR_IRQ_FLAG_ADDRESS) & AS60XX_E0_TSQ_FNS ) == 0 ) {};
    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR, 0xDE, 0x00080000);
    while( ( As60xx_Read_Register_1_Dword(as60xx, RC_RAA_RD, AS60XX_SRR_IRQ_FLAG_ADDRESS) & AS60XX_E0_TSQ_FNS ) == 0 ) {};

    // Phase 3: FW Update
    As60xx_Read_Register_1_Dword(as60xx, RC_RAA_RD, AS60XX_SRR_FWU_RNG_ADDRESS);

    // Write FWC
    for (int32_t i = 20; i < FWC_Length; i++)
    {
	    As60xx_Write_8_Bit_Address_Register(as60xx, RC_FWC_WR, i, FWC[i]);  // Writing FWC, bytewise with two byte address
    }

    // Write FWD
    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR_NVRAM, 0x00, 0x0000AB6A);    // Writing Firmware Code User, Checksum
    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR_NVRAM, 0x01, 0x00000556);    // Writing Firmware Data User, Checksum
    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR_NVRAM, 0x02, 0x00010000);    // Writing FWD_SIMPLE_SCALE (fd16)
    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR_NVRAM, 0x03, 0x00000000);    // Writing FWD_ZERO_OFFSET
    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR_NVRAM, 0x04, 0x051EB852);    // Writing FWD_MAX_TOF_DIFF
    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR_NVRAM, 0x05, 0xFAE147AE);    // Writing FWD_NEG_TOF_DIFF_LIMIT

    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR_NVRAM, 0x5B, 0x0000000A);    // Writing FWD_R_PULSE_PER_LITER
    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR_NVRAM, 0x5C, 0x000003E8);    // Writing FWD_R_PULSE_MAX_FLOW

    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR_NVRAM, 0x67, 0x00000000);    // Writing FWD_USM_RLS_DLY_INIT

    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR_NVRAM, 0x6B, 0xABCD7654);    // Writing Boot-Loader Release Code

    // Update Config 0x6C ... 0x77 in NVRAM
    // without CR_TRIMx and without SHR_...
    //As60xx_Write_8_Bit_Address_Register(RC_RAA_WR_NVRAM, 0x6C, 0x48DBA399); // CR_WD_DIS Watchdog Disable
    //As60xx_Write_8_Bit_Address_Register(RC_RAA_WR_NVRAM, 0x6D, 0x00800101); // CR_IFC_CTRL Interfaces Control
    //As60xx_Write_8_Bit_Address_Register(RC_RAA_WR_NVRAM, 0x6E, 0x00100044); // CR_GP_CTRL General Purpose Control
    //As60xx_Write_8_Bit_Address_Register(RC_RAA_WR_NVRAM, 0x6F, 0x20000003); // CR_USM_OPT USM Options
    //As60xx_Write_8_Bit_Address_Register(RC_RAA_WR_NVRAM, 0x70, 0x001002A7); // CR_IEH Interrupt & Error Handling
    //As60xx_Write_8_Bit_Address_Register(RC_RAA_WR_NVRAM, 0x71, 0x2046EE08); // CR_CPM Clock & Power Management
    //As60xx_Write_8_Bit_Address_Register(RC_RAA_WR_NVRAM, 0x72, 0x0101A080); // CR_MRG_TS Measure Rate Generator & Task Sequencer
    //As60xx_Write_8_Bit_Address_Register(RC_RAA_WR_NVRAM, 0x73, 0x00140000); // CR_TPM Temperature Measurement
    //As60xx_Write_8_Bit_Address_Register(RC_RAA_WR_NVRAM, 0x74, 0x207807A4); // CR_USM_PRC USM Processing
    //As60xx_Write_8_Bit_Address_Register(RC_RAA_WR_NVRAM, 0x75, 0x60150202); // CR_USM_FRC USM Fire & Receive Control
    //As60xx_Write_8_Bit_Address_Register(RC_RAA_WR_NVRAM, 0x76, 0x00002A0E); // CR_USM_TOF Time Of Flight Rate init value
    //As60xx_Write_8_Bit_Address_Register(RC_RAA_WR_NVRAM, 0x77, 0x23209E71); // CR_USM_AM Amplitude and FHL

    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR, AS60XX_SHR_RC_RLS_ADDRESS, 0x50F5B8CA);
    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR, AS60XX_SHR_RC_ADDRESS, 0x00010000);
    while( ( As60xx_Read_Register_1_Dword(as60xx, RC_RAA_RD, AS60XX_SRR_IRQ_FLAG_ADDRESS) & AS60XX_E0_TSQ_FNS ) == 0 ) {};

    // Phase 4: FW Retention Check
    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR, AS60XX_SHR_RC_RLS_ADDRESS, 0x50F5B8CA);
    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR, AS60XX_SHR_RC_ADDRESS, 0x00100000);
    while( ( As60xx_Read_Register_1_Dword(as60xx, RC_RAA_RD, AS60XX_SRR_IRQ_FLAG_ADDRESS) & AS60XX_E0_TSQ_FNS ) == 0 ) {};
    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR, AS60XX_SHR_RC_ADDRESS, 0x00080000);
    while( ( As60xx_Read_Register_1_Dword(as60xx, RC_RAA_RD, AS60XX_SRR_IRQ_FLAG_ADDRESS) & AS60XX_E0_TSQ_FNS ) == 0 ) {};
    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR, AS60XX_SHR_GPO_ADDRESS, 0x0007F000);
    wait(35);  // After initialization checksum error flags, delay of at least 34ms are needed _MH
    As60xx_Write_Opcode(as60xx, RC_FW_CHKSUM);
    while( ( As60xx_Read_Register_1_Dword(as60xx, RC_RAA_RD, AS60XX_SRR_IRQ_FLAG_ADDRESS) & AS60XX_E0_TSQ_FNS ) == 0 ) {};
    As60xx_Read_Register_1_Dword(as60xx, RC_RAA_RD, AS60XX_SHR_GPO_ADDRESS);

    // END
    As60xx_Write_Opcode(as60xx, RC_SYS_RST);
}

AS60xx_Measure_Type As60xx_Update(ScioSense_As60xx* as60xx)
{
    uint8_t newData = AS60XX_NO_MEASUREMENT;

    As60xx_Read_Register_N_Dword(as60xx, RC_RAA_RD, AS60XX_SRR_IRQ_FLAG_ADDRESS, as60xx->Status, AS60XX_AMOUNT_STATUS_REGISTERS);
    
    if( 1 )	// !(as60xx->Status[AS60XX_STATUS_SRR_ERR_FLAG_INDEX])
    {
        if( as60xx->Status[AS60XX_STATUS_SRR_FEP_STF_INDEX] & AS60XX_E2_TM_UPD_Msk )
        {
            As60xx_Read_Register_N_Dword(as60xx, RC_RAA_RD, AS60XX_FDB_ADDRESS, as60xx->FrontendDataBufferTemperature, AS60XX_AMOUNT_FDB_REGISTERS);
            newData = AS60XX_TEMPERATURE_MEASUREMENT;
        }
        else if( as60xx->Status[AS60XX_STATUS_SRR_FEP_STF_INDEX] & (AS60XX_E2_US_U_UPD_Msk | AS60XX_E2_US_D_UPD_Msk | AS60XX_E2_US_TOF_UPD_Msk) )
        {
            As60xx_Read_Register_N_Dword(as60xx, RC_RAA_RD, AS60XX_FDB_ADDRESS, as60xx->FrontendDataBufferUltrasound, AS60XX_AMOUNT_FDB_REGISTERS);
            newData = AS60XX_TOF_MEASUREMENT;
        }    
    }

    As60xx_Write_8_Bit_Address_Register(as60xx, RC_RAA_WR, AS60XX_SHR_EXC_ADDRESS, AS60XX_DD_FES_CLR_CLEAR);
    As60xx_Write_Opcode(as60xx, RC_IF_CLR);

    return newData;
}

static inline uint32_t As60xx_GetSumTofUp(ScioSense_As60xx* as60xx)
{
    return as60xx->FrontendDataBufferUltrasound[AS60XX_FDB_US_TOF_SUM_OF_ALL_U_INDEX];
}

static inline uint32_t As60xx_GetSumTofDown(ScioSense_As60xx* as60xx)
{
    return as60xx->FrontendDataBufferUltrasound[AS60XX_FDB_US_TOF_SUM_OF_ALL_D_INDEX];
}

static inline uint32_t As60xx_GetAmountHitsForSumTof(ScioSense_As60xx* as60xx)
{
    return ( (as60xx->CR[AS60XX_CR_ARRAY_CR_USM_TOF_INDEX] & AS60XX_CA_TOF_HIT_SUM_NO_Msk) >> AS60XX_CA_TOF_HIT_SUM_NO_Pos );
}

static inline uint32_t As60xx_CalculateTDCTimePs(ScioSense_As60xx* as60xx, uint32_t contentTDCRegister)
{
    uint8_t frequencyTDC = ( (as60xx->CR[AS60XX_CR_ARRAY_CR_CPM_INDEX] & AS60XX_C5_HSC_DIV_MODE_Msk) >> AS60XX_C5_HSC_DIV_MODE_Pos );
    uint64_t tPeriodHSO;
    if( frequencyTDC == AS60XX_C5_HSC_DIV_MODE_4MHZ )
    {
        tPeriodHSO = 250;
    }
    else
    {
        tPeriodHSO = 125;
    }
    return (uint32_t)( (((uint64_t)contentTDCRegister) * tPeriodHSO * 1000) / (1<<16) );
}

static inline void AS60xx_CalculateTemperatureResistance2Wire(ScioSense_As60xx* as60xx, float* temperatureResistancesRatiosOut)
{
    float t_gain_1  = (float)(as60xx->FrontendDataBufferTemperature[AS60XX_FDB_TPM1_M1AB_RAB_G12_INDEX]);
    float t_RAB_1   = (float)(as60xx->FrontendDataBufferTemperature[AS60XX_FDB_TPM1_RAB_G12_INDEX]);
    float t_M1A_1   = (float)(as60xx->FrontendDataBufferTemperature[AS60XX_FDB_TPM1_M1A_G12_INDEX]);
    float t_M2A_1   = (float)(as60xx->FrontendDataBufferTemperature[AS60XX_FDB_TPM1_M2A_G12_INDEX]);
    float t_Rdson_1 = (float)(as60xx->FrontendDataBufferTemperature[AS60XX_FDB_TPM1_RA_G12_INDEX]);
    float t_RO_1 = t_Rdson_1 - t_RAB_1;
    float deltaT_1 = 2.0 * ( t_gain_1 - (t_M1A_1 * t_RAB_1)/(t_M1A_1 + t_RAB_1) );
    float t_R_1 = t_RAB_1 - t_RO_1 - deltaT_1;
    float t_C_1 = t_M1A_1 - t_RO_1 - deltaT_1;
    float t_H_1 = t_M2A_1 - t_RO_1 - deltaT_1;
    temperatureResistancesRatiosOut[0] = t_C_1 / t_R_1;     // Cold temperature sensor resistance
    temperatureResistancesRatiosOut[1] = t_H_1 / t_R_1;     // Hot temperature sensor resistance
}

static inline void AS60xx_CalculateTemperature2Wire(ScioSense_As60xx* as60xx, float* temperaturesOut)
{
    float tempResistanceRatios[2];
    AS60xx_CalculateTemperatureResistance2Wire(as60xx, tempResistanceRatios);

    for( uint8_t idx=0; idx<2; idx++ )
    {
        temperaturesOut[idx] = 10.115 * tempResistanceRatios[idx] * tempResistanceRatios[idx] + 235.57 * tempResistanceRatios[idx] - 245.683;
    }
}

static inline float AS60xx_CalculateInternalTemperature(ScioSense_As60xx* as60xx)
{
    float t_MI_R_1  = (float)(as60xx->FrontendDataBufferTemperature[AS60XX_FDB_TPM1_MI_R_G12_INDEX]);
    float t_MI_M_1  = (float)(as60xx->FrontendDataBufferTemperature[AS60XX_FDB_TPM1_MI_M_G12_INDEX]);

    return ( (t_MI_M_1 / t_MI_R_1) - 1 ) * 1235 / 3.8;
}

static inline uint32_t As60xx_AmplitudeToMv(uint32_t AM, uint32_t AMCHigh, uint32_t AMCLow)
{
    float VCal = 350.0 / 2.0;
    float AMCGradient = VCal / (float)(AMCHigh - AMCLow);
    float AMCOffset = (float)(2 * AMCLow - AMCHigh) * AMCGradient;

    return (uint32_t)(AMCGradient * AM - AMCOffset);
}

static inline uint32_t As60xx_GetAmplitudeUp(ScioSense_As60xx* as60xx)
{
    uint32_t AM_Up = as60xx->FrontendDataBufferUltrasound[AS60XX_FDB_US_AM_U_INDEX];
    uint32_t AMC_High = as60xx->FrontendDataBufferUltrasound[AS60XX_FDB_US_AMC_VH_INDEX];
    uint32_t AMC_Low = as60xx->FrontendDataBufferUltrasound[AS60XX_FDB_US_AMC_VL_INDEX];

    return As60xx_AmplitudeToMv(AM_Up, AMC_High, AMC_Low);
}

static inline uint32_t As60xx_GetAmplitudeDown(ScioSense_As60xx* as60xx)
{
    uint32_t AM_Low = as60xx->FrontendDataBufferUltrasound[AS60XX_FDB_US_AM_D_INDEX];
    uint32_t AMC_High = as60xx->FrontendDataBufferUltrasound[AS60XX_FDB_US_AMC_VH_INDEX];
    uint32_t AMC_Low = as60xx->FrontendDataBufferUltrasound[AS60XX_FDB_US_AMC_VL_INDEX];

    return As60xx_AmplitudeToMv(AM_Low, AMC_High, AMC_Low);
}

static inline float As60xx_PulseWidthRatioToFloat(uint32_t registerContent)
{
    float contentInteger = (float)((registerContent & AS60XX_FDB_US_PW_DECIMAL_Msk) >> AS60XX_FDB_US_PW_DECIMAL_Pos);
    float contentFractional = (float)(registerContent & AS60XX_FDB_US_PW_FRACTIONAL_Msk) * AS60XX_FDB_US_PW_FRACTIONAL_LSB;
    return (contentInteger + contentFractional);
}

static inline float As60xx_GetPulseWidthRatioUp(ScioSense_As60xx* as60xx)
{
    return As60xx_PulseWidthRatioToFloat(as60xx->FrontendDataBufferUltrasound[AS60XX_FDB_US_PW_U_INDEX]);
}

static inline float As60xx_GetPulseWidthRatioDown(ScioSense_As60xx* as60xx)
{
    return As60xx_PulseWidthRatioToFloat(as60xx->FrontendDataBufferUltrasound[AS60XX_FDB_US_PW_D_INDEX]);
}

static inline void As60xx_GetTofValuesUp(ScioSense_As60xx* as60xx, uint32_t* tofValues)
{
    for ( uint8_t idx=0; idx<AS60XX_AMOUNT_TOF_VALUES_REGISTERS ; idx++ )
    {
        tofValues[idx] = as60xx->FrontendDataBufferUltrasound[AS60XX_FDB_US_TOF_0_U_INDEX + idx];
    }
}

static inline void As60xx_GetTofValuesDown(ScioSense_As60xx* as60xx, uint32_t* tofValues)
{
    for ( uint8_t idx=0; idx<AS60XX_AMOUNT_TOF_VALUES_REGISTERS ; idx++ )
    {
        tofValues[idx] = as60xx->FrontendDataBufferUltrasound[AS60XX_FDB_US_TOF_0_D_INDEX + idx];
    }
}

static inline float As60xx_CalculateFluidSpeed(uint32_t tofUs_ps, uint32_t tofDn_ps, float speedSound_mpers, float distance_m)
{
    /* Calculation algorithm
    tof1 = d / (c+v)                // Time of flight upstream is the distance between transducers divided by the speed of sound plus fluid speed
    tof2 = d / (c-v)                // Time of flight downstream is the distance between transducers divided by the speed of sound minus fluid speed
    v = (tof2-tof1) * c^2 / (2*d) 
    */
    float tofDif = ( ((float)tofUs_ps) - ((float)tofDn_ps) ) / 1000000000.0;
    return ( tofDif * speedSound_mpers * speedSound_mpers / (2.0 * distance_m) );
}

static inline float As60xx_GetSpeedSoundFromTemperature(float temperature)
{
    if( temperature < as60xxSpeedSoundWaterFromTemperature[0][0] )
    {
        return as60xxSpeedSoundWaterFromTemperature[0][1];
    }
    if( temperature > as60xxSpeedSoundWaterFromTemperature[AS60XX_AMOUNT_POINTS_SPEED_SOUND_TABLE-1][0] )
    {
        return as60xxSpeedSoundWaterFromTemperature[AS60XX_AMOUNT_POINTS_SPEED_SOUND_TABLE-1][1];
    }
    uint8_t idx = 0;
    while( (temperature >= as60xxSpeedSoundWaterFromTemperature[idx][0]) && (idx < (AS60XX_AMOUNT_POINTS_SPEED_SOUND_TABLE-1)) )
    {
        idx++;
    }
    
    float temp1 = as60xxSpeedSoundWaterFromTemperature[idx-1][0];
    float temp2 = as60xxSpeedSoundWaterFromTemperature[idx][0];
    float speedSound1 = as60xxSpeedSoundWaterFromTemperature[idx-1][1];
    float speedSound2 = as60xxSpeedSoundWaterFromTemperature[idx][1];
    
    return speedSound1 + (speedSound2 - speedSound1) * (temperature - temp1) / (temp2 - temp1);
}

static inline void As60xx_Set_Configuration_Registers(ScioSense_As60xx* as60xx, uint32_t* registerConfiguration)
{
    for( uint8_t registerIdx=0; registerIdx<AS60XX_AMOUNT_CONFIGURATION_REGISTERS; registerIdx++ )
    {
        as60xx->CR[registerIdx] = registerConfiguration[registerIdx];
    }
    As60xx_Update_Parameters(as60xx);
}

static inline void As60xx_Update_Parameters(ScioSense_As60xx* as60xx)
{
    /* Read all content from CR[] and write into every parameter
     * Update for each parameter */
    /* Parameter of CR[0] */
    as60xx->Param.CR0.WS_DIS                = ( (as60xx->CR[0]) & AS60XX_C0_WS_DIS_Msk )                >> AS60XX_C0_WS_DIS_Pos;
    /* Parameter of CR[1] */
    as60xx->Param.CR1.PI_TPW                = ( (as60xx->CR[1]) & AS60XX_C1_PI_TPW_Msk )                >> AS60XX_C1_PI_TPW_Pos;
    as60xx->Param.CR1.PI_EN                 = ( (as60xx->CR[1]) & AS60XX_C1_PI_EN_Msk )                 >> AS60XX_C1_PI_EN_Pos;
    as60xx->Param.CR1.PI_OUT_MODE           = ( (as60xx->CR[1]) & AS60XX_C1_PI_OUT_MODE_Msk )           >> AS60XX_C1_PI_OUT_MODE_Pos;
    as60xx->Param.CR1.PI_UPD_MODE           = ( (as60xx->CR[1]) & AS60XX_C1_PI_UPD_MODE_Msk )           >> AS60XX_C1_PI_UPD_MODE_Pos;
    as60xx->Param.CR1.NOT_USED_11           = ( (as60xx->CR[1]) & AS60XX_C1_NOT_USED_11_Msk )           >> AS60XX_C1_NOT_USED_11_Pos;
    as60xx->Param.CR1.I2C_MODE              = ( (as60xx->CR[1]) & AS60XX_C1_I2C_MODE_Msk )              >> AS60XX_C1_I2C_MODE_Pos;
    as60xx->Param.CR1.I2C_ADR               = ( (as60xx->CR[1]) & AS60XX_C1_I2C_ADR_Msk )               >> AS60XX_C1_I2C_ADR_Pos;
    as60xx->Param.CR1.NOT_USED_21           = ( (as60xx->CR[1]) & AS60XX_C1_NOT_USED_21_Msk )           >> AS60XX_C1_NOT_USED_21_Pos;
    as60xx->Param.CR1.SPI_INPORT_CFG        = ( (as60xx->CR[1]) & AS60XX_C1_SPI_INPORT_CFG_Msk )        >> AS60XX_C1_SPI_INPORT_CFG_Pos;
    as60xx->Param.CR1.NOT_USED_31_24        = ( (as60xx->CR[1]) & AS60XX_C1_NOT_USED_31_24_Msk )        >> AS60XX_C1_NOT_USED_31_24_Pos;
    /* Parameter of CR[2] */
    as60xx->Param.CR2.GP0_DIR               = ( (as60xx->CR[2]) & AS60XX_C2_GP0_DIR_Msk )               >> AS60XX_C2_GP0_DIR_Pos;
    as60xx->Param.CR2.GP0_SEL               = ( (as60xx->CR[2]) & AS60XX_C2_GP0_SEL_Msk )               >> AS60XX_C2_GP0_SEL_Pos;
    as60xx->Param.CR2.GP1_DIR               = ( (as60xx->CR[2]) & AS60XX_C2_GP1_DIR_Msk )               >> AS60XX_C2_GP1_DIR_Pos;
    as60xx->Param.CR2.GP1_SEL               = ( (as60xx->CR[2]) & AS60XX_C2_GP1_SEL_Msk )               >> AS60XX_C2_GP1_SEL_Pos;
    as60xx->Param.CR2.GP2_DIR               = ( (as60xx->CR[2]) & AS60XX_C2_GP2_DIR_Msk )               >> AS60XX_C2_GP2_DIR_Pos;
    as60xx->Param.CR2.GP2_SEL               = ( (as60xx->CR[2]) & AS60XX_C2_GP2_SEL_Msk )               >> AS60XX_C2_GP2_SEL_Pos;
    as60xx->Param.CR2.GP3_DIR               = ( (as60xx->CR[2]) & AS60XX_C2_GP3_DIR_Msk )               >> AS60XX_C2_GP3_DIR_Pos;
    as60xx->Param.CR2.GP3_SEL               = ( (as60xx->CR[2]) & AS60XX_C2_GP3_SEL_Msk )               >> AS60XX_C2_GP3_SEL_Pos;
    as60xx->Param.CR2.GP4_DIR               = ( (as60xx->CR[2]) & AS60XX_C2_GP4_DIR_Msk )               >> AS60XX_C2_GP4_DIR_Pos;
    as60xx->Param.CR2.GP4_SEL               = ( (as60xx->CR[2]) & AS60XX_C2_GP4_SEL_Msk )               >> AS60XX_C2_GP4_SEL_Pos;
    as60xx->Param.CR2.GP5_DIR               = ( (as60xx->CR[2]) & AS60XX_C2_GP5_DIR_Msk )               >> AS60XX_C2_GP5_DIR_Pos;
    as60xx->Param.CR2.GP5_SEL               = ( (as60xx->CR[2]) & AS60XX_C2_GP5_SEL_Msk )               >> AS60XX_C2_GP5_SEL_Pos;
    as60xx->Param.CR2.NOT_USED_31_24        = ( (as60xx->CR[2]) & AS60XX_C2_NOT_USED_31_24_Msk )        >> AS60XX_C2_NOT_USED_31_24_Pos;
    /* Parameter of CR[3] */
    as60xx->Param.CR3.USM_OPT               = ( (as60xx->CR[3]) & AS60XX_C3_USM_OPT_Msk )               >> AS60XX_C3_USM_OPT_Pos;
    as60xx->Param.CR3.NOT_USED_31_5         = ( (as60xx->CR[3]) & AS60XX_C3_NOT_USED_31_5_Msk )         >> AS60XX_C3_NOT_USED_31_5_Pos;
    /* Parameter of CR[4] */
    as60xx->Param.CR4.EF_EN_TDC_TMO         = ( (as60xx->CR[4]) & AS60XX_C4_EF_EN_TDC_TMO_Msk )         >> AS60XX_C4_EF_EN_TDC_TMO_Pos;
    as60xx->Param.CR4.EF_EN_TOF_TMO         = ( (as60xx->CR[4]) & AS60XX_C4_EF_EN_TOF_TMO_Msk )         >> AS60XX_C4_EF_EN_TOF_TMO_Pos;
    as60xx->Param.CR4.EF_EN_AM_TMO          = ( (as60xx->CR[4]) & AS60XX_C4_EF_EN_AM_TMO_Msk )          >> AS60XX_C4_EF_EN_AM_TMO_Pos;
    as60xx->Param.CR4.EF_EN_TM_OC           = ( (as60xx->CR[4]) & AS60XX_C4_EF_EN_TM_OC_Msk )           >> AS60XX_C4_EF_EN_TM_OC_Pos;
    as60xx->Param.CR4.EF_EN_TM_SC           = ( (as60xx->CR[4]) & AS60XX_C4_EF_EN_TM_SC_Msk )           >> AS60XX_C4_EF_EN_TM_SC_Pos;
    as60xx->Param.CR4.EF_EN_ZCC_ERR         = ( (as60xx->CR[4]) & AS60XX_C4_EF_EN_ZCC_ERR_Msk )         >> AS60XX_C4_EF_EN_ZCC_ERR_Pos;
    as60xx->Param.CR4.EF_EN_LBD_ERR         = ( (as60xx->CR[4]) & AS60XX_C4_EF_EN_LBD_ERR_Msk )         >> AS60XX_C4_EF_EN_LBD_ERR_Pos;
    as60xx->Param.CR4.EF_EN_USM_SQC_TMO     = ( (as60xx->CR[4]) & AS60XX_C4_EF_EN_USM_SQC_TMO_Msk )     >> AS60XX_C4_EF_EN_USM_SQC_TMO_Pos;
    as60xx->Param.CR4.EF_EN_TM_SQC_TMO      = ( (as60xx->CR[4]) & AS60XX_C4_EF_EN_TM_SQC_TMO_Msk )      >> AS60XX_C4_EF_EN_TM_SQC_TMO_Pos;
    as60xx->Param.CR4.EF_EN_TSQ_TMO         = ( (as60xx->CR[4]) & AS60XX_C4_EF_EN_TSQ_TMO_Msk )         >> AS60XX_C4_EF_EN_TSQ_TMO_Pos;
    as60xx->Param.CR4.EF_EN_I2C_ACK_ERR     = ( (as60xx->CR[4]) & AS60XX_C4_EF_EN_I2C_ACK_ERR_Msk )     >> AS60XX_C4_EF_EN_I2C_ACK_ERR_Pos;
    as60xx->Param.CR4.EF_EN_CHP_ERR         = ( (as60xx->CR[4]) & AS60XX_C4_EF_EN_CHP_ERR_Msk )         >> AS60XX_C4_EF_EN_CHP_ERR_Pos;
    as60xx->Param.CR4.EF_EN_NVM_FWCU_ERR    = ( (as60xx->CR[4]) & AS60XX_C4_EF_EN_NVM_FWCU_ERR_Msk )    >> AS60XX_C4_EF_EN_NVM_FWCU_ERR_Pos;
    as60xx->Param.CR4.EF_EN_NVM_FWDU_ERR    = ( (as60xx->CR[4]) & AS60XX_C4_EF_EN_NVM_FWDU_ERR_Msk )    >> AS60XX_C4_EF_EN_NVM_FWDU_ERR_Pos;
    as60xx->Param.CR4.EF_EN_NVM_FWA_ERR     = ( (as60xx->CR[4]) & AS60XX_C4_EF_EN_NVM_FWA_ERR_Msk )     >> AS60XX_C4_EF_EN_NVM_FWA_ERR_Pos;
    as60xx->Param.CR4.EF_EN_CPU_ERR         = ( (as60xx->CR[4]) & AS60XX_C4_EF_EN_CPU_ERR_Msk )         >> AS60XX_C4_EF_EN_CPU_ERR_Pos;
    as60xx->Param.CR4.IRQ_EN_TSQ_FNS        = ( (as60xx->CR[4]) & AS60XX_C4_IRQ_EN_TSQ_FNS_Msk )        >> AS60XX_C4_IRQ_EN_TSQ_FNS_Pos;
    as60xx->Param.CR4.IRQ_EN_TRANS_FNS      = ( (as60xx->CR[4]) & AS60XX_C4_IRQ_EN_TRANS_FNS_Msk )      >> AS60XX_C4_IRQ_EN_TRANS_FNS_Pos;
    as60xx->Param.CR4.IRQ_EN_BLD_FNS        = ( (as60xx->CR[4]) & AS60XX_C4_IRQ_EN_BLD_FNS_Msk )        >> AS60XX_C4_IRQ_EN_BLD_FNS_Pos;
    as60xx->Param.CR4.IRQ_EN_CHKSUM_FNS     = ( (as60xx->CR[4]) & AS60XX_C4_IRQ_EN_CHKSUM_FNS_Msk )     >> AS60XX_C4_IRQ_EN_CHKSUM_FNS_Pos;
    as60xx->Param.CR4.IRQ_EN_FW_S           = ( (as60xx->CR[4]) & AS60XX_C4_IRQ_EN_FW_S_Msk )           >> AS60XX_C4_IRQ_EN_FW_S_Pos;
    as60xx->Param.CR4.IRQ_EN_TSQ_TO         = ( (as60xx->CR[4]) & AS60XX_C4_IRQ_EN_TSQ_TO_Msk )         >> AS60XX_C4_IRQ_EN_TSQ_TO_Pos;
    as60xx->Param.CR4.NOT_USED_22           = ( (as60xx->CR[4]) & AS60XX_C4_NOT_USED_22_Msk )           >> AS60XX_C4_NOT_USED_22_Pos;
    as60xx->Param.CR4.IRQ_EN_ERR_FLAG       = ( (as60xx->CR[4]) & AS60XX_C4_IRQ_EN_ERR_FLAG_Msk )       >> AS60XX_C4_IRQ_EN_ERR_FLAG_Pos;
    as60xx->Param.CR4.NOT_USED_26_24        = ( (as60xx->CR[4]) & AS60XX_C4_NOT_USED_26_24_Msk )        >> AS60XX_C4_NOT_USED_26_24_Pos;
    as60xx->Param.CR4.CPU_REQ_EN_GPH        = ( (as60xx->CR[4]) & AS60XX_C4_CPU_REQ_EN_GPH_Msk )        >> AS60XX_C4_CPU_REQ_EN_GPH_Pos;
    as60xx->Param.CR4.TS_GPT_RATE           = ( (as60xx->CR[4]) & AS60XX_C4_TS_GPT_RATE_Msk )           >> AS60XX_C4_TS_GPT_RATE_Pos;
    /* Parameter of CR[5] */
    as60xx->Param.CR5.HSC_DIV_MODE          = ( (as60xx->CR[5]) & AS60XX_C5_HSC_DIV_MODE_Msk )          >> AS60XX_C5_HSC_DIV_MODE_Pos;
    as60xx->Param.CR5.NOT_USED_1            = ( (as60xx->CR[5]) & AS60XX_C5_NOT_USED_1_Msk )            >> AS60XX_C5_NOT_USED_1_Pos;
    as60xx->Param.CR5.HSC_CLK_ST            = ( (as60xx->CR[5]) & AS60XX_C5_HSC_CLK_ST_Msk )            >> AS60XX_C5_HSC_CLK_ST_Pos;
    as60xx->Param.CR5.NOT_USED_7_5          = ( (as60xx->CR[5]) & AS60XX_C5_NOT_USED_7_5_Msk )          >> AS60XX_C5_NOT_USED_7_5_Pos;
    as60xx->Param.CR5.HSC_DIV               = ( (as60xx->CR[5]) & AS60XX_C5_HSC_DIV_Msk )               >> AS60XX_C5_HSC_DIV_Pos;
    as60xx->Param.CR5.HSC_RATE              = ( (as60xx->CR[5]) & AS60XX_C5_HSC_RATE_Msk )              >> AS60XX_C5_HSC_RATE_Pos;
    as60xx->Param.CR5.HSC_MODE_CPU          = ( (as60xx->CR[5]) & AS60XX_C5_HSC_MODE_CPU_Msk )          >> AS60XX_C5_HSC_MODE_CPU_Pos;
    as60xx->Param.CR5.VM_RATE               = ( (as60xx->CR[5]) & AS60XX_C5_VM_RATE_Msk )               >> AS60XX_C5_VM_RATE_Pos;
    as60xx->Param.CR5.LBD_TH                = ( (as60xx->CR[5]) & AS60XX_C5_LBD_TH_Msk )                >> AS60XX_C5_LBD_TH_Pos;
    as60xx->Param.CR5.TSV_UPD_MODE          = ( (as60xx->CR[5]) & AS60XX_C5_TSV_UPD_MODE_Msk )          >> AS60XX_C5_TSV_UPD_MODE_Pos;
    as60xx->Param.CR5.BF_SEL                = ( (as60xx->CR[5]) & AS60XX_C5_BF_SEL_Msk )                >> AS60XX_C5_BF_SEL_Pos;
    as60xx->Param.CR5.CHP_HV_SEL            = ( (as60xx->CR[5]) & AS60XX_C5_CHP_HV_SEL_Msk )            >> AS60XX_C5_CHP_HV_SEL_Pos;
    as60xx->Param.CR5.NOT_USED_28           = ( (as60xx->CR[5]) & AS60XX_C5_NOT_USED_28_Msk )           >> AS60XX_C5_NOT_USED_28_Pos;
    as60xx->Param.CR5.TI_PATH_SEL           = ( (as60xx->CR[5]) & AS60XX_C5_TI_PATH_SEL_Msk )           >> AS60XX_C5_TI_PATH_SEL_Pos;
    as60xx->Param.CR5.NOT_USED_31           = ( (as60xx->CR[5]) & AS60XX_C5_NOT_USED_31_Msk )           >> AS60XX_C5_NOT_USED_31_Pos;
    /* Parameter of CR[6] */
    as60xx->Param.CR6.MR_CT                 = ( (as60xx->CR[6]) & AS60XX_C6_MR_CT_Msk )                 >> AS60XX_C6_MR_CT_Pos;
    as60xx->Param.CR6.TS_MCM                = ( (as60xx->CR[6]) & AS60XX_C6_TS_MCM_Msk )                >> AS60XX_C6_TS_MCM_Pos;
    as60xx->Param.CR6.TS_PP_T_EN            = ( (as60xx->CR[6]) & AS60XX_C6_TS_PP_T_EN_Msk )            >> AS60XX_C6_TS_PP_T_EN_Pos;
    as60xx->Param.CR6.TS_PP_F_EN            = ( (as60xx->CR[6]) & AS60XX_C6_TS_PP_F_EN_Msk )            >> AS60XX_C6_TS_PP_F_EN_Pos;
    as60xx->Param.CR6.TS_PP_MODE            = ( (as60xx->CR[6]) & AS60XX_C6_TS_PP_MODE_Msk )            >> AS60XX_C6_TS_PP_MODE_Pos;
    as60xx->Param.CR6.TS_CST_RATE           = ( (as60xx->CR[6]) & AS60XX_C6_TS_CST_RATE_Msk )           >> AS60XX_C6_TS_CST_RATE_Pos;
    as60xx->Param.CR6.TS_NVR_RATE           = ( (as60xx->CR[6]) & AS60XX_C6_TS_NVR_RATE_Msk )           >> AS60XX_C6_TS_NVR_RATE_Pos;
    as60xx->Param.CR6.NOT_USED_25_24        = ( (as60xx->CR[6]) & AS60XX_C6_NOT_USED_25_24_Msk )        >> AS60XX_C6_NOT_USED_25_24_Pos;
    as60xx->Param.CR6.TS_CHP_MODE           = ( (as60xx->CR[6]) & AS60XX_C6_TS_CHP_MODE_Msk )           >> AS60XX_C6_TS_CHP_MODE_Pos;
    as60xx->Param.CR6.TS_CHP_WT             = ( (as60xx->CR[6]) & AS60XX_C6_TS_CHP_WT_Msk )             >> AS60XX_C6_TS_CHP_WT_Pos;
    as60xx->Param.CR6.NOT_USED_30           = ( (as60xx->CR[6]) & AS60XX_C6_NOT_USED_30_Msk )           >> AS60XX_C6_NOT_USED_30_Pos;
    as60xx->Param.CR6.TS_CST_MODE           = ( (as60xx->CR[6]) & AS60XX_C6_TS_CST_MODE_Msk )           >> AS60XX_C6_TS_CST_MODE_Pos;
    /* Parameter of CR[7] */
    as60xx->Param.CR7.TM_RATE               = ( (as60xx->CR[7]) & AS60XX_C7_TM_RATE_Msk )               >> AS60XX_C7_TM_RATE_Pos;
    as60xx->Param.CR7.TPM_PAUSE             = ( (as60xx->CR[7]) & AS60XX_C7_TPM_PAUSE_Msk )             >> AS60XX_C7_TPM_PAUSE_Pos;
    as60xx->Param.CR7.TM_MODE               = ( (as60xx->CR[7]) & AS60XX_C7_TM_MODE_Msk )               >> AS60XX_C7_TM_MODE_Pos;
    as60xx->Param.CR7.NOT_USED_16           = ( (as60xx->CR[7]) & AS60XX_C7_NOT_USED_16_Msk )           >> AS60XX_C7_NOT_USED_16_Pos;
    as60xx->Param.CR7.TPM_PORT_MODE         = ( (as60xx->CR[7]) & AS60XX_C7_TPM_PORT_MODE_Msk )         >> AS60XX_C7_TPM_PORT_MODE_Pos;
    as60xx->Param.CR7.TM_PORT_ORDER         = ( (as60xx->CR[7]) & AS60XX_C7_TM_PORT_ORDER_Msk )         >> AS60XX_C7_TM_PORT_ORDER_Pos;
    as60xx->Param.CR7.TPM_CLOAD_TRIM        = ( (as60xx->CR[7]) & AS60XX_C7_TPM_CLOAD_TRIM_Msk )        >> AS60XX_C7_TPM_CLOAD_TRIM_Pos;
    as60xx->Param.CR7.TPM_CYCLE_SEL         = ( (as60xx->CR[7]) & AS60XX_C7_TPM_CYCLE_SEL_Msk )         >> AS60XX_C7_TPM_CYCLE_SEL_Pos;
    as60xx->Param.CR7.TPM_FAKE_NO           = ( (as60xx->CR[7]) & AS60XX_C7_TPM_FAKE_NO_Msk )           >> AS60XX_C7_TPM_FAKE_NO_Pos;
    as60xx->Param.CR7.NOT_USED_31_24        = ( (as60xx->CR[7]) & AS60XX_C7_NOT_USED_31_24_Msk )        >> AS60XX_C7_NOT_USED_31_24_Pos;
    /* Parameter of CR[8] */
    as60xx->Param.CR8.USM_PAUSE             = ( (as60xx->CR[8]) & AS60XX_C8_USM_PAUSE_Msk )             >> AS60XX_C8_USM_PAUSE_Pos;
    as60xx->Param.CR8.TI_PGA_AZ_DIS         = ( (as60xx->CR[8]) & AS60XX_C8_TI_PGA_AZ_DIS_Msk )         >> AS60XX_C8_TI_PGA_AZ_DIS_Pos;
    as60xx->Param.CR8.USM_DIR_MODE          = ( (as60xx->CR[8]) & AS60XX_C8_USM_DIR_MODE_Msk )          >> AS60XX_C8_USM_DIR_MODE_Pos;
    as60xx->Param.CR8.USM_NOISE_MASK_WIN    = ( (as60xx->CR[8]) & AS60XX_C8_USM_NOISE_MASK_WIN_Msk )    >> AS60XX_C8_USM_NOISE_MASK_WIN_Pos;
    as60xx->Param.CR8.USM_TO                = ( (as60xx->CR[8]) & AS60XX_C8_USM_TO_Msk )                >> AS60XX_C8_USM_TO_Pos;
    as60xx->Param.CR8.NOT_USED_18           = ( (as60xx->CR[8]) & AS60XX_C8_NOT_USED_18_Msk )           >> AS60XX_C8_NOT_USED_18_Pos;
    as60xx->Param.CR8.USM_RLS_MODE          = ( (as60xx->CR[8]) & AS60XX_C8_USM_RLS_MODE_Msk )          >> AS60XX_C8_USM_RLS_MODE_Pos;
    as60xx->Param.CR8.ZCC_RATE              = ( (as60xx->CR[8]) & AS60XX_C8_ZCC_RATE_Msk )              >> AS60XX_C8_ZCC_RATE_Pos;
    as60xx->Param.CR8.NOT_USED_29_23        = ( (as60xx->CR[8]) & AS60XX_C8_NOT_USED_29_23_Msk )        >> AS60XX_C8_NOT_USED_29_23_Pos;
    as60xx->Param.CR8.TI_PGA_CON_MODE       = ( (as60xx->CR[8]) & AS60XX_C8_TI_PGA_CON_MODE_Msk )       >> AS60XX_C8_TI_PGA_CON_MODE_Pos;
    /* Parameter of CR[9] */
    as60xx->Param.CR9.FBG_CLK_DIV           = ( (as60xx->CR[9]) & AS60XX_C9_FBG_CLK_DIV_Msk )           >> AS60XX_C9_FBG_CLK_DIV_Pos;
    as60xx->Param.CR9.FBG_MODE              = ( (as60xx->CR[9]) & AS60XX_C9_FBG_MODE_Msk )              >> AS60XX_C9_FBG_MODE_Pos;
    as60xx->Param.CR9.FBG_PHASE_INS         = ( (as60xx->CR[9]) & AS60XX_C9_FBG_PHASE_INS_Msk )         >> AS60XX_C9_FBG_PHASE_INS_Pos;
    as60xx->Param.CR9.FBG_BURST_PRE         = ( (as60xx->CR[9]) & AS60XX_C9_FBG_BURST_PRE_Msk )         >> AS60XX_C9_FBG_BURST_PRE_Pos;
    as60xx->Param.CR9.FBG_BURST_POST        = ( (as60xx->CR[9]) & AS60XX_C9_FBG_BURST_POST_Msk )        >> AS60XX_C9_FBG_BURST_POST_Pos;
    as60xx->Param.CR9.NOT_USED_28           = ( (as60xx->CR[9]) & AS60XX_C9_NOT_USED_28_Msk )           >> AS60XX_C9_NOT_USED_28_Pos;
    as60xx->Param.CR9.NOT_USED_29           = ( (as60xx->CR[9]) & AS60XX_C9_NOT_USED_29_Msk )           >> AS60XX_C9_NOT_USED_29_Pos;
    as60xx->Param.CR9.TOF_HIT_MODE          = ( (as60xx->CR[9]) & AS60XX_C9_TOF_HIT_MODE_Msk )          >> AS60XX_C9_TOF_HIT_MODE_Pos;
    as60xx->Param.CR9.NOT_USED_31           = ( (as60xx->CR[9]) & AS60XX_C9_NOT_USED_31_Msk )           >> AS60XX_C9_NOT_USED_31_Pos;
    /* Parameter of CR[10] */
    as60xx->Param.CR10.NOT_USED_0           = ( (as60xx->CR[10]) & AS60XX_CA_NOT_USED_0_Msk )           >> AS60XX_CA_NOT_USED_0_Pos;
    as60xx->Param.CR10.TOF_HIT_START        = ( (as60xx->CR[10]) & AS60XX_CA_TOF_HIT_START_Msk )        >> AS60XX_CA_TOF_HIT_START_Pos;
    as60xx->Param.CR10.TOF_HIT_IGN          = ( (as60xx->CR[10]) & AS60XX_CA_TOF_HIT_IGN_Msk )          >> AS60XX_CA_TOF_HIT_IGN_Pos;
    as60xx->Param.CR10.TOF_HIT_SUM_NO       = ( (as60xx->CR[10]) & AS60XX_CA_TOF_HIT_SUM_NO_Msk )       >> AS60XX_CA_TOF_HIT_SUM_NO_Pos;
    as60xx->Param.CR10.TOF_HIT_END          = ( (as60xx->CR[10]) & AS60XX_CA_TOF_HIT_END_Msk )          >> AS60XX_CA_TOF_HIT_END_Pos;
    as60xx->Param.CR10.NOT_USED_21_20       = ( (as60xx->CR[10]) & AS60XX_CA_NOT_USED_21_20_Msk )       >> AS60XX_CA_NOT_USED_21_20_Pos;
    as60xx->Param.CR10.TOF_EDGE_MODE        = ( (as60xx->CR[10]) & AS60XX_CA_TOF_EDGE_MODE_Msk )        >> AS60XX_CA_TOF_EDGE_MODE_Pos;
    as60xx->Param.CR10.TOF_RATE_INIT        = ( (as60xx->CR[10]) & AS60XX_CA_TOF_RATE_INIT_Msk )        >> AS60XX_CA_TOF_RATE_INIT_Pos;
    as60xx->Param.CR10.NOT_USED_31_30       = ( (as60xx->CR[10]) & AS60XX_CA_NOT_USED_31_30_Msk )       >> AS60XX_CA_NOT_USED_31_30_Pos;
    /* Parameter of CR[11] */
    as60xx->Param.CR11.AM_RATE              = ( (as60xx->CR[11]) & AS60XX_CB_AM_RATE_Msk )              >> AS60XX_CB_AM_RATE_Pos;
    as60xx->Param.CR11.NOT_USED_3           = ( (as60xx->CR[11]) & AS60XX_CB_NOT_USED_3_Msk )           >> AS60XX_CB_NOT_USED_3_Pos;
    as60xx->Param.CR11.AM_PD_END            = ( (as60xx->CR[11]) & AS60XX_CB_AM_PD_END_Msk )            >> AS60XX_CB_AM_PD_END_Pos;
    as60xx->Param.CR11.NOT_USED_11_9        = ( (as60xx->CR[11]) & AS60XX_CB_NOT_USED_11_9_Msk )        >> AS60XX_CB_NOT_USED_11_9_Pos;
    as60xx->Param.CR11.AMC_RATE             = ( (as60xx->CR[11]) & AS60XX_CB_AMC_RATE_Msk )             >> AS60XX_CB_AMC_RATE_Pos;
    as60xx->Param.CR11.PWD_EN               = ( (as60xx->CR[11]) & AS60XX_CB_PWD_EN_Msk )               >> AS60XX_CB_PWD_EN_Pos;
    as60xx->Param.CR11.PGA_TRIM             = ( (as60xx->CR[11]) & AS60XX_CB_PGA_TRIM_Msk )             >> AS60XX_CB_PGA_TRIM_Pos;
    as60xx->Param.CR11.PGA_EN_MODE          = ( (as60xx->CR[11]) & AS60XX_CB_PGA_EN_MODE_Msk )          >> AS60XX_CB_PGA_EN_MODE_Pos;
    as60xx->Param.CR11.PGA_MODE             = ( (as60xx->CR[11]) & AS60XX_CB_PGA_MODE_Msk )             >> AS60XX_CB_PGA_MODE_Pos;
    as60xx->Param.CR11.NOT_USED_22          = ( (as60xx->CR[11]) & AS60XX_CB_NOT_USED_22_Msk )          >> AS60XX_CB_NOT_USED_22_Pos;
    as60xx->Param.CR11.AM_PD_START_MODE     = ( (as60xx->CR[11]) & AS60XX_CB_AM_PD_START_MODE_Msk )     >> AS60XX_CB_AM_PD_START_MODE_Pos;
    as60xx->Param.CR11.ZCD_FHL_INIT         = ( (as60xx->CR[11]) & AS60XX_CB_ZCD_FHL_INIT_Msk )         >> AS60XX_CB_ZCD_FHL_INIT_Pos;
    /* Parameter of CR[12] */
    as60xx->Param.CR12.TRIM1                = ( (as60xx->CR[12]) & AS60XX_CC_TRIM1_Msk )                >> AS60XX_CC_TRIM1_Pos;
    /* Parameter of CR[13] */
    as60xx->Param.CR13.TRIM2                = ( (as60xx->CR[13]) & AS60XX_CD_TRIM2_Msk )                >> AS60XX_CD_TRIM2_Pos;
    /* Parameter of CR[14] */
    as60xx->Param.CR14.TRIM3                = ( (as60xx->CR[14]) & AS60XX_CE_TRIM3_Msk )                >> AS60XX_CE_TRIM3_Pos;
    /* Parameter of CR[15] */
    as60xx->Param.CR15.TOF_RATE             = ( (as60xx->CR[15]) & AS60XX_D0_TOF_RATE_Msk )             >> AS60XX_D0_TOF_RATE_Pos;
    as60xx->Param.CR15.NOT_USED_31_6        = ( (as60xx->CR[15]) & AS60XX_D0_NOT_USED_31_6_Msk )        >> AS60XX_D0_NOT_USED_31_6_Pos;
    /* Parameter of CR[16] */
    as60xx->Param.CR16.USM_RLS_DLY_U        = ( (as60xx->CR[16]) & AS60XX_D1_USM_RLS_DLY_U_Msk )        >> AS60XX_D1_USM_RLS_DLY_U_Pos;
    as60xx->Param.CR16.NOT_USED_31_19       = ( (as60xx->CR[16]) & AS60XX_D1_NOT_USED_31_19_Msk )       >> AS60XX_D1_NOT_USED_31_19_Pos;
    /* Parameter of CR[17] */
    as60xx->Param.CR17.USM_RLS_DLY_D        = ( (as60xx->CR[17]) & AS60XX_D2_USM_RLS_DLY_D_Msk )        >> AS60XX_D2_USM_RLS_DLY_D_Pos;
    as60xx->Param.CR17.NOT_USED_31_19       = ( (as60xx->CR[17]) & AS60XX_D2_NOT_USED_31_19_Msk )       >> AS60XX_D2_NOT_USED_31_19_Pos;
    /* Parameter of CR[18] */
    as60xx->Param.CR18.ZCD_FHL_U            = ( (as60xx->CR[18]) & AS60XX_DA_ZCD_FHL_U_Msk )            >> AS60XX_DA_ZCD_FHL_U_Pos;
    as60xx->Param.CR18.NOT_USED_31_8        = ( (as60xx->CR[18]) & AS60XX_DA_NOT_USED_31_8_Msk )        >> AS60XX_DA_NOT_USED_31_8_Pos;
    /* Parameter of CR[19] */
    as60xx->Param.CR19.ZCD_FHL_D            = ( (as60xx->CR[19]) & AS60XX_DB_ZCD_FHL_D_Msk )            >> AS60XX_DB_ZCD_FHL_D_Pos;
    as60xx->Param.CR19.NOT_USED_31_8        = ( (as60xx->CR[19]) & AS60XX_DB_NOT_USED_31_8_Msk )        >> AS60XX_DB_NOT_USED_31_8_Pos;
}

static inline void As60xx_Update_Configuration(ScioSense_As60xx* as60xx)
{
    /* Writes all parameters into every configuration register */
    /* Parameter for CR[0] */
    as60xx->CR[0]   = 0;// Clearing the register
    as60xx->CR[0]   |= AS60XX_C0_WS_DIS_SET             (as60xx->Param.CR0.WS_DIS);
    /* Parameter for CR[1] */
    as60xx->CR[1]   = 0;// Clearing the register
    as60xx->CR[1]   |= AS60XX_C1_PI_TPW_SET             (as60xx->Param.CR1.PI_TPW);
    as60xx->CR[1]   |= AS60XX_C1_PI_EN_SET              (as60xx->Param.CR1.PI_EN);
    as60xx->CR[1]   |= AS60XX_C1_PI_OUT_MODE_SET        (as60xx->Param.CR1.PI_OUT_MODE);
    as60xx->CR[1]   |= AS60XX_C1_PI_UPD_MODE_SET        (as60xx->Param.CR1.PI_UPD_MODE);
    as60xx->CR[1]   |= AS60XX_C1_NOT_USED_11_SET        (as60xx->Param.CR1.NOT_USED_11);
    as60xx->CR[1]   |= AS60XX_C1_I2C_MODE_SET           (as60xx->Param.CR1.I2C_MODE);
    as60xx->CR[1]   |= AS60XX_C1_I2C_ADR_SET            (as60xx->Param.CR1.I2C_ADR);
    as60xx->CR[1]   |= AS60XX_C1_NOT_USED_21_SET        (as60xx->Param.CR1.NOT_USED_21);
    as60xx->CR[1]   |= AS60XX_C1_SPI_INPORT_CFG_SET     (as60xx->Param.CR1.SPI_INPORT_CFG);
    as60xx->CR[1]   |= AS60XX_C1_NOT_USED_31_24_SET     (as60xx->Param.CR1.NOT_USED_31_24);
    /* Parameter for CR[2] */
    as60xx->CR[2]   = 0;// Clearing the register
    as60xx->CR[2]   |= AS60XX_C2_GP0_DIR_SET            (as60xx->Param.CR2.GP0_DIR);
    as60xx->CR[2]   |= AS60XX_C2_GP0_SEL_SET            (as60xx->Param.CR2.GP0_SEL);
    as60xx->CR[2]   |= AS60XX_C2_GP1_DIR_SET            (as60xx->Param.CR2.GP1_DIR);
    as60xx->CR[2]   |= AS60XX_C2_GP1_SEL_SET            (as60xx->Param.CR2.GP1_SEL);
    as60xx->CR[2]   |= AS60XX_C2_GP2_DIR_SET            (as60xx->Param.CR2.GP2_DIR);
    as60xx->CR[2]   |= AS60XX_C2_GP2_SEL_SET            (as60xx->Param.CR2.GP2_SEL);
    as60xx->CR[2]   |= AS60XX_C2_GP3_DIR_SET            (as60xx->Param.CR2.GP3_DIR);
    as60xx->CR[2]   |= AS60XX_C2_GP3_SEL_SET            (as60xx->Param.CR2.GP3_SEL);
    as60xx->CR[2]   |= AS60XX_C2_GP4_DIR_SET            (as60xx->Param.CR2.GP4_DIR);
    as60xx->CR[2]   |= AS60XX_C2_GP4_SEL_SET            (as60xx->Param.CR2.GP4_SEL);
    as60xx->CR[2]   |= AS60XX_C2_GP5_DIR_SET            (as60xx->Param.CR2.GP5_DIR);
    as60xx->CR[2]   |= AS60XX_C2_GP5_SEL_SET            (as60xx->Param.CR2.GP5_SEL);
    as60xx->CR[2]   |= AS60XX_C2_NOT_USED_31_24_SET     (as60xx->Param.CR2.NOT_USED_31_24);
    /* Parameter for CR[3] */
    as60xx->CR[3]   = 0;// Clearing the register
    as60xx->CR[3]   |= AS60XX_C3_USM_OPT_SET            (as60xx->Param.CR3.USM_OPT);
    as60xx->CR[3]   |= AS60XX_C3_NOT_USED_31_5_SET      (as60xx->Param.CR3.NOT_USED_31_5);
    /* Parameter for CR[4] */
    as60xx->CR[4]   = 0;// Clearing the register
    as60xx->CR[4]   |= AS60XX_C4_EF_EN_TDC_TMO_SET      (as60xx->Param.CR4.EF_EN_TDC_TMO);
    as60xx->CR[4]   |= AS60XX_C4_EF_EN_TOF_TMO_SET      (as60xx->Param.CR4.EF_EN_TOF_TMO);
    as60xx->CR[4]   |= AS60XX_C4_EF_EN_AM_TMO_SET       (as60xx->Param.CR4.EF_EN_AM_TMO);
    as60xx->CR[4]   |= AS60XX_C4_EF_EN_TM_OC_SET        (as60xx->Param.CR4.EF_EN_TM_OC);
    as60xx->CR[4]   |= AS60XX_C4_EF_EN_TM_SC_SET        (as60xx->Param.CR4.EF_EN_TM_SC);
    as60xx->CR[4]   |= AS60XX_C4_EF_EN_ZCC_ERR_SET      (as60xx->Param.CR4.EF_EN_ZCC_ERR);
    as60xx->CR[4]   |= AS60XX_C4_EF_EN_LBD_ERR_SET      (as60xx->Param.CR4.EF_EN_LBD_ERR);
    as60xx->CR[4]   |= AS60XX_C4_EF_EN_USM_SQC_TMO_SET  (as60xx->Param.CR4.EF_EN_USM_SQC_TMO);
    as60xx->CR[4]   |= AS60XX_C4_EF_EN_TM_SQC_TMO_SET   (as60xx->Param.CR4.EF_EN_TM_SQC_TMO);
    as60xx->CR[4]   |= AS60XX_C4_EF_EN_TSQ_TMO_SET      (as60xx->Param.CR4.EF_EN_TSQ_TMO);
    as60xx->CR[4]   |= AS60XX_C4_EF_EN_I2C_ACK_ERR_SET  (as60xx->Param.CR4.EF_EN_I2C_ACK_ERR);
    as60xx->CR[4]   |= AS60XX_C4_EF_EN_CHP_ERR_SET      (as60xx->Param.CR4.EF_EN_CHP_ERR);
    as60xx->CR[4]   |= AS60XX_C4_EF_EN_NVM_FWCU_ERR_SET (as60xx->Param.CR4.EF_EN_NVM_FWCU_ERR);
    as60xx->CR[4]   |= AS60XX_C4_EF_EN_NVM_FWDU_ERR_SET (as60xx->Param.CR4.EF_EN_NVM_FWDU_ERR);
    as60xx->CR[4]   |= AS60XX_C4_EF_EN_NVM_FWA_ERR_SET  (as60xx->Param.CR4.EF_EN_NVM_FWA_ERR);
    as60xx->CR[4]   |= AS60XX_C4_EF_EN_CPU_ERR_SET      (as60xx->Param.CR4.EF_EN_CPU_ERR);
    as60xx->CR[4]   |= AS60XX_C4_IRQ_EN_TSQ_FNS_SET     (as60xx->Param.CR4.IRQ_EN_TSQ_FNS);
    as60xx->CR[4]   |= AS60XX_C4_IRQ_EN_TRANS_FNS_SET   (as60xx->Param.CR4.IRQ_EN_TRANS_FNS);
    as60xx->CR[4]   |= AS60XX_C4_IRQ_EN_BLD_FNS_SET     (as60xx->Param.CR4.IRQ_EN_BLD_FNS);
    as60xx->CR[4]   |= AS60XX_C4_IRQ_EN_CHKSUM_FNS_SET  (as60xx->Param.CR4.IRQ_EN_CHKSUM_FNS);
    as60xx->CR[4]   |= AS60XX_C4_IRQ_EN_FW_S_SET        (as60xx->Param.CR4.IRQ_EN_FW_S);
    as60xx->CR[4]   |= AS60XX_C4_IRQ_EN_TSQ_TO_SET      (as60xx->Param.CR4.IRQ_EN_TSQ_TO);
    as60xx->CR[4]   |= AS60XX_C4_NOT_USED_22_SET        (as60xx->Param.CR4.NOT_USED_22);
    as60xx->CR[4]   |= AS60XX_C4_IRQ_EN_ERR_FLAG_SET    (as60xx->Param.CR4.IRQ_EN_ERR_FLAG);
    as60xx->CR[4]   |= AS60XX_C4_NOT_USED_26_24_SET     (as60xx->Param.CR4.NOT_USED_26_24);
    as60xx->CR[4]   |= AS60XX_C4_CPU_REQ_EN_GPH_SET     (as60xx->Param.CR4.CPU_REQ_EN_GPH);
    as60xx->CR[4]   |= AS60XX_C4_TS_GPT_RATE_SET        (as60xx->Param.CR4.TS_GPT_RATE);
    /* Parameter for CR[5] */
    as60xx->CR[5]   = 0;// Clearing the register
    as60xx->CR[5]   |= AS60XX_C5_HSC_DIV_MODE_SET       (as60xx->Param.CR5.HSC_DIV_MODE);
    as60xx->CR[5]   |= AS60XX_C5_NOT_USED_1_SET         (as60xx->Param.CR5.NOT_USED_1);
    as60xx->CR[5]   |= AS60XX_C5_HSC_CLK_ST_SET         (as60xx->Param.CR5.HSC_CLK_ST);
    as60xx->CR[5]   |= AS60XX_C5_NOT_USED_7_5_SET       (as60xx->Param.CR5.NOT_USED_7_5);
    as60xx->CR[5]   |= AS60XX_C5_HSC_DIV_SET            (as60xx->Param.CR5.HSC_DIV);
    as60xx->CR[5]   |= AS60XX_C5_HSC_RATE_SET           (as60xx->Param.CR5.HSC_RATE);
    as60xx->CR[5]   |= AS60XX_C5_HSC_MODE_CPU_SET       (as60xx->Param.CR5.HSC_MODE_CPU);
    as60xx->CR[5]   |= AS60XX_C5_VM_RATE_SET            (as60xx->Param.CR5.VM_RATE);
    as60xx->CR[5]   |= AS60XX_C5_LBD_TH_SET             (as60xx->Param.CR5.LBD_TH);
    as60xx->CR[5]   |= AS60XX_C5_TSV_UPD_MODE_SET       (as60xx->Param.CR5.TSV_UPD_MODE);
    as60xx->CR[5]   |= AS60XX_C5_BF_SEL_SET             (as60xx->Param.CR5.BF_SEL);
    as60xx->CR[5]   |= AS60XX_C5_CHP_HV_SEL_SET         (as60xx->Param.CR5.CHP_HV_SEL);
    as60xx->CR[5]   |= AS60XX_C5_NOT_USED_28_SET        (as60xx->Param.CR5.NOT_USED_28);
    as60xx->CR[5]   |= AS60XX_C5_TI_PATH_SEL_SET        (as60xx->Param.CR5.TI_PATH_SEL);
    as60xx->CR[5]   |= AS60XX_C5_NOT_USED_31_SET        (as60xx->Param.CR5.NOT_USED_31);
    /* Parameter for CR[6] */
    as60xx->CR[6]   = 0;// Clearing the register
    as60xx->CR[6]   |= AS60XX_C6_MR_CT_SET              (as60xx->Param.CR6.MR_CT);
    as60xx->CR[6]   |= AS60XX_C6_TS_MCM_SET             (as60xx->Param.CR6.TS_MCM);
    as60xx->CR[6]   |= AS60XX_C6_TS_PP_T_EN_SET         (as60xx->Param.CR6.TS_PP_T_EN);
    as60xx->CR[6]   |= AS60XX_C6_TS_PP_F_EN_SET         (as60xx->Param.CR6.TS_PP_F_EN);
    as60xx->CR[6]   |= AS60XX_C6_TS_PP_MODE_SET         (as60xx->Param.CR6.TS_PP_MODE);
    as60xx->CR[6]   |= AS60XX_C6_TS_CST_RATE_SET        (as60xx->Param.CR6.TS_CST_RATE);
    as60xx->CR[6]   |= AS60XX_C6_TS_NVR_RATE_SET        (as60xx->Param.CR6.TS_NVR_RATE);
    as60xx->CR[6]   |= AS60XX_C6_NOT_USED_25_24_SET     (as60xx->Param.CR6.NOT_USED_25_24);
    as60xx->CR[6]   |= AS60XX_C6_TS_CHP_MODE_SET        (as60xx->Param.CR6.TS_CHP_MODE);
    as60xx->CR[6]   |= AS60XX_C6_TS_CHP_WT_SET          (as60xx->Param.CR6.TS_CHP_WT);
    as60xx->CR[6]   |= AS60XX_C6_TS_CST_MODE_SET        (as60xx->Param.CR6.TS_CST_MODE);
    /* Parameter for CR[7] */
    as60xx->CR[7]   = 0;// Clearing the register
    as60xx->CR[7]   |= AS60XX_C7_TM_RATE_SET            (as60xx->Param.CR7.TM_RATE);
    as60xx->CR[7]   |= AS60XX_C7_TPM_PAUSE_SET          (as60xx->Param.CR7.TPM_PAUSE);
    as60xx->CR[7]   |= AS60XX_C7_TM_MODE_SET            (as60xx->Param.CR7.TM_MODE);
    as60xx->CR[7]   |= AS60XX_C7_NOT_USED_16_SET        (as60xx->Param.CR7.NOT_USED_16);
    as60xx->CR[7]   |= AS60XX_C7_TPM_PORT_MODE_SET      (as60xx->Param.CR7.TPM_PORT_MODE);
    as60xx->CR[7]   |= AS60XX_C7_TM_PORT_ORDER_SET      (as60xx->Param.CR7.TM_PORT_ORDER);
    as60xx->CR[7]   |= AS60XX_C7_TPM_CLOAD_TRIM_SET     (as60xx->Param.CR7.TPM_CLOAD_TRIM);
    as60xx->CR[7]   |= AS60XX_C7_TPM_CYCLE_SEL_SET      (as60xx->Param.CR7.TPM_CYCLE_SEL);
    as60xx->CR[7]   |= AS60XX_C7_TPM_FAKE_NO_SET        (as60xx->Param.CR7.TPM_FAKE_NO);
    as60xx->CR[7]   |= AS60XX_C7_NOT_USED_31_24_SET     (as60xx->Param.CR7.NOT_USED_31_24);
    /* Parameter for CR[8] */
    as60xx->CR[8]   = 0;// Clearing the register
    as60xx->CR[8]   |= AS60XX_C8_USM_PAUSE_SET          (as60xx->Param.CR8.USM_PAUSE);
    as60xx->CR[8]   |= AS60XX_C8_TI_PGA_AZ_DIS_SET      (as60xx->Param.CR8.TI_PGA_AZ_DIS);
    as60xx->CR[8]   |= AS60XX_C8_USM_DIR_MODE_SET       (as60xx->Param.CR8.USM_DIR_MODE);
    as60xx->CR[8]   |= AS60XX_C8_USM_NOISE_MASK_WIN_SET (as60xx->Param.CR8.USM_NOISE_MASK_WIN);
    as60xx->CR[8]   |= AS60XX_C8_USM_TO_SET             (as60xx->Param.CR8.USM_TO);
    as60xx->CR[8]   |= AS60XX_C8_NOT_USED_18_SET        (as60xx->Param.CR8.NOT_USED_18);
    as60xx->CR[8]   |= AS60XX_C8_USM_RLS_MODE_SET       (as60xx->Param.CR8.USM_RLS_MODE);
    as60xx->CR[8]   |= AS60XX_C8_ZCC_RATE_SET           (as60xx->Param.CR8.ZCC_RATE);
    as60xx->CR[8]   |= AS60XX_C8_NOT_USED_29_23_SET     (as60xx->Param.CR8.NOT_USED_29_23);
    as60xx->CR[8]   |= AS60XX_C8_TI_PGA_CON_MODE_SET    (as60xx->Param.CR8.TI_PGA_CON_MODE);
    /* Parameter for CR[9] */
    as60xx->CR[9]   = 0;// Clearing the register
    as60xx->CR[9]   |= AS60XX_C9_FBG_CLK_DIV_SET        (as60xx->Param.CR9.FBG_CLK_DIV);
    as60xx->CR[9]   |= AS60XX_C9_FBG_MODE_SET           (as60xx->Param.CR9.FBG_MODE);
    as60xx->CR[9]   |= AS60XX_C9_FBG_PHASE_INS_SET      (as60xx->Param.CR9.FBG_PHASE_INS);
    as60xx->CR[9]   |= AS60XX_C9_FBG_BURST_PRE_SET      (as60xx->Param.CR9.FBG_BURST_PRE);
    as60xx->CR[9]   |= AS60XX_C9_FBG_BURST_POST_SET     (as60xx->Param.CR9.FBG_BURST_POST);
    as60xx->CR[9]   |= AS60XX_C9_NOT_USED_28_SET        (as60xx->Param.CR9.NOT_USED_28);
    as60xx->CR[9]   |= AS60XX_C9_NOT_USED_29_SET        (as60xx->Param.CR9.NOT_USED_29);
    as60xx->CR[9]   |= AS60XX_C9_TOF_HIT_MODE_SET       (as60xx->Param.CR9.TOF_HIT_MODE);
    as60xx->CR[9]   |= AS60XX_C9_NOT_USED_31_SET        (as60xx->Param.CR9.NOT_USED_31);
    /* Parameter for CR[10] */
    as60xx->CR[10]  = 0;// Clearing the register
    as60xx->CR[10]  |= AS60XX_CA_NOT_USED_0_SET         (as60xx->Param.CR10.NOT_USED_0);
    as60xx->CR[10]  |= AS60XX_CA_TOF_HIT_START_SET      (as60xx->Param.CR10.TOF_HIT_START);
    as60xx->CR[10]  |= AS60XX_CA_TOF_HIT_IGN_SET        (as60xx->Param.CR10.TOF_HIT_IGN);
    as60xx->CR[10]  |= AS60XX_CA_TOF_HIT_SUM_NO_SET     (as60xx->Param.CR10.TOF_HIT_SUM_NO);
    as60xx->CR[10]  |= AS60XX_CA_TOF_HIT_END_SET        (as60xx->Param.CR10.TOF_HIT_END);
    as60xx->CR[10]  |= AS60XX_CA_NOT_USED_21_20_SET     (as60xx->Param.CR10.NOT_USED_21_20);
    as60xx->CR[10]  |= AS60XX_CA_TOF_EDGE_MODE_SET      (as60xx->Param.CR10.TOF_EDGE_MODE);
    as60xx->CR[10]  |= AS60XX_CA_TOF_RATE_INIT_SET      (as60xx->Param.CR10.TOF_RATE_INIT);
    as60xx->CR[10]  |= AS60XX_CA_NOT_USED_31_30_SET     (as60xx->Param.CR10.NOT_USED_31_30);
    /* Parameter for CR[11] */
    as60xx->CR[11]  = 0;// Clearing the register
    as60xx->CR[11]  |= AS60XX_CB_AM_RATE_SET            (as60xx->Param.CR11.AM_RATE);
    as60xx->CR[11]  |= AS60XX_CB_NOT_USED_3_SET         (as60xx->Param.CR11.NOT_USED_3);
    as60xx->CR[11]  |= AS60XX_CB_AM_PD_END_SET          (as60xx->Param.CR11.AM_PD_END);
    as60xx->CR[11]  |= AS60XX_CB_NOT_USED_11_9_SET      (as60xx->Param.CR11.NOT_USED_11_9);
    as60xx->CR[11]  |= AS60XX_CB_AMC_RATE_SET           (as60xx->Param.CR11.AMC_RATE);
    as60xx->CR[11]  |= AS60XX_CB_PWD_EN_SET             (as60xx->Param.CR11.PWD_EN);
    as60xx->CR[11]  |= AS60XX_CB_PGA_TRIM_SET           (as60xx->Param.CR11.PGA_TRIM);
    as60xx->CR[11]  |= AS60XX_CB_PGA_EN_MODE_SET        (as60xx->Param.CR11.PGA_EN_MODE);
    as60xx->CR[11]  |= AS60XX_CB_PGA_MODE_SET           (as60xx->Param.CR11.PGA_MODE);
    as60xx->CR[11]  |= AS60XX_CB_NOT_USED_22_SET        (as60xx->Param.CR11.NOT_USED_22);
    as60xx->CR[11]  |= AS60XX_CB_AM_PD_START_MODE_SET   (as60xx->Param.CR11.AM_PD_START_MODE);
    as60xx->CR[11]  |= AS60XX_CB_ZCD_FHL_INIT_SET       (as60xx->Param.CR11.ZCD_FHL_INIT);
    /* Parameter for CR[12] */
    as60xx->CR[12]  = 0;// Clearing the register
    as60xx->CR[12]  |= AS60XX_CC_TRIM1_SET              (as60xx->Param.CR12.TRIM1);
    /* Parameter for CR[13] */
    as60xx->CR[13]  = 0;// Clearing the register
    as60xx->CR[13]  |= AS60XX_CD_TRIM2_SET              (as60xx->Param.CR13.TRIM2);
    /* Parameter for CR[14] */
    as60xx->CR[14]  = 0;// Clearing the register
    as60xx->CR[14]  |= AS60XX_CE_TRIM3_SET              (as60xx->Param.CR14.TRIM3);
    /* Parameter for CR[15] */
    as60xx->CR[15]  = 0;// Clearing the register
    as60xx->CR[15]  |= AS60XX_D0_TOF_RATE_SET           (as60xx->Param.CR15.TOF_RATE);
    as60xx->CR[15]  |= AS60XX_D0_NOT_USED_31_6_SET      (as60xx->Param.CR15.NOT_USED_31_6);
    /* Parameter for CR[16] */
    as60xx->CR[16]  = 0;// Clearing the register
    as60xx->CR[16]  |= AS60XX_D1_USM_RLS_DLY_U_SET      (as60xx->Param.CR16.USM_RLS_DLY_U);
    as60xx->CR[16]  |= AS60XX_D1_NOT_USED_31_19_SET     (as60xx->Param.CR16.NOT_USED_31_19);
    /* Parameter for CR[17] */
    as60xx->CR[17]  = 0;// Clearing the register
    as60xx->CR[17]  |= AS60XX_D2_USM_RLS_DLY_D_SET      (as60xx->Param.CR17.USM_RLS_DLY_D);
    as60xx->CR[17]  |= AS60XX_D2_NOT_USED_31_19_SET     (as60xx->Param.CR17.NOT_USED_31_19);
    /* Parameter for CR[18] */
    as60xx->CR[18]  = 0;// Clearing the register
    as60xx->CR[18]  |= AS60XX_DA_ZCD_FHL_U_SET          (as60xx->Param.CR18.ZCD_FHL_U);
    as60xx->CR[18]  |= AS60XX_DA_NOT_USED_31_8_SET      (as60xx->Param.CR18.NOT_USED_31_8);
    /* Parameter for CR[19] */
    as60xx->CR[19]  = 0;// Clearing the register
    as60xx->CR[19]  |= AS60XX_DB_ZCD_FHL_D_SET          (as60xx->Param.CR19.ZCD_FHL_D);
    as60xx->CR[19]  |= AS60XX_DB_NOT_USED_31_8_SET      (as60xx->Param.CR19.NOT_USED_31_8);
}

static inline void As6xx_Initialize_Configuration(ScioSense_As60xx* as60xx)
{
  uint8_t registersToWrite[] = {
        0x0C0, 0X0C1, 0x0C2, 0x0C3, 0x0C4, 0x0C5, 0x0C6, 0x0C7, 0x0C8, 0x0C9, 0x0CA, 0x0CB, 0x0CC, 0x0CD, 0x0CE,
        0x0D0, 0x0D1, 0x0D2,                                                  0x0DA, 0x0DB};
  for( uint8_t idx=0; idx<AS60XX_AMOUNT_CONFIGURATION_REGISTERS; idx++ )
  {
    as60xx->Addresses[idx] = registersToWrite[idx];
  }

  as60xx->State = AS60XX_STATE_RESET;

  as60xx->Param.CR0.WS_DIS              = 0xAF0A7435;

  as60xx->Param.CR1.PI_TPW              = 0;                            /*!< Pulse Interface, Pulse Width */
  as60xx->Param.CR1.PI_EN               = 0;                            /*!< Pulse Interface Enable */
  as60xx->Param.CR1.PI_OUT_MODE         = 0;                            /*!< Pulse Interface Output Mode */
  as60xx->Param.CR1.PI_UPD_MODE         = 0;                            /*!< Pulse Interface Update Mode */
  as60xx->Param.CR1.NOT_USED_11         = AS60XX_C1_NOT_USED_11;        /*!< Mandatory setting: b0 */
  as60xx->Param.CR1.I2C_MODE            = 0;                            /*!< 2-wire master interface mode */
  as60xx->Param.CR1.I2C_ADR             = 0;                            /*!< 2-wire master interface slave address */
  as60xx->Param.CR1.NOT_USED_21         = AS60XX_C1_NOT_USED_21;        /*!< Mandatory setting: b0 */
  as60xx->Param.CR1.SPI_INPORT_CFG      = 0;                            /*!< Configuration of SPI input ports */
  as60xx->Param.CR1.NOT_USED_31_24      = AS60XX_C1_NOT_USED_31_24;     /*!< Not used */

  as60xx->Param.CR2.GP0_DIR             = 0;                            /*!< Direction of General Purpose Port 0 */
  as60xx->Param.CR2.GP0_SEL             = 0;                            /*!< Output Select of General Purpose Port 0 */
  as60xx->Param.CR2.GP1_DIR             = 0;                            /*!< Direction of General Purpose Port 1 */
  as60xx->Param.CR2.GP1_SEL             = 0;                            /*!< Output Select of General Purpose Port 1 */
  as60xx->Param.CR2.GP2_DIR             = 0;                            /*!< Direction of General Purpose Port 2 */
  as60xx->Param.CR2.GP2_SEL             = 0;                            /*!< Output Select of General Purpose Port 2 */
  as60xx->Param.CR2.GP3_DIR             = 0;                            /*!< Direction of General Purpose Port 3 */
  as60xx->Param.CR2.GP3_SEL             = 0;                            /*!< Output Select of General Purpose Port 3 */
  as60xx->Param.CR2.GP4_DIR             = 0;                            /*!< Direction of General Purpose Port 4 */
  as60xx->Param.CR2.GP4_SEL             = 0;                            /*!< Output Select of General Purpose Port 4 */
  as60xx->Param.CR2.GP5_DIR             = 0;                            /*!< Direction of General Purpose Port 5 */
  as60xx->Param.CR2.GP5_SEL             = 0;                            /*!< Output Select of General Purpose Port 5 */
  as60xx->Param.CR2.NOT_USED_31_24      = AS60XX_C2_NOT_USED_31_24;     /*!< Not used */

  as60xx->Param.CR3.USM_OPT             = 0;                            /*!< Mandatory setting: b00001 */
  as60xx->Param.CR3.NOT_USED_31_5       = AS60XX_C3_NOT_USED_31_5;      /*!< Not used */
  
  as60xx->Param.CR4.EF_EN_TDC_TMO       = 0;                            /*!< Error Flag Enable, TDC Timeout */
  as60xx->Param.CR4.EF_EN_TOF_TMO       = 0;                            /*!< Error Flag Enable, TOF Timeout */
  as60xx->Param.CR4.EF_EN_AM_TMO        = 0;                            /*!< Error Flag Enable, Amplitude Measurement Timeout */
  as60xx->Param.CR4.EF_EN_TM_OC         = 0;                            /*!< Error Flag Enable, Temperature Measurement Open Circuit */
  as60xx->Param.CR4.EF_EN_TM_SC         = 0;                            /*!< Error Flag Enable, Temperature Measurement Short Circuit */
  as60xx->Param.CR4.EF_EN_ZCC_ERR       = 0;                            /*!< Error Flag Enable, Zero Cross Calibration Error */
  as60xx->Param.CR4.EF_EN_LBD_ERR       = 0;                            /*!< Error Flag Enable, Low Battery Detect Error */
  as60xx->Param.CR4.EF_EN_USM_SQC_TMO   = 0;                            /*!< Error Flag Enable, Ultrasonic Sequence Timeout */
  as60xx->Param.CR4.EF_EN_TM_SQC_TMO    = 0;                            /*!< Error Flag Enable, Temperature Sequence Timeout */
  as60xx->Param.CR4.EF_EN_TSQ_TMO       = 0;                            /*!< Error Flag Enable, Task Sequencer Timeout */
  as60xx->Param.CR4.EF_EN_I2C_ACK_ERR   = 0;                            /*!< Error Flag Enable, EEPROM Acknowledge Error */
  as60xx->Param.CR4.EF_EN_CHP_ERR       = 0;                            /*!< Mandatory setting: b0 */
  as60xx->Param.CR4.EF_EN_NVM_FWCU_ERR  = 0;                            /*!< Error Flag Enable, NVM FWCU Error */
  as60xx->Param.CR4.EF_EN_NVM_FWDU_ERR  = 0;                            /*!< Error Flag Enable, NVM FWDU Error */
  as60xx->Param.CR4.EF_EN_NVM_FWA_ERR   = 0;                            /*!< Error Flag Enable, NVM Applied Firmware Error */
  as60xx->Param.CR4.EF_EN_CPU_ERR       = 0;                            /*!< Error Flag Enable, CPU Error */
  as60xx->Param.CR4.IRQ_EN_TSQ_FNS      = 0;                            /*!< Interrupt Request Enable, Task Sequencer finished */
  as60xx->Param.CR4.IRQ_EN_TRANS_FNS    = 0;                            /*!< Interrupt Request Enable, FW Transaction finished */
  as60xx->Param.CR4.IRQ_EN_BLD_FNS      = 0;                            /*!< Interrupt Request Enable, Bootload finished */
  as60xx->Param.CR4.IRQ_EN_CHKSUM_FNS   = 0;                            /*!< Interrupt Request Enable, Checksum generation finished */
  as60xx->Param.CR4.IRQ_EN_FW_S         = 0;                            /*!< Interrupt Request Enable, Firmware, synchronized with task sequencer */
  as60xx->Param.CR4.IRQ_EN_TSQ_TO       = 0;                            /*!< Interrupt Request Enable, Firmware */
  as60xx->Param.CR4.NOT_USED_22         = AS60XX_C4_NOT_USED_22;        /*!< Error Flag Enable, Charge Pump Error */
  as60xx->Param.CR4.IRQ_EN_ERR_FLAG     = 0;                            /*!< Interrupt Request Enable, Error Flag */
  as60xx->Param.CR4.NOT_USED_26_24      = AS60XX_C4_NOT_USED_26_24;     /*!< Mandatory setting: b000 */
  as60xx->Param.CR4.CPU_REQ_EN_GPH      = 0;                            /*!< CPU Request Enable, General Purpose Handling */
  as60xx->Param.CR4.TS_GPT_RATE         = 0;                            /*!< General Purpose Timer Rate */
  
  as60xx->Param.CR5.HSC_DIV_MODE        = 0;                            /*!< High Speed Clock Divider Mode */
  as60xx->Param.CR5.NOT_USED_1          = AS60XX_C5_NOT_USED_1;         /*!< Mandatory setting: b0 */
  as60xx->Param.CR5.HSC_CLK_ST          = 0;                            /*!< High-Speed Clock Settling Time */
  as60xx->Param.CR5.NOT_USED_7_5        = AS60XX_C5_NOT_USED_7_5;       /*!< Recommended setting: b001 */
  as60xx->Param.CR5.HSC_DIV             = 0;                            /*!< High-Speed Clock Divider */
  as60xx->Param.CR5.HSC_RATE            = 0;                            /*!< High-Speed Clock Calibration Rate */
  as60xx->Param.CR5.HSC_MODE_CPU        = 0;                            /*!< High-Speed Clock Mode CPU */
  as60xx->Param.CR5.VM_RATE             = 0;                            /*!< VCC Voltage measurement rate */
  as60xx->Param.CR5.LBD_TH              = 0;                            /*!< Low battery detection threshold */
  as60xx->Param.CR5.TSV_UPD_MODE        = 0;                            /*!< Time stamp update mode */
  as60xx->Param.CR5.BF_SEL              = 0;                            /*!< Base Frequency Select */
  as60xx->Param.CR5.CHP_HV_SEL          = 1;         			/*!< Selection of charge pump voltage */
  as60xx->Param.CR5.NOT_USED_28         = AS60XX_C5_NOT_USED_28;        /*!< Mandatory setting: b0 */
  as60xx->Param.CR5.TI_PATH_SEL         = 0;                            /*!< Transducer Fire Buffer Impedance */
  as60xx->Param.CR5.NOT_USED_31         = AS60XX_C5_NOT_USED_31;        /*!< Mandatory setting: b0 */

  as60xx->Param.CR6.MR_CT               = 0;                            /*!< Measure rate cycle time */
  as60xx->Param.CR6.TS_MCM              = 0;                            /*!< Task Sequencer Measure Cycle Mode */
  as60xx->Param.CR6.TS_PP_T_EN          = 0;                            /*!< Enables final post processing T */
  as60xx->Param.CR6.TS_PP_F_EN          = 0;                            /*!< Enables post processing F */
  as60xx->Param.CR6.TS_PP_MODE          = 0;                            /*!< Post processing mode */
  as60xx->Param.CR6.TS_CST_RATE         = 0;                            /*!< Firmware Check(sum) Timer Rate */
  as60xx->Param.CR6.TS_NVR_RATE         = 0;                            /*!< Recall Timer Rate */
  as60xx->Param.CR6.NOT_USED_25_24      = AS60XX_C6_NOT_USED_25_24;     /*!< Mandatory setting: b01 */
  as60xx->Param.CR6.NOT_USED_30      	= 0;                            /*!< Mandatory setting: b0 */
  as60xx->Param.CR6.TS_CST_MODE         = 0;                            /*!< Checksum Handling Mode */

  as60xx->Param.CR7.TM_RATE             = 0;                            /*!< Temperature Measurement Rate */
  as60xx->Param.CR7.TPM_PAUSE           = 0;                            /*!< Pause time between 2 temperature measurements */
  as60xx->Param.CR7.TM_MODE             = 0;                            /*!< Temperature Measurement Mode */
  as60xx->Param.CR7.NOT_USED_16         = AS60XX_C7_NOT_USED_16;        /*!< Mandatory setting: b0 */
  as60xx->Param.CR7.TPM_PORT_MODE       = 0;                            /*!< Temperature Measurement Port Mode */
  as60xx->Param.CR7.TM_PORT_ORDER       = 0;                            /*!< Temperature Measurement Port Order */
  as60xx->Param.CR7.TPM_CLOAD_TRIM      = 0;                            /*!< Temperature Measurement Load Trim */
  as60xx->Param.CR7.TPM_CYCLE_SEL       = 0;                            /*!< Temperature Measurement Cycle Select */
  as60xx->Param.CR7.TPM_FAKE_NO         = 0;                            /*!< Number of Fake measurements */
  as60xx->Param.CR7.NOT_USED_31_24      = AS60XX_C7_NOT_USED_31_24;     /*!< Mandatory setting: h00 */

  as60xx->Param.CR8.USM_PAUSE           = 0;                            /*!< Pause time between two ultrasonic measurements */
  as60xx->Param.CR8.TI_PGA_AZ_DIS       = AS60XX_C8_TI_PGA_AZ_DIS_ENABLED;             /*!< Mandatory setting: b0 */
  as60xx->Param.CR8.USM_DIR_MODE        = 0;                            /*!< Ultrasonic Measurement Direction Mode */
  as60xx->Param.CR8.USM_NOISE_MASK_WIN  = 0;                            /*!< Noise Mask Window */
  as60xx->Param.CR8.USM_TO              = 0;                            /*!< Timeout */
  as60xx->Param.CR8.NOT_USED_18         = AS60XX_C8_NOT_USED_18;        /*!< Mandatory setting: b0 */
  as60xx->Param.CR8.USM_RLS_MODE        = 0;                            /*!< Select mode for multihit start release */
  as60xx->Param.CR8.ZCC_RATE            = 0;                            /*!< Zero Cross Calibration Rate */
  as60xx->Param.CR8.NOT_USED_29_23      = 0;                            /*!< Mandatory setting: b0000000 */
  as60xx->Param.CR8.TI_PGA_CON_MODE     = AS60XX_C8_TI_PGA_CON_MODE_WITH_EXTERNAL;     /*!< Connection of PGA filter */

  as60xx->Param.CR9.FBG_CLK_DIV         = 0;                            /*!< Clock divider for fire burst generator */
  as60xx->Param.CR9.FBG_MODE            = 0;                            /*!< Fire Burst Generator Mode */
  as60xx->Param.CR9.FBG_PHASE_INS       = 0;                            /*!< Fire Burst Generator, Phase Insertion */
  as60xx->Param.CR9.FBG_BURST_PRE       = 0;                            /*!< Fire Burst Generator, pre-burst */
  as60xx->Param.CR9.FBG_BURST_POST      = 0;                            /*!< Fire Burst Generator, post-burst */
  as60xx->Param.CR9.NOT_USED_28         = AS60XX_C9_NOT_USED_28;        /*!< Mandatory setting: b0 */
  as60xx->Param.CR9.NOT_USED_29         = AS60XX_C9_NOT_USED_29;        /*!< Mandatory setting: b1 */
  as60xx->Param.CR9.TOF_HIT_MODE        = 0;                            /*!< TOF data in FDB according to Multi-Hit Mode */
  as60xx->Param.CR9.NOT_USED_31         = AS60XX_C9_NOT_USED_31;        /*!< Mandatory setting: b0 */

  as60xx->Param.CR10.NOT_USED_0         = AS60XX_CA_NOT_USED_0;         /*!< Mandatory setting: b0 */
  as60xx->Param.CR10.TOF_HIT_START      = 0;                            /*!< Defines number of detected hits (including first hit) */
  as60xx->Param.CR10.TOF_HIT_IGN        = 0;                            /*!< Number of multi hits ignored between two hits taken for TDC measurement */
  as60xx->Param.CR10.TOF_HIT_SUM_NO     = 0;                            /*!< Number of hits taken for sum value of TOF measurement */
  as60xx->Param.CR10.TOF_HIT_END        = 0;                            /*!< TOF Hits stored to frontend data buffer */
  as60xx->Param.CR10.NOT_USED_21_20     = AS60XX_CA_NOT_USED_21_20;     /*!< Mandatory setting: b00 */
  as60xx->Param.CR10.TOF_EDGE_MODE      = 0;                            /*!< Time of Flight, edge mode */
  as60xx->Param.CR10.TOF_RATE_INIT      = 0;                            /*!< FWD copy of initial value for TOF rate */
  as60xx->Param.CR10.NOT_USED_31_30     = AS60XX_CA_NOT_USED_31_30;     /*!< Not Used */

  as60xx->Param.CR11.AM_RATE            = 0;                            /*!< Amplitude measurement rate */
  as60xx->Param.CR11.NOT_USED_3         = AS60XX_CB_NOT_USED_3;         /*!< Default setting: b0 */
  as60xx->Param.CR11.AM_PD_END          = 0;                            /*!< Amplitude measurement, end of peak detection */
  as60xx->Param.CR11.NOT_USED_11_9      = AS60XX_CB_NOT_USED_11_9;      /*!< Mandatory setting: b111 */
  as60xx->Param.CR11.AMC_RATE           = 0;                            /*!< Amplitude measurement calibration rate */
  as60xx->Param.CR11.PWD_EN             = 0;                            /*!< Enables pulse width detection */
  as60xx->Param.CR11.PGA_TRIM           = 0;                            /*!< DC gain of the PGA */
  as60xx->Param.CR11.PGA_EN_MODE        = 0;                            /*!< PGA enable mode */
  as60xx->Param.CR11.PGA_MODE           = 0;                            /*!< Ultrasonic measurement PGA Mode */
  as60xx->Param.CR11.NOT_USED_22        = AS60XX_CB_NOT_USED_22;        /*!< Mandatory setting: b0 */
  as60xx->Param.CR11.AM_PD_START_MODE   = 0;                            /*!< Peak Detection Start Mode */
  as60xx->Param.CR11.ZCD_FHL_INIT       = 0;                            /*!< FWD copy of initial value for first hit levels */
  
  as60xx->Param.CR12.TRIM1              = AS60XX_CC_TRIM1_DEFAULT;      /*!< Default setting: 0x95A0C06C */

  as60xx->Param.CR13.TRIM2              = AS60XX_CD_TRIM2_DEFAULT;      /*!< Default setting: 0x40110000 */

  as60xx->Param.CR14.TRIM3              = AS60XX_CE_TRIM3_DEFAULT;      /*!< Default setting: 0x4027000F */

  as60xx->Param.CR15.TOF_RATE           = 0;                            /*!< TOF Rate */
  as60xx->Param.CR15.NOT_USED_31_6      = AS60XX_D0_NOT_USED_31_6;      /*!< Not used */

  as60xx->Param.CR16.USM_RLS_DLY_U      = 0;                            /*!< Delay window in up direction, releasing ultrasonic measurement */
  as60xx->Param.CR16.NOT_USED_31_19     = AS60XX_D1_NOT_USED_31_19;     /*!< Not used */
  
  as60xx->Param.CR17.USM_RLS_DLY_D      = 0;                            /*!< Delay window in down direction, releasing ultrasonic measurement */
  as60xx->Param.CR17.NOT_USED_31_19     = AS60XX_D2_NOT_USED_31_19;     /*!< Not used */

  as60xx->Param.CR18.ZCD_FHL_U          = 0;                            /*!< First Hit Level Up */
  as60xx->Param.CR18.NOT_USED_31_8      = AS60XX_DA_NOT_USED_31_8;      /*!< Not used */

  as60xx->Param.CR19.ZCD_FHL_D          = 0;                            /*!< First Hit Level Down */
  as60xx->Param.CR19.NOT_USED_31_8      = AS60XX_DB_NOT_USED_31_8;      /*!< Not used */

  As60xx_Update_Configuration(as60xx);
}

#undef read
#undef write
#undef wait

#endif // SCIOSENSE_AS60XX_C
