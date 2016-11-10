#include <iostream>
#include <vector>
#include <algorithm>
#include "../base/dbghelp.h"
#include "Matrix.h"
using namespace std;

template <typename T>
ostream& operator<< (ostream& os, const Matrix<T>& m) {
        //cout << "operator<<(ostream&, const Matrix<T>&)" << endl;
        auto& data = m.getData();
        for (auto& row:data) {
                for (auto& col: row) {
                        os << col << '\t';
                }
                os << endl;
        } 
        return os;
}

//template<>
//void Matrix<int>::simplest_row_form() {
//        ////dbgcout << "template spcialization of simplest_row_form() invoked." << endl;
//        int non_zero_cnt = 0;
//        ////dbgcout << *this << endl << endl;
//        for (int i = 0; i < ncol; ++i) { //第i列找一个非零元素，消去其它行该行，使为０
//                int j = non_zero_cnt; //第j行
//                for (; j < nrow && !data.at(j).at(i); ++j); //找到第i列第一个非零元素 
//                if (j == nrow) //第i列元素全是0 
//                        continue;
//                for (int k = 0; k < nrow; ++k) {
//                        if (k == j) continue;
//                        int clear_factor = -data.at(k).at(i)*1./data.at(j).at(i);
//                        //第j列元素乘上clear_factor加到第k行，消元
//                        for (int m = 0; m < ncol; ++m) {
//                                data.at(k).at(m) += data.at(j).at(m)*clear_factor;
//                        }
//                }
//                swap(data.at(j), data.at(non_zero_cnt));
//                non_zero_cnt ++;
//                ////dbgcout << *this << endl << endl;
//        }
//}
//
////矩阵每一行化整
//template<>
//Matrix<int> Matrix<Fraction>::int_mat() const{
//        vector<vector<Fraction>> tdata(data);  //for temp use
//        Matrix<int> m{nrow, ncol};
//        ////dbgcout << "Matrix<Fraction>::int_mat()" << endl;
//        for (int i = 0; i < nrow; ++i) {
//                vector<int> v(ncol); //保存所有分数的分母
//                transform(tdata.at(i).begin(),tdata.at(i).end(),v.begin(), [](const Fraction& f){return f.getFenmu();}); //取出所有分数的分母保存
//                int fenmu_lcm = lcm_s(v); //计算分母的最小公倍数
//                for_each(tdata.at(i).begin(), tdata.at(i).end(), [fenmu_lcm](Fraction& f){f*=fenmu_lcm;}); //分母乘以最小公倍数
//                transform(tdata.at(i).begin(),tdata.at(i).end(),v.begin(), [](const Fraction& f){return f.getFenzi();}); //取出所有分子保存，此时分数分母应当都为1
//                int fenzi_gcd = gcd_s(v);
//                if (fenzi_gcd != 0 && fenzi_gcd != 1) {
//                        for_each(v.begin(), v.end(), [fenzi_gcd](int& val){val/=fenzi_gcd;});
//                }
//                m.setRow(i, v);
//        }
//        return m;
//}


template<typename T>
Matrix<T> mat_union(const Matrix<T>& A, const Matrix<T>& B) {
        if (!A.isEmpty() && !B.isEmpty()) {
                Matrix<T> ret(A.getNrow(), A.getNcol()+B.getNcol());
                for (int i = 0; i < A.getNrow(); ++i) {
                        auto end = copy(A.data.at(i).begin(), A.data.at(i).end(), ret.data.at(i).begin());
                        copy(B.data.at(i).begin(), B.data.at(i).end(), end);
                }
                return ret;
        } else if (!A.isEmpty())
                return A;

        return B;
}

