/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright 2021 ROHM Semiconductors.
 *
 * Author: Matti Vaittinen <matti.vaittinen@fi.rohmeurope.com>
 *
 * Copyright 2014 Embest Technology Co. Ltd. Inc.
 *
 * Author: yanglsh@embest-tech.com
 */

#ifndef _MFD_BD71815_H
#define _MFD_BD71815_H

#include <linux/regmap.h>

enum {
	BD71815_BUCK1	=	0,
	BD71815_BUCK2,
	BD71815_BUCK3,
	BD71815_BUCK4,
	BD71815_BUCK5,
	/* General Purpose */
	BD71815_LDO1,
	BD71815_LDO2,
	BD71815_LDO3,
	/* LDOs for SD Card and SD Card Interface */
	BD71815_LDO4,
	BD71815_LDO5,
	/* LDO for DDR Reference Voltage */
	BD71815_LDODVREF,
	/* LDO for Low-Power State Retention */
	BD71815_LDOLPSR,
	BD71815_WLED,
	BD71815_REGULATOR_CNT,
};

#define BD71815_SUPPLY_STATE_ENABLED    0x1

enum {
	BD71815_REG_DEVICE		= 0,
	BD71815_REG_PWRCTRL,
	BD71815_REG_BUCK1_MODE,
	BD71815_REG_BUCK2_MODE,
	BD71815_REG_BUCK3_MODE,
	BD71815_REG_BUCK4_MODE,
	BD71815_REG_BUCK5_MODE,
	BD71815_REG_BUCK1_VOLT_H,
	BD71815_REG_BUCK1_VOLT_L,
	BD71815_REG_BUCK2_VOLT_H,
	BD71815_REG_BUCK2_VOLT_L,
	BD71815_REG_BUCK3_VOLT,
	BD71815_REG_BUCK4_VOLT,
	BD71815_REG_BUCK5_VOLT,
	BD71815_REG_LED_CTRL,
	BD71815_REG_LED_DIMM,
	BD71815_REG_LDO_MODE1,
	BD71815_REG_LDO_MODE2,
	BD71815_REG_LDO_MODE3,
	BD71815_REG_LDO_MODE4,
	BD71815_REG_LDO1_VOLT,
	BD71815_REG_LDO2_VOLT,
	BD71815_REG_LDO3_VOLT,
	BD71815_REG_LDO4_VOLT,
	BD71815_REG_LDO5_VOLT_H,
	BD71815_REG_LDO5_VOLT_L,
	BD71815_REG_BUCK_PD_DIS,
	BD71815_REG_LDO_PD_DIS,
	BD71815_REG_GPO,
	BD71815_REG_OUT32K,
	BD71815_REG_SEC,
	BD71815_REG_MIN,
	BD71815_REG_HOUR,
	BD71815_REG_WEEK,
	BD71815_REG_DAY,
	BD71815_REG_MONTH,
	BD71815_REG_YEAR,
	BD71815_REG_ALM0_SEC,

	BD71815_REG_ALM1_SEC		= 0x2C,

