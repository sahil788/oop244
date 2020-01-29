/************************
*name:sahil lapsiwala
id:132584160
date:8/6/2017
file:AidApp.h
email: snlapsiwala@myseneca.ca
***************************/

#ifndef SICT_AIDAPP_H
#define SICT_AIDAPP_H
#include "Product.h"
#include <fstream>
namespace sict
{
	class AidApp
	{
		char filename_[256];
		Product* product_[MAX_NO_RECS];
		std::fstream datafile_;
		int noOfProducts_;

		void pause() const;
		int menu();
		void loadRecs();
		void saveRecs();
		void listProducts() const;
		int SearchProducts(const char* sku) const;
		void addQty(const char* sku);
		void addProduct(bool isPerishable);
		
		

	public:
		int run();
                AidApp(const AidApp&) = delete;
		AidApp& operator=(const AidApp&) = delete;
		AidApp(const char* filename);
		
	};
}

#endif // !SICT_AIDAPP_H

