#include <iostream>

using namespace std;

const int LENGTH = 7;
const int CONTINUE_CODE = 1;
const int BREAK_CODE = -1;

bool checkIsIncorrectSum(int sum) {
    return sum % 50 != 0 || sum <= 0;
}

int requestSumFromUser() {
    int sum;
    cout << "Введите сумму для снятия (кратную 50 рублям)" << endl;
    cin >> sum;

    if(sum == BREAK_CODE) {
        return sum;
    }

    bool sumIsIncorrect = checkIsIncorrectSum(sum);

    while(sumIsIncorrect) {
        cout << "Введите корректную сумму" << endl;
        sum = requestSumFromUser();
        sumIsIncorrect = checkIsIncorrectSum(sum);
    }

    return sum;
}

int getUsedNominals(const int sum, const int nominal, const int nominalCount) {
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

int calculateMaxSum(int count[], const int nominal[]) {
    int result = 0;
    for(int i = 0; i < LENGTH; i++) {
        result += count[i] * nominal[i];
    }
    return result;
}

int moneyRequestHandler(int sum, int nominalCounts[], const int nominals[]) {
    string result = "Вам выданы купюры: ";
    int usedNominalCount = 0;
    int tempCountCopy[LENGTH];

    for(int i = 0; i < LENGTH; i++) {
        usedNominalCount = getUsedNominals(sum, nominals[i], nominalCounts[i]);
        if(usedNominalCount != 0) {
            sum = sum - usedNominalCount * nominals[i];
            tempCountCopy[i] = nominalCounts[i] - usedNominalCount;
            result = concatResultMessage(result, usedNominalCount, nominals[i]);
        } else {
            tempCountCopy[i] = nominalCounts[i];
        }
    }

    if(sum > 0) {
        cout << "Недостаточно купюр нужного номинала, попробуйте другую сумму..." << endl;
        return CONTINUE_CODE;
    }

    for(int i = 0; i < LENGTH; i++) {
        nominalCounts[i] = tempCountCopy[i];
    }

    cout << result << endl;
    cout << "В банкомате осталось " << to_string(calculateMaxSum(nominalCounts, nominals)) << "рублей" << endl;
    cout << "=============================" << endl;
    cout << "=============================" << endl;
    cout << "=============================" << endl;
    cout << "=============================" << endl;

    return CONTINUE_CODE;
}

int startBankOperation(int nominalCounts[], const int nominals[]) {
    int maxSum = calculateMaxSum(nominalCounts, nominals);

    if(maxSum == 0) {
        cout << "В банкомате закончились деньги! Операция прекращена" << endl;
        return BREAK_CODE;
    }
    cout << "В банкомате имеется " << to_string(maxSum) << "рублей" << endl;

    const int sum = requestSumFromUser();
    if(sum == BREAK_CODE) {
        cout << "Операция отменена" << endl;
        return BREAK_CODE;
    }
    if(sum > maxSum) {
        cout << "В банкомате недостаточно денег для выдачи!" << endl;
        return CONTINUE_CODE;
    }

    cout << "Рассчитывается возможность снятия суммы " << sum << " рублей! Ожидайте выдачи купюр..." << endl;
    return moneyRequestHandler(sum, nominalCounts, nominals);
}

int main() {
    int nominalCounts[LENGTH] = {7, 5, 5, 4, 0, 0, 0};
    const int nominals[LENGTH] = {5000, 2000, 1000, 500, 200, 100, 50};

    bool isContinueOperation = startBankOperation(nominalCounts, nominals) == CONTINUE_CODE;

    while(isContinueOperation) {
        isContinueOperation = startBankOperation(nominalCounts, nominals) == CONTINUE_CODE;
    }
    return 0;
}