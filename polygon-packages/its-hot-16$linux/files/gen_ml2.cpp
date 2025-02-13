/*
ex. 
gen_ml2 -X=100 -Y=100 -N=50 -A=1
*/
#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
char state[102][102];

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    
    //X>=3 && Y>=3 && N>=2 && A<=N
    const int X = opt<int>("X");
    const int Y = opt<int>("Y");
    const int N = opt<int>("N");
    const int A = opt<int>("A");
    assert(X>=3 && Y>=3 && N>=2 && A<=N);
    
    cout<<X<<" "<<Y<<"\n";
    cout<<1<<" "<<1<<"\n";
    
    for(int i=1;i<=X;i++){
    	for(int j=1;j<=Y;j++){
    		if (i%N==A && j%N==A)state[i][j]='H';
    		else state[i][j]='.';
		}
	}
	state[1][1] = 'S';
	state[X-1][Y] = '#';
	state[X][Y-1] = '#';
	state[X][Y] = 'E';
	
	for(int i=1;i<=X;i++){
    	for(int j=1;j<=Y;j++){
    		cout<<state[i][j];
    	}
    	cout<<"\n";
    }
}
