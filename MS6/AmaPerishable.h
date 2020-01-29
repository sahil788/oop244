/************************
*name:sahil lapsiwala
id:132584160
date:7/26/2017
file:AmaPerishable.h
email: snlapsiwala@myseneca.ca
***************************/
// AmaPerishable.h
#ifndef SICT_AMAPERISHABLE_H
#define SICT_AMAPERISHABLE_H
#include"AmaProduct.h"
#include"Date.h"


namespace sict {
	class AmaPerishable :public AmaProduct {
		Date expiry_;
	public:
		AmaPerishable();
		const Date& expiry()const;//getter
		void expiry(const Date &value);//accesssor
		std::fstream& store(std::fstream &, bool addNewLine = true)const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& ostr, bool linear)const;
		std::istream& read(std::istream& istr);
	};
}
#endif