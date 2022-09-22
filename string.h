#ifndef __MYSTRING__
#define __MYSTRING__

class String
{
  public:
    String(const char* cstr = 0);
    String(const String& str); // 拷贝构造
    String& operator=(const String& str); // 拷贝赋值
    ~String(); // 析构函数 死亡时调用
    char* get_c_str() const { return m_data; }
  private:
    char* m_data;
};

inline
String::String(const char* cstr = 0) {
  if (cstr) {
    m_data = new char[strlen(cstr)+1]; // 包含结束符号
    strcpy(m_data, cstr);
  }
  else {
    m_data = new char[1];
    *m_data = '\0';
  }
}

inline
String::String(const String& str)
{
  m_data = new char[strlen(str.m_data) + 1];
  strcpy(m_data, str.m_data);
}

inline
String& String::operator=(const String& str) { // & reference
  if (this == &str) return *this; // &取地址，得到指针

  delete[] m_data;
  m_data = new char[strlen(str.m_data) + 1];
  strcpy(m_data, str.m_data);
  return *this; // return出去，不关心接收是值还是引用
}

{
  String s1(),
  String s2("Hello");

  String* p = new String("Hello");
  delete p; // 唤起1次dtor
  // 结束时调用三次析构函数

  String* p1 = new String[3];
  delete[] p1; // 唤起n次dtor
}

inline
String::~String() {
  delete[] m_data; //释放动态分配的内存，否则泄漏
}

#include <iostream.h>
ostream& operator<<(ostream& os, const String& str) {
  os << str.get_c_str();
  return os;
}

#endif

int main() {
  String s1();
  String s2("hello");

  String s3(s1);
  s3 = s2;
}