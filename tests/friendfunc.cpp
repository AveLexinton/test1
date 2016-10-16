#include <iostream>
using namespace std;
class A;
int getanswer(A& a);

class A{
int x ;
public:
A(int y):x(y){}
friend int getanswer(A& a);
};
int getanswer(A& a){
return a.x+2;
}

int main() {
  A a(10);
  cout << getanswer(a);
  return 0;
}
