/****************************************************************************
 * @file     pinConfig.c
 * @version  V1.21
 * @Date     2021/04/28-16:47:56 
 * @brief    NuMicro generated code file
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (C) 2013-2021 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

/********************
MCU:M032SG8AE(LQFP64)
Pin Configuration:
Pin3:ADC0_CH4
Pin4:ADC0_CH3
Pin5:ADC0_CH2
Pin6:ADC0_CH1
Pin7:ADC0_CH0
Pin10:PA.9
Pin11:PA.8
Pin14:X32_IN
Pin15:X32_OUT
Pin20:INT1
Pin21:INT0
Pin25:I2C0_SCL
Pin26:I2C0_SDA
Pin29:UART0_TXD
Pin33:ICE_DAT
Pin34:ICE_CLK
Pin41:SPI0_SS
Pin42:SPI0_CLK
Pin43:SPI0_MISO
Pin44:SPI0_MOSI
Pin62:PB.9
Pin63:PB.8
Pin64:PB.7
Module Configuration:
ADC0_CH0(Pin:7)
ADC0_CH1(Pin:6)
ADC0_CH2(Pin:5)
ADC0_CH3(Pin:4)
ADC0_CH4(Pin:3)
PA.8(Pin:11)
PA.9(Pin:10)
X32_IN(Pin:14)
X32_OUT(Pin:15)
INT0(Pin:21)
INT1(Pin:20)
I2C0_SCL(Pin:25)
I2C0_SDA(Pin:26)
UART0_TXD(Pin:29)
ICE_CLK(Pin:34)
ICE_DAT(Pin:33)
SPI0_CLK(Pin:42)
SPI0_MISO(Pin:43)
SPI0_MOSI(Pin:44)
SPI0_SS(Pin:41)
PB.7(Pin:64)
PB.8(Pin:63)
PB.9(Pin:62)
GPIO Configuration:
PA.1:UART0_TXD(Pin:29)
PA.4:I2C0_SDA(Pin:26)
PA.5:I2C0_SCL(Pin:25)
PA.6:INT0(Pin:21)
PA.7:INT1(Pin:20)
PA.8:PA.8(Pin:11)
PA.9:PA.9(Pin:10)
PB.0:ADC0_CH0(Pin:7)
PB.1:ADC0_CH1(Pin:6)
PB.2:ADC0_CH2(Pin:5)
PB.3:ADC0_CH3(Pin:4)
PB.4:ADC0_CH4(Pin:3)
PB.7:PB.7(Pin:64)
PB.8:PB.8(Pin:63)
PB.9:PB.9(Pin:62)
PD.0:SPI0_MOSI(Pin:44)
PD.1:SPI0_MISO(Pin:43)
PD.2:SPI0_CLK(Pin:42)
PD.3:SPI0_SS(Pin:41)
PF.0:ICE_DAT(Pin:33)
PF.1:ICE_CLK(Pin:34)
PF.4:X32_OUT(Pin:15)
PF.5:X32_IN(Pin:14)
********************/

#include "M031Series.h"

void pinConfig_init_adc0(void)
{
    SYS->GPB_MFPL &= ~(SYS_GPB_MFPL_PB4MFP_Msk | SYS_GPB_MFPL_PB3MFP_Msk | SYS_GPB_MFPL_PB2MFP_Msk | SYS_GPB_MFPL_PB1MFP_Msk | SYS_GPB_MFPL_PB0MFP_Msk);
    SYS->GPB_MFPL |= (SYS_GPB_MFPL_PB4MFP_ADC0_CH4 | SYS_GPB_MFPL_PB3MFP_ADC0_CH3 | SYS_GPB_MFPL_PB2MFP_ADC0_CH2 | SYS_GPB_MFPL_PB1MFP_ADC0_CH1 | SYS_GPB_MFPL_PB0MFP_ADC0_CH0);

    return;
}

void pinConfig_deinit_adc0(void)
{
    SYS->GPB_MFPL &= ~(SYS_GPB_MFPL_PB4MFP_Msk | SYS_GPB_MFPL_PB3MFP_Msk | SYS_GPB_MFPL_PB2MFP_Msk | SYS_GPB_MFPL_PB1MFP_Msk | SYS_GPB_MFPL_PB0MFP_Msk);

    return;
}

void pinConfig_init_i2c0(void)
{
    SYS->GPA_MFPL &= ~(SYS_GPA_MFPL_PA5MFP_Msk | SYS_GPA_MFPL_PA4MFP_Msk);
    SYS->GPA_MFPL |= (SYS_GPA_MFPL_PA5MFP_I2C0_SCL | SYS_GPA_MFPL_PA4MFP_I2C0_SDA);

    return;
}

void pinConfig_deinit_i2c0(void)
{
    SYS->GPA_MFPL &= ~(SYS_GPA_MFPL_PA5MFP_Msk | SYS_GPA_MFPL_PA4MFP_Msk);

    return;
}

void pinConfig_init_ice(void)
{
    SYS->GPF_MFPL &= ~(SYS_GPF_MFPL_PF1MFP_Msk | SYS_GPF_MFPL_PF0MFP_Msk);
    SYS->GPF_MFPL |= (SYS_GPF_MFPL_PF1MFP_ICE_CLK | SYS_GPF_MFPL_PF0MFP_ICE_DAT);

    return;
}

void pinConfig_deinit_ice(void)
{
    SYS->GPF_MFPL &= ~(SYS_GPF_MFPL_PF1MFP_Msk | SYS_GPF_MFPL_PF0MFP_Msk);

    return;
}

