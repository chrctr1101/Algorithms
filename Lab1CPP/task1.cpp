#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "array.h"

Array *array_create_and_read(std::ifstream &input)
{
    int n;
    input >> n;
    /* Create array */
    Array *arr = array_create(n);
    /* Read array data */
    for (int i = 0 ; i < n ; ++i)
    {
        int x;
        input >> x;
        array_set(arr, i, x);
    }
    return arr;
}

void task1(Array *arr, std::ofstream &output)
{ 
    size_t size = array_size(arr);
    if (size == 0) {
        output << std::endl;
        std::cout << std::endl;
        return;
    }

    int max_ = array_get(arr, 0);

    for (size_t i = 1; i < size; i++)
    {
        int val = array_get(arr, i);
        if (max_ < val)
            max_ = val;
    }

    // Если максимальное значение меньше 2, то простых чисел нет
    if (max_ < 2) {
        for (size_t i = 0; i < size; i++) {
            int n = array_get(arr, i);
            if (n < 2) {
                array_set(arr, i, 0);
            }
        }
        // Вывод результата
        for (size_t i = 0; i < size; i++) {
            output << array_get(arr, i) << " ";
            std::cout << array_get(arr, i) << " ";
        }
        output << std::endl;
        std::cout << std::endl;
        return;
    }

    // ВАЖНО: выделяем max_ + 1, чтобы иметь доступ к индексу max_
    bool* simple = new bool[max_ + 1];  

    // Инициализация
    for (int i = 0; i <= max_; i++) {
        simple[i] = true;
    }
    
    // 0 и 1 - не простые числа
    simple[0] = false;
    if (max_ >= 1) simple[1] = false;

    // Решето Эратосфена
    for (int i = 2; i * i <= max_; i++) {
        if (simple[i]) {
            for (int j = i * i; j <= max_; j += i) {
                simple[j] = false;
            }
        }
    }

    // Заменяем непростые числа на 0
    for (size_t i = 0; i < size; i++) {
        int n = array_get(arr, i);
        // Проверка: если число отрицательное, больше max_ или не простое
        if (n < 0 || n > max_ || !simple[n]) {
            array_set(arr, i, 0);
        }
    }
    
    delete[] simple;
        
    // Сдвигаем все ненулевые элементы в начало (сохраняя порядок)
    size_t writePos = 0; 
    for (size_t i = 0; i < size; i++) 
    {
        if (array_get(arr, i) != 0) 
        {
            if (i != writePos) 
            {
                int temp = array_get(arr, i);
                array_set(arr, i, array_get(arr, writePos));
                array_set(arr, writePos, temp);
            }
            writePos++;
        }
    }

    // Вывод результата
    for (size_t i = 0; i < size; i++)
    {
        output << array_get(arr, i) << " ";
        std::cout << array_get(arr, i) << " ";
    }
    output << std::endl;
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    Array *arr = NULL;

    std::ifstream input (argv[1]);
    std::ofstream output (argv[2]);
    arr = array_create_and_read(input);
    task1(arr, output);
    array_delete(arr);

    input.close();
    output.close();
}
