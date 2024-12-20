/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:17:57 by mito              #+#    #+#             */
/*   Updated: 2024/12/20 12:56:44 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void printArr(T& arg) {
	std::cout << arg << std::endl;
}

template <typename T>
void incrementArr(T& arg) {
	arg++;
}

template <typename T>
void iter(T* arr, int arrLen, void (*f)(T&)) {
	for (int i = 0; i < arrLen; i++)
		(*f)(arr[i]);
}

#endif
