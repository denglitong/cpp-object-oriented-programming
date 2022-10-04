//
// Created by Litong Deng on 2022/10/3.
//

#include "Complex.h"

double Complex::real() const { return re; }

double Complex::image() const { return im; }

Complex& Complex::operator+=(const Complex& rhs) { return __doapl(this, rhs); }

Complex operator+(const Complex& lhs, const Complex& rhs) {
  // 此处需要以值返回，因为是内部新建的临时对象，不能以引用返回
  return Complex(lhs.real() + rhs.real(), lhs.image() + rhs.image());
}

Complex operator+(const Complex& x) { return x; }

Complex operator-(const Complex& x) { return Complex(-x.real(), -x.image()); }

bool operator==(const Complex& x, const Complex& y) {
  return x.real() == y.real() && x.image() == y.image();
}

Complex conj(const Complex& x) { return Complex(x.real(), -x.image()); }

ostream& operator<<(ostream& os, const Complex& x) {
  return os << '(' << x.real() << "," << x.image() << ")";
}
