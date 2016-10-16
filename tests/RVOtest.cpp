/**
最好在函数返回值中不使用move和右值引用语义，一是低效，不如RVO，直接返回对象即可．二是返回的是（右值）引用，结果错误．
**/


#include <iostream>
#include <cmath>
using namespace std;

class A{
public:
int x;
  A(int a):x(a){cout << "constructor" << endl;}
  A(const A& a) {
    cout << "copy constructor" << endl;
    x = a.x;
  }
  A& operator=(const A& a) {
    cout << "assignment" << endl;
    if (this != &a) {
      x = a.x;
    }
    return *this;
  }
  A(const A&& a) {
    cout << "move constructor "<< a.x << endl;
    x = a.x;
  }
  A& operator=(const A&& a) {
    cout << "move assignment" << endl;
    if (this != &a) {
      x = a.x;
    }
    return *this;
  }
  ~A() {cout << "destructor" << endl;}
};

A fun(int v=0){
  A ta(10), tb(20);
  if (v==0) {
    return ta;
  } else
    return tb;
}
A func(){
  A a(11);
  return a;
}
int main(){
  //A t(fun(0));
 // cout << t.x;
  float f = HUGE_VAL;
  cout << f << endl;
  if (isinf(f))
    cout << true << endl;
  //A& t = func();
  //cout << t.x << endl;
  //A&& t = fun(0);
  //cout << t.x << endl;
  //A t(30);
 // A t1 = move(t);
  //cout << t.x << endl;
  //cout << t1.x << endl;
  return 0;
}
