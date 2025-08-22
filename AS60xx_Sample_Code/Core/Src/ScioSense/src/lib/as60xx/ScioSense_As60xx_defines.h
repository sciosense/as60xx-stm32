/*
 * ScioSense_As60xx_defines.h
 *
 *  Created on: 14.11.2023
 *      Author: Matthias Hainz
 */

#ifndef INC_AS60XX_BIT_DEFINITION_H_
#define INC_AS60XX_BIT_DEFINITION_H_

#include <inttypes.h>

/******************************************************************************/
/*                                                                            */
/*                        UFC AS60xx                                          */
/*                                                                            */
/******************************************************************************/

#define AS60XX_REGISTER_SIZE                        uint32_t                                        /* Size of each of the configuration registers */
#define AS60XX_AMOUNT_CONFIGURATION_REGISTERS       (20)                                            /* Addresses from CR[0] up to CR[19] */
#define AS60XX_REGISTER_ADDRESSING_SIZE             uint16_t                                        /* Size of the addressing variable used to identify each register */
#define AS60XX_AMOUNT_FDB_REGISTERS                 (28)                                            /* Amount of registers on the Frontend Data Buffer */
#define AS60XX_AMOUNT_TOF_VALUES_REGISTERS          (10)                                            /* Amount of registers on the Frontend Data Buffer */
#define AS60XX_AMOUNT_STATUS_REGISTERS              (15)                                            /* Amount of status & result registers */
#define AS60XX_AMOUNT_ERROR_FLAGS                   (16)                                            /* Amount of error flags */

#define AS60XX_ZERO_CROSS_DETECTION_LSB_TO_MV       (0.88)                                          /* Conversion from the register value to mV for the zero cross detection level on registers 0x0DA and 0x0DB */
#define AS60XX_MAX_ZERO_CROSS_DETECTION_VALUE_MV    (200.0)                                         /* Maximum value in mV that the registers 0x0DA and 0x0DB can represent */
#define AS60XX_DELAY_WINDOW_LSB_TO_NS               (7.8125)                                        /* Conversion from the register value to nanoseconds for the delay window on registers 0x0D1 and 0x0D2 */
#define AS60XX_BOOTUP_COMM_RELEASE_TIME_MAX_MS      (94)                                            /* Maximum time before remote communication is released after power on */
#define AS60XX_CHARGE_PUMP_UPLOADING                (20)                                            /* Time needed to increase the voltage on the charge pump to the desired level */
#define AS60XX_SOFTWARE_RESET_TIME_MS               (3)                                             /* Mandatory time to wait after software reset in milliseconds */
#define AS60XX_FDB_US_PW_FRACTIONAL_LSB             (0.0078125)                                     /* Value of 1 LSB for the Pulse Width measurement fractional part */
#define AS60XX_AMOUNT_POINTS_SPEED_SOUND_TABLE      (12)                                            /* Amount of points used in the speed of sound as function of temperature table */

/*************************  Register addresses AS60XX  ************************/
#define AS60XX_FDB_ADDRESS                          (0x80)                                          /* Register address where the Frontend Data Buffer starts */

#define AS60XX_CR_WD_DIS_ADDRESS                    (0xC0)                                          /* Watchdog Disable register */
#define AS60XX_CR_IFC_CTRL_ADDRESS                  (0xC1)                                          /* Interfaces Control register */
#define AS60XX_CR_GP_CTRL_ADDRESS                   (0xC2)                                          /* General Purpose Control */
#define AS60XX_CR_USM_OPT_ADDRESS                   (0xC3)                                          /* USM: Options register */
#define AS60XX_CR_IEH_ADDRESS                       (0xC4)                                          /* Interrupt & Error Handling register */
#define AS60XX_CR_CPM_ADDRESS                       (0xC5)                                          /* Clock & Power Management register */
#define AS60XX_CR_MRG_TS_ADDRESS                    (0xC6)                                          /* Measure Rate Generator & Task Sequencer register */
#define AS60XX_CR_TPM_ADDRESS                       (0xC7)                                          /* Temperature Measurement register */
#define AS60XX_CR_USM_PRC_ADDRESS                   (0xC8)                                          /* USM: Processing register */
#define AS60XX_CR_USM_FRC_ADDRESS                   (0xC9)                                          /* USM: Fire & Receive Control register */
#define AS60XX_CR_USM_TOF_ADDRESS                   (0xCA)                                          /* USM: Time of Flight register */
#define AS60XX_CR_USM_AM_ADDRESS                    (0xCB)                                          /* USM: Amplitude Measurement register */
#define AS60XX_CR_TRIM1_ADDRESS                     (0xCC)                                          /* Trim Parameter register */
#define AS60XX_CR_TRIM2_ADDRESS                     (0xCD)                                          /* Trim Parameter register */
#define AS60XX_CR_TRIM3_ADDRESS                     (0xCE)                                          /* Trim Parameter register */

#define AS60XX_SHR_TOF_RATE_ADDRESS                 (0xD0)                                          /* Time-of-Flight rate */
#define AS60XX_SHR_USM_RLS_DLY_U_ADDRESS            (0xD1)                                          /* Measurement Release Delay Up register */
#define AS60XX_SHR_USM_RLS_DLY_D_ADDRESS            (0xD2)                                          /* Measurement Release Delay Down register */
#define AS60XX_SHR_GPO_ADDRESS                      (0xD3)                                          /* General Purpose Out register */
#define AS60XX_SHR_PI_NPULSE_ADDRESS                (0xD4)                                          /* Pulse Interface Number of Pulses register */
#define AS60XX_SHR_PI_TPA_ADDRESS                   (0xD5)                                          /* Pulse Interface Time Pulse Distance register */
#define AS60XX_SHR_PI_IU_TIME_ADDRESS               (0xD6)                                          /* Pulse Interface, Internal Update Time Distance register */
#define AS60XX_SHR_PI_IU_NO_ADDRESS                 (0xD7)                                          /* Pulse Interface Number of internal Update register */
#define AS60XX_SHR_ZCD_LVL_ADDRESS                  (0xD9)                                          /* Zero cross detection, level register */
#define AS60XX_SHR_FHL_U_ADDRESS                    (0xDA)                                          /* Zero Cross Detection First Hit Level Up register */
#define AS60XX_SHR_FHL_D_ADDRESS                    (0xDB)                                          /* Zero Cross Detection First Hit Level Down register */
#define AS60XX_SHR_CPU_REQ_ADDRESS                  (0xDC)                                          /* CPU Requests register */
#define AS60XX_SHR_EXC_ADDRESS                      (0xDD)                                          /* Executables register */
#define AS60XX_SHR_RC_ADDRESS                       (0xDE)                                          /* Remote Control register */
#define AS60XX_SHR_RC_RLS_ADDRESS                   (0xDF)                                          /* Release Code for actions of SHR_RC register */

#define AS60XX_SRR_IRQ_FLAG_ADDRESS                 (0xE0)                                          /* Interrupt Flags register */
#define AS60XX_SRR_ERR_FLAG_ADDRESS                 (0xE1)                                          /* Error Flags register */
#define AS60XX_SRR_FEP_STF_ADDRESS                  (0xE2)                                          /* Frontend Processing Status Flags register */
#define AS60XX_SRR_GPI_ADDRESS                      (0xE3)                                          /* General Purpose In register */
#define AS60XX_SRR_HCC_VAL_ADDRESS                  (0xE4)                                          /* High-Speed Clock Calibration Value register */
#define AS60XX_SRR_VCC_VAL_ADDRESS                  (0xE5)                                          /* Measurement Value for VCC Voltage register */
#define AS60XX_SRR_TSV_HOUR_ADDRESS                 (0xE6)                                          /* Time Stamp Value: Hours register */
#define AS60XX_SRR_TSV_MIN_SEC_ADDRESS              (0xE7)                                          /* Time Stamp Value: Minutes & Seconds register */
#define AS60XX_SRR_TS_TIME_ADDRESS                  (0xE9)                                          /* Task Sequencer Time register */
#define AS60XX_SRR_MSC_STF_ADDRESS                  (0xEA)                                          /* Miscellaneous Status Flags register */
#define AS60XX_SRR_I2C_RD_ADDRESS                   (0xEB)                                          /* 2-wire Master Interface Read Data register */
#define AS60XX_SRR_FWU_RNG_ADDRESS                  (0xEC)                                          /* Range Firmware Code User register */
#define AS60XX_SRR_FWU_REV_ADDRESS                  (0xED)                                          /* Revision Firmware Code User register */
#define AS60XX_SRR_FWA_REV_ADDRESS                  (0xEE)                                          /* Revision Firmware Code ScioSense register */

/************  Bit definition for FDB in case of TOF measurement  *************/
#define AS60XX_FDB_US_TOF_SUM_OF_ALL_U_ADDRESS      (0x80)                                          /* Ultrasonic TOF Sum of All Value Up */
#define AS60XX_FDB_US_PW_U_ADDRESS                  (0x81)                                          /* Ultrasonic Pulse Width Ratio Up */
#define AS60XX_FDB_US_AM_U_ADDRESS                  (0x82)                                          /* Ultrasonic Amplitude Value Up */
#define AS60XX_FDB_US_AMC_VH_ADDRESS                (0x83)                                          /* Ultrasonic Amplitude Calibrate Value High */
#define AS60XX_FDB_US_TOF_SUM_OF_ALL_D_ADDRESS      (0x84)                                          /* Ultrasonic TOF Sum of All Value Down */
#define AS60XX_FDB_US_PW_D_ADDRESS                  (0x85)                                          /* Ultrasonic Pulse Width Ratio Down */
#define AS60XX_FDB_US_AM_D_ADDRESS                  (0x86)                                          /* Ultrasonic Amplitude Value Down */
#define AS60XX_FDB_US_AMC_VL_ADDRESS                (0x87)                                          /* Ultrasonic Amplitude Calibrate Value Low */
#define AS60XX_FDB_US_TOF_0_U_ADDRESS               (0x88)                                          /* Ultrasonic TOF Up: Value 0 */
#define AS60XX_FDB_US_TOF_1_U_ADDRESS               (0x89)                                          /* Ultrasonic TOF Up: Value 1 */
#define AS60XX_FDB_US_TOF_2_U_ADDRESS               (0x8A)                                          /* Ultrasonic TOF Up: Value 2 */
#define AS60XX_FDB_US_TOF_3_U_ADDRESS               (0x8B)                                          /* Ultrasonic TOF Up: Value 3 */
#define AS60XX_FDB_US_TOF_4_U_ADDRESS               (0x8C)                                          /* Ultrasonic TOF Up: Value 4 */
#define AS60XX_FDB_US_TOF_5_U_ADDRESS               (0x8D)                                          /* Ultrasonic TOF Up: Value 5 */
#define AS60XX_FDB_US_TOF_6_U_ADDRESS               (0x8E)                                          /* Ultrasonic TOF Up: Value 6 */
#define AS60XX_FDB_US_TOF_7_U_ADDRESS               (0x8F)                                          /* Ultrasonic TOF Up: Value 7 */
#define AS60XX_FDB_US_TOF_8_U_ADDRESS               (0x90)                                          /* Ultrasonic TOF Up: Value 8 */
#define AS60XX_FDB_US_TOF_9_U_ADDRESS               (0x91)                                          /* Ultrasonic TOF Up: Value 9 */
#define AS60XX_FDB_US_TOF_0_D_ADDRESS               (0x92)                                          /* Ultrasonic TOF Down: Value 0 */
#define AS60XX_FDB_US_TOF_1_D_ADDRESS               (0x93)                                          /* Ultrasonic TOF Down: Value 1 */
#define AS60XX_FDB_US_TOF_2_D_ADDRESS               (0x94)                                          /* Ultrasonic TOF Down: Value 2 */
#define AS60XX_FDB_US_TOF_3_D_ADDRESS               (0x95)                                          /* Ultrasonic TOF Down: Value 3 */
#define AS60XX_FDB_US_TOF_4_D_ADDRESS               (0x96)                                          /* Ultrasonic TOF Down: Value 4 */
#define AS60XX_FDB_US_TOF_5_D_ADDRESS               (0x97)                                          /* Ultrasonic TOF Down: Value 5 */
#define AS60XX_FDB_US_TOF_6_D_ADDRESS               (0x98)                                          /* Ultrasonic TOF Down: Value 6 */
#define AS60XX_FDB_US_TOF_7_D_ADDRESS               (0x99)                                          /* Ultrasonic TOF Down: Value 7 */
#define AS60XX_FDB_US_TOF_8_D_ADDRESS               (0x9A)                                          /* Ultrasonic TOF Down: Value 8 */
#define AS60XX_FDB_US_TOF_9_D_ADDRESS               (0x9B)                                          /* Ultrasonic TOF Down: Value 9 */

/********  Bit definition for FDB in case of Temperature measurement  *********/
#define AS60XX_FDB_TPM1_M1AB_RAB_G12_ADDRESS        (0x80)                                          /* Gain compensation Seq 1 */
#define AS60XX_FDB_TPM1_RAB_G12_ADDRESS             (0x81)                                          /* Reference port REF-AB Seq 1 */
#define AS60XX_FDB_TPM1_M1A_G12_ADDRESS             (0x82)                                          /* Temperature port M1-A Seq 1 */
#define AS60XX_FDB_TPM1_M2A_G12_ADDRESS             (0x83)                                          /* Temperature port M2-A Seq 1 */
#define AS60XX_FDB_TPM1_RA_G12_ADDRESS              (0x84)                                          /* RDSON compensation Seq 1 */
#define AS60XX_FDB_TPM1_MI_R_G12_ADDRESS            (0x85)                                          /* Internal temperature reference Seq 1 */
#define AS60XX_FDB_TPM1_MI_RM_G12_ADDRESS           (0x86)                                          /* Internal temperature compensation Seq 1 */
#define AS60XX_FDB_TPM1_MI_M_G12_ADDRESS            (0x87)                                          /* Internal temperature measurement Seq 1 */
#define AS60XX_FDB_TPM2_M1AB_RAB_G12_ADDRESS        (0x8E)                                          /* Gain compensation Seq 2 */
#define AS60XX_FDB_TPM2_RAB_G12_ADDRESS             (0x8F)                                          /* Reference port REF-AB Seq 2 */
#define AS60XX_FDB_TPM2_M1A_G12_ADDRESS             (0x90)                                          /* Temperature port M1-A Seq 2 */
#define AS60XX_FDB_TPM2_M2A_G12_ADDRESS             (0x91)                                          /* Temperature port M2-A Seq 2 */
#define AS60XX_FDB_TPM2_RA_G12_ADDRESS              (0x92)                                          /* RDSON compensation Seq 2 */
#define AS60XX_FDB_TPM2_MI_R_G12_ADDRESS            (0x93)                                          /* Internal temperature reference Seq 2 */
#define AS60XX_FDB_TPM2_MI_RM_G12_ADDRESS           (0x94)                                          /* Internal temperature compensation Seq 2 */
#define AS60XX_FDB_TPM2_MI_M_G12_ADDRESS            (0x95)                                          /* Internal temperature measurement Seq 2 */

/***********  Bit definition for Four Wire Temperature measurement  ***********/
#define AS60XX_FDB_T4W1_M1AB_RAB_G12_ADDRESS        (0x80)                                          /* Gain compensation Seq 1 */
#define AS60XX_FDB_T4W1_RAB_G12_ADDRESS             (0x81)                                          /* Reference port REF-AB Seq 1 */
#define AS60XX_FDB_T4W1_M1AB_G12_ADDRESS            (0x82)                                          /* Temperature port M1-AB Seq 1 */
#define AS60XX_FDB_T4W1_M2AB_G12_ADDRESS            (0x83)                                          /* Temperature port M2-AB Seq 1 */
#define AS60XX_FDB_T4W1_RA_G12_ADDRESS              (0x84)                                          /* Reference port REF A Seq 1 */
#define AS60XX_FDB_T4W1_RB_G12_ADDRESS              (0x85)                                          /* Reference port REF B Seq 1 */
#define AS60XX_FDB_T4W1_M1A_G12_ADDRESS             (0x86)                                          /* Temperature port M1-A Seq 1 */
#define AS60XX_FDB_T4W1_M1B_G12_ADDRESS             (0x87)                                          /* Temperature port M1-B Seq 1 */
#define AS60XX_FDB_T4W1_M1AB_G1_ADDRESS             (0x88)                                          /* Temperature port M1-AB Seq 1 */
#define AS60XX_FDB_T4W1_M1AB_G2_ADDRESS             (0x89)                                          /* Temperature port M1-AB Seq 1 */
#define AS60XX_FDB_T4W1_M2A_G12_ADDRESS             (0x8A)                                          /* Temperature port M2-A Seq 1 */
#define AS60XX_FDB_T4W1_M2B_G12_ADDRESS             (0x8B)                                          /* Temperature port M2-B Seq 1 */
#define AS60XX_FDB_TPM1_M2B_G1_ADDRESS              (0x8C)                                          /* Temperature port M2-AB Seq 1 */
#define AS60XX_FDB_TPM1_M2B_G2_ADDRESS              (0x8D)                                          /* Temperature port M2-AB Seq 1 */
#define AS60XX_FDB_T4W2_M1AB_RAB_G12_ADDRESS        (0x8E)                                          /* Gain compensation Seq 2 */
#define AS60XX_FDB_T4W2_RAB_G12_ADDRESS             (0x8F)                                          /* Reference port REF-AB Seq 2 */
#define AS60XX_FDB_T4W2_M1AB_G12_ADDRESS            (0x90)                                          /* Temperature port M1-AB Seq 2 */
#define AS60XX_FDB_T4W2_M2AB_G12_ADDRESS            (0x91)                                          /* Temperature port M2-AB Seq 2 */
#define AS60XX_FDB_T4W2_RA_G12_ADDRESS              (0x92)                                          /* Reference port REF A Seq 2 */
#define AS60XX_FDB_T4W2_RB_G12_ADDRESS              (0x93)                                          /* Reference port REF B Seq 2 */
#define AS60XX_FDB_T4W2_M1A_G12_ADDRESS             (0x94)                                          /* Temperature port M1-A Seq 2 */
#define AS60XX_FDB_T4W2_M1B_G12_ADDRESS             (0x95)                                          /* Temperature port M1-B Seq 2 */
#define AS60XX_FDB_T4W2_M1AB_G1_ADDRESS             (0x96)                                          /* Temperature port M1-AB Seq 2 */
#define AS60XX_FDB_T4W2_M1AB_G2_ADDRESS             (0x97)                                          /* Temperature port M1-AB Seq 2 */
#define AS60XX_FDB_T4W2_M2A_G12_ADDRESS             (0x98)                                          /* Temperature port M2-A Seq 2 */
#define AS60XX_FDB_T4W2_M2B_G12_ADDRESS             (0x99)                                          /* Temperature port M2-B Seq 2 */
#define AS60XX_FDB_T4W2_M2AB_G1_ADDRESS             (0x9A)                                          /* Temperature port M2-AB Seq 2 */
#define AS60XX_FDB_T4W2_M2AB_G2_ADDRESS             (0x9B)                                          /* Temperature port M2-AB Seq 2 */

/*********  Bit definition for FDB array in case of TOF measurement  **********/
#define AS60XX_FDB_US_TOF_SUM_OF_ALL_U_INDEX        (0)                                             /* Ultrasonic TOF Sum of All Value Up */
#define AS60XX_FDB_US_PW_U_INDEX                    (1)                                             /* Ultrasonic Pulse Width Ratio Up */
#define AS60XX_FDB_US_AM_U_INDEX                    (2)                                             /* Ultrasonic Amplitude Value Up */
#define AS60XX_FDB_US_AMC_VH_INDEX                  (3)                                             /* Ultrasonic Amplitude Calibrate Value High */
#define AS60XX_FDB_US_TOF_SUM_OF_ALL_D_INDEX        (4)                                             /* Ultrasonic TOF Sum of All Value Down */
#define AS60XX_FDB_US_PW_D_INDEX                    (5)                                             /* Ultrasonic Pulse Width Ratio Down */
#define AS60XX_FDB_US_AM_D_INDEX                    (6)                                             /* Ultrasonic Amplitude Value Down */
#define AS60XX_FDB_US_AMC_VL_INDEX                  (7)                                             /* Ultrasonic Amplitude Calibrate Value Low */
#define AS60XX_FDB_US_TOF_0_U_INDEX                 (8)                                             /* Ultrasonic TOF Up: Value 0 */
#define AS60XX_FDB_US_TOF_1_U_INDEX                 (9)                                             /* Ultrasonic TOF Up: Value 1 */
#define AS60XX_FDB_US_TOF_2_U_INDEX                 (10)                                             /* Ultrasonic TOF Up: Value 2 */
#define AS60XX_FDB_US_TOF_3_U_INDEX                 (11)                                             /* Ultrasonic TOF Up: Value 3 */
#define AS60XX_FDB_US_TOF_4_U_INDEX                 (12)                                             /* Ultrasonic TOF Up: Value 4 */
#define AS60XX_FDB_US_TOF_5_U_INDEX                 (13)                                             /* Ultrasonic TOF Up: Value 5 */
#define AS60XX_FDB_US_TOF_6_U_INDEX                 (14)                                             /* Ultrasonic TOF Up: Value 6 */
#define AS60XX_FDB_US_TOF_7_U_INDEX                 (15)                                             /* Ultrasonic TOF Up: Value 7 */
#define AS60XX_FDB_US_TOF_8_U_INDEX                 (16)                                             /* Ultrasonic TOF Up: Value 8 */
#define AS60XX_FDB_US_TOF_9_U_INDEX                 (17)                                             /* Ultrasonic TOF Up: Value 9 */
#define AS60XX_FDB_US_TOF_0_D_INDEX                 (18)                                             /* Ultrasonic TOF Down: Value 0 */
#define AS60XX_FDB_US_TOF_1_D_INDEX                 (19)                                             /* Ultrasonic TOF Down: Value 1 */
#define AS60XX_FDB_US_TOF_2_D_INDEX                 (20)                                             /* Ultrasonic TOF Down: Value 2 */
#define AS60XX_FDB_US_TOF_3_D_INDEX                 (21)                                             /* Ultrasonic TOF Down: Value 3 */
#define AS60XX_FDB_US_TOF_4_D_INDEX                 (22)                                             /* Ultrasonic TOF Down: Value 4 */
#define AS60XX_FDB_US_TOF_5_D_INDEX                 (23)                                             /* Ultrasonic TOF Down: Value 5 */
#define AS60XX_FDB_US_TOF_6_D_INDEX                 (24)                                             /* Ultrasonic TOF Down: Value 6 */
#define AS60XX_FDB_US_TOF_7_D_INDEX                 (25)                                             /* Ultrasonic TOF Down: Value 7 */
#define AS60XX_FDB_US_TOF_8_D_INDEX                 (26)                                             /* Ultrasonic TOF Down: Value 8 */
#define AS60XX_FDB_US_TOF_9_D_INDEX                 (27)                                             /* Ultrasonic TOF Down: Value 9 */

/******  Bit definition for FDB array in case of Temperature measurement  *******/
#define AS60XX_FDB_TPM1_M1AB_RAB_G12_INDEX          (0)                                             /* Gain compensation Seq 1 */
#define AS60XX_FDB_TPM1_RAB_G12_INDEX               (1)                                             /* Reference port REF-AB Seq 1 */
#define AS60XX_FDB_TPM1_M1A_G12_INDEX               (2)                                             /* Temperature port M1-A Seq 1 */
#define AS60XX_FDB_TPM1_M2A_G12_INDEX               (3)                                             /* Temperature port M2-A Seq 1 */
#define AS60XX_FDB_TPM1_RA_G12_INDEX                (4)                                             /* RDSON compensation Seq 1 */
#define AS60XX_FDB_TPM1_MI_R_G12_INDEX              (5)                                             /* Internal temperature reference Seq 1 */
#define AS60XX_FDB_TPM1_MI_RM_G12_INDEX             (6)                                             /* Internal temperature compensation Seq 1 */
#define AS60XX_FDB_TPM1_MI_M_G12_INDEX              (7)                                             /* Internal temperature measurement Seq 1 */
#define AS60XX_FDB_TPM2_M1AB_RAB_G12_INDEX          (14)                                            /* Gain compensation Seq 2 */
#define AS60XX_FDB_TPM2_RAB_G12_INDEX               (15)                                            /* Reference port REF-AB Seq 2 */
#define AS60XX_FDB_TPM2_M1A_G12_INDEX               (16)                                            /* Temperature port M1-A Seq 2 */
#define AS60XX_FDB_TPM2_M2A_G12_INDEX               (17)                                            /* Temperature port M2-A Seq 2 */
#define AS60XX_FDB_TPM2_RA_G12_INDEX                (18)                                            /* RDSON compensation Seq 2 */
#define AS60XX_FDB_TPM2_MI_R_G12_INDEX              (19)                                            /* Internal temperature reference Seq 2 */
#define AS60XX_FDB_TPM2_MI_RM_G12_INDEX             (20)                                            /* Internal temperature compensation Seq 2 */
#define AS60XX_FDB_TPM2_MI_M_G12_INDEX              (21)                                            /* Internal temperature measurement Seq 2 */

