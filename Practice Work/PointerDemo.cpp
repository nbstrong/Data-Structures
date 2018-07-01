/*
The purpose of this program is to demonstrate the use of pointers. 
*/

#include <iostream>		// Used for input and output.
#include <string>
#include <conio.h>		// Used for getch().

using namespace std;

struct Car				// Data of the Car struct are public by default here.
{						// If this were a class, the default access type would be private. 
	string make;
	string model;
	int year;
	double mileage;
};

// Forward function declarations.
void pressAnyKey();

int main()
{
	// Demo 1.
	int int1, int2;				// Declare two ints.
	int *pointer1, *pointer2;	// Declare two int pointers.
	pointer1 = &int1;			// The value of pointer1 is the address of int1.
	*pointer1 = 100;			// This sets the value of int1 to 100.

	cout << "Demo 1:" << endl;
	cout << "int1 = " << int1 << endl;
	cout << "pointer1 = " << pointer1 << " - which is the address of int1 in memory" << endl;
	cout << "*pointer1= " << *pointer1 << " - which is the value of int1" << endl << endl;
	pressAnyKey();

	// Demo 2.
	pointer1 = &int2;			// Now pointer1 has the value of the address of int2.
	*pointer1 = 200;			// Now int2 has the value of 200.

	cout << "Demo 2:" << endl;
	cout << "int1 = " << int1 << "- int1 did not change" << endl;
	cout << "int2 = " << int2 << " - int2 received the value given to *pointer1" << endl;
	cout << "pointer1 = " << pointer1 << " - which is the address of int2 in memory" << endl;
	cout << "*pointer1 = " << *pointer1 << " - which is the value of int2" << endl;
	cout << "&int1 = " << &int1 << endl;
	cout << "&int2 = " << &int2 << endl << endl;
	pressAnyKey();

	// Demo 3.
	pointer2 = pointer1;		// The value (address) of pointer1 is now also the value of pointer2.
								// pointer2 now points to int2.
	pointer1 = &int1;			// The value of pointer1 is now the address of int1. pointer1 points to int1.
	*pointer2 = *pointer1 * int1;	// int2 should now be equal to the square of int1.
	
	cout << "Demo 3:" << endl;
	cout << "int1 = " << int1 << endl;
	cout << "int2 = " << int2 << endl;
	cout << "pointer1 = " << pointer1 << endl;
	cout << "*pointer1 = " << *pointer1 << endl;
	cout << "pointer2 = " << pointer1 << endl;
	cout << "*pointer2 = " << *pointer1 << endl;
	cout << "&int1 = " << &int1 << endl;
	cout << "&int2 = " << &int2 << endl << endl;
	pressAnyKey();

	// Demo 4:
	int int3;
	*pointer1 = *pointer2;		// The value of pointer2 is now the value (address) of pointer1.
								// Meaning that int1 and int2 now equal 10,000.
	pointer1 = new int(42);
	cout << "Demo 4:" << endl;
	cout << "int1 = " << int1 << endl;
	cout << "int2 = " << int2 << endl;	
	cout << "pointer1 = " << pointer1 << endl;
	cout << "*pointer1 = " << *pointer1 << endl;
	cout << "pointer2 = " << pointer1 << endl;
	cout << "*pointer2 = " << *pointer1 << endl;
	cout << "&int1 = " << &int1 << endl;
	cout << "&int2 = " << &int2 << endl;
	cout << "&int3 = " << &int3 << endl;
	cout << "*&int1 = " << *&int1 << endl;
	cout << "*&int2 = " << *&int2 << endl << endl;
	pressAnyKey();
	
	// Demo 5:	
	delete pointer1;									// Remove garbage (the 42) from heap. Do before next line.
	pointer1 = &int3;
	cout << "Demo 5:" << endl;
	cout << "*pointer1: " << *pointer1 << endl;			// Random data.
	cout << "*&int3 = " << *&int3 << endl << endl;		// The same random data.
	pressAnyKey();

	// Demo 6:
	Car car1 = { "Buick", "Century", 1995, 15678.3 };
	Car *carPointer1 = &car1;
	cout << "The make of car1 is " << car1.make << endl;
	// The member access operator for regular variables is . while -> is the member access operator for pointers.
	cout << "The make of car1 (via carPointer1) is " << carPointer1->make << endl;		// Short form of next line.
	cout << "The make of car1 (via carPointer1) is " << (*carPointer1).make << endl;	// Equivalent to preceding line.
	cout << "Juan is driving the " << car1.make << endl;
	pressAnyKey();

	return 0;	// End program.
}

// Press any key to continue.
void pressAnyKey()
{
	cout << "Press any key to continue" << endl << endl;
	_getch();					// Waits and gets next character entered.		
}

