#include <iostream>
using namespace std;

class A {
public:
int x;
A(int tx):x(tx){}
static void print();
};

//static: cannot declare static outsize declaration of class 
void A::print(){
cout << "hello";
}

int main(){
A a(100);
a.print();
return 0;
}
