
#define AS6031F1_FD8_DIVIDER_FLOAT                      (256.0)                                                 // Floating point value of 2^16 
#define AS6031F1_FD16_DIVIDER_FLOAT                     (65536.0)                                               // Floating point value of 2^16 
#define AS6031F1_FD32_DIVIDER_FLOAT                     (4294967296.0)                                          // Floating point value of 2^32 

/***************************  Register RAM AS6031F1  **************************/
#define AS6031F1_RAM_RAM_R_FLOW_VOLUME_INT              (0x000)                                                 // Signed integer part of total volume of water flow in cubic meters
#define AS6031F1_RAM_RAM_R_FLOW_VOLUME_FRACTION         (0x001)                                                 // Unsigned factional part of total volume of water flow in cubic meters
#define AS6031F1_RAM_RAM_R_FLOW_LPH                     (0x002)                                                 // Presently calculated flow volume (l/h)
#define AS6031F1_RAM_RAM_FILTERED_FLOW_LPH              (0x003)                                                 // Filtered flow volume (l/h)
#define AS6031F1_RAM_RAM_R_THETA                        (0x004)                                                 // Temperature (°C) calculated from SUMTOF
#define AS6031F1_RAM_RAM_SOUND_VEL                      (0x005)                                                 // Velocity of sound (m/s)
#define AS6031F1_RAM_RAM_FLOW_SPEED                     (0x006)                                                 // Calculated speed of flow (m/s)
#define AS6031F1_RAM_RAM_R_TOF_DIFF                     (0x007)                                                 // Current DIFTOF in raw TDC units
#define AS6031F1_RAM_RAM_R_TOF_SUM                      (0x008)                                                 // Current SUMTOF in raw TDC units
#define AS6031F1_RAM_RAM_R_AM_MIN_RAW                   (0x01C)                                                 // Minimal acceptable signal amplitude
#define AS6031F1_RAM_RAM_R_AMC_GRADIENT                 (0x01D)                                                 // Latest amplitude calibration gradient value
#define AS6031F1_RAM_RAM_R_AMC_OFFSET                   (0x01E)                                                 // Latest amplitude calibration offset value
#define AS6031F1_RAM_RAM_R_V1F_COEFF_ADR                (0x01F)                                                 // Temporary variable for PWL coefficients table address
#define AS6031F1_RAM_RAM_R_PTC_TEMPERATURE              (0x020)                                                 // Cold sensor temperature (°C)
#define AS6031F1_RAM_RAM_R_PTH_TEMPERATURE              (0x021)                                                 // Hot sensor temperature (°C)
#define AS6031F1_RAM_RAM_PTC_RES                        (0x022)                                                 // Cold sensor resistance (Ω)
#define AS6031F1_RAM_RAM_R_PTH_RES                      (0x023)                                                 // Hot sensor resistance (Ω)
#define AS6031F1_RAM_RAM_R_PT_INT_TEMPERATURE           (0x024)                                                 // Internal sensor temperature (°C)
#define AS6031F1_RAM_RAM_R_FW_STATUS                    (0x025)                                                 // Firmware status bits, see 6.1.1 bits
#define AS6031F1_RAM_RAM_FLOW_COUNTER                   (0x026)                                                 // Internal counter for flow values after last average update int
#define AS6031F1_RAM_RAM_R_FW_ERR_FLAGS                 (0x027)                                                 // Firmware and hardware error flags
#define AS6031F1_RAM_RAM_R_FHL_ERR_CTR                  (0x028)                                                 // Internal error counter
#define AS6031F1_RAM_RAM_V2B_PH_S_UP_0                  (0x02B)                                                 // Phase-shift time 0 UP in multiples of Tref
#define AS6031F1_RAM_RAM_V2C_PH_S_UP_1                  (0x02C)                                                 // Phase-shift time 1 UP in multiples of Tref
#define AS6031F1_RAM_RAM_V2D_PH_S_UP_2                  (0x02D)                                                 // Phase-shift time 2 UP in multiples of Tref
#define AS6031F1_RAM_RAM_V2E_PH_S_UP_3                  (0x02E)                                                 // Multiple temporary use by UFC_PHASE_SHIFT.lib
#define AS6031F1_RAM_RAM_V2F_PH_S_DOWN_0                (0x02F)                                                 // Multiple temporary use by UFC_PHASE_SHIFT.lib
#define AS6031F1_RAM_RAM_V30_PH_S_DOWN_1                (0x030)                                                 // Multiple temporary use by UFC_PHASE_SHIFT.lib
#define AS6031F1_RAM_RAM_V31_PH_S_DOWN_2                (0x031)                                                 // Multiple temporary use by UFC_PHASE_SHIFT.lib
#define AS6031F1_RAM_RAM_V32_PH_S_DOWN_3                (0x032)                                                 // Multiple temporary use by UFC_PHASE_SHIFT.lib
#define AS6031F1_RAM_RAM_V33_PH_S_ERR_FLAGS             (0x033)                                                 // Error Flags for Phase-Shift
#define AS6031F1_RAM_RAM_PERIOD_UPD                     (0x034)                                                 // Period time in UP and DOWN, HSC calibrated value
#define AS6031F1_RAM_RAM_AM_AV_UP                       (0x035)                                                 // Output of amplitude IIR filter, copied also to FDB
#define AS6031F1_RAM_RAM_AM_AV_DOWN                     (0x036)                                                 // Output of amplitude IIR filter, copied also to FDB
#define AS6031F1_RAM_RAM_ERROR_COUNT_21                 (0x04D)                                                 // Peak hourly error count of counters 2 (B3/B2) and 1 (B1/B0)
#define AS6031F1_RAM_RAM_ERROR_COUNT_43                 (0x04E)                                                 // Peak hourly error count of counters 4 (B3/B2) and 3 (B1/B0)
#define AS6031F1_RAM_RAM_NEG_FLOW                       (0x04F)                                                 // Presently calculated negative flow volume (l/h), unfiltered
#define AS6031F1_RAM_RAM_NEG_FLOW_VOLUME_INT            (0x050)                                                 // Integer part of total volume of negative water flow in cubic meters
#define AS6031F1_RAM_RAM_NEG_FLOW_VOLUME_FRACTION       (0x051)                                                 // Fractional part of total volume of negative water flow in cubic meters
#define AS6031F1_RAM_RAM_C1_FLOW_VOLUME_INT             (0x052)                                                 // Safety copy 1 of flow volume, integer part
#define AS6031F1_RAM_RAM_C2_FLOW_VOLUME_INT             (0x053)                                                 // Safety copy 2 of flow volume, integer part
#define AS6031F1_RAM_RAM_C1_FLOW_VOLUME_FRACTION        (0x054)                                                 // Safety copy 1 of flow volume, fractional part
#define AS6031F1_RAM_RAM_C2_FLOW_VOLUME_FRACTION        (0x055)                                                 // Safety copy 2 of flow volume, fractional part
#define AS6031F1_RAM_RAM_FEP_STF                        (0x056)                                                 // Copy of recent SRR_FEP_STF
#define AS6031F1_RAM_RAM_LOW_AM_ERR_CTR                 (0x057)                                                 // Counter for consecutive low AM cases
#define AS6031F1_RAM_RAM_TS_ERR_CTR                     (0x058)                                                 // Counter for consecutive Task sequencer timeout errors
#define AS6031F1_RAM_RAM_R_TM_ERR_CTR                   (0x059)                                                 // Counter for consecutive TM errors
#define AS6031F1_RAM_RAM_R_USM_ERR_CTR                  (0x05A)                                                 // Counter for consecutive USM errors
#define AS6031F1_RAM_RAM_R_AM_ERR_CTR                   (0x05B)                                                 // Counter for consecutive AM errors
#define AS6031F1_RAM_RAM_CYCLE_COUNTER                  (0x05C)                                                 // This counter controls the slow FHL changes
#define AS6031F1_RAM_RAM_R_HSC_SCALE_FACT               (0x05D)                                                 // HS Clock scaling factor, deviation from nominal frequency
#define AS6031F1_RAM_RAM_R_TDC_T_BY_2L                  (0x05E)                                                 // Stores TDC_PERIOD/(2*DIST_WITH_FLOW) fd0 including HSC calibration
#define AS6031F1_RAM_RAM_R_TDC_CLK                      (0x05F)                                                 // real HSC frequency
#define AS6031F1_RAM_RAM_R_ROLAVG_1                     (0x060)                                                 // Rolling average filter for flow 1
#define AS6031F1_RAM_RAM_R_ROLAVG_2                     (0x061)                                                 // Rolling average filter for flow 2
#define AS6031F1_RAM_RAM_R_ROLAVG_3                     (0x062)                                                 // Rolling average filter for flow 3
#define AS6031F1_RAM_RAM_R_ROLAVG_4                     (0x063)                                                 // Rolling average filter for flow 4
#define AS6031F1_RAM_RAM_R_ROLAVG_5                     (0x064)                                                 // Rolling average filter for flow 5
#define AS6031F1_RAM_RAM_R_ROLAVG_6                     (0x065)                                                 // Rolling average filter for flow 6
#define AS6031F1_RAM_RAM_R_ROLAVG_7                     (0x066)                                                 // Rolling average filter for flow 7
#define AS6031F1_RAM_RAM_R_ROLAVG_8                     (0x067)                                                 // Rolling average filter for flow 8
#define AS6031F1_RAM_RAM_R_ROLAVG_9                     (0x068)                                                 // Rolling average filter for flow 9
#define AS6031F1_RAM_RAM_R_ROLAVG_10                    (0x069)                                                 // Rolling average filter for flow 10
#define AS6031F1_RAM_RAM_R_ROLAVG_11                    (0x06A)                                                 // Rolling average filter for flow 11
#define AS6031F1_RAM_RAM_R_ROLAVG_12                    (0x06B)                                                 // Rolling average filter for flow 12
#define AS6031F1_RAM_RAM_R_ROLAVG_13                    (0x06C)                                                 // Rolling average filter for flow 13
#define AS6031F1_RAM_RAM_R_ROLAVG_14                    (0x06D)                                                 // Rolling average filter for flow 14
#define AS6031F1_RAM_RAM_R_ROLAVG_15                    (0x06E)                                                 // Rolling average filter for flow 15
#define AS6031F1_RAM_RAM_R_ROLAVG_16                    (0x06F)                                                 // Rolling average filter for flow 16
#define AS6031F1_RAM_RAM_ROLAVG_DIFTOF_1                (0x070)                                                 // Rolling average filter for DIFTOF 1
#define AS6031F1_RAM_RAM_ROLAVG_DIFTOF_2                (0x071)                                                 // Rolling average filter for DIFTOF 2
#define AS6031F1_RAM_RAM_ROLAVG_DIFTOF_3                (0x072)                                                 // Rolling average filter for DIFTOF 3
#define AS6031F1_RAM_RAM_ROLAVG_DIFTOF_4                (0x073)                                                 // Rolling average filter for DIFTOF 4
#define AS6031F1_RAM_RAM_ROLAVG_DIFTOF_5                (0x074)                                                 // Rolling average filter for DIFTOF 5
#define AS6031F1_RAM_RAM_ROLAVG_DIFTOF_6                (0x075)                                                 // Rolling average filter for DIFTOF 6
#define AS6031F1_RAM_RAM_ROLAVG_DIFTOF_7                (0x076)                                                 // Rolling average filter for DIFTOF 7
#define AS6031F1_RAM_RAM_ROLAVG_DIFTOF_8                (0x077)                                                 // Rolling average filter for DIFTOF 8
#define AS6031F1_RAM_RAM_ROLAVG_SUMTOF_1                (0x078)                                                 // Rolling average filter for SUMTOF 1
#define AS6031F1_RAM_RAM_ROLAVG_SUMTOF_2                (0x079)                                                 // Rolling average filter for SUMTOF 2
#define AS6031F1_RAM_RAM_ROLAVG_SUMTOF_3                (0x07A)                                                 // Rolling average filter for SUMTOF 3
#define AS6031F1_RAM_RAM_ROLAVG_SUMTOF_4                (0x07B)                                                 // Rolling average filter for SUMTOF 4
#define AS6031F1_RAM_RAM_ROLAVG_SUMTOF_5                (0x07C)                                                 // Rolling average filter for SUMTOF 5
#define AS6031F1_RAM_RAM_ROLAVG_SUMTOF_6                (0x07D)                                                 // Rolling average filter for SUMTOF 6
#define AS6031F1_RAM_RAM_ROLAVG_SUMTOF_7                (0x07E)                                                 // Rolling average filter for SUMTOF 7
#define AS6031F1_RAM_RAM_ROLAVG_SUMTOF_8                (0x07F)                                                 // Rolling average filter for SUMTOF 8
#define AS6031F1_RAM_FDB_US_TOF_ADD_ALL_U               (0x080)                                                 // TOF Sum Up of all the configured hits
#define AS6031F1_RAM_FDB_TM_PP_M1                       (0x080)                                                 // tpp: Offset delay comp. value of Meas. 1
#define AS6031F1_RAM_FDB_US_PW_U                        (0x081)                                                 // US Pulse Width Ratio Up
#define AS6031F1_RAM_FDB_TM_PTR_RAB_M1                  (0x081)                                                 // tRAB: Reference Impedance value of Meas. 1
#define AS6031F1_RAM_FDB_US_AM_U                        (0x082)                                                 // US Amplitude Value Up
#define AS6031F1_RAM_FDB_TM_PTC_CAB_M1                  (0x082)                                                 // tCAB: PT Cold Impedance value of Meas. 1
#define AS6031F1_RAM_FDB_US_AMC_VH                      (0x083)                                                 // US Amplitude Calibrate Value High
#define AS6031F1_RAM_FDB_TM_PTH_HAB_M1                  (0x083)                                                 // tHAB: PT Hot Impedance value of Meas. 1
#define AS6031F1_RAM_FDB_US_TOF_ADD_ALL_D               (0x084)                                                 // TOF Sum Down of all the configured hits
#define AS6031F1_RAM_FDB_TM_PTR_RA_M1                   (0x084)                                                 // tRA: 1st Offset resistance value of Meas. 1
#define AS6031F1_RAM_FDB_US_PW_D                        (0x085)                                                 // US Pulse Width Ratio Down
#define AS6031F1_RAM_FDB_TM_PP_M2                       (0x085)                                                 // pp: Offset delay comp. value of Meas. 2
#define AS6031F1_RAM_FDB_US_AM_D                        (0x086)                                                 // US Amplitude Value Down
#define AS6031F1_RAM_FDB_TM_PTR_RAB_M2                  (0x086)                                                 // tRAB: Reference Impedance value of Meas. 2
#define AS6031F1_RAM_FDB_US_AMC_VL                      (0x087)                                                 // US Amplitude Calibrate Value Low
#define AS6031F1_RAM_FDB_TM_PTC_CAB_M2                  (0x087)                                                 // tCAB: PT Cold Impedance value of Meas. 2
#define AS6031F1_RAM_FDB_US_TOF_0_U                     (0x088)                                                 // Ultrasonic TOF Up Value 0
#define AS6031F1_RAM_FDB_TM_PTH_HAB_M2                  (0x088)                                                 // HAB: PT Hot Impedance value of Meas. 2
#define AS6031F1_RAM_FDB_US_TOF_1_U                     (0x089)                                                 // Ultrasonic TOF Up Value 1
#define AS6031F1_RAM_FDB_TM_PTR_RA_M2                   (0x089)                                                 // tRA: 1st Offset resistance value of Meas. 2
#define AS6031F1_RAM_FDB_US_TOF_2_U                     (0x08A)                                                 // Ultrasonic TOF Up Value 2
#define AS6031F1_RAM_FDB_TM_PTR_4W_RB_M1                (0x08A)                                                 // RB: Reference 2nd Offset res. val. of Meas. 1
#define AS6031F1_RAM_FDB_US_TOF_3_U                     (0x08B)                                                 // Ultrasonic TOF Up Value 3
#define AS6031F1_RAM_FDB_TM_PTC_4W_CA_M1                (0x08B)                                                 // tCA: PT Cold 1st Offset res. value of Meas. 1
#define AS6031F1_RAM_FDB_US_TOF_4_U                     (0x08C)                                                 // Ultrasonic TOF Up Value 4
#define AS6031F1_RAM_FDB_TM_PTC_4W_CB_M1                (0x08C)                                                 // tCB: PT Cold 2nd Offset res. value of Meas. 1
#define AS6031F1_RAM_FDB_US_TOF_5_U                     (0x08D)                                                 // Ultrasonic TOF Up Value 5
#define AS6031F1_RAM_FDB_TM_PTC_4W_AC_M1                (0x08D)                                                 // AC: PT Cold 3rd Offset res. value of Meas. 1
#define AS6031F1_RAM_FDB_US_TOF_6_U                     (0x08E)                                                 // Ultrasonic TOF Up Value 6
#define AS6031F1_RAM_FDB_TM_PTC_4W_BC_M1                (0x08E)                                                 // tBC: PT Cold 4th Offset res. value of Meas. 1
#define AS6031F1_RAM_FDB_US_TOF_7_U                     (0x08F)                                                 // Ultrasonic TOF Up Value 7
#define AS6031F1_RAM_FDB_TM_PTH_4W_HA_M1                (0x08F)                                                 // HA: PT Hot 1st Offset res. value of Meas. 1
#define AS6031F1_RAM_FDB_US_TOF_0_D                     (0x090)                                                 // Ultrasonic TOF Down Value 0
#define AS6031F1_RAM_FDB_TM_PTH_4W_HB_M1                (0x090)                                                 // tHB: PT Hot 2nd Offset res. value of Meas. 1
#define AS6031F1_RAM_FDB_US_TOF_1_D                     (0x091)                                                 // Ultrasonic TOF Down Value 1
#define AS6031F1_RAM_FDB_TM_PTH_4W_AH_M1                (0x091)                                                 // tAH: PT Hot 3rd Offset res. value of Meas. 1
#define AS6031F1_RAM_FDB_US_TOF_2_D                     (0x092)                                                 // Ultrasonic TOF Down Value 2
#define AS6031F1_RAM_FDB_TM_PTH_4W_BH_M1                (0x092)                                                 // tBH: PT Hot 4th Offset res. value of Meas. 1
#define AS6031F1_RAM_FDB_US_TOF_3_D                     (0x093)                                                 // Ultrasonic TOF Down Value 3
#define AS6031F1_RAM_FDB_TM_PTR_4W_RB_M2                (0x093)                                                 // tRB: Reference 2nd Offset res. val. of Meas. 2
#define AS6031F1_RAM_FDB_US_TOF_4_D                     (0x094)                                                 // Ultrasonic TOF Down Value 4
#define AS6031F1_RAM_FDB_TM_PTC_4W_CA_M2                (0x094)                                                 // tCA: PT Cold 1st Offset res. value of Meas. 2
#define AS6031F1_RAM_FDB_US_TOF_5_D                     (0x095)                                                 // Ultrasonic TOF Down Value 5
#define AS6031F1_RAM_FDB_TM_PTC_4W_CB_M2                (0x095)                                                 // tCB: PT Cold 2nd Offset res. value of Meas. 2
#define AS6031F1_RAM_FDB_US_TOF_6_D                     (0x096)                                                 // Ultrasonic TOF Down Value 6
#define AS6031F1_RAM_FDB_TM_PTC_4W_AC_M2                (0x096)                                                 // tAC: PT Cold 3rd Offset res. value of Meas. 2
#define AS6031F1_RAM_FDB_US_TOF_7_D                     (0x097)                                                 // Ultrasonic TOF Down Value 7
#define AS6031F1_RAM_FDB_TM_PTC_4W_BC_M2                (0x097)                                                 // tBC: PT Cold 4th Offset res. value of Meas. 2
#define AS6031F1_RAM_FDB_TM_PTH_4W_HA_M2                (0x098)                                                 // tHA: PT Hot 1st Offset res. value of Meas. 2
#define AS6031F1_RAM_FDB_TM_PTH_4W_HB_M2                (0x099)                                                 // tHB: PT Hot 2nd Offset res. value of Meas. 2
#define AS6031F1_RAM_FDB_TM_PTH_4W_AH_M2                (0x09A)                                                 // tAH: PT Hot 3rd Offset res. value of Meas. 2
#define AS6031F1_RAM_FDB_TM_PTH_4W_BH_M2                (0x09B)                                                 // tBH: PT Hot 4th Offset res. value of Meas. 2
#define AS6031F1_RAM_RAM_R_VA8_FWD1_CS                  (0x0A8)                                                 // Checksum Firmware Data 1
#define AS6031F1_RAM_RAM_R_VA9_FWD2_CS                  (0x0A9)                                                 // Checksum Firmware Data 2
#define AS6031F1_RAM_RAM_R_VAA_FWU_CS                   (0x0AA)                                                 // Checksum Firmware Code User
#define AS6031F1_RAM_RAM_R_VAB_FWA_CS                   (0x0AB)                                                 // Checksum Firmware Code ScioSenseFWD_FWU_CS

