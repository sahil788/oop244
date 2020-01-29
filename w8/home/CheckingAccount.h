/************************
*name:sahil lapsiwala
id:132584160
date:20/7/2017
file:CheckingAccount.h
email:snlapsiwala@myseneca.ca
***************************/
#ifndef SICT_CHECKINGACCOUNT_H__
#define SICT_CHECKINGACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict{
	class CheckingAccount : public Account {
		private:
			double transactionFee;

			// TODO: chargeFee subtract transaction fee form the balance
			void chargeFee();
		public:

			// TODO: constructor initializes balance and transaction fee 
			CheckingAccount(double bal, double transFee);

			// TODO: Write a function prototype to override credit function
			virtual void credit(double credit);
			// TODO: Write a function prototype to override debit function
			virtual bool debit(double debit);
			// TODO: Write a function prototype to  override display function
			virtual void display(ostream& out)const;
	};
};
#endif
