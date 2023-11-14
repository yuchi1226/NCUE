#include<iostream>
#include<cstring>
using namespace std;

int main()
{   
    char a[3][101],b[6][303]={0};
    int max=0;
    
 while(cin>>a[0]>>a[1]>>a[2])
 {
  
 strcat(b[0],a[0]); //abc
 strcat(b[0],a[1]);
 strcat(b[0],a[2]);
 
 strcat(b[1],a[0]); 
 strcat(b[1],a[2]);
 strcat(b[1],a[1]);
 
 strcat(b[2],a[1]); //bca
 strcat(b[2],a[0]);
 strcat(b[2],a[2]);
 
 strcat(b[3],a[1]);
 strcat(b[3],a[2]);
 strcat(b[3],a[0]);
 
 strcat(b[4],a[2]); //cab
 strcat(b[4],a[0]);
 strcat(b[4],a[1]);
 
 strcat(b[5],a[2]);
 strcat(b[5],a[1]);
 strcat(b[5],a[0]);

 for(int i=1;i<6;i++)
    if(strcmp(b[i],b[max])>0)
        max=i;
        
 cout<<b[max]<<endl; 
 
}

}
