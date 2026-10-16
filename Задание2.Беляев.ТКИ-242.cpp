#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

int main() {
    std::list<int> L;
    int n;

    // Ввод количества элементов
    std::cout << "Введите количество элементов списка (больше 0 и кратно 4):";
    if (!(std::cin >> n) || n <= 0 || n % 4 != 0) {
        std::cout << "Ошибка: количество элементов должно быть положительным и кратным 4" << std::endl;
        return 1;
    }
    // Ввод элементов списка
    std::cout << "Введите " << n << " чисел через пробел: ";
    std::copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(L));

    // Текущее положение
    int current_pos = n / 2;

    // Цикл удаления
    while (current_pos > 0) {
        auto half_end = L.begin();
        std::advance(half_end, current_pos); 
        std::list<int>::reverse_iterator r(half_end);
        if (current_pos % 2 == 0) { 
            if (current_pos == 2) {
                L.erase(L.begin());
            }
            else {
                L.erase(--(++r).base());
            }
            // После удаления элемента, сдвигаемся на 1
            --current_pos;
        }
        --current_pos;
    }
    // Вывод
    std::cout << "Результат: ";
    for (int val : L) {
        std::cout << val << " ";
    }
    return 0;
}
