//includes all declarations

// passenger.cpp
// 8/6/2017
// sahil lapsiwala

#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
#define MAX_SIZE 32
namespace sict
{
	class Passenger
	{
		char passengers_name[MAX_SIZE];
		char destination[MAX_SIZE];
	public:
		Passenger();
		Passenger( const char *passengerName, const char *Destination);
		bool isEmpty() const;
		void display() const;
	};
}

#endif 

