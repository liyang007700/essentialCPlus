#ifndef __MYSTACK__
#define __MYSTACK__

#include<vector>
#include<string>
using namespace std;

class Stack {
  public:
    bool push(const string&); // 默认inline
    bool pop(string &elem);
    bool peek(string &elem);

    bool empty();
    bool full();

    int size() {
      return _stack.size();
    }

    int max_size() { return _max_size; }
  private:
    vector<string> _stack;
    int _max_size;
};

inline bool
Stack::empty() { // :: 类作用域解析操作符
  return _stack.empty();
}

bool
Stack::pop(string &elem) {
  if (empty()) return false;

  elem = _stack.back();
  _stack.pop_back();
  return true;
}

inline bool
Stack::full() {
  return _stack.size() == _stack.max_size();
}
#endif