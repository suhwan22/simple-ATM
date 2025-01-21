#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <map>
#include <vector>
#include "Account.hpp"

class Bank
{
	private:
		string name;
		static vector<pair<string, Account>> accountDic;
	public:
		vector<Account *> checkPINwithCard(const string& card, const string& pin);
		void addAccount(const string& card, const string& username, const string& accountName, const long long& balance);
};

#endif