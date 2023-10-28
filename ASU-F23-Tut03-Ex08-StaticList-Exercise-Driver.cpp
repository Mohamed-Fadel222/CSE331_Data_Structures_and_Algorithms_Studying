#include "ASU-F23-Tut03-Ex08-StaticList-Exercise-Header.hpp"
#include <iostream>
using namespace std;

int main() {

    StaticList slist;
    slist.insert(3, 0);
    slist.insert(2, 0);
    slist.insert(1, 0);
    cout << slist << endl;
    slist.insert(42, 2);
    cout << slist << endl;
    slist.erase(0);
    cout << slist << endl;
    slist.deleteByValue(42);
    cout << slist << endl;
    cout << (slist.empty() ? "Empty" : "Not Empty") << endl;
    slist.erase(0);
    cout << (slist.empty() ? "Empty" : "Not Empty") << endl;
    slist.erase(0);
    cout << (slist.empty() ? "Empty" : "Not Empty") << endl;
    slist.erase(0);
    cout << (slist.empty() ? "Empty" : "Not Empty") << endl;
    slist.erase(0);
}