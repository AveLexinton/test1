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
  
int main()
{
    Test<int> t(2);
    cout << t << endl;
    getchar();
    return 0;
}
