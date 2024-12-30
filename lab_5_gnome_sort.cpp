#include <iostream>
#include <vector>
#include <algorithm> // Для std::is_sorted
#include <cassert>   // Для assert

using namespace std;

class GnomeSort {
public:
    // Функция для выполнения гномьей сортировки
    void sort(vector<int>& arr) {
        int n = arr.size(); // Получаем размер массива
        int index = 0; // Начальный индекс

        while (index < n) {
            // Если элемент находится на начальном элементе или меньше
            if (index == 0 || arr[index - 1] <= arr[index]) {
                index++; // Переходим к следующему элементу
            } else {
                // Если элемент больше предыдущего, меняем их местами
                swap(arr[index], arr[index - 1]);
                index--; // Возвращаемся на один элемент назад
            }
        }
    }
};

// Функция для тестирования сортировки
void testGnomeSort() {
    GnomeSort sorter;

    // Лучший случай: массив уже отсортирован
    vector<int> bestCase = {1, 2, 3, 4, 5};
    sorter.sort(bestCase);
    assert(is_sorted(bestCase.begin(), bestCase.end()));

    // Средний случай: случайный массив
    vector<int> averageCase = {3, 1, 4, 2, 5};
    sorter.sort(averageCase);
    assert(is_sorted(averageCase.begin(), averageCase.end()));

    // Худший случай: массив отсортирован в обратном порядке
    vector<int> worstCase = {5, 4, 3, 2, 1};
    sorter.sort(worstCase);
    assert(is_sorted(worstCase.begin(), worstCase.end()));

    cout << "Все тесты пройдены успешно!" << endl;
}

int main() {
    testGnomeSort(); // Запускаем тесты
    return 0;
}

/*
Подсчет памяти:
- Основное использование памяти происходит из-за вектора arr.
- Вектор занимает O(N) памяти, где N - размер массива.
- Если N = 1e6, то для целочисленного массива размером в 1 миллион элементов при sizeof(int) = 4, память составит 4 * 1e6 = 4,000,000 байт (около 4 МБ).

Асимптотика:
- Временная сложность:
  - В худшем случае (если массив отсортирован в обратном порядке) алгоритм может потребовать O(N^2) операций для сортировки.
  - В лучшем случае (если массив уже отсортирован) сложность будет O(N).
  - Таким образом, общая временная сложность: O(N^2) в худшем случае.
- Пространственная сложность:
  - Гномья сортировка требует O(1) дополнительной памяти, так как мы сортируем массив на месте без использования каких-либо дополнительных структур данных.
*/