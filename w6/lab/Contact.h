/************************
*name:sahil lapsiwala
 id:132584160
 date:23/6/2017
 file:Contact.h
***************************/

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H
#define SIZE 20

namespace sict
{
  class Contact
	{
         char names[SIZE];
         long long* phone_number;
	 int number;
    public:
	 Contact();
        ~Contact();
	 Contact(const char* name, long long* phone, int no);
         bool isEmpty() const;
         void display() const;
	};
}

#endif