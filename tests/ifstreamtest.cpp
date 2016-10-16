#include <iostream>
#include <fstream>
#include <array>
#include <vector>
using namespace std;

int main() {
  ifstream f("1.txt");
  if (f.is_open())
    cout << "open" << endl;
  else 
    cout << "not open" << endl;

  const int len = 30;
  vector<std::array<char,len>> vec;
  //std::array<char, 100> str;
  for(std::array<char,len> str; f.getline(&str[0], len,',');) 
    vec.push_back(str);

  cout << vec.size() << endl;
  for(auto& v: vec)
    cout << &v[0] << endl;
  f.close();
  return 0;
}
