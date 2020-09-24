/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2019-2020, The Linux Foundation. All rights reserved.
 */

#ifndef __HFI_IO_COMMON_H__
#define __HFI_IO_COMMON_H__

#include <linux/io.h>

#define VBIF_BASE_OFFS			0x00080000

#define CPU_BASE_OFFS			0x000C0000
#define CPU_CS_BASE_OFFS		(CPU_BASE_OFFS + 0x00012000)
#define CPU_IC_BASE_OFFS		(CPU_BASE_OFFS + 0x0001F000)

#define CPU_CS_A2HSOFTINT		(CPU_CS_BASE_OFFS + 0x18)
#define CPU_CS_A2HSOFTINTCLR	(CPU_CS_BASE_OFFS + 0x1C)
#define CPU_CS_VMIMSG		(CPU_CS_BASE_OFFS + 0x34)
#define CPU_CS_VMIMSGAG0		(CPU_CS_BASE_OFFS + 0x38)
#define CPU_CS_VMIMSGAG1		(CPU_CS_BASE_OFFS + 0x3C)
#define CPU_CS_SCIACMD			(CPU_CS_BASE_OFFS + 0x48)

/* HFI_CTRL_STATUS */
#define CPU_CS_SCIACMDARG0		(CPU_CS_BASE_OFFS + 0x4C)
#define CPU_CS_SCIACMDARG0_HFI_CTRL_ERROR_STATUS_BMSK	0xfe
#define CPU_CS_SCIACMDARG0_HFI_CTRL_PC_READY           0x100
#define CPU_CS_SCIACMDARG0_HFI_CTRL_INIT_IDLE_MSG_BMSK     0x40000000

/* HFI_QTBL_INFO */
#define CPU_CS_SCIACMDARG1		(CPU_CS_BASE_OFFS + 0x50)

/* HFI_QTBL_ADDR */
#define CPU_CS_SCIACMDARG2		(CPU_CS_BASE_OFFS + 0x54)

/* HFI_VERSION_INFO */
#define CPU_CS_SCIACMDARG3		(CPU_CS_BASE_OFFS + 0x58)

/* SFR_ADDR */
#define CPU_CS_SCIBCMD		(CPU_CS_BASE_OFFS + 0x5C)

/* MMAP_ADDR */
#define CPU_CS_SCIBCMDARG0		(CPU_CS_BASE_OFFS + 0x60)

/* UC_REGION_ADDR */
#define CPU_CS_SCIBARG1		(CPU_CS_BASE_OFFS + 0x64)

/* UC_REGION_ADDR */
#define CPU_CS_SCIBARG2		(CPU_CS_BASE_OFFS + 0x68)

#define CPU_IC_SOFTINT			(CPU_IC_BASE_OFFS + 0x18)
#define CPU_IC_SOFTINT_H2A_SHFT	0xF

/*
 * --------------------------------------------------------------------------
 * MODULE: wrapper
 * --------------------------------------------------------------------------
 */
#define WRAPPER_BASE_OFFS		0x000E0000
#define WRAPPER_INTR_STATUS	(WRAPPER_BASE_OFFS + 0x0C)
#define WRAPPER_INTR_STATUS_A2HWD_BMSK	0x10
#define WRAPPER_INTR_STATUS_A2H_BMSK	0x4

#define WRAPPER_INTR_MASK		(WRAPPER_BASE_OFFS + 0x10)
#define WRAPPER_INTR_MASK_A2HWD_BMSK	0x10
#define WRAPPER_INTR_MASK_A2HVCODEC_BMSK	0x8
#define WRAPPER_INTR_MASK_A2HCPU_BMSK	0x4
#define WRAPPER_INTR_CLEAR		(WRAPPER_BASE_OFFS + 0x14)

#define WRAPPER_CPU_CLOCK_CONFIG	(WRAPPER_BASE_OFFS + 0x2000)
#define WRAPPER_CPU_CGC_DIS	(WRAPPER_BASE_OFFS + 0x2010)
#define WRAPPER_CPU_STATUS (WRAPPER_BASE_OFFS + 0x2014)

