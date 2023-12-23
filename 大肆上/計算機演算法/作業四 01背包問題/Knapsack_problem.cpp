#include<iostream>
#include<algorithm>
using namespace std;

#define N 100//最多可能的物体?


struct  goods //1.物品?构体
{
	int sign;//物品的序? 
	int w;//物品的重量 
	int p;//物品的价值 
	 
 } a[N];
  
  
  
bool m(goods a,goods b) //2.比??位重量价值?更大 
{
	return (a.p/a.w)>(b.p/b.w); 
} 


int max(int a,int b)//3.比?大小 
{
	return a<b?b:a; 
} 
	
	
	
	
	
int n,C,bestP=0,cp=0,cw=0;//n?物品??  C?背包容量	                          
int X[N],cx[N];


struct KNAPNODE  //4.???构体
{
	bool s1[N];//?前放入物品 
	int k;//搜索的深度
	int b; //价值上界，背包价值+剩下的最大?位重量价值的物品??剩余容量的价值和
	int w;//物品重量
	int p;//物品价值 
} ;
	 
	 
	 
	 
	 
//5.堆 
struct HEAP  //堆元素?构体
{
	KNAPNODE *p;;//???据
	int b;//所指??的上界 
} ;
	 
	 
//交???堆元素
void  swap(HEAP  &a,HEAP &b)
{
	HEAP  temp=a;
	a=b;
	b=temp; 
} 
	 
//堆中元素上移
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

//堆中元素下移
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
 
//往堆中插入??
void insert(HEAP H[], HEAP x, int &n)
{
    n++;
    H[n] = x;
    mov_up(H,n);
}
 
//?除堆中??
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
 
//?得堆?元素并?除
HEAP del_top(HEAP H[], int&n)
{
    HEAP x = H[1];
    del(H, n, 1);
    return x;
}
 
 
//6.?算分支??的上界，更新????的上界  node.b 
void bound( KNAPNODE* node,int M, goods a[], int n)
{
    int i = node->k;
    float w = node->w;
    float p = node->p;
    if(node->w > M)
    {        //物体重量超?背包?重量
       node->b = 0;       //上界置?0
    }
    else
    {   
	    //多加了一?判??件?里888888888888888888888888888
		if(node->s1[node->k]!=false)
	     {
	        while((w+a[i].w <= M)&&(i < n))
	        {  
	           w += a[i].w;   //?算背包已?入?重
	           p += a[i++].p; //?算背包已?入价值
	        }
	        if(i<n)//判?是否是最后一?物品 
	        {
	           node->b = p + (M - w)*a[i].p/a[i].w;//不是，?算新的上界 
	        }
	        else
	        {
	           node -> b = p;//已?得到最??果 
	        }
	    }
	    //多加， node->s1[node->k]==false的?候 8888888888888888888
	    else
		{
			if(i<n)//判?是否是最后一?物品 
		    {
		       node->b = p + (M - w)*a[i].p/a[i].w;//不是，?算新的上界 
		    }
		    else
		    {
		       node -> b = p;//已?得到最??果 
		    }
	    	
		}
    }
}
 
 
 
 
//7.用分支限界法??0/1背包??
int KnapSack(int n,goods a[],int C, int X[])
{
    int i, k = 0;                 //堆中元素??的??器初始化?0
    int v;
    KNAPNODE *xnode, *ynode, *znode; //??
    HEAP x, y, z, *heap;  //堆?构体 
    heap = new HEAP[n*n];         //分配堆的存?空?
    
    for(i = 0; i < n; i++)
    {
       a[i].sign=i;               //??物体的初始??
    }
    
    sort(a,a+n,m);                //?物体按照价值重量比排序
    
    xnode = new KNAPNODE; //建立父???，初始化 
    
    for(i = 0; i < n; i++)
    {          //初始化??，表示?有放入背包 
       xnode->s1[i] = false;
    }
    
    xnode->k = xnode->w = xnode->p = 0;//全部初始化?0 
    //8888888888888888888888888  
     bound(xnode, C, a, n);     //?算??x的上界
    cout<<"w: "<<xnode->w;
    cout<<"   v:"<<xnode->p;
	cout<<"   ub:"<<xnode->b; 
	cout<<"   input pt"<<endl;
	//888888888888888888888888 
    
    
    while(xnode->k < n) //?有物品需要判? 
    {   	
       ynode = new KNAPNODE;      //建立??y
       *ynode = *xnode;           //??x的?据复制到??y，也就是全都初始化成0 
                            //也就是y是第一???了 
       
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
     
    
       ynode->s1[ynode->k] = true;    //?入第k?物体，第一次?入第0?物体 
       ynode->w += a[ynode->k].w;     //背包中物体重量累?
       ynode->p += a[ynode->k].p;     //背包中物体价值累?
       
       
       
       ynode->k++;               //搜索深度++
       bound(ynode, C, a, n);     //?算??y的上界，更新y的y.b 
       
       y.b = ynode->b;  //更新pt表中的，也就是优先?列 堆中的?据 
       y.p = ynode;
      
//888888888888888888888888888888888     
       //更新之后，?y??加入pt表中 
       if(y.b!=0)
       {
           cout<<"w:"<< ynode->w;
		   cout<<"   v:"<<  ynode->p;
		   cout<<"    ub: "<< y.b;   
		   cout<<"   input pt"<<endl;  
	    }
//8888888888888888888888888888888888	   
        insert(heap, y, k);       //??y按上界的值插入堆中
        
      
    	//不?入第k?物体    
       znode = new KNAPNODE;      //建立??z
       *znode = *xnode;           //??x的?据复制到??z
       
       //??(忽略):cout<<"zonode w  he p:  "<<znode->w<<znode->p<<znode->k<<endl;     
        //??(忽略):ynode->s1[ynode->k] = true;  
       znode->s1[znode->k]=false;//不?入物品           
       znode->k++;                //搜索深度++
             
       bound(znode, C, a, n);     //?算??z的上界
       
       //??(忽略):cout<<"znode.b"<<znode->b;
       z.b = znode->b;
       z.p = znode;
                                 
       insert(heap, z, k);        //??z按上界的值插入堆中 
       
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
       x = del_top(heap, k);      //?得堆?元素作?新的父???
       xnode = x.p;	      
    }
     
    v = xnode->p;
    for(i = 0; i < n; i++)
    {          //取?入背包中物体在排序前的序?
    
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
    return v;                    //返回背包中物体的价值
}

/*??以上算法的主函?*/
int main()
{
    goods b[N];
    printf("物品種類n: ");
    scanf("%d",&n);           //?入物品种?
    printf("背包容量C: ");
    scanf("%d",&C);           //?入背包容量
    for (int i=0;i<n;i++)     //?入物品i的重量w及其价值v
    {
       printf("物品%d的重量w[%d]及其價值v[%d]: ",i+1,i+1,i+1);
       scanf("%d%d",&a[i].w,&a[i].p);
       b[i]=a[i];
    }
 
    int sum=KnapSack(n,a,C,X);//?用分支限界法求0/1背包??
    printf("分支限界法求解0/1背包問題:\nX=[ ");
    for(int i=0;i<n;i++)
 		cout<<X[i]<<" ";//?出所求X[n]矩?
    printf("]  裝入總價值[%d]\n",sum);
    return 0;

}
