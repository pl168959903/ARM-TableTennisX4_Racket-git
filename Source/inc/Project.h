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

typedef struct dma_desc_t {
    uint32_t ctl;
    uint32_t src;
    uint32_t dest;
    uint32_t offset;
} DMA_DESC_T;

void DisableDigtalPin( void );

void PinFunctionInit( void );
void SystemClockInit( void );
void ModuleClockInit( void );
void HircTrim( void );

#endif /* __PROJECT_H */
