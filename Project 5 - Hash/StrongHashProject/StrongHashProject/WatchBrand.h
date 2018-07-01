#ifndef WatchBrands_H
#define WatchBrands_H

#include <iostream>		// Used for input and output.
#include <fstream>		// Used for file input and output.
using namespace std;

class Brand {
	char name[80];
	int key;

	friend ostream &operator << (ostream& out, const Brand& theBrand) {
		out << "Name: " << theBrand.name << " Key: " << theBrand.key ;
		return out;
	}

public:
	// Default constructor for temporary or initial objects
	Brand() {
		setName("");
		setKey(0);
	}
	// Constructor for adding objects manually
	Brand(char *theName) {
		setName(theName);
		createKey();
	}
	// Constructor for DELETED and EMPTY object
	Brand(char *theName, int theKey) {
		setName(theName);
		setKey(theKey);
	}
	// C++ doesn't care what is a string or a char array apparently
	string getName() const {
		return name;
	}
	int getKey() const {
		return key;
	}
	void setName(char *theName) {
		strcpy_s(name, theName);
	}
	void setKey(int theKey) {
		key = theKey;
	}
	// Essentially same as hashIt main function except this
	// creates it for an object. Probably redundant but
	// works fine. Sums ASCII values of char[]/string.
	void createKey() {
		int sum = 0;
		for (unsigned int i = 0; i < getName().size(); i++) {
			sum += getName()[i];
		}
		key = sum;
	}
};
#endif