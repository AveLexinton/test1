#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stdexcept>
#include <vector>
#include <numeric>
#include <initializer_list>
using namespace std;

//调试
ostream& dbgcout = cout;

template<typename T>
class Matrix {
  int nrow, ncol;
  vector<vector<T>> data;
public:
  //默认构造函数
  Matrix(int row = 0, int col = 0) {
    dbgcout << "constructor" << endl;
    if (row >= 0 && col >= 0) {
      nrow = row;
      ncol = col;
      vector<vector<T>> tempvec(row);
      for(auto& a:tempvec) {
        a = move(vector<T>(col));
      }
      data = move(tempvec);
    } else 
      throw std::invalid_argument("Error: row and col must be positive!");
  };
  Matrix(const initializer_list<initializer_list<T>>& ilil) {
    data = move(vector<vector<T>>(ilil.begin(), ilil.end()));
    nrow = data.size();
    ncol = 0;
    bool firstin = true;
    for (auto& c:data) {
      if (firstin) {
        ncol = c.size();
        firstin = false;
      } else {
        if (c.size() != ncol) {
          throw invalid_argument("rows must be of same size!");
        }
      }
    }
  }
  //拷贝构造函数　
  Matrix(const Matrix& m) {
    dbgcout << "copy constructor" << endl;
    nrow = m.nrow;
    ncol = m.ncol;
    data = m.data;
  }
  //赋值构造函数
  Matrix& operator=(const Matrix& m) {
    dbgcout << "assignment constructor" << endl;
    if (this != &m) {
      nrow = m.nrow;
      ncol = m.ncol;
      data = m.data;
    }
    return *this;
  }
  //转移构造函数
  Matrix(const Matrix&& m) {
    dbgcout << "move constructor" << endl;
    *this = move(m);
  }
  //转移赋值函数
  Matrix& operator=(Matrix&& m) {
    dbgcout << "move assignment" << endl;
    if (this != &m) {
      nrow = m.nrow;
      ncol = m.ncol;
      data = move(m.data);

      m.nrow = m.ncol = 0;
    }
    return *this;
  }
 
  //取值
  int getNrow()const {return nrow;}
  int getNcol()const {return ncol;}
  const vector<vector<T>>& getData() const {return data;}
  const T& get(int r, int c) const {
    return data.at(r).at(c);
  }
  void set(int r, int c, T val) {
    data.at(r).at(c) = move(val);
  }
  void setData(const initializer_list<initializer_list<T>>& ilil) {
    data = move(vector<vector<int>>{ilil.begin(),ilil.end()});
  }

  //矩阵转置
  Matrix inverse() const {
    Matrix resm(ncol,nrow);
    for (int i =  0; i < nrow; ++i) {
      for (int j = 0; j < ncol; ++j) {
        resm.set(j, i, get(i,j));
      }
    }  
    return resm;
  }

  //矩阵乘法
  Matrix multiplies(const Matrix& m) const {
    if (m.getNrow() != ncol)
      throw invalid_argument("The number of the cols of the 1st matrix should match with that of the rows of the 2nd!");
    Matrix res(nrow, m.getNcol());
    Matrix inverse_m = m.inverse();
    auto& inverse_data = inverse_m.getData();
    for (int i = 0; i < nrow; ++i) {
      for (int j = 0; j < m.getNcol(); ++j) {
        T val = inner_product(data.at(i).begin(), data.at(i).end(), inverse_data.at(j).begin(), 0);
        res.set(i,j, val);
      }
    }
    return res;
  }

  //最简行形式
  void simplest_row_form() {
    int non_zero_cnt = 0;
    dbgcout << *this << endl << endl;
    for (int i = 0; i < ncol; ++i) { //第i列找一个非零元素，消去其它行该行，使为０
      int j = non_zero_cnt; //第j行
      for (; j < nrow && !data.at(j).at(i); ++j); //找到第i列第一个非零元素 
      if (j == nrow) //第i列元素全是0 
        continue;
      for (int k = 0; k < nrow; ++k) { 
        if (k == j) continue;
        T clear_factor = -data.at(k).at(i)*1./data.at(j).at(i);
        //第j列元素乘上clear_factor加到第k行，消元
        for (int m = 0; m < ncol; ++m) {
          data.at(k).at(m) += data.at(j).at(m)*clear_factor;
        }
      }
      swap(data.at(j), data.at(non_zero_cnt));
      non_zero_cnt ++;      
      dbgcout << *this << endl << endl;
    }
  }
  //求解矩阵方程
  
  //打印
  template<typename C>
  friend ostream& operator<< (ostream& os, const Matrix<C>& m);
};

#endif
