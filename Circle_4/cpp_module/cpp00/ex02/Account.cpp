/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 09:21:21 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/12/01 08:20:25 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

static std::ostream& _summary(int index, int amount, bool prev) {
  return std::cout << " index:" << index
          << (prev ? ";p_amount:" : ";amount:") << amount;
}

int Account::getNbAccounts(void) {
  return Account::_nbAccounts;
}

int Account::getTotalAmount(void) {
  return Account::_totalAmount;
}

int Account::getNbDeposits(void) {
  return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
  return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
  Account::_displayTimestamp();
  std::cout << " accounts:" << Account::_nbAccounts
    << ";total:" << Account::_totalAmount
    << ";deposits:" << Account::_totalNbDeposits
    << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
  : _accountIndex(_nbAccounts++), _amount(initial_deposit),
    _nbDeposits(0), _nbWithdrawals(0) {
  Account::_displayTimestamp();
  _summary(_accountIndex, _amount, false) << ";created" << std::endl;
  Account::_totalAmount += initial_deposit;
}

Account::~Account(void) {
  Account::_displayTimestamp();
  _summary(_accountIndex, _amount, false) << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
  Account::_displayTimestamp();
  _summary(_accountIndex, _amount, true)
    << ";deposit:" << deposit
    << ";amount:" << _amount + deposit
    << ";nb_deposits:" << ++_nbDeposits << std::endl;
  _amount += deposit;
  Account::_totalAmount += deposit;
  ++Account::_totalNbDeposits;
}

bool Account::makeWithdrawal(int withdrawal) {
  Account::_displayTimestamp();
  _summary(_accountIndex, _amount, true);
  if (_amount - withdrawal < 0) {
    std::cout << ";withdrawal:refused" << std::endl;
    return false;
  }
  std::cout << ";withdrawal:" << withdrawal
    << ";amount:" << _amount - withdrawal
    << ";nb_withdrawals:" << ++_nbWithdrawals << std::endl;
  _amount -= withdrawal;
  Account::_totalAmount -= withdrawal;
  ++Account::_totalNbWithdrawals;
  return true;
}

int Account::checkAmount(void) const {
  return _amount;
}

void Account::displayStatus(void) const {
  Account::_displayTimestamp();
  _summary(_accountIndex, _amount, false)
    << ";deposits:" << _nbDeposits
    << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t	ts;
	char	buf[16];

	time(&ts);
	strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", localtime(&ts));
	std::cout << "[" << buf << "]";
}

Account::Account(void) {
  std::cout << "This is not gonna be called due to the private member"
    << std::endl;
}