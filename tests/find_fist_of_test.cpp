#include <iostream>
#include <string>
using namespace std;

int main() {
  string s1("abcdefghi");
  string::size_type pos = s1.find("cmm");
  if (string::npos == pos)
    cout << "not found" << endl;
  else
    cout << pos << endl;
  return 0;
}
