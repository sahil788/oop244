// definitoins for functions
// kingdom.cpp
// 30/5/2017
// Sahil lapsiwala


// TODO: include the necessary headers
#include<iostream>
#include"Kingdom.h"
using namespace std;
// TODO: the sict namespace
namespace sict {
	// TODO:definition for display(...) 
	//displays the kingdom name and population
	void display(const Kingdom& king)
	{
		cout << king.m_name << ", population " << king.m_population << endl;
	}


	// dispays the name of kingdom and total population of kingdoms
	void display(const Kingdom* king, int size)
	{
		int i;
		int population = 0;
		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;
		for (i = 0; i < size; i++)
		{
			cout << i + 1 <<". ";
			display(king[i]);
			population += king[i].m_population;
		}
		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << population << endl;
                cout << "------------------------------" << endl;
	}
}