/***************************  Register FWD AS6031F1  **************************/
// Checksums user code & data
#define AS6031F1_FWD_FWU_CS_ADDRESS                     (0x100)                                                 // Checksums User code
#define AS6031F1_FWD_FWDU_CS_ADDRESS                    (0x101)                                                 // Checksums User data
// Jump flag
#define AS6031F1_FWD_JUMP_FLAG_ADDRESS                  (0x102)                                                 // Flag to trigger jump from ScioSense code to address 68 of the user code. Bit 0 = 0: Direct jump to address 68, Any Bit = 1: Indirect jump to address 68
// Error counters
#define AS6031F1_FWD_ERROR_COUNT_CONF1_ADDRESS          (0x103)                                                 // Define error flag positions to be counted in error counter 1
#define AS6031F1_FWD_ERROR_COUNT_CONF2_ADDRESS          (0x104)                                                 // Define error flag positions to be counted in error counter 2
#define AS6031F1_FWD_ERROR_COUNT_21_ADDRESS             (0x105)                                                 // Temporary storage of error counts 2 (B3, B2) and 1 (B1, B0)
#define AS6031F1_FWD_ERROR_COUNT_43_ADDRESS             (0x106)                                                 // Temporary storage of error counts 4 - each error (B3, B2) and 3 - hardware errors (B1, B0)
#define AS6031F1_FWD_ERROR_COUNT_INV21_ADDRESS          (0x107)                                                 // Inverse of 0x105 for constant checksum
#define AS6031F1_FWD_ERROR_COUNT_INV43_ADDRESS          (0x108)                                                 // Inverse of 0x106 for constant checksum
// PWL non-linear correction coeficients
#define AS6031F1_PWL_COEF_TABLE_START_ADDRESS           (0x116)                                                 // Start of the PWL calibration coefficients table
// ScioSense non-linear correction coeficients
#define AS6031F1_SCIOSENSE_COEF_TABLE_START_ADDRESS     (0x12A)                                                 // Start of the r ScioSense calibration coefficients table
// Linear calibration coefficients
#define AS6031F1_LINEAR_COEF_TABLE_START_ADDRESS        (0x136)                                                 // Start of the Linear coefficients table. 
#define AS6031F1_FWD_R_TEMP_TC1_ADDRESS                 (0x136)                                                 // Temperatures for linear calibration in °C 1st
#define AS6031F1_FWD_R_TEMP_TC2_ADDRESS                 (0x137)                                                 // Temperatures for linear calibration in °C 2nd
#define AS6031F1_FWD_R_TEMP_TC3_ADDRESS                 (0x138)                                                 // Temperatures for linear calibration in °C 3rd
#define AS6031F1_FWD_R_TEMP_TC4_ADDRESS                 (0x139)                                                 // Temperatures for linear calibration in °C 4th
#define AS6031F1_FWD_R_TOF_OFFSET_ADDRESS               (0x13A)                                                 // Offset time for SUMTOF (fd16*Tref)
#define AS6031F1_FWD_TOF_DIFF_CAL_ADDRESS               (0x13B)                                                 // DIFTOF at high flow calibration point (fd16*Tref)
#define AS6031F1_FWD_DIST_WITH_FLOW_ADDRESS             (0x13C)                                                 // Ultrasonic sound path length along flow in m (fd24)
#define AS6031F1_FWD_DIST_NO_FLOW_ADDRESS               (0x13D)                                                 // Ultrasonic sound path length w/o flow in m (fd24)
#define AS6031F1_FWD_R_ZERO_OFFSET_TC2_ADDRESS          (0x13E)                                                 // Zero flow DIFTOF, O(TC) at TC2
#define AS6031F1_FWD_R_ZERO_OFFSET_TC3_ADDRESS          (0x13F)                                                 // Zero flow DIFTOF, O(TC) at TC3
#define AS6031F1_FWD_R_ZERO_OFFSET_TC4_ADDRESS          (0x140)                                                 // Zero flow DIFTOF, O(TC) at TC4
#define AS6031F1_FWD_R_O_SLOPE_TC12_ADDRESS             (0x141)                                                 // Zero flow slope, S_O(TC) between TC1 and TC2
#define AS6031F1_FWD_R_O_SLOPE_TC23_ADDRESS             (0x142)                                                 // Zero flow slope, S_O(TC) between TC2 and TC3
#define AS6031F1_FWD_R_O_SLOPE_TC34_ADDRESS             (0x143)                                                 // Zero flow slope, S_O(TC) between TC3 and TC4
#define AS6031F1_FWD_R_F_SLOPE_TC12_ADDRESS             (0x144)                                                 // Proportionality factor slope, S_F(TC) between TC1 and TC2
#define AS6031F1_FWD_R_F_SLOPE_TC23_ADDRESS             (0x145)                                                 // Proportionality factor slope, S_F(TC) between TC2 and TC3
#define AS6031F1_FWD_R_F_SLOPE_TC34_ADDRESS             (0x146)                                                 // Proportionality factor slope, S_F(TC) between TC3 and TC4
#define AS6031F1_FWD_R_F_OFFSET_TC2_ADDRESS             (0x147)                                                 // Proportionality factor, F(TC) at TC2
#define AS6031F1_FWD_R_F_OFFSET_TC3_ADDRESS             (0x148)                                                 // Proportionality factor, F(TC) at TC3
#define AS6031F1_FWD_R_F_OFFSET_TC4_ADDRESS             (0x149)                                                 // Proportionality factor, F(TC) at TC4
// Firmware variables and parameters
#define AS6031F1_FWD_SOUND_VEL_MAX_ADDRESS              (0x14A)                                                 // Maximum of speed of sound in m/s
#define AS6031F1_FWD_1_BY_A_ADDRESS                     (0x14B)                                                 // Medium constant, used for T calculation on basis of the speed of sound
#define AS6031F1_FWD_CONST_C_ADDRESS                    (0x14C)                                                 // Medium constant, used for T calculation on basis of the speed of sound
#define AS6031F1_FWD_THETA_MAX_ADDRESS                  (0x14D)                                                 // B3/B2/B1: Temperature at maximum speed of sound in °C
#define AS6031F1_FWD_LONG_TERM_ERROR_ADDRESS            (0x14E)                                                 // Number of low AM measurements before hardware failure / no-water checks are done
#define AS6031F1_FWD_FHL_USER_ADDRESS                   (0x14F)                                                 // B1/B0: trusted FHL ratio or B0: absolute trusted FHL
#define AS6031F1_FWD_TOF_SUM_DELTA_ADDRESS              (0x150)                                                 // FHL method 3: Nominal time difference (raw TDC units) in SUMTOF between operating and trusted FHL
#define AS6031F1_FWD_TOFSUM_VAR_LIM_ADDRESS             (0x151)                                                 // Error limit for deviation of SUMTOF from former average (raw TDC units)
#define AS6031F1_FWD_HSC_DEV_ADDRESS                    (0x152)                                                 // Firmware data memory with maximum permissible deviation in the HS clock from 4 LS clock periods (250 or 125 ns) * 2^16
#define AS6031F1_FWD_ERR_INTERRUPT_ADDRESS              (0x153)                                                 // Define error flag positions that issue an interrupt. . Same bits as RAM_R_FW_ERR_FLAGS1
#define AS6031F1_FWD_AM_DIFF_LIM_ADDRESS                (0x154)                                                 // Error limit for deviation between currently measured amplitude UP and DOWN in mV
#define AS6031F1_FWD_R_AM_MIN_ADDRESS                   (0x155)                                                 // Minimum allowed amplitude in mV
#define AS6031F1_FWD_PW_NOM_ADDRESS                     (0x156)                                                 // Nominal pulse width ratio
#define AS6031F1_FWD_PW_DEV_ADDRESS                     (0x157)                                                 // Error limit for deviation between currently measured UP and DOWN pulse width
#define AS6031F1_FWD_CORR_OFFSET_ADDRESS                (0x158)                                                 // Offset correction in case of negative PWL coefficients
#define AS6031F1_FWD_TOF_RATE_FACTOR_ADDRESS            (0x159)                                                 // Factor for TOF rate scaling in zero flow case
#define AS6031F1_FWD_FLOW_AVG_FACTOR_ADDRESS            (0x15A)                                                 // 2^N number of flow values for averaging
#define AS6031F1_FWD_R_PULSE_PER_LITER_ADDRESS          (0x15B)                                                 // Pulse interface: Number of pulses per liter
#define AS6031F1_FWD_R_PULSE_MAX_FLOW_ADDRESS           (0x15C)                                                 // Pulse interface & maxflow error limit: maximum permissible flow in l/h.
#define AS6031F1_FWD_NEG_FLOW_LIMIT_ADDRESS             (0x15D)                                                 // Cut-off limit for negative flow in l/h
#define AS6031F1_FWD_R_TOF_DIFF_LIMIT_ADDRESS           (0x15E)                                                 // Minimum limit for DIFTOF values in raw TDC units
#define AS6031F1_FWD_ZERO_FLOW_LIMIT_ADDRESS            (0x15F)                                                 // Zero flow limit in l/h
#define AS6031F1_FWD_CAL_PTR_OFFSETR_ADDRESS            (0x160)                                                 // Reference branch offset resistance in internal reference in Ω
#define AS6031F1_FWD_EXT_REF_VAL_ADDRESS                (0x161)                                                 // Value of reference resistor Rref in Ω
#define AS6031F1_FWD_PT_INT_SLOPE_ADDRESS               (0x162)                                                 // Internal sensor resistance slope in (K/Ω)*Rref
#define AS6031F1_FWD_PT_INT_NOM_ADDRESS                 (0x163)                                                 // Internal sensor nominal resistance
#define AS6031F1_FWD_PTC_RATIO_INV_ADDRESS              (0x164)                                                 // Nominal ratio of reference resistor to PT cold sensor resistance at 0°C
#define AS6031F1_FWD_PTH_RATIO_INV_ADDRESS              (0x165)                                                 // Nominal ratio of reference resistor to PT hot sensor resistance at 0 °C
#define AS6031F1_FWD_HSC_CLOCK_ADDRESS                  (0x166)                                                 // HSC clock in Hz, used as reference in the clock calibration
#define AS6031F1_FWD_MH_RLS_DLY_ADDRESS                 (0x167)                                                 // Nominal value for release delay
#define AS6031F1_FWD_PH_S_THRESHOLD_ADDRESS             (0x168)                                                 // Absolute value of phase-shift threshold value
#define AS6031F1_FWD_MH_RLS_DLY_LIM_ADDRESS             (0x169)                                                 // Multihit release delay limits (min B1, B0. & max B3, B2.)
// Firmware configuration
#define AS6031F1_FWD_FW_CONFIG_ADDRESS                  (0x16A)                                                 // ScioSense firmware configuration register
#define AS6031F1_FWD_FW_RLS_ADDRESS                     (0x16B)                                                 // Boot loader release
// Configuration data, bootloader, release code
#define AS6031F1_FWD_R_CD_ADDRESS                       (0x16C)                                                 // Watchdog disable code
#define AS6031F1_FWD_IFC_CTRL_ADDRESS                   (0x16D)                                                 // Configuration data for CR_IFC_CTRL
#define AS6031F1_FWD_GP_CTRL_ADDRESS                    (0x16E)                                                 // Configuration data for CR_GP_CTRL
#define AS6031F1_FWD_USM_OPT_ADDRESS                    (0x16F)                                                 // Configuration data for CR_USM_OPT
#define AS6031F1_FWD_IEH_ADDRESS                        (0x170)                                                 // Configuration data for CR_IEH
#define AS6031F1_FWD_CPM_ADDRESS                        (0x171)                                                 // Configuration data for CR_CPM
#define AS6031F1_FWD_MRG_TS_ADDRESS                     (0x172)                                                 // Configuration data for CR_MRG_TS
#define AS6031F1_FWD_TPM_ADDRESS                        (0x173)                                                 // Configuration data for CR_TPM
#define AS6031F1_FWD_USM_PRC_ADDRESS                    (0x174)                                                 // Configuration data for CR_USM_PRC
#define AS6031F1_FWD_USM_FRC_ADDRESS                    (0x175)                                                 // Configuration data for CR_USM_FRC
#define AS6031F1_FWD_USM_TOF_ADDRESS                    (0x176)                                                 // Configuration data for CR_USM_TOF
#define AS6031F1_FWD_USM_AM_ADDRESS                     (0x177)                                                 // Configuration data for CR_USM_AM
#define AS6031F1_FWD_TRIM1_ADDRESS                      (0x178)                                                 // Configuration data for CR_TRIM1
#define AS6031F1_FWD_TRIM2_ADDRESS                      (0x179)                                                 // Configuration data for CR_TRIM2
#define AS6031F1_FWD_TRIM3_ADDRESS                      (0x17A)                                                 // Configuration data for CR_TRIM3
// Checksums
#define AS6031F1_FWD_R_FWD1_CS_ADDRESS                  (0x17C)                                                 // Checksum firmware data 1
#define AS6031F1_FWD_R_FWD2_CS_ADDRESS                  (0x17D)                                                 // Checksum firmware data 2
#define AS6031F1_FWD_R_FWU_CS_ADDRESS                   (0x17E)                                                 // Checksum firmware code user
#define AS6031F1_FWD_R_FWA_CS_ADDRESS                   (0x17F)                                                 // Checksum firmware code ScioSense
// Firmware variables in FDB_TM_PTC_4W_AC_M1
#define AS6031F1_FWD_R_FLOW_VOLUME_INT_ADDRESS          (0x100)                                                 // Integer part of negative flow volume in cubic meters
#define AS6031F1_FWD_R_FLOW_VOLUME_FRACTION_ADDRESS     (0x101)                                                 // Fractional part of negative flow volume in cubic meters
#define AS6031F1_FWD_ERROR_COUNT_21_ADDRESS             (0x105)                                                 // Temporary storage of error counts 2 (B3, B2) and 1 (B1, B0)
#define AS6031F1_FWD_ERROR_COUNT_43_ADDRESS             (0x106)                                                 // Temporary storage of error counts 4 - each error (B3, B2) and 3 - hardware errors (B1, B0)
#define AS6031F1_FWD_R_CD_ADDRESS                       (0x16C)                                                 // Watchdog disable code

