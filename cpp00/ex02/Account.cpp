/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:51:25 by mito              #+#    #+#             */
/*   Updated: 2024/08/19 16:25:13 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

static int	_nbAccounts = 0;
static int	_totalAmount = 0;
static int	_totalNbDeposits = 0;
static int	_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
}
