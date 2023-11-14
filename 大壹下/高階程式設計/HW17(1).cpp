#include <iostream>

using namespace std;

struct lists
{
	int list[1000];
	bool check = false;
};

int main()
{
 	int s, p;
 	
 	while(cin >> s >> p)
	{
		lists sd[s], pf[p];
		
	 	int temp[s], ans[s];
	 	
	 	for(int i = 0; i < s; i++)
	  		for(int j = 0; j < p; j++)
	   			cin >> sd[i].list[j];
	   			
	 	for(int i = 0; i < p; i++)
	  		for(int j = 0; j < s; j++)
	   			cin >> pf[i].list[j];
	   			
	 	for(int i = 0; i < p; i++)
	  		for(int j = 0, count = 0; j < s; j++, count = 0)
	   			if(pf[sd[j].list[i]].check == false && sd[j].check == false)
	   			{
	    			temp[0] = j;
	    			count++;
	    			
	    			for(int k = 0; k < s; k++)
	     				if(sd[k].check == true)
	      					continue;
	      					
	     				else if(sd[j].list[i] == sd[k].list[i])
	     				{
	      					temp[count] = k;
	      					count++;
	     				}
	     				
	    			bool find = true;
	    			
	    			for(int k = 0; k < s && find; k++)
	     				for(int l = 0; l < count && find; l++)
	      					if(pf[sd[j].list[i]].list[k] == temp[l])
	      					{
	       						pf[sd[j].list[i]].check = true;
	       						sd[temp[l]].check = true;
	       						ans[temp[l]] = sd[j].list[i];
	       						find = !find;
	      					}
	   			}
	   			
	 	for(int i = 0; i < s; i++)
	  		cout << ans[i] << " ";
	  		
	 	cout << endl ;
	}
	return 0;
}
