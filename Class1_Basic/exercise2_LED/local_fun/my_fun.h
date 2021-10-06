#ifndef _MY_
#define _MY_
#include <reg52.h>

typedef unsigned int uint16;
typedef unsigned char uint8;

sbit LED_1 = P2^0;
sbit LED_2 = P2^1;
sbit LED_3 = P2^2;
sbit LED_4 = P2^3;
sbit LED_5 = P2^4;
sbit LED_6 = P2^5;
sbit LED_7 = P2^6;
sbit LED_8 = P2^7;

extern void delay_us(uint16 ten_us);
extern void led_flash_local(uint8 led_port);
extern int led_flash(uint8 i);
extern void led_flash_someone(uint8 led_port);

#endif