/* Bit definition for FDB array in case of Four Wire Temperature measurement  */
#define AS60XX_FDB_T4W1_M1AB_RAB_G12_INDEX          (0)                                             /* Gain compensation Seq 1 */
#define AS60XX_FDB_T4W1_RAB_G12_INDEX               (1)                                             /* Reference port REF-AB Seq 1 */
#define AS60XX_FDB_T4W1_M1AB_G12_INDEX              (2)                                             /* Temperature port M1-AB Seq 1 */
#define AS60XX_FDB_T4W1_M2AB_G12_INDEX              (3)                                             /* Temperature port M2-AB Seq 1 */
#define AS60XX_FDB_T4W1_RA_G12_INDEX                (4)                                             /* Reference port REF A Seq 1 */
#define AS60XX_FDB_T4W1_RB_G12_INDEX                (5)                                             /* Reference port REF B Seq 1 */
#define AS60XX_FDB_T4W1_M1A_G12_INDEX               (6)                                             /* Temperature port M1-A Seq 1 */
#define AS60XX_FDB_T4W1_M1B_G12_INDEX               (7)                                             /* Temperature port M1-B Seq 1 */
#define AS60XX_FDB_T4W1_M1AB_G1_INDEX               (8)                                             /* Temperature port M1-AB Seq 1 */
#define AS60XX_FDB_T4W1_M1AB_G2_INDEX               (9)                                             /* Temperature port M1-AB Seq 1 */
#define AS60XX_FDB_T4W1_M2A_G12_INDEX               (10)                                            /* Temperature port M2-A Seq 1 */
#define AS60XX_FDB_T4W1_M2B_G12_INDEX               (11)                                            /* Temperature port M2-B Seq 1 */
#define AS60XX_FDB_TPM1_M2B_G1_INDEX                (12)                                            /* Temperature port M2-AB Seq 1 */
#define AS60XX_FDB_TPM1_M2B_G2_INDEX                (13)                                            /* Temperature port M2-AB Seq 1 */
#define AS60XX_FDB_T4W2_M1AB_RAB_G12_INDEX          (14)                                            /* Gain compensation Seq 2 */
#define AS60XX_FDB_T4W2_RAB_G12_INDEX               (15)                                            /* Reference port REF-AB Seq 2 */
#define AS60XX_FDB_T4W2_M1AB_G12_INDEX              (16)                                            /* Temperature port M1-AB Seq 2 */
#define AS60XX_FDB_T4W2_M2AB_G12_INDEX              (17)                                            /* Temperature port M2-AB Seq 2 */
#define AS60XX_FDB_T4W2_RA_G12_INDEX                (18)                                            /* Reference port REF A Seq 2 */
#define AS60XX_FDB_T4W2_RB_G12_INDEX                (19)                                            /* Reference port REF B Seq 2 */
#define AS60XX_FDB_T4W2_M1A_G12_INDEX               (20)                                            /* Temperature port M1-A Seq 2 */
#define AS60XX_FDB_T4W2_M1B_G12_INDEX               (21)                                            /* Temperature port M1-B Seq 2 */
#define AS60XX_FDB_T4W2_M1AB_G1_INDEX               (22)                                            /* Temperature port M1-AB Seq 2 */
#define AS60XX_FDB_T4W2_M1AB_G2_INDEX               (23)                                            /* Temperature port M1-AB Seq 2 */
#define AS60XX_FDB_T4W2_M2A_G12_INDEX               (24)                                            /* Temperature port M2-A Seq 2 */
#define AS60XX_FDB_T4W2_M2B_G12_INDEX               (25)                                            /* Temperature port M2-B Seq 2 */
#define AS60XX_FDB_T4W2_M2AB_G1_INDEX               (26)                                            /* Temperature port M2-AB Seq 2 */
#define AS60XX_FDB_T4W2_M2AB_G2_INDEX               (27)                                            /* Temperature port M2-AB Seq 2 */

/*************  Bit definition for CR array in AS60xx struct  *****************/
#define AS60XX_CR_ARRAY_CR_WD_DIS_INDEX             (0)                                             /* Index of the configuration array in the AS60xx struct that corresponds to register 0xC0 */
#define AS60XX_CR_ARRAY_CR_IFC_CTRL_INDEX           (1)                                             /* Index of the configuration array in the AS60xx struct that corresponds to register 0xC1 */
#define AS60XX_CR_ARRAY_CR_GP_CTRL_INDEX            (2)                                             /* Index of the configuration array in the AS60xx struct that corresponds to register 0xC2 */
#define AS60XX_CR_ARRAY_CR_USM_OPT_INDEX            (3)                                             /* Index of the configuration array in the AS60xx struct that corresponds to register 0xC3 */
#define AS60XX_CR_ARRAY_CR_IEH_INDEX                (4)                                             /* Index of the configuration array in the AS60xx struct that corresponds to register 0xC4 */
#define AS60XX_CR_ARRAY_CR_CPM_INDEX                (5)                                             /* Index of the configuration array in the AS60xx struct that corresponds to register 0xC5 */
#define AS60XX_CR_ARRAY_CR_MRG_TS_INDEX             (6)                                             /* Index of the configuration array in the AS60xx struct that corresponds to register 0xC6 */
#define AS60XX_CR_ARRAY_CR_TPM_INDEX                (7)                                             /* Index of the configuration array in the AS60xx struct that corresponds to register 0xC7 */
#define AS60XX_CR_ARRAY_CR_USM_PRC_INDEX            (8)                                             /* Index of the configuration array in the AS60xx struct that corresponds to register 0xC8 */
#define AS60XX_CR_ARRAY_CR_USM_FRC_INDEX            (9)                                             /* Index of the configuration array in the AS60xx struct that corresponds to register 0xC9 */
#define AS60XX_CR_ARRAY_CR_USM_TOF_INDEX            (10)                                            /* Index of the configuration array in the AS60xx struct that corresponds to register 0xCA */
#define AS60XX_CR_ARRAY_CR_USM_AM_INDEX             (11)                                            /* Index of the configuration array in the AS60xx struct that corresponds to register 0xCB */
#define AS60XX_CR_ARRAY_CR_TRIM1_INDEX              (12)                                            /* Index of the configuration array in the AS60xx struct that corresponds to register 0xCC */
#define AS60XX_CR_ARRAY_CR_TRIM2_INDEX              (13)                                            /* Index of the configuration array in the AS60xx struct that corresponds to register 0xCD */
#define AS60XX_CR_ARRAY_CR_TRIM3_INDEX              (14)                                            /* Index of the configuration array in the AS60xx struct that corresponds to register 0xCE */
#define AS60XX_CR_ARRAY_SHR_TOF_RATE_INDEX          (15)                                            /* Index of the configuration array in the AS60xx struct that corresponds to register 0xD0 */
#define AS60XX_CR_ARRAY_SHR_USM_RLS_DLY_U_INDEX     (16)                                            /* Index of the configuration array in the AS60xx struct that corresponds to register 0xD1 */
#define AS60XX_CR_ARRAY_SHR_USM_RLS_DLY_D_INDEX     (17)                                            /* Index of the configuration array in the AS60xx struct that corresponds to register 0xD2 */
#define AS60XX_CR_ARRAY_SHR_FHL_U_INDEX             (18)                                            /* Index of the configuration array in the AS60xx struct that corresponds to register 0xDA */
#define AS60XX_CR_ARRAY_SHR_FHL_D_INDEX             (19)                                            /* Index of the configuration array in the AS60xx struct that corresponds to register 0xDB */

/***********  Bit definition for Status array in AS60xx struct  ***************/
#define AS60XX_STATUS_SRR_IRQ_FLAG_INDEX            (0)                                             /* Index of the status array in the AS60xx struct that corresponds to register 0xE0 */
#define AS60XX_STATUS_SRR_ERR_FLAG_INDEX            (1)                                             /* Index of the status array in the AS60xx struct that corresponds to register 0xE1 */
#define AS60XX_STATUS_SRR_FEP_STF_INDEX             (2)                                             /* Index of the status array in the AS60xx struct that corresponds to register 0xE2 */
#define AS60XX_STATUS_SRR_GPI_INDEX                 (3)                                             /* Index of the status array in the AS60xx struct that corresponds to register 0xE3 */
#define AS60XX_STATUS_SRR_HCC_VAL_INDEX             (4)                                             /* Index of the status array in the AS60xx struct that corresponds to register 0xE4 */
#define AS60XX_STATUS_SRR_VCC_VAL_INDEX             (5)                                             /* Index of the status array in the AS60xx struct that corresponds to register 0xE5 */
#define AS60XX_STATUS_SRR_TS_HOUR_INDEX             (6)                                             /* Index of the status array in the AS60xx struct that corresponds to register 0xE6 */
#define AS60XX_STATUS_SRR_TS_MIN_SEC_INDEX          (7)                                             /* Index of the status array in the AS60xx struct that corresponds to register 0xE7 */
#define AS60XX_STATUS_SRR_TS_TIME_INDEX             (9)                                             /* Index of the status array in the AS60xx struct that corresponds to register 0xE9 */
#define AS60XX_STATUS_SRR_MSC_STF_INDEX             (10)                                            /* Index of the status array in the AS60xx struct that corresponds to register 0xEA */
#define AS60XX_STATUS_SRR_I2C_RD_INDEX              (11)                                            /* Index of the status array in the AS60xx struct that corresponds to register 0xEB */
#define AS60XX_STATUS_SRR_FWU_RNG_INDEX             (12)                                            /* Index of the status array in the AS60xx struct that corresponds to register 0xEC */
#define AS60XX_STATUS_SRR_FWU_REV_INDEX             (13)                                            /* Index of the status array in the AS60xx struct that corresponds to register 0xED */
#define AS60XX_STATUS_SRR_FWA_REV_INDEX             (14)                                            /* Index of the status array in the AS60xx struct that corresponds to register 0xEE */

/******************  Bit definition for AS60XX_C0 register  *******************/
#define AS60XX_C0_WS_DIS_Pos                        (0U)
#define AS60XX_C0_WS_DIS_Msk                        (0xFFFFFFFFUL << AS60XX_C0_WS_DIS_Pos)          /*!< 0xFFFFFFFF */
#define AS60XX_C0_WS_DIS                            (0x48DBA399)                                    /*!< WS_DIS[31:0]Code to disable Watchdog */

/******************  Bit definition for AS60XX_C1 register  *******************/
#define AS60XX_C1_PI_TPW_Pos                        (0U)
#define AS60XX_C1_PI_TPW_Msk                        (0xFFUL << AS60XX_C1_PI_TPW_Pos)                /*!< 0x000000FF */
#define AS60XX_C1_PI_TPW_0                          (0x01)                                          /*!< PI_TPW[7:0]Pulse Interface, Pulse Width */
#define AS60XX_C1_PI_TPW_1                          (0x02)                                          /*!< PI_TPW[7:0]Pulse Interface, Pulse Width */
#define AS60XX_C1_PI_TPW_2                          (0x04)                                          /*!< PI_TPW[7:0]Pulse Interface, Pulse Width */
#define AS60XX_C1_PI_TPW_3                          (0x08)                                          /*!< PI_TPW[7:0]Pulse Interface, Pulse Width */
#define AS60XX_C1_PI_TPW_4                          (0x10)                                          /*!< PI_TPW[7:0]Pulse Interface, Pulse Width */
#define AS60XX_C1_PI_TPW_5                          (0x20)                                          /*!< PI_TPW[7:0]Pulse Interface, Pulse Width */
#define AS60XX_C1_PI_TPW_6                          (0x40)                                          /*!< PI_TPW[7:0]Pulse Interface, Pulse Width */
#define AS60XX_C1_PI_TPW_7                          (0x80)                                          /*!< PI_TPW[7:0]Pulse Interface, Pulse Width */
#define AS60XX_C1_PI_EN_Pos                         (8U)
#define AS60XX_C1_PI_EN_Msk                         (0x1UL << AS60XX_C1_PI_EN_Pos)                  /*!< 0x00000100 */
#define AS60XX_C1_PI_EN_DISABLE                     (0)                                             /*!< Pulse Interface Disable */
#define AS60XX_C1_PI_EN_ENABLE                      (1)                                             /*!< Pulse Interface Enable */
#define AS60XX_C1_PI_OUT_MODE_Pos                   (9U)
#define AS60XX_C1_PI_OUT_MODE_Msk                   (0x1UL << AS60XX_C1_PI_OUT_MODE_Pos)            /*!< 0x00000200 */
#define AS60XX_C1_PI_OUT_MODE_ONE_LINE              (0)                                             /*!< Pulse Interface Output Mode pulses on one line*/
#define AS60XX_C1_PI_OUT_MODE_DIFF_LINES            (1)                                             /*!< Pulse Interface Output Mode pulses on different lines*/
#define AS60XX_C1_PI_UPD_MODE_Pos                   (10U)
#define AS60XX_C1_PI_UPD_MODE_Msk                   (0x1UL << AS60XX_C1_PI_UPD_MODE_Pos)            /*!< 0x00000400 */
#define AS60XX_C1_PI_UPD_MODE_DISABLED              (0)                                             /*!< Pulse Interface Update Mode, automatic updated disabled */
#define AS60XX_C1_PI_UPD_MODE_ENABLED               (1)                                             /*!< Pulse Interface Update Mode, automatic update */
#define AS60XX_C1_NOT_USED_11_Pos                   (11U)
#define AS60XX_C1_NOT_USED_11_Msk                   (0x1UL << AS60XX_C1_NOT_USED_11_Pos)            /*!< 0x00000800 */
#define AS60XX_C1_NOT_USED_11                       (0)                                             /*!< Mandatory setting: b0 */
#define AS60XX_C1_I2C_MODE_Pos                      (12U)
#define AS60XX_C1_I2C_MODE_Msk                      (0x03UL << AS60XX_C1_I2C_MODE_Pos)              /*!< 0x00003000 */
#define AS60XX_C1_I2C_MODE_DISABLED                 (0)
#define AS60XX_C1_I2C_MODE_ENABLED_GPIO_0_1         (1)
#define AS60XX_C1_I2C_MODE_ENABLED_GPIO_2_3         (2)
#define AS60XX_C1_I2C_ADR_Pos                       (14U)
#define AS60XX_C1_I2C_ADR_Msk                       (0x07FUL << AS60XX_C1_I2C_ADR_Pos)              /*!< 0x001FC000 */
#define AS60XX_C1_I2C_ADR                           AS60XX_C1_I2C_ADR_Msk                           /*!< I2C_ADR[20:14]2-wire master interface slave address */
#define AS60XX_C1_I2C_ADR_0                         (0x01)
#define AS60XX_C1_I2C_ADR_1                         (0x02)
#define AS60XX_C1_I2C_ADR_2                         (0x04)
#define AS60XX_C1_I2C_ADR_3                         (0x08)
#define AS60XX_C1_I2C_ADR_4                         (0x10)
#define AS60XX_C1_I2C_ADR_5                         (0x20)
#define AS60XX_C1_I2C_ADR_6                         (0x40)
#define AS60XX_C1_NOT_USED_21_Pos                   (21U)
#define AS60XX_C1_NOT_USED_21_Msk                   (0x1UL << AS60XX_C1_NOT_USED_21_Pos)            /*!< 0x00200000 */
#define AS60XX_C1_NOT_USED_21                       (0)                                             /*!< Mandatory setting: b0 */
#define AS60XX_C1_SPI_INPORT_CFG_Pos                (22U)
#define AS60XX_C1_SPI_INPORT_CFG_Msk                (0x03UL << AS60XX_C1_SPI_INPORT_CFG_Pos)        /*!< 0x00C00000 */
#define AS60XX_C1_SPI_INPORT_CFG_HIGH_Z             (0)                                             /*!< SPI_INPORT_CFG[23:22] Configuration of SPI input ports as High Z */
#define AS60XX_C1_SPI_INPORT_CFG_PULL_UP            (1)                                             /*!< SPI_INPORT_CFG[23:22] Configuration of SPI input ports as Pull up */
#define AS60XX_C1_SPI_INPORT_CFG_PULL_DN            (2)                                             /*!< SPI_INPORT_CFG[23:22] Configuration of SPI input ports as Pull down */
#define AS60XX_C1_NOT_USED_31_24_Pos                (24U)
#define AS60XX_C1_NOT_USED_31_24_Msk                (0xFFUL << AS60XX_C1_NOT_USED_31_24_Pos)        /*!< 0xFF000000 */
#define AS60XX_C1_NOT_USED_31_24                    (0)                                             /*!< NOT_USED_31_24[31:24]Not used */

/******************  Bit definition for AS60XX_C2 register  *******************/
#define AS60XX_C2_GP0_DIR_Pos                       (0U)
#define AS60XX_C2_GP0_DIR_Msk                       (0x03UL << AS60XX_C2_GP0_DIR_Pos)               /*!< 0x00000003 */
#define AS60XX_C2_GP0_DIR_OUTPUT                    (0)                                             /*!< GP0_DIR[1:0]Direction of General Purpose Port 0 */      
#define AS60XX_C2_GP0_DIR_INPUT_PULL_UP             (1)                                             /*!< GP0_DIR[1:0]Direction of General Purpose Port 0 */
#define AS60XX_C2_GP0_DIR_INPUT_PULL_DN             (2)                                             /*!< GP0_DIR[1:0]Direction of General Purpose Port 0 */
#define AS60XX_C2_GP0_DIR_INPUT_HIGH_Z              (3)                                             /*!< GP0_DIR[1:0]Direction of General Purpose Port 0 */
#define AS60XX_C2_GP0_SEL_Pos                       (2U)
#define AS60XX_C2_GP0_SEL_Msk                       (0x03UL << AS60XX_C2_GP0_SEL_Pos)               /*!< 0x0000000C */
#define AS60XX_C2_GP0_SEL_GENERAL_PURPOSE_OUT       (0)                                             /*!< GP0_SEL[3:2]Output Select of General Purpose Port 0 */
#define AS60XX_C2_GP0_SEL_PULSE                     (1)                                             /*!< GP0_SEL[3:2]Output Select of General Purpose Port 0 */
#define AS60XX_C2_GP0_SEL_LOW_SPEED_CLK             (2)                                             /*!< GP0_SEL[3:2]Output Select of General Purpose Port 0 */
#define AS60XX_C2_GP0_SEL_US_FIRE_BURST             (3)                                             /*!< GP0_SEL[3:2]Output Select of General Purpose Port 0 */
#define AS60XX_C2_GP1_DIR_Pos                       (4U)
#define AS60XX_C2_GP1_DIR_Msk                       (0x03UL << AS60XX_C2_GP1_DIR_Pos)               /*!< 0x00000030 */
#define AS60XX_C2_GP1_DIR_OUTPUT                    (0)                                             /*!< GP1_DIR[5:4]Direction of General Purpose Port 1 */
#define AS60XX_C2_GP1_DIR_INPUT_PULL_UP             (1)                                             /*!< GP1_DIR[5:4]Direction of General Purpose Port 1 */
#define AS60XX_C2_GP1_DIR_INPUT_PULL_DN             (2)                                             /*!< GP1_DIR[5:4]Direction of General Purpose Port 1 */
#define AS60XX_C2_GP1_DIR_INPUT_HIGH_Z              (3)                                             /*!< GP1_DIR[5:4]Direction of General Purpose Port 1 */
#define AS60XX_C2_GP1_SEL_Pos                       (6U)
#define AS60XX_C2_GP1_SEL_Msk                       (0x03UL << AS60XX_C2_GP1_SEL_Pos)               /*!< 0x000000C0 */
#define AS60XX_C2_GP1_SEL_GENERAL_PURPOSE_OUT       (0)                                             /*!< GP1_SEL[7:6]Output Select of General Purpose Port 1 */
#define AS60XX_C2_GP1_SEL_PULSE                     (1)                                             /*!< GP1_SEL[7:6]Output Select of General Purpose Port 1 */
#define AS60XX_C2_GP1_SEL_LOW_SPEED_CLK             (2)                                             /*!< GP1_SEL[7:6]Output Select of General Purpose Port 1 */
#define AS60XX_C2_GP1_SEL_US_FIRE_BURST             (3)                                             /*!< GP1_SEL[7:6]Output Select of General Purpose Port 1 */
#define AS60XX_C2_GP2_DIR_Pos                       (8U)
#define AS60XX_C2_GP2_DIR_Msk                       (0x03UL << AS60XX_C2_GP2_DIR_Pos)               /*!< 0x00000300 */
#define AS60XX_C2_GP2_DIR_OUTPUT                    (0)                                             /*!< GP2_DIR[9:8]Direction of General Purpose Port 2 */      
#define AS60XX_C2_GP2_DIR_INPUT_PULL_UP             (1)                                             /*!< GP2_DIR[9:8]Direction of General Purpose Port 2 */
#define AS60XX_C2_GP2_DIR_INPUT_PULL_DN             (2)                                             /*!< GP2_DIR[9:8]Direction of General Purpose Port 2 */
#define AS60XX_C2_GP2_DIR_INPUT_HIGH_Z              (3)                                             /*!< GP2_DIR[9:8]Direction of General Purpose Port 2 */
#define AS60XX_C2_GP2_SEL_Pos                       (10U)
#define AS60XX_C2_GP2_SEL_Msk                       (0x03UL << AS60XX_C2_GP2_SEL_Pos)               /*!< 0x00000C00 */
#define AS60XX_C2_GP2_SEL_GENERAL_PURPOSE_OUT       (0)                                             /*!< GP2_SEL[11:10]Output Select of General Purpose Port 2 */
#define AS60XX_C2_GP2_SEL_PULSE                     (1)                                             /*!< GP2_SEL[11:10]Output Select of General Purpose Port 2 */
#define AS60XX_C2_GP2_SEL_LOW_SPEED_CLK             (2)                                             /*!< GP2_SEL[11:10]Output Select of General Purpose Port 2 */
#define AS60XX_C2_GP2_SEL_US_FIRE_BURST             (3)                                             /*!< GP2_SEL[11:10]Output Select of General Purpose Port 2 */
#define AS60XX_C2_GP3_DIR_Pos                       (12U)
#define AS60XX_C2_GP3_DIR_Msk                       (0x03UL << AS60XX_C2_GP3_DIR_Pos)               /*!< 0x00003000 */
#define AS60XX_C2_GP3_DIR_OUTPUT                    (0)                                             /*!< GP3_DIR[13:12]Direction of General Purpose Port 3 */      
#define AS60XX_C2_GP3_DIR_INPUT_PULL_UP             (1)                                             /*!< GP3_DIR[13:12]Direction of General Purpose Port 3 */ 
#define AS60XX_C2_GP3_DIR_INPUT_PULL_DN             (2)                                             /*!< GP3_DIR[13:12]Direction of General Purpose Port 3 */ 
#define AS60XX_C2_GP3_DIR_INPUT_HIGH_Z              (3)                                             /*!< GP3_DIR[13:12]Direction of General Purpose Port 3 */ 
#define AS60XX_C2_GP3_SEL_Pos                       (14U)
#define AS60XX_C2_GP3_SEL_Msk                       (0x03UL << AS60XX_C2_GP3_SEL_Pos)               /*!< 0x0000C000 */
#define AS60XX_C2_GP3_SEL_GENERAL_PURPOSE_OUT       (0)                                             /*!< GP3_SEL[15:14]Output Select of General Purpose Port 3 */
#define AS60XX_C2_GP3_SEL_PULSE                     (1)                                             /*!< GP3_SEL[15:14]Output Select of General Purpose Port 3 */
#define AS60XX_C2_GP3_SEL_LOW_SPEED_CLK             (2)                                             /*!< GP3_SEL[15:14]Output Select of General Purpose Port 3 */
#define AS60XX_C2_GP3_SEL_US_FIRE_BURST             (3)                                             /*!< GP3_SEL[15:14]Output Select of General Purpose Port 3 */
#define AS60XX_C2_GP4_DIR_Pos                       (16U)
#define AS60XX_C2_GP4_DIR_Msk                       (0x03UL << AS60XX_C2_GP4_DIR_Pos)               /*!< 0x00030000 */
#define AS60XX_C2_GP4_DIR_OUTPUT                    (0)                                             /*!< GP4_DIR[17:16]Direction of General Purpose Port 4 */      
#define AS60XX_C2_GP4_DIR_INPUT_PULL_UP             (1)                                             /*!< GP4_DIR[17:16]Direction of General Purpose Port 4 */
#define AS60XX_C2_GP4_DIR_INPUT_PULL_DN             (2)                                             /*!< GP4_DIR[17:16]Direction of General Purpose Port 4 */
#define AS60XX_C2_GP4_DIR_INPUT_HIGH_Z              (3)                                             /*!< GP4_DIR[17:16]Direction of General Purpose Port 4 */
#define AS60XX_C2_GP4_SEL_Pos                       (18U)
#define AS60XX_C2_GP4_SEL_Msk                       (0x03UL << AS60XX_C2_GP4_SEL_Pos)               /*!< 0x000C0000 */
#define AS60XX_C2_GP4_SEL_GENERAL_PURPOSE_OUT       (0)                                             /*!< GP4_SEL[19:18]Output Select of General Purpose Port 4 */
#define AS60XX_C2_GP4_SEL_PULSE                     (1)                                             /*!< GP4_SEL[19:18]Output Select of General Purpose Port 4 */
#define AS60XX_C2_GP4_SEL_LOW_SPEED_CLK             (2)                                             /*!< GP4_SEL[19:18]Output Select of General Purpose Port 4 */
#define AS60XX_C2_GP4_SEL_US_FIRE_BURST             (3)                                             /*!< GP4_SEL[19:18]Output Select of General Purpose Port 4 */
#define AS60XX_C2_GP5_DIR_Pos                       (20U)
#define AS60XX_C2_GP5_DIR_Msk                       (0x03UL << AS60XX_C2_GP5_DIR_Pos)               /*!< 0x00300000 */
#define AS60XX_C2_GP5_DIR_OUTPUT                    (0)                                             /*!< GP5_DIR[21:20]Direction of General Purpose Port 5 */      
#define AS60XX_C2_GP5_DIR_INPUT_PULL_UP             (1)                                             /*!< GP5_DIR[21:20]Direction of General Purpose Port 5 */ 
#define AS60XX_C2_GP5_DIR_INPUT_PULL_DN             (2)                                             /*!< GP5_DIR[21:20]Direction of General Purpose Port 5 */ 
#define AS60XX_C2_GP5_DIR_INPUT_HIGH_Z              (3)                                             /*!< GP5_DIR[21:20]Direction of General Purpose Port 5 */ 
#define AS60XX_C2_GP5_SEL_Pos                       (22U)
#define AS60XX_C2_GP5_SEL_Msk                       (0x03UL << AS60XX_C2_GP5_SEL_Pos)               /*!< 0x00C00000 */
#define AS60XX_C2_GP5_SEL_GENERAL_PURPOSE_OUT       (0)                                             /*!< GP5_SEL[23:22]Output Select of General Purpose Port 5 */
#define AS60XX_C2_GP5_SEL_PULSE                     (1)                                             /*!< GP5_SEL[23:22]Output Select of General Purpose Port 5 */
#define AS60XX_C2_GP5_SEL_LOW_SPEED_CLK             (2)                                             /*!< GP5_SEL[23:22]Output Select of General Purpose Port 5 */
#define AS60XX_C2_GP5_SEL_US_FIRE_BURST             (3)                                             /*!< GP5_SEL[23:22]Output Select of General Purpose Port 5 */
#define AS60XX_C2_NOT_USED_31_24_Pos                (24U)
#define AS60XX_C2_NOT_USED_31_24_Msk                (0xFFUL << AS60XX_C2_NOT_USED_31_24_Pos)        /*!< 0xFF000000 */
#define AS60XX_C2_NOT_USED_31_24                    (0)                                             /*!< NOT_USED_31_24[31:24]Not used */

/******************  Bit definition for AS60XX_C3 register  *******************/
#define AS60XX_C3_USM_OPT_Pos                       (0U)
#define AS60XX_C3_USM_OPT_Msk                       (0x1FUL << AS60XX_C3_USM_OPT_Pos)               /*!< 0x0000001F */
#define AS60XX_C3_USM_OPT_0                         (0x01)                                          /*!< USM_OPT[4:0]Mandatory setting: b00001 */
#define AS60XX_C3_USM_OPT_1                         (0x02)                                          /*!< USM_OPT[4:0]Mandatory setting: b00001 */
#define AS60XX_C3_USM_OPT_2                         (0x04)                                          /*!< USM_OPT[4:0]Mandatory setting: b00001 */
#define AS60XX_C3_USM_OPT_3                         (0x08)                                          /*!< USM_OPT[4:0]Mandatory setting: b00001 */
#define AS60XX_C3_USM_OPT_4                         (0x10)                                          /*!< USM_OPT[4:0]Mandatory setting: b00001 */
#define AS60XX_C3_NOT_USED_31_5_Pos                 (5U)
#define AS60XX_C3_NOT_USED_31_5_Msk                 (0x07FFFFFFUL << AS60XX_C3_NOT_USED_31_5_Pos)   /*!< 0xFFFFFFE0 */
#define AS60XX_C3_NOT_USED_31_5                     (0)                                             /*!< NOT_USED_31_5[31:5]Not used */

