#include <iostream>;

using namespace std;

int requestSumFromUser() {
    int sum;
    cout << "Введите сумму для снятия (кратную 50 рублям)" << endl;
    cin >> sum;

    bool sumIsIncorrect = sum % 50 != 0;

    while(sumIsIncorrect) {
        sum = requestSumFromUser(); 
    }

    return sum;
}

int calculateCount

int main() {
    int sum = requestSumFromUser();
    
    return 0;
}