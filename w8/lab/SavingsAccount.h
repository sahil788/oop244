
/************************
*name:sahil lapsiwala
id:132584160
date:20/7/2017
file:SavingsAccount.h
***************************/
#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__
#include "Account.h"

using namespace std;

namespace ict{
	class SavingsAccount : public Account
	{
		private:
    		double interestRate; // interest rate (percentage) 
		public:
			SavingsAccount(double bal, double rate);
			double calculateInterest()const;
			virtual void display(ostream& out)const;
		
			// TODO: put prototypes here

   };
};
#endif
