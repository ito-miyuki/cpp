/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:44:47 by mito              #+#    #+#             */
/*   Updated: 2024/10/29 17:16:29 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include <string>

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice&);
		~Ice() override;
		Ice& operator=(const Ice&);
		void use(ICharacter& target) override;
		AMateria* clone() const override;
};

#endif

/*
clone() 関数：新しい Ice インスタンスを返す関数を定義します。
use() 関数：引数で渡される ICharacter オブジェクトの getName() を使用して、ターゲットの名前を取得し、出力メッセージ * shoots an ice bolt at <name> * を表示します。
*/
