#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>    // Необходим для использования std::istream_iterator
#include <cmath>       // Для std::abs

int main() {
    int K;
    std::cout << "Введите целое число K (> 0): ";
    // Проверяем корректность ввода
    if (!(std::cin >> K)) {
        return 1;
    }
    // Инициализация вектора элементами из входного потока от текущей позиции до конца файла
    std::cout << "Введите количество элементов в векторе: ";
    std::vector<int> V((std::istream_iterator<int>(std::cin)), std::istream_iterator<int>());

    auto it = std::find_if(V.rbegin(), V.rend(), [K](const int x) {
        return std::abs(x) > K; //Логика проверки
        });

    std::cout << "\n--- РЕЗУЛЬТАТ ---\n";
    // Проверка, был ли найден элемент, если итератор равен rend(), совпадений нет
    if (it == V.rend()) {
        std::cout << "0" << std::endl;
    }
    else {
        std::cout << "Последний элемент с модулем > " << K << " равен: " << *it << std::endl;
    }

    return 0;
}
