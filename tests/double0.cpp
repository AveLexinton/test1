#include <iostream>
#include <limits>
using namespace std;

int main() {
  double x = 1.372000001;//1/10e39;
  double y = 2.1131;
 // double y = 13*5*21*10e100;
  double res = y-x*(y/1.372000001);
  if (res == 0) {
    cout << "equals 0" << endl;
  }
  cout <<  std::numeric_limits<double>::epsilon();
  return 0;
}
