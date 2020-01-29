//Fraction.h
//sahil lapsiwala
//15/6/17
//132584160
//contains function declaration and class definition

#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

namespace sict
{


	
	// TODO: define the Fraction class
	class Fraction 
	{
		int num;
		int denum;
		int gcd() const; // returns the greatest common divisor of num and denom
		int max() const; // returns the maximum of num and denom
		int min() const; // returns the minimum of num and denom
		void reduce();   // simplifies a Fraction by dividing the 
						 // numerator and denominator to their greatest common divisor 
         public:
			 Fraction();
			 Fraction(int Num, int Denum);
			 bool isEmpty() const;
			 void display() const;
			 Fraction operator+(const Fraction& rhs);
    };

	
}
#endif