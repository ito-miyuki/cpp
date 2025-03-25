#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <sstream> // are we allowed to use it?
#include <algorithm> // std::lower_bound
#include <chrono> // for time stamp

class PmergeMe {

    private:
        std::vector<int> _intVector; // you might want to change it
        std::deque<int> _intDeque; // you might want to change it

        std::chrono::duration<double, std::micro> _timeVector;
        std::chrono::duration<double, std::micro> _timeDeque;


    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        void parseAndValidateInput(int argc, char **argv);

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