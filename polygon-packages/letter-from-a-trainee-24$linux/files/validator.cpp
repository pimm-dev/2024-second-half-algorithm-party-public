#include "testlib.h"
#include <bits/stdc++.h>
#include <set>
#define MAX 300
using namespace std;
set<pair<int,int>> dupl;
int main(int argc, char** argv){
    registerValidation(argc, argv);
    
    int n = inf.readInt(2, MAX, "n");
    inf.readEoln();
    int m = inf.readInt(1, MAX, "m");
    inf.readEoln();
    ensuref(m < n, "m >= n error");
        
    int len = 987654321;
    for(int i = 0; i<n ;i++)
    {
        string s = inf.readString("[a-z.]{2,"+to_string(MAX)+"}","letter error");
        len = min(len,(int)s.size());
    }
    
    int k = inf.readInt(1, MAX, "k");
    inf.readEoln();
    set<string> names;
    for(int i = 0; i<k; i++)
    {
        string s = inf.readString("[a-z]{1,"+to_string(MAX)+"}","name error");
        ensuref((int)s.size()<=len, "name size error");
        ensuref(names.find(s)==names.end(), "dupl name");
        names.insert(s);
    }
    inf.readEof();
    return 0;
}
