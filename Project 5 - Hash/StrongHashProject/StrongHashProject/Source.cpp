// Nicholas Strong
// Data Structures and Algorithms
// Project 5 - Hash Tables

// This is the main source file.

#include <iostream>		// Used for input and output.
#include <fstream>		// Used for file input and output.
#include <cstring>
#include <conio.h>		// Used for getch().

#include "WatchBrand.h"

using namespace std;

// Hash table and hash file functions.
int initializeHashTable();
void writeBinary(int position, Brand theBrand);
void readBinary(int position, Brand& theBrand);	// Must pass by reference to keep read value.
void displayBrands();
void createBrands();
void addBrand(Brand theBrand);
int hashFunction(int key);
bool addable(int position);
int linearProbe(int position);
int hashIt(string name);
void searchTable(int position, string name);
int quadraticProbe(int position, int counter);

// Miscellaneous functions.
void pressAnyKey();

// Hash table data.
const static int FILE_LENGTH = 31;	// Several collision/probing techniques work best if the length
									// of possible records is a prime number.
const static int REMOVED = -100;	// If this is to be placed in the key value, then it must be outside of valid range.
const static int EMPTY = -200;
const Brand placeHolderBrand("-----", EMPTY);
const Brand removedBrand("DELETED", REMOVED);
fstream hashFile;

int main() {
	initializeHashTable();
	displayBrands();
	createBrands();

	// Display menu for user choice.
	int choice;
	bool keepGoing = true;
	string search;
	while (keepGoing)
	{
		cout << endl
			<< "---------------------------------------------------------------------\n"
			<< "  __  __ \n"
			<< " |  \\/  |\n"
			<< " | \\  / | ___ ____  _   _\n"
			<< " | |\\/| |/ _ \\  _ \\| | | |\n"
			<< " | |  | |  __/ | | | |_| |\n"
			<< " |_|  |_|\\___|_| |_|\\____|\n"
			<< "---------------------------------------------------------------------\n"
			<< "\t1\tAdd a new object to the file\n"
			<< "\t2\tSearch for object using hash key\n"
			<< "\t3\tRemove an object from the hash table\n"
			<< "\t4\tDisplay the hash table\n"
			<< "\t5\tEnd program\n"
			<< "---------------------------------------------------------------------\n\n"
			<< "Enter your choice : \n";

		// Get user choice and process.
		cin >> choice;
		switch (choice)
		{
		case 1: // Add a new object to the file
		{
			char name[80];
			cout << "What brand name would you like to add?" << endl;
			//cin >> name;
			cin.ignore(1000, '\n');
			cin.getline (name, 80);
			addBrand(name);
			break;
		}
		case 2: // Search for object using hash key
		{
			char name[80];
			cout << "What brand name would you like to search?" << endl;
			cin.ignore(1000, '\n');
			cin.getline(name, 80);
			searchTable(hashFunction(hashIt(name)), name);
			break;
		}
		case 3: // Remove an object from the hash table
		{
			displayBrands();
			int position;
			cout << endl << "Delete which row?" << endl;
			cin >> position;
			writeBinary(position, removedBrand);
			break;
		}
		case 4: // Display the hash table
		{
			displayBrands();
			break;
		}
		case 5:
		{
			keepGoing = false;		// Exit from menu loop and program.
			cout << "<Terminating Program>" << endl;
			break;
		}
		default: // Catch all under construction items.
		{
			cout << "That option is currently not available\n";
			system("PAUSE");
			break;
		}
		}
	}

	hashFile.close();
	system("PAUSE");
	return 0;
}

int initializeHashTable()
{
	// Open hash file.
	hashFile.open("BrandTable1.dat", ios::in | ios::out | ios::binary | ios::trunc);
	if (!hashFile)
	{
		cout << "Hash file error - file did not open successfully\n"
			<< "Program will end.\n";
		pressAnyKey();
		return 1;
	}
	// Initialize hash file (hash table) with empty values.	
	for (int position = 0; position < FILE_LENGTH; position++)
	{
		writeBinary(position, placeHolderBrand);
	}
	return 0;	// Successful completion of hash file intialization.
}

void writeBinary(int position, Brand theBrand)
{
	hashFile.seekp(position * sizeof(Brand));
	hashFile.write((char *)&theBrand, sizeof(Brand));
	hashFile.flush();

	hashFile.seekp(0 * sizeof(Brand));
}

void readBinary(int position, Brand& theBrand)
{
	hashFile.seekg(position * sizeof(Brand));
	hashFile.read((char *)&theBrand, sizeof(Brand));
}

void displayBrands()
{
	//Brand tempBrand;	// Used to read object data in binary format from file.		
	cout << "Displaying hash table contents: \n";
	for (int position = 0; position < FILE_LENGTH; position++)
	{
		Brand tempBrand = Brand();
		readBinary(position, tempBrand);
		cout << "Display: " << position << ": " << tempBrand << endl;
	}
	cout << "End of hash table.\n";
}

// Create Brands for the Brandshelf from the BBC's best Brands of the 21st Century.
void createBrands()
{
	addBrand(Brand("Timex"));
	addBrand(Brand("Seiko"));
	addBrand(Brand("Omega"));
	addBrand(Brand("Rolex"));
	addBrand(Brand("Fossil"));
}

void addBrand(Brand theBrand)
{
	// Get hash value. It's best if the key is unique and if the keys' hash values are spread
	// evenly by the hash function.		
	int position = hashFunction(theBrand.getKey());
	int i = 0;
	while (!addable(position))
	{
		i++;
		cout << "Prequad Position: " << position << " i: " << i << endl;
		position = quadraticProbe(position, i);
		cout << "Postquad Position: " << position << " i: " << i << endl;
	}
	// Add the Brand.
	writeBinary(position, theBrand);			// Insert into hash table.
	cout << "addBrand: theBrand: " << theBrand << endl;
}

// Must be called from a loop and pass i as counter
int quadraticProbe(int position, int counter) {
	position = position + (counter * counter);
	while (position > FILE_LENGTH) {
		position = position - FILE_LENGTH;
	}
	return position;
}

// Bit unnecessary, could return key % FILE_LENGTH in hashIt
int hashFunction(int key)
{
	int position = key % FILE_LENGTH;
	// cout for demo purposes only. 
	cout << "Hash value: " << position << endl;
	return position;
}

// Hashes the search string, sums ASCII values of char[]/string
int hashIt(string name) {
	int key = 0;
	for (unsigned int i = 0; i < name.size(); i++) {
		key += name[i];
	}
	return key;
}

void searchTable(int position, string name) {
	Brand tempBrand = Brand();
	readBinary(position, tempBrand);
	int i = 0;

	// May be infinite loop
	while (name != tempBrand.getName()) {
		i++;
		position = quadraticProbe(position, i);
		readBinary(position, tempBrand);
	}

	cout << "Display: " << position << ": " << tempBrand << endl;
}

bool addable(int position)
{
	Brand Brand;
	readBinary(position, Brand);
	return (Brand.getKey() == EMPTY | Brand.getKey() == REMOVED);
}

// Press any key to continue.
void pressAnyKey()
{
	cout << "Press any key to continue" << endl << endl;
	_getch();					// Waits and gets next character entered.		
}