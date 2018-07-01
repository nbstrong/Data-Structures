#include "FoodList.h" //contains function and variable declarations for the class

FoodList::FoodList() //default constructor for the class
{
	head = { }; //initializes head as a NULL array
	tail = { }; //initializes tail as a NULL array
}

FoodList::~FoodList() //deconstructor for the class
{
	while (!headempty() || !tailempty()) //tests for either lists having values
	{
		removeFront(); //used to systematically remove all items from the lists
	}
}

bool FoodList::headempty() const //used to test if head has values
{
	return (head == NULL); //tests if head is nonempty
}

bool FoodList::tailempty() const //used to test if tail has values
{
	return (tail == NULL); //tests if tail is nonempty
}

void FoodList::addFront(const Food& f) //adds item to the front of the list
{
	FoodNode* temp = new FoodNode; //creates new node in the list called temp
	temp->food = f; //assigns new temp's data value to passed value f
	if (head) //if old head is nonempty
	{
		head->previous = temp; //changes old head's previous pointer to new temp
	}
	temp->next = head; //new temp's next pointer is old head
	head = temp; //new head is new temp
	head->previous = NULL; //new head's previous pointer is NULL
}

void FoodList::addBack(const Food& f) //adds item to the back of the list
{
	FoodNode* temp = new FoodNode; //creates new node in the list called temp
	temp->food = f; //assigns new temp's data value to passed value f
	if (tail) //if old tail is nonempty
	{
		tail->next = temp; //old tail's next pointer is new temp
	}
	temp->previous = tail; //new temp's previous pointer is old tail
	tail = temp; //new tail is new temp
	tail->next = NULL; //new tail's next pointer is NULL
}

void FoodList::searchItem(string f) //searches lists for specific item name of passed f
{
	bool founditem = false; //used to catch if item is found
	if (!headempty() || !tailempty()) //if either head or tail is nonempty continue
	{
		if (!headempty()) //if head is nonempty continue
		{
			FoodNode* temp = head; //creates new temp node to search head
			while (temp) //while temp is not NULL
			{
				if (f.compare((temp->food).getFood()) == 0) //compares temp's food value to passed f and continues inside if they match
				{
					temp->food.print(); //displays matching temp's food value
					founditem = true; //switch flag
					return; //exits search
				}
				temp = temp->next; //increments temp to search all of head
			}
		}
		if (!tailempty()) //if tail is nonempty continue
		{
			FoodNode* temp = tail; //creates new temp node to search tail
			while (temp) //while temp is not NULL
			{
				if (f.compare((temp->food).getFood()) == 0) //compares temp's food value to passed f and continues inside if the match
				{
					temp->food.print(); //displays matching temp's food value
					founditem = true; //switch flag
					return; //exits search
				}
				temp = temp->previous; //increments temp to search all of tail
			}
		}
	}
	if(!founditem) //if flag is still false continue
	{
		cout << "That food item was not found in the list.\n";
	}
}

void FoodList::editItem(string f, string name, double price) //searches and edits an item in the list
{
	bool founditem = false; //used to catch if item is found
	if (!headempty() || !tailempty()) //if head or tail is nonempty continue
	{
		if (!headempty()) //if head is nonempty continue
		{
			FoodNode* temp = head; //creates new temp node to search head
			while (temp) //while temp is nonempty
			{
				if (f.compare((temp->food).getFood()) == 0) //compares temp's food value to passed f and continues inside if it matches
				{
					temp->food.setFood(name); //sets temp's food values to name and price
					temp->food.setPrice(price);
					temp->food.print(); //displays temp's food's new values
					founditem = true; //switches flag if found
					return; //stops search
				}
				temp = temp->next; //increments temp to search all of head
			}
		}
		if (!tailempty()) //if tail is nonempty contine
		{
			FoodNode* temp = tail; //creates new node to search all of tail
			while (temp) //while temp is nonempty
			{
				if (f.compare((temp->food).getFood()) == 0) //compares passed f to food value of temp and continues inside if it matches
				{
					temp->food.setFood(name); //sets temp's food values to name and price
					temp->food.setPrice(price);
					temp->food.print(); //displays temp's food's new values
					founditem = true; //switches flag if found
					return; //stops search
				}
				temp = temp->previous; //increments temp to search all of tail
			}
		}
	}
	if (!founditem) //if item was not found continue
	{
		cout << "That food item was not found in the list.\n";
	}
}

