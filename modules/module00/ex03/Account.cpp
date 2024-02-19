#include "Account.hpp"

Account::Account( int initial_deposit ) {
    this->_accountIndex = Account::_nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_totalAmount += initial_deposit;
    Account::_nbAccounts++;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}