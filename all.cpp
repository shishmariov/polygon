#include <iostream>
#include <string>
#include <unordered_map>

bool isScramble(const std::string& s1, const std::string& s2) {
    if (s1 == s2) return true; // если строки равны, они являются перемешанными версиями
    if (s1.length() != s2.length()) return false; // если длины строк разные, то они не могут быть перемешанными версиями

    int n = s1.length();
    std::unordered_map<char, int> count;
    
    // подсчёт количества символов в обеих строках
    for (int i = 0; i < n; ++i) {
        count[s1[i]]++;
        count[s2[i]]--;
    }
    
    // проверка, у всех ли символов счётчик стал равен нулю. если это не так, значит символы не совпадают
    for (const auto& pair : count) {
        if (pair.second != 0) return false;
    }

    // разбиение строк на подстроки
    for (int i = 1; i < n; ++i) {
        // проверка 2 случаев: с сохранением и изменением порядка подстрок
        if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && 
             isScramble(s1.substr(i), s2.substr(i))) ||
            (isScramble(s1.substr(0, i), s2.substr(n - i)) && 
             isScramble(s1.substr(i), s2.substr(0, n - i)))) {
            return true;
        }
    }
    
    return false;
}

int main() {
    std::string s1 = "great";
    std::string s2 = "rgeat";
    
    if (isScramble(s1, s2)) {
        std::cout << "true" << std::endl; // вывод: true
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}
