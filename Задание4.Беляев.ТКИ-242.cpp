#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // Обязательно для std::bind и std::placeholders
#include <cmath>       // Для функции взятия модуля std::abs

// === Задача 1: Определение функционального объекта less_abs ===
// Структура наследована от std::binary_function (современный аналог обобщенной структуры function)
struct less_abs {
    bool operator()(int a, int b) const {
        return std::abs(a) < std::abs(b); // Возвращает true, если модуль 'a' меньше модуля 'b'
    }
};

int main() {
    int K, n;
    std::vector<int> V;

    // 1. Самостоятельный ввод числа K
    std::cout << "Введите целое число K (> 0): ";
    std::cin >> K;

    // 2. Самостоятельный ввод элементов вектора V
    std::cout << "Введите количество элементов в векторе: ";
    std::cin >> n;

    std::cout << "Введите " << n << " целых чисел через пробел: " << std::endl;
    for (int i = 0; i < n; ++i) {
        int element;
        std::cin >> element;
        V.push_back(element); // Добавляем число в вектор
    }

    // === Задача 4: Поиск последнего элемента, у которого |V[i]| > K ===
    using namespace std::placeholders; // Нужен для использования заполнителя _1

    // Ищем С конца вектора с помощью обратных итераторов rbegin() и rend()
    auto it = std::find_if(V.rbegin(), V.rend(), std::bind(less_abs(), K, _1));

    std::cout << "\n--- РЕЗУЛЬТАТ ---" << std::endl;

    // Если find_if дошел до конца (rend), значит подходящих элементов нет
    if (it == V.rend()) {
        std::cout << "0" << std::endl; // По условию выводим 0, если элемент не найден
    }
    else {
        // Если нашли, выводим сам элемент
        std::cout << "Последний элемент с модулем > " << K << " равен: " << *it << std::endl;
    }

    return 0;
}