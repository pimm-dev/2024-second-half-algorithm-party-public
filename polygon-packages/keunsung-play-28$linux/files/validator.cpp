#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv){
    registerValidation(argc, argv);
    
    int N = inf.readInt(1, 200000, "N");
    inf.readEoln(); 
    
    for(int i = 0;i< N;i++)
    {
        int val = inf.readInt(1,2,"query val");
        if(val == 1)
        {
            inf.readSpace();
            int X = inf.readInt(-100'000'000,100'000'000,"X");
            inf.readEoln();
        }
        else if(val == 2)
        {
            inf.readEoln();
        } 
    }
    inf.readEof();
    
    return 0;
}
