
// 
//
// Output : GPC12-15 output control  LED
// 0 : on, 1 : off

#include "NUC1xx.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvSYS.h"


//=============================================================
// MAIN function
//=============================================================

int pattern[10]={0x82, 0xee, 0x07, 0x46, 0x6a, 0x52, 0x12, 0xe2, 0x02, 0x42};
int led[4]={0xe000, 0xd000, 0xb000, 0x7000};
int act[3] = {0xfffb, 0xfffd, 0xfffe};
int add = 0,minus = 0,press = 0,out = 0,enter = 0,termination=0;
int count01 = 3;
int count10 = 3;
GPIO_T * tGPIO_A, * tGPIO_C, * tGPIO_E;
uint32_t u32Reg;  
uint32_t u32Reg_temp;
tGPIO_A = (GPIO_T *)((uint32_t)GPIOA + (0*0x40));
tGPIO_C = (GPIO_T *)((uint32_t)GPIOA + (2*0x40)); 
tGPIO_E = (GPIO_T *)((uint32_t)GPIOA + (4*0x40));
u32Reg = (uint32_t)&GPIOA->PIN + (0*0x40);
	
int32_t main (void)
{

	while (1)
	{
		tGPIO_A -> DOUT = 0xe000;
		
		tGPIO_C -> DOUT = 0xff00;
		tGPIO_C -> DOUT = led[0];
		DrvSYS_Delay(500);
		tGPIO_C -> DOUT = 0xff00;
		tGPIO_C -> DOUT = led[1];
		DrvSYS_Delay(500);
		tGPIO_C -> DOUT = 0xff00;
		tGPIO_C -> DOUT = led[2];
		DrvSYS_Delay(500);
		tGPIO_C -> DOUT = 0xff00;
		tGPIO_C -> DOUT = led[3];
		DrvSYS_Delay(500);
		
		tGPIO_C -> DOUT = 0xff00;
		tGPIO_E -> DOUT = pattern[count10];
		tGPIO_C -> DOUT = sevenpos[0];
		DrvSYS_Delay(500);
		tGPIO_C -> DOUT = 0xff00;
		tGPIO_E -> DOUT = pattern[count01%10];
		tGPIO_C -> DOUT = sevenpos[1];
		DrvSYS_Delay(500);
		
		tGPIO_C -> DOUT = 0xff00;
		
		tGPIO_A -> DOUT = act[0];
		u32Reg_temp = inpw(u32Reg);//1
		if((u32Reg_temp & 0x08) == 0) 
		{
			press = 1;
			DrvSYS_Delay(100000);
		}
		tGPIO_A -> DOUT = act[1];//2
		u32Reg_temp = inpw(u32Reg);
		if((u32Reg_temp & 0x08) == 0)
		{
			DrvSYS_Delay(100000);
			add = 1;press = 1;
		}
		tGPIO_A -> DOUT = act[2];//3
		u32Reg_temp = inpw(u32Reg);
		if ((u32Reg_temp & 0x08) == 0)
		{
			DrvSYS_Delay(100000);
			minus = 1;press = 1;
		}
		else if ((u32Reg_temp & 0x10) == 0)//6
		{
			DrvSYS_Delay(100000);
			enter = 1;press = 1;
		}
	
		if(enter==1)
		{
			out = 0;
			
			for(j = 0 ; j < 2 ; j ++)			
			{
				for(k = 0 ; k < 850 ; k ++)
				{
		
					if(terminaion==0)
					{
						if(j==0)
						{
							tGPIO_C -> DOUT = 0xff00;
							tGPIO_C -> DOUT = led[0];
							DrvSYS_Delay(500);
							tGPIO_C -> DOUT = 0xff00;
							tGPIO_C -> DOUT = led[1];
							DrvSYS_Delay(500);
						}
						else if(j==1)
						{
							tGPIO_C -> DOUT = 0xff00;
							tGPIO_C -> DOUT = led[2];
							DrvSYS_Delay(500);
							tGPIO_C -> DOUT = 0xff00;
							tGPIO_C -> DOUT = led[3];
							DrvSYS_Delay(500);
						}
						
					}

					tGPIO_A -> DOUT = 0xe000;
					tGPIO_C -> DOUT = 0xff00;
					tGPIO_E -> DOUT = pattern[count10];
					tGPIO_C -> DOUT = sevenpos[0];
					DrvSYS_Delay(500);
					tGPIO_C -> DOUT = 0xff00;
					tGPIO_E -> DOUT = pattern[count01%10];
					tGPIO_C -> DOUT = sevenpos[1];
					DrvSYS_Delay(500);
					
					tGPIO_C -> DOUT = 0xff00;
							
					tGPIO_A -> DOUT = act[0];//1
					u32Reg_temp = inpw(u32Reg);
					if((u32Reg_temp & 0x08) == 0) 
					{
						press = 1;
						DrvSYS_Delay(100000);
					}
					tGPIO_A -> DOUT = act[1];//2
					u32Reg_temp = inpw(u32Reg);
					if((u32Reg_temp & 0x08) == 0)
					{
						DrvSYS_Delay(100000);
						add = 1;press = 1;
					}
					tGPIO_A -> DOUT = act[2];//3
					u32Reg_temp = inpw(u32Reg);
					if ((u32Reg_temp & 0x08) == 0)
					{
						DrvSYS_Delay(100000);
						minus = 1;press = 1;
					}
	
					if(add == 1)
					{
						add = 0;
						
						if(count01 <= 98)
							count01 ++;
						if(count01 %10 == 0)
							count10++;
						
						press = 1;
					}
					if (minus == 1)
					{
					
						if(count01 > 1)
							count01--;
						if(count01 %10 == 9 && count10 > 0)
							count10--;
						
						press = 1;
					}
							
					if(press == 1)
					{
						press = 0 ;
						minus = 0;
						out = 1;
						break;	
					}
	
				}
				if(out == 1)
					break;
			}				
			if(out == 1)
				break;
			else if(out == 0)
			{
				count01++;
				if(count01 % 10 == 0)
					count10++;
			}
				
			if(count01 % 10 == 0)
				termination==1;
		}
	}
}
