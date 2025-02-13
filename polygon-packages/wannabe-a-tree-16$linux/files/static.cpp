#include "testlib.h"

using i64 = long long;

using recr = std::function<void(i64)>;

int n = 500'000;

void prnt(std::vector<i64> vec) {
    std::sort(vec.begin(), vec.end());
    println(vec.size());
    println(vec);
}

void f0() {
    std::vector<i64> vec;
    recr f = [&](i64 idx) {
        if (idx >= n) {
            return;
        }
        vec.push_back(idx);
        f(2 * idx);
        f(2 * idx + 1);
    };
    f(2);
    prnt(vec);
}

void f1() {
    std::vector<i64> vec;
    i64 z = 1024;
    i64 x = 1;
    x *= z;
    for (i64 y = x + 1; y < x + z; ++y) {
        vec.push_back(y);
    }
    x *= z;
    for (i64 y = x + 1; y < x + z; ++y) {
        vec.push_back(y);
    }
    x *= z;
    for (i64 y = x + 1; y < x + z; ++y) {
        vec.push_back(y);
    }
    x *= z;
    for (i64 y = x + 1; y < x + z; ++y) {
        vec.push_back(y);
    }
    x *= z;
    for (i64 y = x + 1; y < x + z; ++y) {
        vec.push_back(y);
    }
    x *= z / 2;
    for (i64 y = x + 1; y < x + z / 2; ++y) {
        vec.push_back(y);
    }
    for (i64 i = 0; vec.size() < n; ++i) {
        i64 w = (z + 1) * z * z * z * z;
        vec.push_back(w + i);
    }
    prnt(vec);
}

void f2() {
    std::vector<i64> vec;
    i64 z = 1024;
    i64 x = 1;
    x *= z;
    for (i64 y = x + 1; y < x + z; ++y) {
        vec.push_back(y);
    }
    x *= z;
    for (i64 y = x + 1; y < x + z; ++y) {
        vec.push_back(y);
    }
    x *= z;
    for (i64 y = x + 1; y < x + z; ++y) {
        vec.push_back(y);
    }
    x *= z;
    for (i64 y = x + 1; y < x + z; ++y) {
        vec.push_back(y);
    }
    x *= z;
    for (i64 y = x + 1; y < x + z; ++y) {
        vec.push_back(y);
    }
    x *= z / 2;
    for (i64 y = x; y < x + z / 2; ++y) {
        vec.push_back(y);
    }
    for (i64 i = 0; vec.size() < n; ++i) {
        i64 w = (z + 1) * z * z * z * z;
        vec.push_back(w + i);
    }
    prnt(vec);
}

void f3() {
    std::vector<i64> vec(n);
    for (int i = 0; i < n; ++i) {
        vec[i] = n + i;
    }
    prnt(vec);
}

void f4() {
    std::vector<i64> vec;
    i64 x = 3;
    for (int i = 0; i < 59; ++i) {
        vec.push_back(x);
        x = 2 * x - 1;
    }
    for (int i = 0; vec.size() < n; ++i) {
        i64 y = 3LL * (1LL << 58);
        vec.push_back(y + i);
    }
    prnt(vec);
}

using fns = void(*)();
fns arr[] = {f0, f1, f2, f3, f4};

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);
    int idx = opt<int>("idx");
    arr[idx]();
}
