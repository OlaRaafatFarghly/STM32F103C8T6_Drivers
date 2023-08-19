#ifndef STM32F446XX_H
#define STM32F446XX_H

/************************       Various Memoreis Base Adresses       ************************/

#define FLASH_BASE_ADDRESS         0x40022000UL
#define SRAM_BASE_ADDRESS          0x20000000UL
//#define ROM_BASE_ADDRESS           0x1FFF0000UL


/************************       AHB1 Peripheral Base Adresses       ************************/
 
 #define RCC_BASE_ADDRESS          0x40021000UL

/************************       AHB2 Peripheral Base Adresses       ************************/

 #define GPIOA_BASE_ADDRESS        0x40010800UL
 #define GPIOB_BASE_ADDRESS        0x40010C00UL
 #define GPIOC_BASE_ADDRESS        0x40011000UL
 #define GPIOD_BASE_ADDRESS        0x40011400UL
 #define GPIOE_BASE_ADDRESS        0x40011800UL
 #define GPIOF_BASE_ADDRESS        0x40011C00UL
 #define GPIOG_BASE_ADDRESS        0x40012000UL

/************************       AHB3 Peripheral Base Adresses       ************************/



/************************       APB1 Peripheral Base Adresses       ************************/




/************************       APB2 Peripheral Base Adresses       ************************/



/************************       GPIO Register Definition Structure       ************************/


typedef struct{
	 volatile uint32_t  CRL;       /*GPIO PORT configuration Register Low*/ 
	 volatile uint32_t  CRH;       /*GPIO PORT configuration Register High*/
	 volatile uint32_t  IDR;       /*GPIO PORT Input data Register*/
	 volatile uint32_t  ODR;       /*GPIO PORT Output data Register*/
	 volatile uint32_t  BSRR;      /*GPIO PORT Bit set/Reset Register*/
	 volatile uint32_t  BRR;       /*GPIO PORT Bit Reset Register*/
	 volatile uint32_t  LCKR;      /*GPIO PORT Lock Register*/
}GPIO_RegDef_t;


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
}RCC_RegDef_t;

/************************       GPIO Peripheral Definitions       ************************/

 #define GPIOA                ((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)       
 #define GPIOB                ((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)
 #define GPIOC                ((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)
 #define GPIOD                ((GPIO_RegDef_t*)GPIOD_BASE_ADDRESS)
 #define GPIOE                ((GPIO_RegDef_t*)GPIOE_BASE_ADDRESS)
 #define GPIOF                ((GPIO_RegDef_t*)GPIOF_BASE_ADDRESS)
 #define GPIOG                ((GPIO_RegDef_t*)GPIOG_BASE_ADDRESS)


#endif