	BD71815_REG_ALM0_MASK		= 0x33,
	BD71815_REG_ALM1_MASK,
	BD71815_REG_ALM2,
	BD71815_REG_TRIM,
	BD71815_REG_CONF,
	BD71815_REG_SYS_INIT,
	BD71815_REG_CHG_STATE,
	BD71815_REG_CHG_LAST_STATE,
	BD71815_REG_BAT_STAT,
	BD71815_REG_DCIN_STAT,
	BD71815_REG_VSYS_STAT,
	BD71815_REG_CHG_STAT,
	BD71815_REG_CHG_WDT_STAT,
	BD71815_REG_BAT_TEMP,
	BD71815_REG_IGNORE_0,
	BD71815_REG_INHIBIT_0,
	BD71815_REG_DCIN_CLPS,
	BD71815_REG_VSYS_REG,
	BD71815_REG_VSYS_MAX,
	BD71815_REG_VSYS_MIN,
	BD71815_REG_CHG_SET1,
	BD71815_REG_CHG_SET2,
	BD71815_REG_CHG_WDT_PRE,
	BD71815_REG_CHG_WDT_FST,
	BD71815_REG_CHG_IPRE,
	BD71815_REG_CHG_IFST,
	BD71815_REG_CHG_IFST_TERM,
	BD71815_REG_CHG_VPRE,
	BD71815_REG_CHG_VBAT_1,
	BD71815_REG_CHG_VBAT_2,
	BD71815_REG_CHG_VBAT_3,
	BD71815_REG_CHG_LED_1,
	BD71815_REG_VF_TH,
	BD71815_REG_BAT_SET_1,
	BD71815_REG_BAT_SET_2,
	BD71815_REG_BAT_SET_3,
	BD71815_REG_ALM_VBAT_TH_U,
	BD71815_REG_ALM_VBAT_TH_L,
	BD71815_REG_ALM_DCIN_TH,
	BD71815_REG_ALM_VSYS_TH,
	BD71815_REG_VM_IBAT_U,
	BD71815_REG_VM_IBAT_L,
	BD71815_REG_VM_VBAT_U,
	BD71815_REG_VM_VBAT_L,
	BD71815_REG_VM_BTMP,
	BD71815_REG_VM_VTH,
	BD71815_REG_VM_DCIN_U,
	BD71815_REG_VM_DCIN_L,
	BD71815_REG_VM_VSYS,
	BD71815_REG_VM_VF,
	BD71815_REG_VM_OCI_PRE_U,
	BD71815_REG_VM_OCI_PRE_L,
	BD71815_REG_VM_OCV_PRE_U,
	BD71815_REG_VM_OCV_PRE_L,
	BD71815_REG_VM_OCI_PST_U,
	BD71815_REG_VM_OCI_PST_L,
	BD71815_REG_VM_OCV_PST_U,
	BD71815_REG_VM_OCV_PST_L,
	BD71815_REG_VM_SA_VBAT_U,
	BD71815_REG_VM_SA_VBAT_L,
	BD71815_REG_VM_SA_IBAT_U,
	BD71815_REG_VM_SA_IBAT_L,
	BD71815_REG_CC_CTRL,
	BD71815_REG_CC_BATCAP1_TH_U,
	BD71815_REG_CC_BATCAP1_TH_L,
	BD71815_REG_CC_BATCAP2_TH_U,
	BD71815_REG_CC_BATCAP2_TH_L,
	BD71815_REG_CC_BATCAP3_TH_U,
	BD71815_REG_CC_BATCAP3_TH_L,
	BD71815_REG_CC_STAT,
	BD71815_REG_CC_CCNTD_3,
	BD71815_REG_CC_CCNTD_2,
	BD71815_REG_CC_CCNTD_1,
	BD71815_REG_CC_CCNTD_0,
	BD71815_REG_CC_CURCD_U,
	BD71815_REG_CC_CURCD_L,
	BD71815_REG_VM_OCUR_THR_1,
	BD71815_REG_VM_OCUR_DUR_1,
	BD71815_REG_VM_OCUR_THR_2,
	BD71815_REG_VM_OCUR_DUR_2,
	BD71815_REG_VM_OCUR_THR_3,
	BD71815_REG_VM_OCUR_DUR_3,
	BD71815_REG_VM_OCUR_MON,
	BD71815_REG_VM_BTMP_OV_THR,
	BD71815_REG_VM_BTMP_OV_DUR,
	BD71815_REG_VM_BTMP_LO_THR,
	BD71815_REG_VM_BTMP_LO_DUR,
	BD71815_REG_VM_BTMP_MON,
	BD71815_REG_INT_EN_01,

	BD71815_REG_INT_EN_11		= 0x95,
	BD71815_REG_INT_EN_12,
	BD71815_REG_INT_STAT,
	BD71815_REG_INT_STAT_01,
	BD71815_REG_INT_STAT_02,
	BD71815_REG_INT_STAT_03,
	BD71815_REG_INT_STAT_04,
	BD71815_REG_INT_STAT_05,
	BD71815_REG_INT_STAT_06,
	BD71815_REG_INT_STAT_07,
	BD71815_REG_INT_STAT_08,
	BD71815_REG_INT_STAT_09,
	BD71815_REG_INT_STAT_10,
	BD71815_REG_INT_STAT_11,
	BD71815_REG_INT_STAT_12,
	BD71815_REG_INT_UPDATE,

