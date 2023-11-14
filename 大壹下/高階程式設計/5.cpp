#include<iostream>
#include<cstring>
using namespace std;

int main()
{ 
 char a[101],b[101],c[101];
 int len,lena,lenb,lenc;
 

 while(cin>>a>>b>>c)
 {
  char abc[303]={0},acb[303]={0},bac[303]={0},bca[303]={0},cab[303]={0},cba[303]={0};
  char max[303]={0};
  
  lena=strlen(a);
  lenb=strlen(b);
  lenc=strlen(c);
  
  strncpy(abc,a,lena);
  strncat(abc,b,lenb);
  strncat(abc,c,lenc);

  
  strncpy(acb,a,lena);
  strncat(acb,c,lenc);
  strncat(acb,b,lenb);
  
  
  strncpy(bac,b,lenb);
  strncat(bac,a,lena);
  strncat(bac,c,lenc);

  
  strncpy(bca,b,lenb);
  strncat(bca,c,lenc);
  strncat(bca,a,lena);

  
  strncpy(cab,c,lenc);
  strncat(cab,a,lena);
  strncat(cab,b,lenb);  
  
  strncpy(cba,c,lenc);
  strncat(cba,b,lenb);
  strncat(cba,a,lena);
  

  len=lena+lenb+lenc;
  
  strncpy(max,abc,len);
  
  if(strcmp(acb,max)>0)
   strncpy(max,acb,len);
   
  if(strcmp(bac,max)>0)
   strncpy(max,bac,len);
   
  if(strcmp(bca,max)>0)
   strncpy(max,bca,len);
   
  if(strcmp(cab,max)>0)
   strncpy(max,cab,len);
   
  if(strcmp(cba,max)>0)
   strncpy(max,cba,len);
   
  cout<<max<<endl;
  
 }  
 return 0;  
}
