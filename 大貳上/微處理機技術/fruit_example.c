#include "NUC1xx.h"
#include "LCD_Driver.h"
#include "Driver/DrvGPIO.h"
#include "Driver/DrvSYS.h"
#include "stdlib.h"


volatile uint8_t new_x[100] = {0}, old_x[100] = {0}; 
int score = 0;

unsigned char DisplayBuf [8*128];
extern  SPI_T * SPI_PORT[4]={SPI0, SPI3, SPI2, SPI3};
	
	unsigned char numabc[16][8] = {{0x00,0x7e,0xff,0xc3,0xc3,0xff,0x7e,0x00},
																{0x00,0x00,0xc4,0xc6,0xff,0xff,0xc0,0x00},
																{0x00,0xe6,0xf3,0xfb,0xcb,0xcf,0xce,0x00},
																{0x00,0xdb,0xdb,0xdb,0x99,0xff,0xff,0x00},
																{0x00,0x1c,0x1e,0x1b,0xff,0xff,0x18,0x00},
																{0x00,0x00,0xcf,0xcf,0xc9,0xf9,0xf9,0x00},
																{0x00,0x00,0xff,0xd3,0xd3,0xd3,0xf3,0x00},
																{0x00,0x00,0x07,0x03,0x03,0xff,0xff,0x00},
																{0x00,0x00,0xff,0xdd,0xdd,0xdd,0xff,0x00},
																{0x00,0x00,0xcf,0xc9,0xc9,0xff,0xff,0x00},
																{0x00,0xe0,0xfc,0x1f,0x13,0x1f,0xfc,0xe0},
																{0x00,0x00,0xff,0xff,0xc9,0xc9,0xff,0x00},
																{0x00,0x00,0xff,0xff,0xc3,0xc3,0xc3,0x00},
																{0x00,0x00,0xff,0xff,0xc3,0xc3,0x7e,0x00},
																{0x00,0x00,0xff,0xff,0xdb,0xdb,0xdb,0x00},
																{0x00,0x00,0xff,0xff,0x1b,0x1b,0x1b,0x00}};
																
	int act[3] = {0xfffb, 0xfffd, 0xfffe}; //row
	int l = 1;
	int terminated[100] = {0};

	uint8_t y, loc, plateloc = 56, platelocend = 76;
	GPIO_T * tGPIO_A, * tGPIO_C, * tGPIO_E;
	uint32_t u32Reg;  
	uint32_t u32Reg_temp;
	int begin = 0, end = 0, left = 0, right = 0, init = 0;
	int i, x, z, clear = 0, flag = 0;

	int randomnum[100] = {115, 46, 106, 88, 36, 121, 71, 69, 48, 25,
												82, 36, 70, 71, 32, 105, 74, 100, 44, 69,
												41, 52, 30, 46, 61, 93, 117, 51, 50, 106,
												32, 93, 82, 81, 27, 103, 62, 45, 61, 34,
												54, 88, 101, 46, 35, 65, 75, 50, 90, 105,
												88, 36, 102, 43, 84, 67, 30, 56, 105, 85,
												75, 78, 55, 23, 34, 33, 66, 68, 64, 53,
												49, 92, 106, 24, 29, 72, 98, 43, 64, 38,
												49, 59, 35, 99, 81, 91, 42, 16, 47, 22,
												74, 99, 34, 31, 90, 70, 72, 86, 62, 35};
												
	int fruitPattern[70] = {1, 2, 3, 2, 2, 4, 3, 3, 1, 3, 
												3, 2, 3, 1, 4, 3, 3, 2, 1, 4,
												3, 4, 2, 4, 1, 2 ,2 ,4 ,1, 3,
												3, 2, 1, 2, 2, 4, 1, 3, 1, 1,
												3, 1, 1, 2, 4, 1, 3, 1, 1, 3,
												2, 1, 2, 1, 2, 3, 4, 3, 2, 4,
												4, 3, 2, 4, 4, 1, 3 ,4, 4, 3};										
	int pattern[500] = {1, 2, 0, 0, 0, 3, 0, 2, 0, 0,
											0, 2, 0, 0, 0, 4, 0, 3, 0, 3,
											1, 0, 3, 0, 0, 0, 0, 0, 0, 3,
											0, 2, 0, 3, 0, 1, 0, 4, 0, 3,
											0, 0, 3, 0, 0, 0, 2, 1, 4, 3,
											0, 4, 2, 0, 4, 0, 0, 1, 0, 2,
											2, 4, 1, 3, 0, 3, 0, 0, 2, 1,
											2, 2, 4, 1, 0, 0, 3, 1, 0, 1,
											4, 1, 1, 0, 0, 0, 2, 1, 1, 3,
											4, 1, 3, 2, 0, 1, 2, 1, 2, 0,
											3, 4, 0, 0, 3, 0, 0, 2, 4, 0,
											0, 3, 2, 4, 0, 4, 0, 0, 0, 1,
											3, 0, 4, 4, 3, 4, 0, 0, 3, 3,
											1, 3, 0, 4, 1, 0, 0, 1, 4, 0,
											4, 3, 3, 1, 0, 1, 4, 4, 1, 0,
											1, 3, 0, 2, 2, 3, 1, 2, 1, 2,
											1, 1, 1, 2, 2, 3, 0, 2, 4, 3,
											2, 0, 4, 4, 4, 2, 1, 2, 4, 2,
											3, 2, 3, 2, 1, 4, 4, 1, 2, 3,
											0, 1, 1, 1, 0, 2, 1, 2, 1, 2,
											0, 4, 3, 1, 2, 4, 4, 4, 4, 1,
											0, 1, 1, 0, 0, 4, 1, 4, 3, 0,
											2, 1, 1, 0, 1, 0, 3, 1, 2, 2,
											2, 2, 1, 1, 4, 4, 3, 3, 0, 3,
											2, 2, 3, 1, 0, 2, 3, 1, 3, 0,
											2, 1, 2, 2, 1, 0, 1, 0, 3, 0,
											4, 3, 0, 2, 0, 1, 1, 1, 0, 4,
											4, 1, 4, 0, 2, 2, 4, 4, 3, 0,
											4, 1, 2, 4, 3, 4, 3, 0, 4, 1,
											3, 0, 4, 2, 3, 3, 2, 3, 1, 4,
											0, 2, 0, 1, 0, 0, 3, 3, 1, 1,
											3, 0, 2, 0, 3, 1, 2, 1, 2, 0,
											3, 4, 4, 2, 2, 4, 4, 0, 2, 4,
											0, 3, 0, 0, 0, 0, 1, 0, 0, 1,
											4, 1, 0, 0, 3, 3, 0, 2, 0, 2,
											2, 1, 4, 0, 4, 1, 3, 1, 4, 1,
											2, 2, 4, 3, 3, 1, 4, 4, 4, 2,
											0, 4, 0, 0, 0, 1, 1, 4, 0, 0,
											1, 1, 2, 1, 0, 3, 0, 1, 3, 4,
											1, 1, 3, 3, 4, 0, 0, 0, 2, 1,
											4, 0, 3, 0, 3, 1, 1, 1, 2, 2,
											3, 4, 3, 2, 2, 4, 4, 1, 1, 1,
											4, 2, 3, 1, 4, 1, 1, 2, 2, 3,
											1, 3, 0, 4, 1, 0, 3, 0, 1, 2,
											0, 2, 1, 3, 2, 3, 2, 0, 1, 3,
											1, 0, 2, 1, 1, 3, 3, 1, 3, 4,
											2, 1, 4, 2, 1, 1, 0, 4, 3, 4,
											1, 0, 1, 4, 2, 2, 1, 1, 2, 0,
											3, 4, 3, 3, 2, 0, 4, 0, 2, 1,
											0, 1, 4, 2, 2, 3, 3, 1, 1, 2};
											
	int sevennum[10]={0x82, 0xee, 0x07, 0x46, 0x6a, 0x52, 0x12, 0xe2, 0x02, 0x42};
	int sevenpos[2] = {0xff20, 0xff10};
	int fruit[4][8] = {{0x30, 0x70, 0xf8, 0xfc, 0xff, 0xfd, 0x70, 0x30},
										{0x03, 0x03, 0x1f, 0x3f, 0x73, 0xc3, 0xc0, 0xc0},
										{0x0c, 0x1c, 0x3c, 0x7c, 0x7c, 0x3c, 0x1c, 0x0c},
										{0x00, 0x05, 0x22, 0x75, 0xf8, 0xf8, 0x70, 0x20}};
	int appear[500] = {0};
	int time = 30, timeten, timeone, count = 0;
	int scoreten = 0, scoreone = 0;
