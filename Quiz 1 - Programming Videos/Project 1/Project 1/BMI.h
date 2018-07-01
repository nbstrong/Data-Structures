// Header File - Function Declarations

#include <iostream>
#include <string>

using namespace std;

#ifndef BMI_h
#define BMI_h

class BMI {
public:
	// Default Constructor
	BMI();

	// Overload Constructor
	BMI(string, int, double);

private:
	// Member variables
	string newName;
	int newHeight;
	double newWeight;

};

#endif