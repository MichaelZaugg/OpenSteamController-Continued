/* Memory layout for NXP LPC11U35 (256KB flash, 8KB RAM) */
MEMORY
{
  /* Bootloader occupies 0x0000 - 0x3FFF (16KB), so firmware starts at 0x4000 */
  FLASH (rx)  : ORIGIN = 0x4000, LENGTH = 240K
  RAM (rwx)   : ORIGIN = 0x10000000, LENGTH = 8K
}
