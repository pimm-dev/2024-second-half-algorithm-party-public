#include <bits/stdc++.h>
 
using namespace std;

 
int main(int argc, char** argv) {
    
    const int N = 200000;

    cout << N << "\n";
    int posP = 100000000;
    int posN = -100000000;
    int interval = 2000;
    for (int i = 0; i < N-1; i++) {
        if (i%2 == 0) {
            cout << 1 << " " << posP << "\n"; 
            posP -= interval;
        }
        else {
            cout << 1 << " " << posN << "\n"; 
            posN += interval;
        }
    }
    cout << 2 << "\n";
}
