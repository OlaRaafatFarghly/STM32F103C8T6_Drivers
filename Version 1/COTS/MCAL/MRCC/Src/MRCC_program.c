/*******************************************************************************************************/
/* Author            : Ola Raafat Farghly                                                              */
/* Version           : V0.0.0                                                                          */
/* Data              : 12 October 2023                                                                 */
/* Description       : MRCC_Program.c --> implementations                                              */
/* Module  Features  :                                                                                 */
/*      01- MRCC_u8SetClockStatus                                                                      */
/*      02- MRCC_u8SetSysClock                                                                         */
/*      03- MRCC_setHSEConfig                                                                          */
/*      04- MRCC_u8SetPLLConfig                                                                        */
/*      05- MRCC_u8AHBEnableClock                                                                      */
/*      06- MRCC_u8AHBDisableClock                                                                     */
/*      07- MRCC_u8APB1EnableClock                                                                     */
/*      08- MRCC_u8APB1DisableClock                                                                    */
/*      09- MRCC_u8APB2EnableClock                                                                     */
/*      10- MRCC_u8APB2DisableClock                                                                    */
/*      11- MRCC_voidEnableSecuritySystem                                                              */
/*      12- MRCC_voidDisableSecuritySystem                                                             */
/*******************************************************************************************************/



/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#include<stdint.h>
#include"../Inc/LIB/BIT_Maths.h"
#include"../Inc/LIB/STM32F103.h"
#include"../Inc/LIB/ErrorType.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/

#include"../Inc/MCAL/MRCC_private.h"
#include"../Inc/MCAL/MRCC_interface.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      01- MRCC_u8SetClockStatus                                       */
/*-----------------------------------------------------------------------------------------------------*/
/****************************************************************
 *   @fn         01- MRCC_u8SetClockStatus
 *   @brief      The function Sets the status of the Clock
 *   @param[in]  ClkType: The type of Clock to be set, get options @ClkType_t enum
 *   @param[in]  status : The status of the clock, get options @Status_t enum
 *   @retVal     ErrorStatus
/*******************************************************************************************************/

uint8_t MRCC_u8SetClokSts(uint32_t ClkType,uint32_t status)
{
	uint8_t Local_u8ErrorState = OK;
	switch(ClkType)
	{
	case HSE:
		switch(status)
		{
	    case ON:
	    	SET_BIT((RCC->CR),HSEON);
	    	break;
	    case OFF:
	    	 CLR_BIT((RCC->CR),HSEON);
	    	 break;
	    default:
	    	Local_u8ErrorState = NOK;
	    	break;
		}
		break;
	case HSI:
		switch(status)
		{
		case ON:
			SET_BIT((RCC->CR),HSION);
			break;
		case OFF:
			 CLR_BIT((RCC->CR),HSION);
			 break;
		default:
			Local_u8ErrorState = NOK;
			break;
		}
		break;
	case PLL:
		switch(status)
		{
		case ON:
			SET_BIT((RCC->CR),PLLON);
			break;
		case OFF:
			CLR_BIT((RCC->CR),PLLON);
			 break;
		default:
			Local_u8ErrorState = NOK;
			break;
		}
		break;
	default:
		Local_u8ErrorState = NOK;
		break;
	}

	return Local_u8ErrorState;
}

/****************************************************************
/*                                      02- MRCC_u8SetSysClock                                      */
/*-----------------------------------------------------------------------------------------------------*/
/*   @fn         MRCC_u8SetSysClock                                                                    */
/*   @brief      The function sets the clock to be chosen as system clock                              */
/*   @param[in]  ClkType: The type of Clock to be set, get options @ClkType_t enum                     */
/*   @retVal     ErrorStatus                                                                           */
/*******************************************************************************************************/

uint8_t MRCC_u8SetSysClock(uint32_t ClkType)
{
	uint8_t Local_u8ErrorState = OK;
	switch(ClkType)
	{
	case HSE:
		SET_BIT((RCC->CR),HSEON);
		while(GET_BIT((RCC->CR),HSERDY)==HSE_IS_READY);
		SET_BIT((RCC->CFGR),SW0);
		CLR_BIT((RCC->CFGR),SW1);
		CLR_BIT((RCC->CR),HSION);
		break;
	case HSI:
		SET_BIT((RCC->CR),HSION);
		while(GET_BIT((RCC->CR),HSIRDY)==HSI_IS_READY);
		CLR_BIT((RCC->CFGR),SW0);
		CLR_BIT((RCC->CFGR),SW1);
		CLR_BIT((RCC->CR),HSION);
		break;
	case PLL:
		SET_BIT((RCC->CR),PLLON);
		while(GET_BIT((RCC->CR),PLLRDY)==PLL_IS_READY);
		CLR_BIT((RCC->CFGR),SW0);
		SET_BIT((RCC->CFGR),SW1);
		CLR_BIT((RCC->CR),HSION);
		break;
	default:
		Local_u8ErrorState = NOK;
		break;
	}

	return Local_u8ErrorState;
}

