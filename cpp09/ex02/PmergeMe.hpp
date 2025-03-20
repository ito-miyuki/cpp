#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <sstream> // are we allowed to use it?

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
        void sortingVector();
        void sortingDeque();

        const std::vector<int>& getVector() const; // you might not need it
};