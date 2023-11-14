#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;


void inpatient()//住院 
{
	int day,rate,sevice,medication,money,expense=0,ret;
	float insurance;
	char sevices[13];
	
	
	while(true) 
    {
    	printf("the number of days spent in the hospital:");//30以內 //31~60 //60以上 
    	ret=scanf("%d",&day);
    	if (ret == 1) break;
	    fflush(stdin);
    }
	if(day<30)
	   insurance=0.1;
	if(30<=day && day<=60)
	   insurance=0.2;
	if(day>60)
	   insurance=0.3;
	
	while(true)
    {
    	printf("the daily rate:");
    	ret=scanf("%d",&rate);
	    if (ret == 1) break;
	    fflush(stdin);
    }
	
	while(true)
    {
    	printf("charges for hospital services(Single room/Double room/Special ward):");//單人房Single room--2500//雙人房Double room--1200//特等病房Special ward--3900/天 
		                                                                               //服務費用包含在病房費內 
    	scanf("%s",sevices);
	    if(strncmp("si",sevices,2)==0 || strncmp("Si",sevices,2)==0 || strncmp("Do",sevices,1)==0 || strncmp("do",sevices,1)==0 || strncmp("Sp",sevices,2)==0 || strncmp("sp",sevices,2)==0) break; 
	    else continue;
    }
	if(strncmp("si",sevices,2)==0 || strncmp("Si",sevices,2)==0)
	   sevice=2500;
	if(strncmp("Do",sevices,1)==0 || strncmp("do",sevices,1)==0)
	   sevice=1200;
	if(strncmp("Sp",sevices,2)==0 || strncmp("sp",sevices,2)==0)
	   sevice=3900;      
	
	while(true)
    {
    	printf("hospital medication charges:");
    	ret=scanf("%d",&medication);
	    if (ret == 1) break;
	    fflush(stdin);
    }
	
	money=day*(200+sevice);//天數*(床位+服務+三餐)
	money=money+money*(rate%100)+medication;//+daily rate+ medication
	expense=money-money*insurance;
	
	printf("%d",expense+450);//住院費+掛號費 
	
	
}
void outpatient()//純看診 //掛號費250
{
	int sevices,medication,money,expense=0,ret;
	
	while(true)
    {
    	printf("charges for hospital services:");
    	ret=scanf("%d",&sevices);
	    if (ret == 1) break;
	    fflush(stdin);
    }
	
	while(true)
    {
    	printf("hospital medication charges:");//門診藥品部分負擔費用
    	ret=scanf("%d",&medication);
	    if (ret == 1) break;
	    fflush(stdin);
    }
	                                      //藥品費用   應自行負擔費用
    if(medication<=100)                   
       money=0;                           //100元以下	0元 
    if(100<medication && medication<=200)                   
       money=20;                          //101~200元	20元
    if(200<medication && medication<=300)                   
       money=40;                          //201~300元	40元
    if(300<medication && medication<=400)                   
       money=60;                          //301~400元	60元
    if(400<medication && medication<=500)                   
       money=80;                          //401~500元	80元
    if(500<medication && medication<=600)                   
       money=100;                         //501~600元	100元
    if(600<medication && medication<=700)                   
       money=120;                         //601~700元	120元
    if(700<medication && medication<=800)                   
       money=140;                         //701~800元	140元
    if(800<medication && medication<=900)                   
       money=160;                         //801~900元	160元
    if(900<medication && medication<=1000)                   
       money=180;                         //901~1000元	180元  
    if(1000<medication)                   
       money=200;                         //1000元以上	200元
       
    expense=sevices+money;  
                                          
    printf("%d",expense+250);                                       
	
	
}

int main()
{  
    
    char patient[11]={0};
	char in[3]="in",out[4]="out";
    
	while(true)
    {
    	printf("inpatient or outpatient?");
    	scanf("%s",patient);
	    if(strncmp(in,patient,2)==0 || strncmp(out,patient,3)==0) break; 
	    else continue;
    }
	
	if(strncmp(in,patient,2)==0) //住院 //掛號費450 //30天以內--健保給付10% //31~60--20% //61以上--30% 
	   inpatient();
	if(strncmp(out,patient,3)==0) //純看診//掛號費250 
	   outpatient();
	
}
