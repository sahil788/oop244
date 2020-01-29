// contains all functions implementations
//passenger.cpp
//sahil lapsiwala
//12/6/17

#include <iostream>
#include <cstring>
#include "Passenger.h"

// TODO: continue your namespace here
using namespace std;
namespace sict {
	Passenger::Passenger()//puts into safe empty state
	{
		passenger_name[0] = '\0';
		destination[0] = '\0';
		year = 0;
		month = 0;
		day = 0;

	}
	Passenger::Passenger(const char *PassengerName, const char *Destination) //checks for validity of string and if valid copies it to object otherwise puts to safe empty state

	{
		if ((PassengerName != nullptr) && (Destination != nullptr))
		{
			strncpy(passenger_name, PassengerName, MAX_SIZE);
			strncpy(destination, Destination, MAX_SIZE);
			year = 2017;
			month = 07;
			day = 01;
		}
		else
		{
			passenger_name[0] = '\0';
			destination[0] = '\0';
			year = 0;
			month = 0;
			day = 0;
		}
	}
	Passenger::Passenger(const char *PassengerName, const char *Destination, const int m_Year, const int m_month, const int m_day)// checks for validity of year date month and if the passengerNmae and Destination are not in safe empty state
	{
		if (PassengerName != nullptr && Destination != nullptr && (m_Year >= 2017 && m_Year <= 2020) && (m_month >= 1 && m_month <= 12) && (m_day >= 1 && m_day <= 31))
		{
			strncpy(passenger_name, PassengerName, MAX_SIZE);
			passenger_name[32] = '\0';
			strncpy(destination, Destination, MAX_SIZE);
			destination[32] ='\0';
			year = m_Year;
			month = m_month;
			day = m_day;

		}
		else
		{
			passenger_name[0] = '\0';
			destination[0] = '\0';
			year = 0;
			month = 0;
			day = 0;
		}
	}

	bool Passenger::isEmpty() const//returns the validity of safe empty state

	{
		bool valid;
		if ((passenger_name[0] == '\0') || (destination[0] == '\0'))
		{
			valid = true;
		}
		else
		{
			valid = false;
		}
		return valid;
	}
	void Passenger::display() const//displays the output if valid
	{
		if (isEmpty() == false)
		{
			cout << passenger_name << " - " << destination << " on " << year << "/";
			cout.width(2);
			cout.fill('0');
			cout << month;
			cout << "/";
			cout.width(2);
			cout.fill('0');
			cout << day << endl;
		}
	}
	const char* Passenger::name()const //if array is not empty reurns the passenger_name
{
		if (passenger_name[0] != '\0')
		{

			return passenger_name;
		}
		else
		{
			return passenger_name;
		}

	}

	bool Passenger::canTravelWith(const Passenger& pass) const// checks for validity of travelling passenger
	{
		if (strcmp(destination, pass.destination) == 0 && year == pass.year && month && pass.month&&day == pass.day) 
		{
			return true;
		}
		else
		{
			return false;
		}

	}


}