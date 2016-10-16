#include <cmath>
#include <limits>
#include <iostream>
#include "../base/Fraction.h"
using namespace std;

int main() {
  int f = INFINITY;
  cout <<  isinf(f);
    cout << std::numeric_limits<Fraction>::max();
  return 0;
}
