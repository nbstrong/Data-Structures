#include <iostream>		// Used for input and output.
#include <fstream>		// Used for file input and output.
#include <cstring>
#include <conio.h>		// Used for getch().

#include "Book.h"	

using namespace std;

// Hash table and hash file functions.
int initializeHashTable();
void writeBinary(int position, Book theBook);
void readBinary(int position, Book& theBook);	// Must pass by reference to keep read value.
void displayBooks();
void createBooks();
void addBook(Book theBook);
int hashFunction(int key);
bool addable(int position);
int linearProbe(int position);

// Miscellaneous functions.
void pressAnyKey();

// Some project tasks:
//	menu: add, search, remove, display table.
//	use quadratic probing
//	use a class other than book
//	test add 5 more books - up table size to 31 - trace at least one object through 2 collisions
//	remove objects
//	search for objects

// Hash table data.
const static int FILE_LENGTH = 23;	// Several collision/probing techniques work best if the length
									// of possible records is a prime number.
const static int REMOVED = -100;	// If this is to be placed in the key value, then it must be outside of valid range.
const static int EMPTY = -200;
const Book placeHolderBook("------------------------", "------------------------", 0, EMPTY);    	
const Book removedBook("XXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXX", 0, REMOVED);    	
fstream hashFile; 

int main()
{
	initializeHashTable();		// Initialize empty hash table with dummy records and display.	
	displayBooks();
	pressAnyKey();

	createBooks();				// Create the books used in this hash file demo.	
	displayBooks();
	pressAnyKey();	

	hashFile.close();

	//===========================
	// Miscelleneous demo code.
	// Create objects.
	Book book1("Blue sky", "Matthew Smith", 1924, 123456789);
	Book book2("Red sky", "Regie Jones", 1924, 234567890);
	Book book3;

	// Write objects to the binary file.
	fstream file("test-binary.dat",ios::binary | ios::in | ios::out | ios::trunc );
	if(!file.is_open())
	{
		cout << "error while opening the file";
	}	
	
	// Display books.
	cout << "Book objects: " << endl;
	book1.print();
	book2.print();
	book3.print();
	cout << endl << endl;
	pressAnyKey();	

	// Read books from file and display.
	cout << endl << "Book writes and reads." << endl;
	file.write((char *)&book1, sizeof(Book));
	file.write((char *)&book2, sizeof(Book));
	file.write((char *)&book3, sizeof(Book));
	Book tempBook1, tempBook2, tempBook3;
	file.seekg(0);
	file.read( (char *)&tempBook1, sizeof(Book) );
	tempBook1.print();
	file.read( (char *)&tempBook2, sizeof(Book) );
	tempBook2.print();
	file.read( (char *)&tempBook3, sizeof(Book) );
	tempBook3.print();		
	pressAnyKey();	
	
	// Random access reads from file (looking at file in reverse order).
	cout << endl << "Book random access look ups " << endl;	
	file.seekg(2 * sizeof(Book) );					// Find the position in file.
	file.read( (char *)&tempBook1, sizeof(Book) );	// Read from that position.
	tempBook1.print();								// Display what was read.
	file.seekg(1 * sizeof(Book) );
	file.read( (char *)&tempBook2, sizeof(Book) );
	tempBook2.print();
	file.seekg(0 * sizeof(Book) );
	file.read( (char *)&tempBook3, sizeof(Book) );
	tempBook3.print();		
	pressAnyKey();	

	// Random access over-writes.
	cout << endl << "Random access over-writes" << endl;
	Book book4("New replacement title", "Me", 2015, 345678901);	// Obtain data to write with.
	file.seekp(0 * sizeof(Book) );								// Find position in file.
	file.write( (char *)&book4, sizeof(Book));					// Write data to that position.
	Book book5("Second new replacement title", "Another Me", 2017, 456789012);
	file.seekp(2 * sizeof(Book) );
	file.write( (char *)&book5, sizeof(Book) );	

	// Read and display over-written and non-over-written objects in file to check previous writes.
	file.seekg(0 * sizeof(Book) );
	file.read( (char *)&tempBook1, sizeof(Book) );
	tempBook1.print();
	file.seekg(1 * sizeof(Book) );
	file.read( (char *)&tempBook2, sizeof(Book) );
	tempBook2.print();
	file.seekg(2 * sizeof(Book) );
	file.read( (char *)&tempBook3, sizeof(Book) );
	tempBook3.print();
	pressAnyKey();

	file.close();	// Close file and end program.	
	return 0;	
}

