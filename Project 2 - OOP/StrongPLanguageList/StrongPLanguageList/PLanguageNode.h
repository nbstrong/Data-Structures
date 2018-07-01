// This is the class declaration header file for the node class

#include "PLanguage.h"

// This class is based on the definition on page 118
// in our textbook.

class Node					// Node to hold PLanguage class.
{
private:
	PLanguage languagedata;				// The language element in this node.
	Node* next;				// A self-referential pointer
							// or node pointer
							// pointing to the next item in the list.
	Node* prev;				// Pointer to previous node
							// The list needs access to this Node class.
							// Access is provided by friend declaration.
	friend class DoublyLinkedList;
};