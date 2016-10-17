#include <iostream>
using namespace std;

template<typename T= int>
class A{
public:
T x;
A(T t):x(t){}
};

int main() {
A<> a(100);
cout << a.x;
return 0;
}
