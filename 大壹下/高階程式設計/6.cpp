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
int time[9]={0};//�C�ӤH�U�W�X����
int record[9][5];//�O���O 
int outtime,outsum=0;//�һݥX���ƩM�ثe�X���� 
int out=0;//�X��3���M���S�] 
int base[4]={0};//�S�](0=���S)
int point=0;//�o�� 

char a,b;
bool gameover=false;

for(i=0;i<9;i++)
{
    cin>>time[i];    	
    for(j=0;j<time[i];j++)
    {
    	cin>>a>>b;//�ݲĤ@�Ӧr�N�n 
    	record[i][j]=(int)run(a);
	}	
}//�N�M�~�N�y�Ʀ��]�X�S	
	cin>>outtime;//�`�@�X�ӥX�� 
	
while(true)
{	
for(i=0;i<5 && outsum<=outtime;i++)//[��j�ӤH][i��] 
{   
	for(j=0;j<9 && outsum<=outtime;j++)//�C�H�Ĥ@�y==[j][0]
    {
	    if(i>=time[j])//�W�X�Ӳy�������Ʈɵ���
            break;
					 
        if(record[j][i]==0)
        {
            out++;//�X��3���N�M���S�] 
            outsum++;//�ثe�X���� 
		}
		else
        {
            base[0]=1;//���S���H 
                   
            for(k=3;k>=0;k--) 
                if(base[k]==1)
                {
                    if(k+record[j][i]>3)
                        point++;
                    else
                        base[k+record[j][i]]=1;//��U���S�̶]record[j][i]�B ex:2B(���S�]��2�S) 
                                
                    base[k]=0;//���S�̲��� 
                } 
        } 
			
		if(outsum==outtime)//�F��X���� 
        {
            gameover=true; 
            break;    
        }
             
        if(out==3)// �X��3���N�M���S�]
        {
            base[0]=0;
            base[1]=0;
            base[2]=0;
            base[3]=0;
                    
            out=0;//�s�@�� 
        }
			
			
	}
		
	if(gameover==true)
        break;	   
	
} 
		
}

cout<<point<<endl;

}
