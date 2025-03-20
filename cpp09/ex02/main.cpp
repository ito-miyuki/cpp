#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Not enough argument" << std::endl; // you might need to change this
        return 1;
    }

    if (std::string(argv[1]).empty()) { // type conversting from c's char** to std::string
        std::cerr << "Error: empty string detected" << std::endl; // modify it
        return 1;
    }

    PmergeMe pmm; // better name?
    pmm.parseAndValidateInput(argc, argv);

    // this can be one function to print vefire resuly
    std::cout << "Before: ";
    for (size_t i = 0; i < pmm.getVector().size(); ++i) {
        std::cout << pmm.getVector()[i];
        if (i < pmm.getVector().size() - 1) {
            std::cout << " ";
        } else {
            std::cout << std::endl;
        }
    }

    pmm.sortingVector();
    pmm.sortingDeque();

    return 0;
}