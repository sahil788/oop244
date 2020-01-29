/************************
*name:sahil lapsiwala
id:132584160
date:7/7/2017
file:Date.h
***************************/
#ifndef SICT_DATE_H__
#define SICT_DATE_H__
#define NO_ERROR   0  //--No error the date is valid
#define CIN_FAILED 1  //--istream failed when entering information
#define YEAR_ERROR 2 // --Year value is invalid
#define MON_ERROR  3 // --Month value is invalid
#define DAY_ERROR  4 // --Day value is invalid
namespace sict
{

	class Date {
	private:
		int year_, mon_, day_, readErrorCode_;
		void errCode(int errorCode);
		int value()const;

	public:
		Date();
		Date(int yr, int mon, int day);
		bool operator==(const Date& D)const;
		bool operator!=(const Date& D)const;
		bool operator<(const Date& D)const;
		bool operator>(const Date& D)const;
		bool operator<=(const Date& D)const;
		bool operator>=(const Date& D)const;
		int errCode()const;
		bool bad()const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		int mdays()const;
	};

	std::ostream& operator<<(std::ostream& os, const Date& s);
	std::istream& operator >> (std::istream& is, Date& s);


}
#endif
