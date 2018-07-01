#include "Node.h"

// This class is based on the definition on page 118
// in our textbook.

class SinglyLinkedList 
{			
  public:
    SinglyLinkedList();				// Empty list constructor.
    ~SinglyLinkedList();			// Destructor.
    bool empty() const;				// Is list empty?
    const Book& front() const;		// Get front element in list.
    void addFront(const Book& e);	// Add to front of list.
    void removeFront();				// Remove front item list.
	void displayList() const;		// Display list of books.
  private:
    Node* head;						// Pointer to the head of list
  };
