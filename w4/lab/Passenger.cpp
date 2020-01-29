//includes all function definitions

// passenger.cpp
// 8/6/2017
// sahil lapsiwala

#include<iostream>
#include<cstring>
#include"Passenger.h"
using namespace std;
using namespace sict;


namespace sict 
{
	Passenger::Passenger()// default constructor sets to safe empty state
	{
		passengers_name[0] = '\0';
		destination[0] = '\0';
	}
	
	Passenger::Passenger( const char *passengerName, const char *Destination)// checks for validity of string and if valid copies it to objects
	{
		if ((passengerName != nullptr)&&(Destination != nullptr))
		{
			strncpy(passengers_name, passengerName,MAX_SIZE);
			passengers_name[31] = '\0';
			strncpy(destination, Destination, MAX_SIZE);
			destination[31] = '\0';
		}
		else
		{
			passengers_name[0] =  '\0' ;
			destination[0] =  '\0' ;
		}
	}
	bool Passenger::isEmpty() const// returns the validity of safe empty state
	{
		bool valid;
		if ((passengers_name[0] =='\0')||(destination[0]=='\0'))
		{
			valid= true;
		}
		else
		{
			valid=false;
		}
		return valid;
	}
	void Passenger::display() const// displays the data
	{
		if (isEmpty() == false)
		{
			cout << passengers_name << " - " << destination << endl;
		}
	}
}
   
