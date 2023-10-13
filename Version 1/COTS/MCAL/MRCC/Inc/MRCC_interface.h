#ifndef MCAL_MRCC_INTERFACE_H_
#define MCAL_MRCC_INTERFACE_H_
/**************************************************************************************************/
/***************************        Configuration enums          **********************************/
/**************************************************************************************************/

/*************
 *@Status_t enum
 */
typedef enum
{
	ON=0,
	OFF
}Status_t;

/*************
 *@ClkType_t enum
 */
typedef enum
{
	HSE=0,
	HSI,
	PLL,
}ClkType_t;
//
///*************
// *@Config_t enum
// */
//typedef enum
//{
//}Config_t;
//

/*************
 *@AHB_Peripheral_t enum
 */
typedef enum
{
	DMA1=0,
	DMA2,
	SRAM,
	FLITF=4,
	CRC=6,
	OTGFS=12,
	ETHMAC=14,
	ETHMACTX,
	ETHMACRX,
}AHB_Peripheral_t;

/*************
 *@APB1_Peripheral_t enum
 */
typedef enum
{
	TIM2=0,
	TIM3,
	TIM4,
	TIM5,
	TIM6,
	TIM7,
	WWDG=11,
	SPI2=14,
	SPI3,
	USART2=17,
	USART3,
	UART4,
	UART5,
	I2C1,
	I2C2,
	CAN1=25,
	CAN2,
	BKP,
	PWR,
	DAC
}APB1_Peripheral_t;

/*************
 *@APB2_Peripheral_t enum
 */
typedef enum
{
	AFIO=0,
	IOPA=2,
	IOPB,
	IOPC,
	IOPD,
	IOPE,
	ADC1=9,
	ADC2,
	TIM1,
	SPI1,
	USART1=14,

}APB2_Peripheral_t;

///*************
// *@PLL_MUL_t enum
// */
//typedef enum
//{
//}PLL_MUL_t;

///*************
// *@PLL_Src_t enum
// */
//
//typedef enum
//{
//	HSE=0,
//	HSI,
//	PLL,
//}PLL_Src_t;
//
///*************
// *@Peripheral enum
// */
//
//typedef enum
//{
//	ON,
//	OFF
//}PLL_Src_t;



/**************************************************************************************************/
/***************************        Functions declaration        **********************************/
/**************************************************************************************************/

/****************************************************************
 *   @fn         MRCC_u8SetClockStatus
 *   @brief      The function Sets the status of the Clock
 *   @param[in]  ClkType: The type of Clock to be set, get options @ClkType_t enum
 *   @param[in]  status : The status of the clock, get options @Status_t enum
 *   @retVal     ErrorStatus
 */
uint8_t MRCC_u8SetClokSts(uint32_t ClkType,uint32_t status);

/****************************************************************
 *   @fn         MRCC_u8SetSysClock
 *   @brief      The function sets the clock to be chosen as system clock
 *   @param[in]  ClkType: The type of Clock to be set, get options @ClkType_t enum
 *   @retVal     ErrorStatus
 */
uint8_t MRCC_u8SetSysClock(uint32_t ClkType);

/****************************************************************
 *   @fn         MRCC_setHSEConfig
 *   @brief      The function sets the High Speed External(HSE) clock configurations
 *   @param[in]  Config: The division values of HSE clock, get options @Config_t enum
 *   @retVal     ErrorStatus
 */
uint8_t MRCC_setHSEConfig(uint32_t Config);

/****************************************************************
 *   @fn         MRCC_u8SetPLLConfig
 *   @brief      The function sets the phase locked loop[PLL] clock configurations
 *   @param[in]  PLL_MUL: The multiplication factor in PLL, get options @PLL_MUL_t enum
 *   @param[in]  PLL_Src: The source of PLL, get options @PLL_Src_t enum
 *   @retVal     ErrorStatus
 */
uint8_t MRCC_u8SetPLLConfig(uint32_t PLL_MUL,uint32_t PLL_Src);

/****************************************************************
 *   @fn         MRCC_u8AHBEnableClock
 *   @brief      The function enables clock on Advanced High-Performance [AHB] bus
 *   @param[in]  Peripheral: The Peripheral to be enabled, get options @Peripheral enum
 *   @retVal     ErrorStatus
 */
uint8_t MRCC_u8AHBEnableClock(uint32_t Peripheral);

/****************************************************************
 *   @fn         MRCC_u8AHBDisableClock
 *   @brief      The function disables clock on Advanced High-Performance [AHB] bus
 *   @param[in]  Peripheral: The Peripheral to be disabled, get options @Peripheral enum
 *   @retVal     ErrorStatus
 */
uint8_t MRCC_u8AHBDisableClock(uint32_t Peripheral);

/****************************************************************
 *   @fn         MRCC_u8APB1EnableClock
 *   @brief      The function enables clock on Advanced Peripheral-Performance [APB1] bus
 *   @param[in]  Peripheral: The Peripheral to be enabled, get options @Peripheral enum
 *   @retVal     ErrorStatus
 */
uint8_t MRCC_u8APB1EnableClock(uint32_t Peripheral);

/****************************************************************
 *   @fn         MRCC_u8APB1DisableClock
 *   @brief      The function disables clock on Advanced Peripheral-Performance [APB1] bus
 *   @param[in]  Peripheral: The Peripheral to be disabled, get options @Peripheral enum
 *   @retVal     ErrorStatus
 */
uint8_t MRCC_u8APB1DisableClock(uint32_t Peripheral);

/****************************************************************
 *   @fn         MRCC_u8APB2EnableClock
 *   @brief      The function enables clock on Advanced Peripheral-Performance [APB2] bus
 *   @param[in]  Peripheral: The Peripheral to be enabled, get options @Peripheral enum
 *   @retVal     ErrorStatus
 */
uint8_t MRCC_u8APB2EnableClock(uint32_t Peripheral);

/****************************************************************
 *   @fn         MRCC_u8APB2DisableClock
 *   @brief      The function disables clock on Advanced Peripheral-Performance [APB2] bus
 *   @param[in]  Peripheral: The Peripheral to be disabled, get options @Peripheral enum
 *   @retVal     ErrorStatus
 */
uint8_t MRCC_u8APB2DisableClock(uint32_t Peripheral);


#endif /* MCAL_MRCC_INTERFACE_H_ */
