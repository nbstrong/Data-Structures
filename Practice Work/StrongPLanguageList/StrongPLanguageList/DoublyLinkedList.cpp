// This is the class implementation file for the list class

#include "DoublyLinkedList.h"

// This class is based on the definition on page 118
// in our textbook.

// Constructors. Only default constructor is needed for new empty list. 
DoublyLinkedList::DoublyLinkedList() {
	head = NULL;
	tail = NULL;
}


// Destructor deletes object and code removes garbage.
DoublyLinkedList::~DoublyLinkedList()
{
	while (!empty())
	{
		Node* tempNode = head;
		head = tempNode->prev;
		removeAny(tempNode);
	}
}

// Is list empty?
bool DoublyLinkedList::empty() const
{
	return (head == NULL);
}

// Get front node.
const PLanguage& DoublyLinkedList::front() const
{
	return head->languagedata;
}

// Add node to front.
void DoublyLinkedList::addFront(const PLanguage& x)
{
	if (empty()) {
		cout << "<Creating node at front of empty list>" << endl;
		Node* tempNode = new Node;			// Create new node.
		tempNode->languagedata = x;			// Store data.
		tempNode->next = NULL;				// Set pointers to null because empty list
		tempNode->prev = NULL;				
		head = tempNode;					// Our new node is now the new head.
		tail = tempNode;					// Our new node is also the new tail because empty
	}
	else {
		cout << "<Creating node at front of list>" << endl;
		Node* tempNode = new Node;			// Create new node.
		tempNode->languagedata = x;			// Store data.
		tempNode->next = NULL;				// Set next to null because head
		tempNode->prev = head;				// Set prev to old head
		head->next = tempNode;				// Change old head's next to point to us
		head = tempNode;					// New node is now head
	}
}

void DoublyLinkedList::addBack(const PLanguage& x)
{
	if (empty()) {
		cout << "<Creating node at back of empty list>" << endl;
		Node* tempNode = new Node;			// Create new node.
		tempNode->languagedata = x;			// Store data.
		tempNode->next = NULL;				// Set pointers to NULL because empty list
		tempNode->prev = NULL;				
		head = tempNode;					// Our new node is now the new head...
		tail = tempNode;					// and the new tail (I suppose since this is the
											// exact same code as addFront when empty they could
											// be combined but oh well
	}
	else {
		cout << "<Creating node at back of list>" << endl;
		Node* tempNode = new Node;			// Create new node.
		tempNode->languagedata = x;			// Store data.
		tempNode->next = tail;				// Tempnode's next points to old tail.
		tempNode->prev = NULL;				// Prev points to empty because tail.
		tail->prev = tempNode;				// Old tail's prev points to us.
		tail = tempNode;					// Our new node is now the new tail.
	}
}

void DoublyLinkedList::searchList(string search) // Search and edit an item in the list
{
	if (!empty()) // If node is not empty
	{
		Node* tempNode = head;	// Create temp node and point to head
		bool found = false;		// Flag for found or not
		while (found == false)
		{
			while (tempNode)	// temp evaluates to true if it is not NULL.
			{
				if (search == tempNode->languagedata.getName()) // compare search string to name of language
				{
					found = true;
					char choice = 'n';
					cout << tempNode->languagedata << endl; // Display single node's data
					cout << "Would you like to edit this node y/n?" << endl;
					cin >> choice;
					if (choice == 'y') {
						editList(tempNode);
					}
					return;
				}
				tempNode = tempNode->prev;	// Move to the next node, which if it's NULL
			}								// will cause the loop to terminate.	
			cout << "No language found with " << search << endl;
			break;
		}
	}
	else
	{
		cout << "There are no languages in this list.\n";
	}
}

void DoublyLinkedList::editList(Node*& tempNode) {
	bool stop = false;
	while (stop == false) {
		int choice = 0;
		cout << "<Displaying Edit Menu>" << endl;
		cout << "What element would you like to edit?\n"
			<< "---------------------------------------------------------------------\n"
			<< "\t1\t Name\n"
			<< "\t2\t Level\n"
			<< "\t3\t Author\n"
			<< "\t4\t Date\n"
			<< "\t5\t Delete node\n"
			<< "\t6\t Stop editing\n"
			<< "---------------------------------------------------------------------\n\n"
			<< "Enter your choice : \n\n";
		cin >> choice;
		switch (choice) {
		case 1: {
			string name;
			cout << "Enter new name: " << endl;
			cin >> name;
			tempNode->languagedata.setName(name);
			cout << "<New name set: " << name << ">" << endl;
			break;
		}
		case 2: {
			string level;
			cout << "Enter new level: " << endl;
			cin >> level;
			tempNode->languagedata.setLevel(level);
			cout << "<New level set: " << level << ">" << endl;
			break;
		}
		case 3: {
			string author;
			cout << "Enter new author: " << endl;
			cin >> author;
			tempNode->languagedata.setAuthor(author);
			cout << "<New author set: " << author << ">" << endl;
			break;
		}
		case 4: {
			int date;
			cout << "Enter new start date: " << endl;
			cin >> date;
			tempNode->languagedata.setStartYear(date);
			cout << "<New start date set: " << date << ">" << endl;
			break;
		}
		case 5: {
			if (!empty())
			{
				removeAny(tempNode);					// Delete this node
			}
		}
		default: {
			stop = true;
			break;
		}
		}
	}
}

// Remove node from front.
void DoublyLinkedList::removeAny(Node* tempNode)
{
	if ( tempNode->next == NULL && tempNode->prev == NULL) { // If head and tail
		cout << "<Deleting Head/Tail: " << tempNode->languagedata.getName() << ">" << endl;
		delete tempNode;		// If the node is both head and tail, delete the node
		head = NULL;			// and null the pointers
		tail = NULL;
		return;
	}
	else if (tempNode->next == NULL) {			// If head
		cout << "<Deleting Head: " << tempNode->languagedata.getName() << ">" << endl;
		head = tempNode->prev;					// Prev node is now head
		tempNode->prev->next = NULL;			// Prev node's next is null
		tempNode->prev = NULL;					// Our prev nulled out
		delete tempNode;						// Delete the node
		return;
	}
	else if (tempNode->prev == NULL) {			// If tail
		cout << "<Deleting Tail: " << tempNode->languagedata.getName() << ">" << endl;
		tail = tempNode->next;					// Next node is now tail 
		tempNode->next->prev = NULL;			// Next node's prev nulled
		tempNode->next = NULL;					// Our next nulled
		delete tempNode;						// Delete the node
		return;
	}
	else {											// If neither
		cout << "<Deleting: " << tempNode->languagedata.getName() << ">" << endl;
		tempNode->next->prev = tempNode->prev;		// Next node's prev points to our prev
		tempNode->prev->next = tempNode->next;		// Prev node's next points to our next
		tempNode->next = NULL;						// Null next and prev
		tempNode->prev = NULL;
		delete tempNode;							// Delete node
		return;
	}
}

void DoublyLinkedList::displayList() const
{
	if (!empty())
	{
		cout << "<Displaying List>" << endl;
		cout << "The following programming languages are in this list:" << endl;
		Node* tempNode = head;
		while (tempNode)	// temp evaluates to true if it is not NULL.
		{
			cout << tempNode->languagedata << endl;
			tempNode = tempNode->prev;	// Move to the next node, which if it's NULL
		}								// will cause the loop to terminate.	   
		cout << endl;
	}
	else
	{
		cout << "There are no languages in this list.\n";
	}
}