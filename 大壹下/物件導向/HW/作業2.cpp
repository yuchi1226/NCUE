#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

void memError()
{
    cout<<"Memory allocation error!";
    exit(1);
}


int main()
{
    int rows,columns=4;
	int i,j;
    int **point; //�إ߫��� 
    
    cout<<"�п�J���X��ǥ� ";
    cin>>rows;
       
    point=new int*[rows]; //�إߤ@������ 
                                        
    if(!point) //�ˬd�O�_�O����t�m���~ 
        memError( );
        
    for(i=0; i<rows; i++)
    {
        point[i]=new int [columns]; //�إߤG���}�C 
        
        if(!point[i]) 
        memError();
    }
    
    int c[rows],e[rows],m[rows];
	float sum[rows];
    char name[rows][11];    
    
    printf("�ǥ�  ��  �^  �� \n"); 
    
    for(i=0;i<rows;i++)
	{
	    cin>>name[i];
	    cin>>c[i]>>e[i]>>m[i];
	    
	    sum[i]=((float)(c[i]+e[i]+m[i])/3);
	    
	    
	}
    
    int temp ;
    
    
    for (i = 0; i <rows; ++i) /* �w�j�ƧǪk */
    {
        for (int j = 0; j < i; ++j)
	    {
            if (sum[j]< sum[i])
	        {
                temp = sum[j];//���� 
                sum[j] = sum[i];
                sum[i] = temp;
                
                temp = c[j];//�� 
                c[j] = c[i];
                c[i] = temp;
                
                temp = e[j];//�^ 
                e[j] = e[i];
                e[i] = temp;
                
                temp = m[j];//�� 
                m[j] = m[i];
                m[i] = temp;
                
                char temp1[11]={0};
	        	
                strcpy(temp1,name[j]);//�W�r 
                strcpy(name[j],name[i]);
                strcpy(name[i],temp1);
            }
        }
    }

    
        
    printf("\n**********************\n");
    
    printf("�ǥ�    ��  �^  ��  ���� \n");
    for(i=0;i<rows;i++)
    {
    	cout<<setw(5)<<name[i];
	    cout<<setw(5)<<c[i]<<setw(4)<<e[i]<<setw(4)<<m[i];
		printf("  %0.2f\n",sum[i]);
	} 
    

    for(i=0; i<rows; i++)
        delete [] point[i]; //�R���� 
        
    delete [] point; //�R���C
    
    return 0;
}
