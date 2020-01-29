// display the kingdoms and total population
// w2_at_home.cpp
// 30/5/2017
// Sahil lapsiwala


#include <iostream>
#include "Kingdom.h"

using namespace std;
using namespace sict;

void read(Kingdom&);

int main() {
    int count = 0; // the number of kingdoms in the array
	Kingdom *pKingdom = { 0 };
    // TODO: declare the pKingdom pointer here (don't forget to initialize it)

    cout << "==========\n"
        << "Input data\n"
        << "==========\n"
        << "Enter the number of kingdoms: ";
    cin >> count;
    cin.ignore();

    if (count < 1) return 1;
	pKingdom = new Kingdom[count];
    // TODO: allocate dynamic memory here for the pKingdom pointer

    for (int i = 0; i < count; ++i) {
        cout << "Kingdom #" << i + 1 << ": " << endl;
        // TODO: add code to accept user input for Kingdom i
		read(pKingdom[i]);

    }
    cout << "==========" << endl << endl;

    // testing that "display(...)" works
    cout << "------------------------------" << endl
        << "The first kingdom entered is" << endl
        << "------------------------------" << endl;
    display(pKingdom[0]);
    cout << "------------------------------" << endl << endl;

    // expand the array of Kingdoms by 1 element
	Kingdom* newpKingdom = new Kingdom[count + 1];
    // TODO: allocate dynamic memory for count + 1 Kingdoms
    // TODO: copy elements from original array into this newly allocated array
	int j;
	for (j = 0; j < count; j++)
	{
		newpKingdom[j] = pKingdom[j];

	}
    // TODO: deallocate the dynamic memory for the original array
	delete[] pKingdom;

    // TODO: copy the address of the newly allocated array into pKingdom pointer
	pKingdom = newpKingdom;
    // add the new Kingdom
    cout << "==========\n"
        << "Input data\n"
        << "==========\n"
        << "Kingdom #" << count + 1 << ": " << endl;
    // TODO: accept input for the new element in the array
	read(pKingdom[count]);
    count++;
    cout << "==========\n" << endl;

    // testing that the overload of "display(...)" works
    display(pKingdom, count);
    cout << endl;
	delete[]pKingdom;
    // TODO: deallocate the dynamic memory here

    return 0;
}

// read accepts data for a Kingdom from standard input
//
void read(Kingdom& kingdom) {

    cout << "Enter the name of the kingdom: ";
    cin.get(kingdom.m_name, 32, '\n');
    cin.ignore(2000, '\n');
    cout << "Enter the number people living in " << kingdom.m_name << ": ";
    cin >> kingdom.m_population;
    cin.ignore(2000, '\n');
}