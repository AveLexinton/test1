#include <vector>
using namespace std;

int main() {
  vector<int> v{1,2,3,4};
  v.erase(v.begin()+10);
  return 0;
}
