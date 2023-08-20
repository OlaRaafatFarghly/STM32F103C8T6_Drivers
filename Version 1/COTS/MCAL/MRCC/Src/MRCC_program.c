/*
 * MRCC_program.c
 *
 *  Created on: Aug 10, 2023
 *      Author: Ola Raafat
 */

#include "../../../Library/STD_Types.h"
#include "../../../Library/BIT_Math.h"

#include "../Inc/MRCC_interface.h"
#include "../Inc/MRCC_private.h"
#include "../Inc/MRCC_configration.h"


void MRCC_vInit(void)
{
	/*1- CSS (ON/OFF) */

	/*2- HSE_BYP CLR->Oscillator Enable not bypassed, SET->Oscillator Disable bypassed */
	CLR_BIT(RCC -> CR, HSEBYP);

	/*3- select clock switch (HSI/HSE/PLL) */
	SET_BIT(RCC -> CFGR, SW0);

	/*4- Bus prescalers   */

	/*5- PLL configuration */

	/*6- Enable the selected clock (HSI ON / HSE ON / PLL ON)*/
#if RCC_HSE_ENABLE == ENABLE
	SET_BIT(RCC->CR, HSEON);
#endif

}

void MRCC_vEnableClock(RCCPeriphralReg_t peripheral)
{
	switch(peripheral)
	{
	case DMA2:
		SET_BIT(RCC -> AHB1ENR, DMA2EN);
		break;
	case DMA1:
		SET_BIT(RCC -> AHB1ENR, DMA1EN);
		break;
	case CRC:
		SET_BIT(RCC -> AHB1ENR, CRCEN);
		break;
	case GPIOC:
		SET_BIT(RCC -> AHB1ENR, GPIOCEN);
		break;
	case GPIOB:
		SET_BIT(RCC -> AHB1ENR, GPIOBEN);
		break;
	case GPIOA:
		SET_BIT(RCC -> AHB1ENR, GPIOAEN);
		break;
	default:
		break;
	}

}

void MRCC_vDisableClock(RCCPeriphralReg_t peripheral)
{
	switch(peripheral)
	{
	case DMA2:
		CLR_BIT(RCC -> AHB1ENR, DMA2EN);
		break;
	case DMA1:
		CLR_BIT(RCC -> AHB1ENR, DMA1EN);
		break;
	case CRC:
		CLR_BIT(RCC -> AHB1ENR, CRCEN);
		break;
	case GPIOC:
		CLR_BIT(RCC -> AHB1ENR, GPIOCEN);
		break;
	case GPIOB:
		CLR_BIT(RCC -> AHB1ENR, GPIOBEN);
		break;
	case GPIOA:
		CLR_BIT(RCC -> AHB1ENR, GPIOAEN);
		break;
	default:
		break;
	}
}


