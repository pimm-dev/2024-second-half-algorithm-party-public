#include <bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char** argv) {
    
    const int N = 200000;
 
    int pos = 100000000;
    cout << N << "\n";
    for (int i = 0; i < N; i++) {
        if (i%2 == 1) {
            cout << 2 << "\n";
        }
        else {
            if (i%4 == 0) {
                cout << 1 << " " << pos << "\n";
            }
            else {
                cout << 1 << " " << -pos << "\n";
            }
        }
    }
}
