//
// Created by Litong Deng on 2022/10/3.
//

#ifndef CPP_OBJECT_ORIENTED_PROGRAMMING_COMPLEX_TPL_H
#define CPP_OBJECT_ORIENTED_PROGRAMMING_COMPLEX_TPL_H

// 类模板，泛型化
template <typename T>
class complex_tpl {
 public:
  explicit complex_tpl(T r = 0, T i = 0) : re(r), im(i) {}
  complex_tpl& operator+=(const complex_tpl&);
  T real() const { return re; }
  T imag() const { return im; }

 private:
  T re, im;
  friend complex_tpl& __doapl(complex_tpl*, const complex_tpl&);
};

#endif  // CPP_OBJECT_ORIENTED_PROGRAMMING_COMPLEX_TPL_H
