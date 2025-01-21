#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>

using namespace std;

class Account
{
	private:
		static int cnt;

	protected:
		string userName;
		string userID;
		string AccountType;
		string AccountName;
		long long balance;

	public:
		Account(string name);
		virtual ~Account() {};
		const long long& getBalance() const;
		const string& getUserName() const;
		const string& getUesrID() const;
		const string& getAccountType() const;
		const string& getAccountName() const;

		void setBalance(const long long& amount);
		void setAccountName(const string& name);

		void addBalance(const long long& amount);
		void subBalance(const long long& amount);
};

#endif