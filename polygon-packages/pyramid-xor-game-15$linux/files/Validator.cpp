#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv){
    registerValidation(argc, argv);
    
    int T = inf.readInt(1,65'536,"T");
    inf.readEoln();
    int cntN = 0;
    while(T--)
    {
        int N = inf.readInt(1, 1'000, "N");
        inf.readSpace();
        int K = inf.readInt(1, 1'000, "K");
        ensuref(N >= K, "N < K");
        inf.readEoln();
        
        for(int i = 1; i<=N; i++)
        {
            vector<int> arr = inf.readInts(i,-1,1'000'000'000, "wrong seq");
            inf.readEoln();
        }
        cntN+=N*N;
    }
    ensuref(cntN <= 1'000'000, "sum of N^2 is over 1'000'000");
    inf.readEof();
    return 0;
}
