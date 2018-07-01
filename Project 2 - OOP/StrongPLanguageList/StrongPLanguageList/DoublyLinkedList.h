// This is the class declaration header file for the list class

#include "PLanguageNode.h"

// This class is based on the definition on page 118
// in our textbook.

class DoublyLinkedList
{
public:
	DoublyLinkedList();				// Empty list constructor.
	~DoublyLinkedList();			// Destructor.
	bool empty() const;				// Is list empty?
	const PLanguage& front() const;		// Alias to get get front element in list.
	void addFront(const PLanguage& x);	// Add to front of list.
	void addBack(const PLanguage& x);	// Add to the back of the list.
	void searchList(string search);					// Search for a specific language
	void editList(Node*& tempNode);					// Edit a language
	void removeAny(Node* tempNode);				// Remove front item list.
	void displayList() const;		// Display list of languages.
private:
	Node* head;						// Pointer to the head of list
	Node* tail;						// Pointer to the tail of list
};