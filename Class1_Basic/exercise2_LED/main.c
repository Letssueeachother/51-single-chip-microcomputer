/***********************
*ʵ�����ƣ�LED��ˮ������
*ʵ������������51�����壨A4,STC89C52RC����uvision4
*ʵ��ԭ��P2�ܽ�����͵�ƽ������������LED����˸
***********************/

#include ".\local_fun\my_fun.h"
#include ".\local_fun\fun_define.h"


void main()
{
	while(1)
		{
			led_flash(3);
			led_flash_local(6);
			
		}
			
}