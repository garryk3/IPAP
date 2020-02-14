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

const string IN = "/home/projects/my/ipap/homework/c++/16 /in.txt";
const string OUT = "/home/projects/my/ipap/homework/c++/16/out.txt";

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
            int num;
        while(infile >> num) {
            numbers.push_back(int(num));
        }
        infile.close();
    return numbers;
};

void writeToStream(ofstream &stream, int val) {
    stream << val;
}

void writeToFile(vector<int> &list, string path = OUT) {
    ofstream outfile;
    outfile.open(path);
    if(outfile.is_open()) {
        // for_each(list.begin(), list.end(), writeToStream);
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
    sort(list.begin(), list.end());
    printVector(list);
    // writeToFile(list);
};

int main() {
    readAndWriteSortedList();
    // string filename = IN;
    // ofstream fout;
    // fout.open(filename);
    // if(fout.is_open()) {
    //     string line = "ops";
    //     while(line != "") {
    //         cout << "enter line ";
    //         char buffer[1000];
    //         cin.getline(buffer, 1000);
    //         line = buffer;
    //         if(line != "") {
    //             fout << line << endl;
    //         }
    //     }
    //     fout.close();
    // }
    return 0;
}