#include <iostream>		// Used for input and output.
#include <fstream>		// Used for file input and output.

#include "Book.h"		// Notice "" marks to identify our own header files.

using namespace std;

///////////////////////
// Constructors.
Book::Book()
{
	setTitle("");
	setAuthor("");	
	setYear(0);
	setISBN(0);
}

Book::Book(char *theTitle, char *theAuthor, int theYear, int theISBN)
{
	setTitle(theTitle);
	setAuthor(theAuthor);	
	setYear(theYear);
	setISBN(theISBN);
}

///////////////////////
// Get and set methods.

string Book::getTitle() const	
{								
	return title;				
}								
								
string Book::getAuthor() const
{
	return author;
}

int Book::getYear() const
{
	return year;
}

int Book::getISBN() const
{
	return ISBN;
}

void Book::setTitle(char *theTitle) 
{ 
	strcpy_s(title, theTitle);		// strcpy has been deprecated. _s functions are more secure variants.
}

void Book::setAuthor(char *theAuthor) 
{ 
	strcpy_s(author, theAuthor);
}

void Book::setYear(int theYear)
{
	if (theYear < 0)
	{
		year = 0;
	}
	else
	{
		year = theYear;
	}
}

void Book::setISBN(int theISBN)
{
	// ISBN's must be 9 digit positive numbers or negative numbered flag conditions.
	if ( (theISBN < 100000000) && (theISBN > 0) )
	{
		ISBN = 0;
	}
	else
	{
		ISBN = theISBN;
	}
}

///////////////////////
// Utility functions.

void Book::print()
{
	cout << title << " published in " << year << " by " << author << " (ISBN: " << ISBN << ")" << endl;
}

ostream &operator << (ostream& out, const Book& theBook)
{
	out << theBook.title << " by " << theBook.author << " published in " << theBook.year;
	return out;
}	