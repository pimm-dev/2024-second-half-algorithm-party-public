#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    
    const int N = opt<int>("N");

    cout << N << "\n";
    for (int i = 0; i < N; i++) {
        int q = rnd.next(1,2);
        if (q == 1) {
            int x = rnd.next(-100'000'000,100'000'000);
            cout << q << " " << x << "\n" ;
        }
        else {
            cout << q << "\n";
        }
    }
    
}
