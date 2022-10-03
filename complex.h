//
// Created by Litong Deng on 2022/10/3.
//

#ifndef CPP_OBJECT_ORIENTED_PROGRAMMING_COMPLEX_H
#define CPP_OBJECT_ORIENTED_PROGRAMMING_COMPLEX_H

class complex {
 public:
  explicit complex(double r = 0, double i = 0) : re(r), im(i) {}
  complex& operator+=(const complex&);
  double real() const { return re; }
  double imag() const { return im; }

 private:
  double re, im;
  friend complex& __doapl(complex*, const complex&);
};

#endif  // CPP_OBJECT_ORIENTED_PROGRAMMING_COMPLEX_H