	BD71815_REG_VM_VSYS_U		= 0xC0,
	BD71815_REG_VM_VSYS_L,
	BD71815_REG_VM_SA_VSYS_U,
	BD71815_REG_VM_SA_VSYS_L,

	BD71815_REG_VM_SA_IBAT_MIN_U	= 0xD0,
	BD71815_REG_VM_SA_IBAT_MIN_L,
	BD71815_REG_VM_SA_IBAT_MAX_U,
	BD71815_REG_VM_SA_IBAT_MAX_L,
	BD71815_REG_VM_SA_VBAT_MIN_U,
	BD71815_REG_VM_SA_VBAT_MIN_L,
	BD71815_REG_VM_SA_VBAT_MAX_U,
	BD71815_REG_VM_SA_VBAT_MAX_L,
	BD71815_REG_VM_SA_VSYS_MIN_U,
	BD71815_REG_VM_SA_VSYS_MIN_L,
	BD71815_REG_VM_SA_VSYS_MAX_U,
	BD71815_REG_VM_SA_VSYS_MAX_L,
	BD71815_REG_VM_SA_MINMAX_CLR,

	BD71815_REG_REX_CCNTD_3		= 0xE0,
	BD71815_REG_REX_CCNTD_2,
	BD71815_REG_REX_CCNTD_1,
	BD71815_REG_REX_CCNTD_0,
	BD71815_REG_REX_SA_VBAT_U,
	BD71815_REG_REX_SA_VBAT_L,
	BD71815_REG_REX_CTRL_1,
	BD71815_REG_REX_CTRL_2,
	BD71815_REG_FULL_CCNTD_3,
	BD71815_REG_FULL_CCNTD_2,
	BD71815_REG_FULL_CCNTD_1,
	BD71815_REG_FULL_CCNTD_0,
	BD71815_REG_FULL_CTRL,

	BD71815_REG_CCNTD_CHG_3		= 0xF0,
	BD71815_REG_CCNTD_CHG_2,

	BD71815_REG_TEST_MODE		= 0xFE,
	BD71815_MAX_REGISTER,
};

/* BD71815_REG_BUCK1_MODE bits */
#define BD71815_BUCK_RAMPRATE_MASK		0xC0
#define BD71815_BUCK_RAMPRATE_10P00MV		0x0
#define BD71815_BUCK_RAMPRATE_5P00MV		0x01
#define BD71815_BUCK_RAMPRATE_2P50MV		0x02
#define BD71815_BUCK_RAMPRATE_1P25MV		0x03

#define BD71815_BUCK_PWM_FIXED			BIT(4)
#define BD71815_BUCK_SNVS_ON			BIT(3)
#define BD71815_BUCK_RUN_ON			BIT(2)
#define BD71815_BUCK_LPSR_ON			BIT(1)
#define BD71815_BUCK_SUSP_ON			BIT(0)

/* BD71815_REG_BUCK1_VOLT_H bits */
#define BD71815_BUCK_DVSSEL			BIT(7)
#define BD71815_BUCK_STBY_DVS			BIT(6)
#define BD71815_VOLT_MASK			0x3F
#define BD71815_BUCK1_H_DEFAULT			0x14
#define BD71815_BUCK1_L_DEFAULT			0x14

/* BD71815_REG_BUCK2_VOLT_H bits */
#define BD71815_BUCK2_H_DEFAULT			0x14
#define BD71815_BUCK2_L_DEFAULT			0x14

/* WLED output */
/* current register mask */
#define LED_DIMM_MASK				0x3f
/* LED enable bits at LED_CTRL reg */
#define LED_CHGDONE_EN				BIT(4)
#define LED_RUN_ON				BIT(2)
#define LED_LPSR_ON				BIT(1)
#define LED_SUSP_ON				BIT(0)

