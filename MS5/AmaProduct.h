/************************
*name:sahil lapsiwala
id:132584160
date:7/26/2017
file:AmaProduct.h
email: snlapsiwala@myseneca.ca
***************************/
// AmaProduct.h
#ifndef SICT_AMAPRODUCT_H
#define SICT_AMAPRODUCT_H
#include"Product.h"
#include"ErrorMessage.h"
#include"Streamable.h"
#include<iostream>
namespace sict {
    class AmaProduct : public Product {
        char fileTag_;
        char unit_[11];
    protected:
        ErrorMessage err_;
    public:
        AmaProduct(char value='N');
        const char* unit()const;
        void unit(const char* value);
       std::fstream& store(std::fstream& file, bool addNewLine = true)const;
	   std::fstream& load(std::fstream& file);
	   std::ostream& write(std::ostream& os, bool linear)const;
	   std::istream& read(std::istream& is);

    };
}

#endif 