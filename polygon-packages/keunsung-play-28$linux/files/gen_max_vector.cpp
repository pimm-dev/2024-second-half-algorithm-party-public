#include <bits/stdc++.h>
 
using namespace std;

 
int main(int argc, char** argv) {
    
    const int N = 200000;

    cout << N << "\n";
    
    cout << 1 << " " << -100000000 << "\n";
    cout << 2 << "\n";

    int pos = 100000000;
    int interval = -1000;
    for (int i = 0; i < N-3; i++) {
        cout << 1 << " " << pos << "\n"; 
        pos += interval;
    }
    cout << 2 << "\n";
}