/******************  Bit definition for AS60XX_C4 register  *******************/
#define AS60XX_C4_EF_EN_TDC_TMO_Pos                 (0U)
#define AS60XX_C4_EF_EN_TDC_TMO_Msk                 (0x1UL << AS60XX_C4_EF_EN_TDC_TMO_Pos)          /*!< 0x00000001 */
#define AS60XX_C4_EF_EN_TDC_TMO                     (1)                                             /*!< Error Flag Enable, TDC Timeout */
#define AS60XX_C4_EF_EN_TOF_TMO_Pos                 (1U)
#define AS60XX_C4_EF_EN_TOF_TMO_Msk                 (0x1UL << AS60XX_C4_EF_EN_TOF_TMO_Pos)          /*!< 0x00000002 */
#define AS60XX_C4_EF_EN_TOF_TMO                     (1)                                             /*!< Error Flag Enable, TOF Timeout */
#define AS60XX_C4_EF_EN_AM_TMO_Pos                  (2U)
#define AS60XX_C4_EF_EN_AM_TMO_Msk                  (0x1UL << AS60XX_C4_EF_EN_AM_TMO_Pos)           /*!< 0x00000004 */
#define AS60XX_C4_EF_EN_AM_TMO                      (1)                                             /*!< Error Flag Enable, Amplitude Measurement Timeout */
#define AS60XX_C4_EF_EN_TM_OC_Pos                   (3U)
#define AS60XX_C4_EF_EN_TM_OC_Msk                   (0x1UL << AS60XX_C4_EF_EN_TM_OC_Pos)            /*!< 0x00000008 */
#define AS60XX_C4_EF_EN_TM_OC                       (1)                                             /*!< Error Flag Enable, Temperature Measurement Open Circuit */
#define AS60XX_C4_EF_EN_TM_SC_Pos                   (4U)
#define AS60XX_C4_EF_EN_TM_SC_Msk                   (0x1UL << AS60XX_C4_EF_EN_TM_SC_Pos)            /*!< 0x00000010 */
#define AS60XX_C4_EF_EN_TM_SC                       (1)                                             /*!< Error Flag Enable, Temperature Measurement Short Circuit */
#define AS60XX_C4_EF_EN_ZCC_ERR_Pos                 (5U)
#define AS60XX_C4_EF_EN_ZCC_ERR_Msk                 (0x1UL << AS60XX_C4_EF_EN_ZCC_ERR_Pos)          /*!< 0x00000020 */
#define AS60XX_C4_EF_EN_ZCC_ERR                     (1)                                             /*!< Error Flag Enable, Zero Cross Calibration Error */
#define AS60XX_C4_EF_EN_LBD_ERR_Pos                 (6U)
#define AS60XX_C4_EF_EN_LBD_ERR_Msk                 (0x1UL << AS60XX_C4_EF_EN_LBD_ERR_Pos)          /*!< 0x00000040 */
#define AS60XX_C4_EF_EN_LBD_ERR                     (1)                                             /*!< Error Flag Enable, Low Battery Detect Error */
#define AS60XX_C4_EF_EN_USM_SQC_TMO_Pos             (7U)
#define AS60XX_C4_EF_EN_USM_SQC_TMO_Msk             (0x1UL << AS60XX_C4_EF_EN_USM_SQC_TMO_Pos)      /*!< 0x00000080 */
#define AS60XX_C4_EF_EN_USM_SQC_TMO                 (1)                                             /*!< Error Flag Enable, Ultrasonic Sequence Timeout */
#define AS60XX_C4_EF_EN_TM_SQC_TMO_Pos              (8U)
#define AS60XX_C4_EF_EN_TM_SQC_TMO_Msk              (0x1UL << AS60XX_C4_EF_EN_TM_SQC_TMO_Pos)       /*!< 0x00000100 */
#define AS60XX_C4_EF_EN_TM_SQC_TMO                  (1)                                             /*!< Error Flag Enable, Temperature Sequence Timeout */
#define AS60XX_C4_EF_EN_TSQ_TMO_Pos                 (9U)
#define AS60XX_C4_EF_EN_TSQ_TMO_Msk                 (0x1UL << AS60XX_C4_EF_EN_TSQ_TMO_Pos)          /*!< 0x00000200 */
#define AS60XX_C4_EF_EN_TSQ_TMO                     (1)                                             /*!< Error Flag Enable, Task Sequencer Timeout */
#define AS60XX_C4_EF_EN_I2C_ACK_ERR_Pos             (10U)
#define AS60XX_C4_EF_EN_I2C_ACK_ERR_Msk             (0x1UL << AS60XX_C4_EF_EN_I2C_ACK_ERR_Pos)      /*!< 0x00000400 */
#define AS60XX_C4_EF_EN_I2C_ACK_ERR                 (1)                                             /*!< Error Flag Enable, EEPROM Acknowledge Error */
#define AS60XX_C4_EF_EN_CHP_ERR_Pos                 (11U)
#define AS60XX_C4_EF_EN_CHP_ERR_Msk                 (0x1UL << AS60XX_C4_EF_EN_CHP_ERR_Pos)          /*!< 0x00000800 */
#define AS60XX_C4_EF_EN_CHP_ERR                     (1)                                             /*!< Error Flag Enable, Charge Pump Error */
#define AS60XX_C4_EF_EN_NVM_FWCU_ERR_Pos            (12U)
#define AS60XX_C4_EF_EN_NVM_FWCU_ERR_Msk            (0x1UL << AS60XX_C4_EF_EN_NVM_FWCU_ERR_Pos)     /*!< 0x00001000 */
#define AS60XX_C4_EF_EN_NVM_FWCU_ERR                (1)                                             /*!< Error Flag Enable, NVM FWCU Error */
#define AS60XX_C4_EF_EN_NVM_FWDU_ERR_Pos            (13U)
#define AS60XX_C4_EF_EN_NVM_FWDU_ERR_Msk            (0x1UL << AS60XX_C4_EF_EN_NVM_FWDU_ERR_Pos)     /*!< 0x00002000 */
#define AS60XX_C4_EF_EN_NVM_FWDU_ERR                (1)                                             /*!< Error Flag Enable, NVM FWDU Error */
#define AS60XX_C4_EF_EN_NVM_FWA_ERR_Pos             (14U)
#define AS60XX_C4_EF_EN_NVM_FWA_ERR_Msk             (0x1UL << AS60XX_C4_EF_EN_NVM_FWA_ERR_Pos)      /*!< 0x00004000 */
#define AS60XX_C4_EF_EN_NVM_FWA_ERR                 (1)                                             /*!< Error Flag Enable, NVM Applied Firmware Error */
#define AS60XX_C4_EF_EN_CPU_ERR_Pos                 (15U)
#define AS60XX_C4_EF_EN_CPU_ERR_Msk                 (0x1UL << AS60XX_C4_EF_EN_CPU_ERR_Pos)          /*!< 0x00008000 */
#define AS60XX_C4_EF_EN_CPU_ERR                     (1)                                             /*!< Error Flag Enable, CPU Error */
#define AS60XX_C4_IRQ_EN_TSQ_FNS_Pos                (16U)
#define AS60XX_C4_IRQ_EN_TSQ_FNS_Msk                (0x1UL << AS60XX_C4_IRQ_EN_TSQ_FNS_Pos)         /*!< 0x00010000 */
#define AS60XX_C4_IRQ_EN_TSQ_FNS                    (1)                                             /*!< Interrupt Request Enable, Task Sequencer finished */
#define AS60XX_C4_IRQ_EN_TRANS_FNS_Pos              (17U)
#define AS60XX_C4_IRQ_EN_TRANS_FNS_Msk              (0x1UL << AS60XX_C4_IRQ_EN_TRANS_FNS_Pos)       /*!< 0x00020000 */
#define AS60XX_C4_IRQ_EN_TRANS_FNS                  (1)                                             /*!< Interrupt Request Enable, FW Transaction finished */
#define AS60XX_C4_IRQ_EN_BLD_FNS_Pos                (18U)
#define AS60XX_C4_IRQ_EN_BLD_FNS_Msk                (0x1UL << AS60XX_C4_IRQ_EN_BLD_FNS_Pos)         /*!< 0x00040000 */
#define AS60XX_C4_IRQ_EN_BLD_FNS                    (1)                                             /*!< Interrupt Request Enable, Bootload finished */
#define AS60XX_C4_IRQ_EN_CHKSUM_FNS_Pos             (19U)
#define AS60XX_C4_IRQ_EN_CHKSUM_FNS_Msk             (0x1UL << AS60XX_C4_IRQ_EN_CHKSUM_FNS_Pos)      /*!< 0x00080000 */
#define AS60XX_C4_IRQ_EN_CHKSUM_FNS                 (1)                                             /*!< Interrupt Request Enable, Checksum generation finished */
#define AS60XX_C4_IRQ_EN_FW_S_Pos                   (20U)
#define AS60XX_C4_IRQ_EN_FW_S_Msk                   (0x1UL << AS60XX_C4_IRQ_EN_FW_S_Pos)            /*!< 0x00100000 */
#define AS60XX_C4_IRQ_EN_FW_S                       (1)                                             /*!< Interrupt Request Enable, Firmware, synchronized with task sequencer */
#define AS60XX_C4_IRQ_EN_TSQ_TO_Pos                 (21U)
#define AS60XX_C4_IRQ_EN_TSQ_TO_Msk                 (0x1UL << AS60XX_C4_IRQ_EN_TSQ_TO_Pos)          /*!< 0x00200000 */
#define AS60XX_C4_IRQ_EN_TSQ_TO                     (1)                                             /*!< Interrupt Request Enable, Firmware */
#define AS60XX_C4_NOT_USED_22_Pos                   (22U)
#define AS60XX_C4_NOT_USED_22_Msk                   (0x1UL << AS60XX_C4_NOT_USED_22_Pos)            /*!< 0x00400000 */
#define AS60XX_C4_NOT_USED_22                       (0)                                             /*!< Mandatory setting: b0 */
#define AS60XX_C4_IRQ_EN_ERR_FLAG_Pos               (23U)
#define AS60XX_C4_IRQ_EN_ERR_FLAG_Msk               (0x1UL << AS60XX_C4_IRQ_EN_ERR_FLAG_Pos)        /*!< 0x00800000 */
#define AS60XX_C4_IRQ_EN_ERR_FLAG                   (1)                                             /*!< Interrupt Request Enable, Error Flag */
#define AS60XX_C4_NOT_USED_26_24_Pos                (24U)
#define AS60XX_C4_NOT_USED_26_24_Msk                (0x07UL << AS60XX_C4_NOT_USED_26_24_Pos)        /*!< 0x07000000 */
#define AS60XX_C4_NOT_USED_26_24                    (0)                                             /*!< NOT_USED_26_24[26:24]Mandatory setting: b000 */
#define AS60XX_C4_CPU_REQ_EN_GPH_Pos                (27U)
#define AS60XX_C4_CPU_REQ_EN_GPH_Msk                (0x1UL << AS60XX_C4_CPU_REQ_EN_GPH_Pos)         /*!< 0x08000000 */
#define AS60XX_C4_CPU_REQ_EN_GPH                    (1)                                             /*!< CPU Request Enable, General Purpose Handling */
#define AS60XX_C4_TS_GPT_RATE_Pos                   (28U)
#define AS60XX_C4_TS_GPT_RATE_Msk                   (0xFUL << AS60XX_C4_TS_GPT_RATE_Pos)            /*!< 0xF0000000 */
#define AS60XX_C4_TS_GPT_RATE_DISABLED              (0)                                             /*!< TS_GPT_RATE[31:28]General Purpose Timer Rate */
#define AS60XX_C4_TS_GPT_RATE_1_SEC                 (1)                                             /*!< TS_GPT_RATE[31:28]General Purpose Timer Rate */
#define AS60XX_C4_TS_GPT_RATE_2_SEC                 (2)                                             /*!< TS_GPT_RATE[31:28]General Purpose Timer Rate */
#define AS60XX_C4_TS_GPT_RATE_5_SEC                 (3)                                             /*!< TS_GPT_RATE[31:28]General Purpose Timer Rate */
#define AS60XX_C4_TS_GPT_RATE_10_SEC                (4)                                             /*!< TS_GPT_RATE[31:28]General Purpose Timer Rate */
#define AS60XX_C4_TS_GPT_RATE_30_SEC                (5)                                             /*!< TS_GPT_RATE[31:28]General Purpose Timer Rate */
#define AS60XX_C4_TS_GPT_RATE_1_MIN                 (6)                                             /*!< TS_GPT_RATE[31:28]General Purpose Timer Rate */
#define AS60XX_C4_TS_GPT_RATE_2_MIN                 (7)                                             /*!< TS_GPT_RATE[31:28]General Purpose Timer Rate */
#define AS60XX_C4_TS_GPT_RATE_5_MIN                 (8)                                             /*!< TS_GPT_RATE[31:28]General Purpose Timer Rate */
#define AS60XX_C4_TS_GPT_RATE_10_MIN                (9)                                             /*!< TS_GPT_RATE[31:28]General Purpose Timer Rate */
#define AS60XX_C4_TS_GPT_RATE_30_MIN                (10)                                            /*!< TS_GPT_RATE[31:28]General Purpose Timer Rate */
#define AS60XX_C4_TS_GPT_RATE_1_HR                  (11)                                            /*!< TS_GPT_RATE[31:28]General Purpose Timer Rate */
#define AS60XX_C4_TS_GPT_RATE_2_HR                  (12)                                            /*!< TS_GPT_RATE[31:28]General Purpose Timer Rate */
#define AS60XX_C4_TS_GPT_RATE_6_HR                  (13)                                            /*!< TS_GPT_RATE[31:28]General Purpose Timer Rate */
#define AS60XX_C4_TS_GPT_RATE_24_HR                 (14)                                            /*!< TS_GPT_RATE[31:28]General Purpose Timer Rate */
#define AS60XX_C4_TS_GPT_RATE_48_HR                 (15)                                            /*!< TS_GPT_RATE[31:28]General Purpose Timer Rate */

/******************  Bit definition for AS60XX_C5 register  *******************/
#define AS60XX_C5_HSC_DIV_MODE_Pos                  (0U)
#define AS60XX_C5_HSC_DIV_MODE_Msk                  (0x1UL << AS60XX_C5_HSC_DIV_MODE_Pos)           /*!< 0x00000001 */
#define AS60XX_C5_HSC_DIV_MODE_4MHZ                 (0)                                             /*!< High Speed CLock Divider mode recommended for HS_CLK = 4 MHz */
#define AS60XX_C5_HSC_DIV_MODE_8MHZ                 (1)                                             /*!< High Speed CLock Divider mode recommended for HS_CLK = 8 MHz */
#define AS60XX_C5_NOT_USED_1_Pos                    (1U)
#define AS60XX_C5_NOT_USED_1_Msk                    (0x1UL << AS60XX_C5_NOT_USED_1_Pos)             /*!< 0x00000002 */
#define AS60XX_C5_NOT_USED_1                        (0)                                             /*!< Mandatory setting: b0 */
#define AS60XX_C5_HSC_CLK_ST_Pos                    (2U)
#define AS60XX_C5_HSC_CLK_ST_Msk                    (0x07UL << AS60XX_C5_HSC_CLK_ST_Pos)            /*!< 0x0000001C */
#define AS60XX_C5_HSC_CLK_ST_74_USEC                (0)                                             /*!< HSC_CLK_ST[4:2]High-Speed Clock Settling Time */
#define AS60XX_C5_HSC_CLK_ST_104_USEC               (1)                                             /*!< HSC_CLK_ST[4:2]High-Speed Clock Settling Time */
#define AS60XX_C5_HSC_CLK_ST_135_USEC               (2)                                             /*!< HSC_CLK_ST[4:2]High-Speed Clock Settling Time */
#define AS60XX_C5_HSC_CLK_ST_196_USEC               (3)                                             /*!< HSC_CLK_ST[4:2]High-Speed Clock Settling Time */
#define AS60XX_C5_HSC_CLK_ST_257_USEC               (4)                                             /*!< HSC_CLK_ST[4:2]High-Speed Clock Settling Time */
#define AS60XX_C5_HSC_CLK_ST_379_USEC               (5)                                             /*!< HSC_CLK_ST[4:2]High-Speed Clock Settling Time */
#define AS60XX_C5_HSC_CLK_ST_502_USEC               (6)                                             /*!< HSC_CLK_ST[4:2]High-Speed Clock Settling Time */
#define AS60XX_C5_HSC_CLK_ST_5000_USEC              (7)                                             /*!< HSC_CLK_ST[4:2]High-Speed Clock Settling Time */
#define AS60XX_C5_NOT_USED_7_5_Pos                  (5U)
#define AS60XX_C5_NOT_USED_7_5_Msk                  (0x07UL << AS60XX_C5_NOT_USED_7_5_Pos)          /*!< 0x000000E0 */
#define AS60XX_C5_NOT_USED_7_5                      (1)                                             /*!< NOT_USED_7_5[7:5]Recommended setting: b001 */
#define AS60XX_C5_HSC_DIV_Pos                       (8U)
#define AS60XX_C5_HSC_DIV_Msk                       (0x1UL << AS60XX_C5_HSC_DIV_Pos)                /*!< 0x00000100 */
#define AS60XX_C5_HSC_DIV_4MHZ                      (0)                                             /*!< High-Speed Clock Divider recommended for HS_CLK = 4 MHz */
#define AS60XX_C5_HSC_DIV_8MHZ                      (1)                                             /*!< High-Speed Clock Divider recommended for HS_CLK = 8 MHz  */
#define AS60XX_C5_HSC_RATE_Pos                      (9U)
#define AS60XX_C5_HSC_RATE_Msk                      (0x07UL << AS60XX_C5_HSC_RATE_Pos)              /*!< 0x00000E00 */
#define AS60XX_C5_HSC_RATE_DISABLED                 (0)                                             /*!< HSC_RATE[11:9]High-Speed Clock Calibration Rate */
#define AS60XX_C5_HSC_RATE_EVERY_1                  (1)                                             /*!< HSC_RATE[11:9]High-Speed Clock Calibration Rate */
#define AS60XX_C5_HSC_RATE_EVERY_2                  (2)                                             /*!< HSC_RATE[11:9]High-Speed Clock Calibration Rate */
#define AS60XX_C5_HSC_RATE_EVERY_5                  (3)                                             /*!< HSC_RATE[11:9]High-Speed Clock Calibration Rate */
#define AS60XX_C5_HSC_RATE_EVERY_10                 (4)                                             /*!< HSC_RATE[11:9]High-Speed Clock Calibration Rate */
#define AS60XX_C5_HSC_RATE_EVERY_20                 (5)                                             /*!< HSC_RATE[11:9]High-Speed Clock Calibration Rate */
#define AS60XX_C5_HSC_RATE_EVERY_50                 (6)                                             /*!< HSC_RATE[11:9]High-Speed Clock Calibration Rate */
#define AS60XX_C5_HSC_RATE_EVERY_100                (7)                                             /*!< HSC_RATE[11:9]High-Speed Clock Calibration Rate */
#define AS60XX_C5_HSC_MODE_CPU_Pos                  (12U)
#define AS60XX_C5_HSC_MODE_CPU_Msk                  (0x1UL << AS60XX_C5_HSC_MODE_CPU_Pos)           /*!< 0x00001000 */
#define AS60XX_C5_HSC_MODE_CPU_4MHZ                 (0)                                             /*!< High-Speed Clock Mode CPU */
#define AS60XX_C5_HSC_MODE_CPU_1MHZ                 (1)                                             /*!< High-Speed Clock Mode CPU */
#define AS60XX_C5_VM_RATE_Pos                       (13U)
#define AS60XX_C5_VM_RATE_Msk                       (0x07UL << AS60XX_C5_VM_RATE_Pos)               /*!< 0x0000E000 */
#define AS60XX_C5_VM_RATE_DISABLED                  (0)                                             /*!< VM_RATE[15:13]VCC Voltage measurement rate */
#define AS60XX_C5_VM_RATE_EVERY_1                   (1)                                             /*!< VM_RATE[15:13]VCC Voltage measurement rate */
#define AS60XX_C5_VM_RATE_EVERY_2                   (2)                                             /*!< VM_RATE[15:13]VCC Voltage measurement rate */
#define AS60XX_C5_VM_RATE_EVERY_5                   (3)                                             /*!< VM_RATE[15:13]VCC Voltage measurement rate */
#define AS60XX_C5_VM_RATE_EVERY_10                  (4)                                             /*!< VM_RATE[15:13]VCC Voltage measurement rate */
#define AS60XX_C5_VM_RATE_EVERY_20                  (5)                                             /*!< VM_RATE[15:13]VCC Voltage measurement rate */
#define AS60XX_C5_VM_RATE_EVERY_50                  (6)                                             /*!< VM_RATE[15:13]VCC Voltage measurement rate */
#define AS60XX_C5_VM_RATE_EVERY_100                 (7)                                             /*!< VM_RATE[15:13]VCC Voltage measurement rate */
#define AS60XX_C5_LBD_TH_Pos                        (16U)
#define AS60XX_C5_LBD_TH_Msk                        (0x3FUL << AS60XX_C5_LBD_TH_Pos)                /*!< 0x003F0000 */
#define AS60XX_C5_LBD_TH_0                          (0x01)                                          /*!< LBD_TH[21:16]Low battery detection threshold, 2.15V + LBT_TH * 0.025V */
#define AS60XX_C5_LBD_TH_1                          (0x02)                                          /*!< LBD_TH[21:16]Low battery detection threshold, 2.15V + LBT_TH * 0.025V */
#define AS60XX_C5_LBD_TH_2                          (0x04)                                          /*!< LBD_TH[21:16]Low battery detection threshold, 2.15V + LBT_TH * 0.025V */
#define AS60XX_C5_LBD_TH_3                          (0x08)                                          /*!< LBD_TH[21:16]Low battery detection threshold, 2.15V + LBT_TH * 0.025V */
#define AS60XX_C5_LBD_TH_4                          (0x10)                                          /*!< LBD_TH[21:16]Low battery detection threshold, 2.15V + LBT_TH * 0.025V */
#define AS60XX_C5_LBD_TH_5                          (0x20)                                          /*!< LBD_TH[21:16]Low battery detection threshold, 2.15V + LBT_TH * 0.025V */
#define AS60XX_C5_TSV_UPD_MODE_Pos                  (22U)
#define AS60XX_C5_TSV_UPD_MODE_Msk                  (0x1UL << AS60XX_C5_TSV_UPD_MODE_Pos)           /*!< 0x00400000 */
#define AS60XX_C5_TSV_UPD_MODE_MANUAL               (0)                                             /*!< Time stamp update mode by TSV_UPD in SHR_EXC*/
#define AS60XX_C5_TSV_UPD_MODE_AUTOMATIC            (1)                                             /*!< Time stamp update mode automatic every measure cycle trigger*/
#define AS60XX_C5_BF_SEL_Pos                        (23U)
#define AS60XX_C5_BF_SEL_Msk                        (0x1UL << AS60XX_C5_BF_SEL_Pos)                 /*!< 0x00800000 */
#define AS60XX_C5_BF_SEL_50_HZ                      (0)                                             /*!< Base Frequency Select */
#define AS60XX_C5_BF_SEL_60_HZ                      (1)                                             /*!< Base Frequency Select */
#define AS60XX_C5_CHP_HV_SEL_Pos                    (24U)
#define AS60XX_C5_CHP_HV_SEL_Msk                    (0xFUL << AS60XX_C5_CHP_HV_SEL_Pos)             /*!< 0x0F000000 */
#define AS60XX_C5_CHP_HV_SEL                        (0)                                             /*!< Selection of charge pump voltage */
#define AS60XX_C5_NOT_USED_28_Pos                   (28U)
#define AS60XX_C5_NOT_USED_28_Msk                   (0x1UL << AS60XX_C5_NOT_USED_28_Pos)            /*!< 0x10000000 */
#define AS60XX_C5_NOT_USED_28                       (0)                                             /*!< Mandatory setting: b0 */
#define AS60XX_C5_TI_PATH_SEL_Pos                   (29U)
#define AS60XX_C5_TI_PATH_SEL_Msk                   (0x03UL << AS60XX_C5_TI_PATH_SEL_Pos)           /*!< 0x60000000 */
#define AS60XX_C5_TI_PATH_SEL_BUFFER_DISABLED       (0)                                             /*!< TI_PATH_SEL[30:29]Transducer Fire Buffer Impedance */
#define AS60XX_C5_TI_PATH_SEL_550_OHM_BUFFER        (1)                                             /*!< TI_PATH_SEL[30:29]Transducer Fire Buffer Impedance */
#define AS60XX_C5_TI_PATH_SEL_350_OHM_BUFFER        (2)                                             /*!< TI_PATH_SEL[30:29]Transducer Fire Buffer Impedance */
#define AS60XX_C5_TI_PATH_SEL_214_OHM_BUFFER        (3)                                             /*!< TI_PATH_SEL[30:29]Transducer Fire Buffer Impedance */
#define AS60XX_C5_NOT_USED_31_Pos                   (31U)
#define AS60XX_C5_NOT_USED_31_Msk                   (0x1UL << AS60XX_C5_NOT_USED_31_Pos)            /*!< 0x80000000 */
#define AS60XX_C5_NOT_USED_31                       (0)                                             /*!< Mandatory setting: b0 */

