#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <fstream>


using namespace std;

// ----------------------------------------------------------------
// files
// ----------------------------------------------------------------

// ------------------------------
// homework:
// прочитать числа из файла
// записать отсортированный массив в файл
// ------------------------------

const string IN = "in.txt";
const string OUT = "out.txt";

void readFile() {};

void writeFile() {};

int main() {
    string filename = "out.txt";
    ofstream fout;
    fout.open(filename);
    if(fout.is_open()) {
        string line = "ops";
        while(line != "") {
            cout << "enter line ";
            char buffer[1000];
            cin.getline(buffer, 1000);
            line = buffer;
            if(line != "") {
                fout << line << endl;
            }
        }
        fout.close();
    }
    return 0;
}