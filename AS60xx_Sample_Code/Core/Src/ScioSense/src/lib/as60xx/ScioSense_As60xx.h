#ifndef SCIOSENSE_AS60XX_C_H
#define SCIOSENSE_AS60XX_C_H

#include "stddef.h"
#include "ScioSense_As60xx_defines.h"
#include "ScioSense_As6031f1_defines.h"

typedef struct ScioSense_As60xx_IO
{
    Result  (*transfer) (void* config, uint8_t* dataToWrite, const size_t sizeToWrite, uint8_t* dataToRead, const size_t sizeToRead);
    Result  (*write)    (void* config, uint8_t* data, const size_t size);
    void    (*wait)     (const uint32_t ms);
    void*   config;
} ScioSense_As60xx_IO;

typedef struct As60xx_Timestamp
{
    uint32_t    hours;
    uint8_t     minutes;
    uint8_t     seconds;
} As60xx_Timestamp;

typedef enum
{
    ERR_TDC_TMO         = AS60XX_E1_EF_TDC_TMO_Pos,
    ERR_TOF_TMO         = AS60XX_E1_EF_TOF_TMO_Pos,
    ERR_AM_TMO          = AS60XX_E1_EF_AM_TMO_Pos,
    ERR_TM_OC_ERR       = AS60XX_E1_EF_TM_OC_ERR_Pos,
    ERR_TM_SC_ERR       = AS60XX_E1_EF_TM_SC_ERR_Pos,
    ERR_ZCC_ERR         = AS60XX_E1_EF_ZCC_ERR_Pos,
    ERR_LBD_ERR         = AS60XX_E1_EF_LBD_ERR_Pos,
    ERR_USM_SQC_TMO     = AS60XX_E1_EF_USM_SQC_TMO_Pos,
    ERR_TM_SQC_TMO      = AS60XX_E1_EF_TM_SQC_TMO_Pos,
    ERR_TSQ_TMO         = AS60XX_E1_EF_TSQ_TMO_Pos,
    ERR_I2C_ACK_ERR     = AS60XX_E1_EF_I2C_ACK_ERR_Pos,
    ERR_CHP_ERR         = AS60XX_E1_EF_CHP_ERR_Pos,
    ERR_NVM_FWCU_ERR    = AS60XX_E1_EF_NVM_FWCU_ERR_Pos,
    ERR_NVM_FWDU_ERR    = AS60XX_E1_EF_NVM_FWDU_ERR_Pos,
    ERR_NVM_FWA_ERR     = AS60XX_E1_EF_NVM_FWA_ERR_Pos,
    ERR_CPU_ERR         = AS60XX_E1_EF_CPU_ERR_Pos
} As60xx_ErrorFlag;

typedef enum
{
    FW_ERR_HS_CALIB_FAIL        = AS6031F1_BNR_HS_CALIB_FAIL_Pos,
    FW_ERR_AMP_DIFF_TOO_HIGH    = AS6031F1_BNR_AMP_DIFF_TOO_HIGH_Pos,
    FW_ERR_AMP_VAL_TOO_LOW      = AS6031F1_BNR_AMP_VAL_TOO_LOW_Pos,
    FW_ERR_PW_DIFF_NOT_OK       = AS6031F1_BNR_PW_DIFF_NOT_OK_Pos,
    FW_ERR_SUMTOF_DEV           = AS6031F1_BNR_SUMTOF_DEV_Pos,
    FW_ERR_FHL_NOT_OK           = AS6031F1_BNR_FHL_NOT_OK_Pos,
    FW_ERR_MEAS_NOT_OK          = AS6031F1_BNR_MEAS_NOT_OK_Pos,
    FW_ERR_FLOW_BT_2MAX         = AS6031F1_BNR_FLOW_BT_2MAX_Pos,
    FW_ERR_FLOW_LT_NEGLIM       = AS6031F1_BNR_FLOW_LT_NEGLIM_Pos,
    FW_ERR_VOL_ERR              = AS6031F1_BNR_VOL_ERR_Pos,
    FW_ERR_PH_S_FW_VALID_WRG    = AS6031F1_BNR_PH_S_FW_VALID_WRG_Pos,
    FW_ERR_PH_S_FW_JUMP_DET_ERR = AS6031F1_BNR_PH_S_FW_JUMP_DET_ERR_Pos,
    FW_ERR_VEL_ERROR            = AS6031F1_BNR_VEL_ERROR_Pos,
    FW_ERR_BUBBLE               = AS6031F1_BNR_BUBBLE_Pos,
    FW_ERR_NO_WATER             = AS6031F1_BNR_NO_WATER_Pos,
    FW_ERR_TDC_TMO_FW           = AS6031F1_BNR_TDC_TMO_FW_Pos,
    FW_ERR_TOF_TMO_FW           = AS6031F1_BNR_TOF_TMO_FW_Pos,
    FW_ERR_AM_TMO_FW            = AS6031F1_BNR_AM_TMO_FW_Pos,
    FW_ERR_TM_OC_ERR_FW         = AS6031F1_BNR_TM_OC_ERR_FW_Pos,
    FW_ERR_TM_SC_ERR_FW         = AS6031F1_BNR_TM_SC_ERR_FW_Pos,
    FW_ERR_ZCC_ERR              = AS6031F1_BNR_ZCC_ERR_Pos,
    FW_ERR_LBD_ERR              = AS6031F1_BNR_LBD_ERR_Pos,
    FW_ERR_USM_SQC_TMO          = AS6031F1_BNR_USM_SQC_TMO_Pos,
    FW_ERR_TM_SQC_TMO           = AS6031F1_BNR_TM_SQC_TMO_Pos,
    FW_ERR_TSQ_TMO              = AS6031F1_BNR_TSQ_TMO_Pos,
    FW_ERR_E2C_ACK_ERR          = AS6031F1_BNR_E2C_ACK_ERR_Pos,
    FW_ERR_CS_FWD1_ERR          = AS6031F1_BNR_CS_FWD1_ERR_Pos,
    FW_ERR_CS_FWD2_ERR          = AS6031F1_BNR_CS_FWD2_ERR_Pos,
    FW_ERR_CS_FWU_ERR           = AS6031F1_BNR_CS_FWU_ERR_Pos,
    FW_ERR_CS_FWA_ERR           = AS6031F1_BNR_CS_FWA_ERR_Pos
} As6031F1_ErrorFlag;

