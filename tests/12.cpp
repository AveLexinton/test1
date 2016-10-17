#include<iostream>
#include<string>
using namespace std;
 
template<class T> class Test;
template<class T> ostream& operator<<(ostream& out, const Test<T> &obj);
template<class T> class Test
{
private:
    int num;
public:
    Test(int n=0) 
    {
        num = n;
    }
    Test(const Test <T> &copy)
    {
        num = copy.num;
    }
    //'<<'后面加上'<>'表明这个函数是个函数模板
    friend ostream& operator<< <>(ostream& out, const Test<T> &obj);
};
 
template <class T> ostream& operator<<(ostream& out, const Test<T> &obj)
{
    cout << obj.num << endl;
    return out;
}

class Frac {
public:
int fenzi, fenmu;
Frac(int fz, int fm):fenzi(fz), fenmu(fm){}
operator string() { 
    return to_string(fenzi)+"/"+to_string(fenmu);
}
};
 

template<class T1>
class A{
public:
T1 x;
};
template<class T2>
class B {
public:
T2 x;
void pA(const B& a) {
cout << a.x << endl;
}
};

class C {
public:
int v;
static constexpr int x = 3;
static constexpr double y = 3.332;
C(const int c):v(c){}
};
 
int main()
{
    C c{12};
    cout << c.x << endl << c.y; 
   // B<int> x{10};
    //B<int> b;
    //b.pA(x);
    //const Frac fr(2,7);
    //cout << static_cast<string&>(const_cast<Frac&>(fr)) << endl;
    //string s("hell");
    //cout << s;
    //cout << stoi("-123") << endl;
    //Test<int> t(2);
    //cout << t << endl;
    //getchar();
    return 0;
}
