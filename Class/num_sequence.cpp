#include<iostream>
#include"classMemberPointer.h"

using namespace std;

int main() {
  const int num_sequence::num_seq;
  vector<vector<int> > num_sequence::seq(num_seq);
  num_sequence::PtrType
    num_sequence::func_tbl[num_seq] = {
      0,
      &num_sequence::fibonacci,
      &num_sequence::pell,
      &num_sequence::lucas,
      &num_sequence::square,
      &num_sequence::pentagonal
    }

  num_sequence ns;
  const int pos = 8;
  for (int ix = 1; ix < num_sequence::number_of_sequence(); ++ix) {
    ns.set_sequence(num_sequence::ns_type(ix));
    int elem_val = ns.elem(pos);
    display(cout, ns, pos, elem_val);
  }
}