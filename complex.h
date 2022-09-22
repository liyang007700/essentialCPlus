#ifndef __COMPLEX__
#define __COMPLEX__
#include <iostream.h>

class complex 
{
  public:
    complex (double r = 0, double i = 0)
      :re(r), im(i)
    { }
    complex& operator += (const complex&);
    double real() const { return re; } // inline 成员函数隐含this指针   this->re;
    double imag() const { return im; }
    static double rate = 0;
    static double& fuc() {}; // 只能存取static data

  private:
    double re, im;

    friend complex& __doapl (complex*, const complex&);
}

inline complex&
__doapl(complex* ths, const complex& r)
{
  ths->re += r.re;
  ths->im += r.im;
  return *ths;
}

inline complex&
complex::operator += (const complex& r) // this
{
  return __doapl(this, r);
}

inline complex
operator + (const complex& x, const complex& y)
{
  return complex (real(x) + real(y), // 临时对象
                  imag(x) + imag(y));
}
ostream&

operator << (ostream& os, const complex& x)
{
  os << '(' << real(x) << ',' << imag(x) << endl;
}

#endif


Complex s3();
{
  Complex c1(1, 2); // stack auto object，自动清理
  static Complex c2(); // 声明周期是整个程序结束

  // 1 分配内存 2 转型 3 构造函数
  Complex* p = new Complex(3); //  heap object
  // 1 调用析构 2 释放内存
  delete p;
  // 作用域之外看不到p，无法delete，内存泄漏
}

{
  complex c1;
  cout << c1.real(); // 等价于 complex::real(&c1);
}