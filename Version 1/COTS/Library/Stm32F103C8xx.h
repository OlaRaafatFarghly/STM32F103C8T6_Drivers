/*******************************************************************************************************/
/* File       : STM32F103C8xx.h                                                                 */
/* Author     : Ola Raafat Farghly                                                              */
/* Version    : V0.0.0                                                                          */
/* Data       : 12 October 2023                                                                 */
/* Description: The Register file,including base addresses of peripherals,peripherals Definition Structure and Peripherals Definition*/
/*******************************************************************************************************/

#ifndef LIB_STM32F103C8XX_H_
#define LIB_STM32F103C8XX_H_


/*******************************************************************************************************/
/*******************************           Base Addresses           ************************************/
/*******************************************************************************************************/

/************************       Various Memories Base Addresses       ************************/
#define FLASH_BASE_ADDRESS         0x40022000UL
#define SRAM_BASE_ADDRESS          0x20000000UL
//#define ROM_BASE_ADDRESS           0x1FFF0000UL

/************************        AHB Peripherals Base Addresses       ************************/
#define FSMC_BASE_ADDRESS          0xA0000000UL
#define USB_OTG_FS_BASE_ADDRESS    0x50000000UL
#define ETHERNET_BASE_ADDRESS      0x40028000UL
#define CRC_BASE_ADDRESS           0x40023000UL
#define RCC_BASE_ADDRESS           0x40021000UL
#define DMA2_BASE_ADDRESS          0x40020400UL
#define DMA1_BASE_ADDRESS          0x40020000UL
#define SDIO_BASE_ADDRESS          0x40018000UL

/************************        APB2 Peripherals Base Addresses       ************************/
#define TIM11_BASE_ADDRESS         0x40015400UL
#define TIM10_BASE_ADDRESS         0x40015000UL
#define TIM9_BASE_ADDRESS          0x40014C00UL
#define ADC3_BASE_ADDRESS          0x40013C00UL
#define USART1_BASE_ADDRESS        0x40013800UL
#define TIM8_BASE_ADDRESS          0x40013400UL
#define SPI1_BASE_ADDRESS          0x40013000UL
#define TIM1_BASE_ADDRESS          0x40012C00UL
#define ADC2_BASE_ADDRESS          0x40012800UL
#define ADC1_BASE_ADDRESS          0x40012400UL
#define GPIOG_BASE_ADDRESS         0x40012000UL
#define GPIOF_BASE_ADDRESS         0x40011C00UL
#define GPIOE_BASE_ADDRESS         0x40011800UL
#define GPIOD_BASE_ADDRESS         0x40011400UL
#define GPIOC_BASE_ADDRESS         0x40011000UL
#define GPIOB_BASE_ADDRESS         0x40010C00UL
#define GPIOA_BASE_ADDRESS         0x40010800UL
#define EXTI_BASE_ADDRESS          0x40010400UL
#define AFIO_BASE_ADDRESS          0x40010000UL

/************************        APB1 Peripherals Base Addresses       ************************/
#define DAC_BASE_ADDRESS           0x40007400UL
#define PWR_BASE_ADDRESS           0x40007000UL
#define BKP_BASE_ADDRESS           0x40006C00UL
#define CAN1_BASE_ADDRESS          0x40006400UL
#define CAN2_BASE_ADDRESS          0x40006800UL
#define SHARED_SRAM_BASE_ADDRESS   0x40006000UL
#define USB_BASE_ADDRESS           0x40005C00UL
#define I2C2_BASE_ADDRESS          0x40005800UL
#define I2C1_BASE_ADDRESS          0x40005400UL
#define UART5_BASE_ADDRESS         0x40005000UL
#define UART4_BASE_ADDRESS         0x40004C00UL
#define USART3_BASE_ADDRESS        0x40004800UL
#define USART2_BASE_ADDRESS        0x40004400UL
#define SPI3_I2S_BASE_ADDRESS      0x40003C00UL
#define SPI2_I2S_BASE_ADDRESS      0x40003800UL
#define IWDG_BASE_ADDRESS          0x40003000UL
#define WWDG_BASE_ADDRESS          0x40002C00UL
#define RTC_BASE_ADDRESS           0x40002800UL
#define TIM14_BASE_ADDRESS         0x40002000UL
#define TIM13_BASE_ADDRESS         0x40001C00UL
#define TIM12_BASE_ADDRESS         0x40001800UL
#define TIM7_BASE_ADDRESS          0x40001400UL
#define TIM6_BASE_ADDRESS          0x40001000UL
#define TIM5_BASE_ADDRESS          0x40000C00UL
#define TIM4_BASE_ADDRESS          0x40000800UL
#define TIM3_BASE_ADDRESS          0x40000400UL
#define TIM2_BASE_ADDRESS          0x40000000UL


