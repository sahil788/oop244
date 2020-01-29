//contains all function declarations and class
//passenger.h
//sahil lapsiwala
//12/6/17
#ifndef SICT__Passenger_H
#define SICT__Passenger_H
#define MAX_SIZE 32
namespace sict {

	class Passenger
	{
		char passenger_name[MAX_SIZE];
		char destination[MAX_SIZE];
		int year;
		int month;
		int day;

	public:
		Passenger();
		Passenger(const char *PassengerName, const char *Destination);
		bool isEmpty() const;
		void display() const;
		Passenger(const char *PassengerName, const char *Destination, const int m_year, const int m_month, const int m_day);
		const char* name()const;
		bool canTravelWith(const Passenger&) const;


	};
}


#endif 