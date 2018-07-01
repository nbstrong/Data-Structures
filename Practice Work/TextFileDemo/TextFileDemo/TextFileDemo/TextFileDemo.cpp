/*
The purpose of this file is to demonstrate how to write objects to 
textfiles and how to read textfiles and convert their data into
copies of the original objects. 
*/

#include <iostream>		// Used for input and output.
#include <string>		// Used for strings.
#include <conio.h>		// Used for getch().
#include <fstream>		// Used for file functions. 
#include <vector>		// Used for vectors.

#include "Book.h"		// Notice "" marks to identify our own header files.

using namespace std;

// Global vector of books. A vector has indices like an array but it's size is dynamic. 
// A vector also contains useful functions. 
vector<class Book> bookVector; 

void pressAnyKey();
void writeTextFile();
void readTextFile();
void displayVector();

int main()
{
	// Create books and put into vector and display vector. 	
	bookVector.push_back( Book("The Day it Happened", "Luke Obidiah", 2015) );
	bookVector.push_back( Book("Datastructures and Data", "Al In", 1991) );
	bookVector.push_back( Book("The World is Oblong", "Sandra Tornado", 1478) );	
	displayVector();

	// Save vector data into a textfile and clear vector and display empty vector.
	writeTextFile();	
	bookVector.clear();
	displayVector();

	// Restore vector data by reading the textfile and then display.
	readTextFile();	
	displayVector();
	pressAnyKey();

	return 0; 
} // end main

void writeTextFile()
{
	// Step 1 - Open the "file" for output (writing) with constructor. 
	// The object here is a file handle which is used to write data from vector.
	ofstream bookTextFile("books.txt", ios::out);
	// Exit program if file was not created successfully. 
	if (!bookTextFile) 
	{
		cerr << "File does not exist or could not be opened." << endl; // cerr - error to console
		exit(1);	// End program with errors.
	}

	// Step 2 - Write the data in the vector to the file.
	int i = 0;
	while (i < bookVector.size() ) 
	{
		// Write each element of vector.
		bookTextFile	<< bookVector.at(i).getTitle() << '\t'						
						<< bookVector.at(i).getAuthor() << '\t' 
						<< bookVector.at(i).getYear();
		if (i < bookVector.size() - 1)
		{
			bookTextFile << endl;
		}
		// Display file writing work for demo purposes only.
		cout << "Written to file:\n   " << bookVector.at(i) << endl;
		i++;
	}
	cout << endl;	

	// Step 3 - close file.
	bookTextFile.close();		
}

void readTextFile()
{
	// Step 1 - Open the "file" for input (reading) with constructor. 
	// The object here is a file handle.
	ifstream bookTextFile( "books.txt", ios::in );	
	// Exit program if file is not openable or found. 
    if (!bookTextFile) 
	{
		cerr << "File could not be found or opened." << endl;
		exit(1);	// End program with errors.
	} 

	string theTitle, theAuthor;
	int theYear;	
	// Step 2 - read data, construct objects, and add to vector.
	while ( !bookTextFile.eof() )
	{
		// Get inputs from file.
		getline(bookTextFile, theTitle, '\t');		
		getline(bookTextFile, theAuthor, '\t');				
		bookTextFile >> theYear;	// 	Conversions: stoi( theIntString.c_str() )
									//				 stod( theDoubleString.c_str() )
		// Construct books from file inputs and add to vector.
		Book theBook(theTitle, theAuthor, theYear);
		bookVector.push_back(theBook);
		// Display new book from file for demo purposes.
		cout << "Read into vector:\n  " << theBook << endl;
	}
	cout << endl;

	// Step 3 - close file.
	bookTextFile.close();	
}

void displayVector()
{
	if ( bookVector.size() > 0 )	// Demonstrating the use of the iterator.
	{						
		vector<Book>::iterator bookVectorIterator;
		bookVectorIterator = bookVector.begin();
		cout << "Vector elements:\n";
		while ( bookVectorIterator != bookVector.end() ) // While not finished with data in vector.
		{
			cout << *bookVectorIterator << endl;
			bookVectorIterator++;
		}
		cout << endl;
	}
	else
	{
		cout << "There are no elements in the vector to display.\n\n";
	}	
}

// Press any key to continue.
void pressAnyKey()
{
	cout << "Press any key to continue" << endl << endl;
	_getch();					// Waits and gets next character entered.		
}
