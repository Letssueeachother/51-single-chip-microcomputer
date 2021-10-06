#include "reg52.h"

typedef unsigned char uint8;
typedef unsigned int uint16;

sbit Buzzer = P2^5;
/*************************
*��ʱ����
*ͨ����12M����12T(һ������������12��ʱ�����ڣ���51��Ƭ����
*�е�ָ���ࣩ��1���������ڣ��е���2������������ָ����4�����ˣ�������
*������Ӧ�ľ���Ҫ1us,2us,4us������Ӳ�����
***************************/

/**************************
*���룺������
*�������
*Ч�����Ժ��루ms��Ϊ��λ���ӳ�
*��ԼΪ8mms/500ms
********************/
void delay_us(uint16 ten_us);

/***************************
*���룺10΢����
*�������
*Ч������10΢�루10us��Ϊ��λ���ӳ�
*��δ֪
***************************/
void delay_ms(uint16 i); 

/***************************
*���룺���������ʱ�䣬����ʱ��Ƶ���йأ�
*�������
*Ч������������
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
	//���������λ1ʱ����ʱԼΪ10us
	while(ten_us-- );

}

/********������**********/
void buzzer(uint16 num)
{
	while(1)
		{
			while(num-- )
			{
				//�ı����ڣ��ı�����
				//�ı�ռ�ձȣ��ı�������С
//				Buzzer = !Buzzer;
//				delay_ms(1);
				Buzzer = 0;
				delay_10us(10);
				Buzzer = 1;
				delay_10us(190);
			}
			num = 0;//��Ҫ����Ȼ������ѭ������������һֱ��
			Buzzer = 1;
		}
 }