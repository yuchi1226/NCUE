#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;


void inpatient()//��| 
{
	int day,rate,sevice,medication,money,expense=0,ret;
	float insurance;
	char sevices[13];
	
	
	while(true) 
    {
    	printf("the number of days spent in the hospital:");//30�H�� //31~60 //60�H�W 
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
    	printf("charges for hospital services(Single room/Double room/Special ward):");//��H��Single room--2500//���H��Double room--1200//�S���f��Special ward--3900/�� 
		                                                                               //�A�ȶO�Υ]�t�b�f�жO�� 
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
	
	money=day*(200+sevice);//�Ѽ�*(�ɦ�+�A��+�T�\)
	money=money+money*(rate%100)+medication;//+daily rate+ medication
	expense=money-money*insurance;
	
	printf("%d",expense+450);//��|�O+�����O 
	
	
}
void outpatient()//�¬ݶE //�����O250
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
    	printf("hospital medication charges:");//���E�ī~�����t��O��
    	ret=scanf("%d",&medication);
	    if (ret == 1) break;
	    fflush(stdin);
    }
	                                      //�ī~�O��   ���ۦ�t��O��
    if(medication<=100)                   
       money=0;                           //100���H�U	0�� 
    if(100<medication && medication<=200)                   
       money=20;                          //101~200��	20��
    if(200<medication && medication<=300)                   
       money=40;                          //201~300��	40��
    if(300<medication && medication<=400)                   
       money=60;                          //301~400��	60��
    if(400<medication && medication<=500)                   
       money=80;                          //401~500��	80��
    if(500<medication && medication<=600)                   
       money=100;                         //501~600��	100��
    if(600<medication && medication<=700)                   
       money=120;                         //601~700��	120��
    if(700<medication && medication<=800)                   
       money=140;                         //701~800��	140��
    if(800<medication && medication<=900)                   
       money=160;                         //801~900��	160��
    if(900<medication && medication<=1000)                   
       money=180;                         //901~1000��	180��  
    if(1000<medication)                   
       money=200;                         //1000���H�W	200��
       
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
	
	if(strncmp(in,patient,2)==0) //��| //�����O450 //30�ѥH��--���O���I10% //31~60--20% //61�H�W--30% 
	   inpatient();
	if(strncmp(out,patient,3)==0) //�¬ݶE//�����O250 
	   outpatient();
	
}
