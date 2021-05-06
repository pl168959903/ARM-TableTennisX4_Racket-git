/****************************************************************************
 * @file     clockConfig.c
 * @version  V1.05
 * @Date     2021/04/28-18:08:51 
 * @brief    NuMicro generated code file
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (C) 2013-2021 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

/********************
MCU:M032SE3AE(ULQFP64)
Base Clocks:
LIRC:38.4000kHz
HIRC:48MHz
LXT:32.7680kHz
PLL:144MHz
HCLK:72MHz
PCLK0:72MHz
PCLK1:72MHz
Enabled-Module Frequencies:
ADC=Bus Clock(PCLK1):72MHz/Engine Clock:48MHz
CRC=Bus Clock(HCLK):72MHz
HDIV=Bus Clock(HCLK):72MHz
I2C0=Bus Clock(PCLK0):72MHz
ISP=Bus Clock(HCLK):72MHz/Engine Clock:48MHz
PDMA=Bus Clock(HCLK):72MHz
SPI0=Bus Clock(PCLK1):72MHz/Engine Clock:72MHz
SYSTICK=Bus Clock(HCLK):72MHz/Engine Clock:72MHz
TMR0=Bus Clock(PCLK0):72MHz/Engine Clock:48MHz
UART0=Bus Clock(PCLK0):72MHz/Engine Clock:72MHz
USBD=Bus Clock(PCLK0):72MHz/Engine Clock:48MHz
WDT=Bus Clock(PCLK0):72MHz/Engine Clock:38.4000kHz
WWDT=Bus Clock(PCLK0):72MHz/Engine Clock:35.1563kHz
********************/

#include "M031Series.h"

void clockConfig_init_adc(void)
{
    CLK_EnableModuleClock(ADC_MODULE);
    CLK_SetModuleClock(ADC_MODULE, CLK_CLKSEL2_ADCSEL_PLL, CLK_CLKDIV0_ADC(3));

    return;
}

void clockConfig_deinit_adc(void)
{
    CLK_DisableModuleClock(ADC_MODULE);

    return;
}

void clockConfig_init_crc(void)
{
    CLK_EnableModuleClock(CRC_MODULE);

    return;
}

void clockConfig_deinit_crc(void)
{
    CLK_DisableModuleClock(CRC_MODULE);

    return;
}

void clockConfig_init_hdiv(void)
{
    CLK_EnableModuleClock(HDIV_MODULE);

    return;
}

void clockConfig_deinit_hdiv(void)
{
    CLK_DisableModuleClock(HDIV_MODULE);

    return;
}

void clockConfig_init_i2c0(void)
{
    CLK_EnableModuleClock(I2C0_MODULE);

    return;
}

void clockConfig_deinit_i2c0(void)
{
    CLK_DisableModuleClock(I2C0_MODULE);

    return;
}

void clockConfig_init_isp(void)
{
    CLK_EnableModuleClock(ISP_MODULE);

    return;
}

void clockConfig_deinit_isp(void)
{
    CLK_DisableModuleClock(ISP_MODULE);

    return;
}

void clockConfig_init_pdma(void)
{
    CLK_EnableModuleClock(PDMA_MODULE);

    return;
}

void clockConfig_deinit_pdma(void)
{
    CLK_DisableModuleClock(PDMA_MODULE);

    return;
}

void clockConfig_init_spi0(void)
{
    CLK_EnableModuleClock(SPI0_MODULE);
    CLK_SetModuleClock(SPI0_MODULE, CLK_CLKSEL2_SPI0SEL_PCLK1, MODULE_NoMsk);

    return;
}

void clockConfig_deinit_spi0(void)
{
    CLK_DisableModuleClock(SPI0_MODULE);

    return;
}

void clockConfig_init_systick(void)
{
    CLK_EnableSysTick(CLK_CLKSEL0_STCLKSEL_HCLK, 0);

    return;
}

void clockConfig_deinit_systick(void)
{
    CLK_DisableSysTick();

    return;
}

void clockConfig_init_tmr0(void)
{
    CLK_EnableModuleClock(TMR0_MODULE);
    CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0SEL_HIRC, MODULE_NoMsk);

    return;
}

void clockConfig_deinit_tmr0(void)
{
    CLK_DisableModuleClock(TMR0_MODULE);

    return;
}

void clockConfig_init_uart0(void)
{
    CLK_EnableModuleClock(UART0_MODULE);
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART0SEL_PCLK0, CLK_CLKDIV0_UART0(1));

    return;
}

void clockConfig_deinit_uart0(void)
{
    CLK_DisableModuleClock(UART0_MODULE);

    return;
}

void clockConfig_init_usbd(void)
{
    CLK_EnableModuleClock(USBD_MODULE);
    CLK_SetModuleClock(USBD_MODULE, CLK_CLKSEL0_USBDSEL_PLL, CLK_CLKDIV0_USB(3));

    return;
}

