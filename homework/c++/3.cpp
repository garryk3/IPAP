// описание в файле description (решение без массивов, только примитивные типы, допустим возврат из функции только 1го значения)
#include <iostream>

using namespace std;

bool checkCorrectSum(int sum) {
    return sum % 50 != 0 || sum <= 0;
}

int requestSumFromUser() {
    int sum;
    cout << "Введите сумму для снятия (кратную 50 рублям)" << endl;
    cin >> sum;

    bool sumIsIncorrect = checkCorrectSum(sum);

    while(sumIsIncorrect) {
        cout << "Введите корректную сумму" << endl;
        sum = requestSumFromUser();
        sumIsIncorrect = checkCorrectSum(sum);
    }

    return sum;
}

int getCalculatedResult(int sum, int nominal, int nominalCount) {
    int result = 0;
    if(sum && sum >= nominal && nominalCount > 0) {
        int neededNominalCount = sum / nominal;
        result = neededNominalCount <= nominalCount ? neededNominalCount : nominalCount;
    }
    return result;
}

string concatResultMessage(string result, int calcNominalCount, int nominal) {
    if(calcNominalCount == 0) {
        return result;
    }
    return result + to_string(calcNominalCount) + "x " + to_string(nominal) + " ";
}

int printCalculatedResult(int sum) {
    int count50 = 0;
    int count100 = 3;
    int count200 = 5;
    int count500 = 9;
    int count1000 = 9;
    int count2000 = 3;
    int count5000 = 1;
    int maxSum = count50 * 50 + count100 * 100 + count200 * 200 + count500 * 500 + count1000 * 1000 + count2000 * 2000 + count5000 * 5000;
    string result = "Вам выданы купюры: ";
    int usedNominalCount = 0;

    if(sum > maxSum) {
        cout << "В банкомате недостаточно денег для выдачи!" << endl;
        return 0;
    }

    usedNominalCount = getCalculatedResult(sum, 5000, count5000);
    if(usedNominalCount != 0) {
        sum = sum - usedNominalCount * 5000;
        result = concatResultMessage(result, usedNominalCount, 5000);
    }

    usedNominalCount = getCalculatedResult(sum, 2000, count2000);
    if(usedNominalCount != 0) {
        sum = sum - usedNominalCount * 2000;
        result = concatResultMessage(result, usedNominalCount, 2000);
    }

    usedNominalCount = getCalculatedResult(sum, 1000, count1000);
    if(usedNominalCount != 0) {
        sum = sum - usedNominalCount * 1000;
        result = concatResultMessage(result, usedNominalCount, 1000);
    }

    usedNominalCount = getCalculatedResult(sum, 500, count500);
    if(usedNominalCount != 0) {
        sum = sum - usedNominalCount * 500;
        result = concatResultMessage(result, usedNominalCount, 500);
    }
    usedNominalCount = getCalculatedResult(sum, 200, count200);
    if(usedNominalCount != 0) {
        sum = sum - usedNominalCount * 200;
        result = concatResultMessage(result, usedNominalCount, 200);
    }

    usedNominalCount = getCalculatedResult(sum, 100, count100);
    if(usedNominalCount != 0) {
        sum = sum - usedNominalCount * 100;
        result = concatResultMessage(result, usedNominalCount, 100);
    }

    usedNominalCount = getCalculatedResult(sum, 50, count50);
    if(usedNominalCount != 0) {
        sum = sum - usedNominalCount * 50;
        result = concatResultMessage(result, usedNominalCount, 50);
    }

    if(sum > 0) {
        cout << "Недостаточно купюр нужного номинала, попробуйте другую сумму..." << endl;
        return 0;
    }

    cout << result;
    cout << endl;

    return 1;
}

int startBankOperation() {
    int sum = requestSumFromUser();
    cout << "Рассчитывается возможность снятия суммы " << sum << " рублей! Ожидайте выдачи купюр..." << endl;
    return printCalculatedResult(sum);
}

int main() {
    bool isCorrectOperation = startBankOperation() == 1;

    while(!isCorrectOperation) {
        isCorrectOperation = startBankOperation() == 1;
    }
    return 0;
}