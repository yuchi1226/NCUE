//
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
uint16_t act[3]={0xfffb,0xfffd,0xfffe};//鍵盤

int A[4][7]={{1,0,1,0,1,0,1},{0,1,1,0,0,0,1},{1,0,0,1,0,0,0},{0,1,0,0,0,1,0}};
int printA[7]={0Xf7,0Xef,0Xfe,0Xdf,0Xbf,0Xfb,0X7f};								
int tGPIOc[4]={0Xf080,0Xf040,0Xf020,0Xf010};//七段顯示器

int up_or_down=0,current=1,initial;
int temp[4];
int i,j,k;
uint32_t u32row;
uint32_t u32row_temp;



int32_t main (void)
{
    GPIO_T * tGPIO_A,* tGPIO_C,* tGPIO_E;
	  tGPIO_A = (GPIO_T *)((uint32_t)GPIOA + (0*0x40));
    tGPIO_C = (GPIO_T *)((uint32_t)GPIOA + (2*0x40));
    tGPIO_E = (GPIO_T *)((uint32_t)GPIOA + (4*0x40));
	  u32row = (uint32_t)&GPIOA->PIN + (0*0x40);
		tGPIO_C->DOUT = tGPIOc[1];
	
	while(1)
	{
		
		tGPIO_A->DOUT = act[1];
		u32row_temp=inpw(u32row);
		if((u32row_temp & 0x8) == 0 || (u32row_temp & 0x20) == 0)  //上&下
		{
			temp[0]=A[current][6]^A[current][0];
			temp[1]=A[current][2]^A[current][1];
			temp[2]=A[current][3]^A[current][6];
			temp[3]=A[current][4]^A[current][5];
			
			if(up_or_down==0)//原本在上，改變下
			{
				A[current][6]=temp[0];
				A[current][2]=temp[1];
				A[current][3]=temp[2];
				A[current][4]=temp[3];
				up_or_down=1;
			}
			else if(up_or_down==1)//原本在下，改變上
			{
				A[current][0]=temp[0];
				A[current][1]=temp[1];
				A[current][6]=temp[2];
				A[current][5]=temp[3];
				up_or_down=0;
			}
			DrvSYS_Delay(1000000);
		}
		
			
		tGPIO_A->DOUT = act[2];
		u32row_temp=inpw(u32row);
		if((u32row_temp & 0x10) == 0) //右
		{
			if(current==0)
				{initial=0;current=1;}
			else if(current==1)
				{initial=1;current=2;}
			else if(current==2)
				{initial=2;current=3;}
			else if(current==3)
				{initial=3;current=0;}

			if(up_or_down==0)
			{
				temp[0]=A[current][0]^A[initial][0];
				temp[1]=A[current][1]^A[initial][1];
				temp[2]=A[current][6]^A[initial][6];
				temp[3]=A[current][5]^A[initial][5];
				A[current][0]=temp[0];
				A[current][1]=temp[1];
				A[current][6]=temp[2];
				A[current][5]=temp[3];
			}
			else if(up_or_down==1)
			{
				temp[0]=A[current][6]^A[initial][6];
				temp[1]=A[current][2]^A[initial][2];
				temp[2]=A[current][3]^A[initial][3];
				temp[3]=A[current][4]^A[initial][4];
				A[current][6]=temp[0];
				A[current][2]=temp[1];
				A[current][3]=temp[2];
				A[current][4]=temp[3];
			}		
			DrvSYS_Delay(1000000);
		}
			
		tGPIO_A->DOUT = act[0];
		u32row_temp=inpw(u32row);
		if((u32row_temp&0x10) == 0)   //左
		{
			if(current==0)
				{initial=0;current=3;}
			else if(current==1)
				{initial=1;current=0;}
			else if(current==2)
				{initial=2;current=1;}
			else if(current==3)
				{initial=3;current=2;}

			if(up_or_down==0)
			{
				temp[0]=A[current][0]^A[initial][0];
				temp[1]=A[current][1]^A[initial][1];
				temp[2]=A[current][6]^A[initial][6];
				temp[3]=A[current][5]^A[initial][5];
				A[current][0]=temp[0];
				A[current][1]=temp[1];
				A[current][6]=temp[2];
				A[current][5]=temp[3];
			}
			else if(up_or_down==1)
			{
				temp[0]=A[current][6]^A[initial][6];
				temp[1]=A[current][2]^A[initial][2];
				temp[2]=A[current][3]^A[initial][3];
				temp[3]=A[current][4]^A[initial][4];
				A[current][6]=temp[0];
				A[current][2]=temp[1];
				A[current][3]=temp[2];
				A[current][4]=temp[3];
			}			
			DrvSYS_Delay(1000000);
		}
		
	
		for(i=0;i<4;i++)	
			for(j=0;j<7;j++)
				if(A[i][j]==1)
				{
					tGPIO_C->DOUT = 0xff00;
					tGPIO_E->DOUT = printA[j];
					tGPIO_C->DOUT = tGPIOc[i];
					DrvSYS_Delay(1000);
				}	
	
		
			
	}//while	
}//main    
    