typedef enum _AS60XX_OpcodeTypeDef
{
    /* Opcode = Hex / Description */
    RC_SYS_RST          = AS60XX_OC_RC_SYS_RST,                   /*!< Resets main part of digital core including register part and triggers bootloading process                  */
    RC_SYS_INIT         = AS60XX_OC_RC_SYS_INIT,                  /*!< Resets main part of digital core without register part and triggers bootloading process                    */
    RC_SV_INIT          = AS60XX_OC_RC_SV_INIT,                   /*!< Resets Supervisor, Frontend Processing and CPU in main part of digital core but without a bootload trigger */
    RC_RAA_WR           = AS60XX_OC_RC_RAA_WR,                    /*!< Write to RAM or register area                                                                              */
    RC_RAA_WR_NVRAM     = AS60XX_OC_RC_RAA_WR_NVRAM,              /*!< Write to FW data area (NVRAM)                                                                              */
    RC_RAA_WRS          = AS60XX_OC_RC_RAA_WRS,                   /*!< Write to RAM or register area with read system status before write                                         */
    RC_RAA_WRS_NVRAM    = AS60XX_OC_RC_RAA_WRS_NVRAM,             /*!< Write to FW data area (NVRAM) with read system status before write                                         */
    RC_RAA_RD           = AS60XX_OC_RC_RAA_RD,                    /*!< Read from RAM or register area                                                                             */
    RC_RAA_RD_NVRAM     = AS60XX_OC_RC_RAA_RD_NVRAM,              /*!< Read from FW data area (NVRAM)                                                                             */
    RC_RAA_RDS          = AS60XX_OC_RC_RAA_RDS,                   /*!< Read from RAM or register area with read system status before read                                         */
    RC_RAA_RDS_NVRAM    = AS60XX_OC_RC_RAA_RDS_NVRAM,             /*!< Read from FW data area (NVRAM) with read system status before read                                         */
    RC_FWC_WR           = AS60XX_OC_RC_FWC_WR,                    /*!< Write to FW code area (NVRAM)                                                                              */
    RC_RD_STATUS        = AS60XX_OC_RC_RD_STATUS,                 /*!< Read system status only                                                                                    */
    RC_MT_REQ           = AS60XX_OC_RC_MT_REQ,                    /*!< Measure Task Request                                                                                       */
    RC_TSC_CLR          = AS60XX_OC_RC_TSC_CLR,                   /*!< Time stamp counter clear                                                                                   */
    RC_BM_RLS           = AS60XX_OC_RC_BM_RLS,                    /*!< Bus Master Release                                                                                         */
    RC_BM_REQ           = AS60XX_OC_RC_BM_REQ,                    /*!< Bus Master Request                                                                                         */
    RC_RF_CLR           = AS60XX_OC_RC_RF_CLR,                    /*!< Reset flag clear (RST_FLAG in SYS_STATUS)                                                                  */
    RC_MCT_OFF          = AS60XX_OC_RC_MCT_OFF,                   /*!< Measure Cycle Timer Off                                                                                    */
    RC_MCT_ON           = AS60XX_OC_RC_MCT_ON,                    /*!< Measure Cycle Timer On                                                                                     */
    RC_GPR_REQ          = AS60XX_OC_RC_GPR_REQ,                   /*!< General Purpose Request                                                                                    */
    RC_IF_CLR           = AS60XX_OC_RC_IF_CLR,                    /*!< Interrupt Flags Clear                                                                                      */
    RC_COM_REQ          = AS60XX_OC_RC_COM_REQ,                   /*!< Communication Request                                                                                      */
    RC_FW_CHKSUM        = AS60XX_OC_RC_FW_CHKSUM                  /*!< Builds checksum of all FW memories                                                                         */
} AS60XX_OpcodeTypeDef;

typedef enum _AS60XX_StateTypeDef
{
    AS60XX_STATE_RESET          = 0x00U,    /*!< Device not Initialized                             */
    AS60XX_STATE_READY          = 0x01U,    /*!< Device Configured, Initialized and ready for use   */
    AS60XX_STATE_BUSY           = 0x02U,    /*!< an internal process is ongoing                     */
    AS60XX_STATE_INTN           = 0x03U,    /*!< Device interrupt state                             */
    AS60XX_STATE_ERROR          = 0x04U,    /*!< Device error state                                 */
    AS60XX_STATE_NOT_CONNECTED  = 0xFFU,    /*!< Device not connect                                 */
} AS60XX_StateTypeDef;