#define CTRL_INIT		CPU_CS_SCIACMD

#define CTRL_STATUS	CPU_CS_SCIACMDARG0
#define CTRL_ERROR_STATUS__M \
		CPU_CS_SCIACMDARG0_HFI_CTRL_ERROR_STATUS_BMSK
#define CTRL_INIT_IDLE_MSG_BMSK \
		CPU_CS_SCIACMDARG0_HFI_CTRL_INIT_IDLE_MSG_BMSK
#define CTRL_STATUS_PC_READY \
		CPU_CS_SCIACMDARG0_HFI_CTRL_PC_READY


#define QTBL_INFO		CPU_CS_SCIACMDARG1

#define QTBL_ADDR		CPU_CS_SCIACMDARG2

#define VERSION_INFO	CPU_CS_SCIACMDARG3

#define SFR_ADDR		CPU_CS_SCIBCMD
#define MMAP_ADDR		CPU_CS_SCIBCMDARG0
#define UC_REGION_ADDR	CPU_CS_SCIBARG1
#define UC_REGION_SIZE	CPU_CS_SCIBARG2

/* HFI_DSP_QTBL_ADDR
 * 31:3 - HFI_DSP_QTBL_ADDR
 *        4-byte aligned Address
 */
#define HFI_DSP_QTBL_ADDR	CPU_CS_VMIMSG

/* HFI_DSP_UC_REGION_ADDR
 * 31:20 - HFI_DSP_UC_REGION_ADDR
 *         1MB aligned address.
 *         Uncached Region start Address. This region covers
 *         HFI DSP QTable,
 *         HFI DSP Queue Headers,
 *         HFI DSP Queues,
 */
#define HFI_DSP_UC_REGION_ADDR	CPU_CS_VMIMSGAG0

/* HFI_DSP_UC_REGION_SIZE
 * 31:20 - HFI_DSP_UC_REGION_SIZE
 *         Multiples of 1MB.
 *         Size of the DSP_UC_REGION Uncached Region
 */
#define HFI_DSP_UC_REGION_SIZE	CPU_CS_VMIMSGAG1

/*
 * --------------------------------------------------------------------------
 * MODULE: vcodec noc error log registers
 * --------------------------------------------------------------------------
 */
#define VCODEC_CORE0_VIDEO_NOC_BASE_OFFS		0x00004000
#define CVP_NOC_BASE_OFFS				0x0000C000
#define VCODEC_COREX_VIDEO_NOC_ERR_SWID_LOW_OFFS	0x0500
#define VCODEC_COREX_VIDEO_NOC_ERR_SWID_HIGH_OFFS	0x0504
#define VCODEC_COREX_VIDEO_NOC_ERR_MAINCTL_LOW_OFFS	0x0508
#define VCODEC_COREX_VIDEO_NOC_ERR_ERRVLD_LOW_OFFS	0x0510
#define VCODEC_COREX_VIDEO_NOC_ERR_ERRCLR_LOW_OFFS	0x0518
#define VCODEC_COREX_VIDEO_NOC_ERR_ERRLOG0_LOW_OFFS	0x0520
#define VCODEC_COREX_VIDEO_NOC_ERR_ERRLOG0_HIGH_OFFS	0x0524
#define VCODEC_COREX_VIDEO_NOC_ERR_ERRLOG1_LOW_OFFS	0x0528
#define VCODEC_COREX_VIDEO_NOC_ERR_ERRLOG1_HIGH_OFFS	0x052C
#define VCODEC_COREX_VIDEO_NOC_ERR_ERRLOG2_LOW_OFFS	0x0530
#define VCODEC_COREX_VIDEO_NOC_ERR_ERRLOG2_HIGH_OFFS	0x0534
#define VCODEC_COREX_VIDEO_NOC_ERR_ERRLOG3_LOW_OFFS	0x0538
#define VCODEC_COREX_VIDEO_NOC_ERR_ERRLOG3_HIGH_OFFS	0x053C
#endif
