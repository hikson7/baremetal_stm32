// #include "main.h"

// void LED_Init();

// int main(void)
// {
//     HAL_Init();
//     LED_Init();
//     while (1) {
//         HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN);
//         // LED_GPIO_PORT->ODR |= 0x00000020;
//         // HAL_Delay(1000);
//         delay_ms(100);
//     }
// }

// void LED_Init()
// {
//     GPIO_InitTypeDef GPIO_InitStruct = {0};
//     // LED_GPIO_CLK_ENABLE();
//     __HAL_RCC_GPIOA_CLK_ENABLE();

//     HAL_GPIO_WritePin(LED_GPIO_PORT, LED_PIN, GPIO_PIN_RESET);
//     GPIO_InitStruct.Pin = LED_PIN;
//     GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//     GPIO_InitStruct.Pull = GPIO_NOPULL;
//     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//     HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);
// }

// void SysTick_Handler(void)
// {
//     HAL_IncTick();
// }


#include "stm32f4xx.h"

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
    int ms = 250;
    while (1) {
        GPIOA->ODR |= 0x00000020;
        // GPIOA->BSRR = 0x00000020;
        delay_ms(ms);
        GPIOA->ODR &= ~0x00000020;
        // GPIOA->BSRR = 0x00200000;
        delay_ms(ms);
    }
}

void exit() {
    
}

int main(void)
{
    setup();
    loop();    
}
