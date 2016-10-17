/**
  分数定义及运算
 **/
#ifndef __FRACTION_H__
#define __FRACTION_H__

#include <iostream>
#include <stdexcept>
#include <string>
#include <regex>
#include <cmath>
#include "util.h"
//#include "dbghelp.h"
using namespace std;

template<typename ValueType=long long>
class Fraction {
        ValueType fenzi, fenmu;

        public:
        //构造函数
        Fraction(ValueType afenzi = 0, ValueType afenmu = 1) {
                if (0 == afenmu) {
                         throw invalid_argument("Error in constructing Fraction object: denominator cannot be 0! \
                                                It has been set to 1 for validity.");
                } else {
                        fenmu = abs(afenmu);
                        fenzi = (afenmu<0)?-afenzi:afenzi;
                }
        };

        //字符串构造函数
        Fraction(const string& str) {
                const regex fraction_regex{"-?([0-9]+)(/[1-9]([0-9]*))?"};
                if (!regex_match(str, fraction_regex)) {//如果不是一个分数
                    throw invalid_argument("Error in Fraction(const string&): it is not a proper fraction!");
                }
                string::size_type slash_pos = str.find('/');
                if (slash_pos == string::npos) {//没有/字符
                    fenzi = stoi(str);
                    fenmu = 1;
                } else {
                    fenzi = stoi(str.substr(0, slash_pos));
                    fenmu = stoi(str.substr(slash_pos+1));
                }
        }
        
        //拷贝构造函数
        Fraction(const Fraction& f){
                //dbgcout << "Log: Fraction move constructor invoked!" << endl;
                fenzi = f.getFenzi();
                fenmu = f.getFenmu();
        }

        //拷贝赋值函数
        Fraction& operator=(const Fraction& f) {
                //dbgcout << "Log: Fraction move assignment invoked!" << endl;
                if (this != &f) {
                        fenzi = f.getFenzi();
                        fenmu = f.getFenmu();
                }
                return *this;
        }


        //转移构造函数
        Fraction(const Fraction&& f){
                //dbgcout << "Log: Fraction move constructor invoked!" << endl;
                fenzi = f.getFenzi();
                fenmu = f.getFenmu();
        }

        //转移赋值函数
        Fraction& operator=(const Fraction&& f) {
                //dbgcout << "Log: Fraction move assignment invoked!" << endl;
                if (this != &f) {
                        fenzi = f.getFenzi();
                        fenmu = f.getFenmu();
                }
                return *this;
        }
        
        //！操作符重载
        bool operator!() const {
            return !fenzi;
        }
        //-操作符重载
        Fraction operator-() const {
            return Fraction{-fenzi,fenmu};
        }

        //取值
        ValueType getFenzi()const{return fenzi;};
        ValueType getFenmu()const{return fenmu;};

        //打印
        //friend ostream& operator<<(ostream& os, const Fraction& fr);
};

//打印
template<typename ValueType>
ostream& operator<<(ostream& os, const Fraction<ValueType>& fr){
  if (fr.getFenzi() == 0)
    cout << "0";
  else if (fr == numeric_limits<Fraction<ValueType>>::max())
    cout << "INF";
  else if (fr.getFenmu() == 1) {
    cout << fr.getFenzi();
  } else
    cout << fr.getFenzi() << '/' << fr.getFenmu();
  return os;
}

//分数加法
template<typename ValueType>
Fraction<ValueType> operator+(const Fraction<ValueType>& a, const Fraction<ValueType>& b) {
  ValueType afenzi = a.getFenzi();
  ValueType afenmu = a.getFenmu();
  ValueType bfenzi = b.getFenzi();
  ValueType bfenmu = b.getFenmu();
  ValueType rfenzi = afenzi*bfenmu+bfenzi*afenmu;
  ValueType rfenmu = afenmu*bfenmu;
  ValueType gcdres = gcd(rfenzi, rfenmu);
  Fraction<ValueType> res(rfenzi/gcdres, rfenmu/gcdres);
  return res;
}

