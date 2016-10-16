#include <iostream>
using namespace std;

int main() {
  string s("153.23");
  cout << s << endl;
  double d = stoi(s);
  cout << d+100 << endl;
  return 0;
}
