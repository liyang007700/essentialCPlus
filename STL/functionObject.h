#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
using namespace std;

template <typename InputIter, typename OutputIter, typename ElemType, typename Comp>
OutputIter
filter(InputIter first, InputIter last, OutputIter at, const ElemType &val, Comp pred);

// int main() {
//   int ia[8] = {10, 1, 2, 3, 5, 8, 13, 21};
//   vector<int> vec(ia, ia + 8);
//   sort(vec.begin(), vec.end(), less<int>());
//   std::cout << vec.at(0) << endl;
  
//   int ia2[8];
//   vector<int> ivec(8);
//   filter(ia, ia+8, ia2, 8, less<int>());
//   filter(vec.begin(), vec.end(), ivec.begin(), 8, greater<int>());
// }

template <typename InputIter, typename OutputIter, typename ElemType, typename Comp>
OutputIter
filter(InputIter first, InputIter last, OutputIter at, const ElemType &val, Comp pred) {
  while ((first = find_if(first, last, not1(bind2nd(pred, val)))) != last) {
    cout << "find value: " << *first << endl;
    *at++ = *first++;
  }
  return at;
}