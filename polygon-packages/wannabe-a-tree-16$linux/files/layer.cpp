#include "testlib.h"
#include <numeric>
using namespace std;
int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  auto N = opt<int>("N");
  auto A = opt<long long>("A");
  vector<long long> v(N);
  iota(begin(v), end(v), A);
  println(N);
  println(v);
}
