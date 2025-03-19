#include "PmergeMe.hpp"

// should this be a member function?


std::vector<int> parseAndValidateInput(int argc, char **argv) {
    std::vector<int> intVector;

    for (int i = 1; i < argc; i++) {
        std::string token = argv[i];

        // check chars one by one because stoi accept something like 56as
        for (size_t j = 0; j < token.length(); j++) {
            if (!isdigit(token[j])) {
                std::cerr << "It contains non-digit char" << std::endl; // delete it
                return {}; // return an empty vector
            }
        }
        try {
            int num = std::stoi(token);

            if (num < 0) {
                std::cerr << "negative number are not allowed" << std::endl;
                return {}; // return an empty vector
            }

            intVector.push_back(num);
        } catch (const std::exception& e) {
            std::cerr << "Error: Invalid input. " << e.what() << std::endl;
        }
    }
    return intVector;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Not enough argument" << std::endl; // you might need to change this
        return 1;
    }

    if (std::string(argv[1]).empty()) { // type conversting from c's char** to std::string
        std::cerr << "Error: empty string detected" << std::endl; // modify it
        return 1;
    }

    std::vector<int> intVector = parseAndValidateInput(argc, argv);

    for (size_t i = 0; i < intVector.size(); ++i) {
        std::cout << "numVector[" << i << "] is " <<  intVector[i] << std::endl; // for debugging, delete it
    }

    PmergeMe::sortingVector(argv[1]);
    // PmergeMe::sortingDeque(argv[1]);

    return 0;
}