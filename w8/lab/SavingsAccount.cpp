
/************************
*name:sahil lapsiwala
id:132584160
date:20/7/2017
file:SavingsAccount.cpp
***************************/
#include <iostream>
#include<iomanip>
#include "SavingsAccount.h"


using namespace std;

namespace ict
{
	// TODO: Implement SavingsAccount member functions here
	SavingsAccount::SavingsAccount(double bal, double rate) :Account(bal)
	{
		if (rate < 0)
		{
			interestRate = 0;
		}
		else 
                     {
                       interestRate = rate;
                     }
	}
	double SavingsAccount::calculateInterest()const
	{
		double interest;
		 interest = interestRate*getBalance();

		return interest;

	}
	void SavingsAccount::display(ostream& out)const
	{
		out << "Account type: Saving" << endl;
		out << "Balance: $ " << fixed << setprecision(2) << getBalance() << endl;
		out << "Interest Rate (%): " << interestRate * 100 << endl;
    }
}