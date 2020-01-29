/************************
*name:sahil lapsiwala
id:132584160
date:7/12/2017
file:Streamable.h
***************************/

#ifndef SICT_STREAMABLE_H
#define SICT_STREAMABLE_H
#include <iostream>
#include <fstream>

namespace sict 
{

	class Streamable 
	{
		//virtual functions prototypes
	public:
		virtual std::fstream& store(std::fstream& file, bool addNewLine = true)const=0;
	       	virtual std::fstream& load(std::fstream& file)=0;
		virtual std::ostream& write(std::ostream& os, bool linear)const=0;
		virtual std::istream& read(std::istream& is)=0;
	};
}
#endif
