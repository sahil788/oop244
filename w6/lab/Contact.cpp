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
		number = 0;
	}
	
    //copies the valid numbers to allocated arrays
	Contact::Contact(const char* name, long long* phone, int no)
	{
		int no_of_digits[30];
		int count=0, no1 = 0;
		long long nums[1000];
		long long phoneNumber = 0;
		
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
			phoneNumber = phone[i];
			while (phoneNumber != 0)
			{
				no_of_digits[count] = phoneNumber % 10;
				phoneNumber /= 10;
				count++;
			}
			if (count == 11)
			{
				if (no_of_digits[5] != 0 && no_of_digits[8] != 0)
				{
					nums[no1] = phone[i];
					no1++;
				}
			}
			 else
			{
				if (no_of_digits[6] != 0 && no_of_digits[9] != 0)
				{
					nums[no1] = phone[i];
					no1++;
				}
			}
			while (count != 0)
			{
				no_of_digits[count] = 0;
				count--;
			}

		}
		if (no1 > 0)
		{
		  phone_number = new long long[no1];
		  number = no1;

		   for (int i = 0; i < no1; i++)
		    {
	             phone_number[i] = nums[i];
		    }
	       }
		else
		{
			phone_number = nullptr;
			number = 0;
		}
	}

	//destructor deallocates the dynamic memory

	Contact :: ~Contact()
	{
		delete[] phone_number;
	}

	//checks if the object is in safe empty state

	bool Contact::isEmpty() const
	{
		bool valid;
		if (names[0] == '\0' && phone_number == nullptr && number <= 0)
		{
			valid = true;
		}
		else
		{
			valid = false;
		}
		return valid;
	}

	//displays the data
	void Contact::display() const
	{
		int no_of_digits[30];
		int counter = 0;

		if (isEmpty() == true)
		{
			cout << "Empty contact!" << endl;
		}
		else {
			cout << names << endl;

			for (int i = 0; i < number; i++)
			{
				while (phone_number[i] != 0)
				{
					no_of_digits[counter] = phone_number[i] % 10;
					phone_number[i] /= 10;
					counter++;
				}
				if (counter == 11)
				{
					cout << "(+" << no_of_digits[10] << ") " << no_of_digits[9] << no_of_digits[8] << no_of_digits[7] << " "<< no_of_digits[6] << no_of_digits[5] << no_of_digits[4] << "-" << no_of_digits[3]
						<< no_of_digits[2] << no_of_digits[1] << no_of_digits[0] << endl;
				}
				if (counter == 12)
                                   {
					cout << "(+" << no_of_digits[11] << no_of_digits[10] << ") " << no_of_digits[9] << no_of_digits[8]<< no_of_digits[7] << " " << no_of_digits[6] << no_of_digits[5] << no_of_digits[4] << "-" << no_of_digits[3]
						<< no_of_digits[2] << no_of_digits[1] << no_of_digits[0] << endl;
				}
				while (counter != 0) {
					no_of_digits[counter] = 0;
					counter--;
				}
			}
		}

	}
}