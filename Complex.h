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
  Complex(double r = 0, double i = 0) : re(r), im(i) {}

  Complex& operator+=(const Complex&);

  // inline methods 函数定义在类body里面
  // 但是如果函数很复杂，编译器也无法给它force inline，最后是由编译器决定的
  // 同名函数，重载 overloading
  double real() const { return re; }

  // 成员函数分 2 种：一种是会改变成员便利店，另一种是不会改变成员变量的，
  //  对于不会改变成员变量的，声明时加上 const，防止外部取到之后改变数据，
  //  所有的数据改变都要限制在成员函数内部；
  //  防止在外部声明了 const Complex 变量的情况下还能改变成员变量；
  double image() const { return im; }

 private:
  double re, im;
  friend Complex& __doapl(Complex&, const Complex&);
};

#endif  // CPP_OBJECT_ORIENTED_PROGRAMMING_COMPLEX_H
