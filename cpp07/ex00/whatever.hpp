/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:55:48 by mito              #+#    #+#             */
/*   Updated: 2024/12/16 15:05:52 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T& a, T&b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T& a, T& b) {
	if (a >= b)
		return b;
	else
		return a;
}
// it can write like this: return a < b ? a : b

template <typename T>
T max(T& a, T& b) {
	if (a >= b)
		return a;
	else
		return b;
}

#endif
