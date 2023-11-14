#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<math.h> 

int main()
{
	int i,j,number[5];

	
	printf("請輸入介於1~3999之間的阿拉伯數字:");
	scanf("%d",&i);
	
	printf("轉換羅馬數字為");
	
	number[0]=i%10000-i%1000;
	if(number[0]==1000)
	    printf("M");   
	else if(number[0]==2000)
	    printf("MM");    
	else if(number[0]==3000)
	    printf("MMM");
	
	number[1]=i%1000-i%100;
    if(number[1]==100)
	    printf("C");
	else if(number[1]==200)
	    printf("CC"); 
	else if(number[1]==300)
	    printf("CCC");  
	else if(number[1]==400)
	    printf("CD"); 
	else if(number[1]==500)
	    printf("D");  
	else if(number[1]==600)
	    printf("DC");
	else if(number[1]==700)
	    printf("DCC");
	else if(number[1]==800)
	    printf("DCCC");
	else if(number[1]==900)
	    printf("CM");							    
	
	number[2]=i%100-i%10; 
	if(number[2]==10)
	    printf("X");
	else if(number[2]==20)
	    printf("XX");
	else if(number[2]==30)
	    printf("XXX");
	else if(number[2]==40)
	    printf("XL");
	else if(number[2]==50)
	    printf("L");
	else if(number[2]==60)
	    printf("LX");
	else if(number[2]==70)
	    printf("LXX");
	else if(number[2]==80)
	    printf("LXXX");
	else if(number[2]==90)
	    printf("XC");    
	
	number[3]=i%10;
	if(number[3]==1)
	    printf("I");
	else if(number[3]==2)
	    printf("II");
	else if(number[3]==3)
	    printf("III");
	else if(number[3]==4)
	    printf("IV");
	else if(number[3]==5)
	    printf("V");
	else if(number[3]==6)
	    printf("VI");
	else if(number[3]==7)
	    printf("VII");
	else if(number[3]==8)
	    printf("VIII");
	else if(number[3]==9)
	    printf("IX");  

	
	
	
	
	
}
