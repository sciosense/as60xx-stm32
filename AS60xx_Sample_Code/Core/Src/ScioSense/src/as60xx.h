#ifndef SCIOSENSE_AS60XX_H
#define SCIOSENSE_AS60XX_H

#include <stdint.h>

#include "lib/as60xx/ScioSense_As60xx.h"
#include "lib/io/ScioSense_IOInterface_STM32.c"

class AS60xx : public ScioSense_As60xx
{
    public:
        AS60xx();
        virtual ~AS60xx();

    public:
        virtual void        begin                               (SPI_HandleTypeDef* spi, uint16_t cs_pin, GPIO_TypeDef* port);          // Connnects to AS60XX through SPI
        virtual bool        isConnected                         ();                                 // Checks if a communication to the device was established; returns true, if so.
        bool                init                                ();                                 // Resets the device and configuration

    public:
        AS60xx_Measure_Type update                              ();                                 // Reads the Frontend Data Buffer and Status
        Result              reset                               ();                                 // Software reset the device

    public:
        void                updateConfiguration                 ();                                 // Update the 
        Result              writeConfig                         ();                                 // Write and check the configuration into the AS60xx
        void                setConfigurationRegisters           (uint32_t* configurationRegisters); // Set the configuration from an array containing the values for registers 0xC0-0xCE, 0xD0-0xD2, and 0xDA-0xDB
        Result              startMeasurement                    ();                                 // Perform soft reset and turn the Measure Cycle Timer on
        uint32_t            getSupplyVoltageMv                  ();                                 // Get the supply voltage at the AS60xx
        float               getHighSpeedClockFrequencyHz        ();                                 // Get the High Speed Clock frequency in Hz
        As60xx_Timestamp    getTimestamp                        ();                                 // Convert the value read through the update function into a timestamp value
    
    public:
        Result              writeFW                             (uint8_t* FWC, int32_t FWC_Length, uint8_t* FWD, int32_t FWD_Length);   // Write firmware code and firmware data to the AS60xx, returns if the write process was successful

    public:
        bool                hasError                            ();                                 // Checks if any error flag has been activated
        uint32_t            getErrorRegister                    ();                                 // Returns the content of the SRR_ERR_FLAG error flags register
        bool                hasErrorFlag                        (As60xx_ErrorFlag errorFlag);       // Checks if the provided flag has been activated
        const char*         errorToString                       (As60xx_ErrorFlag errorFlag);       // Returns a string that describes the provided error

    public:
        uint32_t            getSumTofUp                         ();                                 // Get the sum of all upstream TOF values
        uint32_t            getSumTofDown                       ();                                 // Get the sum of all downstream TOF values
        uint32_t            getAmountHitsForSumToF              ();                                 // Gets the configured amount of hits used for calculating the ToF sum
        float               calculateTimeNs                     (uint32_t contentTDCRegister);      // Transforms the content of a TDC register content to nanoseconds
        uint32_t            calculateTimePs                     (uint32_t contentTDCRegister);      // Transforms the content of a TDC register content to picoseconds
        void                getTemperatures2WireDegC            (float* temperatures2Wire);         // Get the temperatures of the RTDs wired in 2-wire mode in degrees Celsius
        float               getInternalTemperatureDegC          ();                                 // Get the internal temperature. Uncalibrated value, must add a T0 offset
        uint32_t            getAmplitudeUp                      ();                                 // Get the amplitude of the upstream pulses in millivolts
        uint32_t            getAmplitudeDown                    ();                                 // Get the amplitude of the downstream pulses in millivolts
        float               getPulseWidthRatioUp                ();                                 // Get the ratio of the upstream pulse widths
        float               getPulseWidthRatioDown              ();                                 // Get the ratio of the downstream pulse widths
        void                getTofValuesUp                      (uint32_t* tofValues);              // Get an array with the TOF of each upstream pulse
        void                getTofValuesDown                    (uint32_t* tofValues);              // Get an array with the TOF of each upstream pulse
    
        protected:
        ScioSense_Stm32_Spi_Config        		spiConfig;
};

#endif //SCIOSENSE_AS60XX_H
