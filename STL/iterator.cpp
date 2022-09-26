#include<iostream>
#include<vector>
using namespace std;

template <typename elemType>
void display(const vector<elemType> &vec);

int main() {
  const int seq_size = 18;
  vector<int> pell_seq(seq_size);
  pell_seq[0] = 1;
  pell_seq[1] = 1;
  for (int ix = 2; ix < seq_size; ++ix) {
    pell_seq[ix] = pell_seq[ix - 2] + pell_seq[ix - 1];
  }  
  display(pell_seq);
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
find(IterT first, IterT last, const elemType &value) {
  for(; first != last; ++first) {
    if (value == *first) return first;
  }
  return 0;
}