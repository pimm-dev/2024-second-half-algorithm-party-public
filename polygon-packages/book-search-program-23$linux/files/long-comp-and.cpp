#include "testlib.h"
using namespace std;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  auto N = opt<int>("N");
  auto M = opt<int>("M");
  auto A = opt<int>("A");
  auto B = opt<int>("B");
  auto K = opt<int>("K");
  string author = "aa";
  println(N);
  for (int i = 0; i < N; ++i) {
    println(string(A, 'a'), author);
    author[0]++;
    if (author[0] > 'z') {
      author[0] = 'a';
      author[1]++;
    }
  }
  println(M);
  string pat(B, 'a');
  string q = "ni:";
  q += pat;
  for (int j = 1; j < K; ++j) {
    q += ", ni:";
    q += pat;
  }
  for (int i = 0; i < M; ++i) {
    println(q);
  }
}
