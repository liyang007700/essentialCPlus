#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  const int seq_size = 18;
  // int *p1 = 0; // 空指针的值是0
  // if (!p1) {
  //   cout << "p1 is empty\n";
  // }
  vector<int> pell_seq(seq_size);
  vector<int> *pc = 0;
  pell_seq[0] = 1;
  pell_seq[1] = 1;
  for (int ix = 2; ix < seq_size; ++ix) {
    pell_seq[ix] = pell_seq[ix - 2] + pell_seq[ix - 1];
    cout << pell_seq[ix]
         << "\n";
    }
  pc = &pell_seq;
  cout << pell_seq.size();
  cout << '\n';
  cout << pc->size();
  cout << '\n';
}