void Initial_Lcd()
{
		uint8_t x, y;
		SYSCLK->APBCLK.SPI3_EN  =1;			 //enable spi function 
		SYS->IPRSTC2.SPI3_RST   =1;			 //reset spi function
		SYS->IPRSTC2.SPI3_RST   =0;

		/* set GPIO to SPI mode*/
		SYS->GPDMFP.SPI3_SS0 	=1;
		SYS->GPDMFP.SPI3_CLK 	=1;
		//SYS->GPDMFP.SPI3_MISO0 	=1;
		SYS->GPDMFP.SPI3_MOSI0 	=1;

		SPI_PORT[3]->CNTRL.CLKP = 1;							//CLKP HIGH IDLE
		SPI_PORT[3]->CNTRL.TX_BIT_LEN = 9;						//TX LEGTH 9
		SPI_PORT[3]->CNTRL.TX_NEG = 1;							//SET TX_NEG
		SPI_PORT[3]->DIVIDER.DIVIDER=0X03;					    //SET DIV

		SPI_PORT[3]->SSR.SSR=1;									//ENABLE SLAVE SELECT
		// Set BR
		SPI_PORT[3]->TX[0] =0xEB;
		SPI_PORT[3]->CNTRL.GO_BUSY = 1;
			while ( SPI_PORT[3]->CNTRL.GO_BUSY == 1 );
		// Set PM
		SPI_PORT[3]->SSR.SSR=0;

		SPI_PORT[3]->SSR.SSR=1;
		//outp32(SPI3_Tx0, 0x81);	
		SPI_PORT[3]->TX[0] =0x81;
		SPI_PORT[3]->CNTRL.GO_BUSY = 1;
			while ( SPI_PORT[3]->CNTRL.GO_BUSY == 1 );
		SPI_PORT[3]->TX[0] =0xa0;
		SPI_PORT[3]->CNTRL.GO_BUSY = 1;
			while ( SPI_PORT[3]->CNTRL.GO_BUSY == 1 );
		SPI_PORT[3]->SSR.SSR=0;

		SPI_PORT[3]->SSR.SSR=1;
		//outp32(SPI3_Tx0, 0xC0);
		SPI_PORT[3]->TX[0] =0xc0;	
		SPI_PORT[3]->CNTRL.GO_BUSY = 1;
			while ( SPI_PORT[3]->CNTRL.GO_BUSY == 1 );
		// Set Display Enable
		SPI_PORT[3]->SSR.SSR=0;

		SPI_PORT[3]->SSR.SSR=1;
		SPI_PORT[3]->TX[0] = 0XAF;
		SPI_PORT[3]->CNTRL.GO_BUSY = 1;
			while ( SPI_PORT[3]->CNTRL.GO_BUSY == 1 );
		for (y=0; y< 128; y++) 
		{
			for (x=0; x< 8; x++) 
			{
					SPI_PORT[3]->TX[0] = 0xB0 | x;	
					SPI_PORT[3]->CNTRL.GO_BUSY = 1;
						while ( SPI_PORT[3]->CNTRL.GO_BUSY == 1 );	 //check data out?

						
					//cloumn MSB
					SPI_PORT[3]->TX[0] =0x10 |((129-y)>>4)&0xF;
					SPI_PORT[3]->CNTRL.GO_BUSY = 1;
						while ( SPI_PORT[3]->CNTRL.GO_BUSY == 1 );	  //check data out?
							
							
					// cloumn LSB
					SPI_PORT[3]->TX[0] =0x00 | ((129-y) & 0xF);		
					SPI_PORT[3]->CNTRL.GO_BUSY = 1;
						while ( SPI_PORT[3]->CNTRL.GO_BUSY == 1 );	  //check data out?
							
					// Write Data
					//SPI_PORT[3]->SSR.SSR=1;	   //chip select
					SPI_PORT[3]->TX[0] =0x100 | 0;    	//write data
					SPI_PORT[3]->CNTRL.GO_BUSY = 1;
						while ( SPI_PORT[3]->CNTRL.GO_BUSY == 1 ); //check data out?
			}
		}
}


