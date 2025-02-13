#include "testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  auto N = opt<int>("N");
  auto M = opt<int>("M");
  auto L = opt<int>("L");
  auto K = opt<int>("K");
  auto Q = opt<int>("Q");
  println(N);
  println(M);
  for (int i = 0; i < N; ++i) {
    println(string(L, 'a'));
  }
  println(K);
  string ki(Q, 'a');
  for (int i = 0; i < K; ++i) {
    for (int j = Q / 2; j < Q; ++j) {
      if (++ki[j] > 'z')
        ki[j] = 'a';
      else
        break;
    }
    println(ki);
  }
}
