/*
ex. 
gen_ml1 -N=100 -M=100 -Option=0 > $
*/
#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
char state[102][102];

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    
    //N>=3 && M>=3
    const int N = opt<int>("N");
    const int M = opt<int>("M");
    const int K = opt<int>("K");
    const int C = opt<int>("C");
    assert(N>=3 && M>=3);
    //only get 0,1
    const int option = opt<int>("Option");
    assert(option==0 || option==1);
    
    cout<<N<<" "<<M<<"\n";
    cout<<K<<" "<<C<<"\n";
    
    for(int i=1;i<=N;i++){
    	for(int j=1;j<=M;j++){
    		if(option==0){
    			if(i%2!=j%2)state[i][j] = 'H';
		    	else state[i][j]='.';
			}
			else{
				if(i%2==j%2)state[i][j] = 'H';
		    	else state[i][j]='.';
			}
		}
	}
	state[1][1] = 'S';
	state[N-1][M] = '#';
	state[N][M-1] = '#';
	state[N][M] = 'E';
	
	for(int i=1;i<=N;i++){
    	for(int j=1;j<=M;j++){
    		cout<<state[i][j];
    	}
    	cout<<"\n";
    }
}
