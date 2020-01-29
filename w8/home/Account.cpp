/************************
*name:sahil lapsiwala
id:132584160
date:20/7/2017
file:Account.cpp
email:snlapsiwala@myseneca.ca
***************************/
#include "Account.h"

using namespace std;

namespace ict {

	// constructor   
	Account::Account(double bal)
	{
		balance = bal;
	}

	// credit (add) an amount to the account balance
	void Account::credit(double credit)
	{
		balance += credit;
	}

	// debit (subtract) an amount from the account balance return bool 
	bool Account::debit(double debit)
	{
		if (balance > debit)
		{
			balance -= debit;
			return true;
		}
		else
		{
			return false;
		}
	}

	double Account::getBalance() const
	{
		return balance;
	}

	void Account::setBalance(double newBalance)
	{
		balance = newBalance;
	}
}