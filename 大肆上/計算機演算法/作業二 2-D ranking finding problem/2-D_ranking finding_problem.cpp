#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;


void heapify(float x_arr[], float y_arr[], int n, int i) 
{
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && x_arr[left] > x_arr[largest])
      largest = left;
  
    if (right < n && x_arr[right] > x_arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) 
	{
      swap(x_arr[i], x_arr[largest]);
      swap(y_arr[i], y_arr[largest]);
      heapify(x_arr, y_arr, n, largest);
    }
  }
  
  // main function to do heap sort
void heapSort(float x_arr[], float y_arr[], int n) 
{
	// Build max heap
	for (int i = n / 2 - 1; i >= 0; i--)
	  heapify(x_arr, y_arr, n, i);
	
	// Heap sort
	for (int i = n - 1; i >= 0; i--) 
	{
	  swap(x_arr[0], x_arr[i]);
	  swap(y_arr[0], y_arr[i]);
	  // Heapify root element to get highest element at root again
	  heapify(x_arr, y_arr, i, 0);
	}
}

// Driver code
int main() 
{
	FILE *file = fopen("test2.txt", "r");
	
    bool flag = true;
	int n=0;
    
    const int maxn = 2000;    
	float x[maxn],y[maxn],num;
	
	//int bit[maxn][maxn];
	//int n ,qx ,qy, rank[maxn],count;

    memset(x ,0 ,sizeof(x));
    memset(y ,0 ,sizeof(y));
    //memset(bit ,0 ,sizeof(bit) );
	//memset(rank ,0 ,sizeof(rank));
	//count = 0;
	
    while(fscanf(file, "%f", &num) > 0) 
	{
		
        if(flag == true)
        {
        	x[n] = num;
        	flag = false;
        	cout << "(" << num << ",";
		}	
		else if(flag == false)
		{
			y[n] = num;
        	flag = true;
        	cout << num << ")  ";
        	//update(a[n][0], a[n][1]);
        	n++;
		}
    }
    float x_arr[n],y_arr[n];
    for(int i =0 ;i < n ; i++)
    {
    	x_arr[i] = x[i];
    	//cout << x_arr[i] << " "; 
    	y_arr[i] = y[i];
	}
    fclose(file);
    //cout << "\n" << n << "\n";
    
	
	heapSort(x_arr, y_arr, n);
	//cout << "Sorted array is \n";
	
	int rank[n];
	memset(rank ,0 ,sizeof(rank));
	for(int i = 1;i < n;i++)
	{
		for(int j = 0;j < i; j++)
		{
			if(y_arr[i] >= y_arr[j])
			{
				for(int k = 0;k < n; k++)
				{
					if(y_arr[i] == y[k])
						rank[k]++;
				}
			}
			
		}
	}
	cout << "\n";
	
	int max = 0,min = 0, sum = 0;
    for(int i = 0;i < n; i++)
    {
    	cout << "Rank(" << i + 1 <<") = " << rank[i] << ", "; 
    	sum = sum + rank[i];
    	
    	if(max < rank[i])
    		max = rank[i];
    	else if(min > rank[i])
    		min = rank[i];	
	}
	
	cout << "\n(1) 郎い┮Τ翴计:" << n <<"\n" ;
	cout << "(2) 程rank:" << max <<"\n";
	cout << "(3) 程rank:" << min <<"\n" ;
	cout << "(4)キАrank(计翴ㄢ):"	<< float(sum)/n;
    
	
}
