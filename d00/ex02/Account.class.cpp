#include "Account.class.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp( void )
{
	std::time_t t = std::time(0);
	std::tm *now = std::localtime(&t);

	std::cout << "[" << (now->tm_year + 1900)
			  << std::setw(2) << std::setfill('0') 
			  << (now->tm_mon + 1)
			  << now->tm_mday << "_"
			  << now->tm_hour
			  << now->tm_min
			  << now->tm_sec
			  << "] ";
}

Account::Account( int initial_deposit )
{
	this->_nbAccounts++;
	this->_accountIndex = this->_nbAccounts - 1;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = initial_deposit;
	this->_totalAmount += initial_deposit;
	this->_count = 0;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";created" << std::endl;
}

Account::Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";closed" << std::endl;
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
  	this->_nbDeposits++;
  	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << (this->_amount - deposit)
			  << ";deposit:" << deposit
			  << ";amount:" << this->_amount
			  << ";nb_deposits:" << this->_nbDeposits
			  << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (this->_amount < withdrawal)
	{
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
				  << ";p_amount:" << this->_amount
				  << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;
		this->_totalNbWithdrawals++;

		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
				  << ";p_amount:" << this->_amount + withdrawal
				  << ";withdrawal:" << withdrawal
				  << ";amount:" << this->_amount
				  << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	return (true);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals
			  << std::endl;
}

int Account::getNbAccounts(void) { return (_nbAccounts); }
int Account::getTotalAmount(void) { return (_totalAmount); }
int Account::getNbDeposits(void) { return (_totalNbDeposits); }
int Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); }

int		Account::checkAmount( void ) const {
	this->_count++;
	return (this->_count);
}