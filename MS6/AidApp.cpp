/************************
*name:sahil lapsiwala
id:132584160
date:8/6/2017
file:AidApp.cpp
email: snlapsiwala@myseneca.ca
***************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "AidApp.h"
#include "AmaPerishable.h"
#include "Product.h"
using namespace std;
namespace sict
{
	AidApp::AidApp(const char* filename)// constructor sets all the objects to safe empty state
	{
		strncpy(filename_, filename, 256);
		filename_[255] = '\0';
		for (int i = 0; i < MAX_NO_RECS; i++)
		{
			product_[i] = nullptr;
		}
		noOfProducts_ = 0;
		loadRecs();
	}

	void AidApp::pause()const// pauses the execution untill user press enter
	{
		cout << "Press Enter to continue..." << endl;
		while (getchar() != '\n')
			;

	}

	int AidApp::menu()// displays the menu
	{
		int option;
		
		cout << "Disaster Aid Supply Management Program" << endl;
		cout << "1- List products" << endl;
		cout << "2- Display product" << endl;
		cout << "3- Add non-perishable product" << endl;
		cout << "4- Add perishable product" << endl;
		cout << "5- Add to quantity of purchased products" << endl;
		cout << "0- Exit program" << endl;
		cout << "> ";
		cin >> option;
		cin.ignore(1000, '\n');
		if (option >= 0 || option <= 5)
		{
			return option;
		}
		else
		{
			return -1;
		}
	}

	void AidApp::loadRecs()// writes the records in the file
	{
		int readIndex = 0;
		char read;

		datafile_.open(filename_, std::ios::in);

		if (datafile_.fail())
		{
			datafile_.clear();
			datafile_.close();
			datafile_.open(filename_, std::ios::out);
			datafile_.close();
		}
		else
		{
			while (!datafile_.fail())
			{
				delete[] product_[readIndex];
				product_[readIndex] = nullptr;
				datafile_ >> read;
				if (datafile_.good())
				{
					if (read == 'P')
					{
						product_[readIndex] = new AmaPerishable();
					}
					else if (read == 'N')
					{
						product_[readIndex] = new AmaProduct();
					}
					if (read == 'P' || read == 'N')
					{
						datafile_.ignore();
						product_[readIndex]->load(datafile_);
						readIndex++;
					}
				}
			}
		}
		noOfProducts_ = readIndex;
		datafile_.close();
	}
	void AidApp::saveRecs()// save the records in the file
	{
		datafile_.open(filename_, std::ios::out);

		for (int i = 0; i < noOfProducts_; i++)
		{
			product_[i]->store(datafile_);
		}
		datafile_.close();

	}
	void AidApp::listProducts()const // displays the list and calculates total with each loop
	{
		double total = 0;
		cout << endl;
		cout << " Row | SKU    | Product Name       | Cost  | QTY| Unit     |Need| Expiry   " << endl;
		cout << "-----|--------|--------------------|-------|----|----------|----|----------" << endl;

		for (int i = 0; i < noOfProducts_; i++)
		{
			cout << setfill(' ') << setw(4) << right << i + 1 << " | ";
			product_[i]->write(cout, true);
			cout << endl;
			//took help for the calculation of total that is formula
			total += *product_[i];
			if (i == 10)
			{
				pause();
			}


		}
		cout << "---------------------------------------------------------------------------" << endl;
		cout << "Total cost of support: $" << setprecision(2)  << total;
	}
	int AidApp::SearchProducts(const char* sku)const// searches the products inside the array 
	{
		int no = -1;
		for (int i = 0; i < noOfProducts_; i++)
		{
			if (*product_[i] == sku)
			{
				no = i;
			}
		}
		return no;
	}


	void AidApp::addQty(const char* sku)// adds quantity to the product matching with the sku
	{
		int found = SearchProducts(sku);
		int quantity;
		if (found == -1)
		{
			cout << "Not found!" << endl;
		}
		else
		{
			cout << "Please enter the number of purchased items: ";
			cin >> quantity;
			if (cin.fail())
			{
				cout << "Invalid quantity value!" << endl;
			}
			else
			{
				int qtyNeeded = product_[found]->qtyNeeded();
				int qty = product_[found]->quantity();
				int required = (qtyNeeded - qty);

				if (quantity <= required)
				{
					product_[found]->operator+=(quantity);
					cin.ignore(1000, '\n');

				}
				else
				{
					cout << "Too many items; only " << required << " is needed, please return the extra " << quantity - required << " items." << endl;
				}
				cout << endl << "Updated!" << endl << endl;
			}
		}cin.clear();


	}

	void AidApp::addProduct(bool isPerishable)// add product to the list
	{
		if (isPerishable== true)
		{
			product_[noOfProducts_] = new AmaPerishable();
			product_[noOfProducts_]->read(cin);
			noOfProducts_++;
		}
		else
		{
			product_[noOfProducts_] = new AmaProduct();
			product_[noOfProducts_]->read(cin);
			noOfProducts_++;
		}
		saveRecs();
		cout << endl << "Product added" << endl << endl;
	}

	int AidApp::run()// execute the menu ui
	{
		char sku[MAX_SKU_LEN];
		int option;
		int found;
		while ((option = menu()) != 0) {
			switch (option)
			{
			case 1:
				listProducts();
				cout << endl;
				cout << endl;
				pause();
				break;

			case 2:
				cout << endl << "Please enter the SKU: ";
				cin >> sku;
				cout << endl;
				found = SearchProducts(sku);
				if (found != -1)
				{
					product_[found]->write(cout, false);
				}
				else
				{
					cout << "Not found!" << endl;
				}
				cout << endl;
				cout << endl;
				pause();
				cout << endl;
				break;

			case 3:
				cout << endl;
				addProduct(false);
				break;

			case 4:
				cout << endl;
				addProduct(true);
				break;

			case 5:
				cout << endl;
				cout << "Please enter the SKU: ";
				cin >> sku;
				cout << endl;
				found = SearchProducts(sku);
				if (found != -1)
				{
					product_[found]->write(cout, false);
				}
				else
				{
					cout << "Not found!" << endl;
				}
				cout << endl;
				cout << endl;
				addQty(sku);
				break;
				;

			default:
				cout << "===Invalid Selection, try again.==="<<endl;;
				pause();
				break;
			}
		}cout << endl << "Goodbye!!" << endl;

		return 0;
	}
}