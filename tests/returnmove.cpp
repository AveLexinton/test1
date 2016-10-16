#include <iostream>
using namespace std;

class A {
public:
  int x;
public:
  A(int t = 0):x(t){cout <<"constructor"<< endl;}  
  A(const A& a) {x=a.x; cout << "copy constructor" << endl;}
  A& operator=(const A& b) {
    cout << "assignment" << endl;
    if (this != &b) {
      x = b.x;
    }
    return *this;
  }
  A(const A&& a) {
    x = a.x;
    cout << "move constructor" << endl;
  }
  A& operator=(const A&& a) {
    cout << "move assignment" <<endl;
    if (this != &a) {
      x = a.x;
    }
  }
  ~A() {
    cout << "destructor" << endl;
  }
};

A fun() {
  A a(100);
  a.x+=200;
  return a;
}
int main() {
  A a = fun();
  cout << a.x;
  return 0;
}
