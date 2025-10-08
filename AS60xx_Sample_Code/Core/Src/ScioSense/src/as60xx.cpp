#include "as60xx.h"
#include "lib/as60xx/ScioSense_As60xx.h"
#include "lib/io/ScioSense_IOInterface_STM32.c"

static const char* as60xx_ErrorNames[AS60XX_AMOUNT_ERROR_FLAGS] =
{
    "TDC timeout",
    "TOF timeout",
    "Amplitude measurement timeout",
    "Temperature measurement open circuit",
    "Temperature measurement short circuit",
    "Zero cross calibration",
    "Low battery detect",
    "Ultrasonic sequence timeout",
    "Temperature sequence timeout",
    "Task sequencer timeout",
    "EEPROM acknowledge",
    "Charge pump error",
    "NVM error in FWCU area",
    "NVM error in FWDU area",
    "NVM error in any FWA area",
    "CPU error"
};

AS60xx::~AS60xx() { }

AS60xx::AS60xx()
{
    State   = AS60XX_STATE_NOT_CONNECTED;
}

void AS60xx::begin(SPI_HandleTypeDef* spi, uint16_t cs_pin, GPIO_TypeDef* port)
{
    spiConfig               = { 0 };
    spiConfig.spi           = spi;
    spiConfig.cs_pin        = cs_pin;
    spiConfig.port          = port;

    io.read    = ScioSense_STM32_Spi_Read;
    io.write   = ScioSense_STM32_Spi_Write;
    io.wait    = ScioSense_STM32_Wait;
    io.config  = &spiConfig;
}

Result AS60xx::reset()
{
    return As60xx_Reset(this);
}

Result AS60xx::writeConfig()
{
    return As60xx_Write_Config(this);
}

Result AS60xx::startMeasurement()
{
    return As60xx_Start_Measurements(this);
}

uint32_t AS60xx::getSupplyVoltageMv()
{
    return As60xx_GetSupplyVoltageMv(this);
}

float AS60xx::getHighSpeedClockFrequencyHz()
{
    return As60xx_GetHsClkFreqHz(this);
}

As60xx_Timestamp AS60xx::getTimestamp()
{
    return As60xx_GetTimestamp(this);
}

bool AS60xx::hasError()
{
    return (bool)As60xx_HasAnyError(this);
}

uint32_t AS60xx::getErrorRegister()
{
    return As60xx_GetRawErrorFlags(this);
}

bool AS60xx::hasErrorFlag(As60xx_ErrorFlag errorFlag)
{
    return (bool)As60xx_HasErrorFlag(this, errorFlag);
}

const char* AS60xx::errorToString(As60xx_ErrorFlag errorFlag)
{
    return as60xx_ErrorNames[(uint8_t)errorFlag];
}

Result AS60xx::writeFW(uint8_t* FWC, int32_t FWC_Length, uint8_t* FWD, int32_t FWD_Length)
{
    return As60xx_Write_Fw(this, FWC, FWC_Length, FWD, FWD_Length);
}

bool AS60xx::init()
{
    As60xx_Init(this);

    return isConnected();
}

bool AS60xx::isConnected()
{
    return (bool)As60xx_isConnected(this);
}

AS60xx_Measure_Type AS60xx::update()
{
    return As60xx_Update(this);
}

uint32_t AS60xx::getSumTofUp()
{
    return As60xx_GetSumTofUp(this);
}

uint32_t AS60xx::getSumTofDown()
{
    return As60xx_GetSumTofDown(this);
}

uint32_t AS60xx::getAmountHitsForSumToF()
{
    return As60xx_GetAmountHitsForSumTof(this);
}

float AS60xx::calculateTimeNs(uint32_t contentTDCRegister)
{
    return ((float)As60xx_CalculateTDCTimePs(this, contentTDCRegister)) / 1000.0;
}

uint32_t AS60xx::calculateTimePs(uint32_t contentTDCRegister)
{
    return As60xx_CalculateTDCTimePs(this, contentTDCRegister);
}

void AS60xx::getTemperatures2WireDegC(float* temperatures2Wire)
{
    AS60xx_CalculateTemperature2Wire(this, temperatures2Wire);
}

float AS60xx::getInternalTemperatureDegC()
{
    return AS60xx_CalculateInternalTemperature(this);
}

uint32_t AS60xx::getAmplitudeUp()
{
    return As60xx_GetAmplitudeUp(this);
}

uint32_t AS60xx::getAmplitudeDown()
{
    return As60xx_GetAmplitudeDown(this);
}

float AS60xx::getPulseWidthRatioUp()
{
    return As60xx_GetPulseWidthRatioUp(this);
}

float AS60xx::getPulseWidthRatioDown()
{
    return As60xx_GetPulseWidthRatioDown(this);
}

void AS60xx::getTofValuesUp(uint32_t* tofValues)
{
    return As60xx_GetTofValuesUp(this, tofValues);
}

void AS60xx::getTofValuesDown(uint32_t* tofValues)
{
    return As60xx_GetTofValuesDown(this, tofValues);
}

void AS60xx::updateConfiguration()
{
    As60xx_Update_Configuration(this);
}

void AS60xx::setConfigurationRegisters(uint32_t* configurationRegisters)
{
    As60xx_Set_Configuration_Registers(this, configurationRegisters);
}