/******************  Bit definition for AS60XX_C6 register  *******************/
#define AS60XX_C6_MR_CT_Pos                         (0U)
#define AS60XX_C6_MR_CT_Msk                         (0x1FFFUL << AS60XX_C6_MR_CT_Pos)               /*!< 0x00001FFF */
#define AS60XX_C6_MR_CT_DISABLED                    (0)                                             /*!< MR_CT[12:0]Measure rate cycle time */
#define AS60XX_C6_MR_CT_0                           (0x0001)                                        /*!< MR_CT[12:0]Measure rate cycle time */
#define AS60XX_C6_MR_CT_1                           (0x0002)                                        /*!< MR_CT[12:0]Measure rate cycle time */
#define AS60XX_C6_MR_CT_2                           (0x0004)                                        /*!< MR_CT[12:0]Measure rate cycle time */
#define AS60XX_C6_MR_CT_3                           (0x0008)                                        /*!< MR_CT[12:0]Measure rate cycle time */
#define AS60XX_C6_MR_CT_4                           (0x0010)                                        /*!< MR_CT[12:0]Measure rate cycle time */
#define AS60XX_C6_MR_CT_5                           (0x0020)                                        /*!< MR_CT[12:0]Measure rate cycle time */
#define AS60XX_C6_MR_CT_6                           (0x0040)                                        /*!< MR_CT[12:0]Measure rate cycle time */
#define AS60XX_C6_MR_CT_7                           (0x0080)                                        /*!< MR_CT[12:0]Measure rate cycle time */
#define AS60XX_C6_MR_CT_8                           (0x0100)                                        /*!< MR_CT[12:0]Measure rate cycle time */
#define AS60XX_C6_MR_CT_9                           (0x0200)                                        /*!< MR_CT[12:0]Measure rate cycle time */
#define AS60XX_C6_MR_CT_10                          (0x0400)                                        /*!< MR_CT[12:0]Measure rate cycle time */
#define AS60XX_C6_MR_CT_11                          (0x0800)                                        /*!< MR_CT[12:0]Measure rate cycle time */
#define AS60XX_C6_MR_CT_12                          (0x1000)                                        /*!< MR_CT[12:0]Measure rate cycle time */
#define AS60XX_C6_TS_MCM_Pos                        (13U)
#define AS60XX_C6_TS_MCM_Msk                        (0x1UL << AS60XX_C6_TS_MCM_Pos)                 /*!< 0x00002000 */
#define AS60XX_C6_TS_MCM_SAME_PHASE                 (0)                                             /*!< Task Sequencer Measure Cycle Mode same phase for USM and TM*/
#define AS60XX_C6_TS_MCM_DIFF_PHASE                 (1)                                             /*!< Task Sequencer Measure Cycle Mode different phases for USM and TM*/
#define AS60XX_C6_TS_PP_T_EN_Pos                    (14U)
#define AS60XX_C6_TS_PP_T_EN_Msk                    (0x1UL << AS60XX_C6_TS_PP_T_EN_Pos)             /*!< 0x00004000 */
#define AS60XX_C6_TS_PP_T_EN                        (1)                                             /*!< Enables final post processing T */
#define AS60XX_C6_TS_PP_F_EN_Pos                    (15U)
#define AS60XX_C6_TS_PP_F_EN_Msk                    (0x1UL << AS60XX_C6_TS_PP_F_EN_Pos)             /*!< 0x00008000 */
#define AS60XX_C6_TS_PP_F_EN                        (1)                                             /*!< Enables post processing F */
#define AS60XX_C6_TS_PP_MODE_Pos                    (16U)
#define AS60XX_C6_TS_PP_MODE_Msk                    (0x1UL << AS60XX_C6_TS_PP_MODE_Pos)             /*!< 0x00010000 */
#define AS60XX_C6_TS_PP_MODE_EVERY_TASK             (0)                                             /*!< Post processing mode requested with every task sequencer trigger */
#define AS60XX_C6_TS_PP_MODE_ON_MEASUREMENT         (1)                                             /*!< Post processing mode only requested if a measurement task is requested */
#define AS60XX_C6_TS_CST_RATE_Pos                   (17U)
#define AS60XX_C6_TS_CST_RATE_Msk                   (0x07UL << AS60XX_C6_TS_CST_RATE_Pos)           /*!< 0x000E0000 */
#define AS60XX_C6_TS_CST_RATE_DISABLED              (0)                                             /*!< TS_CST_RATE[19:17]Firmware Check(sum) Timer Rate */
#define AS60XX_C6_TS_CST_RATE_1_HR                  (1)                                             /*!< TS_CST_RATE[19:17]Firmware Check(sum) Timer Rate */
#define AS60XX_C6_TS_CST_RATE_2_HR                  (2)                                             /*!< TS_CST_RATE[19:17]Firmware Check(sum) Timer Rate */
#define AS60XX_C6_TS_CST_RATE_6_HR                  (3)                                             /*!< TS_CST_RATE[19:17]Firmware Check(sum) Timer Rate */
#define AS60XX_C6_TS_CST_RATE_24_HR                 (4)                                             /*!< TS_CST_RATE[19:17]Firmware Check(sum) Timer Rate */
#define AS60XX_C6_TS_CST_RATE_48_HR                 (5)                                             /*!< TS_CST_RATE[19:17]Firmware Check(sum) Timer Rate */
#define AS60XX_C6_TS_CST_RATE_96_HR                 (6)                                             /*!< TS_CST_RATE[19:17]Firmware Check(sum) Timer Rate */
#define AS60XX_C6_TS_CST_RATE_168_HR                (7)                                             /*!< TS_CST_RATE[19:17]Firmware Check(sum) Timer Rate */
#define AS60XX_C6_TS_NVR_RATE_Pos                   (20U)
#define AS60XX_C6_TS_NVR_RATE_Msk                   (0xFUL << AS60XX_C6_TS_NVR_RATE_Pos)            /*!< 0x00F00000 */
#define AS60XX_C6_TS_NVR_RATE_DISABLED              (0)
#define AS60XX_C6_TS_NVR_RATE_0                     (0x1)
#define AS60XX_C6_TS_NVR_RATE_1                     (0x2)
#define AS60XX_C6_TS_NVR_RATE_2                     (0x4)
#define AS60XX_C6_TS_NVR_RATE_3                     (0x8)
#define AS60XX_C6_NOT_USED_25_24_Pos                (24U)
#define AS60XX_C6_NOT_USED_25_24_Msk                (0x03UL << AS60XX_C6_NOT_USED_25_24_Pos)        /*!< 0x03000000 */
#define AS60XX_C6_NOT_USED_25_24                    (1)                                             /*!< NOT_USED_25_24[25:24]. Mandatory setting 0b01 */
#define AS60XX_C6_TS_CHP_MODE_Pos                   (26U)
#define AS60XX_C6_TS_CHP_MODE_Msk                   (0x1FUL << AS60XX_C6_TS_CHP_MODE_Pos)           /*!< 0x0C000000 */
#define AS60XX_C6_TS_CHP_MODE_DISABLED              (0)                                             /*!< Charge Pump Mode, Charge Pump disabled */
#define AS60XX_C6_TS_CHP_MODE_ENABLED               (2)                                             /*!< Charge Pump Mode, Charge Pump enabled */
#define AS60XX_C6_TS_CHP_WT_Pos                     (28U)
#define AS60XX_C6_TS_CHP_WT_Msk                     (0x1FUL << AS60XX_C6_TS_CHP_WT_Pos)             /*!< 0x30000000 */
#define AS60XX_C6_TS_CHP_WT_520_USEC                (0)                                             /*!< Charge Pump Wait Time, 0.52 ms */
#define AS60XX_C6_TS_CHP_WT_1000_USEC               (1)                                             /*!< Charge Pump Wait Time, 1 ms (recommended) */
#define AS60XX_C6_TS_CHP_WT_2500_USEC               (2)                                             /*!< Charge Pump Wait Time, 2.5 ms */
#define AS60XX_C6_NOT_USED_30_Pos                   (30U)
#define AS60XX_C6_NOT_USED_30_Msk                   (0x1FUL << AS60XX_C6_NOT_USED_30_Pos)           /*!< 0x40000000 */
#define AS60XX_C6_NOT_USED_30                       (0)                                             /*!< NOT_USED_30. Mandatory setting 0b0 */
#define AS60XX_C6_TS_CST_MODE_Pos                   (31U)
#define AS60XX_C6_TS_CST_MODE_Msk                   (0x1UL << AS60XX_C6_TS_CST_MODE_Pos)            /*!< 0x80000000 */
#define AS60XX_C6_TS_CST_MODE_ALWAYS                (0)                                             /*!< Checksum Handling Mode, performed as soon as timer request occurs */
#define AS60XX_C6_TS_CST_MODE_IF_FREE               (1)                                             /*!< Checksum Handling Mode, only performed if no TPM or USM task is requested */

/******************  Bit definition for AS60XX_C7 register  *******************/
#define AS60XX_C7_TM_RATE_Pos                       (0U)
#define AS60XX_C7_TM_RATE_Msk                       (0x03FFUL << AS60XX_C7_TM_RATE_Pos)             /*!< 0x000003FF */
#define AS60XX_C7_TM_RATE_DISABLED                  (0)
#define AS60XX_C7_TM_RATE_0                         (0x001)
#define AS60XX_C7_TM_RATE_1                         (0x002)
#define AS60XX_C7_TM_RATE_2                         (0x004)
#define AS60XX_C7_TM_RATE_3                         (0x008)
#define AS60XX_C7_TM_RATE_4                         (0x010)
#define AS60XX_C7_TM_RATE_5                         (0x020)
#define AS60XX_C7_TM_RATE_6                         (0x040)
#define AS60XX_C7_TM_RATE_7                         (0x080)
#define AS60XX_C7_TM_RATE_8                         (0x100)
#define AS60XX_C7_TM_RATE_9                         (0x200)
#define AS60XX_C7_TPM_PAUSE_Pos                     (10U)
#define AS60XX_C7_TPM_PAUSE_Msk                     (0x07UL << AS60XX_C7_TPM_PAUSE_Pos)             /*!< 0x00001C00 */
#define AS60XX_C7_TPM_PAUSE_DISABLED                (0)                                             /*!< TPM_PAUSE[12:10]Pause time between 2 temperature measurements */
#define AS60XX_C7_TPM_PAUSE_0                       (0x1)                                           /*!< TPM_PAUSE[12:10]Pause time between 2 temperature measurements */
#define AS60XX_C7_TPM_PAUSE_1                       (0x2)                                           /*!< TPM_PAUSE[12:10]Pause time between 2 temperature measurements */                                           /*!< TPM_PAUSE[12:10]Pause time between 2 temperature measurements */
#define AS60XX_C7_TPM_PAUSE_2                       (0x4)                                           /*!< TPM_PAUSE[12:10]Pause time between 2 temperature measurements */
#define AS60XX_C7_TM_MODE_Pos                       (13U)
#define AS60XX_C7_TM_MODE_Msk                       (0x07UL << AS60XX_C7_TM_MODE_Pos)               /*!< 0x0000E000 */
#define AS60XX_C7_TM_MODE_OFF                       (0)                                             /*!< TM_MODE[15:13]Temperature Measurement Mode */
#define AS60XX_C7_TM_MODE_0                         (0x1)                                           /*!< TM_MODE[15:13]Temperature Measurement Mode */
#define AS60XX_C7_TM_MODE_1                         (0x2)                                           /*!< TM_MODE[15:13]Temperature Measurement Mode */
#define AS60XX_C7_TM_MODE_2                         (0x4)                                           /*!< TM_MODE[15:13]Temperature Measurement Mode */
#define AS60XX_C7_NOT_USED_16_Pos                   (16U)
#define AS60XX_C7_NOT_USED_16_Msk                   (0x1UL << AS60XX_C7_NOT_USED_16_Pos)            /*!< 0x00010000 */
#define AS60XX_C7_NOT_USED_16                       (0)                                             /*!< Mandatory setting: b0 */
#define AS60XX_C7_TPM_PORT_MODE_Pos                 (17U)
#define AS60XX_C7_TPM_PORT_MODE_Msk                 (0x1UL << AS60XX_C7_TPM_PORT_MODE_Pos)          /*!< 0x00020000 */
#define AS60XX_C7_TPM_PORT_MODE_UNUSED_TO_GND       (0)                                             /*!< Temperature Measurement Port Mode, inactive ports pulled to GND */
#define AS60XX_C7_TPM_PORT_MODE_UNUSED_TO_HIGHZ     (0x00000001 << AS60XX_C7_TM_MODE_Pos)           /*!< Temperature Measurement Port Mode, inactive ports pulled to High Z */
#define AS60XX_C7_TM_PORT_ORDER_Pos                 (18U)
#define AS60XX_C7_TM_PORT_ORDER_Msk                 (0x03UL << AS60XX_C7_TM_PORT_ORDER_Pos)         /*!< 0x000C0000 */
#define AS60XX_C7_TM_PORT_ORDER_1ST_MEASUREMENT     (1)                                             /*!< TM_PORT_ORDER[19:18]Temperature Measurement Port Order, 1st measurement: default order */
#define AS60XX_C7_TM_PORT_ORDER_2ND_MEASUREMENT     (2)                                             /*!< TM_PORT_ORDER[19:18]Temperature Measurement Port Order, 2nd measurement */
#define AS60XX_C7_TPM_CLOAD_TRIM_Pos                (20U)
#define AS60XX_C7_TPM_CLOAD_TRIM_Msk                (0x03UL << AS60XX_C7_TPM_CLOAD_TRIM_Pos)        /*!< 0x00300000 */
#define AS60XX_C7_TPM_CLOAD_TRIM_0                  (1)                                             /*!< TPM_CLOAD_TRIM[21:20]Temperature Measurement Load Trim */
#define AS60XX_C7_TPM_CLOAD_TRIM_1                  (2)                                             /*!< TPM_CLOAD_TRIM[21:20]Temperature Measurement Load Trim, 3.95 us, recommended */
#define AS60XX_C7_TPM_CYCLE_SEL_Pos                 (22U)
#define AS60XX_C7_TPM_CYCLE_SEL_Msk                 (0x1UL << AS60XX_C7_TPM_CYCLE_SEL_Pos)          /*!< 0x00400000 */
#define AS60XX_C7_TPM_CYCLE_SEL_512_USEC            (0)                                             /*!< Temperature Measurement Cycle Select, 512 microseconds*/
#define AS60XX_C7_TPM_CYCLE_SEL_1024_USEC           (1)                                             /*!< Temperature Measurement Cycle Select, 1024 microseconds */
#define AS60XX_C7_TPM_FAKE_NO_Pos                   (23U)
#define AS60XX_C7_TPM_FAKE_NO_Msk                   (0x1UL << AS60XX_C7_TPM_FAKE_NO_Pos)            /*!< 0x00800000 */
#define AS60XX_C7_TPM_FAKE_NO_2                     (0)                                             /*!< Number of Fake measurements, 2 */
#define AS60XX_C7_TPM_FAKE_NO_8                     (1)                                             /*!< Number of Fake measurements, 8 */
#define AS60XX_C7_NOT_USED_31_24_Pos                (24U)
#define AS60XX_C7_NOT_USED_31_24_Msk                (0xFFUL << AS60XX_C7_NOT_USED_31_24_Pos)        /*!< 0xFF000000 */
#define AS60XX_C7_NOT_USED_31_24                    (0)                                             /*!< NOT_USED_31_24[31:24]Mandatory setting: h00 */

/******************  Bit definition for AS60XX_C8 register  *******************/
#define AS60XX_C8_USM_PAUSE_Pos                     (0U)
#define AS60XX_C8_USM_PAUSE_Msk                     (0x07UL << AS60XX_C8_USM_PAUSE_Pos)             /*!< 0x00000007 */
#define AS60XX_C8_USM_PAUSE_DISABLED                (0)                                             /*!< USM_PAUSE[2:0]Pause time between two ultrasonic measurements */
#define AS60XX_C8_USM_PAUSE_0                       (0x1)                                           /*!< USM_PAUSE[2:0]Pause time between two ultrasonic measurements */
#define AS60XX_C8_USM_PAUSE_1                       (0x2)                                           /*!< USM_PAUSE[2:0]Pause time between two ultrasonic measurements */
#define AS60XX_C8_USM_PAUSE_2                       (0x4)                                           /*!< USM_PAUSE[2:0]Pause time between two ultrasonic measurements */
#define AS60XX_C8_TI_PGA_AZ_DIS_Pos                 (3U)
#define AS60XX_C8_TI_PGA_AZ_DIS_Msk                 (0x1UL << AS60XX_C8_TI_PGA_AZ_DIS_Pos)          /*!< 0x00000008 */
#define AS60XX_C8_TI_PGA_AZ_DIS_ENABLED             (0)                                             /*!< PGA Auto-zero Disable, PGA Auto-zero process as defined */
#define AS60XX_C8_TI_PGA_AZ_DIS_DISABLED            (1)                                             /*!< PGA Auto-zero Disable, PGA Auto-zero disabled */
#define AS60XX_C8_USM_DIR_MODE_Pos                  (4U)
#define AS60XX_C8_USM_DIR_MODE_Msk                  (0x03UL << AS60XX_C8_USM_DIR_MODE_Pos)          /*!< 0x00000030 */
#define AS60XX_C8_USM_DIR_MODE_VIA_UP               (0)                                             /*!< USM_DIR_MODE[5:4]Ultrasonic Measurement Direction Mode always starting firing via UP-buffer */
#define AS60XX_C8_USM_DIR_MODE_VIA_DN               (1)                                             /*!< USM_DIR_MODE[5:4]Ultrasonic Measurement Direction Mode always starting firing via DOWN-buffer */
#define AS60XX_C8_USM_DIR_MODE_VIA_TOGGLE           (2)                                             /*!< USM_DIR_MODE[5:4]Ultrasonic Measurement Direction Mode toggle direction every measurement*/
#define AS60XX_C8_USM_NOISE_MASK_WIN_Pos            (6U)
#define AS60XX_C8_USM_NOISE_MASK_WIN_Msk            (0x03FFUL << AS60XX_C8_USM_NOISE_MASK_WIN_Pos)  /*!< 0x0000FFC0 */
#define AS60XX_C8_USM_NOISE_MASK_WIN_0              (0x001)                                         /*!< USM_NOISE_MASK_WIN[15:6]Noise Mask Window */
#define AS60XX_C8_USM_NOISE_MASK_WIN_1              (0x002)                                         /*!< USM_NOISE_MASK_WIN[15:6]Noise Mask Window */
#define AS60XX_C8_USM_NOISE_MASK_WIN_2              (0x004)                                         /*!< USM_NOISE_MASK_WIN[15:6]Noise Mask Window */
#define AS60XX_C8_USM_NOISE_MASK_WIN_3              (0x008)                                         /*!< USM_NOISE_MASK_WIN[15:6]Noise Mask Window */
#define AS60XX_C8_USM_NOISE_MASK_WIN_4              (0x010)                                         /*!< USM_NOISE_MASK_WIN[15:6]Noise Mask Window */
#define AS60XX_C8_USM_NOISE_MASK_WIN_5              (0x020)                                         /*!< USM_NOISE_MASK_WIN[15:6]Noise Mask Window */
#define AS60XX_C8_USM_NOISE_MASK_WIN_6              (0x040)                                         /*!< USM_NOISE_MASK_WIN[15:6]Noise Mask Window */
#define AS60XX_C8_USM_NOISE_MASK_WIN_7              (0x080)                                         /*!< USM_NOISE_MASK_WIN[15:6]Noise Mask Window */
#define AS60XX_C8_USM_NOISE_MASK_WIN_8              (0x100)                                         /*!< USM_NOISE_MASK_WIN[15:6]Noise Mask Window */
#define AS60XX_C8_USM_NOISE_MASK_WIN_9              (0x200)                                         /*!< USM_NOISE_MASK_WIN[15:6]Noise Mask Window */
#define AS60XX_C8_USM_TO_Pos                        (16U)
#define AS60XX_C8_USM_TO_Msk                        (0x03UL << AS60XX_C8_USM_TO_Pos)                /*!< 0x00030000 */
#define AS60XX_C8_USM_TO_128_USEC                   (0)                                             /*!< USM_TO[17:16]Timeout */
#define AS60XX_C8_USM_TO_256_USEC                   (1)                                             /*!< USM_TO[17:16]Timeout */
#define AS60XX_C8_USM_TO_1024_USEC                  (2)                                             /*!< USM_TO[17:16]Timeout */
#define AS60XX_C8_USM_TO_4096_USEC                  (3)                                             /*!< USM_TO[17:16]Timeout */
#define AS60XX_C8_NOT_USED_18_Pos                   (18U)
#define AS60XX_C8_NOT_USED_18_Msk                   (0x1UL << AS60XX_C8_NOT_USED_18_Pos)            /*!< 0x00040000 */
#define AS60XX_C8_NOT_USED_18                       (0)                                             /*!< Mandatory setting: b0 */
#define AS60XX_C8_USM_RLS_MODE_Pos                  (19U)
#define AS60XX_C8_USM_RLS_MODE_Msk                  (0x1UL << AS60XX_C8_USM_RLS_MODE_Pos)           /*!< 0x00080000 */
#define AS60XX_C8_USM_RLS_MODE_FIRST_HIT_ONLY       (0)                                             /*!< Select mode for multihit start release, derived by detection of First Hit Level only */
#define AS60XX_C8_USM_RLS_MODE_COMBINED             (1)                                             /*!< Select mode for multihit start release, derived by Ultrasonic Release Delay only or in combination by First Hit Level detection */
#define AS60XX_C8_ZCC_RATE_Pos                      (20U)
#define AS60XX_C8_ZCC_RATE_Msk                      (0x07UL << AS60XX_C8_ZCC_RATE_Pos)              /*!< 0x00700000 */
#define AS60XX_C8_ZCC_RATE_DISABLED                 (0)                                             /*!< ZCC_RATE[22:20]Zero Cross Calibration Rate */
#define AS60XX_C8_ZCC_RATE_EVERY_1                  (1)                                             /*!< ZCC_RATE[22:20]Zero Cross Calibration Rate */
#define AS60XX_C8_ZCC_RATE_EVERY_2                  (2)                                             /*!< ZCC_RATE[22:20]Zero Cross Calibration Rate */
#define AS60XX_C8_ZCC_RATE_EVERY_5                  (3)                                             /*!< ZCC_RATE[22:20]Zero Cross Calibration Rate */
#define AS60XX_C8_ZCC_RATE_EVERY_10                 (4)                                             /*!< ZCC_RATE[22:20]Zero Cross Calibration Rate */
#define AS60XX_C8_ZCC_RATE_EVERY_20                 (5)                                             /*!< ZCC_RATE[22:20]Zero Cross Calibration Rate */
#define AS60XX_C8_ZCC_RATE_EVERY_50                 (6)                                             /*!< ZCC_RATE[22:20]Zero Cross Calibration Rate */
#define AS60XX_C8_ZCC_RATE_EVERY_100                (7)                                             /*!< ZCC_RATE[22:20]Zero Cross Calibration Rate */
#define AS60XX_C8_NOT_USED_29_23_Pos                (23U)
#define AS60XX_C8_NOT_USED_29_23_Msk                (0x1FFUL << AS60XX_C8_NOT_USED_29_23_Pos)       /*!< 0x3F800000 */
#define AS60XX_C8_NOT_USED_29_23                    (0)                                             /*!< NOT_USED_29_23[29:23]Not used */
#define AS60XX_C8_TI_PGA_CON_MODE_Pos               (30U)
#define AS60XX_C8_TI_PGA_CON_MODE_Msk               (0x3UL << AS60XX_C8_TI_PGA_CON_MODE_Pos)        /*!< 0xC0000000 */
#define AS60XX_C8_TI_PGA_CON_MODE_NO_EXTERNAL       (0)                                             /*!< Connection of PGA filter, without external filter */
#define AS60XX_C8_TI_PGA_CON_MODE_WITH_EXTERNAL     (2)                                             /*!< Connection of PGA filter, external filter connected */

