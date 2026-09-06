#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>


    template <typename T>
    class array
    {
        private:

            T* fel; // fel - First element
            unsigned int size;
            unsigned int capacity;

        public:


            // CONSTRUCTORS
            array() : size(0), capacity(1)
            {
                fel = new T(capacity);
            };

            array(unsigned int size_) : size(size_), capacity(size*2)
            {
                fel = new T(size_);
            };
            T& operator[](unsigned int index) 
            {
                if (index < size)
                {
                    return fel[index];
                } else { throw std::out_of_range("Index out of range"); }
            }


            // METHODS
            
            // print
            void print () 
            {
                for (int i = 0; i < size; i++)
                {
                     std::cout << fel(i) << std::endl;
                }
            };

            void print (unsigned int n) 
            {
                std::cout << fel[n] << std::endl;
            }
            
            // reserve
            void reserve (unsigned int n) 
            {
                if (n > size) 
                {
                    
                }
            }

            //DESTRUCTOR
            ~array()
            {
                delete[] fel;
            }
    };

#endif