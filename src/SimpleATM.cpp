#include "SimpleATM.hpp"

SimpleATM::SimpleATM() : isInsertedCard(false), isValidPin(false), isAccountSelected(false)
{
	// for test
	Account account("suhwan");
	account.setBalance(2000000);
	account.setAccountName("test1");

	Account account2("suhwan");
	account2.setBalance(5000000);
	account2.setAccountName("test2");

	Account account3("suhwan");
	account3.setBalance(7777777);
	account3.setAccountName("lucky");

	accounts.push_back(account);
	accounts.push_back(account2);
	accounts.push_back(account3);
}

SimpleATM::~SimpleATM() {}

bool SimpleATM::insertCard()
{
	cout << "Card inserted.\n";
	cout << "Recognizing your card, please wait...\n";
	
	// if recognition was successful.
	cout << "Card recognition was successful.\n";
	isInsertedCard = true;

	// if you fail to recognize your card.
	// cout << "Please insert the card again.\n";
	// isInsertedCard = false;

	return isInsertedCard;
}

bool SimpleATM::enterPIN(const string &pin)
{
	if (!isInsertedCard)
	{
		cout << "Please insert your card first.\n";
		isValidPin = false;
		return false;
	}

	cout << "\nChecking PIN, please wait...\n";
	bool fromBankSystem;
	// If the bank system successfully confirms the justification of the pin.
	if (pin == "password")
		fromBankSystem = true;
	else
		fromBankSystem = false;
	
	if (fromBankSystem)
	{
		cout << "\n * PIN verified. *\n";
		isValidPin = true;
	}
	else
	{
		cout << "\n * Invalid PIN. *\n";
		isValidPin = false;
	}
	return isValidPin;
}

void SimpleATM::selectAccount(const string &accountType)
{
	// 계좌 정보 가져오는 부분 수정 요망
	// to-do get account
	for (int i = 0; i < (int)accounts.size(); i++)
	{
		if (accounts[i].getAccountName() == accountType)
			ac = &accounts[i];
	}

	accountName = accountType;
	isAccountSelected = true;
	cout << "you selected: " << accountName << "\n";

}

long long SimpleATM::seeBalance()
{
	cout << "Current Balance: $" << ac->getBalance() << "\n";
	return balance;
}

void SimpleATM::deposit(long long amount)
{
	if (amount <= 0)
		cout << "\nPlease enter a valid deposit amount.\n";
	else
	{
		cout << "*****************************\n";
		cout << "Account balance\n";
		cout << "before deposit: $" << ac->getBalance() << "\n";
		ac->addBalance(amount);
		cout << "after deposit: $" << ac->getBalance() << "\n";
		cout << "*****************************\n";
	}
}

void SimpleATM::withdraw(long long amount)
{
	if (amount <= 0)
		cout << "\nPlease enter a valid deposit amount.\n";
	else if (balance < amount)
		cout << "not enough balance to withdraw.\n";
	else
	{
		cout << "*****************************\n";
		cout << "Account balance\n";
		cout << "before deposit: $" << ac->getBalance() << "\n";
		ac->subBalance(amount);
		cout << "after deposit: $" << ac->getBalance() << "\n";
		cout << "*****************************\n";
	}
}

void SimpleATM::showMenu()
{
	cout << "\n-----Menu-----\n";
	cout << "1. see balance\n";
	cout << "2. deposit\n";
	cout << "3. withdraw\n";
	cout << "4. select other account\n";
	cout << "5. exit\n";
}

void SimpleATM::run()
{
	while (1)
	{
		if (!isInsertedCard)
		{
			cout << "Please insert card.\n";
			if (!insertCard())
				continue;
		}
		if (!isValidPin)
		{
			cout << "Please enter the pin: ";
			string pin;
			cin >> pin;
			if (!enterPIN(pin))
				continue;
		}
		// showAccountList()
		if (!isAccountSelected)
		{
			cout << "Please select the account you want to use.\n";
			showAccountList();
			string accountType;
			cin >> accountType;
			selectAccount(accountType);
		}
		showMenu();
		int sel;
		cin >> sel;
		if (sel == 1)
			seeBalance();
		else if (sel == 2)
		{
			long long amount;
			cout << "Please enter the amount to deposit: ";
			cin >> amount;
			deposit(amount);
		}
		else if (sel == 3)
		{
			long long amount;
			cout << "Please enter the amount to withdraw: ";
			cin >> amount;
			withdraw(amount);
		}
		else if (sel == 4)
			isAccountSelected = false;
		else if (sel == 5)
			clear();
	}
}

void SimpleATM::showAccountList()
{
	cout << "--------ACCOUNTS LIST---------\n";
	for (auto name : accounts)
		cout << " - " << name.getAccountName() << "\n";
	cout << "------------------------------\n";
}

void SimpleATM::clear()
{
	isInsertedCard = false;
	isValidPin = false;
	isAccountSelected = false;
}