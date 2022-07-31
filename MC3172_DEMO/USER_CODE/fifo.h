#ifndef __FIFO_H__
#define __FIFO_H__

#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef void (*lock_f)( void );
typedef void (*unlock_f)( void );

/**@brief   A FIFO instance structure.
 * @details Keeps track of which bytes to read and write next.
 *          Also, it keeps the information about which memory is allocated for the buffer
 *          and its size. This structure must be initialized by app_fifo_init() before use.
 */
typedef struct
{
    u8			*p_buf;				/**< Pointer to FIFO buffer memory.                      */
    u32		    buf_size_mask;   	/**< Read/write index mask. Also used for size checking. */
    u32		    read_pos;        	/**< Next read position in the FIFO buffer.              */
    u32		    write_pos;       	/**< Next write position in the FIFO buffer.             */
    lock_f      lock;
    unlock_f    unlock;
}fifo_t;

extern u8 fifo_init( fifo_t *p_fifo, u8 *p_buf, u32 buf_size, lock_f lock, unlock_f unlock );

extern u8 fifo_put( fifo_t *p_fifo,u8 byte );

extern u8 fifo_get( fifo_t *p_fifo,u8 *p_byte );

extern u8 fifo_peek( fifo_t *p_fifo,u32 index, u8 *p_byte );

extern void fifo_flush( fifo_t *p_fifo );

extern u8 fifo_read( fifo_t *p_fifo,u8 *p_byte_array, u32 *p_size );

extern u8 fifo_write( fifo_t *p_fifo,u8 const *p_byte_array, u32 *p_size );

extern  u32 fifo_length ( fifo_t *p_fifo );
#ifdef __cplusplus
}
#endif

#endif 

/** @} */

