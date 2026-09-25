#include <fstream>    // Библиотека для работы с файлами (ofstream)
#include <iostream>   // Библиотека для работы с вводом-выводом (std::cin)
#include <string>     // Библиотека для работы со строками (std::string)
#include <algorithm>  // Библиотека с алгоритмами (std::transform)
#include <iterator>   // Библиотека для работы с итераторами (istream_iterator и ostream_iterator)

int main() {
    // Переменная name хранит имя будущего текстового файла
    std::string name = "name.txt";

    // Создаем и открываем текстовый файл с именем name для записи данных
    std::ofstream outfile(name);

    // Проверяем: если файл по какой-то причине не открылся, завершаем программу с ошибкой 1
    if (!outfile.is_open()) return 1;

    // Алгоритм transform считывает, преобразует и сразу записывает данные
    std::transform(
        std::istream_iterator<char>(std::cin),    // Начальный итератор: начинает читать символы из консоли (по заданию istream_iterator)
        std::istream_iterator<char>(),           // Конечный итератор: сигнализирует о конце ввода 
        std::ostream_iterator<int>(outfile, " "), // Выходной итератор: записывает числа в файл outfile, добавляя после каждого пробел " "

        // Лямбда-функция (правило преобразования):
        [](char c) {
            return static_cast<int>(c) * 2;       // Берет символ c, переводит его в числовой код (int) и умножает на 2
        }
    ); // Конец алгоритма transform

    // Закрываем файл, чтобы сохранить все записанные данные на диск
    outfile.close();

    // Успешное завершение программы
    return 0;
}