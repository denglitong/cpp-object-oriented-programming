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

  const Complex c4(2, 1);

  cout << "c3: " << c3.real() << " " << c3.image() << endl;
  cout << c4.real() << " " << c4.image() << endl;
  c3 += c4;
  cout << "c3: " << c3.real() << " " << c3.image() << endl;

  return 0;
}
