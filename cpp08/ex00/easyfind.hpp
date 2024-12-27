/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:06:05 by mito              #+#    #+#             */
/*   Updated: 2024/12/27 14:11:08 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm> // for std::find
#include <stdexcept> // for std::runtime_error

template <typename T>
typename T::iterator easyfind(T& container, int value){
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), value);

	if (it == container.end()) {
		throw std::runtime_error("Value not found");
	}
	return it;
}
