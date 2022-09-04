#include "stm32f446xx.h"

// volatile int my_global_uninit;
// volatile static int my_static_global_uninit;
// volatile int my_global_init = 10;
// volatile static int my_static_global_init = 11;

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
    volatile const int ms = 1000;
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
