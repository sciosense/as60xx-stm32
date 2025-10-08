#ifndef SCIOSENSE_AS6031F1_H
#define SCIOSENSE_AS6031F1_H

#include <stdint.h>

#include "as60xx.h"

class AS6031f1 : public AS60xx
{
    public:
        Result      updateF1                        ();                                 // Read the AS6031F1 firmware data

    public:
        uint32_t    getF1VolumeIntegerPartRaw       ();                                 // Parse the content of the VOLUME_INT output
        uint32_t    getF1VolumeFractionalPartRaw    ();                                 // Parse the content of the VOLUME_FRAC output
        uint32_t    getF1InstantFlowRaw             ();                                 // Parse the content of the FLOW_LPH output
        uint32_t    getF1TemperatureRaw             ();                                 // Parse the content of the TEMPERATURE output
        uint32_t    getF1ErrorFlags                 ();                                 // Parse the content of the ERROR_FLAGS output
       
    public:
        float       getF1VolumeM3                   ();                                 // Parse the total volume of fluid measured in cubic meters
        float       getF1InstantFlowLPerHr          ();                                 // Parse instant flow in litres per hour
        float       getF1TemperatureDegC            ();                                 // Parse temperature measured in degrees Celsius
        
    public:
        uint32_t    getF1RamIndex                   (uint8_t index);                    // Get the raw value of the indicated RAM register
    
    public:
        bool        hasF1ErrorFlag                  (As6031F1_ErrorFlag errorFlag);     // Checks if the firmware output has the specified error
        const char* errorF1ToString                 (As6031F1_ErrorFlag errorFlag);     // Return a string that describes the provided firmware error
};

#endif //SCIOSENSE_AS6031F1_H
