
/* Set entry point */
ENTRY(reset_handler)

/* Provide end of stack i.e. Highest address of user RAM */
_estack = ORIGIN(sram) + LENGTH(sram);

MEMORY
{
  flash (rx)    : ORIGIN =  0x08000000,   LENGTH = 512K
  sram  (xrw)   : ORIGIN =  0x20000000,   LENGTH = 128K
}

SECTIONS
{ 
    /* Contains code & constants. */
  
    .text :
    {
        . = ALIGN(4);
        _stext = .;             /* start of .text section i.e. start of code memory*/

        KEEP(*(.my_isr_vector)) /* vector table defined at startup */
        *(.text*)
        *(.rodata*)

        . = ALIGN(4);
        _etext = .;
    } > flash

    /* Initialised variable section. */
    .data :
    {
        . = ALIGN(4);
        _sdata = .;

        *(.data*)
        _edata = .;

    } > sram AT > flash

    /*
    LMA -> flash
    VMA -> sram
    */
    /* Uninitialised variable section. */
    .bss (NOLOAD) :
    {
        . = ALIGN(4);
        _sbss = .;
        
        *(.bss*)    /* Uninitialised static variables */
        *(COMMON)   /* Uninitialised global variables */
        
        . = ALIGN(4);
        _ebss = .;
    } > sram

  .ARM.attributes 0 : { *(.ARM.attributes) }
}
