#include "PmergeMe.hpp"


PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe& other){
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other){
    (void)other;
	return *this;   
}

void PmergeMe::sortVector(std::vector<int>& vector){
    std::cout << "You are in sortingVector()" << std::endl;

    if (vector.size() == 1) {
        return ;
    }

    std::vector<int> bigList; // store the bigger value
    std::vector<int> smallList; // store the smaller value

    size_t vectorSize = vector.size();

    for (size_t i = 0; i + 1 < vectorSize; i += 2) {
        int a = vector[i];
        int b = vector[i + 1];

        if (a < b) {
            bigList.push_back(b);
            smallList.push_back(a);
        } else {
            bigList.push_back(a);
            smallList.push_back(b);
        }
    }

    if (vectorSize % 2 != 0) {
        smallList.push_back(_intVector[vectorSize - 1]); // or you can use _intVector.back()
    }

    //for debuging
    for (size_t j = 0; j < bigList.size(); j++) {
        std::cout << "index[" << j << "] in  bigList is " << bigList[j] << std::endl;
    }
    for (size_t k = 0; k < smallList.size(); k++) {
        std::cout << "index[" << k << "] in  smallList is " << smallList[k] << std::endl;
    }

    sortVector(bigList);
}

void PmergeMe::sortDeque(){
    std::cout << "You are in sortingDeque()" << std::endl;
}

// you might need to delete it if you are not using it
std::vector<int>& PmergeMe::getVector() {
    return _intVector;
}


void PmergeMe::parseAndValidateInput(int argc, char **argv) {

    for (int i = 1; i < argc; i++) {
        std::string token = argv[i];

        // check chars one by one because stoi accepts something like 56as or 67f2
        for (size_t j = 0; j < token.length(); j++) {
            if (!isdigit(token[j])) {
                std::cerr << "It contains non-digit char" << std::endl; // delete it
            }
        }
        try {
            int num = std::stoi(token);

            if (num < 0) {
                std::cerr << "negative number are not allowed" << std::endl;
            }

            _intVector.push_back(num);
            _intDeque.push_back(num);
        } catch (const std::exception& e) {
            std::cerr << "Error: Invalid input. " << e.what() << std::endl;
        }
    }
}
