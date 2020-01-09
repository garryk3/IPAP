// описание в файле description (решение без массивов, только примитивные типы, допустим возврат из функции только 1го значения)
#include <iostream>;

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

int calcucateNeededNominalCount(int sumPart, int nominal, int nominalCount) {
    int neededNominalCount = sumPart / nominal;
    
    return neededNominalCount <= nominalCount ? neededNominalCount : nominalCount; 
}

string getCalculatedResult(int nextCalculateSum, int nominal, int nominalCount) {
    string result = "";
    if(nextCalculateSum && nextCalculateSum >= nominal && nominalCount > 0) {
        int calcNominalCount = calcucateNeededNominalCount(nextCalculateSum, nominal, nominalCount);
        if(calcNominalCount) {
            result = result + to_string(calcNominalCount) + "x " + to_string(nominal) + " ";
        }
    }
    return result;
}

int printCalculatedResult(int sum) {
    int count50 = 7;
    int count100 = 3;
    int count200 = 5;
    int count500 = 9;
    int count1000 = 9;
    int count2000 = 3;
    int count5000 = 9;
    int maxSum = count50 * 50 + count100 * 100 + count200 * 200 + count500 * 500 + count1000 * 1000 + count2000 * 2000 + count5000 * 5000;
    string result = "Вам выданы купюры: ";
    int nextCalculateSum = 0;
    bool operationFailed = false;

    if(sum > maxSum) {
        cout << "В банкомате недостаточно денег для выдачи!" << endl;
        return 0;
    }

    result = getCalculatedResult(sum, 5000, count5000);
    nextCalculateSum = sum % 5000;

    string result2000 = getCalculatedResult(nextCalculateSum, 2000, count2000);
    if(result2000 != "") {
        nextCalculateSum = nextCalculateSum % 2000;
        result = result + result2000;
    }

    string result1000 = getCalculatedResult(nextCalculateSum, 1000, count1000);
    if(result1000 != "") {
        nextCalculateSum = nextCalculateSum % 1000;
        result = result + result1000;
    }

    string result500 = getCalculatedResult(nextCalculateSum, 500, count500);
    if(result500 != "") {
        nextCalculateSum = nextCalculateSum % 500;
        result = result + result500;
    }
    string result200 = getCalculatedResult(nextCalculateSum, 200, count200);
    if(result200 != "") {
        nextCalculateSum = nextCalculateSum % 200;
        result = result + result200;
    }

    string result100 = getCalculatedResult(nextCalculateSum, 100, count100);
    if(result100 != "") {
        nextCalculateSum = nextCalculateSum % 100;
        result = result + result100;
    }

    string result50 = getCalculatedResult(nextCalculateSum, 50, count50);
    if(result50 != "") {
        nextCalculateSum = nextCalculateSum % 50;
        result = result + result50;
    } else if(nextCalculateSum > 0) {
        operationFailed = true;
    }
    if(operationFailed) {
        cout << "Недостаточно купюр нужного номинала, попробуйте другую сумму...";
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