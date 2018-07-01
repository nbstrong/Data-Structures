// This is the main class declaration header file

#include <iostream> // Used for input/output
#include <string>

using namespace std;

// Preprocessing directives that prevents multiple definitions.
#ifndef PLanguage_H
#define PLanguage_H

// Class definition for PLanguage class

class PLanguage
{
	// Class declarations.

	// Declare friends (access to private data and operations)
	friend ostream &operator << (ostream& out, const PLanguage& theLanguage);

	// Member functions (often public).
public:				// Access modifier = available to other programs.
	
	// Default constructor.
	PLanguage();	// Declared but not defined - needs semi-colon.
	
	// Other constructors.
	PLanguage(string theName, string theLevel, string theAuthor, int theStartYear);

	// Get and set methods or member functions.
	// Sometimes also called accessor and mutator functions.
	string getName() const;
	string getLevel() const; // Low level or high level?
	string getAuthor() const; // Who created it?
	int getStartYear() const; // When was it created?
	void setName(string theName);
	void setLevel(string theLevel);
	void setAuthor(string theAuthor);
	void setStartYear(int theStartYear);

	// Utility member functions.
	void print();

	// Member attributes (generally private).
private:			// Access modifier = not available to other programs.
	string name;
	string level;
	string author;
	int startyear;

};	

// The ending curly brace needs this semi-colon or 
// there will be errors.

#endif