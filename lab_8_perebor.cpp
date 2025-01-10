#include <iostream>
#include <vector>
using namespace std;

// Рекурсивная функция для полного перебора
int rucksackRecursion(int W, vector<int>& weights, vector<int>& values, int n) {
    if (n == 0 || W == 0) {
        return 0; // Если нет предметов или вес рюкзака равен 0, возвращаем 0
    }
    // Если вес текущего предмета больше W, пропускаем его
    if (weights[n - 1] > W) {
        return rucksackRecursion(W, weights, values, n - 1);
    } else {
        // Возвращаем максимум из двух случаев:
        // 1. Не берем текущий предмет
        // 2. Берем текущий предмет
        return max(
            rucksackRecursion(W, weights, values, n - 1), 
            values[n - 1] + rucksackRecursion(W - weights[n - 1], weights, values, n - 1)
        );
    }
}

int main() {
    vector<int> values = {60, 100, 120};    // Стоимости предметов
    vector<int> weights = {10, 20, 30};     // Вес предметов
    int W = 50;                             // Максимальный вес рюкзака
    int n = values.size();                  // Количество предметов
    
    int maxValue = rucksackRecursion(W, weights, values, n);
    cout << "Максимальная стоимость (при полном переборе): " << maxValue << endl;

    return 0;
}