void pinConfig_init_int(void)
{
    SYS->GPA_MFPL &= ~(SYS_GPA_MFPL_PA7MFP_Msk | SYS_GPA_MFPL_PA6MFP_Msk);
    SYS->GPA_MFPL |= (SYS_GPA_MFPL_PA7MFP_INT1 | SYS_GPA_MFPL_PA6MFP_INT0);

    return;
}

void pinConfig_deinit_int(void)
{
    SYS->GPA_MFPL &= ~(SYS_GPA_MFPL_PA7MFP_Msk | SYS_GPA_MFPL_PA6MFP_Msk);

    return;
}

void pinConfig_init_pa(void)
{
    SYS->GPA_MFPH &= ~(SYS_GPA_MFPH_PA9MFP_Msk | SYS_GPA_MFPH_PA8MFP_Msk);
    SYS->GPA_MFPH |= (SYS_GPA_MFPH_PA9MFP_GPIO | SYS_GPA_MFPH_PA8MFP_GPIO);

    return;
}

void pinConfig_deinit_pa(void)
{
    SYS->GPA_MFPH &= ~(SYS_GPA_MFPH_PA9MFP_Msk | SYS_GPA_MFPH_PA8MFP_Msk);

    return;
}

void pinConfig_init_pb(void)
{
    SYS->GPB_MFPH &= ~(SYS_GPB_MFPH_PB9MFP_Msk | SYS_GPB_MFPH_PB8MFP_Msk);
    SYS->GPB_MFPH |= (SYS_GPB_MFPH_PB9MFP_GPIO | SYS_GPB_MFPH_PB8MFP_GPIO);
    SYS->GPB_MFPL &= ~(SYS_GPB_MFPL_PB7MFP_Msk);
    SYS->GPB_MFPL |= (SYS_GPB_MFPL_PB7MFP_GPIO);

    return;
}

void pinConfig_deinit_pb(void)
{
    SYS->GPB_MFPH &= ~(SYS_GPB_MFPH_PB9MFP_Msk | SYS_GPB_MFPH_PB8MFP_Msk);
    SYS->GPB_MFPL &= ~(SYS_GPB_MFPL_PB7MFP_Msk);

    return;
}

void pinConfig_init_spi0(void)
{
    SYS->GPD_MFPL &= ~(SYS_GPD_MFPL_PD3MFP_Msk | SYS_GPD_MFPL_PD2MFP_Msk | SYS_GPD_MFPL_PD1MFP_Msk | SYS_GPD_MFPL_PD0MFP_Msk);
    SYS->GPD_MFPL |= (SYS_GPD_MFPL_PD3MFP_SPI0_SS | SYS_GPD_MFPL_PD2MFP_SPI0_CLK | SYS_GPD_MFPL_PD1MFP_SPI0_MISO | SYS_GPD_MFPL_PD0MFP_SPI0_MOSI);

    return;
}

void pinConfig_deinit_spi0(void)
{
    SYS->GPD_MFPL &= ~(SYS_GPD_MFPL_PD3MFP_Msk | SYS_GPD_MFPL_PD2MFP_Msk | SYS_GPD_MFPL_PD1MFP_Msk | SYS_GPD_MFPL_PD0MFP_Msk);

    return;
}

void pinConfig_init_uart0(void)
{
    SYS->GPA_MFPL &= ~(SYS_GPA_MFPL_PA1MFP_Msk);
    SYS->GPA_MFPL |= (SYS_GPA_MFPL_PA1MFP_UART0_TXD);

    return;
}

void pinConfig_deinit_uart0(void)
{
    SYS->GPA_MFPL &= ~(SYS_GPA_MFPL_PA1MFP_Msk);

    return;
}

void pinConfig_init_x32(void)
{
    SYS->GPF_MFPL &= ~(SYS_GPF_MFPL_PF5MFP_Msk | SYS_GPF_MFPL_PF4MFP_Msk);
    SYS->GPF_MFPL |= (SYS_GPF_MFPL_PF5MFP_X32_IN | SYS_GPF_MFPL_PF4MFP_X32_OUT);

    return;
}

void pinConfig_deinit_x32(void)
{
    SYS->GPF_MFPL &= ~(SYS_GPF_MFPL_PF5MFP_Msk | SYS_GPF_MFPL_PF4MFP_Msk);

    return;
}

void pinConfig_init(void)
{
    //SYS->GPA_MFPH = 0x00000000UL;
    //SYS->GPA_MFPL = 0xFF990070UL;
    //SYS->GPB_MFPH = 0x00000000UL;
    //SYS->GPB_MFPL = 0x00011111UL;
    //SYS->GPC_MFPH = 0x00000000UL;
    //SYS->GPC_MFPL = 0x00000000UL;
    //SYS->GPD_MFPH = 0x00000000UL;
    //SYS->GPD_MFPL = 0x00004444UL;
    //SYS->GPF_MFPH = 0x00000000UL;
    //SYS->GPF_MFPL = 0x00AA00EEUL;

    pinConfig_init_adc0();
    pinConfig_init_i2c0();
    pinConfig_init_ice();
    pinConfig_init_int();
    pinConfig_init_pa();
    pinConfig_init_pb();
    pinConfig_init_spi0();
    pinConfig_init_uart0();
    pinConfig_init_x32();

    return;
}

void pinConfig_deinit(void)
{
    pinConfig_deinit_adc0();
    pinConfig_deinit_i2c0();
    pinConfig_deinit_ice();
    pinConfig_deinit_int();
    pinConfig_deinit_pa();
    pinConfig_deinit_pb();
    pinConfig_deinit_spi0();
    pinConfig_deinit_uart0();
    pinConfig_deinit_x32();

    return;
}
/*** (C) COPYRIGHT 2013-2021 Nuvoton Technology Corp. ***/