/* BD71815_REG_LDO1_CTRL bits */
#define LDO1_EN					BIT(0)
#define LDO2_EN					BIT(1)
#define LDO3_EN					BIT(2)
#define DVREF_EN				BIT(3)
#define VOSNVS_SW_EN				BIT(4)

/* LDO_MODE1_register */
#define LDO1_SNVS_ON				BIT(7)
#define LDO1_RUN_ON				BIT(6)
#define LDO1_LPSR_ON				BIT(5)
#define LDO1_SUSP_ON				BIT(4)
/* set => register control, unset => GPIO control */
#define LDO4_MODE_MASK				BIT(3)
#define LDO4_MODE_I2C				BIT(3)
#define LDO4_MODE_GPIO				0
/* set => register control, unset => start when DCIN connected */
#define LDO3_MODE_MASK				BIT(2)
#define LDO3_MODE_I2C				BIT(2)
#define LDO3_MODE_DCIN				0

/* LDO_MODE2 register */
#define LDO3_SNVS_ON				BIT(7)
#define LDO3_RUN_ON				BIT(6)
#define LDO3_LPSR_ON				BIT(5)
#define LDO3_SUSP_ON				BIT(4)
#define LDO2_SNVS_ON				BIT(3)
#define LDO2_RUN_ON				BIT(2)
#define LDO2_LPSR_ON				BIT(1)
#define LDO2_SUSP_ON				BIT(0)


/* LDO_MODE3 register */
#define LDO5_SNVS_ON				BIT(7)
#define LDO5_RUN_ON				BIT(6)
#define LDO5_LPSR_ON				BIT(5)
#define LDO5_SUSP_ON				BIT(4)
#define LDO4_SNVS_ON				BIT(3)
#define LDO4_RUN_ON				BIT(2)
#define LDO4_LPSR_ON				BIT(1)
#define LDO4_SUSP_ON				BIT(0)

/* LDO_MODE4 register */
#define DVREF_SNVS_ON				BIT(7)
#define DVREF_RUN_ON				BIT(6)
#define DVREF_LPSR_ON				BIT(5)
#define DVREF_SUSP_ON				BIT(4)
#define LDO_LPSR_SNVS_ON			BIT(3)
#define LDO_LPSR_RUN_ON				BIT(2)
#define LDO_LPSR_LPSR_ON			BIT(1)
#define LDO_LPSR_SUSP_ON			BIT(0)

/* BD71815_REG_OUT32K bits */
#define OUT32K_EN				BIT(0)
#define OUT32K_MODE				BIT(1)
#define OUT32K_MODE_CMOS			BIT(1)
#define OUT32K_MODE_OPEN_DRAIN			0

/* BD71815_REG_BAT_STAT bits */
#define BAT_DET					BIT(5)
#define BAT_DET_OFFSET				5
#define BAT_DET_DONE				BIT(4)
#define VBAT_OV					BIT(3)
#define DBAT_DET				BIT(0)

/* BD71815_REG_VBUS_STAT bits */
#define VBUS_DET				BIT(0)

#define BD71815_REG_RTC_START			BD71815_REG_SEC
#define BD71815_REG_RTC_ALM_START		BD71815_REG_ALM0_SEC

/* BD71815_REG_ALM0_MASK bits */
#define A0_ONESEC				BIT(7)

/* BD71815_REG_INT_EN_00 bits */
#define ALMALE					BIT(0)

/* BD71815_REG_INT_STAT_03 bits */
#define DCIN_MON_DET				BIT(1)
#define DCIN_MON_RES				BIT(0)
#define POWERON_LONG				BIT(2)
#define POWERON_MID				BIT(3)
#define POWERON_SHORT				BIT(4)
#define POWERON_PRESS				BIT(5)

/* BD71805_REG_INT_STAT_08 bits */
#define VBAT_MON_DET				BIT(1)
#define VBAT_MON_RES				BIT(0)

