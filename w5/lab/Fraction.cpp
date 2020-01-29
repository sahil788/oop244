//Fraction.cpp
//sahil lapsiwala
//15/6/17
//132584160
#include<iostream>
#include"Fraction.h"


using namespace std;
namespace sict
{
	//sets to safe empty state
	Fraction::Fraction()
	{
		num = 0;
		denum = 0;
	}
	// checks for validity
	Fraction::Fraction(int Num, int Denum)
	{
		if (Num > 0 && Denum > 0)
		{
			num = Num;
			denum = Denum;
		}
		else
		{
			num = 0;
			denum = 0;
		}
	}
	// returns max of numerator and denominator
	int Fraction::max() const
	{
		int result;
		if (num > denum)
		{
			result = num;
		}
		else
		{
			result = denum;
		}
		return result;
	}
	// returns min of numerator and denominator
	int Fraction::min() const
	{
		int result;
		if (num < denum)
		{
			result = num;
		}
		else
		{
			result = denum;
		}
		return result;
	}
//calculated greatest common divisor
	int Fraction::gcd() const 
	{
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// reduces the fraction by dividing with gcd
	void Fraction::reduce() 
	{
int v=gcd();
		int reduce_num = num /v;
		num = reduce_num;
		int reduce_denum = denum /v;
		denum = reduce_denum;
	}
	// checks if the num and denum are in safe empty state
	bool Fraction::isEmpty() const
	{
		if (num == 0 && denum == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	// displays the output
	void Fraction::display() const
	{
Fraction t;
t.num=this->num;
t.denum=this->denum;
t.reduce();
		if (isEmpty() == false)
		{
			if (t.denum != 1)
			{
				cout << t.num <<"/"<<t.denum;
			}
			else {
				cout << t.num;
			}
		}
		else{
		cout << "no fraction stored";
	}
	}
	//adds two functions and reduces them
	Fraction Fraction::operator+(const Fraction& rhs)
	{
		Fraction f;
		if (rhs.isEmpty() == false && isEmpty() == false)
		{
			 f.num = (rhs.num*this->denum) + (rhs.denum*this->num);
			 f.denum  = (rhs.denum*this->denum);
			 f.reduce();
			
	    }
		return f;
	}
	

	

}
