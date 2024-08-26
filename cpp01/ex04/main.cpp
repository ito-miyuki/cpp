#include "ReplaceFile.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Invalid number of arguments." << std::endl;
        std::cout << "Input has to be: ./sed <filename> <s1> <s2>" << std::endl;
        return (1);
    }
    ReplaceFile replacer(argv[1], argv[2], argv[3]);
    if (replacer.replacing() != 0)
        return (1);
    return (0);
}