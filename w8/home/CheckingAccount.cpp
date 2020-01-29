/************************
*name:sahil lapsiwala
id:132584160
date:20/7/2017
file:CheckingAccount.cpp
email:snlapsiwala@myseneca.ca
***************************/
#include <iomanip>
#include "CheckingAccount.h"

using namespace std;

namespace ict{    
	
	// TODO: define CheckingAccount class member functions here  
	CheckingAccount::CheckingAccount(double bal, double transFee) :Account(bal)
	{
		transactionFee = transFee;
	}
	void CheckingAccount::chargeFee()// subtacts transaction fee from balance
	{
		double bal;
	    bal = getBalance() - transactionFee;
		setBalance(bal);
	}
	void CheckingAccount::credit(double cred)//credits the amount to balance and charges transactionfee
	{
		Account::credit(cred);
		chargeFee();
	}
	bool CheckingAccount::debit(double debt) //debits the amount from balance and charges transactionfee if true
	{
		bool valid;
	    valid = Account::debit(debt);
		if (valid==true) 
		{
			chargeFee();
		}
		return valid;
	}

	void CheckingAccount::display(ostream& out)const // displays the balance
	{
		out << "Account type: Checking" << endl;
		out << "Balance: $ " << fixed << setprecision(2) << getBalance() << endl;
		out << "Transaction Fee: " << transactionFee << endl;

	}

}

