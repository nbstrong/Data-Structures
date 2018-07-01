#include <iostream>
#include <string>

#include "BMI.h"

using namespace std;

int main() {

	string name;
	int height;
	double weight;
	cout << "Enter your name: ";
	cin >> name;
	cout << "Enter your height (in inches): ";
	cin >> height;
	cout << "Enter your weight (in lbs): ";
	cin >> weight;

	BMI Student_1(name, height, weight);

	return 0;

}
