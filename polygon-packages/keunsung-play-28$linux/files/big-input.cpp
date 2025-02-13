#include "testlib.h"
using namespace std;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  auto K = opt<int>("K");
  auto T = opt<int>("T");
  println((K + 1) * T);
  for (int i = 0; i < T; ++i) {
    for (int j = 0; j < K; ++j)
      println(1, rnd.next("-[1-9]{8}"));
    println(2);
  }
}
