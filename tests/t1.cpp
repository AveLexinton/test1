#include <iostream>
using namespace std;

template<class T>
class A{
public:
  void print(){cout << "hi, T" << endl;}
  template<>
  void print() {cout << "hi, int" << endl;}
};

//template<class T>
//void A<T>::print(){cout << "hi, T" << endl;}

//template<>
//void A<int>::print() {cout << "hi, int" << endl;}

int main() {
  Matrix<int> m(2,2);
  cout << m;
  return 0;
}
