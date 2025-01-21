#ifndef SIMPLEATM_HPP
#define SIMPLEATM_HPP

#include "ATM.hpp"

// class Account;

class SimpleATM : public ATM
{
	private:
		// Account &account;
		string accountName;
		long long balance;
		bool isInsertedCard;
		bool isValidPin;
		bool isAccountSelected;

	public:
		SimpleATM();
		~SimpleATM();
    bool insertCard() override;
		bool enterPIN(const string& pin) override;
		void selectAccount(const string& accountType) override;
		long long seeBalance() override;
		void deposit(long long amount) override;
		void withdraw(long long amount) override;

		void showMenu();
		void run();
};

#endif