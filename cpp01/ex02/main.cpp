#include <iostream>
#include <string>

int main()
{
    std::string     str = "HI THIS IS BRAIN";
    std::string*    stringPTR = &str; // A pointer to str.
    std::string&    stringREF = str; // A reference to the string

    std::cout << "Address of str: " << &str << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

    /*
    The value of the string variable.
    • The value pointed to by stringPTR.
    • The value pointed to by stringREF
    */

    std::cout << "value of the string: " << str << std::endl;
    std::cout << "value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "value pointed to by stringREF: " << stringREF << std::endl;
    return (0);
}

