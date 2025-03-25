#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm> // std::lower_bound
#include <chrono> // for time stamp

class PmergeMe {

    private:
        std::vector<int> _intVector;
        std::deque<int> _intDeque;

        std::chrono::duration<double, std::micro> _timeVector;
        std::chrono::duration<double, std::micro> _timeDeque;

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        bool parseAndValidateInput(int argc, char **argv);

        void sortVector(std::vector<int>& vector);
        void sortVectorAlgorithm(std::vector<int>& vector);

        void sortDeque(std::deque<int>& deque);
        void sortDequeAlgorithm(std::deque<int>& deque);

        std::vector<size_t> indexByJacobsthal(size_t n);

        std::vector<int>& getVector();
        std::deque<int>& getDeque();

        std::chrono::duration<double, std::micro> getTimeVector();
        std::chrono::duration<double, std::micro> getTimeDeque();
};