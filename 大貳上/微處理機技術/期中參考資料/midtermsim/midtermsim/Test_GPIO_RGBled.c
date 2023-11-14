
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


	
int32_t main (void)
{

	int pattern[10]={0x22, 0x1a, 0x93, 0x0e, 0x03, 0x33, 0x42, 0x3a, 0x57, 0x86};
	int sevenpos[2] = {0xff20, 0xff10};
	int color[4]={0xe000, 0xb000, 0xe000, 0xd000};	//A
	int led[4]={0xe000, 0x7000, 0xd000, 0xb000};
	int act[3] = {0xfffb, 0xfffd, 0xfffe}; //row
	int add = 0, minus = 0, tens = 0, ones = 0;
	int count01 = 1;
	int count10 = 0;
	int press = 0;
	int out = 0;
	int i, j, k;
	int ddelay = 850;
	int terminate = 0;
	GPIO_T * tGPIO_A, * tGPIO_C, * tGPIO_E;
	uint32_t u32Reg;  
	uint32_t u32Reg_temp;
	tGPIO_A = (GPIO_T *)((uint32_t)GPIOA + (0*0x40));
	tGPIO_C = (GPIO_T *)((uint32_t)GPIOA + (2*0x40)); 
	tGPIO_E = (GPIO_T *)((uint32_t)GPIOA + (4*0x40));
	u32Reg = (uint32_t)&GPIOA->PIN + (0*0x40);
	
	//initialize
	
	while (count01 < 100)
	{
		/*
					tGPIO_A -> DOUT = act[0];
					u32Reg_temp = inpw(u32Reg);
					if((u32Reg_temp & 0x08) == 0) //++
					{
						add = 1;
						press = 1;
						DrvSYS_Delay(100000);
					}
					else if((u32Reg_temp & 0x20) == 0) //--
					{
						minus = 1;
						press = 1;
						DrvSYS_Delay(100000);
					}
					
					tGPIO_A -> DOUT = act[1];
					u32Reg_temp = inpw(u32Reg);
					if((u32Reg_temp & 0x08) == 0)
					{
						DrvSYS_Delay(100000);
						tens = 1;
						press = 1;
					}
					tGPIO_A -> DOUT = act[2];
					u32Reg_temp = inpw(u32Reg);
					if ((u32Reg_temp & 0x08) == 0)
					{
						DrvSYS_Delay(100000);
						ones = 1;
						press = 1;
					}
						///
					tGPIO_A -> DOUT = act[0];
					u32Reg_temp = inpw(u32Reg);
					if((u32Reg_temp & 0x08) == 0) //++
					{
						add = 1;
						press = 1;
						DrvSYS_Delay(100000);
					}
					else if((u32Reg_temp & 0x20) == 0) //--
					{
						minus = 1;
						press = 1;
						DrvSYS_Delay(100000);
					}
					///
					
					if(add == 1)
					{
						add = 0;
						if(tens == 1)
						{
							if(count01 < 90)
							{
							count01+=10;
							count10++;
							}
							tens = 0;
						}
						else if(ones == 1)
						{
							if(count01 < 98)
								count01 ++;
							ones = 0;
						}
						press = 1;
					}
					
					if (minus == 1)
					{
						minus = 0;
						if(tens == 1)
						{
							if(count01 > 10);
							{
								count01-=10;
								count10--;
							}
							tens = 0;
						}
						else if(ones == 1)
						{
							if(count01 > 1)
								count01--;
							ones = 0;
						}
						press = 1;
					}
					/////
					if(press == 1)
					{
						//DrvSYS_Delay(10000000);
						press = 0 ;
						minus = 0;
						continue;
						//continue;
					}
					*/
					out = 0;
					if(terminate == 0)
					{
						for( i = 1 ; i <= count01 ; i ++)
						{
							
							for(j = 0 ; j < 4 ; j ++)			
							{
								for(k = 0 ; k < ddelay ; k ++)
								{
						
									//tGPIO_C -> DOUT = 0xff00;
									tGPIO_A -> DOUT = color[j];
									tGPIO_C -> DOUT = led[j];
									DrvSYS_Delay(ddelay);
									tGPIO_C -> DOUT = 0xff00;
									tGPIO_E -> DOUT = pattern[count10];
									tGPIO_C -> DOUT = sevenpos[0];
									DrvSYS_Delay(ddelay);
									tGPIO_C -> DOUT = 0xff00;
									tGPIO_E -> DOUT = pattern[count01%10];
									tGPIO_C -> DOUT = sevenpos[1];
									DrvSYS_Delay(ddelay);
									tGPIO_C -> DOUT = 0xff00;
									////////
									tGPIO_A -> DOUT = act[0];
									u32Reg_temp = inpw(u32Reg);
									if((u32Reg_temp & 0x08) == 0) //++
									{
										add = 1;
										press = 1;
										DrvSYS_Delay(100000);
									}
									else if((u32Reg_temp & 0x20) == 0) //--
									{
										minus = 1;
										press = 1;
										DrvSYS_Delay(100000);
									}
									
									tGPIO_A -> DOUT = act[1];
									u32Reg_temp = inpw(u32Reg);
									if((u32Reg_temp & 0x08) == 0)
									{
										DrvSYS_Delay(100000);
										tens = 1;
										press = 1;
									}
									tGPIO_A -> DOUT = act[2];
									u32Reg_temp = inpw(u32Reg);
									if ((u32Reg_temp & 0x08) == 0)
									{
										DrvSYS_Delay(100000);
										ones = 1;
										press = 1;
									}
									/*	///
									tGPIO_A -> DOUT = act[0];
									u32Reg_temp = inpw(u32Reg);
									if((u32Reg_temp & 0x08) == 0) //++
									{
										add = 1;
										press = 1;
										DrvSYS_Delay(100000);
									}
									else if((u32Reg_temp & 0x20) == 0) //--
									{
										minus = 1;
										press = 1;
										DrvSYS_Delay(100000);
									}
									*/
									//delay speed
									tGPIO_A -> DOUT = act[0];
									u32Reg_temp = inpw(u32Reg);
									if((u32Reg_temp & 0x10) == 0)	//slow down
									{
										DrvSYS_Delay(100000);
										if(ddelay < 1550)
											ddelay +=200;
									}								
									tGPIO_A -> DOUT = act[2];
									u32Reg_temp = inpw(u32Reg);
									if((u32Reg_temp & 0x10) == 0)	//speed up;
									{
										DrvSYS_Delay(100000);
										if(ddelay > 250)
											ddelay -= 200;
									}							
									
									
									//
									
									if(add == 1)
									{
										add = 0;
										if(tens == 1)
										{
											if(count01 < 90)
											{
											count01+=10;
											count10++;
											}
											tens = 0;
										}
										else if(ones == 1)
										{
											if(count01 <= 98)
												count01 ++;
											if(count01 %10 == 0)
												count10++;
											ones = 0;
										}
										press = 1;
									}
									
									if (minus == 1)
									{
										minus = 0;
										if(tens == 1)
										{
											if(count01 > 10);
											{
												count01-=10;
												count10--;
											}
											tens = 0;
										}
										else if(ones == 1)
										{
											if(count01 > 1)
												count01--;
											if(count01 %10 == 9 && count10 > 0)
												count10--;
											ones = 0;
										}
										press = 1;
									}
									/////
									if(press == 1)
									{
										//DrvSYS_Delay(10000000);
										press = 0 ;
										minus = 0;
										out = 1;
										break;
										//continue;
									}
			
								}//ddelay 
								if(out == 1)
									break;
							}//j < 4 
							if(out == 1)
								break;
							//DrvSYS_Delay(500);
						}//i <= count01
				}//if(terminate == 0) 
				if(terminate == 1)
				{
					tGPIO_A -> DOUT = color[3];
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
				}
				if(out == 0)
				{
					if(count01 == 99)
					{
						terminate = 1;
						continue;
					}
					
					else
					{
						count01++;
						if(count01 % 10 == 0)
							count10++;
					}
				}
		//DrvSYS_Delay(1000000000);
	}//	while(1) 
/*
		while(1)
		{
			//for(i = 0 ; i < 500 ; i ++)
			//{
				tGPIO_A -> DOUT = color[3];
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
			//}
		}*/
}
