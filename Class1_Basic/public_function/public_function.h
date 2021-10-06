#include "reg52.h"

typedef unsigned char uint8;
typedef unsigned int uint16;

sbit Buzzer = P2^5;
/*************************
*延时函数
*通常对12M晶振，12T(一个机器周期是12个时钟周期）的51单片机，
*有的指令（汇编）是1个机器周期，有的是2个，还有两条指令是4个（乘，除），
*这样对应的就需要1us,2us,4us，即跟硬件相关
***************************/

/**************************
*输入：毫秒数
*输出：无
*效果：以毫秒（ms）为单位的延迟
*误差：约为8mms/500ms
********************/
void delay_us(uint16 ten_us);

/***************************
*输入：10微秒数
*输出：无
*效果：以10微秒（10us）为单位的延迟
*误差：未知
***************************/
void delay_ms(uint16 i); 

/***************************
*输入：蜂鸣器响的时间，跟延时（频率有关）
*输出：无
*效果：蜂鸣器响
***************************/
void buzzer(uint16 num);





/****PUBLIC_FUNCTION*******/
void delay_ms(uint16 ten_us)
{	
	ten_us = ten_us * 104;
	while(ten_us--);
}

void delay_10us(uint16 ten_us)
{
	//ten_us = ten_us*104;
	//即传入参数位1时，延时约为10us
	while(ten_us-- );

}

/********蜂鸣器**********/
void buzzer(uint16 num)
{
	while(1)
		{
			while(num-- )
			{
				//改变周期：改变音调
				//改变占空比：改变音量大小
//				Buzzer = !Buzzer;
//				delay_ms(1);
				Buzzer = 0;
				delay_10us(10);
				Buzzer = 1;
				delay_10us(190);
			}
			num = 0;//重要，不然会无限循环，即蜂鸣器一直响
			Buzzer = 1;
		}
 }