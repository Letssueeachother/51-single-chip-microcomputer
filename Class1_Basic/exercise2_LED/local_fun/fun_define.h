
#include <intrins.h>
#include "my_fun.h"
#define LED_PORT P2
//uint8 port;
/***********************
*��ʱ����
*ͨ����12M����12T(һ������������12��ʱ�����ڣ���51��Ƭ�����е�ָ���ࣩ��1���������ڣ��е���2������������ָ����4�����ˣ�������
*������Ӧ�ľ���Ҫ1us,2us,4us��
*����Ӳ�����
*������������stc89c52rc��A4����������ʵ���ӳ�
*���������������
*���ԼΪ8mms/500ms
********************/
void delay_us(uint16 ten_us)
{
	ten_us = ten_us*104;
	while(ten_us-- );

}

/***********************
*LED���������ķ�װ
*�����������Ҫ������LEDλ�ã���D1,�������Ϊ1
*����ֵ����
*Ч��������LEDһֱ��
*�˳�������������
****************************/

void led_flash_someone(uint8 led_port)
{
		while(1) ///��������ֹͣ����
		{
			LED_PORT = ~(0x1 << (led_port - 1));
			delay_us(300);
			LED_PORT = 0x00;
			delay_us(300);
		}


}


void led_flash_local(uint8 i)
{		
		uint8 port;	//��һ����ں������ʾ: error C202: 'port': undefined identifier
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