void clockConfig_deinit_usbd(void)
{
    CLK_DisableModuleClock(USBD_MODULE);

    return;
}

void clockConfig_init_wdt(void)
{
    CLK_EnableModuleClock(WDT_MODULE);
    CLK_SetModuleClock(WDT_MODULE, CLK_CLKSEL1_WDTSEL_LIRC, MODULE_NoMsk);

    return;
}

void clockConfig_deinit_wdt(void)
{
    CLK_DisableModuleClock(WDT_MODULE);

    return;
}

void clockConfig_init_wwdt(void)
{
    CLK_EnableModuleClock(WWDT_MODULE);
    CLK_SetModuleClock(WWDT_MODULE, CLK_CLKSEL1_WWDTSEL_HCLK_DIV2048, MODULE_NoMsk);

    return;
}

void clockConfig_deinit_wwdt(void)
{
    CLK_DisableModuleClock(WWDT_MODULE);

    return;
}

void clockConfig_init_base(void)
{
    /* Enable clock source */
    CLK_EnableXtalRC(CLK_PWRCTL_LIRCEN_Msk|CLK_PWRCTL_HIRCEN_Msk|CLK_PWRCTL_LXTEN_Msk);

    /* Waiting for clock source ready */
    CLK_WaitClockReady(CLK_STATUS_LIRCSTB_Msk|CLK_STATUS_HIRCSTB_Msk|CLK_STATUS_LXTSTB_Msk);

    /* Disable PLL first to avoid unstable when setting PLL */
    CLK_DisablePLL();

    /* Set PLL frequency */
    CLK->PLLCTL = (CLK->PLLCTL & ~(0x000FFFFFUL)) | 0x0008402EUL;

    /* Waiting for PLL ready */
    CLK_WaitClockReady(CLK_STATUS_PLLSTB_Msk);

    /* If the defines do not exist in your project, please refer to the related clk.h in the Header folder appended to the tool package. */
    /* Set HCLK clock */
    CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_PLL, CLK_CLKDIV0_HCLK(2));

    /* Set PCLK-related clock */
    CLK->PCLKDIV = (CLK_PCLKDIV_APB0DIV_DIV1 | CLK_PCLKDIV_APB1DIV_DIV1);

    return;
}

void clockConfig_init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/
    //CLK->PWRCTL = (CLK->PWRCTL & ~(0x0000000FUL)) | 0x0231001EUL;
    //CLK->PLLCTL = (CLK->PLLCTL & ~(0x000FFFFFUL)) | 0x0008402EUL;
    //CLK->CLKDIV0 = (CLK->CLKDIV0 & ~(0x00FFFFFFUL)) | 0x00020021UL;
    //CLK->CLKDIV4 = (CLK->CLKDIV4 & ~(0x0000000FUL)) | 0x00000000UL;
    //CLK->PCLKDIV = (CLK->PCLKDIV & ~(0x00000077UL)) | 0x00000000UL;
    //CLK->CLKSEL0 = (CLK->CLKSEL0 & ~(0x0000013FUL)) | 0x0000013AUL;
    //CLK->CLKSEL1 = (CLK->CLKSEL1 & ~(0x7777777FUL)) | 0x4477773BUL;
    //CLK->CLKSEL2 = (CLK->CLKSEL2 & ~(0x00300033UL)) | 0x00100023UL;
    //CLK->CLKSEL3 = (CLK->CLKSEL3 & ~(0x07000000UL)) | 0x04000000UL;
    //CLK->AHBCLK = (CLK->AHBCLK & ~(0x0000009EUL)) | 0x00000096UL;
    //CLK->APBCLK0 = (CLK->APBCLK0 & ~(0x180723FDUL)) | 0x18012105UL;
    //CLK->APBCLK1 = (CLK->APBCLK1 & ~(0x00030100UL)) | 0x00000000UL;
    //CLK->CLKOCTL = (CLK->CLKOCTL & ~(0x0000003FUL)) | 0x00000000UL;
    //SysTick->CTRL = (SysTick->CTRL & ~(0x00000005UL)) | 0x00000005UL;

    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Enable base clock */
    clockConfig_init_base();

    /* Enable module clock and set clock source */
    clockConfig_init_adc();
    clockConfig_init_crc();
    clockConfig_init_hdiv();
    clockConfig_init_i2c0();
    clockConfig_init_isp();
    clockConfig_init_pdma();
    clockConfig_init_spi0();
    clockConfig_init_systick();
    clockConfig_init_tmr0();
    clockConfig_init_uart0();
    clockConfig_init_usbd();
    clockConfig_init_wdt();
    clockConfig_init_wwdt();

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock. */
    SystemCoreClockUpdate();

    /* Lock protected registers */
    SYS_LockReg();

    return;
}

/*** (C) COPYRIGHT 2013-2021 Nuvoton Technology Corp. ***/
