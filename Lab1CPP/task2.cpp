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

void task2(Array *arr, std::ofstream& output)
{
    int list_[1001];

    for (int i = 0; i < 1001; i++)
    {
        list_[i] = 0;
    }

    for (size_t i = 0; i < array_size(arr); i++)
    {
        list_[array_get(arr, i)]++;
    }

    int max_ = 0;      

    for (int i = 0; i < 1001; i++)
    {
        if (list_[i] > max_)  
        {
            max_ = i;
        }
    }

    std::cout << max_;
    output << max_;
}

int main(int argc, char **argv)
{
    Array *arr = NULL;

    std::ifstream input (argv[1]);
    std::ofstream output (argv[2]);
    arr = array_create_and_read(input);
    task2(arr, output);

    array_delete(arr);
    input.close();
    output.close();
}
