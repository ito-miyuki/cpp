/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:42:00 by mito              #+#    #+#             */
/*   Updated: 2024/10/28 11:32:20 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(const Brain& other);
		~Brain();

		Brain& operator=(const Brain& other);

		std::string getIdea(int index);
		void setIdea(int index, std::string idea);
};

#endif
