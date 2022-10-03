//
// Created by Litong Deng on 2022/10/3.
//

#include "Complex.h"

double Complex::image() const { return im; }

Complex& Complex::operator+=(const Complex& rhs) {
  // 同一个class的各个objects互为friends（友元）
  // 所以这里 rhs 可以直接取私有成员
  this->re += rhs.re;
  this->im += rhs.im;
  return *this;
}