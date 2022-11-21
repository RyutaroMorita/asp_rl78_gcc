/*
 *	2022/10/12 Ryutaro Morita
 */

OUTPUT_ARCH(rl78)
STARTUP(start.o)

PROVIDE (hardware_init_hook = 0) ;
PROVIDE (software_init_hook = 0) ;
PROVIDE (_software_term_hook = 0) ;

MEMORY
{
	ROM :		ORIGIN = 0x00000,	LENGTH = 0x7FE00
	RAM :		ORIGIN = 0xF3F00,	LENGTH = 0x0C000
}

SECTIONS
{
	.text :
	{
		__text = .;
		KEEP(*(.vec))
		KEEP(*(.vects))
		. = ABSOLUTE(0xc0);
		KEEP(*(.option_bytes))
		KEEP(*(.security_id))
		. = ABSOLUTE(0xd8);
		*(.text)
		*(.text.*)
	} > ROM
	etext = .;
/*
	.rodata :
	{
		KEEP(*(.rodata))
		*(.rodata.*)
	} > ROM
*/
	. = ALIGN(2);

	__idata_start = .;
	.data : AT(__idata_start)
	{
		__data_start = .;
		*(.rodata)
		*(.rodata.*)
		*(.data)
		*(.data.*)
	} > RAM
	__idata_end = __idata_start + SIZEOF(.data);
	_edata = .;
	PROVIDE(edata = .);

	. = ALIGN(2);

	.bss :
	{
		__bss_start  = .;
		*(.bss)
		*(.bss.**)
		*(COMMON)
		. = ALIGN(2);
	} > RAM
	. = ALIGN(2);
	_end = .;
	__bss_end = .;
	PROVIDE(end = .);
}
