#include "testlib.h"
#include <numeric>
using namespace std;

std::vector<int> anti_stdsort(int N) {
  std::vector<int> idx(N);
  std::iota(begin(idx), end(idx), 0);
  std::vector<int> assigned(N, -1);
  int l = 0, r = N;
  int high = N;
  assigned[idx[0]] = --high;
  assigned[idx[1]] = 0;
  for (int i = 0; i < std::__lg(N) * 2; ++i) {
    int pivot = l;
    int mid = l + (r - l) / 2;
    int last = r - 1;
    assigned[idx[last]] = --high;
    assigned[idx[mid]] = --high;
    std::swap(idx[mid], idx[pivot]);
    std::swap(idx[mid], idx[last - 1]);
    r = last - 1;
  }
  std::vector<int> rem;
  for (int i = l; i < r; ++i) {
    if (assigned[idx[i]] == -1)
      rem.push_back(idx[i]);
  }
  shuffle(std::begin(rem), std::end(rem));
  int low = 1;
  for (auto i : rem)
    assigned[i] = low++;
  return assigned;
}

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  auto K = opt<int>("K");
  auto T = opt<int>("T");
  auto order = anti_stdsort(K);
  println((K + 1) * T);
  for (int i = 0; i < T; ++i) {
    vector<int> candidate = rnd.distinct(K, -100'000'000, 100'000'000);
    sort(begin(candidate), end(candidate));
    for (int j = 0; j < K; ++j)
      println(1, candidate[order[j]]);
    println(2);
  }
}
