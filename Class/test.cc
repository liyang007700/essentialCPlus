#include<iostream>
#include"triangle.h"
#include"stack.h"
using namespace std;

int sum(const Triangular &trian) {
  if (!trian.length()) {
    return 0;
  }
  int val, sum = 0;
  trian.next_reset();
  while (trian.next(val)) {
    sum += val;
  }
  return sum;
}

int main() {
  const Triangular trian(4, 2);
  cout << sum(trian) << endl;
  return 0;
}