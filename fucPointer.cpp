#include <iostream>
#include <vector>
#include <string>

using namespace std;
const vector<int>* fibon_seq(int);
const vector<int>* fibon_seq(int size) {
  const int max_size = 1024;
  static vector<int> elems;
  if (size <=0 || size > max_size) {
    cerr << "fibon seq(): oops invalid size: "
         << size << " -- can't fulfill request.\n";
  }
  for (int ix = elems.size(); ix < size; ++ix) {
    if (ix == 0 || ix == 1) {
      elems.push_back(1);
    } else {
      elems.push_back(elems[ix - 1] + elems[ix - 2]);
    }
  }
  cout << elems.size() << '\n';
  return &elems;
}
bool seq_elem(int pos, int &elem,
  const vector<int>* (*seq_ptr)(int))
{
  const vector<int> *pseq = seq_ptr(pos);
  if (!pseq) {elem = 0; return false;}
  elem = (*pseq)[pos - 1];
  return true;
}
int main() {
  int elem = 0; 
  const vector<int>* (*seq_ptr)(int) = 0;
  seq_ptr = fibon_seq;
  seq_elem(5, elem, seq_ptr);
  cout << elem << '\n';
  return 0;
}
