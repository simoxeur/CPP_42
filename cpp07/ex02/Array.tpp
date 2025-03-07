#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <iostream>
#include <exception>
#include <cstdlib>

template <typename T>
class Array
{
    private:
        int lenght;
        T*  arr_ptr;

    public:
        Array() 
        : lenght(0)
        , arr_ptr(NULL){}

        Array(unsigned int n)
        : lenght(n)
        , arr_ptr(new T[lenght]){}

        Array(const Array& other)
            : lenght(other.lenght)
            , arr_ptr(new T[lenght])
        {
            for(int i = 0; i < lenght; i++){
                arr_ptr[i] = other.arr_ptr[i];
            }
        }
        Array& operator=(const Array& other)
        {
            if(this != &other){
                delete[] arr_ptr;
                lenght = other.lenght;
                arr_ptr = new T[lenght];
                for(int i = 0; i < lenght; i++){
                    arr_ptr[i] = other.arr_ptr[i];
                }
            }
            return *this;
        }
        ~Array(){
            delete[] arr_ptr;
        }

        T& operator[](int index) const
        {
            if(index < 0 || index >= lenght){
                throw OutOfRange();
            }
            return arr_ptr[index];
        }
        int size() const
        {
            return lenght;
        }

        class OutOfRange : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "the index is out of range";
                }
        };
};

template <typename T>
void fill_arr(T& d, int lenght)
{
    double r = 42;
    for(int i = 0; i < lenght; i++){
        r += 0.5;
        d[i] = r;
    }
}

template <typename T>
void print_arr(T& d, int lenght)
{
    for(int i = 0; i < lenght; i++){
        std::cout << d[i];
        std::cout << (i != lenght -1 ? ", " : "");
    }
    std::cout << '\n';
}

#endif