#include "testlib.h"

using i64 = long long;

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    i64 ubd = opt<i64>("ubd");
    println(n);
    
    auto vec = rnd.distinct(n, 1LL, ubd);
    std::sort(vec.begin(), vec.end());
    println(vec);
}