/*****************************  Bit definitions  ******************************/
// Bit definition of FWD_FW_CONFIG register
#define AS6031F1_PWL_ADDR_Pos                           (0U)                                                    // Start address of PWL coefficients table in FWD
#define AS6031F1_PWL_ADDR_Msk                           (0xFFUL << AS6031F1_PWL_ADDR_Pos)                       // 0x00000001
#define AS6031F1_PWL_EXP_Pos                            (8U)                                                    // Exponent of scaling factor for PWL coefficients
#define AS6031F1_PWL_EXP_Msk                            (0x3FUL << AS6031F1_PWL_EXP_Pos)                        // 0x00000100
#define AS6031F1_BNR_FWCONF_PWL_Pos                     (15U)                                                   // Enable PWL calibration
#define AS6031F1_BNR_FWCONF_PWL_Msk                     (0x01UL << AS6031F1_BNR_FWCONF_PWL_Pos)                 // 0x00008000
#define AS6031F1_BNR_FWCONF_2MAX_NOZERO_Pos             (16U)                                                   // Behaviour when exceeding 2x maximum flow
#define AS6031F1_BNR_FWCONF_2MAX_NOZERO_Msk             (0x01UL << AS6031F1_BNR_FWCONF_2MAX_NOZERO_Pos)         // 0x00010000
#define AS6031F1_BNR_FWCONF_FHL_ZEROFLOW_Pos            (17U)                                                   // Enable zero flow state independent of FHL regulation
#define AS6031F1_BNR_FWCONF_FHL_ZEROFLOW_Msk            (0x01UL << AS6031F1_BNR_FWCONF_FHL_ZEROFLOW_Pos)        // 0x00020000
#define AS6031F1_BNR_FWCONF_FILTER_Pos                  (18U)                                                   // Enable IIR filter for HSC factor and AM values
#define AS6031F1_BNR_FWCONF_FILTER_Msk                  (0x01UL << AS6031F1_BNR_FWCONF_FILTER_Pos)              // 0x00040000
#define AS6031F1_BNR_FWCONF_NOENF_RECALL_Pos            (19U)                                                   // Don't enforce recall setting
#define AS6031F1_BNR_FWCONF_NOENF_RECALL_Msk            (0x01UL << AS6031F1_BNR_FWCONF_NOENF_RECALL_Pos)        // 0x00080000
#define AS6031F1_BNR_FWCONF_IND_RECALL0_Pos             (20U)                                                   // To be changed to 1 by FW after initialization due to recall
#define AS6031F1_BNR_FWCONF_IND_RECALL0_Msk             (0x01UL << AS6031F1_BNR_FWCONF_IND_RECALL0_Pos)         // 0x00100000
#define AS6031F1_BNR_FWCONF_NO_PI_ERR_Pos               (21U)                                                   // Never signal error on pulse interface
#define AS6031F1_BNR_FWCONF_NO_PI_ERR_Msk               (0x01UL << AS6031F1_BNR_FWCONF_NO_PI_ERR_Pos)           // 0x00200000
#define AS6031F1_BNR_FWCONF_PI_ERROR_Pos                (22U)                                                   // Signal no-water/hardware error as error on pulse interface
#define AS6031F1_BNR_FWCONF_PI_ERROR_Msk                (0x01UL << AS6031F1_BNR_FWCONF_PI_ERROR_Pos)            // 0x00400000
#define AS6031F1_BNR_FWCONF_ERR_Pos                     (23U)                                                   // Activate average error counters
#define AS6031F1_BNR_FWCONF_ERR_Msk                     (0x01UL << AS6031F1_BNR_FWCONF_ERR_Pos)                 // 0x00800000
#define AS6031F1_BNR_FWCONF_FHL_Pos                     (24U)                                                   // Configuration of FHL regulation methods
#define AS6031F1_BNR_FWCONF_FHL_Msk                     (0x03UL << AS6031F1_BNR_FWCONF_FHL_Pos)                 // 0x01000000
#define AS6031F1_BNR_FWCONF_FHL_RATIO_Pos               (26U)                                                   // Configuration for FHL regulation option B
#define AS6031F1_BNR_FWCONF_FHL_RATIO_Msk               (0x01UL << AS6031F1_BNR_FWCONF_FHL_RATIO_Pos)           // 0x04000000
#define AS6031F1_BNR_FWCONF_VLIM_Pos                    (27U)                                                   // Control of speed of sound limits
#define AS6031F1_BNR_FWCONF_VLIM_Msk                    (0x01UL << AS6031F1_BNR_FWCONF_VLIM_Pos)                // 0x08000000
#define AS6031F1_BNR_FWCONF_IND_RECALL_Pos              (28U)                                                   // Activate recall initialisation, to be changed to 0 after initialization due to recall
#define AS6031F1_BNR_FWCONF_IND_RECALL_Msk              (0x01UL << AS6031F1_BNR_FWCONF_IND_RECALL_Pos)          // 0x10000000
#define AS6031F1_BNR_FWCONF_VOL_Pos                     (29U)                                                   // Flow volume storage protection
#define AS6031F1_BNR_FWCONF_VOL_Msk                     (0x01UL << AS6031F1_BNR_FWCONF_VOL_Pos)                 // 0x20000000
#define AS6031F1_BNR_FWCONF_TSENS_Pos                   (30U)                                                   // Temperature value to use for calibration coefficients
#define AS6031F1_BNR_FWCONF_TSENS_Msk                   (0x01UL << AS6031F1_BNR_FWCONF_TSENS_Pos)               // 0x40000000
#define AS6031F1_BNR_FWCONF_ACAM_Pos                    (31U)                                                   // Disable ScioSense calibration method
#define AS6031F1_BNR_FWCONF_ACAM_Msk                    (0x01UL << AS6031F1_BNR_FWCONF_ACAM_Pos)                // 0x80000000

