#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Структура для хранения предмета
struct Item {
    int value;
    int weight;
    double ratio; // стоимость на единицу веса

    // Метод для вычисления соотношения стоимости к весу
    void calculateRatio() {
        ratio = (double)value / weight;
    }
};

// Функция для сравнения элементов при сортировке
bool compare(Item a, Item b) {
    return a.ratio > b.ratio; // Мы хотим, чтобы более высокая стоимость на единицу веса была первой
}

double rucksackGreedy(vector<Item>& items, int W) {
    sort(items.begin(), items.end(), compare); // Сортируем по соотношению стоимости к весу

    double totalValue = 0.0;
    for (auto& item : items) {
        if (W >= item.weight) {
            //Если в рюкзак вмещается весь предмет
            W -= item.weight;
            totalValue += item.value;
        } else {
            // Если не вмещается, берем дробную часть предмета
            totalValue += item.ratio * W;
            break; // Рюкзак полон
        }
    }
    return totalValue;
}

int main() {
    vector<Item> items = { {60, 10}, {100, 20}, {120, 30} };
    for (auto& item : items) {
        item.calculateRatio();  // Рассчитываем соотношение
    }
    int W = 50; // Максимальный вес рюкзака

    double maxValue = rucksackGreedy(items, W);
    cout << "Максимальная стоимость (жадный алгоритм): " << maxValue << endl;

    return 0;
}