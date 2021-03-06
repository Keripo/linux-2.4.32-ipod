/* $Header$
 *
 * uclinux/include/asm-armnommu/arch-isl3893/processor.h
 *
 * Copyright (C) 2002 Intersil Americas Inc.
 *
 */
#ifndef __ASM_ARCH_PROCESSOR_H
#define __ASM_ARCH_PROCESSOR_H

#define EISA_bus 0
#define EISA_bus__is_a_macro
#define MCA_bus 0
#define MCA_bus__is_a_macro

#define INIT_MMAP { \
  &init_mm, 0, 0x02000000, PAGE_SHARED, VM_READ | VM_WRITE | VM_EXEC \
}

#endif
