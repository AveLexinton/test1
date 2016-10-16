#include <iostream>
using namespace std;

int main() {
  float f = 0.000000000000000000000000001; //10^-28
  if (f == 0)
    cout << "zero" << endl;
  else 
    cout << "not zero" << endl;
  return 0;
}
