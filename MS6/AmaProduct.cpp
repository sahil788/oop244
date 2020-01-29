/************************
*name:sahil lapsiwala
id:132584160
date:7/26/2017
file:AmaProduct.cpp
email: snlapsiwala@myseneca.ca
***************************/
// AmaProduct.cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include <fstream>
#include <cstring>
#include"AmaProduct.h"
#include"general.h"
#include "Product.h"
namespace sict 
{

	//constructor
	AmaProduct::AmaProduct(char value)
	{
		fileTag_ = value;
	}
	//unit getter
	const char* AmaProduct::unit()const 
	{
		return  unit_;
	}
	// copying unit from value
	void AmaProduct::unit(const char* value) {
		strncpy(unit_, value, 11);
		unit_[10] = '\0';
	}
	//store the value to file
	std::fstream& AmaProduct::store(std::fstream& file, bool addNewLine)const {

		if (addNewLine == true) {
			file << fileTag_ << "," << sku() << "," << name() << "," << price() << "," << taxed() << "," << quantity() << "," << unit() << "," << qtyNeeded() <<std::endl;
		}
		else
			file << fileTag_ << "," << sku() << "," << name() << "," << price() << "," << taxed() << "," << quantity() << "," << unit() << "," << qtyNeeded();
      
		return file;
	}
	//load the value from the file
	std::fstream& AmaProduct::load(std::fstream& file)
	{
		char temp_sku[MAX_SKU_LEN];
		char temp_name[600];
		double temp_price=0.0;
		int temp_tax=0;
		int temp_quantity=0;
		char temp_unit[11];
		int temp_quantityneeded=0;

		file.getline(temp_sku, MAX_SKU_LEN, ',');
		file.getline(temp_name, 600, ',');
        
		file >> temp_price;
		file.ignore();

		file >> temp_tax;
		file.ignore();

		file >> temp_quantity;
		file.ignore();

		file.getline(temp_unit, 12, ',');

		file >> temp_quantityneeded;
		file.ignore();

		sku(temp_sku);
		name(temp_name);
		price(temp_price);
		taxed(temp_tax);
		price(temp_price);
		unit(temp_unit);
		quantity(temp_quantity);
		qtyNeeded(temp_quantityneeded);
		
		return file;
   }
	//displays the value to the screen
	std::ostream& AmaProduct::write(std::ostream& os, bool linear)const 
	{
		if (err_.isClear() == false)
		{
			os << err_;
		}
		else
		{
		 if (linear==true)
		 {
			os << std::left <<std::setw(MAX_SKU_LEN) << std::setfill(' ') << sku() << "|"<< std::left << std::setw(20) << std::setfill(' ') << name() << "|"<< std::right << std::setw(7) << std::fixed << std::setprecision(2) << cost() << "|"
				<< std::right << std::setw(4) << quantity() << "|"<< std::left << std::setw(10) << unit() << "|"<< std::right << std::setw(4) << qtyNeeded() << "|";
         }
		else {
			os << "Sku: " << sku() << std::endl;
			os << "Name: " << name() << std::endl;
			os << "Price: " << price() << std::endl;
			if (taxed()==true)
			{
				os << "Price after tax: " << std::fixed << std::setprecision(2) << cost() << std::endl;
			}
			else
			{
				os << "Price after tax: " << "N/A" << std::endl;
			}
			os << "Quantity On Hand: " << quantity()<<" " <<unit() << std::endl;
			os << "Quantity Needed: " << qtyNeeded();
		}

		}
		return os;
	}
	//reads the value user enters
	// this is in comments.txt 
	std::istream& AmaProduct::read(std::istream& istr) 
	{
		char temp_sku[MAX_SKU_LEN];
		char temp_name[20];
		char temp_unit[11];
		char temp_tax;
		double temp_price;
		int temp_quantity;
		int temp_quantityNeeded;

		err_.clear();

		if (istr.fail() == false) 
			{
			std::cout << "Sku: ";
			istr.getline(temp_sku, MAX_SKU_LEN, '\n');

			if (istr.fail() == false) 
			{
				sku(temp_sku);
			}

			std::cout << "Name: ";
			istr.getline(temp_name, 20, '\n');
			if (istr.fail() == false) 
			{
				name(temp_name);
			}

			std::cout << "Unit: ";
			istr.getline(temp_unit, 11, '\n');
			if (istr.fail() == false)
			 {
				unit(temp_unit);
			}

			std::cout << "Taxed? (y/n): ";

			istr >> temp_tax;

			if ((temp_tax == 'Y' || temp_tax == 'y') || (temp_tax == 'N' || temp_tax == 'n'))
			{
				if (temp_tax == 'Y' || temp_tax == 'y')
				{
					taxed(true);
                                        istr.clear();
				}
				else  
				{
					taxed(false);
					istr.clear();
				}
			}
			else
			{
				err_.message("Only (Y)es or (N)o are acceptable");
				istr.setstate(std::ios::failbit);
			}
			
			if (err_.isClear())
			 {
				std::cout << "Price: ";
				istr >> temp_price;
				if (istr.fail()) 
				{
					err_.message("Invalid Price Entry");
				}
				else 
				{
					price(temp_price);
				}
			}
			if (err_.isClear())
			{
				std::cout << "Quantity On hand: ";
				istr >> temp_quantity;
				if (istr.fail()) 
				{
					err_.message("Invalid Quantity Entry");
				}
				else
				 {
					quantity(temp_quantity);
				}

			}
			if (err_.isClear()) 
			{
				std::cout << "Quantity Needed: ";
				istr >> temp_quantityNeeded;
				if (istr.fail())
				 {
					err_.message("Invalid Quantity Needed Entry");
				}
				else 
				{
					qtyNeeded(temp_quantityNeeded);
				}
			}

		}
		return istr;

	}
}