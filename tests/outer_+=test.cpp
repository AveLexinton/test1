#include <iostream>
using namespace std;

class A {
public:
int x;
public:
A(int tx):x(tx) {
}
};

A& operator+= (A& a1, const A& a2) {
  a1.x += a2.x;
  return a1;
}

int main() {
  A a1(1), a2(3);
  a1 += a2;
  cout << a1.x ;
  return 0;
}
