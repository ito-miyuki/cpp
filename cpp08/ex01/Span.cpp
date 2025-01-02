/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:24:50 by mito              #+#    #+#             */
/*   Updated: 2025/01/02 16:17:33 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <limits>

Span::Span(unsigned int N) : _maxSize(N){}

Span::Span() : _maxSize(0) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _vector(other._vector) {}

Span& Span::operator=(const Span& other){
	if (this != &other){
		_maxSize = other._maxSize;
		_vector = other._vector;
	}
	return *this;
}

Span::~Span(){}

void Span::addNumber(int num){
	if (_vector.size() >= _maxSize) {
		throw std::length_error("Maximum size exceeded");
	}
	_vector.push_back(num);
}

unsigned int Span::shortestSpan(){
	if (_vector.size() <= 1)
		throw std::logic_error("Cannot check the shortest span with fewer than 2 numbers");
	std::vector<int> sortedVec = _vector;
	std::sort(sortedVec.begin(), sortedVec.end());

	unsigned int minSpan = std::numeric_limits<unsigned int>::max();
	for (size_t i = 0; i < sortedVec.size(); ++i) {
		unsigned int span = sortedVec[i] - sortedVec[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}

unsigned int Span::longestSpan(){
	if (_vector.size() <= 1)
		throw std::logic_error("Cannot check the longest span with fewer than 2 numbers");
	int maxValue = *std::max_element(_vector.begin(), _vector.end());
	int minValue = *std::min_element(_vector.begin(), _vector.end());
	return (maxValue - minValue);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end){
	size_t sizeToAdd = std::distance(begin, end);

	if (_vector.size() + sizeToAdd > _maxSize) {
		throw std::length_error("Cannnot add because maximum size exceeded");
	}

	_vector.insert(_vector.end(), begin, end); // this can insert multiple elements at the same time
}

const std::vector<int>& Span::getVector() const {
	return _vector;
}
