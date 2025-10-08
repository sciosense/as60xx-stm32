#include "as6031f1.h"

static const char* as6031F1_ErrorNames[AS6031F1_AMOUNT_ERROR_FLAGS] =
{
    "HS Clock Calibration deviation is too large",
    "Amplitude difference exceeds limits",
    "Measured amplitude is below minimum",
    "PWR difference exceeds limits",
    "Deviation from former SUMTOF average exceeds limits",
    "Current FHL is inconsistent with configuration",
    "Measurement not ok, e.g. low or no signal",
    "",
    "Flow exceeds 2*maximum flow and is forced to zero",
    "Flow is below negative limit and stored separately",
    "Stored flow volume had an unrecoverable error",
    "Validation warning from the phase-shift routines",
    "Jump detection error",
    "Calculated velocity of sound is outside limits",
    "Bubbles detected",
    "No water or hardware error",
    "TDC timeout",
    "TOF timeout",
    "TDC timeout reached during amplitude measurement",
    "Temperature open circuit",
    "Temperature short circuit",
    "Zero cross calibration did not converge",
    "Low supply voltage",
    "Ultrasonic sequence timeout",
    "Temperature sequence timeout",
    "Task sequencer timeout",
    "EEPROM acknowledge error",
    "",
    "FWD1 checksum error",
    "FWD2 checksum error",
    "FWU checksum error",
    "FWA checksum error"
};

Result AS6031f1::updateF1()
{
    return As6031F1_Update(this);
}

uint32_t AS6031f1::getF1VolumeIntegerPartRaw()
{
    return As6031F1_Parse_Flow_Volume_Int(this);
}

uint32_t AS6031f1::getF1VolumeFractionalPartRaw()
{
    return As6031F1_Parse_Flow_Volume_Frac(this);
}

uint32_t AS6031f1::getF1InstantFlowRaw()
{
    return As6031F1_Parse_Flow_Rate_Filtered_Raw(this);
}

uint32_t AS6031f1::getF1TemperatureRaw()
{
    return As6031F1_Parse_Temperature_Raw(this);
}

uint32_t AS6031f1::getF1RamIndex(uint8_t index)
{
    return As6031F1_Parse_Value(this, index);
}

uint32_t AS6031f1::getF1ErrorFlags()
{
    return As6031F1_Parse_Error_Flags(this);
}

float AS6031f1::getF1VolumeM3()
{
    return As6031F1_Parse_Flow_Volume_M3(this);
}

float AS6031f1::getF1InstantFlowLPerHr()
{
    return As6031F1_Parse_Flow_Rate_Filtered_L_Per_Hr(this);
}

float AS6031f1::getF1TemperatureDegC()
{
    return As6031F1_Parse_Temperature_Deg_C(this);
}

bool AS6031f1::hasF1ErrorFlag(As6031F1_ErrorFlag errorFlag)
{
    
    return (bool)As6031F1_HasErrorFlag(this, errorFlag);
}

const char* AS6031f1::errorF1ToString(As6031F1_ErrorFlag errorFlag)
{
    return as6031F1_ErrorNames[(uint8_t)errorFlag];
}