/* BD71805_REG_INT_STAT_11 bits */
#define	INT_STAT_11_VF_DET			BIT(7)
#define	INT_STAT_11_VF_RES			BIT(6)
#define	INT_STAT_11_VF125_DET			BIT(5)
#define	INT_STAT_11_VF125_RES			BIT(4)
#define	INT_STAT_11_OVTMP_DET			BIT(3)
#define	INT_STAT_11_OVTMP_RES			BIT(2)
#define	INT_STAT_11_LOTMP_DET			BIT(1)
#define	INT_STAT_11_LOTMP_RES			BIT(0)

#define VBAT_MON_DET				BIT(1)
#define VBAT_MON_RES				BIT(0)

/* BD71815_REG_PWRCTRL bits */
#define RESTARTEN				BIT(0)

/* BD71815_REG_GPO bits */
#define READY_FORCE_LOW				BIT(2)
#define BD71815_GPIO_DRIVE_MASK			BIT(4)
#define BD71815_GPIO_OPEN_DRAIN			0
#define BD71815_GPIO_CMOS			BIT(4)

/* BD71815 interrupt masks */
enum {
	BD71815_INT_EN_01_BUCKAST_MASK	=	0x0F,
	BD71815_INT_EN_02_DCINAST_MASK	=	0x3E,
	BD71815_INT_EN_03_DCINAST_MASK	=	0x3F,
	BD71815_INT_EN_04_VSYSAST_MASK	=	0xCF,
	BD71815_INT_EN_05_CHGAST_MASK	=	0xFC,
	BD71815_INT_EN_06_BATAST_MASK	=	0xF3,
	BD71815_INT_EN_07_BMONAST_MASK	=	0xFE,
	BD71815_INT_EN_08_BMONAST_MASK	=	0x03,
	BD71815_INT_EN_09_BMONAST_MASK	=	0x07,
	BD71815_INT_EN_10_BMONAST_MASK	=	0x3F,
	BD71815_INT_EN_11_TMPAST_MASK	=	0xFF,
	BD71815_INT_EN_12_ALMAST_MASK	=	0x07,
};
/* BD71815 interrupt irqs */
enum {
	/* BUCK reg interrupts */
	BD71815_INT_BUCK1_OCP,
	BD71815_INT_BUCK2_OCP,
	BD71815_INT_BUCK3_OCP,
	BD71815_INT_BUCK4_OCP,
	BD71815_INT_BUCK5_OCP,
	BD71815_INT_LED_OVP,
	BD71815_INT_LED_OCP,
	BD71815_INT_LED_SCP,
	/* DCIN1 interrupts */
	BD71815_INT_DCIN_RMV,
	BD71815_INT_CLPS_OUT,
	BD71815_INT_CLPS_IN,
	BD71815_INT_DCIN_OVP_RES,
	BD71815_INT_DCIN_OVP_DET,
	/* DCIN2 interrupts */
	BD71815_INT_DCIN_MON_RES,
	BD71815_INT_DCIN_MON_DET,
	BD71815_INT_WDOG,
	/* Vsys INT_STAT_04 */
	BD71815_INT_VSYS_UV_RES,
	BD71815_INT_VSYS_UV_DET,
	BD71815_INT_VSYS_LOW_RES,
	BD71815_INT_VSYS_LOW_DET,
	BD71815_INT_VSYS_MON_RES,
	BD71815_INT_VSYS_MON_DET,
	/* Charger INT_STAT_05 */
	BD71815_INT_CHG_WDG_TEMP,
	BD71815_INT_CHG_WDG_TIME,
	BD71815_INT_CHG_RECHARGE_RES,
	BD71815_INT_CHG_RECHARGE_DET,
	BD71815_INT_CHG_RANGED_TEMP_TRANSITION,
	BD71815_INT_CHG_STATE_TRANSITION,
	/* Battery  INT_STAT_06 */
	BD71815_INT_BAT_TEMP_NORMAL,
	BD71815_INT_BAT_TEMP_ERANGE,
	BD71815_INT_BAT_REMOVED,
	BD71815_INT_BAT_DETECTED,
	BD71815_INT_THERM_REMOVED,
	BD71815_INT_THERM_DETECTED,
	/* Battery Mon 1 INT_STAT_07 */
	BD71815_INT_BAT_DEAD,
	BD71815_INT_BAT_SHORTC_RES,
	BD71815_INT_BAT_SHORTC_DET,
	BD71815_INT_BAT_LOW_VOLT_RES,
	BD71815_INT_BAT_LOW_VOLT_DET,
	BD71815_INT_BAT_OVER_VOLT_RES,
	BD71815_INT_BAT_OVER_VOLT_DET,
	/* Battery Mon 2 INT_STAT_08 */
	BD71815_INT_BAT_MON_RES,
	BD71815_INT_BAT_MON_DET,
	/* Battery Mon 3 (Coulomb counter) INT_STAT_09 */
	BD71815_INT_BAT_CC_MON1,
	BD71815_INT_BAT_CC_MON2,
	BD71815_INT_BAT_CC_MON3,
	/* Battery Mon 4 INT_STAT_10 */
	BD71815_INT_BAT_OVER_CURR_1_RES,
	BD71815_INT_BAT_OVER_CURR_1_DET,
	BD71815_INT_BAT_OVER_CURR_2_RES,
	BD71815_INT_BAT_OVER_CURR_2_DET,
	BD71815_INT_BAT_OVER_CURR_3_RES,
	BD71815_INT_BAT_OVER_CURR_3_DET,
	/* Temperature INT_STAT_11 */
	BD71815_INT_TEMP_BAT_LOW_RES,
	BD71815_INT_TEMP_BAT_LOW_DET,
	BD71815_INT_TEMP_BAT_HI_RES,
	BD71815_INT_TEMP_BAT_HI_DET,
	BD71815_INT_TEMP_CHIP_OVER_125_RES,
	BD71815_INT_TEMP_CHIP_OVER_125_DET,
	BD71815_INT_TEMP_CHIP_OVER_VF_RES,
	BD71815_INT_TEMP_CHIP_OVER_VF_DET,
	/* RTC Alarm INT_STAT_12 */
	BD71815_INT_RTC0,
	BD71815_INT_RTC1,
	BD71815_INT_RTC2,
};

