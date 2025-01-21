#include "SimpleATM.hpp"

SimpleATM::SimpleATM() : isInsertedCard(false), isValidPin(false), isAccountSelected(false) {}

SimpleATM::~SimpleATM() {}

bool SimpleATM::insertCard()
{
	isInsertedCard = true;
	cout << "Card inserted.\n";
	cout << "Recognizing your card, please wait...\n";
	
	// if recognition was successful.
	cout << "Card recognition was successful.\n";

	// If you fail to recognize your card.
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

	cout << "Checking PIN, please wait...\n";
	bool fromBankSystem;
	// If the bank system successfully confirms the justification of the pin.
	if (pin == "password")
		fromBankSystem = true;
	else
		fromBankSystem = false;
	
	if (fromBankSystem)
	{
		cout << "PIN verified.\n";
		isValidPin = true;
	}
	else
	{
		cout << "Invalid PIN.\n";
		isValidPin = false;
	}
	return isValidPin;
}

void SimpleATM::selectAccount(const string &accountType)
{
	accountName = accountType;
	isAccountSelected = true;
	cout << "you selected: " << accountName << "\n";

	// to-do get account
}

long long SimpleATM::seeBalance()
{
	cout << "Current Balance: $" << balance << "\n";
	return balance;
}

void SimpleATM::deposit(long long amount)
{
	if (amount <= 0)
		cout << "Please enter a valid deposit amount.\n";
	else
	{
		cout << "Account balance\n";
		cout << "before deposit: $" << balance << "\n";
		balance += amount;
		cout << "after deposit: $" << balance << "\n";
	}
}

void SimpleATM::withdraw(long long amount)
{
	if (amount <= 0)
		cout << "Please enter a valid deposit amount.\n";
	else if (balance < amount)
		cout << "not enough balance to withdraw.\n";
	else
	{
		cout << "Account balance\n";
		cout << "before withdraw: $" << balance << "\n";
		balance -= amount;
		cout << "after withdraw: $" << balance << "\n";
	}
}

void SimpleATM::showMenu()
{
	cout << "-----Menu-----" << endl;
	cout << "1. see balance\n";
	cout << "2. deposit\n";
	cout << "3. withdraw\n";
	cout << "4. exit\n";
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
			string accountType;
			cin >> accountType;
			selectAccount(accountType);
			balance = 1000000;
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
		if (sel == 4)
			break;
	}
}