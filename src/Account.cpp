#include "Account.hpp"

int Account::cnt = 0;

Account::Account(string name) : userName(name)
{
	userID = ++cnt;
}

const long long &Account::getBalance() const
{
	return balance;
}

const string &Account::getUserName() const
{
	return userName;
}

const string &Account::getUesrID() const
{
	return userID;
}

const string &Account::getAccountType() const
{
	return AccountType;
}

const string &Account::getAccountName() const
{
	return AccountName;
}

void Account::setBalance(const long long &amount)
{
	balance = amount;
}

void Account::setAccountName(const string &name)
{
	AccountName = name;
}

void Account::addBalance(const long long &amount)
{
	balance += amount;
}

void Account::subBalance(const long long &amount)
{
	balance -= amount;
}