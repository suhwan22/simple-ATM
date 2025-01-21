#ifndef ATM_HPP
#define ATM_HPP

#include <iostream>
#include <string>

using namespace std;

class ATM {
	public:
    virtual ~ATM() {};

    virtual bool insertCard() = 0;

		virtual bool enterPIN(const string& pin) = 0;

    virtual void selectAccount(const string& accountType) = 0;

		virtual long long seeBalance() = 0;
		virtual void deposit(long long amount) = 0;
		virtual void withdraw(long long amount) = 0;
};

#endif