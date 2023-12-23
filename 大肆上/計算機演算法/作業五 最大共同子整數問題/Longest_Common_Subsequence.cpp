#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int re[200][200];//??隔???1
int re1[200][200];//??隔???2
char s1[200],s2[200];//??程???12
int i1=0,i2=0;

void p(char t[],int n,int m)
{//誹??隔???1―程?
	if(m==0 || n==0) return;
    if(re[n][m]==0)//??方琌?オà
    {
        p(t,n-1,m-1);//???オà?︽??
        s1[i1]=t[n-1];
        i1++;
	}
	if(re[n][m]==1)//??方琌??
	    p(t,n-1,m);//????︽??
	if(re[n][m]==2)//??方琌?オ?
	    p(t,n,m-1);//???オ??︽??
}

void p1(char t[],int n,int m)
{//誹??隔???2―程? 蒓p
	if(m==0 || n==0) return;
	    if(re1[n][m]==0)
	    {
	        p1(t,n-1,m-1);
		    s2[i2]=t[n-1];
		    i2++;
		}
	if(re1[n][m]==1)
	    p1(t,n-1,m);
	if(re1[n][m]==2)
	    p1(t,n,m-1);

}
int main()
{
    
    ifstream inFile("input.txt"); // 传 "input.txt" 郎嘿

    if (!inFile.is_open()) {
        cout << "礚猭秨币郎" << endl;
        return 1;
    }

	string line;
    while (getline(inFile, line)) {
    	
    	int n=0,m=0,i=0,j=0,l=0,k=0;
		re[200][200]={0};//??隔???1
		re1[200][200]={0};//??隔???2
		s1[200],s2[200];//??程???12
		i1=0,i2=0;
		
        // 硋︽弄郎ず甧
        istringstream iss(line);
        string N1, N2;
        // だ筳弄ㄢ﹃
        iss >> N1 >> N2;
        // 矪ㄏノ N1 ㎝ N2 秈︽惠璶巨
        cout << "N1: " << N1 << ", N2: " << N2 << endl;
        
        n=N1.length();
        m=N2.length();
        
        char a[n],b[m];
	    int z[n+1][m+1];//?????
	    //﹍て?
	    for(i=0;i<n+1;i++)//?材﹍て
	        z[i][0]=0;
	    for(i=0;i<m+1;i++)//?材︽﹍て
	        z[0][i]=0;
	        
	    for(int i=0;i<n;i++)//だ??才﹃
    		a[i] = N1[i];  
    	for(int i=0;i<m;i++)
    		b[i]=N2[i];
        
        for(int i=1;i<n+1;i++)
	        for(int j=1;j<m+1;j++)
		    {
		        if(a[i-1]==b[j-1])//?︽㎝?甧琌
		        {
		            z[i][j]=z[i-1][j-1]+1;//单オà+1
		            re[i][j]=0;//?0?方?オà
		        }
		        else if(z[i-1][j]>z[i][j-1])//オ
		        {
		            z[i][j]=z[i-1][j];//??
		            re[i][j]=1;//?1?方?
		        }
		
		        else //??オ单
		            {z[i][j]=z[i][j-1];//??オ
		            re[i][j]=2;//?2?方?オ
		        }
		    }
	    //?Ω筂?隔??re1??ń
	    //蒓??琌?㎝オ单?
	    for(int i=1;i<n+1;i++)
	        for(int j=1;j<m+1;j++)
	    {
	        if(a[i-1]==b[j-1])
	        {
	            re1[i][j]=0;//オà
	        }
	        else if(z[i-1][j]>=z[i][j-1])//?ń﹚?ンぃ
	        {
	            re1[i][j]=1;//
	        }
	
	        else {
	            re1[i][j]=2;//オ
	        }
	    }
	    //????
	    for(i=1;i<n+1;i++)
        {
             for(j=1;j<m+1;j++)
                printf("%d ",z[i][j]);
             printf("\n");
        }
        printf("\n");
        p(a,n,m);
        p1(a,n,m);
        for(i=0;i<i1;i++)
        {
           if(s1[i]!=s2[i])
		   {//??销﹚?ン┮眔程?そ琌
            k=1;break;
           }
        	else k=0;
        }
       if(k==1)
       {//ぃ?场?
           for(j=0;j<i1;j++)
            printf("%c ",s1[j]);
           printf("\n");
           for(j=0;j<i2;j++)
            printf("%c ",s2[j]);
       }
       else
            for(j=0;j<i1;j++)
                printf("%c !",s1[j]);
                
       	printf("\n");
       	printf("\n");
    }
    return 0;
}

