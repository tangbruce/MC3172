/*--------------------------------------------------------------------------
main.c
****************************************
**  Copyright  (C)    2021-2022   **
**  Web:              http://rothd.cn   **
****************************************
--------------------------------------------------------------------------*/

#include "../MC3172/MC3172.h"
#include "uart.h"

////////////////////////////////////////////////////////////

serial_device_t serial;
void thread_end(void)
{
    while(1);
}

////////////////////////////////////////////////////////////
u8 rx_data_temp[32];


void tx_vid_fun( void )
{
    u8 byte;
    if ( 0 != fifo_length( &serial.int_rx ) )
    {
        while( GPCOM_TX_FIFO_FULL( serial.uart.uart_com ) );
        if ((u8 )0 == fifo_get( &serial.int_rx, &byte ) )
        {
            GPCOM_PUSH_TX_DATA( serial.uart.uart_com, byte );
        }
    }
}

void rx_vid_fun( void )
{
    u8 rx_data_rp = 0;
    u8 rx_data = 0;
    rx_data_rp = GPCOM_GET_RX_WP( serial.uart.uart_com );
    while( 1 )
    {
         if( rx_data_rp != (GPCOM_GET_RX_WP(serial.uart.uart_com)) )
         {
              rx_data = GPCOM_GET_RX_DATA(serial.uart.uart_com, rx_data_rp);
              fifo_put( &serial.int_rx , rx_data );
              rx_data_rp++;
              rx_data_rp &= 0x0f;
         }
    }
}

void thread0_main(void)
{
    //P0 Rx  P1 TX
    serial.config.baud_rate = UART_BAUD_115200;
    serial.uart.uart_clock = 12000000;
    serial.uart.uart_com = GPCOM4_BASE_ADDR;
    serial.uart.uart_clock_config = (INTDEV_RUN|INTDEV_IS_GROUP0|INTDEV_CLK_IS_CORECLK_DIV4);
    serial.uart.in_port = GPCOM_RXD_IS_P0;
    serial.uart.out_port = ( \
            GPCOM_P0_OUTPUT_DISABLE|GPCOM_P1_OUTPUT_ENABLE|GPCOM_P2_OUTPUT_DISABLE|GPCOM_P3_OUTPUT_DISABLE| \
             GPCOM_P0_IS_HIGH | GPCOM_P1_IS_TXD |GPCOM_P2_IS_HIGH |GPCOM_P3_IS_HIGH \
            );
    serial.uart.out_mode = GPCOM_P1_OVERRIDE_GPIO | GPCOM_P1_OUTPUT_ENABLE;
    serial.uart.in_mode = GPCOM_P0_OVERRIDE_GPIO|GPCOM_P0_INPUT_ENABLE;

    serial_init(&serial, rx_data_temp, 32);

    while(1){
        rx_vid_fun();
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread1_main(void)
{
    while(1){
        tx_vid_fun();
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread2_main(void)
{
    while(1){
        //GPCOM_SPI_EXAMPLE(GPCOM9_BASE_ADDR);
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread3_main(void)
{
    while(1){
        //TIMER_COMPARER_EXAMPLE(TIMER2_BASE_ADDR);
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread4_main(void)
{
    while(1){
        //TIMER_CAPTURER_EXAMPLE(TIMER3_BASE_ADDR);
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread5_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread6_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread7_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread8_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread9_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread10_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread11_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread12_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread13_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread14_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread15_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread16_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread17_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread18_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread19_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread20_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread21_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread22_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread23_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread24_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread25_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread26_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread27_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread28_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread29_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread30_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread31_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread32_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread33_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread34_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread35_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread36_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread37_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread38_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread39_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread40_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread41_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread42_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread43_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread44_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread45_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread46_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread47_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread48_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread49_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread50_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread51_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread52_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread53_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread54_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread55_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread56_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread57_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread58_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread59_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread60_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread61_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread62_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////

void thread63_main(void)
{
    while(1){
        //user code section
    }
    thread_end();
}

////////////////////////////////////////////////////////////