// Bit definition of RAM_R_FW_STATUS register
#define AS6031F1_BNR_HCC_UPD_Pos                        (0U)                                                    // Copy of current state in SRR_FEP_STF, High speed clock calibration updated
#define AS6031F1_BNR_HCC_UPD_Msk                        (0x01UL << AS6031F1_BNR_HCC_UPD_Pos)                    // 0x00000001
#define AS6031F1_BNR_TM_UPD_Pos                         (1U)                                                    // Copy of current state in SRR_FEP_STF, Temperature measurement updated
#define AS6031F1_BNR_TM_UPD_Msk                         (0x01UL << AS6031F1_BNR_TM_UPD_Pos)                     // 0x00000002
#define AS6031F1_BNR_FLOW_FILT_INIT_DONE_Pos            (3U)                                                    // Flow filter initialized
#define AS6031F1_BNR_FLOW_FILT_INIT_DONE_Msk            (0x01UL << AS6031F1_BNR_FLOW_FILT_INIT_DONE_Pos)        // 0x00000008
#define AS6031F1_BNR_US_U_UPD_Pos                       (4U)                                                    // Copy of current state in SRR_FEP_STF, TOF_UP measurements available
#define AS6031F1_BNR_US_U_UPD_Msk                       (0x01UL << AS6031F1_BNR_US_U_UPD_Pos)                   // 0x00000010
#define AS6031F1_BNR_US_D_UPD_Pos                       (5U)                                                    // Copy of current state in SRR_FEP_STF, TOF_DOWN measurements available
#define AS6031F1_BNR_US_D_UPD_Msk                       (0x01UL << AS6031F1_BNR_US_D_UPD_Pos)                   // 0x00000020
#define AS6031F1_BNR_US_TOF_UPD_Pos                     (6U)                                                    // Copy of current state in SRR_FEP_STF, TOF measurement updated
#define AS6031F1_BNR_US_TOF_UPD_Msk                     (0x01UL << AS6031F1_BNR_US_TOF_UPD_Pos)                 // 0x00000040
#define AS6031F1_BNR_TOF_EDGE_Pos                       (7U)                                                    // Copy of current state in SRR_FEP_STF, TOF edge sign
#define AS6031F1_BNR_TOF_EDGE_Msk                       (0x01UL << AS6031F1_BNR_TOF_EDGE_Pos)                   // 0x00000080
#define AS6031F1_BNR_AM_UPD_Pos                         (8U)                                                    // Copy of current state in SRR_FEP_STF, Amplitude measurement updated
#define AS6031F1_BNR_AM_UPD_Msk                         (0x01UL << AS6031F1_BNR_AM_UPD_Pos)                     // 0x00000100
#define AS6031F1_BNR_AMC_UPD_Pos                        (9U)                                                    // Copy of current state in SRR_FEP_STF, Amplitude calibration updated
#define AS6031F1_BNR_AMC_UPD_Msk                        (0x01UL << AS6031F1_BNR_AMC_UPD_Pos)                    // 0x00000200
#define AS6031F1_BNR_MEAS_FAILURE_ALERT_Pos             (10U)                                                   // Measurement failure
#define AS6031F1_BNR_MEAS_FAILURE_ALERT_Msk             (0x01UL << AS6031F1_BNR_MEAS_FAILURE_ALERT_Pos)         // 0x00000400
#define AS6031F1_BNR_FILTER_INIT_DONE_Pos               (11U)                                                   // TOF filters initialized
#define AS6031F1_BNR_FILTER_INIT_DONE_Msk               (0x01UL << AS6031F1_BNR_FILTER_INIT_DONE_Pos)           // 0x00000800
#define AS6031F1_BNR_CHKSUM_DUE_AUX_Pos                 (12U)                                                   // This bit supports checksum building indication
#define AS6031F1_BNR_CHKSUM_DUE_AUX_Msk                 (0x01UL << AS6031F1_BNR_CHKSUM_DUE_AUX_Pos)             // 0x00001000
#define AS6031F1_BNR_CHKSUM_DUE_Pos                     (13U)                                                   // This bit indicates that checksum building is due after the next identified recall
#define AS6031F1_BNR_CHKSUM_DUE_Msk                     (0x01UL << AS6031F1_BNR_CHKSUM_DUE_Pos)                 // 0x00002000
#define AS6031F1_BNR_AVG_TOF_FOR_FLOW_Pos               (14U)                                                   // Flow values for long term average reached
#define AS6031F1_BNR_AVG_TOF_FOR_FLOW_Msk               (0x01UL << AS6031F1_BNR_AVG_TOF_FOR_FLOW_Pos)           // 0x00004000
#define AS6031F1_BNR_TOFSUM_DIV_MODE_Pos                (15U)                                                   // TOF sum division mode
#define AS6031F1_BNR_TOFSUM_DIV_MODE_Msk                (0x01UL << AS6031F1_BNR_TOFSUM_DIV_MODE_Pos)            // 0x00008000
#define AS6031F1_BNR_HSC_SCALE_EN_Pos                   (16U)                                                   // Set HSC cal. according to configuration
#define AS6031F1_BNR_HSC_SCALE_EN_Msk                   (0x01UL << AS6031F1_BNR_HSC_SCALE_EN_Pos)               // 0x00010000
#define AS6031F1_BNR_PI_UPD_REQ_Pos                     (17U)                                                   // Pulse interface update
#define AS6031F1_BNR_PI_UPD_REQ_Msk                     (0x01UL << AS6031F1_BNR_PI_UPD_REQ_Pos)                 // 0x00020000
#define AS6031F1_BNR_NON_ZERO_FLOW_Pos                  (18U)                                                   // No zero flow
#define AS6031F1_BNR_NON_ZERO_FLOW_Msk                  (0x01UL << AS6031F1_BNR_NON_ZERO_FLOW_Pos)              // 0x00040000
#define AS6031F1_BNR_THETA_OUT_OF_RANGE_Pos             (19U)                                                   // Temperature for calibration outside of calibration table
#define AS6031F1_BNR_THETA_OUT_OF_RANGE_Msk             (0x01UL << AS6031F1_BNR_THETA_OUT_OF_RANGE_Pos)         // 0x00080000
#define AS6031F1_BNR_FWI_DONE_Pos                       (20U)                                                   // Firmware initialization done
#define AS6031F1_BNR_FWI_DONE_Msk                       (0x01UL << AS6031F1_BNR_FWI_DONE_Pos)                   // 0x00100000
#define AS6031F1_BNR_I2C_ABORT_Pos                      (21U)                                                   // Some I2C was aborted with NACK
#define AS6031F1_BNR_I2C_ABORT_Msk                      (0x01UL << AS6031F1_BNR_I2C_ABORT_Pos)                  // 0x00200000
#define AS6031F1_BNR_TEMP_REFRSH_Pos                    (22U)                                                   // Refresh of registers after recall needed
#define AS6031F1_BNR_TEMP_REFRSH_Msk                    (0x01UL << AS6031F1_BNR_TEMP_REFRSH_Pos)                // 0x00400000
#define AS6031F1_BNR_PI_ERR_1ST_DIR_Pos                 (23U)                                                   // Temporary storage of pulse interface direction when starting error signal
#define AS6031F1_BNR_PI_ERR_1ST_DIR_Msk                 (0x01UL << AS6031F1_BNR_PI_ERR_1ST_DIR_Pos)             // 0x00800000
#define AS6031F1_BNR_TEST_MODE_ADJ_Pos                  (24U)                                                   // Indicate active PWR adjustment
#define AS6031F1_BNR_TEST_MODE_ADJ_Msk                  (0x01UL << AS6031F1_BNR_TEST_MODE_ADJ_Pos)              // 0x01000000
#define AS6031F1_BNR_TEST_MODE_EP_Pos                   (25U)                                                   // Indicate no-water / hardware error test mode
#define AS6031F1_BNR_TEST_MODE_EP_Msk                   (0x01UL << AS6031F1_BNR_TEST_MODE_EP_Pos)               // 0x02000000
#define AS6031F1_BNR_EN_FHL_MONITORING_Pos              (26U)                                                   // Enable FHL regulation (enforced at init or recall)
#define AS6031F1_BNR_EN_FHL_MONITORING_Msk              (0x01UL << AS6031F1_BNR_EN_FHL_MONITORING_Pos)          // 0x04000000
#define AS6031F1_BNR_TOF_RATE_REDUCED_Pos               (29U)                                                   // TOF rate configuration
#define AS6031F1_BNR_TOF_RATE_REDUCED_Msk               (0x01UL << AS6031F1_BNR_TOF_RATE_REDUCED_Pos)           // 0x20000000
#define AS6031F1_BNR_TOF_DIFF_NEGATIVE_Pos              (30U)                                                   //  Current DIFTOF sign after zero-flow correction
#define AS6031F1_BNR_TOF_DIFF_NEGATIVE_Msk              (0x01UL << AS6031F1_BNR_TOF_DIFF_NEGATIVE_Pos)          // 0x40000000
#define AS6031F1_BNR_TEST_MODE_FHL_Pos                  (31U)                                                   // Indicate active FHL regulation
#define AS6031F1_BNR_TEST_MODE_FHL_Msk                  (0x01UL << AS6031F1_BNR_TEST_MODE_FHL_Pos)              // 0x80000000

