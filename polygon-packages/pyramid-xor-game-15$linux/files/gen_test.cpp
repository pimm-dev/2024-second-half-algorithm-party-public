#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);



    int n = stoi(argv[1]);
    int m = n * (n + 1) / 2;
    int k = stoi(argv[2]);
    int maxAi = stoi(argv[3]);
    int c = 1;

    int t = 1;
    cout << 1 << "\n";

    cout << n << " " << k << "\n";
    vector<int> arr;

    for (int p = 0; p < m; p++)
    {
        int h = rnd.next(0, 2);
        if (h == 0)
            arr.push_back(-1);
        else
            arr.push_back(rnd.next(0, maxAi));
    }

    int index = 0;
    for (int p = 1; p <= n; p++)
    {
        for (int q = 0; q < p; q++)
        {
            cout << arr[index] << " \n"[q == p - 1];
            index++;
        }
    }
    return 0;
}

