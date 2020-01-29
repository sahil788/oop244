
// Final Project Milestone 2
/************************
*name:sahil lapsiwala
id:132584160
date:7/8/2017
file:ErrorMessage.h
***************************/
#ifndef SICT_ERRORMESSAGE_H
#define SICT_ERRORMESSAGE_H
namespace sict {

	class ErrorMessage
	{
		char* message_;
	public:
		ErrorMessage();
		ErrorMessage(const char* errorMessage);
		ErrorMessage(const ErrorMessage& em) = delete;
		ErrorMessage& operator=(const ErrorMessage& em) = delete;
		ErrorMessage& operator=(const char* errorMessage);
		virtual ~ErrorMessage();
		void clear();
		bool isClear()const;
		void message(const char* value);
		const char* message()const;
		std::ostream& write(std::ostream& wr)const;

	};

	std::ostream& operator<<(std::ostream& os, const ErrorMessage& s);
}
#endif // !SICT_ERRORMESSAGE_H