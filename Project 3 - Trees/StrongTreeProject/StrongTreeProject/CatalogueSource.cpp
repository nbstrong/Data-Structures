// Nicholas Strong
// Data Structures and Algorithms
// Project 3 - Trees

// This is the main source file.
// Thoughts on this project: It feels very hacky and messy. As projects
// get bigger, it can easily become a mess.

#include <iostream> // Used for input output.
#include <string>
#include <conio.h> // Used for getch().
#include <fstream>

#include "Product.h"
#include "Tree.h"

using namespace std;

void pressAnyKey();
void fillTree(Tree& productTree);
Product fillProduct();

int main()
{
	// Declare, construct, and fill tree object.
	cout << "<Constructing product and order trees>" << endl;
	Tree productTree;
	Tree orderTree;
	cout << "<Filling from file>" << endl;
	fillTree(productTree);
	pressAnyKey();

	// Display menu for user choice.
	int choice;
	bool keepGoing = true;
	string search;
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
			<< "\t1\tAdd a product to the catalogue\n"
			<< "\t2\tEdit a product\n"
			<< "\t3\tFind and display a product\n"
			<< "\t4\tView all products\n"
			<< "\t5\tDelete a product\n"
			<< "\t6\tFind and purchase a product\n"
			<< "\t7\tDisplay the current order\n"
			<< "\t8\tClear the current order\n"
			<< "\t9\tEnd program\n"
			<< "---------------------------------------------------------------------\n\n"
			<< "Enter your choice : \n\n";

		// Get user choice and process.
		cin >> choice;
		switch (choice)
		{
		case 1: // Add a product to the catalogue
		{	
			// Asks product details then adds the node
			productTree.addNode(fillProduct());
			break;
		}
		case 2: // Edit a product
		{
			// In order to prevent crashes I decided to export and remake the tree.
			// This is probably a worst solution than reordering it like delete does but...
			// yeah. This was difficult.
			cout << "Enter name of product to edit: " << endl;
			cin >> search;

			if (productTree.searchTree(search, productTree.Root()) != NULL) {
				productTree.editTree(productTree.searchTree(search, productTree.Root()));
				productTree.exportTree(productTree.Root());
				productTree.freeNode(productTree.Root());
				fillTree(productTree);
				break;
			}
			else {
				cout << "No product found matching \"" << search << "\"" << endl;
			}
			break;
		}
		case 3: // Find and display a product
		{
			cout << "Enter name of product to search: " << endl;
			cin >> search;

			// Find root, search from root, and display node found
			productTree.displayNode(productTree.searchTree(search, productTree.Root()));
			break;
		}
		case 4: // View all products
		{
			// Finds root, displays tree inorder
			if (productTree.Root() != NULL) {
				productTree.Inorder(productTree.Root());
			}
			else {
				cout << "No products found" << endl;
			}
			break;
		}
		case 5: // Delete a product
		{
			cout << "Enter name of product to delete: " << endl;
			cin >> search;
			cout << "No confirmation! We live dangerously in bat country!" << endl;
			
			// Crashes weirdly, need to focus on this more
			// Crashes no more, what a nightmare

			productTree.DeleteNode(productTree.Root(), productTree.searchTree(search, productTree.Root())->key);
			break;
		}
		case 6: // Find and purchase a product
		{
			cout << "Search for a product you want to add:" << endl;
			cin >> search;
			cout << "How many would you like to buy?" << endl;
			int quant;
			cin >> quant;

			// If it finds something, add node to ordertree and set quantity

			if (productTree.searchTree(search, productTree.Root()) != NULL) {
				orderTree.addNode(productTree.searchTree(search, productTree.Root())->productdata);
				orderTree.searchTree(search, orderTree.Root())->productdata.setQuantity(quant);
			}
			else {
				cout << "No product found" << endl;
			}
			break;
		}
		case 7: // Display the current order
		{
			// Same as display product tree except Preorder
			if (orderTree.Root() != NULL) {
				orderTree.Preorder(orderTree.Root());
			}
			else {
				cout << "No order found" << endl;
			}
			break;
		}
		case 8: // Clear the current order
		{

			// Find root then run freenode on it

			orderTree.freeNode(orderTree.Root());
			break;
		}
		case 9: // Quit program.
		{
			keepGoing = false;		// Exit from menu loop and program.
			cout << "<Terminating Program>" << endl;
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

	// End program and export the catalogue

	productTree.exportTree(productTree.Root());

	cout << "<Program Terminated>" << endl;
	return 0;
}

// Function - Press any key to continue
void pressAnyKey()
{
	cout << "Press any key to continue" << endl;
	_getch();					// Waits and gets next character entered.		
}

// This function should open and read the product txt file and have a
// function call to create a tree with the products.
void fillTree(Tree& productTree) {
	string theName, dummy;
	double thePrice;
	int theQuant;

	ifstream TxtObject("productlist.txt", ios::in);

	if (!TxtObject) {
		cerr << "<File not found>" << endl;
		exit(1); // End program with errors
	}

	while (!TxtObject.eof()) {
		getline(TxtObject, theName, '\t');
		TxtObject >> thePrice;
		TxtObject >> theQuant;
		getline(TxtObject, dummy, '\n');

		Product theProduct(theName, thePrice);
		productTree.addNode(theProduct);
	}

	TxtObject.close();
}

Product fillProduct() {
	string theName;
	double thePrice;
	//int theQuant;

	cout << "<Quering User for Product Information>" << endl;
	cout << "What product would you like to add?" << endl;
	cin >> theName;
	cout << "What is its' price?" << endl;
	cin >> thePrice;

	cout << "<Creating Product Object>" << endl;
	Product theProduct(theName, thePrice);
	
	return theProduct;
}