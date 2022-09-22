#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "NumericSeq.h"
using namespace std;

// void display_message( string, vector<int> &);

template <typename T>
void display_message( const string &msg, const vector<T> &vec) {
  cout << msg;
  for ( int ix = 0; ix < vec.size(); ++ix) {
    elemType t = vec[ix];
    cout << t << " ";
  }
}



void display(vector<int> &vec, ostream &os = cout) {
  for (int ix = 0; ix < vec.size(); ++ix)
    os << vec[ix] << " ";
  os << endl;
}

void swap(int & val1, int & val2) {
  int temp = val1;
  val1 = val2;
  val2 = temp;
}

void bubble_sort(vector<int> &vec, ofstream *ofil = 0) {
  for (int ix = 0; ix < vec.size(); ix++) {
    for (int jx = ix + 1; jx < vec.size(); ++jx) {
      if (vec[ix] > vec[jx]) {
        (*ofil) << "about to call swap! ix: " << ix
             << " jx: " << jx << "\tswapping: "
             << vec[ix] << " with " << vec[jx] << endl;
        swap(vec[ix], vec[jx]);
      }
    }
  }
}

int main() {
  int ia[8] = { 8, 34, 3, 13, 1, 21, 5, 2 };
  vector<int> vec(ia, ia + 8);

  cout << "vector before sort: ";
  display(vec);
  ofstream ofil("text_out1");
  bubble_sort(vec, &ofil);
  cout << "vector after sort: ";
  display(vec);
  display_message("template function", vec);
}

