
#include <intrins.h>
#include "my_fun.h"
#define LED_PORT P2
//uint8 port;
/***********************
*延时函数
*通常对12M晶振，12T(一个机器周期是12个时钟周期）的51单片机，有的指令（汇编）是1个机器周期，有的是2个，还有两条指令是4个（乘，除），
*这样对应的就需要1us,2us,4us。
*即跟硬件相关
*本函数在普中stc89c52rc（A4）开发板上实现延迟
*输入参数：毫秒数
*误差约为8mms/500ms
********************/
void delay_us(uint16 ten_us)
{
	ten_us = ten_us*104;
	while(ten_us-- );

}

/***********************
*LED单个点亮的封装
*输入参数：需要点亮的LED位置，如D1,输入参数为1
*返回值：无
*效果：单个LED一直闪
*退出条件：待开发
****************************/

void led_flash_someone(uint8 led_port)
{
		while(1) ///后续设置停止条件
		{
			LED_PORT = ~(0x1 << (led_port - 1));
			delay_us(300);
			LED_PORT = 0x00;
			delay_us(300);
		}


}


void led_flash_local(uint8 i)
{		
		uint8 port;	//这一句放在后面会提示: error C202: 'port': undefined identifier
		LED_PORT = ~0x01;
		//delay_us(100);
		//uint8 port;
		for (port = 0; port < i; port++ )
			{
			 	LED_PORT = ~(0x1 << port);
				delay_us(300);
			}
}

/**********************
*
**********************/
int led_flash(uint8 i)
{
//	while(1)
	{
				LED_PORT = ~0x01;
				delay_us(300);
				if(i == 1 || i == 0)
					{
						LED_PORT = 0xFF;
						delay_us(300);
						return 0;
					}
			
				if(i >= 2)
					{
						uint8 led_port = 0;
						uint8 num = i -1;
						for(led_port = 0;led_port < num; led_port++ )
							{
								LED_PORT = _crol_(LED_PORT, 1);
								delay_us(300);
							}
						return 0; 
					}
	}
}

