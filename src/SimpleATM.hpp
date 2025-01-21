#ifndef SIMPLEATM_HPP
#define SIMPLEATM_HPP

#include "ATM.hpp"
#include "Account.hpp"
#include <vector>


class SimpleATM : public ATM
{
	private:
		Bank *bank;
		vector<Account *> accounts;

		Account *ac;
		string accountName;
		long long balance;

		bool isInsertedCard;
		bool isValidPin;
		bool isAccountSelected;

	public:
		SimpleATM();
		~SimpleATM();

    bool insertCard(Bank *bank) override;
		bool enterPIN(const string& pin) override;
		void selectAccount(const string& accountType) override;
		void clear() override;

		long long seeBalance() override;
		void deposit(long long amount) override;
		void withdraw(long long amount) override;

		void showAccountList() override;
		void showMenu() override;
		void run() override;
};

#endif