// Bit definition of RAM_R_FW_ERR_FLAGS register
#define AS6031F1_BNR_PH_S_U_JUMP_PH_LEFT_Pos            (0U)                                                    // Jump in the left direction for the UP hits
#define AS6031F1_BNR_PH_S_U_JUMP_PH_LEFT_Msk            (0x01UL << AS6031F1_BNR_PH_S_U_JUMP_PH_LEFT_Pos)        // 0x00000001
#define AS6031F1_BNR_PH_S_U_JUMP_PH_RIGHT_Pos           (1U)                                                    // Jump in the right direction for the UP hits
#define AS6031F1_BNR_PH_S_U_JUMP_PH_RIGHT_Msk           (0x01UL << AS6031F1_BNR_PH_S_U_JUMP_PH_RIGHT_Pos)       // 0x00000002
#define AS6031F1_BNR_PH_S_U_JUMP_ONE_PH_Pos             (2U)                                                    // Jump of one phase for the UP hits
#define AS6031F1_BNR_PH_S_U_JUMP_ONE_PH_Msk             (0x01UL << AS6031F1_BNR_PH_S_U_JUMP_ONE_PH_Pos)         // 0x00000004
#define AS6031F1_BNR_PH_S_U_JUMP_TWO_PH_Pos             (3U)                                                    // Jump of two phases for the UP hits
#define AS6031F1_BNR_PH_S_U_JUMP_TWO_PH_Msk             (0x01UL << AS6031F1_BNR_PH_S_U_JUMP_TWO_PH_Pos)         // 0x00000008
#define AS6031F1_BNR_PH_S_D_JUMP_PH_LEFT_Pos            (4U)                                                    // Jump in the left direction for the DOWN hits
#define AS6031F1_BNR_PH_S_D_JUMP_PH_LEFT_Msk            (0x01UL << AS6031F1_BNR_PH_S_D_JUMP_PH_LEFT_Pos)        // 0x00000010
#define AS6031F1_BNR_PH_S_D_JUMP_PH_RIGHT_Pos           (5U)                                                    // Jump in the right direction for the DOWN hits
#define AS6031F1_BNR_PH_S_D_JUMP_PH_RIGHT_Msk           (0x01UL << AS6031F1_BNR_PH_S_D_JUMP_PH_RIGHT_Pos)       // 0x00000020
#define AS6031F1_BNR_PH_S_D_JUMP_ONE_PH_Pos             (6U)                                                    // Jump of one phase for the DOWN hits
#define AS6031F1_BNR_PH_S_D_JUMP_ONE_PH_Msk             (0x01UL << AS6031F1_BNR_PH_S_D_JUMP_ONE_PH_Pos)         // 0x00000040
#define AS6031F1_BNR_PH_S_D_JUMP_TWO_PH_Pos             (7U)                                                    // Jump of two phases for the DOWN hits
#define AS6031F1_BNR_PH_S_D_JUMP_TWO_PH_Msk             (0x01UL << AS6031F1_BNR_PH_S_D_JUMP_TWO_PH_Pos)         // 0x00000080
#define AS6031F1_BNR_PH_S_U_TOF01_CONS_Pos              (14U)                                                   // UP_TOF 0&1 inconsistency flag
#define AS6031F1_BNR_PH_S_U_TOF01_CONS_Msk              (0x01UL << AS6031F1_BNR_PH_S_U_TOF01_CONS_Pos)          // 0x00004000
#define AS6031F1_BNR_PH_S_D_TOF01_CONS_Pos              (15U)                                                   // DOWN_TOF 0&1 inconsistency flag
#define AS6031F1_BNR_PH_S_D_TOF01_CONS_Msk              (0x01UL << AS6031F1_BNR_PH_S_D_TOF01_CONS_Pos)          // 0x00008000
#define AS6031F1_BNR_PH_S_U_TOF03_CONS_Pos              (16U)                                                   // UP_TOF 0&3 inconsistency flag
#define AS6031F1_BNR_PH_S_U_TOF03_CONS_Msk              (0x01UL << AS6031F1_BNR_PH_S_U_TOF03_CONS_Pos)          // 0x00010000
#define AS6031F1_BNR_PH_S_D_TOF03_CONS_Pos              (17U)                                                   // DOWN_TOF 0&3 inconsistency flag
#define AS6031F1_BNR_PH_S_D_TOF03_CONS_Msk              (0x01UL << AS6031F1_BNR_PH_S_D_TOF03_CONS_Pos)          // 0x00020000
#define AS6031F1_BNR_PH_S_CONS_ERR_Pos                  (22U)                                                   // Flag indicating possible inconsistency between hits TOF_0 and TOF_1 or TOF_0 and TOF_3.
#define AS6031F1_BNR_PH_S_CONS_ERR_Msk                  (0x01UL << AS6031F1_BNR_PH_S_CONS_ERR_Pos)              // 0x00400000
#define AS6031F1_BNR_PH_S_DLY_LIM_MIN_EXC_Pos           (23U)                                                   // Flag indicating that the release delay window MIN limit is exceeded
#define AS6031F1_BNR_PH_S_DLY_LIM_MIN_EXC_Msk           (0x01UL << AS6031F1_BNR_PH_S_DLY_LIM_MIN_EXC_Pos)       // 0x00800000
#define AS6031F1_BNR_PH_S_DLY_LIM_MAX_EXC_Pos           (24U)                                                   // Flag indicating that the release delay window MAX limit is exceeded
#define AS6031F1_BNR_PH_S_DLY_LIM_MAX_EXC_Msk           (0x01UL << AS6031F1_BNR_PH_S_DLY_LIM_MAX_EXC_Pos)       // 0x01000000
#define AS6031F1_BNR_PH_S_CONF_WRG_Pos                  (25U)                                                   // Flag indicating wrong configuration; stops phase shift routines execution if set
#define AS6031F1_BNR_PH_S_CONF_WRG_Msk                  (0x01UL << AS6031F1_BNR_PH_S_CONF_WRG_Pos)              // 0x02000000
#define AS6031F1_BNR_PH_S_VALID_WRG_Pos                 (26U)                                                   // Flag indicating a validation warning
#define AS6031F1_BNR_PH_S_VALID_WRG_Msk                 (0x01UL << AS6031F1_BNR_PH_S_VALID_WRG_Pos)             // 0x04000000
#define AS6031F1_BNR_PH_S_JUMP_DET_ERR_Pos              (27U)                                                   // Flag indicating jump detection error (eg. both left and right jumps detected)
#define AS6031F1_BNR_PH_S_JUMP_DET_ERR_Msk              (0x01UL << AS6031F1_BNR_PH_S_JUMP_DET_ERR_Pos)          // 0x08000000
#define AS6031F1_BNR_PH_S_DONE_Pos                      (30U)                                                   // Flag indicating that the phase-shift routines were finished
#define AS6031F1_BNR_PH_S_DONE_Msk                      (0x01UL << AS6031F1_BNR_PH_S_DONE_Pos)                  // 0x40000000
#define AS6031F1_BNR_PH_S_PARAMS_INITIALIZED_Pos        (31U)                                                   // Flag indicating that the parameters were initialized (only used in case of NO flow firmware inside the chip)
#define AS6031F1_BNR_PH_S_PARAMS_INITIALIZED_Msk        (0x01UL << AS6031F1_BNR_PH_S_PARAMS_INITIALIZED_Pos)    // 0x80000000

