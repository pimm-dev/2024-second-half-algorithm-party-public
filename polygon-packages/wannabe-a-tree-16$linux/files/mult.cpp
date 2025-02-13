#include "testlib.h"

using i64 = long long;

int n = 200'000;

void prnt(std::vector<i64> vec) {
    std::sort(vec.begin(), vec.end());
    println(vec.size());
    println(vec);
}

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);
    i64 k = opt<i64>("k");
    std::vector<i64> vec;
    
    vec.push_back(2);
    for (i64 i = k; vec.size() < n; i += k) {
        vec.push_back(i);
    }
    prnt(vec);
}
