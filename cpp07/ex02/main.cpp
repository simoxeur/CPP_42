#include "Array.tpp"
#include <cstdlib>

#define MAX_VAL 750
int main(int, char**)
{
    try{
    {
        // double tests
        int len = 5;
        Array<double> dArr(len);
        fill_arr(dArr, len);
        print_arr(dArr, len);
        double* Arr = new double[len];
        fill_arr(Arr, len);
        print_arr(Arr, len);
        delete Arr;
        std::cout << "---------------------------\n";
    }
    {
        // chars tests
        int len = 5;
        Array<char> cArr(len);
        fill_arr(cArr, len);
        print_arr(cArr, len);
        char* Arr = new char[len];
        fill_arr(Arr, len);
        print_arr(Arr, len);
        delete Arr;
        std::cout << "---------------------------\n";
    }
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
    }
    catch(const std::exception& e){
        std::cout << e.what() << '\n';
    }
}