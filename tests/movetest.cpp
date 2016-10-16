#include <iostream>
#include <cstring>
using namespace std;

class A {
int y;
public:
    int x;
    char *a;
    A(int tx,int ty):x(tx),y(ty){a=new char(100); memset(a, 0, sizeof(a));a= const_cast<char*>(string("hello").c_str());}
    A(const A&& ta) {
        cout << "move constructor" << endl;
        x = ta.x;
    }
    A(const A& ta){
        cout << "copy" << endl;
        x = ta.x;
        y = ta.y;
    }
    int getY(){return y;}
    void disp(const A& a){
        cout << a.y << endl;
    }
};

int main() {
    A a(100,200);
    A b(a);
    b.disp(A(10000, 113));
  return 0;
}
