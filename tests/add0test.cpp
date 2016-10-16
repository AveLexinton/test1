#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
  vector<double> vd{0.3,0.001,0.004,0.031};
  double a = accumulate(vd.begin(), vd.end(),0);
  cout << a;
  return 0;
}