/*******************************************************************************************************/
/********************************      Peripherals Definition Structure    ******************************/
/*******************************************************************************************************/

/************************       RCC Peripheral Definition Structure    ************************/

typedef struct{
	 volatile uint32_t  CR;              /*RCC clock control register*/
	 volatile uint32_t  CFGR;            /*RCC clock configuration register*/
	 volatile uint32_t  CIR;             /*RCC clock interrupt register*/
	 volatile uint32_t  APB2RSTR;        /*RCC APB2 Peripheral reset register*/
	 volatile uint32_t  APB1RSTR;        /*RCC APB1 Peripheral reset register*/
	 volatile uint32_t  AHBENR;          /*RCC AHB Peripheral clock Enable register*/
	 volatile uint32_t  APB2ENR;         /*RCC APB2 Peripheral clock Enable register*/
	 volatile uint32_t  APB1ENR;         /*RCC APB1 Peripheral clock Enable register*/
	 volatile uint32_t  BDCR;            /*RCC Backup domain control register*/
	 volatile uint32_t  CSR;             /*RCC control/status register*/
	 volatile uint32_t  AHBSTR;          /*RCC AHB peripheral clock reset register*/
	 volatile uint32_t  CFGR2;           /*RCC clock configuration register 2*/
}RCC_RegDef_t;

/************************       GPIO/AFIO Register Definition Structure       ************************/


typedef struct{
	 volatile uint32_t  CR[2];     /*GPIO PORT configuration Register */
	 volatile uint32_t  IDR;       /*GPIO PORT Input data Register*/
	 volatile uint32_t  ODR;       /*GPIO PORT Output data Register*/
	 volatile uint32_t  BSRR;      /*GPIO PORT Bit set/Reset Register*/
	 volatile uint32_t  BRR;       /*GPIO PORT Bit Reset Register*/
	 volatile uint32_t  LCKR;      /*GPIO PORT Lock Register*/
}GPIO_RegDef_t;

typedef struct{
	 volatile uint32_t  EVCR;          /*AFIO PORT Event control register Register */
	 volatile uint32_t  MAPR;          /*AFIO PORT remap and debug I/O configuration register*/
	 volatile uint32_t  EXTICR1;       /*AFIO PORT External interrupt configuration register 1*/
	 volatile uint32_t  EXTICR2;       /*AFIO PORT External interrupt configuration register 2*/
	 volatile uint32_t  EXTICR3;       /*AFIO PORT External interrupt configuration register 3*/
	 volatile uint32_t  EXTICR4;       /*AFIO PORT External interrupt configuration register 4*/
	 volatile uint32_t  MAPR2;         /*AFIO PORT remap and debug I/O configuration register2*/

}AFIO_RegDef_t;



/*******************************************************************************************************/
/********************************      Peripherals Definition      *************************************/
/*******************************************************************************************************/

/************************       RCC Peripheral Definitions        **************************/

#define RCC                   ((RCC_RegDef_t*)RCC_BASE_ADDRESS)

/************************       GPIO Peripheral Definitions       ************************/

 #define GPIOA                ((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)
 #define GPIOB                ((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)
 #define GPIOC                ((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)
 #define GPIOD                ((GPIO_RegDef_t*)GPIOD_BASE_ADDRESS)
 #define GPIOE                ((GPIO_RegDef_t*)GPIOE_BASE_ADDRESS)
 #define GPIOF                ((GPIO_RegDef_t*)GPIOF_BASE_ADDRESS)
 #define GPIOG                ((GPIO_RegDef_t*)GPIOG_BASE_ADDRESS)

#endif /* LIB_STM32F103C8XX_H_ */
