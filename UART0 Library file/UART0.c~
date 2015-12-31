/*
 * UART0.h
 *
 * Created: 30/12/2015 5:17:49 AM
 *  Author: Ashish kushwaha
 * Email: Ashish_kushwaha@outlook.com
 * Website:arm-tutorials.com
 */ 

#include <TM4c123gh6pm.h>
#include <stdlib.h>
#include <stdint.h>
#include "UART0.h"

void UART0_init (uint32_t baud_rate){
		float baud_value=(F_CPU/(16.0*baud_rate));
		int baud_Ivalue=baud_value;
		int baud_Fvalue=(((baud_value-baud_Ivalue)*64)+0.5);
		SYSCTL->RCGC1|=1;
		SYSCTL->RCGC2|=1;
		SYSCTL->RCGCUART|=1;	//Enabling UART 
		SYSCTL->RCGCGPIO|=1;	//Enabling UART0
		UART0->CTL&=~0x1;	//uart disable during setting
		UART0->IBRD=baud_Ivalue; //int part
		UART0->FBRD=baud_Fvalue;	//float part
		UART0->LCRH|=((1<<6)|(1<<5)|(1<<4)); //8 bit FIFO enable 
		UART0->CTL|=0x1; //uart enable
		GPIOA->AFSEL|=0x3; //Enabling alternate function
		GPIOA->DEN|=0x3;		//digital enable
		GPIOA->PCTL=((GPIOA->PCTL&0xFFFFFF00)+0x11);
		GPIOA->AMSEL&=~0x3;
}

void U0_snd_chr(uint8_t one_byte){
	empty_buf();
	while((UART0->FR&0x20)!=0);
	UART0->DR=one_byte;
}

void U0_snd_str(char *buffer){
	empty_buf();
  while(*buffer!=0){ 
  U0_snd_chr(*buffer);
		buffer++;
	}
}

char U0_get_chr(void){
  while((UART0->FR&0x10) != 0);
	return(UART0->DR&0xFF);
}

void empty_buf(void){
	volatile char trash=0;
	 while((UART0->FR&0x10) == 0) trash=(UART0->DR&0xFF);
}

char *U0_get_str(char *target,int size){
			target=(char*)malloc(size*sizeof(char));
			int i=0;
			for(;(i<size&&(target[i-1]!='.'));i++) target[i]=U0_get_chr();
			target[i-1]=0;
			empty_buf();
			return target;
}
