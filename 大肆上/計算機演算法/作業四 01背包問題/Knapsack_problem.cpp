#include<iostream>
#include<algorithm>
using namespace std;

#define N 100//�̦h�i�઺���^?


struct  goods //1.���~?���^
{
	int sign;//���~����? 
	int w;//���~�����q 
	int p;//���~��ɲ�� 
	 
 } a[N];
  
  
  
bool m(goods a,goods b) //2.��??�쭫�qɲ��?��j 
{
	return (a.p/a.w)>(b.p/b.w); 
} 


int max(int a,int b)//3.��?�j�p 
{
	return a<b?b:a; 
} 
	
	
	
	
	
int n,C,bestP=0,cp=0,cw=0;//n?���~??  C?�I�]�e�q	                          
int X[N],cx[N];


struct KNAPNODE  //4.???���^
{
	bool s1[N];//?�e��J���~ 
	int k;//�j�����`��
	int b; //ɲ�ȤW�ɡA�I�]ɲ��+�ѤU���̤j?�쭫�qɲ�Ȫ����~??�ѧE�e�q��ɲ�ȩM
	int w;//���~���q
	int p;//���~ɲ�� 
} ;
	 
	 
	 
	 
	 
//5.�� 
struct HEAP  //�露��?���^
{
	KNAPNODE *p;;//???�u
	int b;//�ҫ�??���W�� 
} ;
	 
	 
//��???�露��
void  swap(HEAP  &a,HEAP &b)
{
	HEAP  temp=a;
	a=b;
	b=temp; 
} 
	 
//�襤�����W��
void mov_up(HEAP H[],int i)
{
	bool  done=false;
	if(i!=1)
	{
		while(!done && i!=1)
		{
			if(H[i].b>H[i/2].b)
			{
				swap(H[i],H[i/2]) ;
			} 
			else{
				done =true; 
			} 
			i=i/2;
		} 
	} 
} 

//�襤�����U��
void mov_down(HEAP H[], int n, int i)
{
    bool done = false;
    if((2*i)<=n)
    {
        while(!done && ((i = 2*i) <= n))
        {
            if(i+1 <= n && H[i+1].b > H[i].b)
            {
                i++;
            }
            if(H[i/2].b < H[i].b)
            {
                swap(H[i/2], H[i]);
            }
            else
            {
                done = true;
            }
        }
    }
}
 
//���襤���J??
void insert(HEAP H[], HEAP x, int &n)
{
    n++;
    H[n] = x;
    mov_up(H,n);
}
 
//?���襤??
void del(HEAP H[], int &n, int i)
{
    HEAP x, y;
    x = H[i]; y = H[n];
    n --;
    if(i <= n)
    {
        H[i] = y;
        if(y.b >= x.b)
        {
            mov_up(H,i);
        }
        else
        {
            mov_down(H, n, i);
        }
    }
}
 