typedef enum _AS60XX_FwTransactionTypeDef
{
    AS60XX_FW_STORE_ALL         = 16,       /*!< Store Firmware Code & Firmware Data                */
    AS60XX_FW_STORE_AND_LOCK    = 17,       /*!< Store & Lock Firmware Program Code & Firmware Data */
    AS60XX_FW_ERASE_AND_UNLOCK  = 18,       /*!< Erase User Firmware Program Code & Firmware Data   */
    AS60XX_FW_CODE_RECALL       = 19,       /*!< Recall Firmware Program Code                       */
    AS60XX_FW_DATA_RECALL       = 20,       /*!< Recall Firmware Data                               */
    AS60XX_FW_CODE_STORE        = 21,       /*!< Store Firmware Program Code                        */
    AS60XX_FW_DATA_STORE        = 22,       /*!< Store Firmware Data (FWDU, user part only)         */
} AS60XX_FwTransactionTypeDef;

typedef struct {
    uint32_t WS_DIS;              /*!< Code to disable Watchdog */
} AS60XX_CR0TypeDef;

typedef struct {
    uint8_t PI_TPW;               /*!< Pulse Interface, Pulse Width */
    uint8_t PI_EN;                /*!< Pulse Interface Enable */
    uint8_t PI_OUT_MODE;          /*!< Pulse Interface Output Mode */
    uint8_t PI_UPD_MODE;          /*!< Pulse Interface Update Mode */
    uint8_t NOT_USED_11;          /*!< Mandatory setting: b0 */
    uint8_t I2C_MODE;             /*!< 2-wire master interface mode */
    uint8_t I2C_ADR;              /*!< 2-wire master interface slave address */
    uint8_t NOT_USED_21;          /*!< Mandatory setting: b0 */
    uint8_t SPI_INPORT_CFG;       /*!< Configuration of SPI input ports */
    uint8_t NOT_USED_31_24;       /*!< Not used */
} AS60XX_CR1TypeDef;

typedef struct {
    uint8_t GP0_DIR;              /*!< Direction of General Purpose Port 0 */
    uint8_t GP0_SEL;              /*!< Output Select of General Purpose Port 0 */
    uint8_t GP1_DIR;              /*!< Direction of General Purpose Port 1 */
    uint8_t GP1_SEL;              /*!< Output Select of General Purpose Port 1 */
    uint8_t GP2_DIR;              /*!< Direction of General Purpose Port 2 */
    uint8_t GP2_SEL;              /*!< Output Select of General Purpose Port 2 */
    uint8_t GP3_DIR;              /*!< Direction of General Purpose Port 3 */
    uint8_t GP3_SEL;              /*!< Output Select of General Purpose Port 3 */
    uint8_t GP4_DIR;              /*!< Direction of General Purpose Port 4 */
    uint8_t GP4_SEL;              /*!< Output Select of General Purpose Port 4 */
    uint8_t GP5_DIR;              /*!< Direction of General Purpose Port 5 */
    uint8_t GP5_SEL;              /*!< Output Select of General Purpose Port 5 */
    uint8_t NOT_USED_31_24;       /*!< Not used */
} AS60XX_CR2TypeDef;

typedef struct {
    uint8_t USM_OPT;              /*!< Mandatory setting: b00001 */
    uint32_t NOT_USED_31_5;       /*!< Not used */
} AS60XX_CR3TypeDef;

typedef struct {
    uint8_t EF_EN_TDC_TMO;        /*!< Error Flag Enable, TDC Timeout */
    uint8_t EF_EN_TOF_TMO;        /*!< Error Flag Enable, TOF Timeout */
    uint8_t EF_EN_AM_TMO;         /*!< Error Flag Enable, Amplitude Measurement Timeout */
    uint8_t EF_EN_TM_OC;          /*!< Error Flag Enable, Temperature Measurement Open Circuit */
    uint8_t EF_EN_TM_SC;          /*!< Error Flag Enable, Temperature Measurement Short Circuit */
    uint8_t EF_EN_ZCC_ERR;        /*!< Error Flag Enable, Zero Cross Calibration Error */
    uint8_t EF_EN_LBD_ERR;        /*!< Error Flag Enable, Low Battery Detect Error */
    uint8_t EF_EN_USM_SQC_TMO;    /*!< Error Flag Enable, Ultrasonic Sequence Timeout */
    uint8_t EF_EN_TM_SQC_TMO;     /*!< Error Flag Enable, Temperature Sequence Timeout */
    uint8_t EF_EN_TSQ_TMO;        /*!< Error Flag Enable, Task Sequencer Timeout */
    uint8_t EF_EN_I2C_ACK_ERR;    /*!< Error Flag Enable, EEPROM Acknowledge Error */
    uint8_t EF_EN_CHP_ERR;        /*!< Error Flag Enable, Charge pump error */
    uint8_t EF_EN_NVM_FWCU_ERR;   /*!< Error Flag Enable, NVM FWCU Error */
    uint8_t EF_EN_NVM_FWDU_ERR;   /*!< Error Flag Enable, NVM FWDU Error */
    uint8_t EF_EN_NVM_FWA_ERR;    /*!< Error Flag Enable, NVM Applied Firmware Error */
    uint8_t EF_EN_CPU_ERR;        /*!< Error Flag Enable, CPU Error */
    uint8_t IRQ_EN_TSQ_FNS;       /*!< Interrupt Request Enable, Task Sequencer finished */
    uint8_t IRQ_EN_TRANS_FNS;     /*!< Interrupt Request Enable, FW Transaction finished */
    uint8_t IRQ_EN_BLD_FNS;       /*!< Interrupt Request Enable, Bootload finished */
    uint8_t IRQ_EN_CHKSUM_FNS;    /*!< Interrupt Request Enable, Checksum generation finished */
    uint8_t IRQ_EN_FW_S;          /*!< Interrupt Request Enable, Firmware, synchronized with task sequencer */
    uint8_t IRQ_EN_TSQ_TO;        /*!< Interrupt Request Enable, Firmware */
    uint8_t NOT_USED_22;          /*!< Mandatory setting: b0 */
    uint8_t IRQ_EN_ERR_FLAG;      /*!< Interrupt Request Enable, Error Flag */
    uint8_t NOT_USED_26_24;       /*!< Mandatory setting: b000 */
    uint8_t CPU_REQ_EN_GPH;       /*!< CPU Request Enable, General Purpose Handling */
    uint8_t TS_GPT_RATE;          /*!< General Purpose Timer Rate */
} AS60XX_CR4TypeDef;

