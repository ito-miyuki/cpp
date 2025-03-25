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

std::vector<size_t> PmergeMe::indexByJacobsthal(size_t listSize) {
    
    std::vector<size_t> indexList;
    std::vector<size_t> used;

    std::vector<int> jacobVector;
    jacobVector.push_back(0);
    if (listSize > 1) {
        jacobVector.push_back(1);
    }

    size_t j = 2;
    while (true) {
        size_t next = jacobVector[j - 1] + 2 * jacobVector[j - 2];
        if (next >= listSize) {
            break;
        }
        jacobVector.push_back(next);
        ++j;
    }

    for (size_t i = jacobVector.size(); i > 0; --i) {
        if (jacobVector[i - 1] < listSize && used.insert(jacobVector[i - 1].second)) {
            indexList.push_back(jacobVector[i - 1]);
        }
    }

    for (size_t i = 0; i < listSize; ++i) {
        if (used.insert(i).sedond) {
            indexList.push_back(i);
        }
    }
    return indexList;
}

void PmergeMe::sortVector(std::vector<int>& vector){
    // std::cout << "You are in sortingVector()" << std::endl;

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
        smallList.push_back(vector[vectorSize - 1]); // or you can use _intVector.back()
    }

    //for debuging
    // for (size_t n = 0; n < bigList.size(); n++) {
    //     std::cout << "index[" << n << "] in  bigList is " << bigList[n] << std::endl;
    // }
    // for (size_t k = 0; k < smallList.size(); k++) {
    //     std::cout << "index[" << k << "] in  smallList is " << smallList[k] << std::endl;
    // }

    sortVector(bigList);

    std::vector<size_t> insertOrder = indexByJacobsthal(smallList.size());

    for (size_t index : insertOrder) {
        if (index < smallList.size()) {
            std::vector<int>::iterator indexToInsert = std::lower_bound(bigList.begin(), bigList.end(), smallList[j]);
            bigList.insert(indexToInsert, smallList[index]);
        }
    }
    vector = bigList;
}

void PmergeMe::sortDeque(){
    std::cout << "You are in sortingDeque()" << std::endl;
}

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
