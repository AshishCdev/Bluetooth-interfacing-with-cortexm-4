/*
 * UART0.h
 *
 * Created: 30/12/2015 5:17:49 AM
 *  Author: Ashish kushwaha
 * Email: Ashish_kushwaha@outlook.com
 * Website:arm-tutorials.com
 */ 

#ifndef UART0_H
#define UART0_H
#include <stdint.h>
#define F_CPU 16000000

extern void UART0_init(uint32_t baud_rate);
extern void U0_snd_chr(uint8_t one_byte);
extern void U0_snd_str(char *buffer);
extern char U0_get_chr(void);
extern char *U0_get_str(char *target,int size);
extern void empty_buf(void);

#endif
