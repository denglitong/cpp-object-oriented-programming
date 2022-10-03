//
// Created by Litong Deng on 2022/10/3.
//

#include "Complex.h"

double Complex::real() const { return re; }

double Complex::image() const { return im; }

Complex& Complex::operator+=(const Complex& rhs) { return __doapl(this, rhs); }