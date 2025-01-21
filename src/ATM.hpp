#ifndef ATM_HPP
#define ATM_HPP

#include <iostream>
#include <string>

#include "Bank.hpp"

using namespace std;

class ATM {
	public:
    virtual ~ATM() {};

    virtual bool insertCard(Bank *bank) = 0;
		virtual bool enterPIN(const string& pin) = 0;
    virtual void selectAccount(const string& accountType) = 0;
		virtual void clear() = 0;

		virtual long long seeBalance() = 0;
		virtual void deposit(long long amount) = 0;
		virtual void withdraw(long long amount) = 0;

		virtual void showAccountList() = 0;
		virtual void showMenu() = 0;
		virtual void run() = 0;
};

#endif