typedef struct {
    uint8_t HSC_DIV_MODE;         /*!< High Speed Clock Divider Mode */
    uint8_t NOT_USED_1;           /*!< Mandatory setting: b0 */
    uint8_t HSC_CLK_ST;           /*!< High-Speed Clock Settling Time */
    uint8_t NOT_USED_7_5;         /*!< Recommended setting: b001 */
    uint8_t HSC_DIV;              /*!< High-Speed Clock Divider */
    uint8_t HSC_RATE;             /*!< High-Speed Clock Calibration Rate */
    uint8_t HSC_MODE_CPU;         /*!< High-Speed Clock Mode CPU */
    uint8_t VM_RATE;              /*!< VCC Voltage measurement rate */
    uint8_t LBD_TH;               /*!< Low battery detection threshold */
    uint8_t TSV_UPD_MODE;         /*!< Time stamp update mode */
    uint8_t BF_SEL;               /*!< Base Frequency Select */
    uint8_t CHP_HV_SEL;           /*!< Selection of charge pump voltage */
    uint8_t NOT_USED_28;          /*!< Mandatory setting: b0 */
    uint8_t TI_PATH_SEL;          /*!< Transducer Fire Buffer Impedance */
    uint8_t NOT_USED_31;          /*!< Mandatory setting: b0 */
} AS60XX_CR5TypeDef;

typedef struct {
    uint32_t MR_CT;               /*!< Measure rate cycle time */
    uint8_t TS_MCM;               /*!< Task Sequencer Measure Cycle Mode */
    uint8_t TS_PP_T_EN;           /*!< Enables final post processing T */
    uint8_t TS_PP_F_EN;           /*!< Enables post processing F */
    uint8_t TS_PP_MODE;           /*!< Post processing mode */
    uint8_t TS_CST_RATE;          /*!< Firmware Check(sum) Timer Rate */
    uint8_t TS_NVR_RATE;          /*!< Recall Timer Rate */
    uint8_t NOT_USED_25_24;       /*!< Mandatory setting: b01 */
    uint8_t TS_CHP_MODE;          /*!< Charge Pump Mode */
    uint8_t TS_CHP_WT;            /*!< Charge Pump Wait Time */
    uint8_t NOT_USED_30;          /*!< Mandatory setting: b0 */
    uint8_t TS_CST_MODE;          /*!< Checksum Handling Mode */
} AS60XX_CR6TypeDef;

typedef struct {
    uint32_t TM_RATE;             /*!< Temperature Measurement Rate */
    uint8_t TPM_PAUSE;            /*!< Pause time between 2 temperature measurements */
    uint8_t TM_MODE;              /*!< Temperature Measurement Mode */
    uint8_t NOT_USED_16;          /*!< Mandatory setting: b0 */
    uint8_t TPM_PORT_MODE;        /*!< Temperature Measurement Port Mode */
    uint8_t TM_PORT_ORDER;        /*!< Temperature Measurement Port Order */
    uint8_t TPM_CLOAD_TRIM;       /*!< Temperature Measurement Load Trim */
    uint8_t TPM_CYCLE_SEL;        /*!< Temperature Measurement Cycle Select */
    uint8_t TPM_FAKE_NO;          /*!< Number of Fake measurements */
    uint8_t NOT_USED_31_24;       /*!< Mandatory setting: h00 */
} AS60XX_CR7TypeDef;

typedef struct {
    uint8_t USM_PAUSE;            /*!< Pause time between two ultrasonic measurements */
    uint8_t TI_PGA_AZ_DIS;        /*!< GA Auto-zero Disable */
    uint8_t USM_DIR_MODE;         /*!< Ultrasonic Measurement Direction Mode */
    uint32_t USM_NOISE_MASK_WIN;  /*!< Noise Mask Window */
    uint8_t USM_TO;               /*!< Timeout */
    uint8_t NOT_USED_18;          /*!< Mandatory setting: b0 */
    uint8_t USM_RLS_MODE;         /*!< Select mode for multihit start release */
    uint8_t ZCC_RATE;             /*!< Zero Cross Calibration Rate */
    uint32_t NOT_USED_29_23;      /*!< Mandatory setting: b000000000 */
    uint16_t TI_PGA_CON_MODE;     /*!< Connection of PGA filter between pins INVERT_IN and COMP_IN */
} AS60XX_CR8TypeDef;

