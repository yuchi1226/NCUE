#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
	
	BITMAPFILEHEADER FileHeader;    //宣告BMP檔案標頭
    BITMAPINFOHEADER InfoHeader;    //宣告BMP資訊標頭
    
	FILE *fp;                       //讀取檔案FILE
    FILE *fpw;                      //寫入檔案FILE
    fp=fopen("lena.bmp", "rb");                   
    fpw=fopen("作業13輸出.bmp", "wb");
    
	fread(&FileHeader, sizeof(BITMAPFILEHEADER), 1, fp);    //1.陣列or結構的指標 2.陣列or結構的大小
    fread(&InfoHeader, sizeof(BITMAPINFOHEADER), 1, fp);    //3.陣列的元素數量，如果是結構就等同 1 個陣列元素 4.指向結構 FILE 的指標
   
    int ImageX, ImageY;             //圖檔內容寬高
    ImageX = InfoHeader.biWidth;        // 取得寬高
    ImageY = InfoHeader.biHeight;
    
    int color[512][512],rgb;
    
    for(int i=0; i<ImageY; i++ )        //逐列掃描
    {
        for(int j=0; j<ImageX; j++ )    //逐行掃描
        {
          fread(&rgb, sizeof(RGBTRIPLE), 1, fp);        //將每格的pixel BGR 寫入 color matrix 中
          color[i][j]=rgb;
          
        }
    }
    fclose(fp);     //檔案fp讀取完成，關閉
    
    
    fwrite(&FileHeader, sizeof(BITMAPFILEHEADER), 1, fpw); //輸出檔案
    fwrite(&InfoHeader, sizeof(BITMAPINFOHEADER), 1, fpw);

    for(int i=0; i<ImageY; i++ )        //逐列掃描
    {
        for(int j=0; j<ImageX; j++ )    //逐行掃描
        {
            rgb=225-color[i][j];
            fwrite(&rgb, sizeof(RGBTRIPLE), 1, fpw);        // 將 color matrix 寫入輸出圖檔中
        }
    }
	fclose(fpw);

    return 0;


}
