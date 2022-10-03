#include <iostream>

#include "complex_tpl.h"

using namespace std;

int main() {
  int i = 7;
  cout << "i=" << i << endl;

  complex_tpl<double> c1(2.1, 2.5);
  cout << c1.real() << " " << c1.imag() << endl;

  return 0;
}
