#ifndef __PROJECT_H
#define __PROJECT_H

#include "NuMicro.h"
#include "clockConfig.h"
#include "pinConfig.h"
#include <stdbool.h>
#include <stdio.h>

#define _MASK( bit ) ( 0x1ul << bit )

#define _NRF_SPI         SPI0
#define _ICM20948_I2C    I2C0
#define _SPI0_TX_PDMA_CH 0
#define _SPI0_RX_PDMA_CH 1

#define _NRF_CE_PIN PD0
#define _LED_R_PIN PB7
#define _LED_G_PIN PB9
#define _LED_B_PIN PB8


void DisableDigtalPin( void );
void PinFunctionInit( void );
void SystemClockInit( void );
void ModuleClockInit( void );
void HircTrim( void );

#endif /* __PROJECT_H */
