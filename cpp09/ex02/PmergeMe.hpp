#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <sstream> // are we allowed to use it?
#include <algorithm> // std::lower_bound

class PmergeMe {

    private:
        std::vector<int> _intVector; // you might want to change it
        std::deque<int> _intDeque; // you might want to change it
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        void parseAndValidateInput(int argc, char **argv);
        void sortVector(std::vector<int>& vector);
        void sortDeque();
        std::vector<size_t> indexByJacobsthal(size_t n);

        std::vector<int>& getVector(); // you might not need it
};