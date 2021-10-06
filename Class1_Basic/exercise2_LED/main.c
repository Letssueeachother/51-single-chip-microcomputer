/***********************
*实验名称：LED流水灯试验
*实验条件：普中51开发板（A4,STC89C52RC），uvision4
*实验原理：P2管脚输出低电平，驱动共阳极LED灯闪烁
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