typedef struct {
    uint8_t FBG_CLK_DIV;          /*!< Clock divider for fire burst generator */
    uint8_t FBG_MODE;             /*!< Fire Burst Generator Mode */
    uint8_t FBG_PHASE_INS;        /*!< Fire Burst Generator, Phase Insertion */
    uint8_t FBG_BURST_PRE;        /*!< Fire Burst Generator, pre-burst */
    uint8_t FBG_BURST_POST;       /*!< Fire Burst Generator, post-burst */
    uint8_t NOT_USED_28;          /*!< Mandatory setting: b0 */
    uint8_t NOT_USED_29;          /*!< Mandatory setting: b1 */
    uint8_t TOF_HIT_MODE;         /*!< TOF data in FDB according to Multi-Hit Mode */
    uint8_t NOT_USED_31;          /*!< Mandatory setting: b0 */
} AS60XX_CR9TypeDef;

typedef struct {
    uint8_t NOT_USED_0;           /*!< Mandatory setting: b0 */
    uint8_t TOF_HIT_START;        /*!< Defines number of detected hits (including first hit) */
    uint8_t TOF_HIT_IGN;          /*!< Number of multi hits ignored between two hits taken for TDC measurement */
    uint8_t TOF_HIT_SUM_NO;       /*!< Number of hits taken for sum value of TOF measurement */
    uint8_t TOF_HIT_END;          /*!< TOF Hits stored to frontend data buffer */
    uint8_t NOT_USED_21_20;       /*!< Mandatory setting: b00 */
    uint8_t TOF_EDGE_MODE;        /*!< Time of Flight, edge mode */
    uint8_t TOF_RATE_INIT;        /*!< FWD copy of initial value for TOF rate */
    uint8_t NOT_USED_31_30;       /*!< Not Used */
} AS60XX_CR10TypeDef;

typedef struct {
    uint8_t AM_RATE;              /*!< Amplitude measurement rate */
    uint8_t NOT_USED_3;           /*!< Default setting: b0 */
    uint8_t AM_PD_END;            /*!< Amplitude measurement, end of peak detection */
    uint8_t NOT_USED_11_9;        /*!< Mandatory setting: b111 */
    uint8_t AMC_RATE;             /*!< Amplitude measurement calibration rate */
    uint8_t PWD_EN;               /*!< Enables pulse width detection */
    uint8_t PGA_TRIM;             /*!< DC gain of the PGA */
    uint8_t PGA_EN_MODE;          /*!< PGA enable mode */
    uint8_t PGA_MODE;             /*!< Ultrasonic measurement PGA Mode */
    uint8_t NOT_USED_22;          /*!< Mandatory setting: b0 */
    uint8_t AM_PD_START_MODE;     /*!< Peak Detection Start Mode */
    uint8_t ZCD_FHL_INIT;         /*!< FWD copy of initial value for first hit levels */
} AS60XX_CR11TypeDef;

typedef struct {
    uint32_t TRIM1;               /*!< Default setting: 0x95A0C06C */
} AS60XX_CR12TypeDef;

typedef struct {
    uint32_t TRIM2;               /*!< Default setting: 0x40110000 */
} AS60XX_CR13TypeDef;

typedef struct {
    uint32_t TRIM3;               /*!< Default setting: 0x4027000F */
} AS60XX_CR14TypeDef;

typedef struct {
    uint8_t TOF_RATE;             /*!< TOF Rate */
    uint32_t NOT_USED_31_6;       /*!< Not used */
} AS60XX_CR15TypeDef;

typedef struct {
    uint32_t USM_RLS_DLY_U;       /*!< Delay window in up direction, releasing ultrasonic measurement */
    uint32_t NOT_USED_31_19;      /*!< Not used */
} AS60XX_CR16TypeDef;

typedef struct {
    uint32_t USM_RLS_DLY_D;       /*!< Delay window in down direction, releasing ultrasonic measurement */
    uint32_t NOT_USED_31_19;      /*!< Not used */
} AS60XX_CR17TypeDef;

typedef struct {
    uint8_t ZCD_FHL_U;            /*!< First Hit Level Up */
    uint32_t NOT_USED_31_8;       /*!< Not used */
} AS60XX_CR18TypeDef;

typedef struct {
    uint8_t ZCD_FHL_D;            /*!< First Hit Level Down */
    uint32_t NOT_USED_31_8;       /*!< Not used */
} AS60XX_CR19TypeDef;

typedef struct {
    AS60XX_CR0TypeDef     CR0;      /*!< Configuration Register Address C0 */
    AS60XX_CR1TypeDef     CR1;      /*!< Configuration Register Address C1 */
    AS60XX_CR2TypeDef     CR2;      /*!< Configuration Register Address C2 */
    AS60XX_CR3TypeDef     CR3;      /*!< Configuration Register Address C3 */
    AS60XX_CR4TypeDef     CR4;      /*!< Configuration Register Address C4 */
    AS60XX_CR5TypeDef     CR5;      /*!< Configuration Register Address C5 */
    AS60XX_CR6TypeDef     CR6;      /*!< Configuration Register Address C6 */
    AS60XX_CR7TypeDef     CR7;      /*!< Configuration Register Address C7 */
    AS60XX_CR8TypeDef     CR8;      /*!< Configuration Register Address C8 */
    AS60XX_CR9TypeDef     CR9;      /*!< Configuration Register Address C9 */
    AS60XX_CR10TypeDef    CR10;     /*!< Configuration Register Address CA */
    AS60XX_CR11TypeDef    CR11;     /*!< Configuration Register Address CB */
    AS60XX_CR12TypeDef    CR12;     /*!< Configuration Register Address CC */
    AS60XX_CR13TypeDef    CR13;     /*!< Configuration Register Address CD */
    AS60XX_CR14TypeDef    CR14;     /*!< Configuration Register Address CE */
    AS60XX_CR15TypeDef    CR15;     /*!< Configuration Register Address D0 */
    AS60XX_CR16TypeDef    CR16;     /*!< Configuration Register Address D1 */
    AS60XX_CR17TypeDef    CR17;     /*!< Configuration Register Address D2 */
    AS60XX_CR18TypeDef    CR18;     /*!< Configuration Register Address DA */
    AS60XX_CR19TypeDef    CR19;     /*!< Configuration Register Address DB */
} AS60XX_ParamTypeDef;

