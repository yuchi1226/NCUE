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
    int **point; //建立指標 
    
    cout<<"請輸入有幾位學生 ";
    cin>>rows;
       
    point=new int*[rows]; //建立一維指標 
                                        
    if(!point) //檢查是否記憶體配置錯誤 
        memError( );
        
    for(i=0; i<rows; i++)
    {
        point[i]=new int [columns]; //建立二維陣列 
        
        if(!point[i]) 
        memError();
    }
    
    int c[rows],e[rows],m[rows];
	float sum[rows];
    char name[rows][11];    
    
    printf("學生  國  英  數 \n"); 
    
    for(i=0;i<rows;i++)
	{
	    cin>>name[i];
	    cin>>c[i]>>e[i]>>m[i];
	    
	    sum[i]=((float)(c[i]+e[i]+m[i])/3);
	    
	    
	}
    
    int temp ;
    
    
    for (i = 0; i <rows; ++i) /* 泡沫排序法 */
    {
        for (int j = 0; j < i; ++j)
	    {
            if (sum[j]< sum[i])
	        {
                temp = sum[j];//平均 
                sum[j] = sum[i];
                sum[i] = temp;
                
                temp = c[j];//國 
                c[j] = c[i];
                c[i] = temp;
                
                temp = e[j];//英 
                e[j] = e[i];
                e[i] = temp;
                
                temp = m[j];//數 
                m[j] = m[i];
                m[i] = temp;
                
                char temp1[11]={0};
	        	
                strcpy(temp1,name[j]);//名字 
                strcpy(name[j],name[i]);
                strcpy(name[i],temp1);
            }
        }
    }

    
        
    printf("\n**********************\n");
    
    printf("學生    國  英  數  平均 \n");
    for(i=0;i<rows;i++)
    {
    	cout<<setw(5)<<name[i];
	    cout<<setw(5)<<c[i]<<setw(4)<<e[i]<<setw(4)<<m[i];
		printf("  %0.2f\n",sum[i]);
	} 
    

    for(i=0; i<rows; i++)
        delete [] point[i]; //刪除行 
        
    delete [] point; //刪除列
    
    return 0;
}