/******************  Bit definition for AS60XX_C9 register  *******************/
#define AS60XX_C9_FBG_CLK_DIV_Pos                   (0U)
#define AS60XX_C9_FBG_CLK_DIV_Msk                   (0x07FUL << AS60XX_C9_FBG_CLK_DIV_Pos)          /*!< 0x0000007F */
#define AS60XX_C9_FBG_CLK_DIV_0                     (0x01)                                          /*!< FBG_CLK_DIV[6:0]Clock divider for fire burst generator */
#define AS60XX_C9_FBG_CLK_DIV_1                     (0x02)                                          /*!< FBG_CLK_DIV[6:0]Clock divider for fire burst generator */
#define AS60XX_C9_FBG_CLK_DIV_2                     (0x04)                                          /*!< FBG_CLK_DIV[6:0]Clock divider for fire burst generator */
#define AS60XX_C9_FBG_CLK_DIV_3                     (0x08)                                          /*!< FBG_CLK_DIV[6:0]Clock divider for fire burst generator */
#define AS60XX_C9_FBG_CLK_DIV_4                     (0x10)                                          /*!< FBG_CLK_DIV[6:0]Clock divider for fire burst generator */
#define AS60XX_C9_FBG_CLK_DIV_5                     (0x20)                                          /*!< FBG_CLK_DIV[6:0]Clock divider for fire burst generator */
#define AS60XX_C9_FBG_CLK_DIV_6                     (0x40)                                          /*!< FBG_CLK_DIV[6:0]Clock divider for fire burst generator */
#define AS60XX_C9_FBG_MODE_Pos                      (7U)
#define AS60XX_C9_FBG_MODE_Msk                      (0x1UL << AS60XX_C9_FBG_MODE_Pos)               /*!< 0x00000080 */
#define AS60XX_C9_FBG_MODE_LOW_PHASE_INSERTION      (0)                                             /*!< Fire Burst Generator Mode */
#define AS60XX_C9_FBG_MODE_HIGH_PHASE_INSERTION     (1)                                             /*!< Fire Burst Generator Mode */
#define AS60XX_C9_FBG_PHASE_INS_Pos                 (8U)
#define AS60XX_C9_FBG_PHASE_INS_Msk                 (0xFFUL << AS60XX_C9_FBG_PHASE_INS_Pos)         /*!< 0x0000FF00 */
#define AS60XX_C9_FBG_PHASE_INS_0                   (0x01)                                          /*!< FBG_PHASE_INS[15:8]Fire Burst Generator, Phase Insertion */
#define AS60XX_C9_FBG_PHASE_INS_1                   (0x02)                                          /*!< FBG_PHASE_INS[15:8]Fire Burst Generator, Phase Insertion */
#define AS60XX_C9_FBG_PHASE_INS_2                   (0x04)                                          /*!< FBG_PHASE_INS[15:8]Fire Burst Generator, Phase Insertion */
#define AS60XX_C9_FBG_PHASE_INS_3                   (0x08)                                          /*!< FBG_PHASE_INS[15:8]Fire Burst Generator, Phase Insertion */
#define AS60XX_C9_FBG_PHASE_INS_4                   (0x10)                                          /*!< FBG_PHASE_INS[15:8]Fire Burst Generator, Phase Insertion */
#define AS60XX_C9_FBG_PHASE_INS_5                   (0x20)                                          /*!< FBG_PHASE_INS[15:8]Fire Burst Generator, Phase Insertion */
#define AS60XX_C9_FBG_PHASE_INS_6                   (0x40)                                          /*!< FBG_PHASE_INS[15:8]Fire Burst Generator, Phase Insertion */
#define AS60XX_C9_FBG_PHASE_INS_7                   (0x80)                                          /*!< FBG_PHASE_INS[15:8]Fire Burst Generator, Phase Insertion */
#define AS60XX_C9_FBG_BURST_PRE_Pos                 (16U)
#define AS60XX_C9_FBG_BURST_PRE_Msk                 (0x3FUL << AS60XX_C9_FBG_BURST_PRE_Pos)         /*!< 0x003F0000 */
#define AS60XX_C9_FBG_BURST_PRE_0                   (0x01)                                          /*!< FBG_BURST_PRE[21:16]Fire Burst Generator, pre-burst */
#define AS60XX_C9_FBG_BURST_PRE_1                   (0x02)                                          /*!< FBG_BURST_PRE[21:16]Fire Burst Generator, pre-burst */
#define AS60XX_C9_FBG_BURST_PRE_2                   (0x04)                                          /*!< FBG_BURST_PRE[21:16]Fire Burst Generator, pre-burst */
#define AS60XX_C9_FBG_BURST_PRE_3                   (0x08)                                          /*!< FBG_BURST_PRE[21:16]Fire Burst Generator, pre-burst */
#define AS60XX_C9_FBG_BURST_PRE_4                   (0x10)                                          /*!< FBG_BURST_PRE[21:16]Fire Burst Generator, pre-burst */
#define AS60XX_C9_FBG_BURST_PRE_5                   (0x20)                                          /*!< FBG_BURST_PRE[21:16]Fire Burst Generator, pre-burst */
#define AS60XX_C9_FBG_BURST_POST_Pos                (22U)
#define AS60XX_C9_FBG_BURST_POST_Msk                (0x3FUL << AS60XX_C9_FBG_BURST_POST_Pos)        /*!< 0x0FC00000 */
#define AS60XX_C9_FBG_BURST_POST_0                  (0x01)                                          /*!< FBG_BURST_POST[27:22]Fire Burst Generator, post-burst */
#define AS60XX_C9_FBG_BURST_POST_1                  (0x02)                                          /*!< FBG_BURST_POST[27:22]Fire Burst Generator, post-burst */
#define AS60XX_C9_FBG_BURST_POST_2                  (0x04)                                          /*!< FBG_BURST_POST[27:22]Fire Burst Generator, post-burst */
#define AS60XX_C9_FBG_BURST_POST_3                  (0x08)                                          /*!< FBG_BURST_POST[27:22]Fire Burst Generator, post-burst */
#define AS60XX_C9_FBG_BURST_POST_4                  (0x10)                                          /*!< FBG_BURST_POST[27:22]Fire Burst Generator, post-burst */
#define AS60XX_C9_FBG_BURST_POST_5                  (0x20)                                          /*!< FBG_BURST_POST[27:22]Fire Burst Generator, post-burst */
#define AS60XX_C9_NOT_USED_28_Pos                   (28U)
#define AS60XX_C9_NOT_USED_28_Msk                   (0x1UL << AS60XX_C9_NOT_USED_28_Pos)            /*!< 0x10000000 */
#define AS60XX_C9_NOT_USED_28                       (0)                                             /*!< Mandatory setting: b0 */
#define AS60XX_C9_NOT_USED_29_Pos                   (29U)
#define AS60XX_C9_NOT_USED_29_Msk                   (0x1UL << AS60XX_C9_NOT_USED_29_Pos)            /*!< 0x20000000 */
#define AS60XX_C9_NOT_USED_29                       (1)                                             /*!< Mandatory setting: b1 */
#define AS60XX_C9_TOF_HIT_MODE_Pos                  (30U)
#define AS60XX_C9_TOF_HIT_MODE_Msk                  (0x1UL << AS60XX_C9_TOF_HIT_MODE_Pos)           /*!< 0x40000000 */
#define AS60XX_C9_TOF_HIT_MODE_AS60XX               (0)                                             /*!< TOF data in FDB according to Multi-Hit Mode, 10 TOF in 3 bundles */
#define AS60XX_C9_TOF_HIT_MODE_GP30                 (1)                                             /*!< TOF data in FDB according to Multi-Hit Mode, 10 TOF in 1 bundle */
#define AS60XX_C9_NOT_USED_31_Pos                   (31U)
#define AS60XX_C9_NOT_USED_31_Msk                   (0x1UL << AS60XX_C9_NOT_USED_31_Pos)            /*!< 0x80000000 */
#define AS60XX_C9_NOT_USED_31                       (0)                                             /*!< Mandatory setting: b0 */

/******************  Bit definition for AS60XX_CA register  *******************/
#define AS60XX_CA_NOT_USED_0_Pos                    (0U)
#define AS60XX_CA_NOT_USED_0_Msk                    (0x1UL << AS60XX_CA_NOT_USED_0_Pos)             /*!< 0x00000001 */
#define AS60XX_CA_NOT_USED_0                        (0)                                             /*!< Mandatory setting: b0 */
#define AS60XX_CA_TOF_HIT_START_Pos                 (1U)
#define AS60XX_CA_TOF_HIT_START_Msk                 (0x1FUL << AS60XX_CA_TOF_HIT_START_Pos)         /*!< 0x0000003E */
#define AS60XX_CA_TOF_HIT_START_0                   (0x01)                                          /*!< TOF_HIT_START[5:1]Defines number of detected hits (including first hit) */
#define AS60XX_CA_TOF_HIT_START_1                   (0x02)                                          /*!< TOF_HIT_START[5:1]Defines number of detected hits (including first hit) */
#define AS60XX_CA_TOF_HIT_START_2                   (0x04)                                          /*!< TOF_HIT_START[5:1]Defines number of detected hits (including first hit) */
#define AS60XX_CA_TOF_HIT_START_3                   (0x08)                                          /*!< TOF_HIT_START[5:1]Defines number of detected hits (including first hit) */
#define AS60XX_CA_TOF_HIT_START_4                   (0x10)                                          /*!< TOF_HIT_START[5:1]Defines number of detected hits (including first hit) */
#define AS60XX_CA_TOF_HIT_IGN_Pos                   (6U)
#define AS60XX_CA_TOF_HIT_IGN_Msk                   (0x03UL << AS60XX_CA_TOF_HIT_IGN_Pos)           /*!< 0x000000C0 */
#define AS60XX_CA_TOF_HIT_IGN_0_HITS                (0)                                             /*!< TOF_HIT_IGN[7:6]Number of multi hits ignored between two hits taken for TDC measurement */
#define AS60XX_CA_TOF_HIT_IGN_1_HITS                (1)                                             /*!< TOF_HIT_IGN[7:6]Number of multi hits ignored between two hits taken for TDC measurement */
#define AS60XX_CA_TOF_HIT_IGN_2_HITS                (2)                                             /*!< TOF_HIT_IGN[7:6]Number of multi hits ignored between two hits taken for TDC measurement */
#define AS60XX_CA_TOF_HIT_IGN_3_HITS                (3)                                             /*!< TOF_HIT_IGN[7:6]Number of multi hits ignored between two hits taken for TDC measurement */
#define AS60XX_CA_TOF_HIT_SUM_NO_Pos                (8U)
#define AS60XX_CA_TOF_HIT_SUM_NO_Msk                (0x1FUL << AS60XX_CA_TOF_HIT_SUM_NO_Pos)        /*!< 0x00001F00 */
#define AS60XX_CA_TOF_HIT_SUM_NO_0                  (0x01)                                          /*!< TOF_HIT_SUM_NO[12:8]Number of hits taken for sum value of TOF measurement */
#define AS60XX_CA_TOF_HIT_SUM_NO_1                  (0x02)                                          /*!< TOF_HIT_SUM_NO[12:8]Number of hits taken for sum value of TOF measurement */
#define AS60XX_CA_TOF_HIT_SUM_NO_2                  (0x04)                                          /*!< TOF_HIT_SUM_NO[12:8]Number of hits taken for sum value of TOF measurement */
#define AS60XX_CA_TOF_HIT_SUM_NO_3                  (0x08)                                          /*!< TOF_HIT_SUM_NO[12:8]Number of hits taken for sum value of TOF measurement */
#define AS60XX_CA_TOF_HIT_SUM_NO_4                  (0x10)                                          /*!< TOF_HIT_SUM_NO[12:8]Number of hits taken for sum value of TOF measurement */
#define AS60XX_CA_TOF_HIT_END_Pos                   (13U)
#define AS60XX_CA_TOF_HIT_END_Msk                   (0x07FUL << AS60XX_CA_TOF_HIT_END_Pos)          /*!< 0x000FE000 */
#define AS60XX_CA_TOF_HIT_END_0                     (0x01)                                          /*!< TOF_HIT_END[19:13]TOF Hits stored to frontend data buffer */
#define AS60XX_CA_TOF_HIT_END_1                     (0x02)                                          /*!< TOF_HIT_END[19:13]TOF Hits stored to frontend data buffer */
#define AS60XX_CA_TOF_HIT_END_2                     (0x04)                                          /*!< TOF_HIT_END[19:13]TOF Hits stored to frontend data buffer */
#define AS60XX_CA_TOF_HIT_END_3                     (0x08)                                          /*!< TOF_HIT_END[19:13]TOF Hits stored to frontend data buffer */
#define AS60XX_CA_TOF_HIT_END_4                     (0x10)                                          /*!< TOF_HIT_END[19:13]TOF Hits stored to frontend data buffer */
#define AS60XX_CA_TOF_HIT_END_5                     (0x20)                                          /*!< TOF_HIT_END[19:13]TOF Hits stored to frontend data buffer */
#define AS60XX_CA_TOF_HIT_END_6                     (0x40)                                          /*!< TOF_HIT_END[19:13]TOF Hits stored to frontend data buffer */
#define AS60XX_CA_NOT_USED_21_20_Pos                (20U)
#define AS60XX_CA_NOT_USED_21_20_Msk                (0x03UL << AS60XX_CA_NOT_USED_21_20_Pos)        /*!< 0x00300000 */
#define AS60XX_CA_NOT_USED_21_20                    (0)                                             /*!< NOT_USED_21_20[21:20]Mandatory setting: b00 */
#define AS60XX_CA_TOF_EDGE_MODE_Pos                 (22U)
#define AS60XX_CA_TOF_EDGE_MODE_Msk                 (0x03UL << AS60XX_CA_TOF_EDGE_MODE_Pos)         /*!< 0x00C00000 */
#define AS60XX_CA_TOF_EDGE_MODE_POS_EDGE            (0)                                             /*!< TOF_EDGE_MODE[23:22]Time of Flight, edge mode, on positive edge of TOF hit */
#define AS60XX_CA_TOF_EDGE_MODE_NEG_EDGE            (1)                                             /*!< TOF_EDGE_MODE[23:22]Time of Flight, edge mode, on negative edge of TOF hit*/
#define AS60XX_CA_TOF_EDGE_MODE_TOGGLE_EVERY_1      (2)                                             /*!< TOF_EDGE_MODE[23:22]Time of Flight, edge mode, toggle edge every measurement*/
#define AS60XX_CA_TOF_EDGE_MODE_TOGGLE_EVERY_2      (3)                                             /*!< TOF_EDGE_MODE[23:22]Time of Flight, edge mode, toggle edge after 2 measurements*/
#define AS60XX_CA_TOF_RATE_INIT_Pos                 (24U)
#define AS60XX_CA_TOF_RATE_INIT_Msk                 (0x3FUL << AS60XX_CA_TOF_RATE_INIT_Pos)         /*!< 0x3F000000 */
#define AS60XX_CA_TOF_RATE_INIT_0                   (0x01)                                          /*!< TOF_RATE_INIT[29:24]FWD copy of initial value for TOF rate */
#define AS60XX_CA_TOF_RATE_INIT_1                   (0x02)                                          /*!< TOF_RATE_INIT[29:24]FWD copy of initial value for TOF rate */
#define AS60XX_CA_TOF_RATE_INIT_2                   (0x04)                                          /*!< TOF_RATE_INIT[29:24]FWD copy of initial value for TOF rate */
#define AS60XX_CA_TOF_RATE_INIT_3                   (0x08)                                          /*!< TOF_RATE_INIT[29:24]FWD copy of initial value for TOF rate */
#define AS60XX_CA_TOF_RATE_INIT_4                   (0x10)                                          /*!< TOF_RATE_INIT[29:24]FWD copy of initial value for TOF rate */
#define AS60XX_CA_TOF_RATE_INIT_5                   (0x20)                                          /*!< TOF_RATE_INIT[29:24]FWD copy of initial value for TOF rate */
#define AS60XX_CA_NOT_USED_31_30_Pos                (30U)
#define AS60XX_CA_NOT_USED_31_30_Msk                (0x03UL << AS60XX_CA_NOT_USED_31_30_Pos)        /*!< 0xC0000000 */
#define AS60XX_CA_NOT_USED_31_30                    (0)                                             /*!< NOT_USED_31_30[31:30]Not Used */

/******************  Bit definition for AS60XX_CB register  *******************/
#define AS60XX_CB_AM_RATE_Pos                       (0U)
#define AS60XX_CB_AM_RATE_Msk                       (0x07UL << AS60XX_CB_AM_RATE_Pos)               /*!< 0x00000007 */
#define AS60XX_CB_AM_RATE_DISABLED                  (0)
#define AS60XX_CB_AM_RATE_EVERY_1                   (1)
#define AS60XX_CB_AM_RATE_EVERY_2                   (2)
#define AS60XX_CB_AM_RATE_EVERY_5                   (3)
#define AS60XX_CB_AM_RATE_EVERY_10                  (4)
#define AS60XX_CB_AM_RATE_EVERY_20                  (5)
#define AS60XX_CB_AM_RATE_EVERY_50                  (6)
#define AS60XX_CB_AM_RATE_EVERY_100                 (7)
#define AS60XX_CB_NOT_USED_3_Pos                    (3U)
#define AS60XX_CB_NOT_USED_3_Msk                    (0x1UL << AS60XX_CB_NOT_USED_3_Pos)             /*!< 0x00000008 */
#define AS60XX_CB_NOT_USED_3                        (0)                                             /*!< Default setting: b0 */
#define AS60XX_CB_AM_PD_END_Pos                     (4U)
#define AS60XX_CB_AM_PD_END_Msk                     (0x1FUL << AS60XX_CB_AM_PD_END_Pos)             /*!< 0x000001F0 */
#define AS60XX_CB_AM_PD_END_0                       (0x01)                                          /*!< AM_PD_END[8:4]Amplitude measurement, end of peak detection */
#define AS60XX_CB_AM_PD_END_1                       (0x02)                                          /*!< AM_PD_END[8:4]Amplitude measurement, end of peak detection */
#define AS60XX_CB_AM_PD_END_2                       (0x04)                                          /*!< AM_PD_END[8:4]Amplitude measurement, end of peak detection */
#define AS60XX_CB_AM_PD_END_3                       (0x08)                                          /*!< AM_PD_END[8:4]Amplitude measurement, end of peak detection */
#define AS60XX_CB_AM_PD_END_4                       (0x10)                                          /*!< AM_PD_END[8:4]Amplitude measurement, end of peak detection */
#define AS60XX_CB_NOT_USED_11_9_Pos                 (9U)
#define AS60XX_CB_NOT_USED_11_9_Msk                 (0x07UL << AS60XX_CB_NOT_USED_11_9_Pos)         /*!< 0x00000E00 */
#define AS60XX_CB_NOT_USED_11_9                     (7)                                             /*!< NOT_USED_11_9[11:9]Mandatory setting: b111 */
#define AS60XX_CB_AMC_RATE_Pos                      (12U)
#define AS60XX_CB_AMC_RATE_Msk                      (0x07UL << AS60XX_CB_AMC_RATE_Pos)              /*!< 0x00007000 */
#define AS60XX_CB_AMC_RATE_DISABLED                 (0)                                             /*!< AMC_RATE[14:12]Amplitude measurement calibration rate */
#define AS60XX_CB_AMC_RATE_EVERY_1                  (1)                                             /*!< AMC_RATE[14:12]Amplitude measurement calibration rate */
#define AS60XX_CB_AMC_RATE_EVERY_2                  (2)                                             /*!< AMC_RATE[14:12]Amplitude measurement calibration rate */
#define AS60XX_CB_AMC_RATE_EVERY_5                  (3)                                             /*!< AMC_RATE[14:12]Amplitude measurement calibration rate */
#define AS60XX_CB_AMC_RATE_EVERY_10                 (4)                                             /*!< AMC_RATE[14:12]Amplitude measurement calibration rate */
#define AS60XX_CB_AMC_RATE_EVERY_20                 (5)                                             /*!< AMC_RATE[14:12]Amplitude measurement calibration rate */
#define AS60XX_CB_AMC_RATE_EVERY_50                 (6)                                             /*!< AMC_RATE[14:12]Amplitude measurement calibration rate */
#define AS60XX_CB_AMC_RATE_EVERY_100                (7)                                             /*!< AMC_RATE[14:12]Amplitude measurement calibration rate */
#define AS60XX_CB_PWD_EN_Pos                        (15U)
#define AS60XX_CB_PWD_EN_Msk                        (0x1UL << AS60XX_CB_PWD_EN_Pos)                 /*!< 0x00008000 */
#define AS60XX_CB_PWD_EN                            (1)                                             /*!< Enables pulse width detection */
#define AS60XX_CB_PGA_TRIM_Pos                      (16U)
#define AS60XX_CB_PGA_TRIM_Msk                      (0x07UL << AS60XX_CB_PGA_TRIM_Pos)              /*!< 0x00070000 */
#define AS60XX_CB_PGA_TRIM_2_V_PER_V                (0)                                             /*!< PGA_TRIM[18:16]DC gain of the PGA */
#define AS60XX_CB_PGA_TRIM_3_V_PER_V                (0x1)                                           /*!< PGA_TRIM[18:16]DC gain of the PGA */
#define AS60XX_CB_PGA_TRIM_4_V_PER_V                (0x2)                                           /*!< PGA_TRIM[18:16]DC gain of the PGA */
#define AS60XX_CB_PGA_TRIM_5_V_PER_V                (0x3)                                           /*!< PGA_TRIM[18:16]DC gain of the PGA */
#define AS60XX_CB_PGA_TRIM_7_V_PER_V                (0x4)                                           /*!< PGA_TRIM[18:16]DC gain of the PGA */
#define AS60XX_CB_PGA_TRIM_10_V_PER_V               (0x5)                                           /*!< PGA_TRIM[18:16]DC gain of the PGA */
#define AS60XX_CB_PGA_TRIM_14_V_PER_V               (0x6)                                           /*!< PGA_TRIM[18:16]DC gain of the PGA */
#define AS60XX_CB_PGA_TRIM_19_V_PER_V               (0x7)                                           /*!< PGA_TRIM[18:16]DC gain of the PGA */
#define AS60XX_CB_PGA_TRIM_26_V_PER_V               (0x8)                                           /*!< PGA_TRIM[18:16]DC gain of the PGA */
#define AS60XX_CB_PGA_TRIM_36_V_PER_V               (0x9)                                           /*!< PGA_TRIM[18:16]DC gain of the PGA */
#define AS60XX_CB_PGA_TRIM_50_V_PER_V               (0xA)                                           /*!< PGA_TRIM[18:16]DC gain of the PGA */
#define AS60XX_CB_PGA_TRIM_69_V_PER_V               (0xB)                                           /*!< PGA_TRIM[18:16]DC gain of the PGA */
#define AS60XX_CB_PGA_TRIM_96_V_PER_V               (0xC)                                           /*!< PGA_TRIM[18:16]DC gain of the PGA */
#define AS60XX_CB_PGA_TRIM_132_V_PER_V              (0xD)                                           /*!< PGA_TRIM[18:16]DC gain of the PGA */
#define AS60XX_CB_PGA_EN_MODE_Pos                   (20U)                                           /*!< PGA_TRIM[18:16]DC gain of the PGA */
#define AS60XX_CB_PGA_EN_MODE_Msk                   (0x1UL << AS60XX_CB_PGA_EN_MODE_Pos)            /*!< 0x00100000 */
#define AS60XX_CB_PGA_EN_MODE                       (0)                                             /*!< Default setting: b0 */
#define AS60XX_CB_PGA_MODE_Pos                      (21U)
#define AS60XX_CB_PGA_MODE_Msk                      (0x1UL << AS60XX_CB_PGA_MODE_Pos)               /*!< 0x00200000 */
#define AS60XX_CB_PGA_MODE_DISABLED                 (0)                                             /*!< Ultrasonic measurement PGA Mode */
#define AS60XX_CB_PGA_MODE_ENABLED                  (1)                                             /*!< Ultrasonic measurement PGA Mode */
#define AS60XX_CB_NOT_USED_22_Pos                   (22U)
#define AS60XX_CB_NOT_USED_22_Msk                   (0x1UL << AS60XX_CB_NOT_USED_22_Pos)            /*!< 0x00400000 */
#define AS60XX_CB_NOT_USED_22                       (0)                                             /*!< Mandatory setting: b0 */
#define AS60XX_CB_AM_PD_START_MODE_Pos              (23U)
#define AS60XX_CB_AM_PD_START_MODE_Msk              (0x1UL << AS60XX_CB_AM_PD_START_MODE_Pos)       /*!< 0x00800000 */
#define AS60XX_CB_AM_PD_START_MODE_NOISE_MASK       (0)                                             /*!< Peak Detection Start Mode, starts after noise mask window expires */
#define AS60XX_CB_AM_PD_START_MODE_US_RELEASE       (1)                                             /*!< Peak Detection Start Mode, starts after ultrasonic release delay expires */
#define AS60XX_CB_ZCD_FHL_INIT_Pos                  (24U)
#define AS60XX_CB_ZCD_FHL_INIT_Msk                  (0xFFUL << AS60XX_CB_ZCD_FHL_INIT_Pos)          /*!< 0xFF000000 */
#define AS60XX_CB_ZCD_FHL_INIT_0                    (0x01)                                          /*!< ZCD_FHL_INIT[31:24]FWD copy of initial value for first hit levels */
#define AS60XX_CB_ZCD_FHL_INIT_1                    (0x02)                                          /*!< ZCD_FHL_INIT[31:24]FWD copy of initial value for first hit levels */
#define AS60XX_CB_ZCD_FHL_INIT_2                    (0x04)                                          /*!< ZCD_FHL_INIT[31:24]FWD copy of initial value for first hit levels */
#define AS60XX_CB_ZCD_FHL_INIT_3                    (0x08)                                          /*!< ZCD_FHL_INIT[31:24]FWD copy of initial value for first hit levels */
#define AS60XX_CB_ZCD_FHL_INIT_4                    (0x10)                                          /*!< ZCD_FHL_INIT[31:24]FWD copy of initial value for first hit levels */
#define AS60XX_CB_ZCD_FHL_INIT_5                    (0x20)                                          /*!< ZCD_FHL_INIT[31:24]FWD copy of initial value for first hit levels */
#define AS60XX_CB_ZCD_FHL_INIT_6                    (0x40)                                          /*!< ZCD_FHL_INIT[31:24]FWD copy of initial value for first hit levels */
#define AS60XX_CB_ZCD_FHL_INIT_7                    (0x80)                                          /*!< ZCD_FHL_INIT[31:24]FWD copy of initial value for first hit levels */

/******************  Bit definition for AS60XX_CC register  *******************/
#define AS60XX_CC_TRIM1_Pos                         (0U)
#define AS60XX_CC_TRIM1_Msk                         (0xFFFFFFFFUL << AS60XX_CC_TRIM1_Pos)           /*!< 0xFFFFFFFF */
#define AS60XX_CC_TRIM1                             AS60XX_CC_TRIM1_Msk                             /*!< TRIM1[31:0]Default setting: 0x94A0C46C */
#define AS60XX_CC_TRIM1_DEFAULT                     (0x94A0C46C)

/******************  Bit definition for AS60XX_CD register  *******************/
#define AS60XX_CD_TRIM2_Pos                         (0U)
#define AS60XX_CD_TRIM2_Msk                         (0xFFFFFFFFUL << AS60XX_CD_TRIM2_Pos)           /*!< 0xFFFFFFFF */
#define AS60XX_CD_TRIM2                             AS60XX_CD_TRIM2_Msk                             /*!< TRIM2[31:0]Default setting: 0x40110000 */
#define AS60XX_CD_TRIM2_DEFAULT                     (0x401100C4)

/******************  Bit definition for AS60XX_CE register  *******************/
#define AS60XX_CE_TRIM3_Pos                         (0U)
#define AS60XX_CE_TRIM3_Msk                         (0xFFFFFFFFUL << AS60XX_CE_TRIM3_Pos)           /*!< 0xFFFFFFFF */
#define AS60XX_CE_TRIM3                             AS60XX_CE_TRIM3_Msk                             /*!< TRIM3[31:0]Default setting: 0x4027000F */
#define AS60XX_CE_TRIM3_DEFAULT                     (0x00A7400F)

/******************  Bit definition for AS60XX_D0 register  *******************/
#define AS60XX_D0_TOF_RATE_Pos                      (0U)
#define AS60XX_D0_TOF_RATE_Msk                      (0x3FUL << AS60XX_D0_TOF_RATE_Pos)              /*!< 0x0000003F */
#define AS60XX_D0_TOF_RATE_0                        (0x01)                                          /*!< TOF_RATE[5:0]TOF Rate */
#define AS60XX_D0_TOF_RATE_1                        (0x02)                                          /*!< TOF_RATE[5:0]TOF Rate */
#define AS60XX_D0_TOF_RATE_2                        (0x04)                                          /*!< TOF_RATE[5:0]TOF Rate */
#define AS60XX_D0_TOF_RATE_3                        (0x08)                                          /*!< TOF_RATE[5:0]TOF Rate */
#define AS60XX_D0_TOF_RATE_4                        (0x10)                                          /*!< TOF_RATE[5:0]TOF Rate */
#define AS60XX_D0_TOF_RATE_5                        (0x20)                                          /*!< TOF_RATE[5:0]TOF Rate */
#define AS60XX_D0_NOT_USED_31_6_Pos                 (6U)
#define AS60XX_D0_NOT_USED_31_6_Msk                 (0x03FFFFFFUL << AS60XX_D0_NOT_USED_31_6_Pos)   /*!< 0xFFFFFFC0 */
#define AS60XX_D0_NOT_USED_31_6                     (0)                                             /*!< NOT_USED_31_6[31:6]Not used */

