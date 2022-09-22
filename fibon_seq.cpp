#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
vector<int>* fibon_seq(int);
vector<int>* fibon_seq(int size) {
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
  cout << elems.size();
  return &elems;
}
int main() {
  fibon_seq(4);
  fibon_seq(8);
  fibon_seq(16);
  const vector<int> *elems = fibon_seq(2);
  cout << elems->size() << "log";
  return 0;
}