#ifndef __UART_H__
#define __UART_H__

#include "fifo.h"

#define UART_OPEN_STATUS     ((u8 ) 0x55u)
#define UART_CLOSE_STATUS    ((u8 ) 0x00u)

#define E_OK        ((u8)0x00u)
#define E_ERROR     ((u8)0x01u)


typedef enum   /* All the UART Baud Rate that the UART Package supplay */
{
    UART_BAUD_2400      = 2400,
    UART_BAUD_3600      = 3600,
    UART_BAUD_4800      = 4800,
    UART_BAUD_9600      = 9600,
    UART_BAUD_19200     = 19200,
    UART_BAUD_38400     = 38400,
    UART_BAUD_57600     = 57600,
    UART_BAUD_115200    = 115200,
    UART_BAUD_230400    = 230400,
    UART_BAUD_460800    = 460800,
    UART_BAUD_921600    = 921600,
    UART_BAUD_1842000   = 1842000,
    UART_BAUD_3686400   = 3686400,
    UART_MAX_NUM_BAUD
}serial_baud_e;

typedef enum  /* The Word Len of the UART Frame Format  */
{
    UART_WORD_LEN_5,                /* set Word Lengto to 5 Bits         */
    UART_WORD_LEN_6,                /* set Word Lengto to 6 Bits         */
    UART_WORD_LEN_7,                /* set Word Lengto to 7 Bits         */
    UART_WORD_LEN_8                 /* set Word Lengto to 8 Bits         */
}serial_wrodlen_e;

typedef enum   /* The Stop Bits of the UART Frame Format */
{
    UART_ONE_STOP_BIT,
    UART_ONE_HALF_OR_TWO_STOP_BITS
}serial_stopbit_e;

typedef enum  /* The Parity Bits of the UART Frame Format */
{
    UART_NO_PARITY_BITS,
    UART_EVEN_PARITY_SELECT,
    UART_ODD_PARITY_SELECT
}serial_paritybit_e;

/****************************************************************************
    Define struct
*****************************************************************************/
typedef struct SCuartConfiguration
{
    serial_baud_e       baud_rate;  /* the baudrate of the uart(default - 115200)*/
    serial_wrodlen_e    data_bits;   /* 5, 6, 7, or 8 number of data bits in the UART data frame (default - 8). */
    serial_stopbit_e    stop_bits;  /* 1, 1.5 or 2 stop bits in the UART data frame (default - 1).   */
    serial_paritybit_e  parity_bit; /* Even, Odd or no-parity bit type in the UART data frame (default - Non). */
}uartConfiguration_t;

typedef struct {
    u32                     uart_clock;
    u32                     uart_clock_config;
    u32                     uart_com;
    u32                     in_port;
    u32                     in_mode;
    u32                     out_port;
    u32                     out_mode;
}uart_typedef_t;
typedef struct {
    u8                      flag;
    uartConfiguration_t     config;
    uart_typedef_t          uart;
    /* rx structure */
    fifo_t                  int_rx;
}serial_device_t;

/*****************************************************
* @function  : serial_init
* @brief     :

* @in param  :
* @out param :
* @return    : E_OK:sucess  E_ERROR:failed

* @author    : bruce thb
* @other     :
*****************************************************/
u8 serial_init( serial_device_t *serial, u8 *recv_buf, u16 recv_buf_len );

/*****************************************************
* @function  : serial_close
* @brief     :

* @in param  :
* @out param :
* @return    :  E_OK:sucess  E_ERROR:failed

* @author    : bruce thb
* @other     :
*****************************************************/
 u8 serial_close( serial_device_t *serial );

/*****************************************************
* @function  : serial_write
* @brief     :

* @in param  :
* @out param :
* @return    :  write length

* @author    : bruce thb
* @other     :
*****************************************************/
u32 serial_write( serial_device_t *serial, const void *buffer, u32 size );

/*****************************************************
* @function  : serial_read
* @brief     :

* @in param  :
* @out param :
* @return    :  E_OK:sucess  E_ERROR:failed

* @author    : bruce thb
* @other     :
*****************************************************/
u8 serial_read( serial_device_t *serial, void *buffer, u32 *p_size );



#endif