/******************  Bit definition for AS60XX_D1 register  *******************/
#define AS60XX_D1_USM_RLS_DLY_U_Pos                 (0U)
#define AS60XX_D1_USM_RLS_DLY_U_Msk                 (0x07FFFFUL << AS60XX_D1_USM_RLS_DLY_U_Pos)     /*!< 0x0007FFFF */
#define AS60XX_D1_USM_RLS_DLY_U_0                   (0x00001)                                       /*!< USM_RLS_DLY_U[18:0]Delay window in up direction, releasing ultrasonic measurement */
#define AS60XX_D1_USM_RLS_DLY_U_1                   (0x00002)                                       /*!< USM_RLS_DLY_U[18:0]Delay window in up direction, releasing ultrasonic measurement */
#define AS60XX_D1_USM_RLS_DLY_U_2                   (0x00004)                                       /*!< USM_RLS_DLY_U[18:0]Delay window in up direction, releasing ultrasonic measurement */
#define AS60XX_D1_USM_RLS_DLY_U_3                   (0x00008)                                       /*!< USM_RLS_DLY_U[18:0]Delay window in up direction, releasing ultrasonic measurement */
#define AS60XX_D1_USM_RLS_DLY_U_4                   (0x00010)                                       /*!< USM_RLS_DLY_U[18:0]Delay window in up direction, releasing ultrasonic measurement */
#define AS60XX_D1_USM_RLS_DLY_U_5                   (0x00020)                                       /*!< USM_RLS_DLY_U[18:0]Delay window in up direction, releasing ultrasonic measurement */
#define AS60XX_D1_USM_RLS_DLY_U_6                   (0x00040)                                       /*!< USM_RLS_DLY_U[18:0]Delay window in up direction, releasing ultrasonic measurement */
#define AS60XX_D1_USM_RLS_DLY_U_7                   (0x00080)                                       /*!< USM_RLS_DLY_U[18:0]Delay window in up direction, releasing ultrasonic measurement */
#define AS60XX_D1_USM_RLS_DLY_U_8                   (0x00100)                                       /*!< USM_RLS_DLY_U[18:0]Delay window in up direction, releasing ultrasonic measurement */
#define AS60XX_D1_USM_RLS_DLY_U_9                   (0x00200)                                       /*!< USM_RLS_DLY_U[18:0]Delay window in up direction, releasing ultrasonic measurement */
#define AS60XX_D1_USM_RLS_DLY_U_10                  (0x00400)                                       /*!< USM_RLS_DLY_U[18:0]Delay window in up direction, releasing ultrasonic measurement */
#define AS60XX_D1_USM_RLS_DLY_U_11                  (0x00800)                                       /*!< USM_RLS_DLY_U[18:0]Delay window in up direction, releasing ultrasonic measurement */
#define AS60XX_D1_USM_RLS_DLY_U_12                  (0x01000)                                       /*!< USM_RLS_DLY_U[18:0]Delay window in up direction, releasing ultrasonic measurement */
#define AS60XX_D1_USM_RLS_DLY_U_13                  (0x02000)                                       /*!< USM_RLS_DLY_U[18:0]Delay window in up direction, releasing ultrasonic measurement */
#define AS60XX_D1_USM_RLS_DLY_U_14                  (0x04000)                                       /*!< USM_RLS_DLY_U[18:0]Delay window in up direction, releasing ultrasonic measurement */
#define AS60XX_D1_USM_RLS_DLY_U_15                  (0x08000)                                       /*!< USM_RLS_DLY_U[18:0]Delay window in up direction, releasing ultrasonic measurement */
#define AS60XX_D1_USM_RLS_DLY_U_16                  (0x10000)                                       /*!< USM_RLS_DLY_U[18:0]Delay window in up direction, releasing ultrasonic measurement */
#define AS60XX_D1_USM_RLS_DLY_U_17                  (0x20000)                                       /*!< USM_RLS_DLY_U[18:0]Delay window in up direction, releasing ultrasonic measurement */
#define AS60XX_D1_USM_RLS_DLY_U_18                  (0x40000)                                       /*!< USM_RLS_DLY_U[18:0]Delay window in up direction, releasing ultrasonic measurement */
#define AS60XX_D1_NOT_USED_31_19_Pos                (19U)
#define AS60XX_D1_NOT_USED_31_19_Msk                (0x1FFFUL << AS60XX_D1_NOT_USED_31_19_Pos)      /*!< 0xFFF80000 */
#define AS60XX_D1_NOT_USED_31_19                    (0)                                             /*!< NOT_USED_31_19[31:19]Not used */

/******************  Bit definition for AS60XX_D2 register  *******************/
#define AS60XX_D2_USM_RLS_DLY_D_Pos                 (0U)
#define AS60XX_D2_USM_RLS_DLY_D_Msk                 (0x07FFFFUL << AS60XX_D2_USM_RLS_DLY_D_Pos)     /*!< 0x0007FFFF */
#define AS60XX_D2_USM_RLS_DLY_D_0                   (0x00001)                                       /*!< USM_RLS_DLY_D[18:0]Delay window in down direction, releasing ultrasonic measurement */
#define AS60XX_D2_USM_RLS_DLY_D_1                   (0x00002)                                       /*!< USM_RLS_DLY_D[18:0]Delay window in down direction, releasing ultrasonic measurement */
#define AS60XX_D2_USM_RLS_DLY_D_2                   (0x00004)                                       /*!< USM_RLS_DLY_D[18:0]Delay window in down direction, releasing ultrasonic measurement */
#define AS60XX_D2_USM_RLS_DLY_D_3                   (0x00008)                                       /*!< USM_RLS_DLY_D[18:0]Delay window in down direction, releasing ultrasonic measurement */
#define AS60XX_D2_USM_RLS_DLY_D_4                   (0x00010)                                       /*!< USM_RLS_DLY_D[18:0]Delay window in down direction, releasing ultrasonic measurement */
#define AS60XX_D2_USM_RLS_DLY_D_5                   (0x00020)                                       /*!< USM_RLS_DLY_D[18:0]Delay window in down direction, releasing ultrasonic measurement */
#define AS60XX_D2_USM_RLS_DLY_D_6                   (0x00040)                                       /*!< USM_RLS_DLY_D[18:0]Delay window in down direction, releasing ultrasonic measurement */
#define AS60XX_D2_USM_RLS_DLY_D_7                   (0x00080)                                       /*!< USM_RLS_DLY_D[18:0]Delay window in down direction, releasing ultrasonic measurement */
#define AS60XX_D2_USM_RLS_DLY_D_8                   (0x00100)                                       /*!< USM_RLS_DLY_D[18:0]Delay window in down direction, releasing ultrasonic measurement */
#define AS60XX_D2_USM_RLS_DLY_D_9                   (0x00200)                                       /*!< USM_RLS_DLY_D[18:0]Delay window in down direction, releasing ultrasonic measurement */
#define AS60XX_D2_USM_RLS_DLY_D_10                  (0x00400)                                       /*!< USM_RLS_DLY_D[18:0]Delay window in down direction, releasing ultrasonic measurement */
#define AS60XX_D2_USM_RLS_DLY_D_11                  (0x00800)                                       /*!< USM_RLS_DLY_D[18:0]Delay window in down direction, releasing ultrasonic measurement */
#define AS60XX_D2_USM_RLS_DLY_D_12                  (0x01000)                                       /*!< USM_RLS_DLY_D[18:0]Delay window in down direction, releasing ultrasonic measurement */
#define AS60XX_D2_USM_RLS_DLY_D_13                  (0x02000)                                       /*!< USM_RLS_DLY_D[18:0]Delay window in down direction, releasing ultrasonic measurement */
#define AS60XX_D2_USM_RLS_DLY_D_14                  (0x04000)                                       /*!< USM_RLS_DLY_D[18:0]Delay window in down direction, releasing ultrasonic measurement */
#define AS60XX_D2_USM_RLS_DLY_D_15                  (0x08000)                                       /*!< USM_RLS_DLY_D[18:0]Delay window in down direction, releasing ultrasonic measurement */
#define AS60XX_D2_USM_RLS_DLY_D_16                  (0x10000)                                       /*!< USM_RLS_DLY_D[18:0]Delay window in down direction, releasing ultrasonic measurement */
#define AS60XX_D2_USM_RLS_DLY_D_17                  (0x20000)                                       /*!< USM_RLS_DLY_D[18:0]Delay window in down direction, releasing ultrasonic measurement */
#define AS60XX_D2_USM_RLS_DLY_D_18                  (0x40000)                                       /*!< USM_RLS_DLY_D[18:0]Delay window in down direction, releasing ultrasonic measurement */
#define AS60XX_D2_NOT_USED_31_19_Pos                (19U)
#define AS60XX_D2_NOT_USED_31_19_Msk                (0x1FFFUL << AS60XX_D2_NOT_USED_31_19_Pos)      /*!< 0xFFF80000 */
#define AS60XX_D2_NOT_USED_31_19                    (0)                                             /*!< NOT_USED_31_19[31:19]Not used */

/******************  Bit definition for AS60XX_D3 register  *******************/
#define AS60XX_D3_GPO_Pos                           (0U)
#define AS60XX_D3_GPO_Msk                           (0x3FUL << AS60XX_D3_GPO_Pos)                   /*!< 0x0000003F */
#define AS60XX_D3_GPO_0                             (0x01)                                          /*!< GPO[5:0]General Purpose Out */
#define AS60XX_D3_GPO_1                             (0x02)                                          /*!< GPO[5:0]General Purpose Out */
#define AS60XX_D3_GPO_2                             (0x04)                                          /*!< GPO[5:0]General Purpose Out */
#define AS60XX_D3_GPO_3                             (0x08)                                          /*!< GPO[5:0]General Purpose Out */
#define AS60XX_D3_GPO_4                             (0x10)                                          /*!< GPO[5:0]General Purpose Out */
#define AS60XX_D3_GPO_5                             (0x20)                                          /*!< GPO[5:0]General Purpose Out */
#define AS60XX_D3_NOT_USED_7_6_Pos                  (6U)
#define AS60XX_D3_NOT_USED_7_6_Msk                  (0x3UL << AS60XX_D3_NOT_USED_7_6_Pos)           /*!< 0x000000C0 */
#define AS60XX_D3_NOT_USED_7_6                      (0)                                             /*!< NOT_USED_7_6[7:6]Not used */
#define AS60XX_D3_PI_OUT_FRC0_Pos                   (8U)
#define AS60XX_D3_PI_OUT_FRC0_Msk                   (0x1UL << AS60XX_D3_PI_OUT_FRC0_Pos)            /*!< 0x00000100 */
#define AS60XX_D3_PI_OUT_FRC0                       (1)                                             /*!< Forces LOW on pulse output */
#define AS60XX_D3_PI_OUT_FRC1_Pos                   (9U)
#define AS60XX_D3_PI_OUT_FRC1_Msk                   (0x1UL << AS60XX_D3_PI_OUT_FRC1_Pos)            /*!< 0x00000200 */
#define AS60XX_D3_PI_OUT_FRC1                       (1)                                             /*!< Forces HIGH on pulse output */
#define AS60XX_D3_PI_DIR_FRC0_Pos                   (10U)
#define AS60XX_D3_PI_DIR_FRC0_Msk                   (0x1UL << AS60XX_D3_PI_DIR_FRC0_Pos)            /*!< 0x00000400 */
#define AS60XX_D3_PI_DIR_FRC0                       (1)                                             /*!< Forces LOW on pulse direction */
#define AS60XX_D3_PI_DIR_FRC1_Pos                   (11U)
#define AS60XX_D3_PI_DIR_FRC1_Msk                   (0x1UL << AS60XX_D3_PI_DIR_FRC1_Pos)            /*!< 0x00000800 */
#define AS60XX_D3_PI_DIR_FRC1                       (1)                                             /*!< Forces HIGH on pulse direction */
#define AS60XX_D3_FWCU_CS_ERR_Pos                   (12U)
#define AS60XX_D3_FWCU_CS_ERR_Msk                   (0x1UL << AS60XX_D3_FWCU_CS_ERR_Pos)            /*!< 0x00001000 */
#define AS60XX_D3_FWCU_CS_ERR                       (1)                                             /*!< FWCU checksum error */
#define AS60XX_D3_FWDU_CS_ERR_Pos                   (13U)
#define AS60XX_D3_FWDU_CS_ERR_Msk                   (0x1UL << AS60XX_D3_FWDU_CS_ERR_Pos)            /*!< 0x00002000 */
#define AS60XX_D3_FWDU_CS_ERR                       (1)                                             /*!< FWDU checksum error */
#define AS60XX_D3_FWA_CS_ERR_Pos                    (14U)
#define AS60XX_D3_FWA_CS_ERR_0                      (0x01)                                          /*!< FWA_CS_ERR[18:14]Different FWA checksum errors */
#define AS60XX_D3_FWA_CS_ERR_1                      (0x02)                                          /*!< FWA_CS_ERR[18:14]Different FWA checksum errors */
#define AS60XX_D3_FWA_CS_ERR_2                      (0x04)                                          /*!< FWA_CS_ERR[18:14]Different FWA checksum errors */
#define AS60XX_D3_FWA_CS_ERR_3                      (0x08)                                          /*!< FWA_CS_ERR[18:14]Different FWA checksum errors */
#define AS60XX_D3_FWA_CS_ERR_4                      (0x10)                                          /*!< FWA_CS_ERR[18:14]Different FWA checksum errors */
#define AS60XX_D3_FW_ERR_Pos                        (19U)
#define AS60XX_D3_FW_ERR_Msk                        (0x1UL << AS60XX_D3_FW_ERR_Pos)                 /*!< 0x00080000 */
#define AS60XX_D3_FW_ERR                            (1)                                             /*!< FW error */
#define AS60XX_D3_NOT_USED_31_20_Pos                (20U)
#define AS60XX_D3_NOT_USED_31_20_Msk                (0xFFFUL << AS60XX_D3_NOT_USED_31_20_Pos)       /*!< 0xFFF00000 */
#define AS60XX_D3_NOT_USED_31_20                    (0)                                             /*!< NOT_USED_31_20[31:20]Not used */

/******************  Bit definition for AS60XX_D4 register  *******************/
#define AS60XX_D4_PI_NPULSE_Pos                     (0U)
#define AS60XX_D4_PI_NPULSE_Msk                     (0xFFFFFFFFUL << AS60XX_D4_PI_NPULSE_Pos)       /*!< 0xFFFFFFFF */

/******************  Bit definition for AS60XX_D5 register  *******************/
#define AS60XX_D5_PI_TPA_Pos                        (0U)
#define AS60XX_D5_PI_TPA_Msk                        (0xFFFFUL << AS60XX_D5_PI_TPA_Pos)              /*!< 0x0000FFFF */
#define AS60XX_D5_NOT_USED_31_16_Pos                (16U)
#define AS60XX_D5_NOT_USED_31_16_Msk                (0xFFFFUL << AS60XX_D5_NOT_USED_31_16_Pos)      /*!< 0xFFFF0000 */
#define AS60XX_D5_NOT_USED_31_16                    (0)                                             /*!< NOT_USED_31_16[31:16]Not used */

/******************  Bit definition for AS60XX_D6 register  *******************/
#define AS60XX_D6_PI_IU_TIME_Pos                    (0U)
#define AS60XX_D6_PI_IU_TIME_Msk                    (0xFFFFUL << AS60XX_D6_PI_IU_TIME_Pos)          /*!< 0x0000FFFF */
#define AS60XX_D6_NOT_USED_31_16_Pos                (16U)
#define AS60XX_D6_NOT_USED_31_16_Msk                (0xFFFFUL << AS60XX_D5_NOT_USED_31_16_Pos)      /*!< 0xFFFF0000 */
#define AS60XX_D6_NOT_USED_31_16                    (0)                                             /*!< NOT_USED_31_16[31:16]Not used */

/******************  Bit definition for AS60XX_D7 register  *******************/
#define AS60XX_D7_PI_IU_NO_Pos                      (0U)
#define AS60XX_D7_PI_IU_NO_Msk                      (0xFFUL << AS60XX_D7_PI_IU_NO_Pos)              /*!< 0x000000FF */
#define AS60XX_D7_NOT_USED_31_8_Pos                 (8U)
#define AS60XX_D7_NOT_USED_31_8_Msk                 (0xFFFFFFUL << AS60XX_D7_NOT_USED_31_8_Pos)     /*!< 0xFFFFFF00 */
#define AS60XX_D7_NOT_USED_31_8                     (0)                                             /*!< NOT_USED_31_8[31:8]Not used */

/******************  Bit definition for AS60XX_D9 register  *******************/
#define AS60XX_D9_ZCD_LVL_Pos                       (0U)
#define AS60XX_D9_ZCD_LVL_Msk                       (0x7FFUL << AS60XX_D9_ZCD_LVL_Pos)              /*!< 0x000007FF */
#define AS60XX_D9_NOT_USED_31_10_Pos                (10U)
#define AS60XX_D9_NOT_USED_31_10_Msk                (0xFFFFF8UL << AS60XX_D9_NOT_USED_31_10_Pos)    /*!< 0xFFFFF800 */
#define AS60XX_D9_NOT_USED_31_10                    (0)                                             /*!< NOT_USED_31_10[31:10]Not used */

/******************  Bit definition for AS60XX_DA register  *******************/
#define AS60XX_DA_ZCD_FHL_U_Pos                     (0U)
#define AS60XX_DA_ZCD_FHL_U_Msk                     (0xFFUL << AS60XX_DA_ZCD_FHL_U_Pos)             /*!< 0x000000FF */
#define AS60XX_DA_ZCD_FHL_U_0                       (0x01)                                          /*!< ZCD_FHL_U[7:0]First Hit Level Up */
#define AS60XX_DA_ZCD_FHL_U_1                       (0x02)                                          /*!< ZCD_FHL_U[7:0]First Hit Level Up */
#define AS60XX_DA_ZCD_FHL_U_2                       (0x04)                                          /*!< ZCD_FHL_U[7:0]First Hit Level Up */
#define AS60XX_DA_ZCD_FHL_U_3                       (0x08)                                          /*!< ZCD_FHL_U[7:0]First Hit Level Up */
#define AS60XX_DA_ZCD_FHL_U_4                       (0x10)                                          /*!< ZCD_FHL_U[7:0]First Hit Level Up */
#define AS60XX_DA_ZCD_FHL_U_5                       (0x20)                                          /*!< ZCD_FHL_U[7:0]First Hit Level Up */
#define AS60XX_DA_ZCD_FHL_U_6                       (0x40)                                          /*!< ZCD_FHL_U[7:0]First Hit Level Up */
#define AS60XX_DA_ZCD_FHL_U_7                       (0x80)                                          /*!< ZCD_FHL_U[7:0]First Hit Level Up */
#define AS60XX_DA_NOT_USED_31_8_Pos                 (8U)
#define AS60XX_DA_NOT_USED_31_8_Msk                 (0xFFFFFFUL << AS60XX_DA_NOT_USED_31_8_Pos)     /*!< 0xFFFFFF00 */
#define AS60XX_DA_NOT_USED_31_8                     (0)                                             /*!< NOT_USED_31_8[31:8]Not used */

/******************  Bit definition for AS60XX_DB register  *******************/
#define AS60XX_DB_ZCD_FHL_D_Pos                     (0U)
#define AS60XX_DB_ZCD_FHL_D_Msk                     (0xFFUL << AS60XX_DB_ZCD_FHL_D_Pos)             /*!< 0x000000FF */
#define AS60XX_DB_ZCD_FHL_D_0                       (0x01)                                          /*!< ZCD_FHL_D[7:0]First Hit Level Down */
#define AS60XX_DB_ZCD_FHL_D_1                       (0x02)                                          /*!< ZCD_FHL_D[7:0]First Hit Level Down */
#define AS60XX_DB_ZCD_FHL_D_2                       (0x04)                                          /*!< ZCD_FHL_D[7:0]First Hit Level Down */
#define AS60XX_DB_ZCD_FHL_D_3                       (0x08)                                          /*!< ZCD_FHL_D[7:0]First Hit Level Down */
#define AS60XX_DB_ZCD_FHL_D_4                       (0x10)                                          /*!< ZCD_FHL_D[7:0]First Hit Level Down */
#define AS60XX_DB_ZCD_FHL_D_5                       (0x20)                                          /*!< ZCD_FHL_D[7:0]First Hit Level Down */
#define AS60XX_DB_ZCD_FHL_D_6                       (0x40)                                          /*!< ZCD_FHL_D[7:0]First Hit Level Down */
#define AS60XX_DB_ZCD_FHL_D_7                       (0x80)                                          /*!< ZCD_FHL_D[7:0]First Hit Level Down */
#define AS60XX_DB_NOT_USED_31_8_Pos                 (8U)
#define AS60XX_DB_NOT_USED_31_8_Msk                 (0xFFFFFFUL << AS60XX_DB_NOT_USED_31_8_Pos)     /*!< 0xFFFFFF00 */
#define AS60XX_DB_NOT_USED_31_8                     (0)                                             /*!< NOT_USED_31_8[31:8]Not used */

/******************  Bit definition for AS60XX_DC register  *******************/
#define AS60XX_DC_CPU_REQ_BLD_EXC_Pos               (0U)
#define AS60XX_DC_CPU_REQ_BLD_EXC_Msk               (0x1UL << AS60XX_DC_CPU_REQ_BLD_EXC_Pos)        /*!< 0x00000001 */
#define AS60XX_DC_CPU_REQ_BLD_EXC_NOT_REQUESTED     (0)                                             /*!< CPU Request Bootloader Execute, Bootloader subroutine in CPU not requested */
#define AS60XX_DC_CPU_REQ_BLD_EXC_REQUESTED         (1)                                             /*!< CPU Request Bootloader Execute, Bootloader subroutine in CPU requested */
#define AS60XX_DC_CPU_REQ_CHKSUM_Pos                (1U)
#define AS60XX_DC_CPU_REQ_CHKSUM_Msk                (0x1UL << AS60XX_DC_CPU_REQ_CHKSUM_Pos)         /*!< 0x00000002 */
#define AS60XX_DC_CPU_REQ_CHKSUM_NOT_REQUESTED      (0)                                             /*!< CPU Request Build Checksum, Build checksum in CPU not requested */
#define AS60XX_DC_CPU_REQ_CHKSUM_REQUESTED          (1)                                             /*!< CPU Request Build Checksum, Build checksum in CPU requested */
#define AS60XX_DC_CPU_REQ_PP_T_Pos                  (2U)
#define AS60XX_DC_CPU_REQ_PP_T_Msk                  (0x1UL << AS60XX_DC_CPU_REQ_PP_T_Pos)           /*!< 0x00000004 */
#define AS60XX_DC_CPU_REQ_PP_T_NOT_REQUESTED        (0)                                             /*!< CPU Request Post Processing PB, Post processing PB in CPU not requested */
#define AS60XX_DC_CPU_REQ_PP_T_REQUESTED            (1)                                             /*!< CPU Request Post Processing PB, Post processing PB in CPU requested */
#define AS60XX_DC_CPU_REQ_PP_F_Pos                  (3U)
#define AS60XX_DC_CPU_REQ_PP_F_Msk                  (0x1UL << AS60XX_DC_CPU_REQ_PP_F_Pos)           /*!< 0x00000008 */
#define AS60XX_DC_CPU_REQ_PP_F_NOT_REQUESTED        (0)                                             /*!< CPU Request Post Processing PA, Post processing PA in CPU not requested */
#define AS60XX_DC_CPU_REQ_PP_F_REQUESTED            (1)                                             /*!< CPU Request Post Processing PA, Post processing PA in CPU requested */
#define AS60XX_DC_CPU_REQ_GPH_Pos                   (4U)
#define AS60XX_DC_CPU_REQ_GPH_Msk                   (0x1UL << AS60XX_DC_CPU_REQ_GPH_Pos)            /*!< 0x00000010 */
#define AS60XX_DC_CPU_REQ_GPH_NOT_REQUESTED         (0)                                             /*!< CPU Request General Purpose Handling, General purpose handling in CPU not requested */
#define AS60XX_DC_CPU_REQ_GPH_REQUESTED             (1)                                             /*!< CPU Request General Purpose Handling, General purpose handling in CPU requested */
#define AS60XX_DC_CPU_REQ_FW_INIT_Pos               (5U)
#define AS60XX_DC_CPU_REQ_FW_INIT_Msk               (0x1UL << AS60XX_DC_CPU_REQ_FW_INIT_Pos)        /*!< 0x00000020 */
#define AS60XX_DC_CPU_REQ_FW_INIT_NOT_REQUESTED     (0)                                             /*!< CPU Request Firmware Initialization, Firmware initialization not requested */
#define AS60XX_DC_CPU_REQ_FW_INIT_REQUESTED         (1)                                             /*!< CPU Request Firmware Initialization, Firmware initialization requested */
#define AS60XX_DC_NOT_USED_6_Pos                    (6U)
#define AS60XX_DC_NOT_USED_6_Msk                    (0x1UL << AS60XX_DC_NOT_USED_6_Pos)             /*!< 0x00000040 */
#define AS60XX_DC_NOT_USED_6                        (0)                                             /*!< Not used */
#define AS60XX_DC_NOT_USED_7_Pos                    (7U)
#define AS60XX_DC_NOT_USED_7_Msk                    (0x1UL << AS60XX_DC_NOT_USED_7_Pos)             /*!< 0x00000080 */
#define AS60XX_DC_NOT_USED_7                        (0)                                             /*!< Not used */
#define AS60XX_DC_CPU_SFLAG_HSO_ST_TO_Pos           (8U)
#define AS60XX_DC_CPU_SFLAG_HSO_ST_TO_Msk           (0x1UL << AS60XX_DC_CPU_SFLAG_HSO_ST_TO_Msk)    /*!< 0x00000100 */
#define AS60XX_DC_CPU_SFLAG_HSO_ST_TO_NOT_SETTLED   (0)                                             /*!< High speed oscillator, not settled yet */
#define AS60XX_DC_CPU_SFLAG_HSO_ST_TO_SETTLED       (1)                                             /*!< High speed oscillator, settled and stable */
#define AS60XX_DC_CPU_COM_REQ_Pos                   (9U)
#define AS60XX_DC_CPU_COM_REQ_Msk                   (0x1UL << AS60XX_DC_CPU_COM_REQ_Pos)            /*!< 0x00000200 */
#define AS60XX_DC_CPU_COM_REQ_NOT_REQUESTED         (0)                                             /*!< No communication request set by SPI interface */
#define AS60XX_DC_CPU_COM_REQ_REQUESTED             (1)                                             /*!< Communication request set by SPI interface */
#define AS60XX_DC_CPU_LS_CORE_CLK_Pos               (10U)
#define AS60XX_DC_CPU_LS_CORE_CLK_Msk               (0x1UL << AS60XX_DC_CPU_LS_CORE_CLK_Pos)        /*!< 0x00000400 */
#define AS60XX_DC_CPU_LS_CORE_CLK_LOW_PHASE         (0)                                             /*!< Low phase of LS_CORE_CLK */
#define AS60XX_DC_CPU_LS_CORE_CLK_HIGH_PHASE        (1)                                             /*!< High phase of LS_CORE_CLK */
#define AS60XX_DC_NOT_USED_31_11_Pos                (11U)
#define AS60XX_DC_NOT_USED_31_11_Msk                (0x1FFFFUL << AS60XX_DA_NOT_USED_31_11_Pos)     /*!< 0xFFFFF800 */
#define AS60XX_DC_NOT_USED_31_11                    (0)                                             /*!< NOT_USED_31_8[31:11]Not used */

