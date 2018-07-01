// Nicholas Strong
// Data Structures and Algorithms
// Project 2 - Lists
// Topic: Programming languages with a focus on lower level languages

// This is the class driver file

#include <iostream> // Used for input output
#include <string>
#include <conio.h> // Used for getch().

#include "PLanguage.h"
#include "DoublyLinkedList.h"

using namespace std;

void pressAnyKey();
PLanguage fillLanguage();

int main()
{
	// Declare, construct, and display list object.
	cout << "<Constructing list object>" << endl;
	DoublyLinkedList languageList;
	pressAnyKey();

	// Display menu for user choice.
	int choice;
	bool keepGoing = true;
	while (keepGoing)
	{
		cout << "<Displaying Main Menu>" << endl;
		cout << endl
			<< "---------------------------------------------------------------------\n"
			<< "  __  __ \n"
			<< " |  \\/  |\n"
			<< " | \\  / | ___ ____  _   _\n"
			<< " | |\\/| |/ _ \\  _ \\| | | |\n"
			<< " | |  | |  __/ | | | |_| |\n"
			<< " |_|  |_|\\___|_| |_|\\____|\n"
			<< "---------------------------------------------------------------------\n"
			<< "\t1\tAdd a language to the front of the list\n"
			<< "\t2\tAdd a language to the back of the list\n"
			<< "\t3\tSearch, edit, or delete language\n"
			<< "\t4\tDisplay all languages in the list\n"
			<< "\t5\tEnd program\n"
			<< "---------------------------------------------------------------------\n\n"
			<< "Enter your choice : \n\n";

		// Get user choice and process.
		cin >> choice;
		switch (choice)
		{
		case 1: // Add language to the front
		{
			// Query user for language information
			languageList.addFront(fillLanguage()); // Create node at front of list with language object
			break;
		}
		case 2: // Add language to the back
		{
			// Query user for language information
			languageList.addBack(fillLanguage()); // Create node at back of list with language object
			break;
		}
		case 3: // Search for a language
		{
			string search;
			cout << "Enter name of language to search for:" << endl;
			cin >> search;
			languageList.searchList(search); // Search list names for search string
			break;
		}
		case 4:	// Display language list.
		{
			languageList.displayList();
			pressAnyKey();
			break;
		}
		case 5: // Quit program.
		{
			keepGoing = false;		// Exit from menu loop and program.
			cout << "<Terminating Program>" << endl;
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
	cout << "<Program Terminated>" << endl;
	return 0;
}

// Function - Press any key to continue
void pressAnyKey()
{
	cout << "Press any key to continue" << endl;
	_getch();					// Waits and gets next character entered.		
}

PLanguage fillLanguage() {
	string theName, theLevel, theAuthor;
	int theStartYear;

	cout << "<Quering User for Language Information>" << endl;
	cout << "What language would you like to add?" << endl;
	cin >> theName;
	cout << "Is it low or high level?" << endl;
	cin >> theLevel;
	cout << "Who created it?" << endl;
	cin >> theAuthor;
	cout << "What year was it released?" << endl;
	cin >> theStartYear;
	cout << "<Creating Language Object>" << endl;
	PLanguage languageObject(theName, theLevel, theAuthor, theStartYear); //Create new language object

	return languageObject;
}
