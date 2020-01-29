/***************************
file_name:CRA_Account.h
author: sahil lapsiwala
id:132584160
*/


#ifndef SICT_CRA_Account_H
#define SICT_CRA_Account_H
#define MAX_NAME_LENGTH 40
#define MIN_SIN 100000000
#define MAX_SIN 999999999
namespace sict
{
	class CRA_Account
	{
		char family_name[MAX_NAME_LENGTH +1];
		char given_name[MAX_NAME_LENGTH + 1];
		int Sin;
	public:
		void set(const char* familyName, const char* givenName, int sin);
		void display();
		bool isValid();
	};
}
#endif // !

