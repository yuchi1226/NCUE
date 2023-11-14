#include<iostream>
using namespace std;

int main()
{
    int n,m,i,j,time,c,d;
	int a[200],b[200][200];
	int temp=1,max=0,change;
    
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>m;
        temp=1;
        

        for(j=0;j<m;j++)
            cin>>a[j];

        for(c=0;c<m;c++)
            for(d=0;d<m;d++)
                if(c-d>=-1)
                {
                    b[c][d]=0;
                }

        for(c=0;c<m;c++)
            for(d=c;d<c+3;d++)
            {
                temp=temp*a[d];
                
            }
            b[c][c+2]=temp;
            
            temp=1;

        time=((m-3)+1)*(m-3)/2;
        temp=2;

        for(c=0;c<time;c++)
            for(d=0;d<=m-4;d++)
               for(j=d+temp;j<m;j++)
               {
                    max=-1;
                    
			        for(int z=d+1;z<=j-1;z++)
			        {
			            change=b[d][z]+b[z][j]+a[d]*a[z]*a[j];
			            if(change>max)
			            max=change;
			        }
			       
			        b[d][j]=max;
               }

     
        cout<<b[0][m-1]<<" ";




        temp=2;
        int min=2147483647;
        for(c=0;c<time;c++)
        {
            temp++;
            for(d=0;d<=m-4;d++)
            {
                for(j=d+temp;j<=temp+d,j<m;j++)
                {
                   min=2147483647;
                   
                   for(int z=d+1;z<=j-1;z++)
                    {
                      change=b[d][z]+b[z][j]+a[d]*a[z]*a[j];
                      if(change<min)
                      min=change;
                    }
       
                b[d][j]=min;
               }

            }
        }
        
     
        cout<<b[0][m-1]<<endl;
        
      
  }
  
}
