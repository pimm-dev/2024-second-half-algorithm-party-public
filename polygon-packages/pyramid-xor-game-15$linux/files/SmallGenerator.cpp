#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	
	
	
	int n = stoi(argv[1]);
	ensuref(n <= 5, "n > 5");
	int m = n*(n+1)/2;
	int k = stoi(argv[2]);
	int maxAi = stoi(argv[3]);
	int c = 1;
	while((1<<m)*(c+1)*n*n <= 1000000 && (1<<m)*(c+1) <= 65536)
	    c++;
	  
    int t = (1<<m)*c;
    cout << t << "\n";
	
	for(int i = 0; i<1<<m; i++)
	{
	    for(int j = 0; j<c; j++)
	    {
	        cout << n << " " << k << "\n";
    	    vector<int> arr;
    	    
    	    for(int p = 0; p<m; p++)
    	    {
    	        if(i&(1<<p))
    	            arr.push_back(-1);
    	        else
    	            arr.push_back(rnd.next(0,maxAi));
    	    }
    	    
    	    int index = 0;
    	    for(int p = 1; p<=n; p++)
    	    {
    	        for(int q = 0; q<p; q++)
    	        {
    	            cout << arr[index] << " \n"[q == p-1];
    	            index++;
    	        }
    	    }
	    }
	}
    return 0;
}
