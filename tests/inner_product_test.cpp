#include <iostream>
#include <numeric>
#include <vector>
using namespace std;


int main() {
  vector<int> v1{1,2,3,6}, v2{2,5,1,2};
  cout << inner_product(v1.begin(), v1.end(), v2.begin(), 0);

  return 0;
}
