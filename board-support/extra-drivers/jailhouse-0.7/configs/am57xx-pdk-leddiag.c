/*
 * Jailhouse, a Linux-based partitioning hypervisor
 *
 * Configuration for uart-demo inmate on AM57XX-EVM:
 *
 * Copyright (c) Texas Instruments, Inc.
 *
 * Authors:
 *  Vitaly Andrianiov <vitalya@ti.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2.  See
 * the COPYING file in the top-level directory.
 */

#include <jailhouse/types.h>
#include <jailhouse/cell-config.h>

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

struct {
	struct jailhouse_cell_desc cell;
	__u64 cpus[1];
	struct jailhouse_memory mem_regions[6];
	struct jailhouse_irqchip irqchips[1];
} __attribute__((packed)) config = {
	.cell = {
		.signature = JAILHOUSE_CELL_DESC_SIGNATURE,
		.revision = JAILHOUSE_CONFIG_REVISION,
		.name = "AM57XX-EVM-PDK-LED",
		.flags = JAILHOUSE_CELL_PASSIVE_COMMREG,
		.num_irqchips = 1,
		.cpu_set_size = sizeof(config.cpus),
		.num_memory_regions = ARRAY_SIZE(config.mem_regions),
	},

	.cpus = {
		0x2,
	},

	.mem_regions = {
		/* UART... */ {
			.phys_start = 0x48020000,
			.virt_start = 0x48020000,
			.size = 0x1000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO | JAILHOUSE_MEM_ROOTSHARED,
		},
		/* GPIO etc... */ {
			.phys_start = 0x48050000,
			.virt_start = 0x48050000,
			.size = 0x10000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO | JAILHOUSE_MEM_ROOTSHARED,
		},
		/* UART... */ {
			.phys_start = 0x48424000,
			.virt_start = 0x48424000,
			.size = 0x1000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO | JAILHOUSE_MEM_ROOTSHARED,
		},
		/* TIMER... */ {
			.phys_start = 0x48826000,
			.virt_start = 0x48826000,
			.size = 0x1000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO | JAILHOUSE_MEM_ROOTSHARED,
		},
		/* L4_CFG */ {
			.phys_start = 0x4a000000,
			.virt_start = 0x4a000000,
			.size = 0xE10000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO | JAILHOUSE_MEM_ROOTSHARED,
		},
		/* RAM */ {
			.phys_start = 0xee000000,
			.virt_start = 0x00000000,
			.size = 0x100000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_EXECUTE | JAILHOUSE_MEM_LOADABLE,
		},
	},
	.irqchips = {
		/* GIC */ {
			.address = 0x48211000,
			.pin_base = 160,
			.pin_bitmap = {
				0x00000040,
			},
		},
	}
};