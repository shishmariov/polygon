#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    // Функция для вычисления минимальной стоимости найма k работников 
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        const int n = quality.size(); // Длина массива работников
        vector<array<double, 2>> worker(n); // Массив для хранения (wage/quality, quality)
        
        // Заполнение массива worker
        for(int i = 0; i < n; i++) {
            worker[i] = {(double)wage[i] / quality[i], (double)quality[i]}; 
        }

        // Сортировка работников по стоимости найма (wage/quality)
        sort(worker.begin(), worker.end());

        int quality_sum = 0; // Сумма качества выбранных работников

        priority_queue<int> pq; // max heap для хранения качества работников
        for(int i = 0; i < k; i++) { // Выбираем лучших k работников по соотношению quality/wage
            quality_sum += worker[i][1]; // Добавляем качество работника
            pq.push(worker[i][1]); // Добавляем качество в max heap
        }

        // Начальная стоимость найма
        double pay = quality_sum * worker[k - 1][0];
        
        // Итерация по оставшимся работникам
        for(int i = k; i < n; i++) {
            pq.push(worker[i][1]); // Добавляем нового работника в max heap
            quality_sum += worker[i][1] - pq.top(); // Обновляем сумму качества, теряя качество наивысшего работника
            pq.pop(); // Удаляем работника с наивысшим качеством

            // Обновляем минимальную стоимость найма
            pay = min(pay, quality_sum * worker[i][0]);
        }
        
        return pay; // Возвращаем минимальную стоимость найма
    }
};

// Инициализация стандартного ввода/вывода
auto init = []() {
    ios::sync_with_stdio(0); // Отключаем синхронизацию с C I/O
    cin.tie(0); // Отключаем завязку cin и cout
    cout.tie(0); // Отключаем завязку cout
    return 'c';
}();

int main() {
    Solution solution;
    vector<int> quality = {10, 20, 5};
    vector<int> wage = {70, 50, 30};
    int k = 2;
    
    double minCost = solution.mincostToHireWorkers(quality, wage, k);
    cout << "Минимальная стоимость найма " << k << " работников: " << minCost << endl;
    
    return 0;
}