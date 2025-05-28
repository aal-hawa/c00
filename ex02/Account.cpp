#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>



int Account::_nbAccounts = 0;
	int Account::_totalAmount = 0;
	int Account::_totalNbDeposits = 0;
	int Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit)
{
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	//[19920104_091532] index:0;amount:42;created
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

void Account::displayAccountsInfos(void)
{
	//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << _totalAmount << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals()<< std::endl;

}

void Account::displayStatus(void) const
{
	//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" <<  _nbDeposits << ";withdrawals:" <<_nbWithdrawals<< std::endl;

}

Account::~Account(void)
{
	//[19920104_091532] index:0;amount:47;closed
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed"<< std::endl;

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
	_nbDeposits++;
	_totalNbDeposits += deposit;
	_amount += deposit;
	// _totalAmount += deposit;
	//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << checkAmount() << ";deposit" <<  deposit   << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits  << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (checkAmount() < withdrawal)
	{
		
		//[19920104_091532] index:0;p_amount:47;withdrawal:refused
		_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;

		return (false);
	}
	_nbWithdrawals ++;
	_totalNbWithdrawals += withdrawal;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	return (true);

	//[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << checkAmount() << ";withdrawal" <<  withdrawal   << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals  << std::endl;

}

int Account::checkAmount(void) const
{
	return (_amount - _nbDeposits);
	// return (_amount);
}

int Account::getNbAccounts(void)
{
	return(_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return(_totalAmount);

}
int Account::getNbDeposits(void)
{
	return(_totalNbDeposits);

}
int Account::getNbWithdrawals(void)
{
	return(_totalNbWithdrawals);

}


// void	Account::initAccountStatic(void)
// {
// 	_nbAccounts = 0;
// 	_totalAmount = 0;
// 	_totalNbDeposits = 0;
// 	_totalNbWithdrawals = 0;
// }