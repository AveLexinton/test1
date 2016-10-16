#include <iostream>
#include <vector>
#include "Matrix.h"
using namespace std;

template <typename T>
ostream& operator<< (ostream& os, const Matrix<T>& m) {
  auto& data = m.getData();
  for (auto& row:data) {
    for (auto& col: row) {
      os << col << '\t';
    }
    os << endl;
  } 
  return os;
}


int main() {
//Matrix<double> m0{{1,4,14},{2,5,19},{3,8,30}};
//m0.simplest_row_form();
//cout << m0 << endl;

//Matrix<double> m1{{0,1,2},{2,2,3},{4,1,6}};
//m1.simplest_row_form();
//cout << m1 << endl;

Matrix<double> m2{{2,0,1,2,3,1},{2,1,1,1,1,0},{1,3,2,1,2,1},{2,2,2,1,2,1},{1,0,1,2,1,1}};
m2.simplest_row_form();
cout << m2 << endl;
//Matrix<int> m1{{0,1,0},{1,2,1}};
//Matrix<int> m2{{1,0,1,0},{1,0,0,2},{1,1,0,1}};
//cout << m1.getNrow() << "    " << m1.getNcol() << endl;
//cout << m2.getNrow() << "    " << m2.getNcol() << endl;

//cout << m1.multiplies(m2) << endl;

//vector<vector<int>> vec{{0,1,0},{1,2,1}};
//Matrix<int> m2{{0,1},{1,2,1}};
//cout << m2.get(1,1);
//cout << vec.at(1).at(1) << endl;
//Matrix<int> m1(2,3);
//initializer_list<initializer_list<int>> il = {{0,1,0},{1,2,1}};
//m1.setData({{0,1},{1,2,1}});
//cout << m1.get(0,2) << endl;
/*  Matrix<int> m(2,3);
  m.set(1,1, 13);
  m.set(1,0, 11);
  m.set(1,2, 10);
  cout << m << endl;
  Matrix<int> m1 = m.inverse();
  cout << endl << m1 << endl << endl;
  cout << m.multiplies(m1) << endl;*/
  return 0;
}
