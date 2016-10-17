#ifndef __UTIL_H__
#define __UTIL_H__

#include <vector>
using namespace std;

//注意：如果两个数都为0,gcd返回0
template<class T>
T gcd(T a, T b){
     if (a != 0 && b != 0) {
        while (a % b != 0) {
                T r = a % b;
                a = b;
                b = r;
        }
        return b;
    } else if (a != 0) 
        return a;
      else
        return b;
}

//注意:如果全为0,则返回0
template<class T>
T gcd_s(const vector<T>& vec) {
    T res = 0;
    for (auto& v: vec)
        res = gcd(res, v);
    return res;
}

//如果两个至少有一个为0, 则结果为0
template<class T>
T lcm(T a, T b) {
    if (a != 0 && b != 0) {
        return a*b/gcd(a,b);
    }
    return 0;
}

//如果两个至少有一个为0, 则结果为0
template<class T>
T lcm_s(const vector<T>& vec) {
    T res = 1;
    for (auto& v : vec) 
        res = lcm(res, v);
    return res;
}

/*
int main(){ 
vector<int> v{10, 14, 22, 18,0,0};
cout << lcm(6,4) << endl;
cout << lcm_s({4,6,18}) << endl;
cout << gcd_s({12, 18});
return 0;
}*/

#endif
