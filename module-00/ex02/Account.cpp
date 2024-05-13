#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

// init statics

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// constructors definitions

Account::Account(int initial_deposit) {
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	this->_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created" << std::endl;
}

// destructors definitions

Account::~Account() {
	this->_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "closed" << std::endl;
	return;
}

// getters definitions

int	Account::getNbAccounts( void ) {
	_nbAccounts++;
	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return _totalAmount;
}

int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout
		<< "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawals:" << _totalNbWithdrawals << std::endl;
}

// methods definitions

void	Account::_displayTimestamp( void ) {
	std::time_t	time = std::time(0);
	std::tm*	now = std::localtime(&time);

	std::cout << std::setfill('0')
		<< "[" << now->tm_year + 1900
		<< std::setw(2) << now->tm_mon
		<< std::setw(2) << now->tm_mday
		<< "_"
		<< std::setw(2) << now->tm_hour
		<< std::setw(2) << now->tm_min
		<< std::setw(2) << now->tm_sec << "] ";
}

void	Account::makeDeposit(int deposit) {
	int	p_amount = this->_amount;

	_totalNbDeposits++;
	_totalAmount += deposit;
	this->_nbDeposits++;
	this->_amount += deposit;

	this->_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "p_amount:" << p_amount << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << this->_amount << ";"
		<< "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	int	p_amount = this->_amount;

	if (this->_amount < withdrawal) {
		this->_displayTimestamp();
		std::cout
			<< "index:" << this->_accountIndex << ";"
			<< "p_amount:" << p_amount << ";"
			<< "withdrawal:refused" << std::endl;
		return false;
	}
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	
	this->_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "p_amount:" << p_amount << ";"
		<< "withdrawal:" << withdrawal << ";"
		<< "amount:" << this->_amount << ";"
		<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount() const {
	return (this->_amount);
}

void	Account::displayStatus() const {
	this->_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}