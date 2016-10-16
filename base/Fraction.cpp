#include <stdexcept>
#include <limits>
#include "Fraction.h"

//自定义Fraction max()
namespace std {
    template<>
    Fraction numeric_limits<Fraction>::max() {
        return Fraction(numeric_limits<int>::max(), 1);
    }
}

//打印
ostream& operator<<(ostream& os, const Fraction& fr){
  if (fr.getFenzi() == 0)
    cout << "0";
  else if (fr == numeric_limits<Fraction>::max())
    cout << "INF";
  else if (fr.getFenmu() == 1) {
    cout << fr.getFenzi();
  } else
    cout << fr.getFenzi() << '/' << fr.getFenmu();
  return os;
}

//分数加法
Fraction operator+(const Fraction& a, const Fraction& b) {
  int afenzi = a.getFenzi();
  int afenmu = a.getFenmu();
  int bfenzi = b.getFenzi();
  int bfenmu = b.getFenmu();
  int rfenzi = afenzi*bfenmu+bfenzi*afenmu;
  int rfenmu = afenmu*bfenmu;
  int gcdres = gcd(rfenzi, rfenmu);
  Fraction res(rfenzi/gcdres, rfenmu/gcdres);
  return res;
}

//分数减法
Fraction operator-(const Fraction& a, const Fraction& b) {
  int afenzi = a.getFenzi();
  int afenmu = a.getFenmu();
  int bfenzi = b.getFenzi();
  int bfenmu = b.getFenmu();
  int rfenzi = afenzi*bfenmu-bfenzi*afenmu;
  int rfenmu = afenmu*bfenmu;
  int gcdres = gcd(rfenzi, rfenmu);
  Fraction res(rfenzi/gcdres, rfenmu/gcdres);
  return res;
}

//分数乘法
Fraction operator*(const Fraction& a, const Fraction& b) {
  int afenzi = a.getFenzi();
  int afenmu = a.getFenmu();
  int bfenzi = b.getFenzi();
  int bfenmu = b.getFenmu();
  int rfenzi = afenzi*bfenzi;
  int rfenmu = afenmu*bfenmu;
  int gcdres = gcd(rfenzi, rfenmu);
  Fraction res(rfenzi/gcdres, rfenmu/gcdres);
  return res;
}

//分数除法
Fraction operator/(const Fraction& a, const Fraction& b) {
  if (b.getFenzi() == 0)
    throw runtime_error("Error: denominator(fenmu) cannot be 0!");

  int afenzi = a.getFenzi();
  int afenmu = a.getFenmu();
  int bfenzi = b.getFenzi();
  int bfenmu = b.getFenmu();
  int rfenzi = afenzi*bfenmu;
  int rfenmu = afenmu*bfenzi;
  int gcdres = gcd(rfenzi, rfenmu);
  Fraction res(rfenzi/gcdres, rfenmu/gcdres);
  return res;
}

//分数加等
Fraction operator+=(Fraction& a, const Fraction& b) {
  return a = a+b;
}

//分数减等
Fraction operator-=(Fraction& a, const Fraction& b) {
  return a = a-b;
}
//分数乘等
Fraction operator*=(Fraction& a, const Fraction& b) {
    return a = a*b; 
}
//分数除等
Fraction operator/=(Fraction& a, const Fraction& b) {
  return a = a/b;
}
//分数相等
bool operator==(const Fraction& a, const Fraction& b) {
    return (a.getFenzi()==0 && b.getFenzi()==0)||(a.getFenzi()==b.getFenzi() && a.getFenmu() == b.getFenmu());
}
//分数不等
bool operator!=(const Fraction& a, const Fraction& b) {
    return !(a==b);
}



int main_fraction() {
  if (Fraction(numeric_limits<int>::max(), 1)==numeric_limits<Fraction>::max())
    cout << "max" << endl;
  else 
    cout << "not max" << endl;
  //Fraction f{0,12};
  //Fraction f2{1,25};
  //cout << f/f2 << endl;
  //Fraction f3("5/6");
  //cout << -f3 << endl;
  return 0;
}

