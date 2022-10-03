//
// Created by Litong Deng on 2022/10/3.
//

#ifndef CPP_OBJECT_ORIENTED_PROGRAMMING_COMPLEX_H
#define CPP_OBJECT_ORIENTED_PROGRAMMING_COMPLEX_H

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
  // 参数可以有默认值，
  // 构造函数可以有初始值列 initialization list，即 : re(r), im(i)
  // 一个变量值，有初始化阶段、赋值阶段，放在初始化阶段能提高效率
  // 参数传递：pass by value
  Complex(double r = 0, double i = 0) : re(r), im(i) {}

  // 参数传递：pass by reference (to const)
  // C++ 的引用（类似于 C 中的指针，但比指针更漂亮，底层也是指针）
  // 引用/指针大小是四个字节，常用在大数据变量的传递上；
  // const reference 是不可更改的
  // return by reference
  // 操作符重载，在C++里面就是函数
  Complex& operator+=(const Complex&);

  // inline methods 函数定义在类body里面
  // 但是如果函数很复杂，编译器也无法给它force inline，最后是由编译器决定的
  // 同名函数，重载 overloading
  // return by value
  double real() const;

  // 成员函数分 2 种：一种是会改变成员变量的，另一种是不会改变成员变量的，
  //  对于不会改变成员变量的，声明时加上 const，防止外部取到之后改变数据，
  //  所有的数据改变都要限制在成员函数内部；
  //  防止在外部声明了 const Complex 变量的情况下还能改变成员变量；
  // return by value
  double image() const;

 private:
  // 参数传递：pass by reference (to const)
  // 返回值传递: return by reference (to const)
  // C++ friend 友员可以自由取得对方的 private 成员 而无需通过成员函数
  // do assignment plus
  friend Complex& __doapl(Complex* lhs, const Complex& rhs) {
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

#endif  // CPP_OBJECT_ORIENTED_PROGRAMMING_COMPLEX_H
