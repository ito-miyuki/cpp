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

void PmergeMe::sortingVector(std::string strNum){
    std::cout << "You are in sortingVector()" << std::endl;
    (void)strNum; //delete it

}

void PmergeMe::sortingDeque(std::string strNum){
    std::cout << "You are in sortingDeque()" << std::endl;
    (void)strNum; //delete it
}
