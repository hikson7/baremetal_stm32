
// #include <stdint.h>
// #define     __IO    volatile             /*!< Defines 'read / write' permissions */

// typedef struct
// {
//   __IO uint32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
//   __IO uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
//   __IO uint32_t CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
//   __IO uint32_t CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
//   __IO uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
//   __IO uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
//   __IO uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
//   uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                                    */
//   __IO uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
//   __IO uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
//   uint32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
//   __IO uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
//   __IO uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
//   __IO uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
//   uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                                    */
//   __IO uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
//   __IO uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
//   uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
//   __IO uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
//   __IO uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
//   __IO uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
//   uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                                    */
//   __IO uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
//   __IO uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
//   uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
//   __IO uint32_t BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
//   __IO uint32_t CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
//   uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
//   __IO uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
//   __IO uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
//   __IO uint32_t PLLSAICFGR;    /*!< RCC PLLSAI configuration register,                           Address offset: 0x88 */
//   __IO uint32_t DCKCFGR;       /*!< RCC Dedicated Clocks configuration register,                 Address offset: 0x8C */
//   __IO uint32_t CKGATENR;      /*!< RCC Clocks Gated ENable Register,                            Address offset: 0x90 */
//   __IO uint32_t DCKCFGR2;      /*!< RCC Dedicated Clocks configuration register 2,               Address offset: 0x94 */
// } RCC_TypeDef;

// #define RCC_AHB1ENR_GPIOAEN_Pos            (0U)                                
// #define RCC_AHB1ENR_GPIOAEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOAEN_Pos)   /*!< 0x00000001 */
// #define RCC_AHB1ENR_GPIOAEN                RCC_AHB1ENR_GPIOAEN_Msk             

// #define PERIPH_BASE           0x40000000UL /*!< Peripheral base address in the alias region                                */
// #define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
// #define RCC_BASE              (AHB1PERIPH_BASE + 0x3800UL)
// #define RCC                 ((RCC_TypeDef *) RCC_BASE)

// #define READ_BIT(REG, BIT)    ((REG) & (BIT))
// #define UNUSED(X) (void)X      /* To avoid gcc/g++ warnings */

// #define __HAL_RCC_GPIOA_CLK_ENABLE()   do { \
//                                         __IO uint32_t tmpreg = 0x00U; \
//                                         SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);\
//                                         /* Delay after an RCC peripheral clock enabling */ \
//                                         tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);\
//                                         UNUSED(tmpreg); \
//                                           } while(0U)

// #define LED_PIN
// #define LED_GPIO_PORT
// #define LED_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOA_CLK_ENABLE()

#include "stm32f446xx.h"

volatile int my_global_uninit;
volatile static int my_static_global_uninit;
volatile int my_global_init = 10;
volatile static int my_static_global_init = 11;

void delay_ms(int ms) {
    volatile int i;
    for (; ms > 0; ms--) {
        for (i=0; i < 3195; i++) {}
    }
}

void setup()
{
    RCC->AHB1ENR |= 1;
    GPIOA->MODER &= ~0x00000C00;
    GPIOA->MODER |= 0x00000400;
}

void loop()
{
    volatile const int ms = 500;
    while (1) {
        // GPIOA->ODR |= 0x00000020;
        GPIOA->BSRR = 0x00000020;
        delay_ms(ms);
        // GPIOA->ODR &= ~0x00000020;
        GPIOA->BSRR = 0x00200000;
        delay_ms(ms);
    }
}

int main(void)
{
    setup();
    loop();
}

// int main(void)
// { 
//     // setup
//     RCC->AHB1ENR |= 1;
//     GPIOA->MODER &= ~0x00000C00;
//     GPIOA->MODER |= 0x00000400;

//     // blink
//     volatile int i;
//     while (1) {
//         GPIOA->BSRR = 0x00000020;
//         int ms = 1000;
//         for (; ms > 0; ms--) {
//             for (i=0; i < 3195; i++) {}
//         }
//         ms = 1000;    
//         GPIOA->BSRR = 0x00200000;
//         for (; ms > 0; ms--) {
//             for (i=0; i < 3195; i++) {}
//         }
//     }
// }


// void exit(int code)
// {
//     while (1) {}
// }