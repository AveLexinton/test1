#include <stdexcept>
#include <limits>
#include "Fraction.h"

//自定义Fraction max()
namespace std {
    template<>
    Fraction<> numeric_limits<Fraction<>>::max() {
        return Fraction<>(numeric_limits<long long>::max(), static_cast<long long>(1));
    }
}

////打印
//ostream& operator<<(ostream& os, const Fraction& fr){
//  if (fr.getFenzi() == 0)
//    cout << "0";
//  else if (fr == numeric_limits<Fraction>::max())
//    cout << "INF";
//  else if (fr.getFenmu() == 1) {
//    cout << fr.getFenzi();
//  } else
//    cout << fr.getFenzi() << '/' << fr.getFenmu();
//  return os;
//}
//
////分数加法
//Fraction operator+(const Fraction& a, const Fraction& b) {
//  ValueType afenzi = a.getFenzi();
//  ValueType afenmu = a.getFenmu();
//  ValueType bfenzi = b.getFenzi();
//  ValueType bfenmu = b.getFenmu();
//  ValueType rfenzi = afenzi*bfenmu+bfenzi*afenmu;
//  ValueType rfenmu = afenmu*bfenmu;
//  ValueType gcdres = gcd(rfenzi, rfenmu);
//  Fraction res(rfenzi/gcdres, rfenmu/gcdres);
//  return res;
//}
//
////分数减法
//Fraction operator-(const Fraction& a, const Fraction& b) {
//  ValueType afenzi = a.getFenzi();
//  ValueType afenmu = a.getFenmu();
//  ValueType bfenzi = b.getFenzi();
//  ValueType bfenmu = b.getFenmu();
//  ValueType rfenzi = afenzi*bfenmu-bfenzi*afenmu;
//  ValueType rfenmu = afenmu*bfenmu;
//  ValueType gcdres = gcd(rfenzi, rfenmu);
//  Fraction res(rfenzi/gcdres, rfenmu/gcdres);
//  return res;
//}
//
////分数乘法
//Fraction operator*(const Fraction& a, const Fraction& b) {
//  ValueType afenzi = a.getFenzi();
//  ValueType afenmu = a.getFenmu();
//  ValueType bfenzi = b.getFenzi();
//  ValueType bfenmu = b.getFenmu();
//  ValueType rfenzi = afenzi*bfenzi;
//  ValueType rfenmu = afenmu*bfenmu;
//  ValueType gcdres = gcd(rfenzi, rfenmu);
//  Fraction res(rfenzi/gcdres, rfenmu/gcdres);
//  return res;
//}
//
////分数除法
//Fraction operator/(const Fraction& a, const Fraction& b) {
//  if (b.getFenzi() == 0)
//    throw runtime_error("Error: denominator(fenmu) cannot be 0!");
//
//  ValueType afenzi = a.getFenzi();
//  ValueType afenmu = a.getFenmu();
//  ValueType bfenzi = b.getFenzi();
//  ValueType bfenmu = b.getFenmu();
//  ValueType rfenzi = afenzi*bfenmu;
//  ValueType rfenmu = afenmu*bfenzi;
//  ValueType gcdres = gcd(rfenzi, rfenmu);
//  Fraction res(rfenzi/gcdres, rfenmu/gcdres);
//  return res;
//}
//
////分数加等
//Fraction operator+=(Fraction& a, const Fraction& b) {
//  return a = a+b;
//}
//
////分数减等
//Fraction operator-=(Fraction& a, const Fraction& b) {
//  return a = a-b;
//}
////分数乘等
//Fraction operator*=(Fraction& a, const Fraction& b) {
//    return a = a*b; 
//}
////分数除等
//Fraction operator/=(Fraction& a, const Fraction& b) {
//  return a = a/b;
//}
////分数相等
//bool operator==(const Fraction& a, const Fraction& b) {
//    return (a.getFenzi()==0 && b.getFenzi()==0)||(a.getFenzi()==b.getFenzi() && a.getFenmu() == b.getFenmu());
//}
////分数不等
//bool operator!=(const Fraction& a, const Fraction& b) {
//    return !(a==b);
//}
//


int main_fraction() {
  //Fraction f{0,12};
  //Fraction f2{1,25};
  //cout << f/f2 << endl;
  //Fraction f3("5/6");
  //cout << -f3 << endl;
  return 0;
}

