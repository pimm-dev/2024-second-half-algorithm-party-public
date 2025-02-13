#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv){
    registerValidation(argc, argv);
    
    int N = inf.readInt(2,100,"N");
    inf.readSpace();
    int M = inf.readInt(2,100,"M");
    inf.readEoln();
    
    int K = inf.readInt(1,100,"K");
    inf.readSpace();
    int C = inf.readInt(1,100,"C");
    inf.readEoln();
    
    vector<string> arr(N);
    vector<int> cnt(200);
    for(int i = 0; i<N; i++)
    {
        arr[i] = inf.readString("[.#SEH]{"+ to_string(M)+ "}","s");
        
        for(int j = 0; j<M; j++)
            cnt[arr[i][j]]++;
    }
    ensuref(cnt['S'] == 1 && cnt['E'] == 1, "S or E cnt not equal 1");
    inf.readEof();
    
    return 0;
}