void draw(uint8_t x, uint8_t y, unsigned char data)
{
	SPI_PORT[3]->TX[0] = 0xB0 | x;
	SPI_PORT[3]->CNTRL.GO_BUSY = 1;
	while ( SPI_PORT[3]->CNTRL.GO_BUSY == 1 ); //check data out

	//cloumn MSB
	SPI_PORT[3]->TX[0] =0x10 |((129-y)>>4)&0xF;
	SPI_PORT[3]->CNTRL.GO_BUSY = 1;
	while ( SPI_PORT[3]->CNTRL.GO_BUSY == 1 );  //check data out

	// cloumn LSB
	SPI_PORT[3]->TX[0] =0x00 | ((129-y) & 0xF);
	SPI_PORT[3]->CNTRL.GO_BUSY = 1;
	while ( SPI_PORT[3]->CNTRL.GO_BUSY == 1 );  //check data out

	// Write Data
	SPI_PORT[3]->TX[0] =0x100 | data;    //write data
	SPI_PORT[3]->CNTRL.GO_BUSY = 1;
	while ( SPI_PORT[3]->CNTRL.GO_BUSY == 1 ); //check data out
}




void InitTIMER0(void)
{
	/* Step 1. Enable and Select Timer clock source */          
	SYSCLK->CLKSEL1.TMR0_S = 0;	//Select 12Mhz for Timer0 clock source 
    	SYSCLK->APBCLK.TMR0_EN =1;	//Enable Timer0 clock source

	/* Step 2. Select Operation mode */	
	TIMER0->TCSR.MODE=1;	//Select periodic mode for operation mode

	/* Step 3. Select Time out period = (Period of timer clock input) * (8-bit Prescale + 1) * (24-bit TCMP)*/
	TIMER0->TCSR.PRESCALE=255;	// Set Prescale [0~255]
	TIMER0->TCMPR = 13825;	// Set TCMPR [0~16777215] //27650
				

	/* Step 4. Enable interrupt */
	TIMER0->TCSR.IE = 1;
	NVIC_EnableIRQ(TMR0_IRQn);	//Enable Timer0 Interrupt

	/* Step 5. Enable Timer module */
	TIMER0->TCSR.CRST = 1;	//Reset up counter
	TIMER0->TCSR.CEN = 1;	//Enable Timer0

  	//TIMER0->TCSR.TDR_EN=1;	// Enable TDR function
}

