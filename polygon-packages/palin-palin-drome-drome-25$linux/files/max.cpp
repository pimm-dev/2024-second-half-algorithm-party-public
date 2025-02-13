#include "testlib.h"
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  auto N = opt<int>("N");
  auto L = opt<int>("L");
  println(N);
  string a(L, 'a');
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < L; ++j) {
      a[j]++, a[L - j - 1]++;
      if (a[j] > 'z')
        a[j] = a[L - j - 1] = 'a';
      else
        break;
    }
    println(a);
  }
}
