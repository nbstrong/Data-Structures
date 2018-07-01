/*
The purpose of this file is to demonstrate how to use objects. 
*/

#include <iostream>		// Used for input and output.
#include <string>
#include <conio.h>		// Used for getch().

#include "Book.h"		// Notice "" marks to identify our own header files.
#include "SinglyLinkedList.h"

using namespace std;

void pressAnyKey();

int main()
{
	// Declare, construct, and display list object.
	SinglyLinkedList bookList;	
	bookList.displayList();
	pressAnyKey();

	// Display menu for user choice.
	int choice;
	bool keepGoing = true;
	while (keepGoing)
	{
		cout	<< endl	
				<< "---------------------------------------------------------------------\n"
				<< " Select an option from the menu below\n"
				<< " by entering the number of the choice\n"
				<< "---------------------------------------------------------------------\n"
				<< "\t1\tAdd book to the front of the list\n"
				<< "\t2\tRemove the book at the front of the list\n"
				<< "\t3\tSort the list of books\n"
				<< "\t4\tSearch for the list of books by an author\n"
				<< "\t5\tDisplay all books in list\n"
				<< "\t6\tEnd program\n"
				<< "---------------------------------------------------------------------\n\n"
				<< "Enter your choice : \n\n";
		
		// Get user choice and process.
		cin >> choice;
		switch(choice)
		{
			case 5:	// Display book list.
				{
					bookList.displayList();
					pressAnyKey();
					break;
				}
			case 6: // Quit program.
				{
					keepGoing = false;		// Exit from menu loop and program.
					cout << "The program is now ending.\n";
					pressAnyKey();
					break;
				}
			default: // Catch all under construction items.
				{
					cout << "That option is currently not available\n";
					pressAnyKey();
					break;
				}
		}
	}

	// End program.	
	return 0;
}

// Press any key to continue.
void pressAnyKey()
{
	cout << "Press any key to continue" << endl << endl;
	_getch();					// Waits and gets next character entered.		
}
