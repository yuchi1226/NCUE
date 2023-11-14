//
// 單色LED燈，最右邊閃爍，其他燈暗的
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
    int patern_1[10] = {0x82,0xee,0x07,0x46,0x6a,0x52,0x12,0xe2,0x02,0x42};
    int patern_2[10] = {0x82,0xee,0x07,0x46,0x6a,0x52,0x12,0xe2,0x02,0x42};
    int index = 1, i, j;
    GPIO_T * tGPIO_C;
    GPIO_T * tGPIO_A;
    GPIO_T * tGPIO_E;
    tGPIO_C = (GPIO_T *)((uint32_t)GPIOA + (2*0x40));
    tGPIO_E = (GPIO_T *)((uint32_t)GPIOA + (4*0x40));
    tGPIO_A = (GPIO_T *)((uint32_t)GPIOA + (0*0x40));
    while(1)
    {
        /*for(i = 0; i < 500; i++)
        {
            DrvSYS_Delay(500);
            tGPIO_C->DOUT = 0x0000; //清空七段顯示器
            tGPIO_E->DOUT = patern_1[index % 10];
            tGPIO_C->DOUT = 0xff10; //個位數
            DrvSYS_Delay(500);

            tGPIO_C->DOUT = 0x0000; //清空七段顯示器
            tGPIO_E->DOUT = patern_2[index / 10];
            tGPIO_C->DOUT = 0xff20; //十位數
            DrvSYS_Delay(500);
        }*/
        for(j = 0; j < index; j++)
        {
            for(i = 0; i < 500; i++)
            {
                tGPIO_C->DOUT = 0x7000;
                tGPIO_A->DOUT = 0xB000;
                DrvSYS_Delay(500);
                tGPIO_C->DOUT = 0x0000; //清空七段顯示器
                tGPIO_E->DOUT = patern_1[index % 10];
                tGPIO_C->DOUT = 0xff10; //個位數
                DrvSYS_Delay(500);

                tGPIO_C->DOUT = 0x0000; //清空七段顯示器
                tGPIO_E->DOUT = patern_2[index / 10];
                tGPIO_C->DOUT = 0xff20; //十位數
                DrvSYS_Delay(500);
            }
        
            for(i = 0; i < 500; i++)
            {
                tGPIO_C->DOUT = 0xD000;
                tGPIO_A->DOUT = 0xD000;
                DrvSYS_Delay(500);
                tGPIO_C->DOUT = 0x0000; //清空七段顯示器
                tGPIO_E->DOUT = patern_1[index % 10];
                tGPIO_C->DOUT = 0xff10; //個位數
                DrvSYS_Delay(500);

                tGPIO_C->DOUT = 0x0000; //清空七段顯示器
                tGPIO_E->DOUT = patern_2[index / 10];
                tGPIO_C->DOUT = 0xff20; //十位數
                DrvSYS_Delay(500);
            }
        
            for(i = 0; i < 500; i++)
            {
                tGPIO_C->DOUT = 0xB000;
                tGPIO_A->DOUT = 0xE000;
                DrvSYS_Delay(500);
                tGPIO_C->DOUT = 0x0000; //清空七段顯示器
                tGPIO_E->DOUT = patern_1[index % 10];
                tGPIO_C->DOUT = 0xff10; //個位數
                DrvSYS_Delay(500);

                tGPIO_C->DOUT = 0x0000; //清空七段顯示器
                tGPIO_E->DOUT = patern_2[index / 10];
                tGPIO_C->DOUT = 0xff20; //十位數
                DrvSYS_Delay(500);
            }
        
            for(i = 0; i < 500; i++)
            {
                tGPIO_C->DOUT = 0xE000;
                tGPIO_A->DOUT = 0xD000;
                DrvSYS_Delay(500);
                tGPIO_C->DOUT = 0x0000; //清空七段顯示器
                tGPIO_E->DOUT = patern_1[index % 10];
                tGPIO_C->DOUT = 0xff10; //個位數
                DrvSYS_Delay(500);

                tGPIO_C->DOUT = 0x0000; //清空七段顯示器
                tGPIO_E->DOUT = patern_2[index / 10];
                tGPIO_C->DOUT = 0xff20; //十位數
                DrvSYS_Delay(500);
            }
        }
        index++;
    }
}