// Bit definition of  register
#define AS6031F1_BNR_HS_CALIB_FAIL_Pos                  (0U)                                                    // HS Clock deviation not within limit
#define AS6031F1_BNR_HS_CALIB_FAIL_Msk                  (0x01UL << AS6031F1_BNR_HS_CALIB_FAIL_Pos)              // 0x00000001
#define AS6031F1_BNR_AMP_DIFF_TOO_HIGH_Pos              (1U)                                                    // Check up / down amplitude difference
#define AS6031F1_BNR_AMP_DIFF_TOO_HIGH_Msk              (0x01UL << AS6031F1_BNR_AMP_DIFF_TOO_HIGH_Pos)          // 0x00000002
#define AS6031F1_BNR_AMP_VAL_TOO_LOW_Pos                (2U)                                                    // Measured amplitude up or down is below minimum
#define AS6031F1_BNR_AMP_VAL_TOO_LOW_Msk                (0x01UL << AS6031F1_BNR_AMP_VAL_TOO_LOW_Pos)            // 0x00000004
#define AS6031F1_BNR_PW_DIFF_NOT_OK_Pos                 (3U)                                                    // Check up and down PWR difference
#define AS6031F1_BNR_PW_DIFF_NOT_OK_Msk                 (0x01UL << AS6031F1_BNR_PW_DIFF_NOT_OK_Pos)             // 0x00000008
#define AS6031F1_BNR_SUMTOF_DEV_Pos                     (4U)                                                    // Check deviation of new SUMTOF from average
#define AS6031F1_BNR_SUMTOF_DEV_Msk                     (0x01UL << AS6031F1_BNR_SUMTOF_DEV_Pos)                 // 0x00000010
#define AS6031F1_BNR_FHL_NOT_OK_Pos                     (5U)                                                    // Consistency current FHL
#define AS6031F1_BNR_FHL_NOT_OK_Msk                     (0x01UL << AS6031F1_BNR_FHL_NOT_OK_Pos)                 // 0x00000020
#define AS6031F1_BNR_MEAS_NOT_OK_Pos                    (6U)                                                    // Measurement is considered wrong
#define AS6031F1_BNR_MEAS_NOT_OK_Msk                    (0x01UL << AS6031F1_BNR_MEAS_NOT_OK_Pos)                // 0x00000040
#define AS6031F1_BNR_FLOW_BT_2MAX_Pos                   (8U)                                                    // Current flow exceeds 2*maximum flow
#define AS6031F1_BNR_FLOW_BT_2MAX_Msk                   (0x01UL << AS6031F1_BNR_FLOW_BT_2MAX_Pos)               // 0x00000100
#define AS6031F1_BNR_FLOW_LT_NEGLIM_Pos                 (9U)                                                    // Flow is below negative limit
#define AS6031F1_BNR_FLOW_LT_NEGLIM_Msk                 (0x01UL << AS6031F1_BNR_FLOW_LT_NEGLIM_Pos)             // 0x00000200
#define AS6031F1_BNR_VOL_ERR_Pos                        (10U)                                                   // Stored flow volume had an unrecoverable erro
#define AS6031F1_BNR_VOL_ERR_Msk                        (0x01UL << AS6031F1_BNR_VOL_ERR_Pos)                    // 0x00000400
#define AS6031F1_BNR_PH_S_FW_VALID_WRG_Pos              (11U)                                                   // Validation warning from the phase-shift routines
#define AS6031F1_BNR_PH_S_FW_VALID_WRG_Msk              (0x01UL << AS6031F1_BNR_PH_S_FW_VALID_WRG_Pos)          // 0x00000800
#define AS6031F1_BNR_PH_S_FW_JUMP_DET_ERR_Pos           (12U)                                                   // "Jump detection error
#define AS6031F1_BNR_PH_S_FW_JUMP_DET_ERR_Msk           (0x01UL << AS6031F1_BNR_PH_S_FW_JUMP_DET_ERR_Pos)       // 0x00001000
#define AS6031F1_BNR_VEL_ERROR_Pos                      (13U)                                                   // Calculated velocity of sound is outside limits;
#define AS6031F1_BNR_VEL_ERROR_Msk                      (0x01UL << AS6031F1_BNR_VEL_ERROR_Pos)                  // 0x00002000
#define AS6031F1_BNR_BUBBLE_Pos                         (14U)                                                   // Bubble detected
#define AS6031F1_BNR_BUBBLE_Msk                         (0x01UL << AS6031F1_BNR_BUBBLE_Pos)                     // 0x00004000
#define AS6031F1_BNR_NO_WATER_Pos                       (15U)                                                   // No-water/hardware error detected
#define AS6031F1_BNR_NO_WATER_Msk                       (0x01UL << AS6031F1_BNR_NO_WATER_Pos)                   // 0x00008000
#define AS6031F1_BNR_TDC_TMO_FW_Pos                     (16U)                                                   // Error flag TDC timeout
#define AS6031F1_BNR_TDC_TMO_FW_Msk                     (0x01UL << AS6031F1_BNR_TDC_TMO_FW_Pos)                 // 0x00010000
#define AS6031F1_BNR_TOF_TMO_FW_Pos                     (17U)                                                   // Error flag TOF timeout
#define AS6031F1_BNR_TOF_TMO_FW_Msk                     (0x01UL << AS6031F1_BNR_TOF_TMO_FW_Pos)                 // 0x00020000
#define AS6031F1_BNR_AM_TMO_FW_Pos                      (18U)                                                   // Error flag amplitude measurement timeout
#define AS6031F1_BNR_AM_TMO_FW_Msk                      (0x01UL << AS6031F1_BNR_AM_TMO_FW_Pos)                  // 0x00040000
#define AS6031F1_BNR_TM_OC_ERR_FW_Pos                   (19U)                                                   // Error Flag Temperature measurement open circuit
#define AS6031F1_BNR_TM_OC_ERR_FW_Msk                   (0x01UL << AS6031F1_BNR_TM_OC_ERR_FW_Pos)               // 0x00080000
#define AS6031F1_BNR_TM_SC_ERR_FW_Pos                   (20U)                                                   // Copy of bit 4 of SRR_ERR_FLAG before clear
#define AS6031F1_BNR_TM_SC_ERR_FW_Msk                   (0x01UL << AS6031F1_BNR_TM_SC_ERR_FW_Pos)               // 0x00100000
#define AS6031F1_BNR_ZCC_ERR_Pos                        (21U)                                                   // Error Flag Zero Cross Calibration
#define AS6031F1_BNR_ZCC_ERR_Msk                        (0x01UL << AS6031F1_BNR_ZCC_ERR_Pos)                    // 0x00200000
#define AS6031F1_BNR_LBD_ERR_Pos                        (22U)                                                   // Error Flag Low Battery Detect
#define AS6031F1_BNR_LBD_ERR_Msk                        (0x01UL << AS6031F1_BNR_LBD_ERR_Pos)                    // 0x00400000
#define AS6031F1_BNR_USM_SQC_TMO_Pos                    (23U)                                                   // Error Flag Ultrasonic Sequence Timeout
#define AS6031F1_BNR_USM_SQC_TMO_Msk                    (0x01UL << AS6031F1_BNR_USM_SQC_TMO_Pos)                // 0x00800000
#define AS6031F1_BNR_TM_SQC_TMO_Pos                     (24U)                                                   // Error Flag Temperature Sequence Timeout
#define AS6031F1_BNR_TM_SQC_TMO_Msk                     (0x01UL << AS6031F1_BNR_TM_SQC_TMO_Pos)                 // 0x01000000
#define AS6031F1_BNR_TSQ_TMO_Pos                        (25U)                                                   // Error Flag Task Sequencer Timeout
#define AS6031F1_BNR_TSQ_TMO_Msk                        (0x01UL << AS6031F1_BNR_TSQ_TMO_Pos)                    // 0x02000000
#define AS6031F1_BNR_E2C_ACK_ERR_Pos                    (26U)                                                   // Error Flag EEPROM Acknowledge
#define AS6031F1_BNR_E2C_ACK_ERR_Msk                    (0x01UL << AS6031F1_BNR_E2C_ACK_ERR_Pos)                // 0x04000000
#define AS6031F1_BNR_CS_FWD1_ERR_Pos                    (28U)                                                   // Error Flag FWD1 Checksum
#define AS6031F1_BNR_CS_FWD1_ERR_Msk                    (0x01UL << AS6031F1_BNR_CS_FWD1_ERR_Pos)                // 0x10000000
#define AS6031F1_BNR_CS_FWD2_ERR_Pos                    (29U)                                                   // Error Flag FWD2 Checksum
#define AS6031F1_BNR_CS_FWD2_ERR_Msk                    (0x01UL << AS6031F1_BNR_CS_FWD2_ERR_Pos)                // 0x20000000
#define AS6031F1_BNR_CS_FWU_ERR_Pos                     (30U)                                                   // Error Flag FWU Checksum
#define AS6031F1_BNR_CS_FWU_ERR_Msk                     (0x01UL << AS6031F1_BNR_CS_FWU_ERR_Pos)                 // 0x40000000
#define AS6031F1_BNR_CS_FWA_ERR_Pos                     (31U)                                                   // Error Flag FWA Checksum
#define AS6031F1_BNR_CS_FWA_ERR_Msk                     (0x01UL << AS6031F1_BNR_CS_FWA_ERR_Pos)                 // 0x80000000

