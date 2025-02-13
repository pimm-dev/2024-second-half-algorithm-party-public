#include "testlib.h"
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;

const int MAX = 1005;
 
int dp[MAX][MAX];
int ind[MAX][MAX];
int pyramid[MAX][MAX];
int hapD[MAX][MAX];
int hapH[MAX][MAX];
int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	
	
	int n = stoi(argv[1]);
	int maxAi = stoi(argv[2]);
	
	int t = min(65536,1000000/(n*n));
	cout << t << "\n";
	while(t--)
	{
	    
    	for(int i = 0; i<n+5; i++)
        {
            for(int j = 0; j<n+5; j++)
            {
                dp[i][j] = 0;
                pyramid[i][j] = 0;
                hapD[i][j] = 0;
                hapH[i][j] = 0;
                ind[i][j] = 0;
            }
        }
        int secondWin = t&1;
        int k = rnd.next(1,n);
        int c = (n-k+1)*(n-k+2)/2;
    	int minus1 = rnd.next(0,c);
    	cout << n << " " << k << "\n";
    	
    	vector<int> hubo;
    	for(int i = 0; i<c; i++)
    	    hubo.push_back(i);
    	    
    	shuffle(all(hubo));
    	set<int> st;
    	for(int i = 0; i<minus1; i++)
    	{
    	    st.insert(hubo[i]);
    	}
    	
    	int index =0 ;
    	
    	for(int i = 0; i<n; i++)
    	{
    	    for(int j = 0; j<=i; j++)
    	    {
    	        if(st.count(index))
    	            pyramid[i][j] = -1;
    	        index++;
    	    }
    	}
    	
    	
    	
    	int grundy = 0;
        for(int i = n-k; i>=0; i--)
        {
            for(int j = 0; j<=i; j++)
            {
                if(pyramid[i][j] != -1) 
                    pyramid[i][j] = rnd.next(0,maxAi);
                dp[i][j] = dp[i+1][j]+hapD[i+1][j+1]-hapD[i+k+1][j+k+1]-hapH[i+k][j+k];
                if(j != 0)
                    dp[i][j]+=hapH[i+k][j-1];
        
                if(dp[i][j]%2 == 0 && pyramid[i][j] != -1)
                {
                    dp[i][j]++;
                    hapH[i][j]++;
                    hapD[i][j]++;
                    ind[i][j] = 1;
                    grundy^=pyramid[i][j];
                }
                if(j != 0)
                    hapH[i][j]+=hapH[i][j-1];
                hapD[i][j]+=hapD[i+1][j+1];
            }
        }
        for(int i = n-k+1; i<n; i++)
        {
            for(int j = 0; j<=i; j++)
            {
                pyramid[i][j] = rnd.next(-1,maxAi);
            }
        }
        
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<=i; j++)
            {
                if(ind[i][j] && secondWin)
                {
                    if((pyramid[i][j]^grundy) <= 1'000'000'000)
                    {
                        pyramid[i][j]^=grundy;
                        i = n;
                        break;
                    }
                }
            }
        }
        
        
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<=i; j++)
                cout << pyramid[i][j] << " \n"[j == i];
        }
	}
    return 0;
}
