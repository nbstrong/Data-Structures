/*
The purpose of this file is to provide an INTERFACE for the Book class. 
It's generally a good idea and best practice to separate the 
interface of the class from its implementation.
*/

#include <iostream>		// Used for input and output.
#include <string>

using namespace std;

// Preprocessing directives that prevents multiple definitions.
#ifndef Book_H
#define Book_H

// Class declaration for Book class.
class Book
{
	/////////////////////////////////////
	// Class declarations.

	// Declaring friends (friends have access to private data and operations).
	friend ostream &operator << (ostream& out, const Book& theBook);
	
	/////////////////////////////////////
	// Member functions (often public).
public:				// Access modifier = available to other programs.
	// Default constructor.
	Book();										// Declared but not defined - needs semi-colon.
	// Other constructors.
	Book(string theTitle, string theAuthor, int theYear);

	// Get and set methods or member functions.
	// Sometimes also called accessor and mutator functions.
	string getTitle() const;	
	string getAuthor() const;	
	int getYear() const;
	void setTitle(string theTitle);
	void setAuthor(string theAuthor);
	void setYear(int Year);	

	// Utility member functions.
	void print();

	/////////////////////////////////////////
	// Member attributes (generally private).
private:			// Access modifier = not available to other programs.
	string title;
	string author;
	int year;	

};	// The ending curly brace needs this semi-colon or 
	// there will be errors.

#endif
