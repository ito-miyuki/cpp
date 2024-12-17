/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:19:22 by mito              #+#    #+#             */
/*   Updated: 2024/12/17 14:56:48 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>

class Array {
	private:
		T* _arr;
		sie_t _arrSize;

	public:
		Array(void);
		Array(unsigned int n);
		~Array(void);
		Array(const Array& other);
		operator=(const Array& other);
};

template<typename T>
Array<T>::Array(void){
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
	delete []_array;
}

template<typename T>
Array<T>::Array(const Array<T>& other){
	other._arrSize = this._arrSize;
	other->_arr = new T[other._arrSize];
	for (int i = 0; i < other._arrSize; i++)
		other->_arr[i] = this->_arr[i];
}

#endif
