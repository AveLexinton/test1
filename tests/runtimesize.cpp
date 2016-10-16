#include <iostream>
#include <vector>
using namespace std;

int fun1(int size) {
  vector<int> v(size);
  v.push_back(100);
  return v.size();
}

class A{
public:
  int a;
public:
  A(int ta):a(ta){cout << "constructor" << endl;};
  A(const A& ta) {a=ta.a;cout << "copy constructor" << endl;}
  A& operator=(const A& ta){if (this != &ta){a=ta.a;}cout << "assignment operator" << endl;}
  /*A(const A&& ta){
    cout << "move constructor invoked!" << endl;
    a = ta.a;
  }*/
};

int main() {
  int &t = 1;
  //A a(100);
  //A b(1000);
  //a = b;
  //vector<int> v(0);
  //A b(10);
  //b = a;
  //cout << b.a;
  //A b = move(a);
  //cout << a.a << endl << b.a << endl;
//  cout << fun1(10) << endl;
  //vector<int> v;
  //cout << v[0] << endl;
  return 0;
}
