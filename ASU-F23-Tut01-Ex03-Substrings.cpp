#include <iostream>
using namespace std;

string test(string s1) {
    string last2 = s1.substr(s1.length() - 2);
    return last2 + last2 + last2;
}

int main() {
    cout << test("Hello") << endl;
    cout << test("Hi") << endl;
    return 0;
}
