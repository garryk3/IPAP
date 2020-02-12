#include <iostream>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;

// -------------------------------
// string
// -------------------------------

void test(string &str  /*  string* str */) {
    str += "hello"; // *str += "hello";
};

int main() {
    string name;
    char chararray[256];
    cout << "Enter your name ";
    cin.getline(chararray, 256);
    name = chararray;
    cout << endl << "Name " << name << " has length " << name.length();
    string* pstr;
    pstr = &name;
    *pstr = "p_" + * pstr;
    string &ls = name;
    return 0;
}