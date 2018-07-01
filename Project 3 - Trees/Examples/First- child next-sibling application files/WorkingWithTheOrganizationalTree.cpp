#include <iostream>		// Used for input and output.
#include <string>
#include <conio.h>		// Used for getch().

#include "FCNSTree.h"

using namespace std;

void pressAnyKey();

int main()
{
	// Declare, construct, and display tree object.	
	Organization organization("Roger");
	/*
	organization.display();	
	pressAnyKey();	
	*/

	// Add new employees.
	organization.add("An", "Roger");
	organization.add("Marissa", "Roger");
	organization.add("Conner", "Marissa");
	organization.add("Jake", "Roger");
	organization.add("Michael", "Marissa");
	organization.add("Ben", "Jake");
	organization.add("Roxyn", "Jake");
	organization.add("Hunter", "An");
	organization.add("Alex", "An");	
	organization.display();		
	//pressAnyKey(); 	

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
				<< "\t1\tAdd an employee to the organization\n"				
				<< "\t2\tDisplay all employees of the organization in outline order\n"
				<< "\t3\tDisplay all employees of the organization in rank order\n"
				<< "\t4\tDisplay all sibling employees of an employee\n"
				<< "\t5\tDisplay all direct reports of a management employee\n"
				<< "\t6\tDisplay all direct and indirect reports of a management employee\n"
				<< "\t7\tDisplay all direct and indirect supervisors of an employee\n"
				<< "\t8\tDisplay all active supervisors\n"
				<< "\t9\tDisplay all worker bees\n"
				<< "\t10\tThe College Football Coaching Option - Fire 'em all\n"
				<< "\t11\tEnd program\n"
				<< "---------------------------------------------------------------------\n\n"
				<< "Enter your choice : \n\n";
		
		// Get user choice and process.
		cin >> choice;
		switch(choice)
		{
			case 1:	// Add an employee.
				{
					string employee, supervisor;
					cout << "Enter the new employee's name: \n";
					cin.ignore();
					getline(cin, employee, '\n');
					cout << "Enter the name " + employee + "'s supervisor: \n";
					getline(cin, supervisor, '\n');
					organization.add(employee, supervisor);
					pressAnyKey();
					break;
				}
			case 2:	// Display organization in outline order.
				{
					organization.displayInOutline();
					pressAnyKey();
					break;
				}
			case 3:	// Display organization in rank order. 
				{
					organization.displayByRank();
					pressAnyKey();
					break;
				}
			case 4:	// Display sibling employees.
				{
					string employee, supervisor;
					cout << "Enter the new employee's name: \n";
					cin.ignore();
					getline(cin, employee, '\n');
					organization.displaySiblings(employee);
					pressAnyKey();
					break;
				}
			// other cases ...
			case 11: // Quit program.
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