int initializeHashTable()
{
	// Open hash file.
	hashFile.open( "BookShelfTable4.dat", ios::in | ios::out | ios::binary | ios::trunc );
	if (!hashFile)
	{
		cout	<< "Hash file error - file did not open successfully\n"
				<< "Program will end.\n";
		pressAnyKey();
		return 1;
	}
	// Initialize hash file (hash table) with empty values.	
	for (int position = 0; position < FILE_LENGTH; position++)
	{   		
		writeBinary(position, placeHolderBook);
    }	
	return 0;	// Successful completion of hash file intialization.
}

void writeBinary(int position, Book theBook)
{
	hashFile.seekp(position * sizeof(Book) );
	hashFile.write( (char *) &theBook, sizeof(Book) );
	hashFile.flush();

	hashFile.seekp(0 * sizeof(Book) );
}

void readBinary(int position, Book& theBook)
{	
	hashFile.seekg(position * sizeof(Book) );
	hashFile.read( (char *) &theBook, sizeof(Book) );
}

void displayBooks()
{
	Book tempBook;	// Used to read object data in binary format from file.		
	cout << "Displaying hash table contents: \n";
	for (int position = 0; position < FILE_LENGTH; position++)	
	{		
		tempBook = Book("", "", 0, 0);
		readBinary(position, tempBook);
		cout << "Display: " << position << ": " << tempBook << endl;			
	}	
	cout << "End of hash table.\n";
}

// Create books for the bookshelf from the BBC's best books of the 21st Century.
void createBooks()
{	
	addBook( Book("The Brief Wondrous Life of Oscar Wao", "Junot Diaz", 2000, 123456789) );
	addBook( Book("The Known World", "Edward P Jones", 2003, 234567890) );
	addBook( Book("Wolf Hall", "Hilary Mantel", 2009, 345678901) );
	addBook( Book("Gilead", "Marilynne Robinson", 2004, 456789012) );
	addBook( Book("The Corrections", "Jonathan Franzen", 2001, 567890123) );
	addBook( Book("The Amazing Adventures of Kavalier & Clay", "Michael Chabon", 2000, 222233333) );
	addBook( Book("A Visit from the Goon Squad", "Jennifer Egan", 2010, 678901234) );
	addBook( Book("Billy Lynn\'s Long Halftime Walk", "Ben Fountain", 2012, 789012345) );
	addBook( Book("Atonement", "Ian McEwan", 2001, 890123456) );
	addBook( Book("Half of a Yellow Sun", "Chimamanda Ngozi Adichie", 2006, 901234567) );
	addBook( Book("White Teeth", "Zadie Smith", 2000, 112345678) );
	addBook( Book("Middlesex", "Jeffrey Eugenides", 2002, 198765432) );	
}

void addBook(Book theBook)
{
	// Get hash value. It's best if the key is unique and if the keys' hash values are spread
	// evenly by the hash function.		
	int position = hashFunction( theBook.getISBN() );
	if ( !addable(position) )
	{
		// Probe linearly as needed to get the correct final position.
		position = linearProbe(position);
	}
	// Add the book.
	writeBinary(position, theBook);			// Insert into hash table.
	cout << "addBook: theBook: " << theBook << endl;	
}

int hashFunction(int key)
{
    int position = key % FILE_LENGTH;
	// cout for demo purposes only. 
	cout << "Hash value: " << position << endl;
    return position;			
}

bool addable(int position)
{
	Book book;
	readBinary(position, book);
	return ( book.getISBN() == EMPTY );	
}

int linearProbe(int position)
{
	do	// Increment position until an addable position is reached.
	{	
		if (position < FILE_LENGTH - 1)
		{
			position++;
		}
		else	// If the end of the file is reached
		{		// restart in the first position.
			position = 0;
		}
	} while ( !addable(position) );	
	return position;		// Return the appropriat position to add the book.
}

// Press any key to continue.
void pressAnyKey()
{
	cout << "Press any key to continue" << endl << endl;
	_getch();					// Waits and gets next character entered.		
}
