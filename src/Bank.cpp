#include "Bank.hpp"

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
				accounts.push_back(&ac.second);
		}
	}
	return accounts;
}

void Bank::addAccount(const string &card, const string &username, const string &accountName, const long long &balance)
{
	Account nAccount(username);
	nAccount.setAccountName(accountName);
	nAccount.setBalance(balance);
	accountDic.push_back({card, nAccount});
}