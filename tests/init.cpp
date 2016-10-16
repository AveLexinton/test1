#include <iostream>
#include <initializer_list>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> vi{{1,2,3},{4,5,6}};
    initializer_list<initializer_list<int>> il(vi);
  return 0;
}
