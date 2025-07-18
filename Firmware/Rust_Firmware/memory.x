/* Memory layout for Steam Controller - Complete chip replacement */
MEMORY
{
  /* Steam Controller flash: 128KB total, replacing entire chip memory */
  /* This firmware will completely replace all existing memory content */
  FLASH : ORIGIN = 0x00000000, LENGTH = 128K
  RAM : ORIGIN = 0x10000000, LENGTH = 4K
}

/* This is where the call stack will be allocated. */
/* The stack is growing downwards so the initial stack pointer 
   will be located at the end of RAM */
_stack_start = ORIGIN(RAM) + LENGTH(RAM);
