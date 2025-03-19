#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <sstream> // are we allowed to use it?

class PmergeMe {

    private:
        std::vector<int> _vector; // you might want to change it
        std::deque<int> _deque; // you might want to change it
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        static void sortingVector(std::string strNum);
        static void sortingDeque(std::string strNum);
};