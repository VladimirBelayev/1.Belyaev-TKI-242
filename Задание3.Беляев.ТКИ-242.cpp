#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <iterator>

int main() {
    std::vector<std::string> V1, V2;
    // Вектор V1
    std::cout << "Введите слова V1 (Заглавными через пробел): \n";
    V1.assign(std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>());
    std::cin.clear();
    // Вектор V2
    std::cout << "\nВведите слова V2 (Заглавными через пробел): \n";
    V2.assign(std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>());

    std::multimap<char, std::string> M;
    // Группировка V2 по последней букве
    std::for_each(V2.begin(), V2.end(), [&M](const std::string& w) {
        if (!w.empty()) {
            char key = w.back(); // ключ группировки
            M.insert({ key, w });
        }
        });
    // Сортируем V1
    std::sort(V1.begin(), V1.end());
    // Итоговый вектор V
    std::vector<std::pair<std::string, std::string>> V;
    // V1 и V2 в V
    std::for_each(V1.begin(), V1.end(), [&M, &V](const std::string& w1) {
        if (!w1.empty()) {
            char search_key = w1.front();
            auto range = M.equal_range(search_key);

            std::for_each(range.first, range.second, [&w1, &V](const auto& pair_m) {
                V.push_back({ w1, pair_m.second });
                });
        }
        });
    // Вывод
    std::cout << "\n РЕЗУЛЬТАТ " << std::endl;
    std::cout << "Размер вектора V: " << V.size() << std::endl;

    std::for_each(V.begin(), V.end(), [](const auto& p) {
        std::cout << "(" << p.first << ", " << p.second << ")" << std::endl;
        });

    return 0;
}
