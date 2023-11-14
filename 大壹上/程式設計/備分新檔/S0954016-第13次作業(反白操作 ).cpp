#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
	
	BITMAPFILEHEADER FileHeader;    //�ŧiBMP�ɮ׼��Y
    BITMAPINFOHEADER InfoHeader;    //�ŧiBMP��T���Y
    
	FILE *fp;                       //Ū���ɮ�FILE
    FILE *fpw;                      //�g�J�ɮ�FILE
    fp=fopen("lena.bmp", "rb");                   
    fpw=fopen("�@�~13��X.bmp", "wb");
    
	fread(&FileHeader, sizeof(BITMAPFILEHEADER), 1, fp);    //1.�}�Cor���c������ 2.�}�Cor���c���j�p
    fread(&InfoHeader, sizeof(BITMAPINFOHEADER), 1, fp);    //3.�}�C�������ƶq�A�p�G�O���c�N���P 1 �Ӱ}�C���� 4.���V���c FILE ������
   
    int ImageX, ImageY;             //���ɤ��e�e��
    ImageX = InfoHeader.biWidth;        // ���o�e��
    ImageY = InfoHeader.biHeight;
    
    int color[512][512],rgb;
    
    for(int i=0; i<ImageY; i++ )        //�v�C���y
    {
        for(int j=0; j<ImageX; j++ )    //�v�汽�y
        {
          fread(&rgb, sizeof(RGBTRIPLE), 1, fp);        //�N�C�檺pixel BGR �g�J color matrix ��
          color[i][j]=rgb;
          
        }
    }
    fclose(fp);     //�ɮ�fpŪ�������A����
    
    
    fwrite(&FileHeader, sizeof(BITMAPFILEHEADER), 1, fpw); //��X�ɮ�
    fwrite(&InfoHeader, sizeof(BITMAPINFOHEADER), 1, fpw);

    for(int i=0; i<ImageY; i++ )        //�v�C���y
    {
        for(int j=0; j<ImageX; j++ )    //�v�汽�y
        {
            rgb=225-color[i][j];
            fwrite(&rgb, sizeof(RGBTRIPLE), 1, fpw);        // �N color matrix �g�J��X���ɤ�
        }
    }
	fclose(fpw);

    return 0;


}
