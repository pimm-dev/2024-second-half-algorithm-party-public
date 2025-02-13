/*
ex. 
gen_snake -IsPossible=0 > $
*/
#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
char state[102][102];
 
int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    
    const int N = 100;
    const int M = 100;

    const int IsPossible = opt<int>("IsPossible");

    cout << N << " " << M << "\n";
    cout << 1 << " " << 99 << "\n";
    
    for(int i = 1; i <= N; i++){
    	for(int j = 1; j <= M; j++){
            state[i][j] = '.';
		}
	}
    
    for(int i = 1; i <= N-2; i+=2){
    	for(int j = 1; j <= M; j+=2){
            state[i][j] = 'H';
		}
	}

    for(int i = 2; i <= N-2; i+=2){
        if (i%4 == 2) {
            for(int j = 1; j <= M-1; j++){
                state[i][j] = '#';
            }
            state[i][M] = 'H';
        }
        else {
            for(int j = 2; j <= M; j++){
                state[i][j] = '#';
            }
        }
	}

    for (int j = 1; j <= M; j+=2) {
        if (j%4 == 1) {
            state[N-1][j] = 'H';
        }
        else {
            state[N-1][j] = '#';
        }
    }

    for (int j = 2; j <= M; j+=2) {
        state[N][j] = 'H';
    }

    for (int j = 1; j <= M; j+=4) {
        state[N][j] = '#';
    }

    if (IsPossible) {
        state[N][1] = 'H';
        state[N-1][2] = 'H';
    }
    else {
        state[N][1] = '.';
        state[N-1][2] = '.';
    }

    state[1][1] = 'S';
    state[N-1][1] = 'E';

	for(int i = 1; i <= N; i++){
    	for(int j = 1; j <= M; j++){
    		cout << state[i][j];
    	}
    	cout << "\n";
    }
}