/******************  Bit definition for AS60XX_DD register  *******************/
#define AS60XX_DD_IF_CLR_Pos                        (0U)
#define AS60XX_DD_IF_CLR_Msk                        (0x1UL << AS60XX_DD_IF_CLR_Pos)                 /*!< 0x00000001 */
#define AS60XX_DD_IF_CLR_CLEAR                      (AS60XX_DD_IF_CLR_Msk)                          /*!< Clear SRR_IRQ_FLAG Interrupt flag */
#define AS60XX_DD_EF_CLR_Pos                        (1U)
#define AS60XX_DD_EF_CLR_Msk                        (0x1UL << AS60XX_DD_EF_CLR_Pos)                 /*!< 0x00000002 */
#define AS60XX_DD_EF_CLR_CLEAR                      (AS60XX_DD_EF_CLR_Msk)                          /*!< Clear SRR_ERR_FLAG Error flag */
#define AS60XX_DD_FES_CLR_Pos                       (2U)
#define AS60XX_DD_FES_CLR_Msk                       (0x1UL << AS60XX_DD_FES_CLR_Pos)                /*!< 0x00000004 */
#define AS60XX_DD_FES_CLR_CLEAR                     (AS60XX_DD_FES_CLR_Msk)                         /*!< Clear SRR_FEP_STF Frontend Status flag */
#define AS60XX_DD_TSC_CLR_Pos                       (3U)
#define AS60XX_DD_TSC_CLR_Msk                       (0x1UL << AS60XX_DD_TSC_CLR_Pos)                /*!< 0x00000008 */
#define AS60XX_DD_TSC_CLR_CLEAR                     (AS60XX_DD_TSC_CLR_Msk)                         /*!< Clear time stamp counter */
#define AS60XX_DD_TSV_UPD_Pos                       (4U)
#define AS60XX_DD_TSV_UPD_Msk                       (0x1UL << AS60XX_DD_TSV_UPD_Pos)                /*!< 0x00000010 */
#define AS60XX_DD_TSV_UPD_CLEAR                     (AS60XX_DD_TSV_UPD_Msk)                         /*!< Update time stamp value */
#define AS60XX_DD_PI_UPD_Pos                        (5U)
#define AS60XX_DD_PI_UPD_Msk                        (0x1UL << AS60XX_DD_PI_UPD_Pos)                 /*!< 0x00000020 */
#define AS60XX_DD_PI_UPD_CLEAR                      (AS60XX_DD_PI_UPD_Msk)                          /*!< Update pulse interface */
#define AS60XX_DD_BG_REFRESH_Pos                    (6U)
#define AS60XX_DD_BG_REFRESH_Msk                    (0x1UL << AS60XX_DD_BG_REFRESH_Pos)             /*!< 0x00000040 */
#define AS60XX_DD_BG_REFRESH_CLEAR                  (AS60XX_DD_BG_REFRESH_Msk)                      /*!< Refresh Bandgap */
#define AS60XX_DD_MCT_CLR_Pos                       (7U)
#define AS60XX_DD_MCT_CLR_Msk                       (0x1UL << AS60XX_DD_MCT_CLR_Pos)                /*!< 0x00000080 */
#define AS60XX_DD_MCT_CLR_CLEAR                     (AS60XX_DD_MCT_CLR_Msk)                         /*!< Clear measure cycle timer */
#define AS60XX_DD_RATE_CTR_CLR_Pos                  (8U)
#define AS60XX_DD_RATE_CTR_CLR_Msk                  (0x1UL << AS60XX_DD_RATE_CTR_CLR_Pos)           /*!< 0x00000100 */
#define AS60XX_DD_RATE_CTR_CLR_CLEAR                (AS60XX_DD_RATE_CTR_CLR_Msk)                    /*!< Clear all rate counters */
#define AS60XX_DD_ZCC_RNG_CLR_Pos                   (9U)
#define AS60XX_DD_ZCC_RNG_CLR_Msk                   (0x1UL << AS60XX_DD_ZCC_RNG_CLR_Pos)            /*!< 0x00000200 */
#define AS60XX_DD_ZCC_RNG_CLR_CLEAR                 (AS60XX_DD_ZCC_RNG_CLR_Msk)                     /*!< Clear zero cross calibration range */
#define AS60XX_DD_FW_IRQ_S_Pos                      (10U)
#define AS60XX_DD_FW_IRQ_S_Msk                      (0x1UL << AS60XX_DD_FW_IRQ_S_Pos)               /*!< 0x00000400 */
#define AS60XX_DD_FW_IRQ_S_TRIGGER                  (AS60XX_DD_FW_IRQ_S_Msk)                        /*!< FW Interrupt Request, synchronized with task sequencer */
#define AS60XX_DD_NOT_USED_11_Pos                   (11U)
#define AS60XX_DD_NOT_USED_11_Msk                   (0x1UL << AS60XX_DD_NOT_USED_11_Pos)            /*!< 0x00000800 */
#define AS60XX_DD_NOT_USED_11                       (AS60XX_DD_NOT_USED_11_Msk)                     /*!< Not used */
#define AS60XX_DD_COM_REQ_CLR_Pos                   (12U)
#define AS60XX_DD_COM_REQ_CLR_Msk                   (0x1UL << AS60XX_DD_COM_REQ_CLR_Pos)            /*!< 0x00001000 */
#define AS60XX_DD_COM_REQ_CLR_CLEAR                 (AS60XX_DD_COM_REQ_CLR_Msk)                     /*!< Clear communication request via remote interface */
#define AS60XX_DD_GPR_REQ_CLR_Pos                   (13U)
#define AS60XX_DD_GPR_REQ_CLR_Msk                   (0x1UL << AS60XX_DD_GPR_REQ_CLR_Pos)            /*!< 0x00002000 */
#define AS60XX_DD_GPR_REQ_CLR_CLEAR                 (AS60XX_DD_GPR_REQ_CLR_Msk)                     /*!< Clear general purpose request via remote interface */
#define AS60XX_DD_GPH_TRIG_Pos                      (14U)
#define AS60XX_DD_GPH_TRIG_Msk                      (0x1UL << AS60XX_DD_GPH_TRIG_Pos)               /*!< 0x00004000 */
#define AS60XX_DD_GPH_TRIG_CLEAR                    (AS60XX_DD_GPH_TRIG_Msk)                        /*!< Triggers general purpose handling for CPU via task sequencer */
#define AS60XX_DD_I2C_CLR_Pos                       (15U)
#define AS60XX_DD_I2C_CLR_Msk                       (0x1UL << AS60XX_DD_I2C_CLR_Pos)                /*!< 0x00008000 */
#define AS60XX_DD_I2C_CLR_CLEAR                     (AS60XX_DD_I2C_CLR_Msk)                         /*!< Clear I2C interface controller */
#define AS60XX_DD_ACP_PAGE_TGL_Pos                  (16U)
#define AS60XX_DD_ACP_PAGE_TGL_Msk                  (0x1UL << AS60XX_DD_ACP_PAGE_TGL_Pos)           /*!< 0x00010000 */
#define AS60XX_DD_ACP_PAGE_TGL_CLEAR                (AS60XX_DD_ACP_PAGE_TGL_Msk)                    /*!< Toggle ACP page (asynchronous communication) */
#define AS60XX_DD_HSO_REQ_Pos                       (17U)
#define AS60XX_DD_HSO_REQ_Msk                       (0x1UL << AS60XX_DD_HSO_REQ_Pos)                /*!< 0x00020000 */
#define AS60XX_DD_HSO_REQ_CLEAR                     (AS60XX_DD_HSO_REQ_Msk)                         /*!< Request high speed oscillator */
#define AS60XX_DD_HSO_CLR_Pos                       (18U)
#define AS60XX_DD_HSO_CLR_Msk                       (0x1UL << AS60XX_DD_HSO_CLR_Pos)                /*!< 0x00040000 */
#define AS60XX_DD_HSO_CLR_CLEAR                     (AS60XX_DD_HSO_CLR_Msk)                         /*!< Clear high speed oscillator */
#define AS60XX_DD_NOT_USED_31_19_Pos                (19U)
#define AS60XX_DD_NOT_USED_31_19_Msk                (0x1FFFUL << AS60XX_DA_NOT_USED_31_19_Pos)      /*!< 0xFFF80000 */
#define AS60XX_DD_NOT_USED_31_19                    (0)                                             /*!< NOT_USED_31_19[31:19]Not used */

/******************  Bit definition for AS60XX_DE register  *******************/
#define AS60XX_DE_CFG_OK_Pos                        (0U)
#define AS60XX_DE_CFG_OK_Msk                        (0x3UL << AS60XX_DD_CFG_OK_Pos)                 /*!< 0x00000003 */
#define AS60XX_DE_CFG_OK_NO_CHANGE                  (0)                                             /*!< UFC Configuration OK, No change of CFG_OK state */
#define AS60XX_DE_CFG_OK_NOT_PROPERLY_CONFIGURED    (1)                                             /*!< UFC Configuration OK, CFG_OK not properly configured */
#define AS60XX_DE_CFG_OK_PROPERLY_CONFIGURED        (2)                                             /*!< UFC Configuration OK, CFG_OK properly configured */
#define AS60XX_DE_HSC_DIV_STATE_Pos                 (2U)
#define AS60XX_DE_HSC_DIV_STATE_Msk                 (0x3UL << AS60XX_DE_HSC_DIV_STATE_Pos)          /*!< 0x0000000C */
#define AS60XX_DE_HSC_DIV_STATE_0                   (0x1)                                           /*!< State of HSC_DIV in CR_CPM */
#define AS60XX_DE_HSC_DIV_STATE_1                   (0x2)                                           /*!< State of HSC_DIV in CR_CPM */
#define AS60XX_DE_RC_FLAG2_Pos                      (4U)
#define AS60XX_DE_RC_FLAG2_Msk                      (0x3UL << AS60XX_DE_RC_FLAG2_Pos)               /*!< 0x00000030 */
#define AS60XX_DE_RC_FLAG2_NO_CHANGE                (0)                                             /*!< User Definable Flag, No change of RC_FLAG2 state */
#define AS60XX_DE_RC_FLAG2_NOT_SET                  (1)                                             /*!< User Definable Flag, RC_FLAG2 not set */
#define AS60XX_DE_RC_FLAG2_SET                      (2)                                             /*!< User Definable Flag, RC_FLAG2 set */
#define AS60XX_DA_NOT_USED_7_6_Pos                  (6U)
#define AS60XX_DA_NOT_USED_7_6_Msk                  (0x3UL << AS60XX_DA_NOT_USED_7_6_Pos)           /*!< 0x000000C0 */
#define AS60XX_DA_NOT_USED_7_6                      (0)                                             /*!< NOT_USED_7_6[7:6]Not used */
#define AS60XX_DE_HSO_MODE_Pos                      (8U)
#define AS60XX_DE_HSO_MODE_Msk                      (0x3UL << AS60XX_DE_HSO_MODE_Pos)               /*!< 0x00000300 */
#define AS60XX_DE_HSO_MODE_NO_CHANGE                (0)                                             /*!< High Speed Oscillator Mode, No change of HSO_MODE state */
#define AS60XX_DE_HSO_MODE_CONTROLLED_AS_CONFIG     (1)                                             /*!< High Speed Oscillator Mode, HSO controlled as configured */
#define AS60XX_DE_HSO_MODE_ALWAYS_ON                (2)                                             /*!< High Speed Oscillator Mode, HSO always on */
#define AS60XX_DE_BG_MODE_Pos                       (10U)
#define AS60XX_DE_BG_MODE_Msk                       (0x3UL << AS60XX_DE_BG_MODE_Pos)                /*!< 0x00000C00 */
#define AS60XX_DE_BG_MODE_NO_CHANGE                 (0)                                             /*!< High Speed Oscillator Mode, No change of BG_MODE state */
#define AS60XX_DE_BG_MODE_CONTROLLED_AS_CONFIG      (1)                                             /*!< High Speed Oscillator Mode, Bandgap controlled as configured */
#define AS60XX_DE_BG_MODE_ALWAYS_ON                 (2)                                             /*!< High Speed Oscillator Mode, Bandgap always on */
#define AS60XX_DE_RC_FLAG3_Pos                      (12U)
#define AS60XX_DE_RC_FLAG3_Msk                      (0x3UL << AS60XX_DE_RC_FLAG3_Pos)               /*!< 0x00003000 */
#define AS60XX_DE_RC_FLAG3_NO_CHANGE                (0)                                             /*!< User Definable Flag, No change of RC_FLAG3 state */
#define AS60XX_DE_RC_FLAG3_NOT_SET                  (1)                                             /*!< User Definable Flag, RC_FLAG3 not set */
#define AS60XX_DE_RC_FLAG3_SET                      (2)                                             /*!< User Definable Flag, RC_FLAG3 set */
#define AS60XX_DE_SYS_RST_Pos                       (14U)
#define AS60XX_DE_SYS_RST_Msk                       (0x1UL << AS60XX_DE_SYS_RST_Pos)                /*!< 0x00004000 */
#define AS60XX_DE_SYS_RST_CLEAR                     (1)                                             /*!< Performs a system reset */
#define AS60XX_DE_SYS_INIT_Pos                      (15U)
#define AS60XX_DE_SYS_INIT_Msk                      (0x1UL << AS60XX_DE_SYS_INIT_Pos)               /*!< 0x00008000 */
#define AS60XX_DE_SYS_INIT_CLEAR                    (1)                                             /*!< Performs a system reset */
#define AS60XX_DE_FW_STORE_ALL_Pos                  (16U)
#define AS60XX_DE_FW_STORE_ALL_Msk                  (0x1UL << AS60XX_DE_FW_STORE_ALL_Pos)           /*!< 0x00010000 */
#define AS60XX_DE_FW_STORE_ALL_REQUEST              (1)                                             /*!< Requests storing of complete firmware code & data */
#define AS60XX_DE_FW_STORE_LOCK_Pos                 (17U)
#define AS60XX_DE_FW_STORE_LOCK_Msk                 (0x1UL << AS60XX_DE_FW_STORE_LOCK_Pos)          /*!< 0x00020000 */
#define AS60XX_DE_FW_STORE_LOCK_REQUEST             (1)                                             /*!< Requests storing & locking of user firmware program code & data */
#define AS60XX_DE_FW_ERASE_Pos                      (18U)
#define AS60XX_DE_FW_ERASE_Msk                      (0x1UL << AS60XX_DE_FW_ERASE_Pos)               /*!< 0x00040000 */
#define AS60XX_DE_FW_ERASE_REQUEST                  (1)                                             /*!< Requests erasing user firmware program code & data */
#define AS60XX_DE_FWC_RECALL_Pos                    (19U)
#define AS60XX_DE_FWC_RECALL_Msk                    (0x1UL << AS60XX_DE_FWC_RECALL_Pos)             /*!< 0x00080000 */
#define AS60XX_DE_FWC_RECALL_REQUEST                (1)                                             /*!< Requests recalling of firmware program code from Flash to SRAM */
#define AS60XX_DE_FWD_RECALL_Pos                    (20U)
#define AS60XX_DE_FWD_RECALL_Msk                    (0x1UL << AS60XX_DE_FWD_RECALL_Pos)             /*!< 0x00100000 */
#define AS60XX_DE_FWD_RECALL_REQUEST                (1)                                             /*!< Requests recalling of firmware data from Flash to SRAM  */
#define AS60XX_DE_FWC_STORE_Pos                     (21U)
#define AS60XX_DE_FWC_STORE_Msk                     (0x1UL << AS60XX_DE_FWC_STORE_Pos)              /*!< 0x00200000 */
#define AS60XX_DE_FWC_STORE_REQUEST                 (1)                                             /*!< Requests storing of firmware program code from SRAM to Flash  */
#define AS60XX_DE_FWD_STORE_Pos                     (22U)
#define AS60XX_DE_FWD_STORE_Msk                     (0x1UL << AS60XX_DE_FWD_STORE_Pos)              /*!< 0x00400000 */
#define AS60XX_DE_FWD_STORE_REQUEST                 (1)                                             /*!< Requests storing of user firmware data from SRAM to Flash  */
#define AS60XX_DE_NOT_USED_31_23_Pos                (30U)
#define AS60XX_DE_NOT_USED_31_23_Msk                (0x1FFUL << AS60XX_DE_NOT_USED_31_23_Pos)       /*!< 0xFF800000 */
#define AS60XX_DE_NOT_USED_31_23                    (0)                                             /*!< NOT_USED_31_23[31:23]Not used */

/******************  Bit definition for AS60XX_DF register  *******************/
#define AS60XX_DF_RC_RLS_Pos                        (0U)
#define AS60XX_DF_RC_RLS_Msk                        (0xFFFFFFFFUL << AS60XX_DD_CFG_OK_Pos)          /*!< 0xFFFFFFFF */
#define AS60XX_DF_RC_RLS_1                          (0x50F5B8CA)                                    /*!< Release code for dedicated self-clearing bits in SHR_RC, Releases bits [22:16] */
#define AS60XX_DF_RC_RLS_2                          (0xAF0A4735)                                    /*!< Release code for dedicated self-clearing bits in SHR_RC, Releases bits [15:14] */

/******************  Bit definition for AS60XX_E0 register  *******************/
#define AS60XX_E0_TSQ_FNS_Pos                       (0U)
#define AS60XX_E0_TSQ_FNS_Msk                       (0x1UL << AS60XX_E0_TSQ_FNS_Pos)                /*!< 0x00000001 */
#define AS60XX_E0_TSQ_FNS                           (1)                                             /*!< Task sequencer finished */
#define AS60XX_E0_FW_TRANS_FNS_Pos                  (1U)
#define AS60XX_E0_FW_TRANS_FNS_Msk                  (0x1UL << AS60XX_E0_FW_TRANS_FNS_Pos)           /*!< 0x00000002 */
#define AS60XX_E0_FW_TRANS_FNS                      (1)                                             /*!< Firmware transaction finished */
#define AS60XX_E0_BLD_FNS_Pos                       (2U)
#define AS60XX_E0_BLD_FNS_Msk                       (0x1UL << AS60XX_E0_BLD_FNS_Pos)                /*!< 0x00000004 */
#define AS60XX_E0_BLD_FNS                           (1)                                             /*!< Bootloader finished */
#define AS60XX_E0_CHKSUM_FNS_Pos                    (3U)
#define AS60XX_E0_CHKSUM_FNS_Msk                    (0x1UL << AS60XX_E0_CHKSUM_FNS_Pos)             /*!< 0x00000008 */
#define AS60XX_E0_CHKSUM_FNS                        (1)                                             /*!< Checksum subroutine finished */
#define AS60XX_E0_FW_IRQ_S_Pos                      (4U)
#define AS60XX_E0_FW_IRQ_S_Msk                      (0x1UL << AS60XX_E0_FW_IRQ_S_Pos)               /*!< 0x00000010 */
#define AS60XX_E0_FW_IRQ_S                          (1)                                             /*!< Firmware interrupt request, synchronized with task sequencer */
#define AS60XX_E0_TSQ_TMO_Pos                       (5U)
#define AS60XX_E0_TSQ_TMO_Msk                       (0x1UL << AS60XX_E0_TSQ_TMO_Pos)                /*!< 0x00000020 */
#define AS60XX_E0_TSQ_TMO                           (1)                                             /*!< Task sequencer timeout */
#define AS60XX_E0_NOT_USED_6_Pos                    (6U)
#define AS60XX_E0_NOT_USED_6_Msk                    (0x1UL << AS60XX_E0_NOT_USED_6_Pos)             /*!< 0x00000040 */
#define AS60XX_E0_NOT_USED_6                        (0)                                             /*!< Not used */
#define AS60XX_E0_ERR_FLAG_Pos                      (7U)
#define AS60XX_E0_ERR_FLAG_Msk                      (0x1UL << AS60XX_E0_ERR_FLAG_Pos)               /*!< 0x00000080 */
#define AS60XX_E0_ERR_FLAG                          (1)                                             /*!< At least 1 error flag is set */
#define AS60XX_E0_NOT_USED_31_8_Pos                 (8U)
#define AS60XX_E0_NOT_USED_31_8_Msk                 (0xFFFFFFUL << AS60XX_E0_NOT_USED_31_8_Pos)     /*!< 0xFFFFFF00 */
#define AS60XX_E0_NOT_USED_31_8                     (0)                                             /*!< NOT_USED_31_8[31:8]Not used */

/******************  Bit definition for AS60XX_E1 register  *******************/
#define AS60XX_E1_EF_TDC_TMO_Pos                    (0U)
#define AS60XX_E1_EF_TDC_TMO_Msk                    (0x1UL << AS60XX_E1_EF_TDC_TMO_Pos)             /*!< 0x00000001 */
#define AS60XX_E1_EF_TDC_TMO                        (1)                                             /*!< Error flag TDC timeout */
#define AS60XX_E1_EF_TOF_TMO_Pos                    (1U)
#define AS60XX_E1_EF_TOF_TMO_Msk                    (0x1UL << AS60XX_E1_EF_TOF_TMO_Pos)             /*!< 0x00000002 */
#define AS60XX_E1_EF_TOF_TMO                        (1)                                             /*!< Error flag TOF timeout */
#define AS60XX_E1_EF_AM_TMO_Pos                     (2U)
#define AS60XX_E1_EF_AM_TMO_Msk                     (0x1UL << AS60XX_E1_EF_AM_TMO_Pos)              /*!< 0x00000004 */
#define AS60XX_E1_EF_AM_TMO                         (1)                                             /*!< Error flag amplitude measurement timeout */
#define AS60XX_E1_EF_TM_OC_ERR_Pos                  (3U)
#define AS60XX_E1_EF_TM_OC_ERR_Msk                  (0x1UL << AS60XX_E1_EF_TM_OC_ERR_Pos)           /*!< 0x00000008 */
#define AS60XX_E1_EF_TM_OC_ERR                      (1)                                             /*!< Error flag temperature measurement open circuit */
#define AS60XX_E1_EF_TM_SC_ERR_Pos                  (4U)
#define AS60XX_E1_EF_TM_SC_ERR_Msk                  (0x1UL << AS60XX_E1_EF_TM_SC_ERR_Pos)           /*!< 0x00000010 */
#define AS60XX_E1_EF_TM_SC_ERR                      (1)                                             /*!< Error flag temperature measurement short circuit */
#define AS60XX_E1_EF_ZCC_ERR_Pos                    (5U)
#define AS60XX_E1_EF_ZCC_ERR_Msk                    (0x1UL << AS60XX_E1_EF_ZCC_ERR_Pos)             /*!< 0x00000020 */
#define AS60XX_E1_EF_ZCC_ERR                        (1)                                             /*!< Error flag zero cross calibration */
#define AS60XX_E1_EF_LBD_ERR_Pos                    (6U)
#define AS60XX_E1_EF_LBD_ERR_Msk                    (0x1UL << AS60XX_EF_LBD_ERR_Pos)                /*!< 0x00000040 */
#define AS60XX_E1_EF_LBD_ERR                        (1)                                             /*!< Error flag low battery detect */
#define AS60XX_E1_EF_USM_SQC_TMO_Pos                (7U)
#define AS60XX_E1_EF_USM_SQC_TMO_Msk                (0x1UL << AS60XX_E1_EF_USM_SQC_TMO_Pos)         /*!< 0x00000080 */
#define AS60XX_E1_EF_USM_SQC_TMO                    (1)                                             /*!< Error flag ultrasonic sequence timeout */
#define AS60XX_E1_EF_TM_SQC_TMO_Pos                 (8U)
#define AS60XX_E1_EF_TM_SQC_TMO_Msk                 (0x1UL << AS60XX_E1_EF_TM_SQC_TMO_Pos)          /*!< 0x00000100 */
#define AS60XX_E1_EF_TM_SQC_TMO                     (1)                                             /*!< Error flag temperature sequence timeout */
#define AS60XX_E1_EF_TSQ_TMO_Pos                    (9U)
#define AS60XX_E1_EF_TSQ_TMO_Msk                    (0x1UL << AS60XX_E1_EF_TSQ_TMO_Pos)             /*!< 0x00000200 */
#define AS60XX_E1_EF_TSQ_TMO                        (1)                                             /*!< Error flag task sequencer timeout */
#define AS60XX_E1_EF_I2C_ACK_ERR_Pos                (10U)
#define AS60XX_E1_EF_I2C_ACK_ERR_Msk                (0x1UL << AS60XX_E1_EF_I2C_ACK_ERR_Pos)         /*!< 0x00000400 */
#define AS60XX_E1_EF_I2C_ACK_ERR                    (1)                                             /*!< Error flag EEPROM acknowledge */
#define AS60XX_E1_EF_CHP_ERR_Pos                    (11U)
#define AS60XX_E1_EF_CHP_ERR_Msk                    (0x1UL << AS60XX_E1_EF_CHP_ERR_Pos)             /*!< 0x00000800 */
#define AS60XX_E1_EF_CHP_ERR                        (1)                                             /*!< Error flag charge pump error */
#define AS60XX_E1_EF_NVM_FWCU_ERR_Pos               (12U)
#define AS60XX_E1_EF_NVM_FWCU_ERR_Msk               (0x1UL << AS60XX_E1_EF_NVM_FWCU_ERR_Pos)        /*!< 0x00001000 */
#define AS60XX_E1_EF_NVM_FWCU_ERR                   (1)                                             /*!< Error flag NVM error in FWCU area */
#define AS60XX_E1_EF_NVM_FWDU_ERR_Pos               (13U)
#define AS60XX_E1_EF_NVM_FWDU_ERR_Msk               (0x1UL << AS60XX_E1_EF_NVM_FWDU_ERR_Pos)        /*!< 0x00002000 */
#define AS60XX_E1_EF_NVM_FWDU_ERR                   (1)                                             /*!< Error flag NVM error in FWDU area */
#define AS60XX_E1_EF_NVM_FWA_ERR_Pos                (14U)
#define AS60XX_E1_EF_NVM_FWA_ERR_Msk                (0x1UL << AS60XX_E1_EF_NVM_FWA_ERR_Pos)         /*!< 0x00004000 */
#define AS60XX_E1_EF_NVM_FWA_ERR                    (1)                                             /*!< Error flag NVM error in any FWA area or set by FW */
#define AS60XX_E1_EF_CPU_ERR_Pos                    (15U)
#define AS60XX_E1_EF_CPU_ERR_Msk                    (0x1UL << AS60XX_E1_EF_CPU_ERR_Pos)             /*!< 0x00008000 */
#define AS60XX_E1_EF_CPU_ERR                        (1)                                             /*!< CPU error (invalid program counter or PC stack overflow) */
#define AS60XX_E1_NOT_USED_31_16_Pos                (8U)
#define AS60XX_E1_NOT_USED_31_16_Msk                (0xFFFFUL << AS60XX_E1_NOT_USED_31_16_Pos)      /*!< 0xFFFF0000 */
#define AS60XX_E1_NOT_USED_31_16                    (0)                                             /*!< NOT_USED_31_16[31:16]Not used */