typedef struct ScioSense_As60xx
{
    ScioSense_As60xx_IO                 io;
    AS60XX_REGISTER_SIZE                CR[AS60XX_AMOUNT_CONFIGURATION_REGISTERS];
    AS60XX_REGISTER_ADDRESSING_SIZE     Addresses[AS60XX_AMOUNT_CONFIGURATION_REGISTERS];
    AS60XX_REGISTER_SIZE                FrontendDataBufferUltrasound[AS60XX_AMOUNT_FDB_REGISTERS];
    AS60XX_REGISTER_SIZE                FrontendDataBufferTemperature[AS60XX_AMOUNT_FDB_REGISTERS];
    AS60XX_REGISTER_SIZE                Status[AS60XX_AMOUNT_STATUS_REGISTERS];
    AS60XX_REGISTER_SIZE                F1AlgorithmOutput[AS6031F1_AMOUNT_OUTPUT_REGISTERS];

    AS60XX_ParamTypeDef Param;          /*!< Configuration Parameter */
    AS60XX_StateTypeDef State;          /*!< Status of AS60XX */
} ScioSense_As60xx;

static inline void                  As60xx_Set_Configuration_Registers          (ScioSense_As60xx* as60xx, uint32_t* registerConfiguration);            // Sets the provided register values into the configuration
static inline void                  As60xx_Update_Parameters                    (ScioSense_As60xx* as60xx);                                             // Updates the configuration parameters from the register contents
static inline void                  As6xx_Initialize_Configuration              (ScioSense_As60xx* as60xx);                                             // Initializes values to the configuration struct, to ensure that if the user doesn't set it it is zero or mandatory value
static inline void                  As60xx_Update_Configuration                 (ScioSense_As60xx* as60xx);                                             // Updates the configuration registers contents (not written into the device) from the configuration parameters
static inline void                  As60xx_Set_State                            (ScioSense_As60xx* as60xx, AS60XX_StateTypeDef newState);               // Set the state of the sensor

static inline Result                As60xx_Write_Opcode                         (ScioSense_As60xx* as60xx, uint8_t opcode);                             // Writes 8 bit opcode
static inline Result                As60xx_Write_Extended_Opcode                (ScioSense_As60xx* as60xx, uint8_t opcode, uint8_t extendedOpcode);     // Writes 8 bit opcode with its 8 bit extension
static inline Result                As60xx_Write_8_Bit_Address_Register         (ScioSense_As60xx* as60xx, uint8_t address, uint32_t dataToWrite);              	                // Writes 8 bit opcode, 8 bit address, and 4 bytes of data
static inline Result                As60xx_Write_16_Bit_Address_Register        (ScioSense_As60xx* as60xx, uint16_t address, uint32_t dataToWrite);             	                // Writes 8 bit opcode, 16 bit address, and 4 bytes of data
static inline Result                As60xx_Write_N_Registers                    (ScioSense_As60xx* as60xx, uint16_t address, uint32_t* dataToWrite, uint16_t len);                  // Writes 8 bit opcode, 8 bit address, and a custom amount of data
static inline uint8_t               As60xx_Read_1_Byte                          (ScioSense_As60xx* as60xx, uint8_t opcode);                             // Writes 8 bit opcode, and then reads 1 byte and returns it as a number
static inline uint32_t              As60xx_Read_1_Dword                         (ScioSense_As60xx* as60xx, uint8_t opcode);                             // Writes 8 bit opcode, and then reads 4 bytes and returns them as a number
static inline uint32_t              As60xx_Read_Register_1_Dword                (ScioSense_As60xx* as60xx, uint16_t address);                           // Writes 8 bit opcode,  8 bit address, and then reads 4 bytes and returns them as a number
static inline void                  As60xx_Read_Register_N_Dword                (ScioSense_As60xx* as60xx, uint16_t address, uint32_t* outputData, uint16_t amountRegistersToRead); // Writes 8 bit opcode,  8 bit address, and then reads N DWORDs (4 bytes)

static inline Result                As60xx_Reset                                (ScioSense_As60xx* as60xx);                                             // Performs a software reset. Returns OK if the state indicates RESET afterwards
static inline Result                As60xx_Init                                 (ScioSense_As60xx* as60xx);                                             // Initializes the device
static inline uint8_t               As60xx_isConnected                          (ScioSense_As60xx* as60xx);                                             // Returns whether a successful communication was achieved with the device
static inline Result                As60xx_Write_Config                         (ScioSense_As60xx* as60xx);                                             // Write the configuration stored on the AS60XX object into the device
static inline Result                As60xx_Start_Measurements                   (ScioSense_As60xx* as60xx);                                             // Performs a software reset without clearing RAM. Returns OK if the Measurement cycle timer is on
static inline Result                As60xx_Stop_Measurements                    (ScioSense_As60xx* as60xx);                                             // Performs a software reset without clearing RAM. Returns OK if the Measurement cycle timer is off
static inline uint32_t              As60xx_GetSupplyVoltageMv                   (ScioSense_As60xx* as60xx);                                             // Reads the supply voltage to the AS60XX, returns value in millivolts
static inline float                 As60xx_GetHsClkFreqHz                       (ScioSense_As60xx* as60xx);                                             // Reads the high speed clock source frequency, returns value in Hz
static inline As60xx_Timestamp      As60xx_GetTimestamp                         (ScioSense_As60xx* as60xx);                                             // Returns the timestamp that was read from the sensor
static inline AS60xx_Measure_Type   As60xx_Update                               (ScioSense_As60xx* as60xx);                                             // Checks the status to see if there are new measurements, and in case there are it reads the values

