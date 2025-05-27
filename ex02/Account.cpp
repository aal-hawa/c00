#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

Account::Account()
{
	Account::_nbAccounts = 0;
	Account::_totalAmount = 0;
	Account::_totalNbDeposits = 0;
	Account::_totalNbWithdrawals = 0;
}

Account::Account(int initial_deposit)
{
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_amount = initial_deposit;
	Account::_totalAmount += _amount;
	_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	//[19920104_091532] index:0;amount:42;created
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created";
}

void Account::displayAccountsInfos(void)
{
	//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals();

}

void Account::displayStatus(void) const
{
	//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" <<  _nbDeposits << ";withdrawals:" <<_nbWithdrawals;

}

Account::~Account(void)
{
	//[19920104_091532] index:0;amount:47;closed
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed";

}

void	Account::_displayTimestamp( void )
{
	//[19920104_091532]
	std::time_t now = std::time(NULL);
	std::tm *localTime = std::localtime(&now);
	std::cout << "[" << std::setfill('0') << std::setw(4) << localTime->tm_year <<
	std::setw(2) << localTime->tm_mon << std::setw(2) << localTime->tm_mday <<
	"_" << std::setw(2) << localTime->tm_hour << std::setw(2) << localTime->tm_min <<
	std::setw(2) << localTime->tm_sec << "] ";

}

void Account::makeDeposit(int deposit)
{
	_nbDeposits  += deposit;
	Account::_totalNbDeposits += deposit;
	_amount += deposit;
	Account::_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (checkAmount() < withdrawal)
		return (false);
	_nbWithdrawals += withdrawal;
	Account::_totalNbWithdrawals += withdrawal;
	_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	return (true);
}

int Account::checkAmount(void) const
{
	return (_amount);
}

int Account::getNbAccounts(void)
{
	return(Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return(Account::_totalAmount);

}
int Account::getNbDeposits(void)
{
	return(Account::_totalNbDeposits);

}
int Account::getNbWithdrawals(void)
{
	return(Account::_totalNbWithdrawals);

}