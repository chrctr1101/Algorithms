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
    int max_ = array_get(arr, 0);

    for (int i = 1; i < array_size(arr); i++)
    {
        if (max_ < array_get(arr, i))
        max_ = array_get(arr, i);
    }

    size_t in;

    bool* simple = new bool[max_];  

    for (int i = 0; i < max_; i++) {
        simple[i] = true;
    }
    simple[0] = simple[1] = false;

    for (int i = 2; i * i < max_; i++) {
        if (simple[i]) {
            for (int j = i * i; j < max_; j += i) {
                simple[j] = false;
            }
        }
    }

    for (int i = 0; i < array_size(arr); i++) {
        int n = array_get(arr, i); 
        if (!simple[n]) {        
            array_set(arr, i, 0);   
        }
    }
    
    delete[] simple;
        
    int writePos = 0; 

    for (int i = 0; i < array_size(arr); i++) 
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

    for (int i = 0; i < array_size(arr); i++)
    {
        output << array_get(arr, i) << " ";
        std::cout << array_get(arr, i) << " ";
    }
    output << std::endl;
    std::cout << std::endl;
}

void task2(Array *arr, std::ofstream& output)
{
    int list_[1001];

    for (int i = 0; i < 1001; i++)
    {
        list_[i] = 0;
    }

    for (int i = 0; i < array_size(arr); i++)
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
    task1(arr, output);
    array_delete(arr);

    input.clear();
    input.seekg(0, std::ios::beg);

    /* Create another array here */
    arr = array_create_and_read(input);
    task2(arr, output);
    array_delete(arr);
    input.close();
    output.close();
}
