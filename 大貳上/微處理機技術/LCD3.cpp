unsigned char DisplayBuf [8*128];
extern  SPI_T * SPI_PORT[4]={SPI0, SPI3, SPI2, SPI3};

	unsigned char one[]=  {0x00,0x00,0xc4,0xc6,0xff,0xff,0xc0,0x00};
	unsigned char two[]=  {0x00,0xe6,0xf3,0xfb,0xcb,0xcf,0xce,0x00};
	unsigned char three[]={0x00,0xdb,0xdb,0xdb,0x99,0xff,0xff,0x00};
	unsigned char four[]= {0x00,0x1c,0x1e,0x1b,0xff,0xff,0x18,0x00};
	unsigned char five[]= {0x00,0x00,0xcf,0xcf,0xc9,0xf9,0xf9,0x00};
	unsigned char six[]=  {0x00,0x00,0xff,0xd3,0xd3,0xd3,0xf3,0x00};
	unsigned char seven[]={0x00,0x00,0x07,0x03,0x03,0xff,0xff,0x00};
	unsigned char eight[]={0x00,0x00,0xff,0xdd,0xdd,0xdd,0xff,0x00};
	unsigned char nine[]= {0x00,0x00,0xcf,0xc9,0xc9,0xff,0xff,0x00};
	unsigned char zero[]= {0x00,0x7e,0xff,0xc3,0xc3,0xff,0x7e,0x00};
	unsigned char A[]= {0x00,0xe0,0xfc,0x1f,0x13,0x1f,0xfc,0xe0};
	unsigned char B[]= {0x00,0x00,0xff,0xff,0xc9,0xc9,0xff,0x00};
	unsigned char C[]= {0x00,0x00,0xff,0xff,0xc3,0xc3,0xc3,0x00};
	unsigned char D[]= {0x00,0x00,0xff,0xff,0xc3,0xc3,0x7e,0x00};
	unsigned char E[]= {0x00,0x00,0xff,0xff,0xdb,0xdb,0xdb,0x00};
	unsigned char F[]= {0x00,0x00,0xff,0xff,0x1b,0x1b,0x1b,0x00};
	unsigned char plus[] = {0x00, 0x18, 0x18, 0x7e, 0x7e, 0x18, 0x18, 0x00};

	
	unsigned char numabc[16][8] = { {0x00,0x7e,0xff,0xc3,0xc3,0xff,0x7e,0x00},//0 
									{0x00,0x00,0xc4,0xc6,0xff,0xff,0xc0,0x00},//1 
									{0x00,0xe6,0xf3,0xfb,0xcb,0xcf,0xce,0x00},//2 
									{0x00,0xdb,0xdb,0xdb,0x99,0xff,0xff,0x00},//3 
									{0x00,0x1c,0x1e,0x1b,0xff,0xff,0x18,0x00},//4 
									{0x00,0x00,0xcf,0xcf,0xc9,0xf9,0xf9,0x00},//5 
									{0x00,0x00,0xff,0xd3,0xd3,0xd3,0xf3,0x00},//6 
									{0x00,0x00,0x07,0x03,0x03,0xff,0xff,0x00},//7 
									{0x00,0x00,0xff,0xdd,0xdd,0xdd,0xff,0x00},//8 
									{0x00,0x00,0xcf,0xc9,0xc9,0xff,0xff,0x00},//9 
									{0x00,0xe0,0xfc,0x1f,0x13,0x1f,0xfc,0xe0},//A 
									{0x00,0x00,0xff,0xff,0xc9,0xc9,0xff,0x00},//B 
									{0x00,0x00,0xff,0xff,0xc3,0xc3,0xc3,0x00},//C
									{0x00,0x00,0xff,0xff,0xc3,0xc3,0x7e,0x00},//D
									{0x00,0x00,0xff,0xff,0xdb,0xdb,0xdb,0x00},//E
									{0x00,0x00,0xff,0xff,0x1b,0x1b,0x1b,0x00}};//F
																
	int act[3] = {0xfffb, 0xfffd, 0xfffe}; 
	uint8_t y, loc;
	GPIO_T * tGPIO_A, * tGPIO_C, * tGPIO_E;
	uint32_t u32Reg;  
	uint32_t u32Reg_temp;
	uint8_t num1,num2,result;
	uint8_t loc;
	uint8_t y;
	int first = 0,second = 0;
	int tens=0, ones=0;
	
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