//子函数：用来实现求解AX=b,  求出X, (A|b)，目前只求解n个未知数n个方程类型的线性方程组
template<typename T>
pair<bool, Matrix<T>> solve_b(Matrix<T> mat) { //返回pair中第一个bool值表示有没有解
        if (mat.getNcol() < 1) {
                throw invalid_argument("Error in solve<T>: empty matrix needs not be solved!");
                return make_pair(false, Matrix<T>());
        }
        if (mat.getNrow() != mat.getNcol()-1)     //如果A不是方阵，不进行求解
                return make_pair(false, Matrix<T>());

        Matrix<T> ret(mat.getNcol()-1, 1);
        ret.fill(numeric_limits<T>::max());     //填充上最大值，没有修改的话，则标志了自由变元，即该位置自变量取所有值

        mat.simplest_row_form();

        vector<int> zeroline_no;
        for(int i = 0; i < mat.getNrow(); ++i) { //找出全0行
                if (all_of(mat.getData().at(i).begin(), mat.getData().at(i).end()-1, [](const T& temp){return temp==0;})) {
                        if (mat.getData().at(i).at(mat.getNcol()-1) != 0)
                                return make_pair(false, ret); //该线性方程组无解，直接返回
                        else //(A|b)第i行全为0, 添加到标记中，准备后面统一删除
                                zeroline_no.push_back(i);
                }
        }
        //从后向前删除矩阵中的行，保证要删除的行号的有效性
        for(auto a = zeroline_no.crbegin(); a != zeroline_no.crend(); ++a)
                mat.rm_row(*a);

        //从最后一行开始，反向求解。每一行找到非零元素连续序列头尾两个指针pos1, pos2
        for (auto r = mat.getData().crbegin(); r != mat.getData().crend(); ++r) {
                int pos1 = 0, pos2 = r->size()-2; //指向倒数第二个
                for(; r->at(pos1) == 0; ++pos1); //找到第一个非零元素位置
                for(; r->at(pos2) == 0; --pos2); //找到最后一个非零元素位置
                T temp = *(r->end()-1);
                for(; pos2 != pos1; --pos2) {
                        if (r->at(pos2) == 0)
                                continue;
                        if (ret.getData().at(pos2).at(0) == numeric_limits<T>::max()) {
                                ret.set(pos2, 0, 1);
                                temp -= r->at(pos2);
                        } else {
                                temp -= r->at(pos2)*ret.getData().at(pos2).at(0);
                        }
                }
                ret.set(pos1, 0, temp/r->at(pos1));
        }

        return make_pair(true, ret);
}


//AX=B，求B，（A|B），只求解n个未知数n个方程类型的线性方程组
template<typename T>
pair<bool, Matrix<T>> solve(const Matrix<T>& A, const Matrix<T>& B) { //返回pair中第一个bool值表示有没有解
        if (A.isEmpty() || B.isEmpty())
                return make_pair(false, Matrix<T>());
        if (A.getNrow() != B.getNrow()) 
                return  make_pair(false, Matrix<T>());
        if (A.getNrow() != A.getNcol())     //如果A不是方阵，不进行求解
                return make_pair(false, Matrix<T>());

        Matrix<T> ret;//(A.getNcol(), B.getNcol());
        //取B的第i列和A粘起来，从solve_b求解a得到c，粘到ret右边
        for (int i = 0; i < B.getNcol(); ++i) {
                Matrix<T> temp = mat_union(A, Matrix<T>{vector<vector<T>>{B.invert().getRow(i)}}.inverse());
                if (!solve_b(temp).first) //无解
                        return make_pair(false, ret);
                else 
                        ret = mat_union(ret, solve_b(temp).second);   
        }
        //dbgcout << ret << endl << endl;
        return make_pair(true, ret);
}


int main() {
        //Matrix<Fraction> m4{{2,0,1},{0,1,0}};
        //Matrix<Fraction> m5{{0},{2}};
        //const auto& r = solve(m4, m5);
        //if (r.first)
        //    cout << r.second.int_mat();

        //Matrix<Fraction> m3{{1,0,0,0,0,1},{0,1,0,0,0,2},{0,0,1,0,0,3},{0,0,0,0,0,4}};
        //const auto& au = solve(m3);
        //cout << "au.first: " << au.first << endl;
        //cout << "au.second: " << au.second << endl;

        //Matrix<Fraction> mf{2,2};
        //cout << mf << endl;
        //mf.int_mat();
        //Matrix<double> m0{{1,4,14},{2,5,19},{3,8,30}};
        //m0.simplest_row_form();
        //cout << m0 << endl;

        //        Matrix<Fraction> m1{{0,1,2},{2,2,3},{4,1,6},{1,1,1},{2,1,1}};
        //        Matrix<Fraction> m2{{2,0,1,2,3},{2,1,1,1,1},{1,3,2,1,2},{2,2,2,1,2},{1,0,1,2,1}};
        //        const auto& r = solve(m2, m1);
        //        if (r.first)
        //                cout << r.second << endl;
        //        else
        //                cout << "cannot solve!" << endl;

        //        Matrix<Fraction<int>> m1{{1.00,2,string("6/2")},{4,1.0,2}, {0,5.0000,1}}, m2{{1},{1},{1}};
        //        Matrix<Fraction<int>> t =  mat_union(m1,m2);
        //        t.simplest_row_form();
        //        cout << t << endl;
        //cout << solve(m1,m2).second << endl;

        Matrix<Fraction<int>> m1{{1,2,3},{4,5,6}};
        cout << m1 <<endl;
        m1.addRow({7,8,9});
        cout << m1 << endl;
        m1.addCol({10,11,12});
        cout << m1 << endl;
        m1.rm_row(2);
        cout << m1 << endl;
        m1.rm_col(3);
        cout << m1 << endl;

        //cout << "int_mat:" << endl << m2.int_mat() << endl;
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
            Matrix<int> m1 = m.invert();
            cout << endl << m1 << endl << endl;
            cout << m.multiplies(m1) << endl;*/
        return 0;
}
