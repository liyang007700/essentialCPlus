#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<algorithm>
using namespace std;

template <typename elemType>
void display(const vector<elemType> &vec);
inline bool greaterThan(int a, int b) {
  return a > b ? true : false;
}
vector<int> filter_ver1(vector<int>& vec, const int filter_value, bool (*pred)(int, int));

int main() {
  const int seq_size = 18;
  vector<int> pell_seq(seq_size);
  pell_seq[0] = 1;
  pell_seq[1] = 1;
  for (int ix = 2; ix < seq_size; ++ix) {
    pell_seq[ix] = pell_seq[ix - 2] + pell_seq[ix - 1];
  }  
  display(pell_seq);
  // array list vector iterator
  const int asize = 8;
  int ia[asize] = {1, 1, 2, 3, 5, 8, 13, 21};
  int *pia = find(ia, ia+asize, 13);
  if (pia != ia+asize) cout << "find" << endl;

  vector<int> ivec(ia, ia+asize);
  vector<int>::iterator it;
  it = find(ivec.begin(), ivec.end(), 2);
  if (it != ivec.end()) cout << "find1" << endl;

  list<int> ilist(ia, ia+asize);
  list<int>::iterator iter;
  iter = find(ilist.begin(), ilist.end(), 3);
  if (iter != ilist.end()) cout << "find2" << endl;

  // deque<int> a_line;
  // int ival;
  // while(cin >> ival) {
  //   a_line.push_back(ival);
  //   int curr_value = a_line.front();
  //   cout << curr_value << a_line.size() << endl;
  //   a_line.pop_front();
  // }

  cout << binary_search(ia, ia+8, 3) << endl;
  vector<int>::iterator i = max_element(ivec.begin(), ivec.end());
  cout << (*i) << endl;
  
  const vector<int> vec = filter_ver1(ivec, 5, greaterThan);
  cout << vec.size() << endl;
  const int& j = vec.at(0);
  cout << j << endl;
}

template <typename elemType>
void display(const vector<elemType> &vec) {
  typename vector<elemType>::const_iterator iter = vec.begin();
  typename vector<elemType>::const_iterator end_it = vec.end();

  for(; iter != end_it; ++iter)
    cout << *iter << " ";
  cout << endl;
}

template <typename IterT, typename T>
IterT
find(IterT first, IterT last, const T &value) {
  for(; first != last; ++first) {
    if (value == *first) return first;
  }
  return 0;
}

vector<int> filter_ver1(vector<int>& vec, const int filter_value, bool (*pred)(int, int)) {
  vector<int> nvec;

  for (auto& v : vec) {
    if (pred(v, filter_value)) nvec.push_back(v);
  }
  return nvec;
}