#define BD71815_INT_BUCK1_OCP_MASK			BIT(0)
#define BD71815_INT_BUCK2_OCP_MASK			BIT(1)
#define BD71815_INT_BUCK3_OCP_MASK			BIT(2)
#define BD71815_INT_BUCK4_OCP_MASK			BIT(3)
#define BD71815_INT_BUCK5_OCP_MASK			BIT(4)
#define BD71815_INT_LED_OVP_MASK			BIT(5)
#define BD71815_INT_LED_OCP_MASK			BIT(6)
#define BD71815_INT_LED_SCP_MASK			BIT(7)

#define BD71815_INT_DCIN_RMV_MASK			BIT(1)
#define BD71815_INT_CLPS_OUT_MASK			BIT(2)
#define BD71815_INT_CLPS_IN_MASK			BIT(3)
#define BD71815_INT_DCIN_OVP_RES_MASK			BIT(4)
#define BD71815_INT_DCIN_OVP_DET_MASK			BIT(5)

#define BD71815_INT_DCIN_MON_RES_MASK			BIT(0)
#define BD71815_INT_DCIN_MON_DET_MASK			BIT(1)
#define BD71815_INT_WDOG_MASK				BIT(6)

#define BD71815_INT_VSYS_UV_RES_MASK			BIT(0)
#define BD71815_INT_VSYS_UV_DET_MASK			BIT(1)
#define BD71815_INT_VSYS_LOW_RES_MASK			BIT(2)
#define BD71815_INT_VSYS_LOW_DET_MASK			BIT(3)
#define BD71815_INT_VSYS_MON_RES_MASK			BIT(6)
#define BD71815_INT_VSYS_MON_DET_MASK			BIT(7)

#define BD71815_INT_CHG_WDG_TEMP_MASK			BIT(2)
#define BD71815_INT_CHG_WDG_TIME_MASK			BIT(3)
#define BD71815_INT_CHG_RECHARGE_RES_MASK		BIT(4)
#define BD71815_INT_CHG_RECHARGE_DET_MASK		BIT(5)
#define BD71815_INT_CHG_RANGED_TEMP_TRANSITION_MASK	BIT(6)
#define BD71815_INT_CHG_STATE_TRANSITION_MASK		BIT(7)

