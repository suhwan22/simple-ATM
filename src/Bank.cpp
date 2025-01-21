#include "Bank.hpp"

Bank::~Bank()
{
	for (auto p : accountDic)
		delete p.second;
}

vector<Account *> Bank::checkPINwithCard(const string &card, const string &pin)
{
	bool isValidPin;
	// bank system check pin with card and set isValidPin true or false;
	isValidPin = true;

	vector<Account *> accounts;
	if (isValidPin)
	{
		for (auto ac : accountDic)
		{
			if (ac.first == card)
				accounts.push_back(ac.second);
		}
	}
	return accounts;
}

void Bank::addAccount(const string &card, const string &username, const string &accountName, const long long &balance)
{
	Account *account = new Account(username);
	account->setAccountName(accountName);
	account->setBalance(balance);
	accountDic.push_back({card, account});
}