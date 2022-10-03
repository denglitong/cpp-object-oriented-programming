#include <iostream>

#include "Complex.h"
#include "complex_tpl.h"

using namespace std;

int main() {
  int i = 7;
  cout << "i=" << i << endl;

  complex_tpl<double> c1(2.1, 2.5);
  complex_tpl<int> c2(2, 5);
  cout << c1.real() << " " << c1.imag() << endl;
  cout << c2.real() << " " << c2.imag() << endl;

  Complex c3(2.1, 2.5);
  Complex *ptr = new Complex(4);

  return 0;
}
