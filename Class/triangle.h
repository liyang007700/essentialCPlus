#pragma once
#include<vector>
using namespace std;
int ia[8] = {1, 2, 3, 4, 5, 6};
class Triangular {
  public:
    Triangular(int len, int bg)
      : _length(len), _beg_pos(bg), _elems(ia, ia + 8)
    {};
    Triangular(int len)
      : _length(len), _beg_pos(1), _elems(ia, ia + 8)
    {};
    int length() const { return _length; }
    int beg_pos() const { return _beg_pos; }
    int elem(int pos) const;

    bool next(int &val) const;
    void next_reset() const { _next = _beg_pos - 1; }

  private:
    int _length;
    int _beg_pos;
    mutable int _next;

    vector<int> _elems;
};

int Triangular::elem(int pos) const {
  return _elems.at(pos);
}

bool Triangular::next(int &value) const {
  if (_next < _beg_pos + _length - 1) {
    cout << _elems.size() << _next << endl;
    value = _elems.at(_next++);
    cout << _next << endl;
    return true;
  }
  return false;
}

Triangular& Triangular::
copy(const Triangular &rhs) {
  if (this != &rhs) {
    _length = rhs._length;
    _beg_pos = rhs._beg_pos;
    _next = rhs._beg_pos - 1;
  }
  return *this;
}