//?�o��?�����}?��
HEAP del_top(HEAP H[], int&n)
{
    HEAP x = H[1];
    del(H, n, 1);
    return x;
}
 
 
//6.?�����??���W�ɡA��s????���W��  node.b 
void bound( KNAPNODE* node,int M, goods a[], int n)
{
    int i = node->k;
    float w = node->w;
    float p = node->p;
    if(node->w > M)
    {        //���^���q�W?�I�]?���q
       node->b = 0;       //�W�ɸm?0
    }
    else
    {   
	    //�h�[�F�@?�P??��?��888888888888888888888888888
		if(node->s1[node->k]!=false)
	     {
	        while((w+a[i].w <= M)&&(i < n))
	        {  
	           w += a[i].w;   //?��I�]�w?�J?��
	           p += a[i++].p; //?��I�]�w?�Jɲ��
	        }
	        if(i<n)//�P?�O�_�O�̦Z�@?���~ 
	        {
	           node->b = p + (M - w)*a[i].p/a[i].w;//���O�A?��s���W�� 
	        }
	        else
	        {
	           node -> b = p;//�w?�o���??�G 
	        }
	    }
	    //�h�[�A node->s1[node->k]==false��?�� 8888888888888888888
	    else
		{
			if(i<n)//�P?�O�_�O�̦Z�@?���~ 
		    {
		       node->b = p + (M - w)*a[i].p/a[i].w;//���O�A?��s���W�� 
		    }
		    else
		    {
		       node -> b = p;//�w?�o���??�G 
		    }
	    	
		}
    }
}
 
 
 
 
//7.�Τ��䭭�ɪk??0/1�I�]??
int KnapSack(int n,goods a[],int C, int X[])
{
    int i, k = 0;                 //�襤����??��??����l��?0
    int v;
    KNAPNODE *xnode, *ynode, *znode; //??
    HEAP x, y, z, *heap;  //��?���^ 
    heap = new HEAP[n*n];         //���t�諸�s?��?
    
    for(i = 0; i < n; i++)
    {
       a[i].sign=i;               //??���^����l??
    }
    
    sort(a,a+n,m);                //?���^����ɲ�ȭ��q��Ƨ�
    
    xnode = new KNAPNODE; //�إߤ�???�A��l�� 
    
    for(i = 0; i < n; i++)
    {          //��l��??�A���?����J�I�] 
       xnode->s1[i] = false;
    }
    
    xnode->k = xnode->w = xnode->p = 0;//������l��?0 
    //8888888888888888888888888  
     bound(xnode, C, a, n);     //?��??x���W��
    cout<<"w: "<<xnode->w;
    cout<<"   v:"<<xnode->p;
	cout<<"   ub:"<<xnode->b; 
	cout<<"   input pt"<<endl;
	//888888888888888888888888 
    
    
    while(xnode->k < n) //?�����~�ݭn�P? 
    {   	
       ynode = new KNAPNODE;      //�إ�??y
       *ynode = *xnode;           //??x��?�u�`���??y�A�]�N�O������l�Ʀ�0 
                            //�]�N�Oy�O�Ĥ@???�F 
       
//8888888888888888888888888     
	    if(ynode->b!=0) 
	    {
		    cout<<"w: "<<ynode->w;
	        cout<<"   v:"<<ynode->p;
	        cout<<"   ub:"<<ynode->b; 
		   	cout<<"   output"<<endl; 
        }  
        else
		{
			xnode->k++; 
			continue;	
		}  
//8888888888888888888888888
     
    
       ynode->s1[ynode->k] = true;    //?�J��k?���^�A�Ĥ@��?�J��0?���^ 
       ynode->w += a[ynode->k].w;     //�I�]�����^���q��?
       ynode->p += a[ynode->k].p;     //�I�]�����^ɲ�Ȳ�?
       
       
       
       ynode->k++;               //�j���`��++
       bound(ynode, C, a, n);     //?��??y���W�ɡA��sy��y.b 
       
       y.b = ynode->b;  //��spt�����A�]�N�Oɬ��?�C �襤��?�u 
       y.p = ynode;
      
//888888888888888888888888888888888     
       //��s���Z�A?y??�[�Jpt�� 
       if(y.b!=0)
       {
           cout<<"w:"<< ynode->w;
		   cout<<"   v:"<<  ynode->p;
		   cout<<"    ub: "<< y.b;   
		   cout<<"   input pt"<<endl;  
	    }
//8888888888888888888888888888888888	   
        insert(heap, y, k);       //??y���W�ɪ��ȴ��J�襤
        
      
    	//��?�J��k?���^    
       znode = new KNAPNODE;      //�إ�??z
       *znode = *xnode;           //??x��?�u�`���??z
       
       //??(����):cout<<"zonode w  he p:  "<<znode->w<<znode->p<<znode->k<<endl;     
        //??(����):ynode->s1[ynode->k] = true;  
       znode->s1[znode->k]=false;//��?�J���~           
       znode->k++;                //�j���`��++
             
       bound(znode, C, a, n);     //?��??z���W��
       
       //??(����):cout<<"znode.b"<<znode->b;
       z.b = znode->b;
       z.p = znode;
                                 
       insert(heap, z, k);        //??z���W�ɪ��ȴ��J�襤 
       
 //8888888888888888888888888      
       if(z.b!=0)
       {
			cout<<"w:"<< znode->w;
			cout<<"   v:"<<  znode->p;
			cout<<"    ub: "<< z.b;   
			cout<<"   input pt"<<endl;  
       }
//88888888888888888888888888888888	         
       delete xnode;
       x = del_top(heap, k);      //?�o��?�����@?�s����???
       xnode = x.p;	      
    }
     
    v = xnode->p;
    for(i = 0; i < n; i++)
    {          //��?�J�I�]�����^�b�Ƨǫe����?
    
        if(xnode->s1[i])
        {
           X[a[i].sign] =1 ;
             
        }
        else
        {
           X[a[i].sign] = 0;
          
        }
    }
    delete xnode;
    delete heap;
    return v;                    //��^�I�]�����^��ɲ��
}

/*??�H�W��k���D��?*/
int main()
{
    goods b[N];
    printf("���~����n: ");
    scanf("%d",&n);           //?�J���~��?
    printf("�I�]�e�qC: ");
    scanf("%d",&C);           //?�J�I�]�e�q
    for (int i=0;i<n;i++)     //?�J���~i�����qw�Ψ�ɲ��v
    {
       printf("���~%d�����qw[%d]�Ψ����v[%d]: ",i+1,i+1,i+1);
       scanf("%d%d",&a[i].w,&a[i].p);
       b[i]=a[i];
    }
 
    int sum=KnapSack(n,a,C,X);//?�Τ��䭭�ɪk�D0/1�I�]??
    printf("���䭭�ɪk�D��0/1�I�]���D:\nX=[ ");
    for(int i=0;i<n;i++)
 		cout<<X[i]<<" ";//?�X�ҨDX[n]�x?
    printf("]  �ˤJ�`����[%d]\n",sum);
    return 0;

}
