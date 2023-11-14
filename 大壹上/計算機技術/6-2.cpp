#include <stdio.h>
#include <stdlib.h>

int main()
{
	int code[26]={10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
	char input[11];
	int d1,d2,d3,d4,d5,d6,d7,d8,d9,a1,a2,y,a;
	
	printf("請輸入身份證字號:");
	scanf("%s",input);
	
	d1=(int)input[1]-48;
	d2=(int)input[2]-48;
	d3=(int)input[3]-48;
	d4=(int)input[4]-48;
	d5=(int)input[5]-48;
	d6=(int)input[6]-48;
	d7=(int)input[7]-48;
	d8=(int)input[8]-48;
	d9=(int)input[9]-48;
	a1=(int)input[0]/10;
	a2=(int)input[0]%10;
	
	y=a1+a2*9+d1*8+d2*7+d3*6+d4*5+d5*4+d6*3+7*2+8*1;
	
	a=10-(y%10);
	
	if(a==d9 || d9==0)
	 printf("\n身份證字號正確");
	 
	else 
	 printf("\n身份證字號錯誤");
}