/******************  Bit definition for AS60XX_E2 register  *******************/
#define AS60XX_E2_HCC_UPD_Pos                       (0U)
#define AS60XX_E2_HCC_UPD_Msk                       (0x1UL << AS60XX_E2_HCC_UPD_Pos)                /*!< 0x00000001 */
#define AS60XX_E2_HCC_UPD                           (1)                                             /*!< High-Speed Clock Calibration Update, Updated value in SRR_HCC_VAL */
#define AS60XX_E2_TM_UPD_Pos                        (1U)
#define AS60XX_E2_TM_UPD_Msk                        (0x1UL << AS60XX_E2_TM_UPD_Pos)                 /*!< 0x00000002 */
#define AS60XX_E2_TM_UPD                            (1)                                             /*!< Updated value in temperature measurement related frontend buffer */
#define AS60XX_E2_NOT_USED_2_Pos                    (2U)
#define AS60XX_E2_NOT_USED_2_Msk                    (0x1UL << AS60XX_E2_NOT_USED_2_Pos)             /*!< 0x00000004 */
#define AS60XX_E2_NOT_USED_2                        (1)                                             /*!< Not used */
#define AS60XX_E2_TPM_ST_Pos                        (3U)
#define AS60XX_E2_TPM_ST_Msk                        (0x1UL << AS60XX_E2_TPM_ST_Pos)                 /*!< 0x00000008 */
#define AS60XX_E2_TPM_ST_0                          (0)                                             /*!< Temperature measurement with 1 subtask */
#define AS60XX_E2_TPM_ST_1                          (1)                                             /*!< Temperature measurement with 2 subtasks */
#define AS60XX_E2_US_U_UPD_Pos                      (4U)
#define AS60XX_E2_US_U_UPD_Msk                      (0x1UL << AS60XX_E2_US_U_UPD_Pos)               /*!< 0x00000010 */
#define AS60XX_E2_US_U_UPD                          (1)                                             /*!< Updated value in ultrasonic up area of frontend buffer */
#define AS60XX_E2_US_D_UPD_Pos                      (5U)
#define AS60XX_E2_US_D_UPD_Msk                      (0x1UL << AS60XX_E2_US_D_UPD_Pos)               /*!< 0x00000020 */
#define AS60XX_E2_US_D_UPD                          (1)                                             /*!< Updated value in ultrasonic down area of frontend buffer */
#define AS60XX_E2_US_TOF_UPD_Pos                    (6U)
#define AS60XX_E2_US_TOF_UPD_Msk                    (0x1UL << AS60XX_E2_US_TOF_UPD_Pos)             /*!< 0x00000040 */
#define AS60XX_E2_US_TOF_UPD                        (1)                                             /*!< Updated value in TOF area of frontend buffer */
#define AS60XX_E2_US_TOF_EDGE_Pos                   (7U)
#define AS60XX_E2_US_TOF_EDGE_Msk                   (0x1UL << AS60XX_E2_US_TOF_EDGE_Pos)            /*!< 0x00000080 */
#define AS60XX_E2_US_TOF_EDGE_POS                   (0)                                             /*!< TOF Measurement positive edge */
#define AS60XX_E2_US_TOF_EDGE_NEG                   (1)                                             /*!< TOF Measurement negative edge */
#define AS60XX_E2_US_AM_UPD_Pos                     (8U)
#define AS60XX_E2_US_AM_UPD_Msk                     (0x1UL << AS60XX_E2_US_D_UPD_Pos)               /*!< 0x00000100 */
#define AS60XX_E2_US_AM_UPD                         (1)                                             /*!< Updated value in ultrasonic down area of frontend buffer */
#define AS60XX_E2_US_AMC_UPD_Pos                    (9U)
#define AS60XX_E2_US_AMC_UPD_Msk                    (0x1UL << AS60XX_E2_US_AMC_UPD_Pos)             /*!< 0x00000200 */
#define AS60XX_E2_US_AMC_UPD                        (1)                                             /*!< Updated value in AMC area of frontend buffer */
#define AS60XX_E2_NOT_USED_31_10_Pos                (10U)
#define AS60XX_E2_NOT_USED_31_10_Msk                (0x3FFFFFUL << AS60XX_E2_NOT_USED_31_10_Pos)    /*!< 0xFFFFFC00 */
#define AS60XX_E2_NOT_USED_31_10                    (0)                                             /*!< NOT_USED_31_10[31:10]Not used */

/******************  Bit definition for AS60XX_E3 register  *******************/
#define AS60XX_E3_GPI_Pos                           (0U)
#define AS60XX_E3_GPI_Msk                           (0x3FUL << AS60XX_E3_GPI_Pos)                   /*!< 0x0000003F */
#define AS60XX_E3_GPI_0                             (0)                                             /*!< General Purpose Input */
#define AS60XX_E3_GPI_1                             (1)                                             /*!< General Purpose Input */
#define AS60XX_E3_GPI_2                             (2)                                             /*!< General Purpose Input */
#define AS60XX_E3_GPI_3                             (3)                                             /*!< General Purpose Input */
#define AS60XX_E3_GPI_4                             (4)                                             /*!< General Purpose Input */
#define AS60XX_E3_GPI_5                             (5)                                             /*!< General Purpose Input */
#define AS60XX_E3_NOT_USED_7_6_Pos                  (6U)
#define AS60XX_E3_NOT_USED_7_6_Msk                  (0x3UL << AS60XX_E3_NOT_USED_7_6_Pos)           /*!< 0x000000C0 */
#define AS60XX_E3_NOT_USED_7_6                      (0)                                             /*!< NOT_USED_7_6[7:6]Not used */
#define AS60XX_E3_LP_MODE_Pos                       (8U)
#define AS60XX_E3_LP_MODE_Msk                       (0x1UL << AS60XX_E3_LP_MODE_Pos)                /*!< 0x00000100 */
#define AS60XX_E3_LP_MODE                           (1)                                             /*!< Low Power Mode */
#define AS60XX_E3_NOT_USED_31_9_Pos                 (9U)
#define AS60XX_E3_NOT_USED_31_9_Msk                 (0x7FFFFFUL << AS60XX_E3_NOT_USED_31_9_Pos)     /*!< 0xFFFFFE00 */
#define AS60XX_E3_NOT_USED_31_9                     (0)                                             /*!< NOT_USED_31_9[31:9]Not used */

/******************  Bit definition for AS60XX_E4 register  *******************/
#define AS60XX_E4_HCC_VAL_Pos                       (0U)
#define AS60XX_E4_HCC_VAL_Msk                       (0x3FFFFFFFUL << AS60XX_E4_HCC_VAL_Pos)         /*!< 0x03FFFFFF */
#define AS60XX_E4_NOT_USED_31_26_Pos                (26U)
#define AS60XX_E4_NOT_USED_31_26_Msk                (0x3FUL << AS60XX_E4_NOT_USED_31_26_Pos)        /*!< 0xFC000000 */
#define AS60XX_E4_NOT_USED_31_26                    (0)                                             /*!< NOT_USED_31_26[31:26]Not used */

/******************  Bit definition for AS60XX_E5 register  *******************/
#define AS60XX_E5_VCC_VAL_Pos                       (0U)
#define AS60XX_E5_VCC_VAL_Msk                       (0x3FUL << AS60XX_E5_VCC_VAL_Pos)               /*!< 0x0000003F */
#define AS60XX_E5_NOT_USED_31_6_Pos                 (6U)
#define AS60XX_E5_NOT_USED_31_6_Msk                 (0x3FFFFFFFUL << AS60XX_E5_NOT_USED_31_6_Pos)   /*!< 0xFFFFFFC0 */
#define AS60XX_E5_NOT_USED_31_6                     (0)                                             /*!< NOT_USED_31_6[31:6]Not used */

/******************  Bit definition for AS60XX_E6 register  *******************/
#define AS60XX_E6_TS_HOUR_Pos                       (0U)
#define AS60XX_E6_TS_HOUR_Msk                       (0x3FFFFFUL << AS60XX_E6_TS_HOUR_Pos)           /*!< 0x0003FFFF */
#define AS60XX_E6_NOT_USED_31_18_Pos                (18U)
#define AS60XX_E6_NOT_USED_31_18_Msk                (0x3FFFUL << AS60XX_E6_NOT_USED_31_18_Pos)      /*!< 0xFFFC0000 */
#define AS60XX_E6_NOT_USED_31_18                    (0)                                             /*!< NOT_USED_31_18[31:18]Not used */

/******************  Bit definition for AS60XX_E7 register  *******************/
#define AS60XX_E7_TS_SEC_Pos                        (0U)
#define AS60XX_E7_TS_SEC_Msk                        (0xFFUL << AS60XX_E7_TS_SEC_Pos)                /*!< 0x00000FFF */
#define AS60XX_E7_TS_MIN_Pos                        (8U)
#define AS60XX_E7_TS_MIN_Msk                        (0xFFUL << AS60XX_E7_TS_MIN_Pos)                /*!< 0x0000FF00 */
#define AS60XX_E7_NOT_USED_31_16_Pos                (16U)
#define AS60XX_E7_NOT_USED_31_16_Msk                (0xFFFFUL << AS60XX_E7_NOT_USED_31_16_Pos)      /*!< 0xFFFF0000 */
#define AS60XX_E7_NOT_USED_31_16                    (0)                                             /*!< NOT_USED_31_16[31:16]Not used */

/******************  Bit definition for AS60XX_E9 register  *******************/
#define AS60XX_E9_TS_TIME_Pos                       (0U)
#define AS60XX_E9_TS_TIME_Msk                       (0xFFFUL << AS60XX_E9_TS_TIME_Pos)              /*!< 0x00000FFF */
#define AS60XX_E9_NOT_USED_31_12_Pos                (12U)
#define AS60XX_E9_NOT_USED_31_12_Msk                (0xFFFFFUL << AS60XX_E9_NOT_USED_31_12_Pos)     /*!< 0xFFFFF000 */
#define AS60XX_E9_NOT_USED_31_12                    (0)                                             /*!< NOT_USED_31_12[31:12]Not used */

/******************  Bit definition for AS60XX_EA register  *******************/
#define AS60XX_EA_RC_RLS_1_Pos                      (0U)
#define AS60XX_EA_RC_RLS_1_Msk                      (0x1UL << AS60XX_EA_RC_RLS_1_Pos)               /*!< 0x00000001 */
#define AS60XX_EA_RC_RLS_1                          (1)                                             /*!< Release 1 of remote communication self-clearing bits */
#define AS60XX_EA_STUP_TO_Pos                       (1U)
#define AS60XX_EA_STUP_TO_Msk                       (0x1UL << AS60XX_EA_STUP_TO_Pos)                /*!< 0x00000002 */
#define AS60XX_EA_STUP_TO                           (1)                                             /*!< Start-up timeout */
#define AS60XX_EA_FW_UNLOCKED_Pos                   (2U)
#define AS60XX_EA_FW_UNLOCKED_Msk                   (0x1UL << AS60XX_EA_FW_UNLOCKED_Pos)            /*!< 0x00000004 */
#define AS60XX_EA_FW_UNLOCKED                       (1)                                             /*!< FW unlocked */
#define AS60XX_EA_SI_BUSY_Pos                       (3U)
#define AS60XX_EA_SI_BUSY_Msk                       (0x1UL << AS60XX_EA_SI_BUSY_Pos)                /*!< 0x00000008 */
#define AS60XX_EA_SI_BUSY                           (1)                                             /*!< Serial remote interface busy */
#define AS60XX_EA_COM_REQ_Pos                       (4U)
#define AS60XX_EA_COM_REQ_Msk                       (0x1UL << AS60XX_EA_COM_REQ_Pos)                /*!< 0x00000010 */
#define AS60XX_EA_COM_REQ                           (1)                                             /*!< Communication request by remote interface */
#define AS60XX_EA_GPR_REQ_Pos                       (5U)
#define AS60XX_EA_GPR_REQ_Msk                       (0x1UL << AS60XX_EA_GPR_REQ_Pos)                /*!< 0x00000020 */
#define AS60XX_EA_GPR_REQ                           (1)                                             /*!< General purpose request by remote interface */
#define AS60XX_EA_GPT_REQ_Pos                       (6U)
#define AS60XX_EA_GPT_REQ_Msk                       (0x1UL << AS60XX_EA_GPT_REQ_Pos)                /*!< 0x00000040 */
#define AS60XX_EA_GPT_REQ                           (1)                                             /*!< General purpose request by GP timer */
#define AS60XX_EA_GPH_REQ_Pos                       (7U)
#define AS60XX_EA_GPH_REQ_Msk                       (0x1UL << AS60XX_EA_GPH_REQ_Pos)                /*!< 0x00000080 */
#define AS60XX_EA_GPH_REQ                           (1)                                             /*!< General purpose request by GPH_TRIG in SHR_EXC */
#define AS60XX_EA_MCT_RLS_Pos                       (8U)
#define AS60XX_EA_MCT_RLS_Msk                       (0x1UL << AS60XX_EA_MCT_RLS_Pos)                /*!< 0x00000100 */
#define AS60XX_EA_MCT_RLS                           (1)                                             /*!< Measure cycle timer release */
#define AS60XX_EA_NVM_RDY_Pos                       (9U)
#define AS60XX_EA_NVM_RDY_Msk                       (0x1UL << AS60XX_EA_NVM_RDY_Pos)                /*!< 0x00000200 */
#define AS60XX_EA_NVM_RDY                           (1)                                             /*!< NVRAM ready */
#define AS60XX_EA_NVR_REQ_Pos                       (10U)
#define AS60XX_EA_NVR_REQ_Msk                       (0x1UL << AS60XX_EA_NVR_REQ_Pos)                /*!< 0x00000400 */
#define AS60XX_EA_NVR_REQ                           (1)                                             /*!< Request by NVRAM recall timer */
#define AS60XX_EA_NOT_USED_11_Pos                   (11U)
#define AS60XX_EA_NOT_USED_11_Msk                   (0xFFFFFUL << AS60XX_EA_NOT_USED_11_Pos)        /*!< 0x00000800 */
#define AS60XX_EA_NOT_USED_11                       (0)                                             /*!< Not used */
#define AS60XX_EA_HSO_ST_TO_Pos                     (12U)
#define AS60XX_EA_HSO_ST_TO_Msk                     (0x1UL << AS60XX_EA_HSO_ST_TO_Pos)              /*!< 0x00001000 */
#define AS60XX_EA_HSO_ST_TO                         (1)                                             /*!< High speed oscillator settling timeout */
#define AS60XX_EA_I2C_ACK_Pos                       (13U)
#define AS60XX_EA_I2C_ACK_Msk                       (0x1UL << AS60XX_EA_I2C_ACK_Pos)                /*!< 0x00002000 */
#define AS60XX_EA_I2C_ACK                           (1)                                             /*!< 2-wire interface acknowledge */
#define AS60XX_EA_I2C_BSY_Pos                       (14U)
#define AS60XX_EA_I2C_BSY_Msk                       (0x1UL << AS60XX_EA_I2C_BSY_Pos)                /*!< 0x00004000 */
#define AS60XX_EA_I2C_BSY                           (1)                                             /*!< 2-wire interface busy */
#define AS60XX_EA_WD_DIS_Pos                        (15U)
#define AS60XX_EA_WD_DIS_Msk                        (0x1UL << AS60XX_EA_WD_DIS_Pos)                 /*!< 0x00008000 */
#define AS60XX_EA_WD_DIS                            (1)                                             /*!< Watchdog disabled */
#define AS60XX_EA_RC_RLS_2_Pos                      (16U)
#define AS60XX_EA_RC_RLS_2_Msk                      (0x1UL << AS60XX_EA_RC_RLS_2_Pos)               /*!< 0x00010000 */
#define AS60XX_EA_RC_RLS_2                          (1)                                             /*!< Release 2 of remote communication self-clearing bits */
#define AS60XX_EA_NOT_USED_31_17_Pos                (17U)
#define AS60XX_EA_NOT_USED_31_17_Msk                (0x7FFFUL << AS60XX_EA_NOT_USED_31_17_Pos)      /*!< 0xFFFE0000 */
#define AS60XX_EA_NOT_USED_31_17                    (0)                                             /*!< NOT_USED_31_17[31:17]Not used */

/******************  Bit definition for AS60XX_EB register  *******************/
#define AS60XX_EB_I2C_DATA_Pos                      (0U)
#define AS60XX_EB_I2C_DATA_Msk                      (0xFFUL << AS60XX_EB_I2C_DATA_Pos)              /*!< 0x000000FF */
#define AS60XX_EB_NOT_USED_31_8_Pos                 (8U)
#define AS60XX_EB_NOT_USED_31_8_Msk                 (0xFFFFFFUL << AS60XX_EB_NOT_USED_31_8_Pos)     /*!< 0xFFFFFF00 */
#define AS60XX_EB_NOT_USED_31_8                     (0)                                             /*!< NOT_USED_31_8[31:8]Not used */

/******************  Bit definition for AS60XX_EC register  *******************/
#define AS60XX_EC_FWU_RNG_Pos                       (0U)
#define AS60XX_EC_FWU_RNG_Msk                       (0xFFFUL << AS60XX_EC_FWU_RNG_Pos)              /*!< 0x00000FFF */
#define AS60XX_EC_NOT_USED_31_12_Pos                (12U)
#define AS60XX_EC_NOT_USED_31_12_Msk                (0xFFFFFUL << AS60XX_EC_NOT_USED_31_12_Pos)     /*!< 0xFFFFF000 */
#define AS60XX_EC_NOT_USED_31_12                    (0)                                             /*!< NOT_USED_31_12[31:12]Not used */

/******************  Bit definition for AS60XX_ED register  *******************/
#define AS60XX_ED_FWU_REV_Pos                       (0U)
#define AS60XX_ED_FWU_REV_Msk                       (0xFFFFFFFFUL << AS60XX_ED_FWU_REV_Pos)         /*!< 0xFFFFFFFF */

/******************  Bit definition for AS60XX_EE register  *******************/
#define AS60XX_EE_FWA_REV_Pos                       (0U)
#define AS60XX_EE_FWA_REV_Msk                       (0xFFFFFFFFUL << AS60XX_EE_FWA_REV_Pos)         /*!< 0xFFFFFFFF */

/**************  Bit definition for AS60XX_SYS_STATUS register  ***************/
#define AS60XX_SYS_STATUS_RAA_BUSY_Pos              (0U)
#define AS60XX_SYS_STATUS_RAA_BUSY_Msk              (0x01UL << AS60XX_SYS_STATUS_RAA_BUSY_Pos)      /*!< 0x01 */
#define AS60XX_SYS_STATUS_NOT_USED_Pos              (1U)
#define AS60XX_SYS_STATUS_NOT_USED_Msk              (0x01UL << AS60XX_SYS_STATUS_NOT_USED_Pos)      /*!< 0x02 */
#define AS60XX_SYS_STATUS_MT_REQ_CTR_Pos            (2U)
#define AS60XX_SYS_STATUS_MT_REQ_CTR_Msk            (0x03UL << AS60XX_SYS_STATUS_MT_REQ_CTR_Pos)    /*!< 0x04 */
#define AS60XX_SYS_STATUS_MCT_STATE_Pos             (4U)
#define AS60XX_SYS_STATUS_MCT_STATE_Msk             (0x01UL << AS60XX_SYS_STATUS_MCT_STATE_Pos)     /*!< 0x10 */
#define AS60XX_SYS_STATUS_COM_FAIL_Pos              (5U)
#define AS60XX_SYS_STATUS_COM_FAIL_Msk              (0x01UL << AS60XX_SYS_STATUS_COM_FAIL_Pos)      /*!< 0x20 */
#define AS60XX_SYS_STATUS_RST_FLAG_Pos              (6U)
#define AS60XX_SYS_STATUS_RST_FLAG_Msk              (0x01UL << AS60XX_SYS_STATUS_RST_FLAG_Pos)      /*!< 0x40 */
#define AS60XX_SYS_STATUS_ERR_FLAG_Pos              (7U)
#define AS60XX_SYS_STATUS_ERR_FLAG_Msk              (0x01UL << AS60XX_SYS_STATUS_ERR_FLAG_Pos)      /*!< 0x80 */

/**************  Bit definition for AS60XX_FDB_US_PW registers  ***************/
#define AS60XX_FDB_US_PW_FRACTIONAL_Pos             (0U)
#define AS60XX_FDB_US_PW_FRACTIONAL_Msk             (0x7FUL << AS60XX_FDB_US_PW_FRACTIONAL_Pos)     /*!< 0x0000007F */
#define AS60XX_FDB_US_PW_DECIMAL_Pos                (7U)
#define AS60XX_FDB_US_PW_DECIMAL_Msk                (0x01UL << AS60XX_FDB_US_PW_DECIMAL_Pos)        /*!< 0x00000080 */

/****************************  Opcode definition  *****************************/
#define AS60XX_OC_RC_SYS_RST                        (0x99U)                                         /*!< Resets main part of digital core including register part and triggers bootloading process                  */
#define AS60XX_OC_RC_SYS_INIT                       (0x9AU)                                         /*!< Resets main part of digital core without register part and triggers bootloading process                    */
#define AS60XX_OC_RC_SV_INIT                        (0x9CU)                                         /*!< Resets Supervisor, Frontend Processing and CPU in main part of digital core but without a bootload trigger */
#define AS60XX_OC_RC_RAA_WR                         (0x5AU)                                         /*!< Write to RAM or register area                                                                              */
#define AS60XX_OC_RC_RAA_WR_NVRAM                   (0x5BU)                                         /*!< Write to FW data area (NVRAM)                                                                              */
#define AS60XX_OC_RC_RAA_WRS                        (0x5EU)                                         /*!< Write to RAM or register area with read system status before write                                         */
#define AS60XX_OC_RC_RAA_WRS_NVRAM                  (0x5FU)                                         /*!< Write to FW data area (NVRAM) with read system status before write                                         */
#define AS60XX_OC_RC_RAA_RD                         (0x7AU)                                         /*!< Read from RAM or register area                                                                             */
#define AS60XX_OC_RC_RAA_RD_NVRAM                   (0x7BU)                                         /*!< Read from FW data area (NVRAM)                                                                             */
#define AS60XX_OC_RC_RAA_RDS                        (0x7EU)                                         /*!< Read from RAM or register area with read system status before read                                         */
#define AS60XX_OC_RC_RAA_RDS_NVRAM                  (0x7FU)                                         /*!< Read from FW data area (NVRAM) with read system status before read                                         */
#define AS60XX_OC_RC_FWC_WR                         (0x5CU)                                         /*!< Write to FW code area (NVRAM)                                                                              */
#define AS60XX_OC_RC_RD_STATUS                      (0x8FU)                                         /*!< Read system status only                                                                                    */
#define AS60XX_OC_RC_MT_REQ                         (0xDAU)                                         /*!< Measure Task Request                                                                                       */
#define AS60XX_OC_RC_TSC_CLR                        (0x86U)                                         /*!< Time stamp counter clear                                                                                   */
#define AS60XX_OC_RC_BM_RLS                         (0x87U)                                         /*!< Bus Master Release                                                                                         */
#define AS60XX_OC_RC_BM_REQ                         (0x88U)                                         /*!< Bus Master Request                                                                                         */
#define AS60XX_OC_RC_RF_CLR                         (0x89U)                                         /*!< Reset flag clear (RST_FLAG in SYS_STATUS)                                                                  */
#define AS60XX_OC_RC_MCT_OFF                        (0x8AU)                                         /*!< Measure Cycle Timer Off                                                                                    */
#define AS60XX_OC_RC_MCT_ON                         (0x8BU)                                         /*!< Measure Cycle Timer On                                                                                     */
#define AS60XX_OC_RC_GPR_REQ                        (0x8CU)                                         /*!< General Purpose Request                                                                                    */
#define AS60XX_OC_RC_IF_CLR                         (0x8DU)                                         /*!< Interrupt Flags Clear                                                                                      */
#define AS60XX_OC_RC_COM_REQ                        (0x8EU)                                         /*!< Communication Request                                                                                      */
#define AS60XX_OC_RC_FW_CHKSUM                      (0xB8U)                                         /*!< Builds checksum of all FW memories                                                                         */
#define AS60XX_OC_RC_MT_REQ                         (0xDAU)                                         /*!< Measure Task Request                                                                         */

/************  Bit definition for Extended Measure Task Request  **************/
#define AS60XX_EC_MT_REQ_VCC_VOLTAGE_MEASUREMENT    (0x01)                                          /* Bit 0. VCC Voltage Measurement */
#define AS60XX_EC_MT_REQ_TOF_MEASUREMENT            (0x04)                                          /* Bit 2. Time of Flight Measurement */
#define AS60XX_EC_MT_REQ_AMPLITUDE_MEASUREMENT      (0x08)                                          /* Bit 3. Amplitude Measurement */
#define AS60XX_EC_MT_REQ_AMPLITUDE_MEASUREMENT_CAL  (0x10)                                          /* Bit 4. Amplitude Measurement Calibration */
#define AS60XX_EC_MT_REQ_TEMPERATURE_MEASUREMENT    (0x20)                                          /* Bit 5. Temperature Measurement */
#define AS60XX_EC_MT_REQ_HIGH_SPEED_CLOCK_CAL       (0x40)                                          /* Bit 6. High Speed Clock Calibration */
#define AS60XX_EC_MT_REQ_ZERO_CROSS_CAL             (0x80)                                          /* Bit 7. Zero Cross Calibration */

/***************************  Received data type  *****************************/
typedef int8_t AS60xx_Measure_Type;
#define AS60XX_NO_MEASUREMENT                       (0)                                             /* No new measurement */
#define AS60XX_TEMPERATURE_MEASUREMENT              (1)                                             /* A new temperature measurement was read */
#define AS60XX_TOF_MEASUREMENT                      (2)                                             /* A new Time of Flight measurement was read */

/*******************  Error code definitions of ScioSense  ********************/
#ifndef SCIOSENSE_RESULT_CODES
#define SCIOSENSE_RESULT_CODES
typedef int8_t Result;
#define RESULT_TIMEOUT                              (5)                                             /* A timeout was triggered before the result was produced */
#define RESULT_NOT_ALLOWED                          (4)                                             /* The requested command is not allowed */
#define RESULT_CHECKSUM_ERROR                       (3)                                             /* The value was read, but the checksum over the payload (valid and data) does not match */
#define RESULT_INVALID                              (2)                                             /* The value was read, but the data is invalid */
#define RESULT_IO_ERROR                             (1)                                             /* There was an IO communication error, read/write the stream failed */
#define RESULT_OK                                   (0)                                             /* All OK; The value was read, the checksum matches, and data is valid */
#endif

#endif /* INC_AS60XX_BIT_DEFINITION_H_ */