/**************  Byte definition for AS6031F1 algorithm output  ***************/
#define AS6031F1_VOLUME_INT_INDEX                       (0x00)                                                  // Index of the register corresponding to the integer part of the accumulated flow volume data of the AS6031F1 algorithm
#define AS6031F1_VOLUME_FRAC_INDEX                      (0x01)                                                  // Index of the register corresponding to the fractional part of the accumulated flow volume data of the AS6031F1 algorithm
#define AS6031F1_UNFILTERED_FLOW_LPH_INDEX              (0x02)                                                  // Index of the register corresponding to the unfiltered instant flow data of the AS6031F1 algorithm
#define AS6031F1_FILTERED_FLOW_LPH_INDEX                (0x03)                                                  // Index of the register corresponding to the filtered instant flow data of the AS6031F1 algorithm
#define AS6031F1_TEMPERATURE_INDEX                      (0x04)                                                  // Index of the register corresponding to the temperature data of the AS6031F1 algorithm
#define AS6031F1_SOUND_VEL_INDEX                        (0x05)                                                  // Index of the register corresponding to the speed of sound data of the AS6031F1 algorithm
#define AS6031F1_FLOW_SPEED_INDEX                       (0x06)                                                  // Index of the register corresponding to the speed of the fluid data of the AS6031F1 algorithm
#define AS6031F1_TOF_DIFF_INDEX                         (0x07)                                                  // Index of the register corresponding to the difference in ToF data of the AS6031F1 algorithm
#define AS6031F1_TOF_SUM_INDEX                          (0x08)                                                  // Index of the register corresponding to the sum of ToF data of the AS6031F1 algorithm
#define AS6031F1_ERROR_FLAGS_INDEX                      (0x27)                                                  // Index of the register corresponding to the error flags data of the AS6031F1 algorithm
