/************************
*name:sahil lapsiwala
id:132584160
date:7/26/2017
file:AmaPerishable.cpp
email: snlapsiwala@myseneca.ca
***************************/
// AmaPersishable.cpp
#include<iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include"AmaPerishable.h"
namespace sict {
	//constructor
	AmaPerishable::AmaPerishable() :AmaProduct('P') {}
	//returns the expiry date
	const Date& AmaPerishable::expiry()const
	{
		return  expiry_;
	}
	//sets the expiry date
	void AmaPerishable::expiry(const Date &value) 
	{
		expiry_ = value;
	}
	std::fstream& AmaPerishable::store(std::fstream& file, bool addNewLine)const 
	{

		AmaProduct::store(file, false);

		if (addNewLine == true) {
			file << ",";
			expiry().write(file) << std::endl;
		}
		else {
			file << ",";
			expiry().write(file);
		}


		return file;
	}
	std::fstream& AmaPerishable::load(std::fstream& file) 
	{
		Date obj;
		AmaProduct::load(file);
		file >> obj;
		file.ignore();
		expiry(obj);
		return file;
	}
	std::ostream& AmaPerishable::write(std::ostream& ostr, bool linear)const 
	{
		AmaProduct::write(ostr, linear);
		if (err_.isClear()==true) 
		{
			if (linear==true) 
			{
				expiry().write(ostr);
			}
			else
			{
				ostr << std::endl << "Expiry date: ";
				expiry().write(ostr);
			}
		}
		return ostr;


	}
	std::istream& AmaPerishable::read(std::istream& istr) 
	{
		Date obj;
		AmaProduct::read(istr);
		if (err_.isClear() == true)
		{
			std::cout << "Expiry date (YYYY/MM/DD): ";
			istr >> obj;
			if (obj.bad()==true) 
			{
				if (obj.errCode() == CIN_FAILED) 
				{
					err_.message("Invalid Date Entry");
					istr.setstate(std::ios::failbit);
				}
				else if (obj.errCode() == YEAR_ERROR) 
				{
					err_.message("Invalid Year in Date Entry");
					istr.setstate(std::ios::failbit);
				}
				else if (obj.errCode() == MON_ERROR) 
				{
					err_.message("Invalid Month in Date Entry");
					istr.setstate(std::ios::failbit);
				}
				else if (obj.errCode() == DAY_ERROR) 
				{
					err_.message("Invalid Day in Date Entry");
					istr.setstate(std::ios::failbit);
				}
			}
			else expiry(obj);

		}
		return istr;
	}
}
