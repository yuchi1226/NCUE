#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct _node 
{
	int a;
	int b;
}Node;

bool cmp1(Node p, Node q)
{
	if (p.a == q.a) return (q.b> p.b);
	else return(p.a < q.a);
}

Node d[10000];

int main() 
{
	int n, cnt,s,e;
	
	while (scanf("%d", &n) != EOF)
	{
		cnt = 0;
		
		for (int i = 0; i<n; i++) 
			scanf("%d %d", &(d[i].a), &(d[i].b));
			
		sort(d, d + n, cmp1);//將區間的開始數值由小到大排序
		
		for (int i = 0; i < n;i++) 
		{
			s = d[i].a;
			e = d[i].b;
			while ((i + 1 < n) && d[i + 1].a < e) 
			{//s與e是否包含下一個區間的開始數值 
				if (d[i + 1].b <= e) i++;//包含下一個區間的全部，忽略此區間 
				
				else 
				{
					e = d[i + 1].b;//未包含下一個區間的全部，但有重疊，將e改成下一個區間的結束值 
					i++;
				}
			}
			
			cnt = cnt + e - s;//此區間的範圍數值個數 
		}
		
		printf("%d\n", cnt);
	}
}
