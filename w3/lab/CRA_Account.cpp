/***************************
file_name:CRA_Account.cpp
author: sahil lapsiwala
id:132584160
*/

#include <iostream>
#include<string.h>
#include "CRA_Account.h"
using namespace std;
namespace sict
{
	bool CRA_Account::isValid()// tests for validity of sin no
	{
		if (Sin != 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void CRA_Account::set(const char* familyName, const char* givenName, int sin)// tests the validity of sin entered by user and if valid copy the contents into the class
	{
		bool valid;
		if (MIN_SIN > sin||sin > MAX_SIN)
		{
			valid = false;
		}
		else
		{
			valid = true;
		}
		if (valid == true)
		{
			strcpy(family_name, familyName);
			strcpy(given_name, givenName);
			Sin = sin;
		}
		else
		{
			Sin = 0;
		}
	}
	void CRA_Account::display()
	{
		if (Sin != 0)
		{
			cout << "Family Name: " << family_name << endl;
			cout << "Given Name : " << given_name << endl;
			cout << "CRA Account: " << Sin << endl;
		}
		else
		{
			cout << "Account object is empty!" << endl;
		}
	}
}
