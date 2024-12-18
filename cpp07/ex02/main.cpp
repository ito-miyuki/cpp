#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL); // create an Array<int> with 750 elements

    int* mirror = new int[MAX_VAL]; // create an int array with 750 elements

    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand(); // generate a random int
        numbers[i] = value; // store the randm value in the array
        mirror[i] = value; // store the randm value in the array, numbers and mirror are the same
    }
    //SCOPE
    {
        Array<int> tmp = numbers; // testing = operator
        Array<int> test(tmp); // testing copy constructor
    }

	// check if the mirror and numbers have the same value
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
        std::cerr << e.what() << '\n';
    }

	// test operator[] is working
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}
