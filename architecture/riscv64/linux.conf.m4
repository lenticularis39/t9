dnl --- T2-COPYRIGHT-NOTE-BEGIN ---
dnl T2 SDE: architecture/riscv64/linux.conf.m4
dnl Copyright (C) 2004 - 2021 The T2 SDE Project
dnl 
dnl This Copyright note is generated by scripts/Create-CopyPatch,
dnl more information can be found in the files COPYING and README.
dnl 
dnl This program is free software; you can redistribute it and/or modify
dnl it under the terms of the GNU General Public License version 2.
dnl --- T2-COPYRIGHT-NOTE-END ---

define(`RISCV64', 'RISCV64')dnl

CONFIG_SOC_SIFIVE=y
CONFIG_SOC_VIRT=y

CONFIG_SPI_SIFIVE=y
CONFIG_CLK_SIFIVE=y
CONFIG_CLK_SIFIVE_PRCI=y
CONFIG_SIFIVE_PLIC=y
CONFIG_GPIO_SIFIVE=y
CONFIG_PWM_SIFIVE=y
CONFIG_EDAC_SIFIVE=y

CONFIG_SIFIVE_L2=y
CONFIG_RISCV_ERRATA_ALTERNATIVE=y
CONFIG_ERRATA_SIFIVE=y
CONFIG_ERRATA_SIFIVE_CIP_453=y
CONFIG_ERRATA_SIFIVE_CIP_1200=y

CONFIG_LEDS_TRIGGER_DISK=y
CONFIG_LEDS_TRIGGER_MTD=y
CONFIG_LEDS_TRIGGER_CPU=y

CONFIG_POWER_RESET=y
CONFIG_POWER_RESET_RESTART=y
CONFIG_POWER_RESET_GPIO=y
CONFIG_POWER_RESET_GPIO_RESTART=y
CONFIG_RESET_CONTROLLER=y
CONFIG_RESET_SIMPLE=y

CONFIG_PCIE_FU740=y
CONFIG_MMC=y
CONFIG_MMC_SPI=y

include(`linux-common.conf.m4')
include(`linux-block.conf.m4')
include(`linux-net.conf.m4')
include(`linux-fs.conf.m4')

# CONFIG_NO_HZ_FULL is not set
CONFIG_NO_HZ_IDLE=y
CONFIG_PREEMPT_NONE=y
