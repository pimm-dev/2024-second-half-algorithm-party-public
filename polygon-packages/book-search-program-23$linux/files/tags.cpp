#include "testlib.h"
using namespace std;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  auto N = opt<int>("N");
  auto M = opt<int>("M");
  auto X = opt<int>("X");
  auto Y = opt<int>("Y");
  println(N);
  vector<char> book(X + 1, 'a');
  book.push_back('b');
  for (int i = 0; i < N; ++i) {
    println(book);
    book[0]++;
    if (book[0] > 'z') {
      book[0] = 'a';
      book[1]++;
    }
  }
  println(M);
  string q = "t:b";
  for (int j = 1; j < Y; ++j) {
    q += ", t:b";
  }
  for (int i = 0; i < M; ++i) {
    println(q);
  }
}
