/************************
*name:sahil lapsiwala
id:132584160
date:7/12/2017
file:Product.h
***************************/
#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H
#include <iostream>
#include "general.h"
#include "Streamable.h"


namespace sict {
	class Product :public Streamable
	{
	private:
		char sku_[MAX_SKU_LEN + 1];
		char* name_;
		double price_;
		bool taxed_;
		int quantity_;
		int qtyneeded_;
	public:
		Product(); // No argument constructor
		Product(const char* sku, const char* name);
		Product(const char* sku1, const char* name1, double price1, int qty_need, bool tax = true);
		Product(const Product& pro);
		Product& operator=(const Product& pro);
		~Product();   // destructor

					  //SETTERS
		void sku(const char* sku);
		void price(double price);
		void name(const char* name);
		void taxed(bool taxed);
		void quantity(int quantity);
		void qtyNeeded(int qtyneeded);

		//GETTERS
		const char* sku()const;
		double price()const;
		const char* name()const;
		bool taxed()const;
		int quantity()const;
		int qtyNeeded()const;
		bool isEmpty()const;
		double cost()const;

		//OPERATOR OVERLOADS
		bool operator==(const char* pro);
		int operator+=(int pro);
		int operator-=(int pro);
	};

	// operator += 
	double operator+=(double& d, const Product& I);

	// operator << and operator >>
	std::ostream& operator<<(std::ostream& out, const Product& p);
	std::istream& operator >> (std::istream& in, Product& p);

}


#endif
