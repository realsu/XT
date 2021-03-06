#ifndef __MYIIC_H
#define __MYIIC_H

#include "REGSREG.h"
#include "pbdata.h"


typedef struct
{
	float x;
	float y;
	float z;
}imu;












//IO方向设置
//#define SDA_IN()  {GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=0<<9*2;}	//PB9输入模式
//#define SDA_OUT() {GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=1<<9*2;} //PB9输出模式

void SDA_IN(void);
void SDA_OUT(void);

//IO操作函数	 
#define IIC_SCL    PAout(5) //SCL
#define IIC_SDA    PAout(6) //SDA	 
#define READ_SDA   PAin(6)  //输入SDA 

//IIC所有操作函数
void IIC_Init(void);                //初始化IIC的IO口				 
void IIC_Start(void);				//发送IIC开始信号
void IIC_Stop(void);	  			//发送IIC停止信号
void IIC_Send_Byte(u8 txd);			//IIC发送一个字节
u8 IIC_Read_Byte(unsigned char ack);//IIC读取一个字节
u8 IIC_Wait_Ack(void); 				//IIC等待ACK信号
void IIC_Ack(void);					//IIC发送ACK信号
void IIC_NAck(void);				//IIC不发送ACK信号

void IIC_Write_One_Byte(u8 daddr,u8 addr,u8 data);
u8 IIC_Read_One_Byte(u8 daddr,u8 addr);	  


u8 IICreadBytes(u8 dev, u8 reg, u8 length, u8 *data);
u8 IICwriteBytes(u8 dev, u8 reg, u8 length, u8* data);


void ShortToChar(short sData,unsigned char cData[]);
short CharToShort(unsigned char cData[]);
void GY_901_Get(void);
void GY_901_Set_Offset(void);




#endif
















