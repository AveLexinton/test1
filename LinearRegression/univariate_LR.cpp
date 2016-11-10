#include <iostream>
#include <vector>
#include <fstream>
#include <array>
#include <numeric>
#include <stdexcept>
using namespace std;

void extract_data(vector<double>& x, vector<int>& y) {
        ifstream ifs("/home/lexinto/Workspace/MLalgorithms/datasets/Bike-Sharing-Dataset/day.csv");
        if (!ifs.is_open()) {
                throw runtime_error("Error in opening file 'day.csv'.");
        }

        //vector<double> x;
        //vector<int> y;
        const int xno = 10, yno = 16, clen = 12;
        for (string s1; getline(ifs, s1);) {
                bool bLastpos = false;
                string::size_type lastpos = -1;
                string::size_type curpos = 0;
                int i = 1;
                for(; string::npos != (curpos = s1.find(',', lastpos+1)); i++) {
                        if (xno == i) {
                                string s2 = s1.substr(bLastpos?lastpos+1:0, bLastpos?(curpos-lastpos-1):curpos);
                                try {
                                        x.push_back(stod(s2));
                                }
                                catch(invalid_argument){
                                        cout << "stod skipped one invalid item." << endl;}
                        } else if (yno == i) {
                                string s2 = s1.substr(bLastpos?lastpos+1:0, bLastpos?(curpos-lastpos-1):curpos);
                                try {
                                        y.push_back(stoi(s2));
                                }
                                catch(invalid_argument){
                                        cout << "stoi skipped one invalid item." << endl;}
                        }
                        lastpos = curpos;
                        bLastpos = true; //lastpos now valid
                }
                curpos = s1.length();
                if (xno == i) {
                        string s2 = s1.substr(bLastpos?lastpos+1:0, bLastpos?(curpos-lastpos-1):curpos);
                        try {
                                x.push_back(stod(s2));
                        }
                        catch(invalid_argument){
                                cout << "stod skipped one invalid item." << endl;}
                } else if (yno == i) {
                        string s2 = s1.substr(bLastpos?lastpos+1:0, bLastpos?(curpos-lastpos-1):curpos);
                        try {
                                y.push_back(stoi(s2));
                        }
                        catch(invalid_argument){
                                cout << "stoi skipped one invalid item." << endl;}
                }

        }

        cout << x.size() << endl;
        cout << y.size() << endl;

        ifs.close();
}

int main() {
        vector<double> x;
        vector<int> y;
        extract_data(x,y);
        //for (auto& a:x)
        //cout << a << '\t';
        //计算x均值
        double avg_x = accumulate(x.begin(), x.end(),0.)/x.size();
        cout << avg_x << endl;
        double w_fenzi = 0., w_fenmu = 0., w_fenmu1 = 0., w_fenmu2 = 0.;
        for (int i = 0; i < x.size(); ++i) {
                w_fenzi += y.at(i)*(x.at(i)-avg_x);
                w_fenmu1 += x.at(i)*x.at(i);
                w_fenmu2 += x.at(i);
        }
        w_fenmu2 *= w_fenmu2;
        w_fenmu2 /= x.size();
        w_fenmu = w_fenmu1-w_fenmu2;
        double w = w_fenzi/w_fenmu;

        cout << "w_fenzi: " << w_fenzi << endl 
                << "w_fenmu: " << w_fenmu << endl 
                << "w: " << w << endl;
        double b = 0.;
        for (int i = 0; i < x.size(); ++i) {
                b += (y.at(i)-x.at(i)*w);
        }
        b /= x.size();
        cout << "b: " << b << endl;
        return 0;
}
