#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    const int N = opt<int>("N");
    const int M = opt<int>("M");
    
    const int K = opt<int>("K");
    const int C = opt<int>("C");
    
    const int CntW = opt<int>("CntW");
    const int CntH = opt<int>("CntH");

    int total_cells = N * M;
    int s_pos = rnd.next(0, total_cells - 1);
    int e_pos;
    do {
        e_pos = rnd.next(0, total_cells - 1);
    } while (e_pos == s_pos);

    int s_row = s_pos / M;
    int s_col = s_pos % M;
    int e_row = e_pos / M;
    int e_col = e_pos % M;
    
    vector<string> grid(N, string(M, '.'));

    grid[s_row][s_col] = 'S';
    grid[e_row][e_col] = 'E';
    
    vector<int> positions;
    for (int i = 0; i < total_cells; ++i) {
        if (i != s_pos && i != e_pos) {
            positions.push_back(i);
        }
    }

    shuffle(positions.begin(), positions.end());
    
    for (int i = 0; i < CntH; ++i) {
        int pos = positions[i];
        int row = pos / M;
        int col = pos % M;
        grid[row][col] = 'H';
    }

    for (int i = 0; i < CntW; ++i) {
        int pos = positions[positions.size() - 1 - i];
        int row = pos / M;
        int col = pos % M;
        grid[row][col] = '#';
    }
    
    cout << N << " " << M << endl;
    cout << K << " " << C << endl;
    for (int i = 0; i < N; ++i) {
        cout << grid[i] << endl;
    }

    return 0;
}