/****************************************************************
 *   @fn         MRCC_setHSEConfig
 *   @brief      The function sets the High Speed External(HSE) clock configurations
 *   @param[in]  Config: The division values of HSE clock, get options @Config_t enum
 *   @retVal     ErrorStatus
 */
uint8_t MRCC_setHSEConfig(uint32_t Config)
{
	uint8_t Local_u8ErrorState = OK;
	return Local_u8ErrorState;
}

/****************************************************************
 *   @fn         MRCC_u8SetPLLConfig
 *   @brief      The function sets the phase locked loop[PLL] clock configurations
 *   @param[in]  PLL_MUL: The multiplication factor in PLL, get options @PLL_MUL_t enum
 *   @param[in]  PLL_Src: The source of PLL, get options @PLL_Src_t enum
 *   @retVal     ErrorStatus
 */
uint8_t MRCC_u8SetPLLConfig(uint32_t PLL_MUL,uint32_t PLL_Src)
{
	uint8_t Local_u8ErrorState = OK;
	return Local_u8ErrorState;
}

/****************************************************************
 *   @fn         MRCC_u8AHBEnableClock
 *   @brief      The function enables clock on Advanced High-Performance [AHB] bus
 *   @param[in]  Peripheral: The Peripheral to be enabled, get options @AHB_Peripheral_t enum
 *   @retVal     ErrorStatus
 */
uint8_t MRCC_u8AHBEnableClock(uint32_t AHB_Peripheral)
{
	uint8_t Local_u8ErrorState = OK;
	switch(AHB_Peripheral)
	{
	case DMA1:
		SET_BIT((RCC->AHBENR),DMA1EN);
		break;
	case DMA2:
		SET_BIT((RCC->AHBENR),DMA2EN);
		break;
	case SRAM:
		SET_BIT((RCC->AHBENR),SRAMEN);
		break;
	case FLITF:
		SET_BIT((RCC->AHBENR),FLITFEN);
		break;
	case CRC:
		SET_BIT((RCC->AHBENR),CRCEN);
		break;
	case OTGFS:
		SET_BIT((RCC->AHBENR),OTGFSEN);
		break;
	case ETHMAC:
		SET_BIT((RCC->AHBENR),ETHMACEN);
		break;
	case ETHMACTX:
		SET_BIT((RCC->AHBENR),ETHMACTXEN);
		break;
	case ETHMACRX:
		SET_BIT((RCC->AHBENR),ETHMACRXEN);
		break;
	default:
		Local_u8ErrorState = NOK;
		break;
	}
	return Local_u8ErrorState;
}

/****************************************************************
 *   @fn         MRCC_u8AHBDisableClock
 *   @brief      The function disables clock on Advanced High-Performance [AHB] bus
 *   @param[in]  Peripheral: The Peripheral to be disabled, get options @AHB_Peripheral_t enum
 *   @retVal     ErrorStatus
 */
uint8_t MRCC_u8AHBDisableClock(uint32_t AHB_Peripheral)
{
	uint8_t Local_u8ErrorState = OK;
	switch(AHB_Peripheral)
	{
	case DMA1:
		CLR_BIT((RCC->AHBENR),DMA1EN);
		break;
	case DMA2:
		CLR_BIT((RCC->AHBENR),DMA2EN);
		break;
	case SRAM:
		CLR_BIT((RCC->AHBENR),SRAMEN);
		break;
	case FLITF:
		CLR_BIT((RCC->AHBENR),FLITFEN);
		break;
	case CRC:
		CLR_BIT((RCC->AHBENR),CRCEN);
		break;
	case OTGFS:
		CLR_BIT((RCC->AHBENR),OTGFSEN);
		break;
	case ETHMAC:
		CLR_BIT((RCC->AHBENR),ETHMACEN);
		break;
	case ETHMACTX:
		CLR_BIT((RCC->AHBENR),ETHMACTXEN);
		break;
	case ETHMACRX:
		CLR_BIT((RCC->AHBENR),ETHMACRXEN);
		break;
	default:
		Local_u8ErrorState = NOK;
		break;
	}
	return Local_u8ErrorState;
}