int32_t main (void)
{
	tGPIO_A = (GPIO_T *)((uint32_t)GPIOA + (0*0x40));
	tGPIO_C = (GPIO_T *)((uint32_t)GPIOA + (2*0x40)); 
	tGPIO_E = (GPIO_T *)((uint32_t)GPIOA + (4*0x40));
	u32Reg = (uint32_t)&GPIOA->PIN + (0*0x40);

	while(1)
	{
		Initial_Lcd();
		DrvSYS_Delay(100000000);
		
		if(first == 0)
		{
		
			tGPIO_A -> DOUT = act[0];
			u32Reg_temp = inpw(u32Reg);
			if((u32Reg_temp & 0x08) == 0)
			{
				DrvSYS_Delay(1000000000);
				num1 = 1;
				first = 1;
			}		
			else if((u32Reg_temp & 0x10) == 0)
			{
				DrvSYS_Delay(1000000000);
				num1 = 4;
				first = 1;					
			}
			else if((u32Reg_temp & 0x20) == 0)
			{
				DrvSYS_Delay(1000000000);
				num1 = 7;	
				first = 1;
			}	
			tGPIO_A -> DOUT = act[1];
			u32Reg_temp = inpw(u32Reg);
			if((u32Reg_temp & 0x08) == 0 )
			{
				DrvSYS_Delay(1000000000);
				num1 = 2;
				first = 1;
			}		
			else if((u32Reg_temp & 0x10) == 0 )
			{
				DrvSYS_Delay(1000000000);
				num1 = 5;	
				first = 1;					
			}
			else if((u32Reg_temp & 0x20) == 0 )
			{
				DrvSYS_Delay(1000000000);
				num1 = 8;	
				first = 1;					
			}	
			tGPIO_A -> DOUT = act[2];
			u32Reg_temp = inpw(u32Reg);
			if((u32Reg_temp & 0x08) == 0 )
			{
				DrvSYS_Delay(1000000000);
				num1 = 3;
				first = 1;
			}		
			else if((u32Reg_temp & 0x10) == 0 )
			{
				DrvSYS_Delay(1000000000);
				num1 = 6;	
				first = 1;					
			}
			else if((u32Reg_temp & 0x20) == 0 )
			{
				DrvSYS_Delay(1000000000);
				num1 = 9;
				first = 1;
			}
			
			loc = 80;
			for (y = loc ; y < loc + 8 ; y ++)  
				draw(2, y, numabc[num1][y-loc]);
		}
		if(first == 1 && second == 0)
		{
			
			DrvSYS_Delay(10000000);
			tGPIO_A -> DOUT = act[0];
			u32Reg_temp = inpw(u32Reg);
			if((u32Reg_temp & 0x08) == 0)
			{
				DrvSYS_Delay(1000000000);
				num2 = 1;
				second = 1;
			}				
			else if((u32Reg_temp & 0x10) == 0)
			{
				DrvSYS_Delay(1000000000);
				num2 = 4;		
				second = 1;					
			}
			else if((u32Reg_temp & 0x20) == 0)
			{
				DrvSYS_Delay(1000000000);
				num2 = 7;	
				second = 1;					
			}			
			tGPIO_A -> DOUT = act[1];
			u32Reg_temp = inpw(u32Reg);
			if((u32Reg_temp & 0x08) == 0 )
			{
				DrvSYS_Delay(1000000000);
				num2 = 2;
				second = 1;
			}				
			else if((u32Reg_temp & 0x10) == 0 )
			{
				DrvSYS_Delay(1000000000);
				num2 = 5;
				second = 1;					
			}
			else if((u32Reg_temp & 0x20) == 0 )
			{
				DrvSYS_Delay(1000000000);
				num2 = 8;	
				second = 1;					
			}
			tGPIO_A -> DOUT = act[2];
			u32Reg_temp = inpw(u32Reg);
			if((u32Reg_temp & 0x08) == 0 )
			{
				DrvSYS_Delay(1000000000);
				num2 = 3;
				second = 1;
			}	
			else if((u32Reg_temp & 0x10) == 0 )
			{
				DrvSYS_Delay(1000000000);
				num2 = 6;		
				second = 1;					
			}
			else if((u32Reg_temp & 0x20) == 0 )
			{
				DrvSYS_Delay(1000000000);
				num2 = 9;	
				second = 1;					
			}	
			
			loc = 80;
			for (y = loc ; y < loc + 8 ; y ++)   	
				draw(4, y, numabc[num2][y-loc]);	
		}
		
		loc = 10;
		for (y = loc ; y < loc + 8 ; y ++)   	
			draw(1, y, numabc[1][y-loc]);
		loc = 19;
		for (y = loc ; y < loc + 8 ; y ++)   	
			draw(1, y, numabc[0][y-loc]);

		result = num1 + num2;
							
		loc = 50;
		for (y = loc ; y < loc + 8 ; y ++)   	
			draw(4, y, plus[y-loc]);	
		for (y = loc ; y < 89 ; y++)
			draw(5, y, 0x18);
			
		tens = result / 16;
		if(tens > 0)
		{
			loc = 65;
			for (y = loc ; y < loc + 8 ; y ++)   	
				draw(6, y, numabc[tens][y-loc]);
		}			
									
		ones = result % 16;
		loc = 80;
		for (y = loc ; y < loc + 8 ; y ++)   	
			draw(6, y, numabc[ones][y-loc]);	
	
	}
}	
