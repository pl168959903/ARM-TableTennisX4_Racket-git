#include "Project.h"
#include "vMemXor.h"

DMA_DESC_T DMA_DESC[ 2 ];

void DisableDigtalPin( void ) {
    PA->DINOFF = PB->DINOFF = PC->DINOFF = PD->DINOFF = PE->DINOFF = PF->DINOFF = 0ul;
    PA->DINOFF |= ~( BIT1 | BIT4 | BIT5 | BIT6 | BIT7 | BIT9 ) << 16;
    PB->DINOFF |= ~( 0ul ) << 16;
    PC->DINOFF |= ~( 0ul ) << 16;
    PD->DINOFF |= ~( BIT0 | BIT1 | BIT2 | BIT3 ) << 16;
    PE->DINOFF |= ~( 0ul ) << 16;
    PF->DINOFF |= ~( BIT0 | BIT1 | BIT4 | BIT5 ) << 16;
    return;
}
void HircTrim( void ) {
    SYS->HIRCTRIMIEN = 0x2ul;
    SYS->HIRCTRIMCTL = 0xF1ul;
    while ( !( SYS->HIRCTRIMCTL & SYS_HIRCTRIMSTS_FREQLOCK_Msk ) ) {};
    return;
}
void EnablePullUpPin( void ) {
    GPIO_SetMode( PA, BIT4 | BIT5, GPIO_MODE_QUASI );
    return;
}
void I2cInit( void ) {
    I2C_Open( _ICM20948_I2C, 400000 );
}
void SpiInit( void ) {
    SPI_Open( _NRF_SPI, SPI_MASTER, SPI_MODE_0, 8, 1000000 );
    SPI_EnableAutoSS( _NRF_SPI, SPI_SS, SPI_SS_ACTIVE_LOW );
}
void PdmaInit( void ) {
    PDMA_Open( PDMA, _MASK( _SPI0_TX_PDMA_CH ) | _MASK( _SPI0_RX_PDMA_CH ) );

    PDMA_SetTransferMode( PDMA, _SPI0_TX_PDMA_CH, PDMA_SPI0_TX, FALSE, 0 );
    PDMA_SetTransferMode( PDMA, _SPI0_RX_PDMA_CH, PDMA_SPI0_RX, FALSE, 0 );
}

void SpiReadAndWriteByPdma( SPI_T* spi, uint8_t tdata[], uint8_t rdata[], uint32_t dataSize ) {
    uint32_t en_ch = ( _MASK( _SPI0_TX_PDMA_CH ) | _MASK( _SPI0_RX_PDMA_CH ) );

    PDMA->DSCT[ _SPI0_TX_PDMA_CH ].CTL = ( ( dataSize - 1 ) << PDMA_DSCT_CTL_TXCNT_Pos ) | PDMA_WIDTH_8 | PDMA_SAR_INC | PDMA_DAR_FIX | PDMA_REQ_SINGLE | PDMA_TBINTDIS_DISABLE | PDMA_OP_BASIC;
    PDMA->DSCT[ _SPI0_TX_PDMA_CH ].SA  = ( uint32_t )tdata;
    PDMA->DSCT[ _SPI0_TX_PDMA_CH ].DA  = ( uint32_t )&spi->TX;

    PDMA->DSCT[ _SPI0_RX_PDMA_CH ].CTL = ( ( dataSize - 1 ) << PDMA_DSCT_CTL_TXCNT_Pos ) | PDMA_WIDTH_8 | PDMA_SAR_FIX | PDMA_DAR_INC | PDMA_REQ_SINGLE | PDMA_TBINTDIS_DISABLE | PDMA_OP_BASIC;
    PDMA->DSCT[ _SPI0_RX_PDMA_CH ].SA  = ( uint32_t )&spi->RX;
    PDMA->DSCT[ _SPI0_RX_PDMA_CH ].DA  = ( uint32_t )rdata;

    SPI_TRIGGER_TX_PDMA( SPI0 );
    spi->PDMACTL |= ( SPI_PDMACTL_RXPDMAEN_Msk | SPI_PDMACTL_TXPDMAEN_Msk );

    while ( 1 ) {
        if ( PDMA_GET_INT_STATUS( PDMA ) & PDMA_INTSTS_TDIF_Msk ) {
            if ( ( PDMA_GET_TD_STS( PDMA ) & en_ch ) == en_ch ) {
                PDMA_CLR_TD_FLAG( PDMA, en_ch );
                spi->PDMACTL |= SPI_PDMACTL_PDMARST_Msk;
                break;
            }
        }
    }
}

int main( void ) {
    uint8_t data[ 5 ]   = { 0x01, 0x02, 0x03, 0x04, 0x05 };
    uint8_t redata[ 5 ] = { 0 };

    pinConfig_init();
    DisableDigtalPin();
    EnablePullUpPin();

    HircTrim();
    clockConfig_init();
    UART_Open( UART0, 921600 );
    printf( "CPU: %d Hz\n", CLK_GetCPUFreq() );
    printf( "HCLK: %d Hz\n", CLK_GetHCLKFreq() );
    printf( "HXT: %d Hz\n", CLK_GetHXTFreq() );
    printf( "LXT: %d Hz\n", CLK_GetLXTFreq() );
    printf( "PCLK0: %d Hz\n", CLK_GetPCLK0Freq() );
    printf( "PCLK1: %d Hz\n", CLK_GetPCLK1Freq() );
    printf( "PLL: %d Hz\n", CLK_GetPLLClockFreq() );
    printf( "UART: %d Hz\n", CLK_GetUARTFreq() );

    TIMER_Open( TIMER0, TIMER_CONTINUOUS_MODE, 1000000 );
    I2cInit();
    SpiInit();
    PdmaInit();

    SpiReadAndWriteByPdma( _NRF_SPI, data, data, 5 );

    //TIMER_Delay( TIMER0, 100000 );

    for ( size_t i = 0; i < 5; i++ ) { printf( "%02x ", data[ i ] ); }

    while ( true ) {};
    return 0;
}

void SPI0_IRQHandler( void ) {
    if ( SPI_GetIntFlag( SPI0, SPI_FIFO_TXTH_INT_MASK ) ) { printf( "SPI_FIFO_TXTH_INT_MASK\n" ); }
    if ( SPI_GetIntFlag( SPI0, SPI_FIFO_RXOV_INT_MASK ) ) { printf( "SPI_FIFO_RXOV_INT_MASK\n" ); }
    if ( SPI_GetIntFlag( SPI0, SPI_FIFO_RXTO_INT_MASK ) ) { printf( "SPI_FIFO_RXTO_INT_MASK\n" ); }
}
