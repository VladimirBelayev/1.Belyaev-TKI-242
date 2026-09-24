#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>       // Для std::abs

int main() {
    int K, n;
    std::vector<int> V;

    std::cout << "Введите целое число K (> 0): ";
    std::cin >> K;

    std::cout << "Введите количество элементов в векторе: ";
    std::cin >> n;

    std::cout << "Введите " << n << " целых чисел через пробел: \n";
    for (int i = 0; i < n; ++i) {
        int element;
        std::cin >> element;
        V.push_back(element);
    }

    // === ВСЯ ЛОГИКА И RETURN ВНУТРИ MAIN ===
    // [K] означает, что лямбда-функция "видит" переменную K из main.
    // (int x) — это текущий элемент вектора, который проверяет find_if.
    auto it = std::find_if(V.rbegin(), V.rend(), [K](int x) {
        return std::abs(x) > K; // Логика проверки и return находятся здесь!
        });

    std::cout << "\n--- РЕЗУЛЬТАТ ---\n";

    if (it == V.rend()) {
        std::cout << "0" << std::endl;
    }
    else {
        std::cout << "Последний элемент с модулем > " << K << " равен: " << *it << std::endl;
    }

    return 0;
}