/****************************************************************
 *   @fn         MRCC_u8APB1EnableClock
 *   @brief      The function enables clock on Advanced Peripheral-Performance [APB1] bus
 *   @param[in]  Peripheral: The Peripheral to be enabled, get options @APB1_Peripheral_t enum
 *   @retVal     ErrorStatus
 */
uint8_t MRCC_u8APB1EnableClock(uint32_t APB1_Peripheral)
{
	uint8_t Local_u8ErrorState = OK;
		switch(APB1_Peripheral)
		{
		case TIM2:
			SET_BIT((RCC->APB1ENR),TIM2EN);
			break;
		case TIM3:
			SET_BIT((RCC->APB1ENR),TIM3EN);
			break;
		case TIM4:
			SET_BIT((RCC->APB1ENR),TIM4EN);
			break;
		case TIM5:
			SET_BIT((RCC->APB1ENR),TIM5EN);
			break;
		case TIM6:
			SET_BIT((RCC->APB1ENR),TIM6EN);
			break;
		case TIM7:
			SET_BIT((RCC->APB1ENR),TIM7EN);
			break;
		case WWDG:
			SET_BIT((RCC->APB1ENR),WWDGEN);
			break;
		case SPI2:
			SET_BIT((RCC->APB1ENR),SPI2EN);
			break;
		case SPI3:
			SET_BIT((RCC->APB1ENR),SPI3EN);
			break;
		case USART2:
			SET_BIT((RCC->APB1ENR),USART2EN);
			break;
		case USART3:
			SET_BIT((RCC->APB1ENR),USART3EN);
			break;
		case UART4:
			SET_BIT((RCC->APB1ENR),UART4EN);
			break;
		case UART5:
			SET_BIT((RCC->APB1ENR),UART5EN);
			break;
		case I2C1:
			SET_BIT((RCC->APB1ENR),I2C1EN);
			break;
		case I2C2:
			SET_BIT((RCC->APB1ENR),I2C2EN);
			break;
		case CAN1:
			SET_BIT((RCC->APB1ENR),CAN1EN);
			break;
		case CAN2:
			SET_BIT((RCC->APB1ENR),CAN2EN);
			break;
		case BKP:
			SET_BIT((RCC->APB1ENR),BKPEN);
			break;
		case PWR:
			SET_BIT((RCC->APB1ENR),PWREN);
			break;
		case DAC:
			SET_BIT((RCC->APB1ENR),DACEN);
			break;

		default:
			Local_u8ErrorState = NOK;
			break;
		}
		return Local_u8ErrorState;
}

/****************************************************************
 *   @fn         MRCC_u8APB1DisableClock
 *   @brief      The function disables clock on Advanced Peripheral-Performance [APB1] bus
 *   @param[in]  Peripheral: The Peripheral to be disabled, get options @APB1_Peripheral_t enum
 *   @retVal     ErrorStatus
 */
uint8_t MRCC_u8APB1DisableClock(uint32_t APB1_Peripheral)
{
	uint8_t Local_u8ErrorState = OK;
			switch(APB1_Peripheral)
			{
			case TIM2:
				CLR_BIT((RCC->APB1ENR),TIM2EN);
				break;
			case TIM3:
				CLR_BIT((RCC->APB1ENR),TIM3EN);
				break;
			case TIM4:
				CLR_BIT((RCC->APB1ENR),TIM4EN);
				break;
			case TIM5:
				CLR_BIT((RCC->APB1ENR),TIM5EN);
				break;
			case TIM6:
				CLR_BIT((RCC->APB1ENR),TIM6EN);
				break;
			case TIM7:
				CLR_BIT((RCC->APB1ENR),TIM7EN);
				break;
			case WWDG:
				CLR_BIT((RCC->APB1ENR),WWDGEN);
				break;
			case SPI2:
				CLR_BIT((RCC->APB1ENR),SPI2EN);
				break;
			case SPI3:
				CLR_BIT((RCC->APB1ENR),SPI3EN);
				break;
			case USART2:
				CLR_BIT((RCC->APB1ENR),USART2EN);
				break;
			case USART3:
				CLR_BIT((RCC->APB1ENR),USART3EN);
				break;
			case UART4:
				CLR_BIT((RCC->APB1ENR),UART4EN);
				break;
			case UART5:
				CLR_BIT((RCC->APB1ENR),UART5EN);
				break;
			case I2C1:
				CLR_BIT((RCC->APB1ENR),I2C1EN);
				break;
			case I2C2:
				CLR_BIT((RCC->APB1ENR),I2C2EN);
				break;
			case CAN1:
				CLR_BIT((RCC->APB1ENR),CAN1EN);
				break;
			case CAN2:
				CLR_BIT((RCC->APB1ENR),CAN2EN);
				break;
			case BKP:
				CLR_BIT((RCC->APB1ENR),BKPEN);
				break;
			case PWR:
				CLR_BIT((RCC->APB1ENR),PWREN);
				break;
			case DAC:
				CLR_BIT((RCC->APB1ENR),DACEN);
				break;
			default:
				Local_u8ErrorState = NOK;
				break;
			}
			return Local_u8ErrorState;
}

