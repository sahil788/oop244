/************************
*name:sahil lapsiwala
id:132584160
date:20/7/2017
file:Account.h
***************************/

#ifndef ICT_ACCOUNT_H
#define ICT_ACCOUNT_H
#include <iostream>

using namespace std;

namespace ict{
   
	class Account
{
		private:
			double balance; // data member that stores the balance

		protected:
			double getBalance() const; // return the account balance
			void setBalance( double ); // sets the account balance

   		public:
			Account(double bal);

			// TODDO: Write a function prototype for the virtual function credit 
			virtual void credit(double credit);
			// TODO: Write a function prototype for the virtual function debit
			virtual bool debit(double debit);
			// TODO: Write a function prototype for the virtual function display
			virtual void display(ostream& out)const = 0;
	};
};
#endif
