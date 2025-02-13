#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    
    const int maxN = opt<int>("maxN");
    
    int N = rnd.next(1,maxN);
    cout << N << "\n";
    for (int i = 1; i < N; i++) {
        int x = rnd.next(-100'000'000,100'000'000);
        cout << 1 << " " << x << "\n" ;
    }
    cout << 2 << "\n";
}
