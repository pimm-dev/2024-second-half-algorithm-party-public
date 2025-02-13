#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv){
    registerValidation(argc, argv);
    
    int n = inf.readInt(2, 10000, "n");
    inf.readEoln();
    
    set<string> st;
    for(int i = 0;i < n;i++)
    {
      string s = inf.readToken("[a-z]{1,1000}","S");
      
      ensuref(s.size() % 2 == 0, "s size is not even");
      ensuref(s.size() <= 1000, "s length sum is too big");
      st.insert(s);
      inf.readEoln();
    }
    
    ensuref((int)st.size() == n, "s is unique");

    inf.readEof();
    
    return 0;
}
