#include <iostream>
#include <list>
#include <iterator>

int main() {
    // Создаем тестовый список, количество элементов кратно 4
    std::list<int> L = { 10, 20, 30, 40, 50, 60, 70, 80 };

    // 1. Определяем диапазон для первой половины списка с помощью std::advance
    auto half_end = L.begin();
    std::advance(half_end, L.size() / 2); // Сдвигаем итератор на середину списка

    // 2. Переводим итераторы в формат обратных (reverse_iterator)
    std::list<int>::reverse_iterator r_start(half_end);
    std::list<int>::reverse_iterator r_end(L.begin());

    // 3. Цикл по обратному итератору
    for (auto r = r_start; r != r_end; ) {

        // Сначала делаем один шаг и проверяем, не дошли ли мы до конца диапазона
        if (++r == r_end) {
            // Если дошли — удаляем последний оставшийся нечетный элемент у L.begin()
            L.erase(L.begin());
            break;
        }

        // Если не дошли — безопасно удаляем элемент строго по формуле из указания
        L.erase(--r.base());

        // Делаем второй шаг цикла, чтобы пропустить четный элемент
        if (r != r_end) {
            ++r;
        }
    }

    // Вывод измененного списка в консоль для проверки результата
    for (int val : L) {
        std::cout << val << " ";
    }

    return 0;
}