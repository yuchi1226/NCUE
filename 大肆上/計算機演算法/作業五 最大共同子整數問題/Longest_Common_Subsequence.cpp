#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int re[200][200];//??��???1
int re1[200][200];//??��???2
char s1[200],s2[200];//??��?�l�ǦC??1�B2
int i1=0,i2=0;

void p(char t[],int n,int m)
{//���u??��???1�D��?�l�ǦC
	if(m==0 || n==0) return;
    if(re[n][m]==0)//�P??���O�_?���W��
    {
        p(t,n-1,m-1);//???���W��?��??
        s1[i1]=t[n-1];
        i1++;
	}
	if(re[n][m]==1)//�P??���O�_?�W?
	    p(t,n-1,m);//???�W���@��?��??
	if(re[n][m]==2)//�P??���O�_?��?
	    p(t,n,m-1);//???��?�@��?��??
}

void p1(char t[],int n,int m)
{//���u??��???2�D��?�l�ǦC �Op�ۦP
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
    
    ifstream inFile("input.txt"); // �� "input.txt" ���A���ɮצW��

    if (!inFile.is_open()) {
        cout << "�L�k�}���ɮסI" << endl;
        return 1;
    }

	string line;
    while (getline(inFile, line)) {
    	
    	int n=0,m=0,i=0,j=0,l=0,k=0;
		re[200][200]={0};//??��???1
		re1[200][200]={0};//??��???2
		s1[200],s2[200];//??��?�l�ǦC??1�B2
		i1=0,i2=0;
		
        // �v��Ū���ɮפ��e
        istringstream iss(line);
        string N1, N2;
        // �H�Ů���jŪ����Ӧr��
        iss >> N1 >> N2;
        // �b���B�ϥ� N1 �M N2 �i��ݭn���ާ@
        cout << "N1: " << N1 << ", N2: " << N2 << endl;
        
        n=N1.length();
        m=N2.length();
        
        char a[n],b[m];
	    int z[n+1][m+1];//???��??
	    //��l��?��
	    for(i=0;i<n+1;i++)//?�Ĥ@�C��l��
	        z[i][0]=0;
	    for(i=0;i<m+1;i++)//?�Ĥ@���l��
	        z[0][i]=0;
	        
	    for(int i=0;i<n;i++)//��??�J�r�Ŧ�
    		a[i] = N1[i];  
    	for(int i=0;i<m;i++)
    		b[i]=N2[i];
        
        for(int i=1;i<n+1;i++)
	        for(int j=1;j<m+1;j++)
		    {
		        if(a[i-1]==b[j-1])//�P?��M�C?�e�O�_�ۦP
		        {
		            z[i][j]=z[i-1][j-1]+1;//����ȵ��_���W��+1
		            re[i][j]=0;//?0�N��?��?���W��
		        }
		        else if(z[i-1][j]>z[i][j-1])//�W�����Ȥj�_������
		        {
		            z[i][j]=z[i-1][j];//?��?�W������
		            re[i][j]=1;//?1�N��?��?�W��
		        }
		
		        else //��??�������Ȥj�_���_�W����
		            {z[i][j]=z[i][j-1];//?��?��������
		            re[i][j]=2;//?2�N��?��?����
		        }
		    }
	    //�U��?���M?��?�s?�bre1??��
	    //�O�W����??�O?�W���M�����۵�?���W������
	    for(int i=1;i<n+1;i++)
	        for(int j=1;j<m+1;j++)
	    {
	        if(a[i-1]==b[j-1])
	        {
	            re1[i][j]=0;//���W��
	        }
	        else if(z[i-1][j]>=z[i][j-1])//?�����P�w?�󤣦P
	        {
	            re1[i][j]=1;//�W��
	        }
	
	        else {
	            re1[i][j]=2;//����
	        }
	    }
	    //?�X?��??
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
		   {//�P??���P�w?��U�ұo��?���@�l�ǦC�O�_�ۦP
            k=1;break;
           }
        	else k=0;
        }
       if(k==1)
       {//���ۦP?����?�X
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

