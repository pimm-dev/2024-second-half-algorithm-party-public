#include "testlib.h"
using namespace std;
int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  auto N = opt<int>("N");
  auto M = opt<int>("M");
  auto L = opt<int>("L");
  auto K = opt<int>("K");
  string si(L, 'a');
  println(N);
  println(M);
  for (int i = 0; i < N; ++i) {
    si[i] = 'b';
    println(si);
    si[i] = 'a';
  }
  println(K);
  vector<string> k;
  string ki(L, 'a');
  for (int i = 0; i < K; ++i) {
    ki[i + 1] = 'b';
    k.push_back(ki);
    ki[i + 1] = 'a';
  }
  shuffle(begin(k), end(k));
  for (auto &ki : k)
    println(ki);
}
