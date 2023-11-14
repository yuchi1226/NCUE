#include "NUC1xx.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvSYS.h"
int pattern_1[4]={0xe000,0xb000,0xe000,0xd000}; //RGB
int pattern_2_1[4]={0xe010,0x7010,0xd010,0xb010}; //LED_1
int pattern_2_2[4]={0xe020,0x7020,0xd020,0xb020}; //LED_2
int pattern_3[10]={0x22,0x12,0x93,0x0e,0x03,0xcc,0x82,0x3a,0x57,0x79}; //七段
//int pattern_3[10]={0x82,0xee,0x07,0x46,0x6a,0x52,0x12,0xe2,0x02,0x42}; //七段個位

int curi=0,curj=0,k=0,re=0,flag=0,z,current=0,speed=1000;
int press_p=0,press_d=0,press_a=0,press_b=0;
int i=1;

int32_t main (void)
{

	GPIO_T *tGPIO_A,*tGPIO_C,*tGPIO_E;
	uint16_t act[3]={0xfffb,0xfffd,0xfffe}; 		//鍵盤: 指定第一行 第二行 第三行掃描
  uint32_t u32Reg;  
	uint32_t u32Reg_temp;
	tGPIO_A = (GPIO_T *)((uint32_t)GPIOA + (0*0x40));
	tGPIO_C = (GPIO_T *)((uint32_t)GPIOA + (2*0x40)); 
	tGPIO_E = (GPIO_T *)((uint32_t)GPIOA + (4*0x40));
	u32Reg = (uint32_t)&GPIOA->PIN + (0*0x40);	//讀取暫存器時須用PIN欄位 
	
	while(1) 
	{
		curi=i;
		
		tGPIO_A->DOUT = act[0];	// 掃描
		u32Reg_temp=inpw(u32Reg);
		if((u32Reg_temp & 0x08) == 0)	 //+
		{
			DrvSYS_Delay(100000);
			press_p=1;
		}
		else if((u32Reg_temp & 0x20) == 0)	 //-
		{
			DrvSYS_Delay(100000);
			press_d=1;
		}
				
				
		tGPIO_A->DOUT = act[1];	// 掃描
		u32Reg_temp=inpw(u32Reg);
		if((u32Reg_temp & 0x08) == 0)	//10 
		{
			press_a=1;
			for(z=0;z<3;z++)
			{
				tGPIO_A->DOUT = act[0];	// 掃描
				u32Reg_temp=inpw(u32Reg);
				if((u32Reg_temp & 0x08) == 0)	 
				{
					DrvSYS_Delay(100000);
					press_p=1;
				}
				else if((u32Reg_temp & 0x20) == 0)	 
				{
					DrvSYS_Delay(100000);
					press_d=1;
				}
			}
		}
		
		tGPIO_A->DOUT = act[2];	// 掃描
		u32Reg_temp=inpw(u32Reg);
		if((u32Reg_temp & 0x08) == 0)	 //1
		{
			press_b=1;
			for(z=0;z<3;z++)
			{
				tGPIO_A->DOUT = act[0];	// 掃描
				u32Reg_temp=inpw(u32Reg);
				if((u32Reg_temp & 0x08) == 0)	 
				{
					DrvSYS_Delay(100000);
					press_p=1;
				}
				else if((u32Reg_temp & 0x20) == 0)	 
				{
					DrvSYS_Delay(100000);	
					press_d=1;
				}
			}
		}
		
		
		tGPIO_A->DOUT = act[0];//4
		u32Reg_temp=inpw(u32Reg);
		if((u32Reg_temp & 0x10) == 0)	 
		{
			DrvSYS_Delay(100000000);	
			speed+=200;
		}
		
		tGPIO_A->DOUT = act[2];//6
		u32Reg_temp=inpw(u32Reg);
		if((u32Reg_temp & 0x10) == 0)	 
		{
			DrvSYS_Delay(100000000);	
			speed-=200;
		}
		
		
		
		
		
		
		if(press_p==1)
		{
			if(press_a==1)
			{
				if(i<90)
					i+=10;
			}
			press_p=0;
			if(press_b==1)
			{
				if(i<99)
					i++;
			}
			press_a=0;
			press_b=0;
			press_p=0;
		}
		
		if(press_d==1)
		{
			if(press_a==1)
			{
				if(i>10)
					i-=10;
			}
			if(press_b==1)
			{
				if(i>1)
					i--;
			}
			press_a=0;
			press_b=0;
			press_d=0;
		}
		
		if(press_a==1)
		{
			press_a=0;
		}
		if(press_b==1)
		{
			press_b=0;
		}
		
		if(curi!=i)
		{
			current=0;
			k=0;
		}
		
		
		
		
		
		if(current<i)
		{
			tGPIO_A -> DOUT = pattern_1[k%4]; //RGB
			tGPIO_E -> DOUT = pattern_3[i/10]; //七段							
			tGPIO_C -> DOUT = pattern_2_2[k%4];
			DrvSYS_Delay(500);
			tGPIO_E -> DOUT = pattern_3[i%10];
			tGPIO_C -> DOUT = pattern_2_1[k%4];
			DrvSYS_Delay(500);
			if(500+speed<0)
			{
				speed=-350;
			}
			
			if(flag>=(500+speed))
			{
				k++;
				k%=4;
				flag=0;
			}
			else
				flag++;
			
			if(k==0&&flag==0)
				current++;
		}
		else
		{
			current=0;
			i++;
		}
		
		
		
		
		
	}
	
	
	
	
	
	
	
	

}

