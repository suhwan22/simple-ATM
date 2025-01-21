#include "SimpleATM.hpp"

SimpleATM::SimpleATM() : isInsertedCard(false), isValidPin(false), isAccountSelected(false) {}

SimpleATM::~SimpleATM() {}

bool SimpleATM::insertCard(Bank *bank)
{
	cout << "Card inserted.\n";
	cout << "Recognizing your card, please wait...\n";
	
	// if recognition was successful.
	cout << "Card recognition was successful.\n";
	isInsertedCard = true;
	this->bank = bank;

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

	// If the bank system successfully confirms the justification of the pin.
	// but this test card name == username.

	accounts = bank->checkPINwithCard(pin , pin);
	if (accounts.empty())
	{
		cout << "\n * Invalid PIN. *\n";
		isValidPin = false;
	}
	else
	{
		cout << "\n * PIN verified. *\n";
		isValidPin = true;
	}

	return isValidPin;
}

void SimpleATM::selectAccount(const string &accountType)
{
	ac = nullptr;
	for (int i = 0; i < (int)accounts.size(); i++)
	{
		if (accounts[i]->getAccountName() == accountType)
			ac = accounts[i];
	}
	if (ac == nullptr)
	{
		cout << "\n* This account name does not exist. Please select again *\n";
		isAccountSelected = false;
		return ;
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
	// 임시 bank data
	// 추후 DI로 변경
	Bank testBank;
	testBank.addAccount("suhwan", "suhwan", "test1", 1000000);
	testBank.addAccount("suhwan", "suhwan", "test2", 1000000);
	testBank.addAccount("suhwan", "suhwan", "lucky", 77777777);
	testBank.addAccount("suhwan", "suhwan", "bear", 99999999);
	testBank.addAccount("suhwan", "suhwan", "robotics", 123456789);

	while (1)
	{
		if (!isInsertedCard)
		{
			cout << "Please insert card.\n";
			if (!insertCard(&testBank))
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

		if (!isAccountSelected)
		{
			cout << "Please select the account you want to use.\n";
			showAccountList();
			string accountType;
			cin >> accountType;
			selectAccount(accountType);
			if (!isAccountSelected)
				continue;
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
			break;
	}
}

void SimpleATM::showAccountList()
{
	cout << "--------ACCOUNTS LIST---------\n";
	for (auto a : accounts)
		cout << " - " << a->getAccountName() << "\n";
	cout << "------------------------------\n";
}

void SimpleATM::clear()
{
	isInsertedCard = false;
	isValidPin = false;
	isAccountSelected = false;
}