static inline Result                As60xx_Disable_Watchdog                     (ScioSense_As60xx* as60xx);                                                                         // Disable watchdog timer
static inline Result                As60xx_Execute_Fw_Transaction               (ScioSense_As60xx* as60xx, AS60XX_FwTransactionTypeDef fwTransactionAction);                        // Execute the specified action to the firmware
static inline Result                As60xx_Fw_Handling_Phase_1                  (ScioSense_As60xx* as60xx);                                                                         // Reset and wait the necessary time
static inline Result                As60xx_Fw_Handling_Phase_2                  (ScioSense_As60xx* as60xx);                                                                         // Sets device in a stable idle state before starting a FW update
static inline Result                As60xx_Fw_Handling_Fw_Upload                (ScioSense_As60xx* as60xx, uint8_t* FWC, uint32_t FWC_Length, uint8_t* FWD, uint32_t FWD_Length);   // Uploads the firmware to the device
static inline Result                As60xx_Fw_Handling_Write_No_Lock            (ScioSense_As60xx* as60xx, uint8_t* FWC, uint32_t FWC_Length, uint8_t* FWD, uint32_t FWD_Length);   // Uploads the firmware code and data to the device and instructs the device to write those values without locking
static inline Result                As60xx_Fw_Handling_Write_Lock               (ScioSense_As60xx* as60xx, uint8_t* FWC, uint32_t FWC_Length, uint8_t* FWD, uint32_t FWD_Length);   // Uploads the firmware code and data to the device and instructs the device to write those values locking it
static inline Result                As60xx_Fw_Handling_Erase                    (ScioSense_As60xx* as60xx);                                                                         // Erases the existing firmware
static inline Result                As60xx_Fw_Handling_Phase_4                  (ScioSense_As60xx* as60xx);                                                                         // Checks if the firmware checksums are correct
static inline Result                As60xx_Write_Fw                             (ScioSense_As60xx* as60xx, uint8_t* FWC, int32_t FWC_Length, uint8_t* FWD, int32_t FWD_Length);     // Writes the firmware into the device

static inline uint32_t              As60xx_GetSumTofUp                          (ScioSense_As60xx* as60xx);                                             // Returns the sum of all upstream TOF values
static inline uint32_t              As60xx_GetSumTofDown                        (ScioSense_As60xx* as60xx);                                             // Returns the sum of all downstream TOF values
static inline uint32_t              As60xx_GetAmountHitsForSumTof               (ScioSense_As60xx* as60xx);                                             // Returns the setting of the amount of hits used to calculate the Sum of ToF
static inline uint32_t              As60xx_CalculateTDCTimePs                   (ScioSense_As60xx* as60xx, uint32_t contentTDCRegister);                // Transforms the measurement of a TDC register to nanosecods
static inline void                  AS60xx_CalculateTemperatureResistance2Wire  (ScioSense_As60xx* as60xx, float* temperatureResistancesRatiosOut);     // Calculates the resistance ratio of the RTDs in 2-wire configuration
static inline void                  AS60xx_CalculateTemperature2Wire            (ScioSense_As60xx* as60xx, float* temperaturesOut);                     // Calculates the temperature of the RTDs in 2-wire in ºC according to IEC 60751:2008
static inline float                 AS60xx_CalculateInternalTemperature         (ScioSense_As60xx* as60xx);                                             // Calculates the internal temperature in ºC. Uncalibrated value, must add a T0 offset
static inline float                 As60xx_CalculateFluidSpeed                  (uint32_t tofUs_ps, uint32_t tofDn_ps, float speedSound_mpers, float distance_m);   // Calculates the fluid speed from the ToF measurements in ns, the speed of sound in meters per second, and the transducer distance in meters 
static inline uint32_t              As60xx_AmplitudeToMv                        (uint32_t AM, uint32_t AMCHigh, uint32_t AMCLow);                       // Transforms the amplitude reading to a value in millivolts
static inline uint32_t              As60xx_GetAmplitudeUp                       (ScioSense_As60xx* as60xx);                                             // Returns the amplitude of the upstream pulses
static inline uint32_t              As60xx_GetAmplitudeDown                     (ScioSense_As60xx* as60xx);                                             // Returns the amplitude of the downstream pulses
static inline float                 As60xx_PulseWidthRatioToFloat               (uint32_t registerContent);                                             // Calculates the fractional value for the Pulse Width ratio from the register content
static inline float                 As60xx_GetPulseWidthRatioUp                 (ScioSense_As60xx* as60xx);                                             // Returns the ratio of the upstream pulse widths 
static inline float                 As60xx_GetPulseWidthRatioDown               (ScioSense_As60xx* as60xx);                                             // Returns the ratio of the downstream pulse widths
static inline void                  As60xx_GetTofValuesUp                       (ScioSense_As60xx* as60xx, uint32_t* tofValues);                        // Fills the array provided with the TOF of each upstream pulse
static inline void                  As60xx_GetTofValuesDown                     (ScioSense_As60xx* as60xx, uint32_t* tofValues);                        // Fills the array provided with the TOF of each upstream pulse
static inline float                 As60xx_GetSpeedSoundFromTemperature         (float temperature);                                                    // Gets the speed of sound in water from the temperature

