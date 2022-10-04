//
// Created by Litong Deng on 2022/10/3.
//

#ifndef CPP_OBJECT_ORIENTED_PROGRAMMING_COMPLEX_H
#define CPP_OBJECT_ORIENTED_PROGRAMMING_COMPLEX_H

#include <iostream>

using namespace std;

/**
 * 类内部没有包含指针成员的，多数情况下不需要 析构函数；
 *
 * 1.数据成员要放在 private
 * 2.参数和返回值尽量用 reference 来传
 * 3.能加 const 的参数和返回值尽量加上
 * 4.构造函数的initialization list可以简化
 */
class Complex {
 private:
  double re, im;

 public:
  Complex(double r = 0, double i = 0) : re(r), im(i) {}

  Complex& operator+=(const Complex&);

  double real() const;

  double image() const;

 private:
  // any definitions in header file should be inline
  // and any definitions in source file should not be inline
  inline friend Complex& __doapl(Complex* lhs, const Complex& rhs) {
    lhs->re += rhs.re;
    lhs->im += rhs.im;
    // 返回值为堆上的对象，此时应该返回 引用；
    // 如果返回值为栈上的变量，此时应该返回 值，因为栈上变量随函数结束而销毁；

    // *lhs 返回是以对象值的形式返回，但是函数声明里的返回类型是对象的引用
    // 结论：传递者无需知道接受者是以 reference 形式接收
    // c2 += c1; // 此时的 c1 是以值传递进来的，但是接受者是以 reference 接收的
    return *lhs;
  }
};

// global function
// 声明应该放在 .h 文件中，定义应该放在 .cpp文件中
// 头文件会被引用多次，如果定义也放在头文件，则会第二次引入的时候提示函数已被定义的错误
// 函数声明可以声明多次，但是函数定义只能有一次
Complex operator+(const Complex& lhs, const Complex& rhs);

// 取正
Complex operator+(const Complex& x);

// 取反
Complex operator-(const Complex& x);

bool operator==(const Complex& x, const Complex& y);

// 共轭复数
Complex conj(const Complex& x);

// 重载 << 输出到 ostream
// cout << Complex, cout 是第一个参数 ostream& os, Complex 是第二个参数
ostream& operator<<(ostream& os, const Complex& x);

#endif  // CPP_OBJECT_ORIENTED_PROGRAMMING_COMPLEX_H