void TMR0_IRQHandler() // Timer0 interrupt subroutine 
{	
	int i;
	static int k = 0;
	if(k % 4 == 0)
		time--;
	for(i = 0 ; i < l ; i ++)
	{

					if(old_x[i] < 7 && terminated[i] == 0)
					{
						old_x[i] = new_x[i];
						new_x[i] =(old_x[i] + 1) ;
					}
					else if(old_x[i] == 7 || new_x[i] == 7)
					{
						terminated[i] = 1;
					}
			
			if(appear[i] == 0)
			{
				if(pattern[k] != 0)
				{
					appear[i] = 1;
					l++;
				}
				k++;
				break;
			}
		}
	

	TIMER0->TISR.TIF =1; 	
}

int32_t main (void)
{


	tGPIO_A = (GPIO_T *)((uint32_t)GPIOA + (0*0x40));
	tGPIO_C = (GPIO_T *)((uint32_t)GPIOA + (2*0x40)); 
	tGPIO_E = (GPIO_T *)((uint32_t)GPIOA + (4*0x40));
	u32Reg = (uint32_t)&GPIOA->PIN + (0*0x40);

	while(1)
	{
		tGPIO_A -> DOUT = act[0];
		u32Reg_temp = inpw(u32Reg);
		if((u32Reg_temp & 0x08) == 0)	//start
		{
			DrvSYS_Delay(10000000);
			begin = 1;
			init = 1;
		}
		if(init == 1)
		{
			UNLOCKREG();
			SYSCLK->PWRCON.XTL12M_EN = 1;	//啟動12MHZ的時脈計數器
			LOCKREG();
			InitTIMER0();	
			Initial_Lcd();	
			init = 0;
		}

		while (begin == 1 && end == 0)
		{	
			if(time == 0)
			{
				end = 1;
				clear = 1;
				break;
			}
			tGPIO_A -> DOUT = act[0];
			u32Reg_temp = inpw(u32Reg);
			if((u32Reg_temp & 0x10) == 0)	//left
			{
				DrvSYS_Delay(100000);
				left = 1;
			}
			
			tGPIO_A -> DOUT = act[2];
			u32Reg_temp = inpw(u32Reg);
			if((u32Reg_temp & 0x10) == 0)	//right
			{
				DrvSYS_Delay(100000);
				right = 1;
			}
			////////
			
			tGPIO_A -> DOUT = act[2];
			if((u32Reg_temp & 0x08) == 0)	//end
			{
				DrvSYS_Delay(1000000000);
				end = 1;
				clear = 1;
				break;
			}
			
			////////
			if(left == 1)
			{
				if(plateloc > 22)
				{
					platelocend -= 2;
					plateloc -= 2;
				}
				left = 0;
			}
			else if(right == 1)
			{
				if(platelocend < 125)
				{
					platelocend += 2;
					plateloc +=2;
				}
				right = 0;
			}
		
			
			for (y = plateloc - 2 ; y <= platelocend + 2 ; y ++) 
			{
				if(y < plateloc)
					draw(6, y, 0x00);
				else if(y > platelocend)
					draw(6, y, 0x00);
				else
					draw(6, y, 0x30);
			}
			////////fruit
			for(i = 0 ; i < l ; i ++)
			{
				if(terminated[i] == 1)
					continue;
				if(terminated[i] == 0)
				{
					loc = randomnum[i];
					
					for (y = loc; y < loc + 8; y ++) 
					{
						draw(old_x[i], y, 0);
						draw(new_x[i], y, fruit[fruitPattern[i]-1][y-loc]);
					}

				}
				
				if( new_x[i] == 6)
				{
					for(y = plateloc ; y <= platelocend ; y ++)
					{
						for(z = loc ; z < loc + 8 ; z++)
						{
							if(loc == y)
							{
								if(fruitPattern[i] == 1)
									score ++;
								else if(fruitPattern[i] == 2)
									score += 2;
								else if(fruitPattern[i] == 3)
									score += 5;
								else
								{
									score -= 10;
									if(score < 0)
										score = 0;
								}
							terminated[i] = 1;
							break;
							}
						}
						if(terminated[i] == 1)
							break;
					}
				}
				
				if(terminated[i] == 1)
				{
					for (y = loc; y < loc + 8; y ++) 
					{
						draw(old_x[i], y, 0x00);
						draw(new_x[i], y, 0x00);
					}
				}
			}
			timeten = time / 10;
			timeone = time % 10;
			for (y = 2; y < 10; y ++) 
			{
				draw(3, y, numabc[timeten][y-2]);
			}	

			for (y = 11; y < 19; y ++) 
			{
				draw(3, y, numabc[timeone][y-11]);
			}
			
			scoreten = score / 10;
			scoreone = score % 10;
			for (y = 2; y < 10; y ++) 
			{
				draw(1, y, numabc[scoreten][y-2]);
			}	

			for (y = 11; y < 19; y ++) 
			{
				draw(1, y, numabc[scoreone][y-11]);
			}
	
		}
		if(clear == 1)
		{
			for(x = 0 ; x <= 7 ; x ++)
			{
				for(y = 2 ; y <= 129 ; y ++)
					draw(x, y, 0x00);
			}
			clear = 0;
		}
		while(end == 1)
		{
			

			if(flag == 1)
			{
				for(i = 0 ; i < 300 ; i ++)
				{
					tGPIO_E -> DOUT = sevennum[scoreten];
					tGPIO_C -> DOUT = sevenpos[0];
					DrvSYS_Delay(300);
					tGPIO_C -> DOUT = 0xff00;
					tGPIO_E -> DOUT = sevennum[scoreone];
					tGPIO_C -> DOUT = sevenpos[1];
					DrvSYS_Delay(300);
					tGPIO_C -> DOUT = 0xff00;
				}
			}
			else
			{
				for(i = 0 ; i < 100 ; i ++)
				{
					tGPIO_E -> DOUT = 0xff;
					tGPIO_C -> DOUT = sevenpos[0];
					DrvSYS_Delay(100);
					tGPIO_C -> DOUT = 0xff00;
					tGPIO_E -> DOUT = 0xff;
					tGPIO_C -> DOUT = sevenpos[1];
					DrvSYS_Delay(100);
					tGPIO_C -> DOUT = 0xff00;
				}
			}
			count++;
			if(count == 5)
			{
				count = 0;
				if(flag == 1)
					flag = 0;
				else
					flag = 1;
			}
		}
	}

}
