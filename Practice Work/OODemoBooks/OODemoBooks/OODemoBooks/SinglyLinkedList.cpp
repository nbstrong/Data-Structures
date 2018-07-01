#include "SinglyLinkedList.h"

// This class is based on the definition on page 118
// in our textbook.

// Constructors. Only default constructor is needed for new empty list. 
  SinglyLinkedList::SinglyLinkedList()
	: head(NULL) { }
  

  // Destructor deletes object and code removes garbage.
  SinglyLinkedList::~SinglyLinkedList()
  { 
	  while (!empty()) 
	  {
			removeFront(); 
	  }
  }

  // Is list empty?
  bool SinglyLinkedList::empty() const			
  { 
	  return (head == NULL); 
  }

  // Get front node.
  const Book& SinglyLinkedList::front() const		
  { 
	  return head->book; 
  }

  // Add node to front.
  void SinglyLinkedList::addFront(const Book& e) 
  {	
    Node* temp = new Node;			// Create new node.
    temp->book = e;					// Store data.
    temp->next = head;				// Current head is now next of our new node.
    head = temp;					// Our new node is now the new head.
  }

	// Remove node from front.
   void SinglyLinkedList::removeFront() 
   {
	   if ( !empty() ) 
	   {
			Node* temp = head;				// temp saves the current head.
			head = temp->next;				// Our new head is the old head's next. 
			delete temp;					// Delete the previous head.
	   }
   }

   void SinglyLinkedList::displayList() const
   {
	   if ( !empty() )
	   {
		   cout << "The following books are in this list:\n";
		   Node* temp = head;	   
		   while (temp)	// temp evaluates to true if it is not NULL.
		   {
			   cout << temp->book << endl;
			   temp = temp->next;	// Move to the next node, which if it's NULL
		   }						// will cause the loop to terminate.	   
		   cout << endl;
	   }
	   else
	   {
		   cout << "There are no books in this list.\n";
	   }
   }