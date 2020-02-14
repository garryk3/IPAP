#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// ----------------------------------------------------------------
// files
// ----------------------------------------------------------------

// ------------------------------
// homework:
// прочитать числа из файла
// записать отсортированный массив в файл
// ------------------------------

const string IN  = "/home/projects/my/ipap/homework/c++/16 /in.txt";
const string OUT = "/home/projects/my/ipap/homework/c++/16 /out.txt";

vector<int> readFile(string path = IN) {
    ifstream infile;
    infile.open(path);
    vector<int> numbers;
    if(infile.is_open()) {
        int num;
        while(infile >> num) {
            numbers.push_back(int(num));
        }
        infile.close();
    }
    return numbers;
};

void writeListToFile(vector<int> &list, string path = OUT) {
    ofstream outfile;
    outfile.open(path);
    bool isOpen = outfile.is_open();
    if(!outfile.is_open()) {
        cout << "File not found: " << path << endl;
    } else {
        for(int i = 0; i < list.size(); i++) {
            outfile << list[i] << " ";
        }
        outfile.close();
    }
};

void printVector(vector<int> &vec) {
    vector<int>::const_iterator it;
    stringstream s;

    for( it = vec.begin(); it != vec.end(); ++it )
    {
        if( it != vec.begin() )
            s << " ";

        s << *it;
    }
    cout << "string: " << s.str() << endl;
};

void readAndWriteSortedList() {
    vector<int> list = readFile();
    cout << "before: ";
    printVector(list);
    sort(list.begin(), list.end());
    cout << "after: ";
    printVector(list);
    writeListToFile(list);
};

int main() {
    readAndWriteSortedList();
    return 0;
}