#ifndef __USART_H
#define __USART_H

#include "stdio.h"	
#include "stm32f4xx_conf.h"
#include "sys.h" 
#include "pbdata.h"



#define RS_485_RX_EN 	GPIO_ResetBits(GPIOD , GPIO_Pin_7)	//接收使能
#define RS_485_TX_EN 	GPIO_SetBits(GPIOD , GPIO_Pin_7) 	//发送使能

#define TX_MODE 	GPIO_SetBits(GPIOD , GPIO_Pin_7)
#define RX_MODE 	GPIO_ResetBits(GPIOD , GPIO_Pin_7)

#define method 	1



#define USART_REC_LEN  			200  	//定义最大接收字节数 200
#define EN_USART2_RX 			1		//使能（1）/禁止（0）串口1接收
	  	
extern u8  USART_RX_BUF[USART_REC_LEN]; //接收缓冲,最大USART_REC_LEN个字节.末字节为换行符 
extern u16 USART_RX_STA;         		//接收状态标记	
//如果想串口中断接收，请不要注释以下宏定义
//void uart_init(u32 bound);
int check(u8 res);
extern void uart_init(u32 bound);

void USART_Configuration(void);
#endif


