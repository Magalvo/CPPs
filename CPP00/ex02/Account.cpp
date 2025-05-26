/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:00:53 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/09 18:54:57 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	    Account::getNbAccounts( void ){
	return (_nbAccounts);
}

int	    Account::getTotalAmount( void ){
	return (_totalAmount);
}

int	    Account::getNbDeposits( void ){
	return (_totalNbDeposits);
}

int	    Account::getNbWithdrawals( void ){
	return (_totalNbWithdrawals);
}

//?my putstr for cpp
static void    putStr(std::string str)
{
   std::cout << str; 
}

//?my putnbr for cpp 
static void    putNum(int num)
{
   std::cout << num; 
}

//?============== Innit Account ==============
Account::Account(int initial_deposit){
	_displayTimestamp();
	putStr("index:");
	putNum(_nbAccounts);
	putStr(";amount:");
	putNum(initial_deposit);
	putStr(";created:\n");
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

//?============== Account Destroyer ==============
Account::~Account(void){
	_displayTimestamp();
	putStr("index:");
	putNum(this->_accountIndex);
	putStr(";amount:");
	putNum(this->_amount);
	putStr(";closed\n");
	_nbAccounts--;
}

//?============== Account Info =============== 
void    Account::displayAccountsInfos( void ){
	_displayTimestamp();
	putStr("accounts:");
	putNum(_nbAccounts);
	putStr(";total:");
	putNum(_totalAmount);
	putStr(";deposits:");
	putNum(_totalNbDeposits);
	putStr(";withdrawals;");
	putNum(_totalNbWithdrawals);
	putStr("\n");
}

//?============== Actions ================
void	Account::makeDeposit( int deposit ){
	_displayTimestamp();
	putStr("index:");
	putNum(this->_accountIndex);
	putStr(";p_amount:");
	putNum(this->_amount);
	putStr(";deposit:");
	putNum(deposit);
	this->_amount += deposit;
	putStr(";amount:");
	putNum(this->_amount);
	this->_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount+=deposit;
	putStr(";nb_deposits:");
	putNum(this->_nbDeposits);
	putStr("\n");
}

bool	Account::makeWithdrawal( int withdrawal ){
	_displayTimestamp();
	putStr("index:");
	putNum(this->_accountIndex);
	putStr(";p_amount:");
	putNum(this->_amount);
	if (this->_amount - withdrawal < 0){
		putStr("withdrawal:refused\n");
		return (false);
	}
	putStr(";withdrawal:");
	putNum(withdrawal);
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	putStr(";amount");
	putNum(this->_amount);
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	putStr(";nb_withdrawals:");
	putNum(this->_nbDeposits);
	putStr("\n");
	return (true);
}

//?============== Info Check ================
int		Account::checkAmount( void ) const{
	_displayTimestamp();
	return (this->_totalAmount);
}

void	Account::displayStatus( void ) const{
	_displayTimestamp();
	putStr("index:");
	putNum(this->_accountIndex);
	putStr(";amount:");
	putNum(this->_amount);
	putStr(";deposits:");
	putNum(this->_nbDeposits);
	putStr(";withdrawals:");
	putNum(_nbWithdrawals);
	putStr("\n");
}

void	Account::_displayTimestamp(void){
	char	buffer[19];
	
	time_t	currentTime = time(0);
	tm*		localTime = localtime(&currentTime);
	strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", localTime);
	putStr(buffer);
}