static inline uint8_t               As60xx_HasAnyError                          (ScioSense_As60xx* as60xx);                                             // Checks if any error flag is set
static inline uint32_t              As60xx_GetRawErrorFlags                     (ScioSense_As60xx* as60xx);                                             // Returns the raw value of the 0xE1 register that contains the error flags
static inline uint8_t               As60xx_HasErrorFlag                         (ScioSense_As60xx* as60xx, As60xx_ErrorFlag errorFlag);                 // Checks if the specified error flag is set

static inline Result                As6031F1_Update                             (ScioSense_As60xx* as6031f1);                                           // Checks reads the output values of the AS6031F1 algorithm
static inline int32_t               As6031F1_Parse_Flow_Volume_Int              (ScioSense_As60xx* as60xx);                                             // Read the signed integer part of total volume of water flow in cubic meters calculated by the AS6031F1 firmware
static inline uint32_t              As6031F1_Parse_Flow_Volume_Frac             (ScioSense_As60xx* as60xx);                                             // Read unsigned factional part of total volume of water flow in cubic meters calculated by the AS6031F1 firmware
static inline int32_t               As6031F1_Parse_Flow_Rate_Raw                (ScioSense_As60xx* as60xx);                                             // Read raw register content of the presently unfiltered calculated flow volume calculated by the AS6031F1 firmware
static inline int32_t               As6031F1_Parse_Flow_Rate_Filtered_Raw       (ScioSense_As60xx* as60xx);                                             // Read raw register content of the presently filtered calculated flow volume calculated by the AS6031F1 firmware
static inline uint32_t              As6031F1_Parse_Temperature_Raw              (ScioSense_As60xx* as60xx);                                             // Read raw register content of the temperature calculated by the AS6031F1 firmware
static inline uint32_t              As6031F1_Parse_Sound_Vel_Raw                (ScioSense_As60xx* as60xx);                                             // Read raw register content of the speed of sound calculated by the AS6031F1 firmware
static inline uint32_t              As6031F1_Parse_Flow_Speed_Raw               (ScioSense_As60xx* as60xx);                                             // Read raw register content of the flow speed calculated by the AS6031F1 firmware
static inline uint32_t              As6031F1_Parse_Tof_Diff_Raw                 (ScioSense_As60xx* as60xx);                                             // Read raw register content of the Time of Flight difference calculated by the AS6031F1 firmware
static inline uint32_t              As6031F1_Parse_Tof_Sum_Raw                  (ScioSense_As60xx* as60xx);                                             // Read raw register content of the Time of Flight sum calculated by the AS6031F1 firmware
static inline uint32_t              As6031F1_Parse_Error_Flags                  (ScioSense_As60xx* as60xx);                                             // Read raw register content of the error flags
static inline uint32_t              As6031F1_Parse_Value                        (ScioSense_As60xx* as60xx, uint8_t index);                              // Read raw register content at the specified index

static inline float                 As6031F1_Parse_Flow_Volume_M3               (ScioSense_As60xx* as60xx);                                             // Read total volume of water flow in cubic meters calculated by the AS6031F1 firmware
static inline float                 As6031F1_Parse_Flow_Rate_L_Per_Hr           (ScioSense_As60xx* as60xx);                                             // Read unfiltered flow rate in litres per hour calculated by the AS6031F1 firmware
static inline float                 As6031F1_Parse_Flow_Rate_Filtered_L_Per_Hr  (ScioSense_As60xx* as60xx);                                             // Read filtered flow rate in litres per hour calculated by the AS6031F1 firmware
static inline float                 As6031F1_Parse_Temperature_Deg_C            (ScioSense_As60xx* as60xx);                                             // Read temperature in degrees Celsius calculated by the AS6031F1 firmware
static inline float                 As6031F1_Parse_Sound_Vel_M_Per_S            (ScioSense_As60xx* as60xx);                                             // Read speed of sound in the fluid in meters per second calculated by the AS6031F1 firmware
static inline float                 As6031F1_Parse_Flow_Speed_M_Per_S           (ScioSense_As60xx* as60xx);                                             // Read flow speed in meters per second calculated by the AS6031F1 firmware

static inline uint8_t               As6031F1_HasErrorFlag                       (ScioSense_As60xx* as60xx, As6031F1_ErrorFlag errorFlag);               // Checks if the specified firmware F1 error flag is set

static inline uint8_t               As60xx_Get_Amount_Configuration_Registers   ();                                                                     // Return the amount of configuration registers to write
static inline uint16_t              As60xx_Get_Configuration_Register_Address   (ScioSense_As60xx* as60xx, uint8_t idx);                                // Return the address of the configuration register corresponding to the index
static inline uint32_t              As60xx_Get_Configuration_Register_Setting   (ScioSense_As60xx* as60xx, uint8_t idx);                                // Return the content of the configuration register that is intended to be written corresponding to the index
static inline uint32_t              As60xx_CalculateDelayWindowRegisterValue    (float delayWindowNs);                                                  // Calculate the delay window register content for registers 0x0D1 and 0x0D2 (ultrasonic release delay)
static inline uint32_t              As60xx_CalculateFirstHitLevelRegisterValue  (float thresholdMv);                                                    // Calculate the value to use in registers 0x0DA and 0x0DB (zero crossing detection level)

#include "ScioSense_As60xx.inl.h"
#endif // SCIOSENSE_AS60XX_C_H
