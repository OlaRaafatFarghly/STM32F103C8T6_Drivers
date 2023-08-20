/*
 * MRCC_private.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Ola Raafat
 */



#ifndef MCAL_MRCC_MRCC_PRIVATE_H_
#define MCAL_MRCC_MRCC_PRIVATE_H_

#define HSION   0
#define HSEON   16
#define HSEBYP  18
#define CSSON   19
#define PLLON   24
#define PLLI2S  26

typedef enum
{
	GPIOAEN,
	GPIOBEN,
	GPIOCEN,
	CRCEN=12,
	DMA1EN=21,
	DMA2EN,

}RCC_AHB1ENR_Reg_t;

typedef enum
{
	GPIOA,
	GPIOB,
	GPIOC,
	CRC,
	DMA1,
	DMA2,

}RCCPeriphralReg_t;
#define SW0     0
#define SW1     1

/************************** RCC BASE ADDRESS  **************************************/
#define RCC_BASE_ADDR  0x40023800

/************************** RCC REGISTERS  **************************************/
typedef struct{

	u32 CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 Reserved1;
	u32 Reserved2;
	u32 APB1RSTR;
	u32 APB2RSTR;
	u32 Reserved3;
	u32 Reserved4;
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 Reserved5;
	u32 Reserved6;

}RCC_MemMap_t;

#define RCC ((volatile RCC_MemMap_t*)(RCC_BASE_ADDR))

#endif /* MCAL_MRCC_MRCC_PRIVATE_H_ */
