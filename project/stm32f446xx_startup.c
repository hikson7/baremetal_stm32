
/*
 A startup file for a typical microcontroller requires at least the following:
 - Stack Pointer
 - Reset Handler
 - Vector table
 */
// #include "stm32f446xx.h"
#include <stdint.h>

// extern uint32_t _stext;
extern uint32_t _etext;

extern uint32_t _sdata;
extern uint32_t _edata;

extern uint32_t _sbss;
extern uint32_t _ebss;

extern uint32_t _estack;
int main(void);

void default_handler(void)
{
    while (1) {}
}

/*
 Reset Handler's job is to:
    1. Zero-out uninitialized global/static variables.
        i.e. set .bss values to 0
    2. Initialise static variables with values.
        i.e. Copy .data section values from Flash to RA
    3. Point the stack pointer to bottom of the stack.
 */
void reset_handler(void)
{
    // Assign 0 to uninitialised variables.
    for (uint32_t* bss_ptr = &_sbss; bss_ptr < &_ebss; bss_ptr++) {
        *bss_ptr = 0;
    }

    // Initialise static/global variables
    uint32_t* src = &_etext;
    uint32_t* dest = &_sdata;
    for (; dest < &_edata;) {
        *dest = *src;
        dest++;
        src++;
    }

    main();
    while (1) {}
}

__attribute__ ((section(".my_isr_vector")))
void (* const interrupt_vector_table[])(void) =
{
    (void *) &_estack,      // 0 - stack
    reset_handler,          // 
    default_handler,        // nmi_handler
    default_handler,        // hardfault_handler
    default_handler,        // mem_manage_handler
    default_handler,        // busfault_handler
    default_handler,        // usage_fault_handler
    0,                      // reserved
    0,                      // reserved
    0,                      // reserved
    0,                      // reserved
    default_handler,        // svcall_handler
    default_handler,        // dbg_monitor_handler
    0,                      // reserved
    default_handler,        // pends_handler
    default_handler,        // systick_handler
    default_handler,        //  0. wwdg_irq_handler
    default_handler,        //  1.
    default_handler,        //  2.
    default_handler,        //  3.
    default_handler,        //  4.
    default_handler,        //  5.
    default_handler,        //  6. 
    default_handler,        //  7.
    default_handler,        //  8.
    default_handler,        //  9.
    default_handler,        // 10.
    default_handler,        // 11.
    default_handler,        // 12.
    default_handler,        // 13.
    default_handler,        // 14.
    default_handler,        // 15.
    default_handler,        // 16.
    default_handler,        // 17.
    default_handler,        // 18.
    default_handler,        // 19.
    default_handler,        // 20.
    default_handler,        // 21.
    default_handler,        // 22.
    default_handler,        // 23.
    default_handler,        // 24.
    default_handler,        // 25.
    default_handler,        // 26.
    default_handler,        // 27.
    default_handler,        // 28.
    default_handler,        // 29.
    default_handler,        // 30.
    default_handler,        // 31.
    default_handler,        // 32.
    default_handler,        // 33.
    default_handler,        // 34. 
    default_handler,        // 35.
    default_handler,        // 36. 
    default_handler,        // 37. 
    default_handler,        // 38. 
    default_handler,        // 39. 
    default_handler,        // 40.
    default_handler,        // 41.
    default_handler,        // 42.
    default_handler,        // 43.
    default_handler,        // 44.
    default_handler,        // 45.
    default_handler,        // 46. 
    default_handler,        // 47. 
    default_handler,        // 48.
    default_handler,        // 49.
    default_handler,        // 50.
    default_handler,        // 51.
    default_handler,        // 52.
    default_handler,        // 53.
    default_handler,        // 54.
    default_handler,        // 55.
    default_handler,        // 56.
    default_handler,        // 57.
    default_handler,        // 58.
    default_handler,        // 59.
    default_handler,        // 60.
    default_handler,        // 61.
    default_handler,        // 62.
    default_handler,        // 63.
    default_handler,        // 64.
    default_handler,        // 65.
    default_handler,        // 66.
    default_handler,        // 67.
    default_handler,        // 68.
    default_handler,        // 69.
    default_handler,        // 70.
    default_handler,        // 71.
    default_handler,        // 72.
    default_handler,        // 73.
    default_handler,        // 74.
    default_handler,        // 75.
    default_handler,        // 76.
    default_handler,        // 77.
    default_handler,        // 78.
    default_handler,        // 79. 
    default_handler,        // 80.
    default_handler,        // 81.
    default_handler,        // 82.
    default_handler,        // 83.
    default_handler,        // 84.
    default_handler,        // 85.
    default_handler,        // 86.
    default_handler,        // 87.
    default_handler,        // 88.
    default_handler,        // 89.
    default_handler,        // 90.
    default_handler,        // 91.
    default_handler,        // 92.
    default_handler,        // 93. 
    default_handler,        // 94.
    default_handler,        // 95.
    default_handler,        // 96.
};