void FoodList::removeItem(string f) //function for removing specific food with value f from list
{
	bool founditem = false; //used to catch if item is found
	if (!headempty() || !tailempty()) //if either head or tail is nonempty continue
	{
		if (!headempty()) //if head is nonempty continue
		{
			FoodNode* temp = head; //creates a new temp node to search all of head
			while (temp) //while temp is nonempty
			{
				if (f.compare((temp->food).getFood()) == 0) //compares passed f to temp's food value and continues inside if it matches
				{
					FoodNode* tempprev = NULL; //initialize a new temp node
					FoodNode* tempnext = NULL; //initialize a new temp node
					if (temp->previous) //if temp's previous exists
					{
						tempprev = temp->previous; //set tempprev to temp's previous
					}
					if (temp->next) //if temp's next exists
					{
						tempnext = temp->next; //set tempnext to temp's next
					}
					if (tempprev && tempnext) //if both were set
					{
						tempprev->next = tempnext; //change pointers so that they point correctly
						tempnext->previous = tempprev;
						head = tempprev; //head now excludes temp
					}
					else if (tempprev && !tempnext) //if only tempprev exists
					{
						tempprev->next = NULL; //change pointers accordingly
						head = tempprev; //head now excludes temp
					}
					else if (!tempprev && tempnext) //if only tempnext exists
					{
						tempnext->previous = NULL; //change pointers accordingly
						head = tempnext; //head now excludes temp
					}
					else if (!tempprev && !tempnext) //if neither exist
					{
						head = NULL; //head is empty
					}
					delete temp; //deletes temp
					cout << f << " was successfully deleted from the list.\n";
					founditem = true; //switches flag for finding the item
					return; //stops search
				}
				temp = temp->next; //increments temp to search all of head
			}
		}
		if (!tailempty()) //if tail is nonempty continue
		{
			FoodNode* temp = tail; //creates a new temp to search all of tail
			while (temp) //while temp is nonempty
			{
				if (f.compare((temp->food).getFood()) == 0) //compares passed f to food value of temp and continues inside if it matches
				{
					FoodNode* tempprev = NULL; //initialize new temp node
					FoodNode* tempnext = NULL; //initialize new temp node
					if (temp->previous) //if temp's previous exists
					{
						tempprev = temp->previous; //set tempprev to temp's previous
					}
					if (temp->next) //if temp's next exists
					{
						tempnext = temp->next; //set tempnext to temp's next
					}
					if (tempprev && tempnext) //if both were set
					{
						tempprev->next = tempnext; //change pointers accordingly
						tempnext->previous = tempprev;
						tail = tempnext; //sets tail accordingly
					}
					else if (tempprev && !tempnext) //if only tempprev exists
					{
						tempprev->next = NULL; //change pointer accordingly
						tail = tempprev; //sets tail accordingly
					}
					else if (!tempprev && tempnext) //if only tempnext exists
					{
						tempnext->previous = NULL; //change pointer accordingly
						tail = tempnext; //sets tail accordingly
					}
					else if (!tempprev && !tempnext) //if neither exist
					{
						tail = NULL; //tail is empty
					}
					delete temp; //deletes temp from the list
					cout << f << " was successfully deleted from the list.\n";
					founditem = true; //switches flag for item found
					return; //stops search
				}
				temp = temp->previous; //increments temp to search all of tail
			}
		}
	}
	if (!founditem) //if the item was not found
	{
		cout << "That food item was not found in the list.\n";
	}
}

void FoodList::removeFront() //this is used to delete both lists
{
	if (!headempty()) //if head is nonempty
	{
		FoodNode* temp = head; //creates a new temp for moving head
		head = temp->next; //sets head equal to the next node
		delete temp; //deletes temp
	}
	if (!tailempty()) //if tail is nonempty
	{
		FoodNode* temp = tail; //creates a new temp for moving tail
		tail = temp->previous; //sets tail equal to previous node
		delete temp; //deletes temp
	}
}

void FoodList::displayList() const //function used to display the lists in order (front at top, back at bottom)
{
	if (!headempty() || !tailempty()) //if either head or tail are nonempty
	{
		cout << "The following food is in the list: \n";
		if (!headempty()) //if head is nonempty
		{
			FoodNode* temp = head; //creates new temp to display all of head
			while (temp) //while temp is nonempty
			{
				temp->food.print(); //prints food values of temp
				temp = temp->next; //increments temp
			}
		}
		if (!tailempty()) //if tail is nonempty
		{
			FoodNode* temp = tail; //creates new temp to display all of tail
			while (temp->previous) //while temp has a previous value
			{
				temp = temp->previous; //goes to the front of tail
			}
			while (temp) //while temp is nonempty
			{
				temp->food.print(); //prints food values of temp
				temp = temp->next; //increments temp
			}
		}
	}
	else //if both are empty
	{
		cout << "There is no food in the list.\n";
	}
}