//分数减法
template<typename ValueType>
Fraction<ValueType> operator-(const Fraction<ValueType>& a, const Fraction<ValueType>& b) {
  ValueType afenzi = a.getFenzi();
  ValueType afenmu = a.getFenmu();
  ValueType bfenzi = b.getFenzi();
  ValueType bfenmu = b.getFenmu();
  ValueType rfenzi = afenzi*bfenmu-bfenzi*afenmu;
  ValueType rfenmu = afenmu*bfenmu;
  ValueType gcdres = gcd(rfenzi, rfenmu);
  Fraction<ValueType> res(rfenzi/gcdres, rfenmu/gcdres);
  return res;
}

//分数乘法
template<typename ValueType>
Fraction<ValueType> operator*(const Fraction<ValueType>& a, const Fraction<ValueType>& b) {
  ValueType afenzi = a.getFenzi();
  ValueType afenmu = a.getFenmu();
  ValueType bfenzi = b.getFenzi();
  ValueType bfenmu = b.getFenmu();
  ValueType rfenzi = afenzi*bfenzi;
  ValueType rfenmu = afenmu*bfenmu;
  ValueType gcdres = gcd(rfenzi, rfenmu);
  Fraction<ValueType> res(rfenzi/gcdres, rfenmu/gcdres);
  return res;
}

//分数除法
template<typename ValueType>
Fraction<ValueType> operator/(const Fraction<ValueType>& a, const Fraction<ValueType>& b) {
  if (b.getFenzi() == 0)
    throw runtime_error("Error: denominator(fenmu) cannot be 0!");

  ValueType afenzi = a.getFenzi();
  ValueType afenmu = a.getFenmu();
  ValueType bfenzi = b.getFenzi();
  ValueType bfenmu = b.getFenmu();
  ValueType rfenzi = afenzi*bfenmu;
  ValueType rfenmu = afenmu*bfenzi;
  ValueType gcdres = gcd(rfenzi, rfenmu);
  Fraction<ValueType> res(rfenzi/gcdres, rfenmu/gcdres);
  return res;
}

//分数加等
template<typename ValueType>
Fraction<ValueType> operator+=(Fraction<ValueType>& a, const Fraction<ValueType>& b) {
  return a = a+b;
}

//分数减等
template<typename ValueType>
Fraction<ValueType> operator-=(Fraction<ValueType>& a, const Fraction<ValueType>& b) {
  return a = a-b;
}
//分数乘等
template<typename ValueType>
Fraction<ValueType> operator*=(Fraction<ValueType>& a, const Fraction<ValueType>& b) {
    return a = a*b;
}
//分数除等
template<typename ValueType>
Fraction<ValueType> operator/=(Fraction<ValueType>& a, const Fraction<ValueType>& b) {
  return a = a/b;
}
//分数相等
template<typename ValueType>
bool operator==(const Fraction<ValueType>& a, const Fraction<ValueType>& b) {
    return (a.getFenzi()==0 && b.getFenzi()==0)||(a.getFenzi()==b.getFenzi() && a.getFenmu() == b.getFenmu());
}
//分数不等
template<typename ValueType>
bool operator!=(const Fraction<ValueType>& a, const Fraction<ValueType>& b) {
    return !(a==b);
}

//ostream& operator<<(ostream& os, const Fraction& fr);
//Fraction operator+(const Fraction& a, const Fraction& b);
//Fraction operator-(const Fraction& a, const Fraction& b); 
//Fraction operator*(const Fraction& a, const Fraction& b); 
//Fraction operator/(const Fraction& a, const Fraction& b); 
//Fraction operator+=(Fraction& a, const Fraction& b); 
//Fraction operator-=(Fraction& a, const Fraction& b); 
//Fraction operator*=(Fraction& a, const Fraction& b); 
//Fraction operator/=(Fraction& a, const Fraction& b); 
//
//bool operator==(const Fraction& a, const Fraction& b); 
//bool operator!=(const Fraction& a, const Fraction& b); 


#endif 

