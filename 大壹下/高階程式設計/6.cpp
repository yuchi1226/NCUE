#include<iostream>
#include<stdio.h>
using namespace std;


int run(char a)
{
    switch(a)
    {
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case 'H': return 4;
    
        case 'F': return 0;  
		case 'G': return 0; 
		case 'S': return 0; 
    }
}


int main()
{
int i,j,k;
int time[9]={0};//每個人各上幾次場
int record[9][5];//記分板 
int outtime,outsum=0;//所需出局數和目前出局數 
int out=0;//出局3次清空壘包 
int base[4]={0};//壘包(0=本壘)
int point=0;//得分 

char a,b;
bool gameover=false;

for(i=0;i<9;i++)
{
    cin>>time[i];    	
    for(j=0;j<time[i];j++)
    {
    	cin>>a>>b;//看第一個字就好 
    	record[i][j]=(int)run(a);
	}	
}//將專業術語化成跑幾壘	
	cin>>outtime;//總共幾個出局 
	
while(true)
{	
for(i=0;i<5 && outsum<=outtime;i++)//[第j個人][i次] 
{   
	for(j=0;j<9 && outsum<=outtime;j++)//每人第一球==[j][0]
    {
	    if(i>=time[j])//超出該球員打擊數時結束
            break;
					 
        if(record[j][i]==0)
        {
            out++;//出局3次就清空壘包 
            outsum++;//目前出局數 
		}
		else
        {
            base[0]=1;//本壘有人 
                   
            for(k=3;k>=0;k--) 
                if(base[k]==1)
                {
                    if(k+record[j][i]>3)
                        point++;
                    else
                        base[k+record[j][i]]=1;//當下的壘者跑record[j][i]步 ex:2B(本壘跑到2壘) 
                                
                    base[k]=0;//原壘者移動 
                } 
        } 
			
		if(outsum==outtime)//達到出局數 
        {
            gameover=true; 
            break;    
        }
             
        if(out==3)// 出局3次就清空壘包
        {
            base[0]=0;
            base[1]=0;
            base[2]=0;
            base[3]=0;
                    
            out=0;//新一局 
        }
			
			
	}
		
	if(gameover==true)
        break;	   
	
} 
		
}

cout<<point<<endl;

}
