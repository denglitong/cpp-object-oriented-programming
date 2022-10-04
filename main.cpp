#include <iostream>

#include "Complex.h"
#include "complex_tpl.h"

using namespace std;

int main() {
  complex_tpl<double> c1(2.1, 2.5);
  complex_tpl<int> c2(2, 5);
  cout << "c1: (" << c1.real() << "," << c1.imag() << ")" << endl;
  cout << "c2: (" << c2.real() << "," << c2.imag() << ")" << endl;

  Complex c3(2.1, 2.5);
  Complex *ptr = new Complex(4);

  const Complex c4(2, 1);

  cout << "c3: " << c3 << endl;
  cout << "c4: " << c4 << endl;
  c3 += c4;
  cout << "c3+=c4: " << c3 << endl;

  Complex c5(1, 2), c6(2, 2), c7;
  c7 = c5 + c6;
  cout << "c5: " << c5 << endl;
  cout << "c6: " << c6 << endl;
  cout << "c7: " << c7 << endl;

  Complex c8 = -c5;
  cout << "c8: " << c8 << ", conj: " << conj(c8) << endl;

  cout << "c5 == c8 " << (c5 == c8) << endl;

  return 0;
}
