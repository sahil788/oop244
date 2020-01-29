/************************
*name:sahil lapsiwala
id:132584160
date:23/6/2017
file:Contact.cpp
***************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;

namespace sict
{
	// sets the object to safe empty state
	Contact::Contact()
	{
		names[0] = '\0';
		phone_number = nullptr;
		number1 = 0;
	}
	//copies the valid numbers to allocated arrays
	Contact::Contact(const char* name, long long* phone, int no) {
		int no1 = 0;
        long long nums[1000];

		if (name == NULL)
		{
			names[0] = '\0';
		}
		else
		{
			strncpy(names, name, 20);
			names[SIZE - 1] = '\0';
		}


		for (int i = 0; i < no; i++)
		{

			bool valid = isValid(phone[i]);
			if (valid==true)
			{
				nums[no1] = phone[i];
				no1++;
			}


		}
		if (no1 > 0)
		{
			phone_number = new long long[no1];
			number1 = no1;
			for (int i = 0; i < no1; i++)
			{
				phone_number[i] = nums[i];
			}
		}
		else
		{
			phone_number = nullptr;
			number1 = 0;
		}
	}

	//destructor deallocates the dynamic memory
	Contact::~Contact()
	{
		delete[] phone_number;

	}

	//checks if the object is in safe empty state

	bool Contact::isEmpty() const
	{
		if (names[0] == '\0' && phone_number == nullptr && number1 <= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//display function to print the data if current object is not empty
	void Contact::display() const
	{
		
		long long num = 0;
		if (isEmpty() == true)
		{
			cout << "Empty contact!" << endl;
		}
		else
		{
			cout << names << endl;

			for (int i = 0; i < number1; i++)
			{       int counter = 0;
		                int no_of_digits[30] = { 0 };
				num = phone_number[i];
				while (num != 0)
				{
					no_of_digits[counter] = num % 10;
					num = num / 10;
					counter++;
				}
				if (counter == 11)
				{
					cout << "(+" << no_of_digits[10] << ") " << no_of_digits[9] << no_of_digits[8] << no_of_digits[7] << " " << no_of_digits[6] << no_of_digits[5] << no_of_digits[4] << "-" << no_of_digits[3]
						<< no_of_digits[2] << no_of_digits[1] << no_of_digits[0] << endl;
				}
				else if (counter == 12)
				{
					cout << "(+" << no_of_digits[11] << no_of_digits[10] << ") " << no_of_digits[9] << no_of_digits[8] << no_of_digits[7] << " " << no_of_digits[6] << no_of_digits[5] << no_of_digits[4] << "-" << no_of_digits[3]
						<< no_of_digits[2] << no_of_digits[1] << no_of_digits[0] << endl;
				}

			}
		}
	}


	Contact::Contact(const Contact& source)
	{
		phone_number = nullptr;
		*this = source;
	}
	Contact& Contact:: operator=(const Contact& contact)
	{
		if (this != &contact)
		{
			if (contact.names != nullptr) {
				strncpy(names, contact.names, SIZE);
				names[SIZE - 1] = '\0';
			}
			number1 = contact.number1;

			delete[] phone_number;
			
			if (contact.phone_number != nullptr)
			{
				phone_number = new long long[number1];
				for (int i = 0; i<number1; i++)
				{
					phone_number[i] = contact.phone_number[i];
				}

			}
			else
			{
				phone_number = nullptr;
			}
		}

		return *this;

	}

	Contact&  Contact::operator+=(const long long number)
	{
		bool valid = isValid(number);
		if (valid==true)
		{
			int numbers = number1 + 1;
			long long *temp;
			temp = new long long[numbers];
			for (int i = 0; i<number1; i++) {
				temp[i] = phone_number[i];
			}
			temp[numbers - 1] = number;
			delete[]phone_number;
			phone_number = new long long[numbers];
			number1 = numbers;
			for (int i = 0; i<number1; i++) {
				phone_number[i] = temp[i];
			}
         }
		return *this;

	}
	bool isValid(long long phone1)
	{
		int counter = 0;
		int no_of_digit[30];
		bool valid=true;
		while (phone1 != 0)
		{
			no_of_digit[counter] = phone1 % 10;
			phone1 = phone1 / 10;
			counter++;
		}
		{
			if (counter == 11)
			{
				if (no_of_digit[5] != 0 && no_of_digit[8] != 0)
				{
					valid=true;
				}
			}
			else if (counter == 12)
			{
				if (no_of_digit[6] != 0 && no_of_digit[9] != 0)
				{
					valid=true;
				}
			}
			else
			{
				valid = false;
			}
		}
		return valid;
	}


}

