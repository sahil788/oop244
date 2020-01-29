/************************
*name:sahil lapsiwala
id:132584160
date:4/8/2017
file:validate.h
email:snlapsiwala@myseneca.ca
***************************/

#ifndef ICT_VALIDATE_H
#define ICT_VALIDATE_H
namespace ict
{
	template<typename T>
	bool validate(const T& min, const T& max, const T* TestValue, int no_element, bool* results)
	{
		int i;
		bool valid= true;
		for (i = 0; i < no_element; i++)
		{
			if (TestValue[i] >= min && TestValue[i] <= max)
			{
				results[i] = true;
				
			}
			else
			{
				results[i] = false;
				valid = false;
			}
		}
		return valid;
	}
}
#endif // !

