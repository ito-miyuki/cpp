/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:19:22 by mito              #+#    #+#             */
/*   Updated: 2024/12/20 14:29:09 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstdlib>
# include <stdexcept>

template <typename T>
class Array {
	private:
		T* _arr;
		unsigned int _arrSize;

	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array& other);
		Array<T>& operator=(const Array<T>& other);
		T& operator[](unsigned int i);
		unsigned int size() const;
};

template<typename T>
Array<T>::Array(){
	_arr = new T[0];
	_arrSize = 0;
}

template<typename T>
Array<T>::Array(unsigned int n){
	_arr = new T[n];
	_arrSize = n;
}

template<typename T>
Array<T>::~Array(){
	delete []_arr;
}

template<typename T>
Array<T>::Array(const Array<T>& other){
	this->_arrSize = other._arrSize;
	this->_arr = new T[this->_arrSize];
	for (unsigned int i = 0; i < other._arrSize; i++) {
		this->_arr[i] = other._arr[i];
	}
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other){
	if (this != &other) {

		delete[] this->_arr; // delete the array that is already constructed

		this->_arrSize = other._arrSize;
		this->_arr = new T[this->_arrSize];
		for (int i = 0; i < other._arrSize; i++) {
			this->_arr[i] = other._arr[i];
		}
	}
	return (*this);
}

template<typename T>
T& Array<T>::operator[](unsigned int i) {
	if (i >= this->_arrSize)
		throw std::out_of_range("Index is out of range");
	return this->_arr[i];
}

template<typename T>
unsigned int Array<T>::size() const {
	return this->_arrSize;
}


#endif
