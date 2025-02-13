#include "testlib.h"
using namespace std;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  auto N = opt<int>("N");
  auto L = opt<int>("L");
  auto M = opt<int>("M");
  auto K = opt<int>("K");
  auto Q = opt<int>("Q");
  println(N);
  println(M);
  auto pat = format("[a-z]{%d}", L);
  for (int i = 0; i < N; ++i) {
    println(rnd.next(pat));
  }
  println(K);
  pat = format("[a-z]{%d}", Q);
  for (int i = 0; i < K; ++i) {
    println(rnd.next(pat));
  }
}
