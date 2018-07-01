// This is the class implementation file

#include "PLanguage.h"		// Notice "" marks to identify our own header files.


// Function definitions.	

// Default constructor.
PLanguage::PLanguage()		
{					// When a method is defined outside of its file,
					// we must use the :: resolution operator with
					// the class name.
					// We don't use the above code in order to maintain full control
					// over the data in our class. It also greatly simplifies
					// the work of testing and debugging.
	setName("");
	setLevel("");
	setAuthor("");
	setStartYear(0);
}

// Another constructor. This is an example of overloading.
PLanguage::PLanguage(string theName, string theLevel, string theAuthor, int theStartYear)
{
	setName(theName);
	setLevel(theLevel);
	setAuthor(theAuthor);
	setStartYear(theStartYear);
}

// Get and set methods.
string PLanguage::getName() const
{
	return name;
}


string PLanguage::getLevel() const	// Not everyone adds const
{								// but it does follow the 
	return level;				// principle of "least 
}								// privelege," a core security
								// principle.

string PLanguage::getAuthor() const
{
	return author;
}

int PLanguage::getStartYear() const
{
	return startyear;
}

void PLanguage::setName(string theName)
{
	name = theName;
}

void PLanguage::setLevel(string theLevel)
{
	level = theLevel;
}

void PLanguage::setAuthor(string theAuthor)
{
	author = theAuthor;
}

// Control data and flag bad data with default value.
void PLanguage::setStartYear(int theStartYear)
{
	if (theStartYear < 0) {
		startyear = 0;
	}
	else {
		startyear = theStartYear;
	}
}

// Utility member functions.
void PLanguage::print()
{
	cout << "Name: " << name << endl
		<< "Low or high: " << level << endl
		<< "Year of Creation: "<< startyear << endl
		<< "Author: " << author << endl;
}

ostream &operator << (ostream& out, const PLanguage& language) // this sneaky function! whaaat?
{
	cout << "Name: " << language.name << endl
		<< "Low or high: " << language.level << endl
		<< "Year of Creation: " << language.startyear << endl
		<< "Author: " << language.author << endl;
	
	return out;
}
