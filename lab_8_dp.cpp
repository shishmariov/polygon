#include <iostream>
#include <vector>
using namespace std;

int rucksackDP(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0)); // Создаем таблицу для хранения результатов

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            // Если текущий предмет не помещается в рюкзак
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W]; // Возвращаем максимальную стоимость
}

int main() {
    vector<int> values = {60, 100, 120};  // Стоимости предметов
    vector<int> weights = {10, 20, 30};   // Вес предметов
    int W = 50;                           // Максимальный вес рюкзака
    int n = values.size();                // Количество предметов

    int maxValue = rucksackDP(W, weights, values, n);
    cout << "Максимальная стоимость (динамическое программирование): " << maxValue << endl;

    return 0;
}