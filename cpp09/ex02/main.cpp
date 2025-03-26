#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: Not enough argument" << std::endl;
        return 1;
    }

    // type conversting from c's char** to std::string
    if (std::string(argv[1]).empty()) {
        std::cerr << "Error: empty string" << std::endl;
        return 1;
    }

    PmergeMe pmm;
    if (!pmm.parseAndValidateInput(argc, argv)){
        // std::cerr << "Error" << std::endl;
        return 1;
    }

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

    // for testing
    // std::cout << "Before(deque): ";
    // for (size_t i = 0; i < pmm.getDeque().size(); ++i) {
    //     std::cout << pmm.getDeque()[i];
    //     if (i < pmm.getDeque().size() - 1) {
    //         std::cout << " ";
    //     } else {
    //         std::cout << std::endl;
    //     }
    // }

    pmm.sortVector(pmm.getVector());    
    pmm.sortDeque(pmm.getDeque());

    std::cout << "After: ";
    for (size_t i = 0; i < pmm.getVector().size(); ++i) {
        std::cout << pmm.getVector()[i];
        if (i < pmm.getVector().size() - 1) {
            std::cout << " ";
        } else {
            std::cout << std::endl;
        }
    }

    // for testing
    // std::cout << "After(deque): ";
    // for (size_t i = 0; i < pmm.getDeque().size(); ++i) {
    //     std::cout << pmm.getDeque()[i];
    //     if (i < pmm.getDeque().size() - 1) {
    //         std::cout << " ";
    //     } else {
    //         std::cout << std::endl;
    //     }
    // }

    std::cout << "Time to process a range of " << pmm.getVector().size() << " elements with std::vector : "
     << pmm.getTimeVector().count() / 1000 << " us" << std::endl;

    std::cout << "Time to process a range of " << pmm.getVector().size() << " elements with std::deque : "
     << pmm.getTimeDeque().count() / 1000 << " us" << std::endl;

    return 0;
}