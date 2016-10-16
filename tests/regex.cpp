#include <iostream>
#include <regex>
#include <stdexcept>
using namespace std;

int main() {
    //throw runtime_error("error");
    regex myregex("([0-9]+)(/([1-9]([0-9]*))?");
    string tests("3/03");
    cout << regex_match(tests, myregex) << endl;
    return 0;
}
