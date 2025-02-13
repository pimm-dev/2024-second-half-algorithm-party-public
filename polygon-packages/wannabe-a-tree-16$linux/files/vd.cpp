#include "testlib.h"

int main(int argc, char **argv) {
    registerValidation(argc, argv);
    
    int n = inf.readInt(1, 500'000, "n");
    inf.readEoln();
    
    auto vec = inf.readLongs(n, 1, ((1LL<<60)-1), "vec");
    inf.readEoln();
    
    for (int i = 0; i < n; ++i) {
        vec[i] -= i;
    }
    ensuref(std::is_sorted(vec.begin(), vec.end()), "not sorted");
    
    inf.readEof();
}
