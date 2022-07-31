/****************************************Copyright (c)****************************************************
**
**
**
**--------------File Info---------------------------------------------------------------------------------
** File name     :
** Descriptions  :
**
**--------------------------------------------------------------------------------------------------------
** Created date  :
** Created date     : 2022-7-31
** Version       : V1.0
** Descriptions  :
**
**--------------------------------------------------------------------------------------------------------
** Modified by   : bruce thb
** Modified date :
** Version       :
** Descriptions  :
*********************************************************************************************************/

#include "../MC3172/MC3172.h"
#include "uart.h"

/*****************************************************
* @function  : serial_init
* @brief     :

* @in param  :
* @out param :
* @return    : E_OK:sucess  E_ERROR:failed

* @author    : bruce thb
* @other     :
*****************************************************/
u8 serial_init( serial_device_t *serial, u8 *recv_buf, u16 recv_buf_len )
{
    u8 ret = E_OK;

    if (serial == NULL)
    {
        serial->flag = UART_CLOSE_STATUS;
        return E_ERROR;
    }

    INTDEV_SET_CLK_RST( serial->uart.uart_com, serial->uart.uart_clock_config);

    GPCOM_SET_IN_PORT( serial->uart.uart_com, ( serial->uart.in_port) );

    GPCOM_SET_OUT_PORT( serial->uart.uart_com, ( serial->uart.out_port ) );

    GPCOM_SET_COM_MODE( serial->uart.uart_com, GPCOM_UART_MODE);

    GPCOM_SET_COM_SPEED(serial->uart.uart_com, serial->uart.uart_clock, (u32 )serial->config.baud_rate);

    GPCOM_SET_OVERRIDE_GPIO(serial->uart.uart_com, ( (serial->uart.out_mode) | (serial->uart.in_mode) ) );

    ret = fifo_init(&serial->int_rx, recv_buf, recv_buf_len, NULL, NULL);

    if (1 == ret )
    {
        ret = E_ERROR;
        serial->flag = UART_CLOSE_STATUS;
    }
    else
    {
        ret = E_OK;
        serial->flag = UART_OPEN_STATUS;
    }

    return ret;
}



/*****************************************************
* @function  : serial_close
* @brief     :

* @in param  :
* @out param :
* @return    :  E_OK:sucess  E_ERROR:failed

* @author    : bruce thb
* @other     :
*****************************************************/
 u8 serial_close( serial_device_t *serial )
{
    u8 ret = E_OK;

    serial->flag = UART_CLOSE_STATUS;
    return ret;
}

/*****************************************************
* @function  : serial_write
* @brief     :

* @in param  :
* @out param :
* @return    :  write length

* @author    : bruce thb
* @other     :
*****************************************************/
u32 serial_write( serial_device_t *serial, const void *buffer, u32 size )
{
    u8 *ptr;

    if (serial == NULL)
    {
        return 0;
    }

    if ( !(serial->flag & UART_OPEN_STATUS) )
    {
        return 0;
    }

    ptr = (u8 *)buffer;

    while ( size )
    {
        while( GPCOM_TX_FIFO_FULL(GPCOM4_BASE_ADDR) );
        GPCOM_PUSH_TX_DATA( GPCOM4_BASE_ADDR, *ptr );
        ++ptr; --size;
    }
    return (u32)ptr - (u32)buffer;
}

/*****************************************************
* @function  : serial_read
* @brief     :

* @in param  :
* @out param :
* @return    :  E_OK:sucess  E_ERROR:failed

* @author    : bruce thb
* @other     :
*****************************************************/
u8 serial_read( serial_device_t *serial, void *buffer, u32 *p_size )
{
    u8 * u8_ptr;
    u8 u8_status = E_OK;
    u32 u32_read_len = *p_size;

    if (serial == NULL)
    {
        u8_status = E_ERROR;
        return u8_status;
    }

    if ( (buffer == NULL) || (*p_size == 0) || (serial == NULL) )
    {
        u8_status = E_ERROR;
        return u8_status;
    }

    if (!(serial->flag & UART_OPEN_STATUS))
    {
        u8_status = E_ERROR;
        return u8_status;
    }

    /* interrupt mode Rx */
    u8_status = fifo_read(&serial->int_rx, (u8 *)buffer, &u32_read_len);
    if (0 != u8_status)
    {
        u8_status = E_ERROR;
    }
    else
    {
        *p_size = u32_read_len;
    }

    return u8_status;
}
