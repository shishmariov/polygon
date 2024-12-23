#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
    // unordered map для хранения ранее вычисленных подстрок
    std::unordered_map<std::string, bool> mp;

public:
    bool isScramble(std::string s1, std::string s2) {
        int n = s1.size();
        // проверка, равны ли две строки
        if (s1 == s2) {
            return true;
        }
        // инициализация векторов частот для s1, s2 и текущей подстроки
        std::vector<int> a(26, 0), b(26, 0), c(26, 0);
        // проверка, была ли текущая подстрока уже вычислена
        if (mp.count(s1 + s2)) {
            return mp[s1 + s2];
        }
        // проверка всех возможных разбиений двух строк
        for (int i = 1; i <= n - 1; i++) {
            int j = n - i;
            // обновление векторов частот для s1, s2 и текущей подстроки
            a[s1[i - 1] - 'a']++;
            b[s2[i - 1] - 'a']++;
            c[s2[j] - 'a']++;
            // проверка на совпадение символов текущей подстроки
            if (a == b && isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) {
                // если подстроки являются перемешанными версиями друг друга, возвращаем true
                mp[s1 + s2] = true;
                return true;
            }
            // проверка на совпадение символов текущей подстроки и ее дополнения
            if (a == c && isScramble(s1.substr(0, i), s2.substr(j)) && isScramble(s1.substr(i), s2.substr(0, j))) {
                // если подстроки являются перемешанными версиями друг друга, возвращаем true
                mp[s1 + s2] = true;
                return true;
            }
        }
        // если ни одно из разбиений не дало перемешанных версий, возвращаем false
        mp[s1 + s2] = false;
        return false;
    }
};

int main() {
    Solution sol;
    std::cout << std::boolalpha; // выводить true/false вместо 1/0
    std::cout << sol.isScramble("great", "rgeat") << std::endl; // должно вывести true
    return 0;
}