#include "testlib.h"
#include <algorithm>
using namespace std;

char next(char c) {
  if (c == '_')
    return 0;
  if (c == '-')
    return '_';
  if (c == 'z')
    return '-';
  if (c == '9')
    return 'a';
  return c + 1;
}

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  auto N = opt<int>("N");
  auto M = opt<int>("M");
  auto X = opt<int>("X");
  auto Y = opt<int>("Y");
  println(N);
  vector<string> book = {"0", "0"};
  string x = "0";
  for (int i = 0; i < X; ++i) {
    book.push_back(x);
    int j;
    for (j = 0; j < x.size(); ++j) {
      x[j] = next(x[j]);
      if (x[j] == 0) {
        x[j] = '0';
      } else {
        break;
      }
    }
    if (j == x.size()) {
      x.push_back('0');
    }
  }
  reverse(begin(book) + 2, end(book));
  for (int i = 0; i < N; ++i) {
    println(book);
    book[0][0] = next(book[0][0]);
    if (book[0][0] == 0) {
      book[0][0] = '0';
      book[1][0] = next(book[1][0]);
    }
  }
  println(M);
  string q = "t:0";
  for (int j = 1; j < Y; ++j)
    q += ", t:0";
  for (int i = 0; i < M; ++i) {
    println(q);
  }
}
