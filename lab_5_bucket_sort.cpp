#include <iostream>
#include <vector>
#include <algorithm> // Для std::sort и std::is_sorted
#include <cassert>   // Для assert

using namespace std;

class BucketSort {
public:
    // Функция для выполнения вёдерной сортировки
    void sort(vector<int>& arr, int k) {
        if (arr.empty()) return;

        int maxVal = *max_element(arr.begin(), arr.end()); // Находим максимальное значение
        int minVal = *min_element(arr.begin(), arr.end()); // Находим минимальное значение

        // Количество ведер
        int bucketCount = (maxVal - minVal) / k + 1;

        // Создание ведер
        vector<vector<int>> buckets(bucketCount);

        // Распределяем элементы по ведрам
        for (int num : arr) {
            int bucketIndex = (num - minVal) / k; // Индекс ведра для текущего элемента
            buckets[bucketIndex].push_back(num);
        }

        // Сортируем каждое ведро и объединяем' их
        arr.clear();
        for (auto& bucket : buckets) {
            sort(bucket.begin(), bucket.end()); // Сортируем ведро с помощью std::sort
            arr.insert(arr.end(), bucket.begin(), bucket.end()); // Объединяем
        }
    }
};

// Функция для тестирования вёдерной сортировки
void testBucketSort() {
    BucketSort sorter;

    // Лучший случай: элементы равномерно распределены
    vector<int> bestCase = {1, 2, 3, 4, 5};
    sorter.sort(bestCase, 1);
    assert(is_sorted(bestCase.begin(), bestCase.end()));

    // Средний случай: случайный массив
    vector<int> averageCase = {3, 1, 4, 2, 5};
    sorter.sort(averageCase, 1);
    assert(is_sorted(averageCase.begin(), averageCase.end()));

    // Худший случай: все элементы одинаковые
    vector<int> worstCase = {5, 5, 5, 5, 5};
    sorter.sort(worstCase, 1);
    assert(is_sorted(worstCase.begin(), worstCase.end()));

    cout << "Все тесты пройдены успешно!" << endl;
}

int main() {
    testBucketSort(); // Запускаем тесты
    return 0;
}

/*
Подсчет памяти:
- Пространственная сложность алгоритма вёдерной сортировки составляет O(N + k), где N - количество элементов, а k - количество ведер. 
- Каждый элемент массива попадает в ведро, поэтому пространство для ведер составляет O(N).
- Если k << N, то k можно считать константой, и память будет близка к O(N).

Асимптотика:
- Временная сложность: 
    - O(N + k) в среднем и лучшем случае, когда элементы заранее равномерно распределены между ведрами.
    - Худший случай ресурсов может составлять O(N^2) (из-за сортировки внутри ведер), если элементы очень неравномерно распределены.
- Пространственная сложность: O(N + k), где k - количество ведер.
*/