#define BD71815_INT_BAT_TEMP_NORMAL_MASK		BIT(0)
#define BD71815_INT_BAT_TEMP_ERANGE_MASK		BIT(1)
#define BD71815_INT_BAT_REMOVED_MASK			BIT(4)
#define BD71815_INT_BAT_DETECTED_MASK			BIT(5)
#define BD71815_INT_THERM_REMOVED_MASK			BIT(6)
#define BD71815_INT_THERM_DETECTED_MASK			BIT(7)

#define BD71815_INT_BAT_DEAD_MASK			BIT(1)
#define BD71815_INT_BAT_SHORTC_RES_MASK			BIT(2)
#define BD71815_INT_BAT_SHORTC_DET_MASK			BIT(3)
#define BD71815_INT_BAT_LOW_VOLT_RES_MASK		BIT(4)
#define BD71815_INT_BAT_LOW_VOLT_DET_MASK		BIT(5)
#define BD71815_INT_BAT_OVER_VOLT_RES_MASK		BIT(6)
#define BD71815_INT_BAT_OVER_VOLT_DET_MASK		BIT(7)

#define BD71815_INT_BAT_MON_RES_MASK			BIT(0)
#define BD71815_INT_BAT_MON_DET_MASK			BIT(1)

#define BD71815_INT_BAT_CC_MON1_MASK			BIT(0)
#define BD71815_INT_BAT_CC_MON2_MASK			BIT(1)
#define BD71815_INT_BAT_CC_MON3_MASK			BIT(2)

#define BD71815_INT_BAT_OVER_CURR_1_RES_MASK		BIT(0)
#define BD71815_INT_BAT_OVER_CURR_1_DET_MASK		BIT(1)
#define BD71815_INT_BAT_OVER_CURR_2_RES_MASK		BIT(2)
#define BD71815_INT_BAT_OVER_CURR_2_DET_MASK		BIT(3)
#define BD71815_INT_BAT_OVER_CURR_3_RES_MASK		BIT(4)
#define BD71815_INT_BAT_OVER_CURR_3_DET_MASK		BIT(5)

#define BD71815_INT_TEMP_BAT_LOW_RES_MASK		BIT(0)
#define BD71815_INT_TEMP_BAT_LOW_DET_MASK		BIT(1)
#define BD71815_INT_TEMP_BAT_HI_RES_MASK		BIT(2)
#define BD71815_INT_TEMP_BAT_HI_DET_MASK		BIT(3)
#define BD71815_INT_TEMP_CHIP_OVER_125_RES_MASK		BIT(4)
#define BD71815_INT_TEMP_CHIP_OVER_125_DET_MASK		BIT(5)
#define BD71815_INT_TEMP_CHIP_OVER_VF_RES_MASK		BIT(6)
#define BD71815_INT_TEMP_CHIP_OVER_VF_DET_MASK		BIT(7)

#define BD71815_INT_RTC0_MASK				BIT(0)
#define BD71815_INT_RTC1_MASK				BIT(1)
#define BD71815_INT_RTC2_MASK				BIT(2)

/* BD71815_REG_CC_CTRL bits */
#define CCNTRST						0x80
#define CCNTENB						0x40
#define CCCALIB						0x20

/* BD71815_REG_CC_CURCD */
#define CURDIR_Discharging				0x8000

/* BD71815_REG_VM_SA_IBAT */
#define IBAT_SA_DIR_Discharging				0x8000

/* BD71815_REG_REX_CTRL_1 bits */
#define REX_CLR						BIT(4)

/* BD71815_REG_REX_CTRL_1 bits */
#define REX_PMU_STATE_MASK				BIT(2)

/* BD71815_REG_LED_CTRL bits */
#define CHGDONE_LED_EN					BIT(4)

#endif /* __LINUX_MFD_BD71815_H */
