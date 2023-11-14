#include<iostream>
#include<iomanip>
using namespace std;


int main()
{
    int a[100][3]={0},b,c,max,sum=0;
    int n,i,j;
    
    cin>>b;
    
    for(n=0;n<b;n++)
    {
        while((cin >> c) && c)
        {
            for(i=0;i<c;i++)
            {
                cin >> a[i][1] >>a[i][2];
                a[i][3]=a[i][1]*a[i][2];
            }
                      
            for(int i=0;i<c;i++)
            {  
                max=i;
                   
                for(j=i+1;j<c;j++)
                    if (a[max][3]>=a[j][3]) 
                        max=j;
                
                int e,f,g;
                
                e=a[max][1]; f=a[max][2]; g=a[max][3];
                a[max][1]=a[i][1];
                a[max][2]=a[i][2];
                a[max][3]=a[i][3];
                a[i][1]=e; a[i][2]=f; a[i][3]=g;                         
            }
            //for(int k=0;k<n;k++)
                //cout <<setiosflags(ios::left)<<setw(7)<<a[k].w1<<setw(7)<<a[k].w2<<setw(7)<<a[k].w3<<endl;

            //for(int k=0;k<n;k++)  
                //sum[k]=1;       
			             
            int max2=0;
            
            for(int i=c-1;i>=0;i--)
            {    
                max=i;sum=1;
                
                for(int j=i-1;j>=0;j--)
                    if((a[max][1]<a[j][1] && a[max][2]<a[j][1] || a[max][1]<a[j][2] && a[max][2]<a[j][2]) || (a[max][1]<a[j][1] && a[max][1]<a[j][2] || a[max][2]<a[j][1] && a[max][2]<a[j][2])) 
                        continue;
                else
                {
            	    sum++;
            	    max=j;
			    }    
				

       //if (sum[j]<=(sum[i]+1))
                //    sum[j]=sum[i]+1;                   
                if(sum>max2)
                    max2=sum;
            }        
              
            //for(int k=0;k<n;k++)  
             // if (maxs<sum[k]) 
           //  maxs=sum[k];
         
            cout << max2 <<endl;    
        }
    }
}
