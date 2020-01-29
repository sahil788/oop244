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
	bool CRA_Account::isValid() // check for validity of sin number 
{
	bool valid;
	if (Sin != 0)
	{

		if ((Sin > MIN_SIN) && (Sin < MAX_SIN))
		{
		 valid = true;
		}
		else
		{
			return 0;
			valid = false;
		}

	}
	if (valid == true) 
	{

		int temp = Sin;
		int checking_no = (Sin % 10);
		int no[9];
		int i;

		int  even = 0;
		int odd = 0;
		for (i = 8; i >= 0; i--) 
	{
			no[i] = temp % 10;
			temp = temp / 10;

   if (i % 2 == 1)
	{

	int even_digit = no[i] * 2;

	for (int j = 0; j < 2; j++)
	{
		int var = even_digit % 10;
		even_digit = even_digit / 10;
		even = even + var;
	}
	}
	if ((i % 2 == 0) && (i != 8))
	{
	 odd =odd + no[i];
	}
	}
	int total = even + odd;

	if ((total + checking_no) % 10 == 0)
	{
	   return 1;
	}
	else
	{
	   return 0;
	}
	}
	else
	{
	  return 0;
	}
	}
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) // stores the familyname, sin,givenname if sin is not equal to 0
        {

	if (sin != 0)
	{
		strcpy(family_name, familyName);
		strcpy(given_name, givenName);
		Sin = sin;
		m_years = 0;
	}
	else
	{
		Sin = 0;
	}


	}
	void CRA_Account::display() //displays the familyname, sin,givenname if sin is valid and checks for refund due or balance owing
       {
	if (isValid())
	{
		cout << "Family Name: " << family_name << endl;
		cout << "Given Name : " << given_name << endl;
		cout << "CRA Account: " << Sin << endl;



	for (int i = 0; i <m_years; i++)
	{
		if (m_balance[i] > 2)
		{

			cout << "Year (" << m_year[i] << ") balance owing: ";
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << m_balance[i] << endl;
			cout.unsetf(ios::fixed);
	}
	else if (m_balance[i] < (-2))
	{

		cout << "Year (" << m_year[i] << ") refund due: ";
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << m_balance[i] * -1.0 << endl;
		cout.unsetf(ios::fixed);
	}
	else
	{
	   cout << "Year (" << m_year[i] << ") No balance owing or refund due!" << endl;
	}

	}

	}
	else
	{
		cout << "Account object empty!" << endl;
	}
	}
	void CRA_Account::set(int year, double balance)// stores the balance according to the years entered
	{
	if (isValid() && m_years<MAX_YRS)
	{
		m_year[m_years] = year;
		m_balance[m_years] = balance;
		m_years += 1;
	}

	}
}