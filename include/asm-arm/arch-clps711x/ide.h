/*
 *  EDB7312 IDE support
 *  based on:
 *
 *  linux/include/asm-arm/arch-sa1100/ide.h
 *  Copyright (c) 1998 Hugo Fiennes & Nicolas Pitre
 *
 *  Copyright (c) 2003 Vladimir Ivanov <vladitx@nucleusys.com>
 */

#include <linux/config.h>
#include <asm/irq.h>
#include <asm/hardware.h>
#include <asm/mach-types.h>

/*
 * Set up a hw structure for a specified data port, control port and IRQ.
 * This should follow whatever the default interface uses.
 */
static __inline__ void
ide_init_hwif_ports(hw_regs_t *hw, int data_port, int ctrl_port, int *irq)
{
	ide_ioreg_t reg;
	int i;
	int regincr = 1;
	
	memset(hw, 0, sizeof(*hw));

	reg = (ide_ioreg_t)data_port;

	for (i = IDE_DATA_OFFSET; i <= IDE_STATUS_OFFSET; i++) {
		hw->io_ports[i] = reg;
		reg += regincr;
	}
	
	hw->io_ports[IDE_CONTROL_OFFSET] = (ide_ioreg_t) ctrl_port;
	
	if (irq)
		*irq = 0;
}

/*
 * This registers the standard ports for this architecture with the IDE
 * driver.
 */
static __inline__ void
ide_init_default_hwifs(void)
{
    if( machine_is_edb7312() ){
	hw_regs_t hw;
	
	ide_init_hwif_ports(&hw, EDB7312_VIRT_IDE + 0x0, EDB7312_VIRT_IDE + 0xE, NULL);
	hw.irq = IRQ_EINT2;
	ide_register_hw(&hw, NULL);
    }
}

