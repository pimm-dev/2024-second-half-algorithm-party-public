#include "testlib.h"
using namespace std;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  auto N = opt<int>("N");
  auto M = opt<int>("M");
  auto K = opt<int>("K");
  auto C = opt<int>("C");
  string a, b;
  for (int i = 0; i < M; ++i) {
    a.push_back('.');
    b.push_back('H');
    a.swap(b);
  }
  vector<string> field;
  for (int i = 0; i < N; ++i)
    field.push_back(i & 1 ? a : b);
  field[0][0] = 'E';
  field[N / 2][M / 2] = 'S';
  println(N, M);
  println(K, C);
  for (auto &line : field)
    println(line);
}