/****************************************************************
 *   @fn         MRCC_u8APB2EnableClock
 *   @brief      The function enables clock on Advanced Peripheral-Performance [APB2] bus
 *   @param[in]  Peripheral: The Peripheral to be enabled, get options @APB2_Peripheral_t enum
 *   @retVal     ErrorStatus
 */
uint8_t MRCC_u8APB2EnableClock(uint32_t APB2_Peripheral)
{
	uint8_t Local_u8ErrorState = OK;
		switch(APB2_Peripheral)
		{
		case AFIO:
			SET_BIT((RCC->APB2ENR),AFIOEN);
			break;
		case IOPA:
			SET_BIT((RCC->APB2ENR),IOPAEN);
			break;
		case IOPB:
			SET_BIT((RCC->APB2ENR),IOPBEN);
			break;
		case IOPC:
			SET_BIT((RCC->APB2ENR),IOPCEN);
			break;
		case IOPD:
			SET_BIT((RCC->APB2ENR),IOPDEN);
			break;
		case IOPE:
			SET_BIT((RCC->APB2ENR),IOPEEN);
			break;
		case ADC1:
			SET_BIT((RCC->APB2ENR),ADC1EN);
			break;
		case ADC2:
			SET_BIT((RCC->APB2ENR),ADC2EN);
			break;
		case TIM1:
			SET_BIT((RCC->APB2ENR),TIM1EN);
			break;
		case SPI1:
			SET_BIT((RCC->APB2ENR),SPI1EN);
			break;
		case USART1:
			SET_BIT((RCC->APB2ENR),USART1EN);
			break;
		default:
			Local_u8ErrorState = NOK;
			break;
		}
		return Local_u8ErrorState;
}

/****************************************************************
 *   @fn         MRCC_u8APB2DisableClock
 *   @brief      The function disables clock on Advanced Peripheral-Performance [APB2] bus
 *   @param[in]  Peripheral: The Peripheral to be disabled, get options @APB2_Peripheral_t enum
 *   @retVal     ErrorStatus
 */
uint8_t MRCC_u8APB2DisableClock(uint32_t APB2_Peripheral)
{
	uint8_t Local_u8ErrorState = OK;
			switch(APB2_Peripheral)
			{
			case AFIO:
				CLR_BIT((RCC->APB2ENR),AFIOEN);
				break;
			case IOPA:
				CLR_BIT((RCC->APB2ENR),IOPAEN);
				break;
			case IOPB:
				CLR_BIT((RCC->APB2ENR),IOPBEN);
				break;
			case IOPC:
				CLR_BIT((RCC->APB2ENR),IOPCEN);
				break;
			case IOPD:
				CLR_BIT((RCC->APB2ENR),IOPDEN);
				break;
			case IOPE:
				CLR_BIT((RCC->APB2ENR),IOPEEN);
				break;
			case ADC1:
				CLR_BIT((RCC->APB2ENR),ADC1EN);
				break;
			case ADC2:
				CLR_BIT((RCC->APB2ENR),ADC2EN);
				break;
			case TIM1:
				CLR_BIT((RCC->APB2ENR),TIM1EN);
				break;
			case SPI1:
				CLR_BIT((RCC->APB2ENR),SPI1EN);
				break;
			case USART1:
				CLR_BIT((RCC->APB2ENR),USART1EN);
				break;
			default:
				Local_u8ErrorState = NOK;
				break;
			}
			return Local_u8ErrorState;
}


/*******************************************************************************************************/
/*                                      03- MRCC_voidEnableSecuritySystem                              */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Security System                                                   */
/* 2- Function Input       -> No Thing                                                                 */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MRCC_voidEnableSecuritySystem(void)
{
	SET_BIT(RCC->CR,CSSON);
}
/*******************************************************************************************************/
/*                                      04- MRCC_voidDisableSecuritySystem                              */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Disable Security System                                                   */
/* 2- Function Input       -> No Thing                                                                 */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/


void MRCC_voidDisableSecuritySystem(void)
{
	CLR_BIT( RCC->CR,CSSON);
}

