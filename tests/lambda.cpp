#include <iostream>
using namespace std;

int main() {
  int a = 3;
  int res = [a](int b)mutable{return a=33+b;}(10);
  cout << res << endl;
  cout << a;
  return 0;
}
