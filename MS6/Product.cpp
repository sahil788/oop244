/************************
*name:sahil lapsiwala
id:132584160
date:7/12/2017
file:Product.cpp
***************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Product.h"

using namespace std;
namespace sict
{
	//constructors
	Product::Product()
	{

		sku_[0] = '\0';
		name_ = nullptr;
		price_ = 0.0;
		quantity_ = 0;
		qtyneeded_ = 0;

	}
	Product::Product(const char* sku1, const char* name1)
	{
		sku(sku1);
		name(name1);
		price_ = 0.0;
		quantity_ = 0;
		qtyneeded_ = 0;
	}



	Product::Product(const char * sku1, const char * name1, double price1, int qty_need, bool tax)
	{
		if (name_ != nullptr)
		{

			sku(sku1);
			name(name1);
			taxed(tax);
			price(price1);
			quantity(0);
			qtyNeeded(qty_need);
		}
		else
		{
			sku_[0] = '\0';
			name_ = nullptr;
			price_ = 0;
			quantity_ = 0;
			qtyneeded_ = 0;
		}
	}

	Product::Product(const Product& pro) // copy constructor
	{
		sku(pro.sku_);
		name(pro.name_);
		price(pro.price_);
		taxed(pro.taxed_);
		qtyNeeded(pro.qtyneeded_);
		quantity(pro.quantity_);
	}

	Product& Product::operator=(const Product& pro)  //assignment operator =
	{
		if (this != &pro)
		{
			sku(pro.sku_);
			name(pro.name_);
			price(pro.price_);
			taxed(pro.taxed_);
			quantity(pro.quantity_);
			qtyNeeded(pro.qtyneeded_);
		}

		return *this;
	}

	//setters
	void Product::sku(const char* sku)
	{
		strncpy(sku_, sku, MAX_SKU_LEN + 1);
		sku_[MAX_SKU_LEN] = '\0';
	}

	void Product::name(const char* name)
	{
		name_ = new char[strlen(name) + 1];
		strncpy(name_, name, strlen(name) + 1);
	}

	void Product::price(double price)
	{
		price_ = price;
	}

	void Product::taxed(bool taxed)
	{
		taxed_ = taxed;
	}

	void Product::quantity(int quantity)
	{
		quantity_ = quantity;
	}
	void Product::qtyNeeded(const int qty_need)
	{
		qtyneeded_ = qty_need;
	}
	//getters
	const char* Product::sku()const
	{
		return sku_;
	}
	double Product::price()const
	{
		return price_;
	}
	const char* Product::name()const
	{
		return name_;
	}
	bool Product::taxed()const
	{
		return taxed_;
	}
	int Product::quantity()const
	{
		return quantity_;
	}
	int Product::qtyNeeded()const
	{
		return qtyneeded_;
	}
	Product::~Product()
	{
		delete name_;
		name_ = nullptr;
	}

	bool Product::isEmpty()const
	{
		if (name_ == nullptr && price_ == 0.0 && quantity_ == 0 && qtyneeded_ == 0 && taxed_ == false)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	double Product::cost() const
	{
		double total;
		if (taxed_ == true)
		{
			total = price_*(TAX + 1);
		}
		else
		{
			total = price_;
		}
		return total;
	}

	bool Product::operator==(const char* k)
	{
		if (strcmp(k, sku_) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int Product:: operator+=(int pro)
	{
		return quantity_ += pro;
	}

	int Product:: operator-=(int pro)
	{
		return quantity_ -= pro;
	}

	double operator+=(double& d, const Product& i)
	{
		double total_price = i.quantity()*i.cost();
		d = (d)+total_price;
		return d;
	}

	std::istream& operator >> (std::istream& in, Product& p)
	{
		p.read(in);
		return in;

	}

	std::ostream & operator<<(std::ostream & out, const Product & p)
	{

		bool linear = true;
		p.write(out, linear);
		return out;
	}
}

