/*
The purpose of this file is to demonstrate how to use objects in an array. 
*/

#include <iostream>		// Used for input and output.
#include <string>
#include <conio.h>		// Used for _getch(), but I'm using system("pause") in this program.

#include "Book.h"		// Notice "" marks to identify our own header files.

using namespace std;

void displayArray(Book array[], int length);

int main()
{
	// Declare, construct, and display list object.
	const int LENGTH = 5;
	Book bookShelf[LENGTH];	
	bookShelf[0] = Book("The Hunger Games", "Suzanne Collins", 2008);
	bookShelf[1] = Book("The Giver", "Lois Lowry", 1993);
	bookShelf[2] = Book("Divergent", "Veronica Roth", 2011);
	bookShelf[3] = Book("The Maze Runner", "James Dashner", 2009);
	bookShelf[4] = Book("1984", "George Orwell", 1949);

	displayArray(bookShelf, LENGTH);
	system("pause");				// Can create non-portable code.
	cout << endl;
	cout << system("dir") << endl;	// system is very useful function however.
	system("pause");				// It is fine to use it, if you like.
									// I will continue to use _getch() as in other programs.
	// End program.	
	return 0;
}

// Display values of array - each on their own line.
void displayArray(Book array[], int length)
{
	int i = 0;
	while (i < length)
	{
		cout << array[i] << endl;
		i++;
	}	
	cout << endl;
}