//
// Created by Litong Deng on 2022/10/3.
//

#include "Complex.h"

double Complex::real() const { return re; }

double Complex::image() const { return im; }

Complex& Complex::operator+=(const Complex& rhs) { return __doapl(this, rhs); }

Complex operator+(const Complex& lhs, const Complex& rhs) {
  // 此处需要以值返回，因为是内部新建的临时变量，不能以引用返回
  return Complex(lhs.real() + rhs.real(), lhs.image() + rhs.image());
}