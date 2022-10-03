//
// Created by Litong Deng on 2022/10/3.
//

#ifndef CPP_OBJECT_ORIENTED_PROGRAMMING_COMPLEX_H
#define CPP_OBJECT_ORIENTED_PROGRAMMING_COMPLEX_H

/**
 * 类内部没有包含指针成员的，多数情况下不需要 析构函数
 */
class Complex {
 public:
  // 参数可以有默认值，
  // 构造函数可以有初始值列 initialization list，即 : re(r), im(i)
  // 一个变量值，有初始化阶段、赋值阶段，放在初始化阶段能提高效率
  explicit Complex(double r = 0, double i = 0) : re(r), im(i) {}
  // inline methods 函数定义在类body里面
  // 但是如果函数很复杂，编译器也无法给它force inline，最后是由编译器决定的
  double real() const { return re; }
  // 同名函数，重载 overloading
  double real() { return re; }
  double image() const { return im; }

 private:
  double re, im;
  friend Complex& __doapl(Complex&, const Complex&);
};

#endif  // CPP_OBJECT_ORIENTED_PROGRAMMING_COMPLEX_H
