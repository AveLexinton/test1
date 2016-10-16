/**
  分数加减
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

class Fraction {
        int fenzi, fenmu;

        public:
        //构造函数
        Fraction(int afenzi = 0, int afenmu = 1) {
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
        int getFenzi()const{return fenzi;};
        int getFenmu()const{return fenmu;};

        //打印
        //friend ostream& operator<<(ostream& os, const Fraction& fr);
};

ostream& operator<<(ostream& os, const Fraction& fr);
Fraction operator+(const Fraction& a, const Fraction& b);
Fraction operator-(const Fraction& a, const Fraction& b); 
Fraction operator*(const Fraction& a, const Fraction& b); 
Fraction operator/(const Fraction& a, const Fraction& b); 
Fraction operator+=(Fraction& a, const Fraction& b); 
Fraction operator-=(Fraction& a, const Fraction& b); 
Fraction operator*=(Fraction& a, const Fraction& b); 
Fraction operator/=(Fraction& a, const Fraction& b); 

bool operator==(const Fraction& a, const Fraction& b); 
bool operator!=(const Fraction& a, const Fraction& b); 


#endif 

