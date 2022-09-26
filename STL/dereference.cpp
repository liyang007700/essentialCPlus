#include<iostream>
#include<vector>
#include<string>

using namespace std;
int ia[8] = {1, 1, 2, 3, 5, 8, 13, 21};
vector<string> svec(2);

template <typename elemType>
elemType* find_pointer(elemType *first, const elemType *last, const elemType &value);

int main() {
  int *pi = find_pointer(ia, ia+8, ia[3]);
  cout << *pi << endl;
  if (!svec.empty()) cout << "not empty";
}

template <typename elemType>
elemType* find_pointer(elemType *first, const elemType *last, const elemType &value)
{
  if (!first || !last) return 0;
  for (; first != last; ++first) {
    if (*first == value) return first;
  }
  return 0;
}