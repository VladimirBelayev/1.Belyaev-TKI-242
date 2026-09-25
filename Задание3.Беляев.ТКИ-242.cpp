#include <iostream>   // Библиотека для ввода-вывода (std::cin, std::cout)
#include <vector>     // Библиотека для работы с векторами (std::vector)
#include <string>     // Библиотека для работы со строками (std::string)
#include <map>        // Библиотека для работы с мультиотображениями (std::multimap)
#include <algorithm>  // Библиотека для алгоритмов (std::sort, std::for_each)
#include <utility>    // Библиотека для работы с парами элементов (std::pair)

int main() {    
    std::vector<std::string> V1, V2; // Исходные векторы для ввода слов

    // 1. ВВОД ЭЛЕМЕНТОВ ДЛЯ ВЕКТОРА V1
    std::cout << "Введите слова для V1 (ЗАГЛАВНЫМИ БУКВАМИ через пробел): \n";
    // Считываем поток ввода от начала до конца
    V1.assign(std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>());
    std::cin.clear(); // Сбрасываем флаг EOF (конца файла) у потока cin, чтобы была возможность считать данные для V2

    // 2. ВВОД ЭЛЕМЕНТОВ ДЛЯ ВЕКТОРА V2
    std::cout << "\nВведите слова для V2 (ЗАГЛАВНЫМИ БУКВАМИ через пробел): \n";
    // Считываем поток ввода от текущей позиции до конца
    V2.assign(std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>());
    // Создаем вспомогательный контейнер multimap M. Ключ — последняя буква слова (char), значение — само слово (string)
    std::multimap<char, std::string> M;

    // 3. ГРУППИРОВКА ЭЛЕМЕНТОВ ВЕКТОРА V2 ПО ПОСЛЕДНЕЙ БУКВЕ
   // Используем алгоритм for_each для перебора вектора V2
    std::for_each(V2.begin(), V2.end(), [&M](const std::string& w) {
        if (!w.empty()) {
            char key = w.back(); // Извлекаем последнюю букву слова в качестве ключа группировки

            // Находим позицию lower_bound для вставки нового элемента перед уже существующими.
            // Благодаря (hint), элементы с одинаковыми буквами запишутся в ОБРАТНОМ порядке.
            auto hint = M.lower_bound(key);
            M.insert(hint, { key, w }); // Вставляем пару {ключ, слово} в мультиотображение
        }
        });

    // 4. СОРТИРОВКА ВЕКТОРА V1 ПО АЛФАВИТУ
    // Порядок пар в результирующем векторе определяется алфавитным порядком первых элементов.
    std::sort(V1.begin(), V1.end());

    // Создаем итоговый вектор V, элементами которого будут пары строк (std::pair)
    std::vector<std::pair<std::string, std::string>> V;

    // 5. ФОРМИРОВАНИЕ ВНУТРЕННЕГО ОБЪЕДИНЕНИЯ ВЕКТОРОВ В ВЕКТОР V
    // Перебираем каждое слово из отсортированного вектора V1 через for_each
    std::for_each(V1.begin(), V1.end(), [&M, &V](const std::string& w1) {
        if (!w1.empty()) {
            char search_key = w1.front(); // Нам нужно найти слова из V2, оканчивающиеся на ПЕРВУЮ букву слова w1

            // equal_range мгновенно находит диапазон всех слов в M, подходящих под наш ключ-букву
            auto range = M.equal_range(search_key);

            // Перебираем найденный диапазон элементов внутри M
            std::for_each(range.first, range.second, [&w1, &V](const auto& pair_m) {
                // Добавляем созданную пару слов в итоговый вектор V
                V.push_back({ w1, pair_m.second });
                });
        }
        });

    // 6. ВЫВОД
    std::cout << "\n--- РЕЗУЛЬТАТ ---" << std::endl;
    // Выводим размер получившегося вектора V
    std::cout << "Размер вектора V: " << V.size() << std::endl;

    // Выводим все элементы-пары вектора V на экран с помощью алгоритма for_each
    std::for_each(V.begin(), V.end(), [](const auto& p) {
        std::cout << "(" << p.first << ", " << p.second << ")" << std::endl;
        });

    return 0; // Успешное завершение программы
}
