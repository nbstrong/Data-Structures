#include "Book.h"

// This class is based on the definition on page 118
// in our textbook.

class Node					// Node for Book class.
{				
  private:
    Book book;				// The book element in this node. 
    Node* next;				// A self-referential pointer
							// or node pointer
							// pointing to the next item in the list.

	// The list needs access to this Node class.
	// Access is provided by friend declaration.
    friend class SinglyLinkedList;		
};
