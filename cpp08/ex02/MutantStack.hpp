/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:38:49 by mito              #+#    #+#             */
/*   Updated: 2025/01/03 19:13:10 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>

template<typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {
	public:
		MutantStack() {};
		~MutantStack() {};
		MutantStack(const MutantStack& other) {
			*this = other;
		};
		MutantStack& operator=(const MutantStack& other) {
			if (this != &other) {
				std::stack<T, Container>::operator=(other);
			}
			return (*this);
		};

		using iterator = typename Container::iterator; //alias for this type

		iterator begin() {
			return this->c.begin(); // this->c refers to the internal container used by std::stack
		}

		iterator end() {
			return this->c.end();
		}
};
