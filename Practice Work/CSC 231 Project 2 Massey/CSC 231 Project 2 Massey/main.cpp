#include <iostream> //used for cout, cin, printf, etc.
#include <string> //used for strings as inputs/outputs
#include <conio.h> //used for getch()
#include "Food.h" //allows the Food class for main
#include "FoodList.h" //allows FoodList class for main

using namespace std;

void PressAny() //function used to pause the program and wait for input
{
	printf("Press any key to continue...\n");
	_getch();
}

int main()
{
	int action; //what choice the user made
	bool exitflag = false; //flag for when the user chooses to quit
	FoodList foodlist; //list of food to use
	string name, newname; //user inputs for names of food
	double pricetag; //user input for prices of food
	cout << "---------------------------------------------------------------------\n"
		<< "\t\t\t ACTIONS AVAILABLE \n"
		<< "---------------------------------------------------------------------\n"
		<< "\t0\t Display the selection menu again.\n"
		<< "\t1\t Add to the front of the list.\n"
		<< "\t2\t Add to the back of the list.\n"
		<< "\t3\t Search for and display an item in the list.\n"
		<< "\t4\t Edit a specific item in the list.\n"
		<< "\t5\t Remove a specific item from the list.\n"
		<< "\t6\t Display the list.\n"
		<< "\t7\t Quit the program.\n"
		<< "---------------------------------------------------------------------\n";
	while (!exitflag) //continues until quit is selected
	{
		cout << "Enter a number corresponding to the action you would like to commit: ";
		cin >> action;
		switch (action) //goes to appropriate choice
		{
		case 0: //displays the choice menu again
		{
			//printf("Display menu again. \n");
			cout << endl;
			cout << "---------------------------------------------------------------------\n"
				<< "\t\t\t ACTIONS AVAILABLE \n"
				<< "---------------------------------------------------------------------\n"
				<< "\t0\t Display the selection menu again.\n"
				<< "\t1\t Add to the front of the list.\n"
				<< "\t2\t Add to the back of the list.\n"
				<< "\t3\t Search for and display an item in the list.\n"
				<< "\t4\t Edit a specific item in the list.\n"
				<< "\t5\t Remove a specific item from the list.\n"
				<< "\t6\t Display the list.\n"
				<< "\t7\t Quit the program.\n"
				<< "---------------------------------------------------------------------\n";
			break;
		}
		case 1: //adds item to the front of the list
		{
			//printf("Add to front. \n");
			cout << "Enter name of food item: ";
			cin >> name;
			cout << "Enter price of food item: ";
			cin >> pricetag;
			foodlist.addFront(Food(name, pricetag)); //function creates and adds Food item to the front called name with price pricetag
			cout << endl;
			break;
		}
		case 2: //adds item to the back of the list
		{
			//printf("Add to back. \n");
			cout << "Enter name of food item: ";
			cin >> name;
			cout << "Enter price of food item: ";
			cin >> pricetag;
			foodlist.addBack(Food(name, pricetag)); //function creates and adds Food item to the back called name with price pricetag
			cout << endl;
			break;
		}
		case 3: //searches the list for a specific food name and displays its properties
		{
			//printf("Search list. \n");
			cout << "Enter food item to search for: ";
			cin >> name;
			foodlist.searchItem(name); //searches for and displays the food item of name
			cout << endl;
			break;
		}
		case 4: //searches for and edits a food item in the list
		{
			//printf("Edit item. \n");
			cout << "Enter food item to edit: ";
			cin >> name;
			cout << "Enter new food: ";
			cin >> newname;
			cout << "Enter new price: ";
			cin >> pricetag;
			foodlist.editItem(name, newname, pricetag); //searches for name in the list and changes its values to newname and pricetag
			cout << endl;
			break;
		}
		case 5: //removes a food item from the list
		{
			//printf("Remove item. \n");
			cout << "Enter food item to remove: ";
			cin >> name;
			foodlist.removeItem(name); //searches for name in the list and removes it from the list while adjusting pointers for next/previous
			cout << endl;
			break;
		}
		case 6: //displays the entire food list
		{
			//printf("Display list. \n");
			foodlist.displayList(); //displays the entirety of foodlist
			PressAny();
			cout << endl;
			break;
		}
		case 7: //exits the program cleanly
		{
			printf("Exiting the program... \n");
			exitflag = true; //while loop will not execute again, ending the program
			//PressAny();
			break;
		}
		default: //used for catching unexpected choices
		{
			printf("The option selected is not available.\n");
			cout << endl;
			break;
		}
		}
		//PressAny();
	}
	return 0;
}