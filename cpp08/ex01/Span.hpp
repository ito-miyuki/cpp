/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:15:15 by mito              #+#    #+#             */
/*   Updated: 2024/12/30 16:25:46 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

class Span {
	private:
		unsigned int _maxSize;
		std::vector<int> _vector;

	public:
		Span(unsigned int N);
		Span();
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int num);
		unsigned int shortestSpan();
		unsigned int longestSpan();

		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);




};
