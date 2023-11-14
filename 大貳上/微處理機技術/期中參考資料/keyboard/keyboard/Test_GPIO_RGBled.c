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

int visit[3][4]={0};
int bling[3][4]={0};
int print_row[3]={0Xf7,0X7f,0Xdf};//i
int print_column[4]={0Xff80,0Xff40,0Xff20,0Xff10};//j

//uint16_t column[3]={0xfffb,0xfffd,0xfffe}; //鍵盤: 指定第一行 第二行 第三行掃描
//uint16_t row[3] = {0X80,0X10,0X20};//鍵盤: 指定第一列 第二列 第三列掃描

uint16_t act[3]={0xfffb,0xfffd,0xfffe};
uint32_t u32row;
uint32_t u32row_temp;
int row=0,column=0,i,j,k,flag=0,push,count=0;
int newrow = 0, newcolumn = 0;
int32_t main (void)
{
    GPIO_T * tGPIO_A,* tGPIO_C,* tGPIO_E;
	  tGPIO_A = (GPIO_T *)((uint32_t)GPIOA + (0*0x40));//鍵盤: 指定第一行 第二行 第三行掃描
    tGPIO_C = (GPIO_T *)((uint32_t)GPIOA + (2*0x40));
    tGPIO_E = (GPIO_T *)((uint32_t)GPIOA + (4*0x40));
	  u32row = (uint32_t)&GPIOA->PIN + (0*0x40);//鍵盤: 指定第一列 第二列 第三列掃描
	
		tGPIO_E->DOUT = 0Xf7;
		tGPIO_C->DOUT = 0Xff80;
		visit[0][0]=1;
		bling[0][0]=1;
	
		while(1) 
		{
				push=0;
				
				tGPIO_A->DOUT = act[0];//強制變1
				u32row_temp=inpw(u32row);
				if((u32row_temp & 0x8) == 0)
				{
					visit[row][column]  = 1;
				}
				tGPIO_A->DOUT = act[0];//強制變0
				u32row_temp=inpw(u32row);
				if((u32row_temp & 0x20) == 0)
				{
					visit[row][column]  = 0;
				}
				
				tGPIO_A->DOUT = act[1];
				u32row_temp=inpw(u32row);
				if((u32row_temp & 0x8) == 0) //上
				{
					if(row==0) newrow=2; 
					else if(row==2) newrow=1; 
					else if(row==1) newrow=0; 
					
					if(visit[newrow][newcolumn]==0)visit[newrow][newcolumn]=1;
					else if(visit[newrow][newcolumn]==1) visit[newrow][newcolumn]=0;
					newcolumn = column;
					push=1;
					
					for(i=0;i<3;i++)
						for(j=0;j<4;j++)
								bling[i][j]=0;
					bling[newrow][newcolumn]=1;
				}
				
				tGPIO_A->DOUT = act[1];
				u32row_temp=inpw(u32row);
				if((u32row_temp & 0x20) == 0) //下
				{
					if(row==0) newrow=1; 
					else if(row==1) newrow=2; 
					else if(row==2) newrow=0; 
					
					if(visit[newrow][newcolumn]==0) visit[newrow][newcolumn]=1;
					else if(visit[newrow][newcolumn]==1) visit[newrow][newcolumn]=0;
					newcolumn = column;
					push=1;
					
					for(i=0;i<3;i++)
						for(j=0;j<4;j++)
								bling[i][j]=0;
					bling[newrow][newcolumn]=1;
				}
				
				tGPIO_A->DOUT = act[0];
				u32row_temp=inpw(u32row);
				if((u32row_temp & 0x10) == 0) //左
				{
					if(column==0) newcolumn=3; 
					else if(column==3) newcolumn=2; 
					else if(column==2) newcolumn=1; 
					else if(column==1) newcolumn=0; 
					
					if(visit[newrow][newcolumn]==0) visit[newrow][newcolumn]=1;
					else if(visit[newrow][newcolumn]==1) visit[newrow][newcolumn]=0;
					
					push=1;
					
					for(i=0;i<3;i++)
						for(j=0;j<4;j++)
								bling[i][j]=0;
					bling[newrow][newcolumn]=1;
				}
				
				tGPIO_A->DOUT = act[2];
				u32row_temp=inpw(u32row);
				if((u32row_temp&0x10) == 0) //右
				{
					if(column==0) newcolumn=1; 
					else if(column==1) newcolumn=2; 
					else if(column==2) newcolumn=3; 
					else if(column==3) newcolumn=0; 
					newrow = row;
					if(visit[newrow][newcolumn]==0) visit[newrow][newcolumn]=1;
					else if(visit[newrow][newcolumn]==1) visit[newrow][newcolumn]=0;
					
					push=1;
					
					for(i=0;i<3;i++)
						for(j=0;j<4;j++)
								bling[i][j]=0;
					bling[newrow][newcolumn]=1;
				}
				
				for(i=0;i<3;i++)
				{	for(j=0;j<4;j++)
					{
							if(bling[i][j]==1)
							{	
								if(flag==0)
								{
									tGPIO_C->DOUT = 0Xff00;
									tGPIO_E->DOUT = print_row[i];
									tGPIO_C->DOUT = print_column[j];
									DrvSYS_Delay(2000);
								}	
								else if(flag==1)
								{
									tGPIO_E->DOUT = print_row[i];
									tGPIO_C->DOUT = 0Xff00;
									DrvSYS_Delay(2000);
								}	
							}
							
							else if(visit[i][j]==1)
							{
								tGPIO_E->DOUT = print_row[i];
								tGPIO_C->DOUT = print_column[j];
								
								DrvSYS_Delay(1500);
							}					
					}
				}	
				if(push==1)
				{
					DrvSYS_Delay(1000000); //防彈跳	
					push = 0;
					column = newcolumn;
					row = newrow;
				}
				
				count++;
				if(count%10==0)
						if(flag==1)
							flag=0;
						else 
							flag=1;
		}    
  
}
