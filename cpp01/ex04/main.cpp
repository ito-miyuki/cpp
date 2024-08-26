#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Invalid number of arguments." << std::endl;
        std::cout << "Input has to be: ./sed <filename> <s1> <s2>" << std::endl;
        return (1);
    }
    

}