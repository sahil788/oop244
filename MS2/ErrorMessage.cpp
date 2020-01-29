
// Final Project Milestone 2
/************************
*name:sahil lapsiwala
id:132584160
date:7/8/2017
file:ErrorMessage.cpp
***************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include "ErrorMessage.h"
namespace sict
{
	ErrorMessage::ErrorMessage()// constructor sets the object to nullptr
	{
	message_ = nullptr;
	}
	ErrorMessage::ErrorMessage(const char* errorMessage)// passes error/message to message function
	{
		message_ = nullptr;
                message(errorMessage);		
	}
	ErrorMessage& ErrorMessage::operator=(const char* errorMessage)//copy assignment operator
	{
		clear();
		message(errorMessage);
		return *this;
	}

	void ErrorMessage::clear()
	{
		delete[] message_;
		message_ = nullptr;
	}
	bool ErrorMessage::isClear()const//returns true if message =nullptr
	{
		if (message_ == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void ErrorMessage::message(const char* value)//deaalocates and allocates new dynamic memory and copy the argument to string
	{
		delete[] message_;
		message_ = new char[strlen(value) + 1];
		strcpy(message_, value);
        }
	const char* ErrorMessage::message()const
	{
		return message_;
	}
	ErrorMessage::~ErrorMessage() 
	{
		delete[] message_;
	}
	std::ostream& ErrorMessage::write(std::ostream& wr)const
	{
		if (isClear()==false)
		{
			wr << message_;
		}
		return wr;
	}
	std::ostream& operator<<(std::ostream& os, const ErrorMessage& s)// overloaded <<operator
	{
		s.write(os);
		return os;
	}
}