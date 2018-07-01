/*
The purpose of this file is to provide an IMPLEMENTATION for the Book class. 
It's generally a good idea and best practice to separate the 
interface of the class from its implementation.
*/

#include "Book.h"		// Notice "" marks to identify our own header files.

////////////////////////
// Function definitions.	
	
// Default constructor.
Book::Book()		// When a method is defined outside of its file,
{					// we must use the :: resolution operator with
					// the class name.
	/*
	title = "";
	author = "";
	year = 0;
			We don't use the above code in order to maintain full control
			over the data in our class. It also greatly simplifies
			the work of testing and debugging.
	*/

	setTitle("");
	setAuthor("");
	setYear(0);
}

// Another constructor. This is an example of overloading.
Book::Book(string theTitle, string theAuthor, int theYear)
{
	setTitle(theTitle);
	setAuthor(theAuthor);
	setYear(theYear);
}

///////////////////////
// Get and set methods.

string Book::getTitle() const	// Not everyone adds const
{								// but it does follow the 
	return title;				// principle of "least 
}								// privelege," a core security
								// principle.

string Book::getAuthor() const
{
	return author;
}

int Book::getYear() const
{
	return year;
}

void Book::setTitle(string theTitle) 
{ 
	title = theTitle; 
}

void Book::setAuthor(string theAuthor) 
{ 
	author = theAuthor; 
}

// Control data and flag bad data with default value.
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

// Utility member functions.
void Book::print()
{
	cout	<< title << " by " << author << " published in " << year;
}

ostream &operator << (ostream& out, const Book& theBook)
{
	out << theBook.title << " by " << theBook.author << " published in " << theBook.year;
	return out;
}