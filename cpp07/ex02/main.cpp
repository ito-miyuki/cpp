#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750


void testForCreateArray() {

	std::cout << "---testForCreateArray()---\n";
	std::cout << "-Double Array\n";
	Array<double> doubleArray(4);
	doubleArray[0] = 1.12;
	doubleArray[1] = 2.23;
	doubleArray[2] = 3.34;
	doubleArray[3] = 4.45;

	for (unsigned int i = 0; i < doubleArray.size(); i++) {
		std::cout << doubleArray[i] << std::endl;
	}

	std::cout << std::endl;

	std::cout << "-String Array\n";
	Array<std::string> stringArray(3);
	stringArray[0] = "Hello";
	stringArray[1] = "Can you";
	stringArray[2] = "hear me?";

	for (unsigned int i = 0; i < stringArray.size(); i++) {
		std::cout << stringArray[i] << std::endl;
	}

}

int main(int, char**)
{

	std::cout << "---test from subject---\n";
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

	testForCreateArray();
	
    return 0;
}
