#include "FCNSTree.h"

// Constructors.
Node::Node() 
{
	name = "";
	supervisor = NULL;
	firstSupervisee = NULL;
	nextPeer = NULL;
}

Node::Node(string theName, Node* theSupervisor) 
{
	name = theName;	
	supervisor = theSupervisor; 
	firstSupervisee = NULL;		
	nextPeer = NULL;
}

// Utility methods for Node class.
int Node::getDepth()
{ 
	int theDepth = 0;
	Node *node = this; 
	while ( ! node->isPresident() )
	{
		node = node->supervisor;
		theDepth++;
	}
	return theDepth;
}

// Constructors.
Organization::Organization()
{
	president = NULL;
	height = 0;
}

Organization::Organization(string thePresidentName) 
{
	president = new Node(); 
	president->name = thePresidentName;
	height = 1;
}

// Find methods.
Node* Organization::find(string theName) 
{
	searchNode = NULL;
	findTraversal(theName, president);
	return searchNode; 
}

void Organization::findTraversal(string theName, Node* node) 
{
	if (node) 
	{
		// When the name in the node matches
		// theName, then we have found the search node we need.
		if (node->name.compare(theName) == 0)
		{
			searchNode = node; 
		}
		findTraversal(theName, node->nextPeer);
		findTraversal(theName, node->firstSupervisee);
	}
}

void Organization::add(string theName, string theSupervisor) 
{
	Node *supervisorNode = find(theSupervisor);			// Find the supervisor of the employee.
	if (supervisorNode)									// If the supervisor is found,  
	{													// then set up new node.
		Node* newNode = new Node(theName, supervisorNode);	// Create new node.
		if (supervisorNode->firstSupervisee == NULL)	// If the employee will be the first supervisee,
		{												// then add as the first supervisee.
			supervisorNode->firstSupervisee = newNode;
		}
		else											// Otherwise add employee as the last sibling
		{												// of the first supervisee of the supervisor.
			Node *walkerNode = supervisorNode->firstSupervisee;
			while (walkerNode->nextPeer) 
			{
				walkerNode = walkerNode->nextPeer;
			}											// Find the sibling position that's NULL and add there.
			walkerNode->nextPeer = newNode;
		}
		if (newNode->getDepth() >= height)				// Update height of organization tree if needed.
		{
			height = newNode->getDepth() + 1;
		}
	}
	else
	{
		cout << theName + " was not added. Supervisor was not found!" << endl;		// Display error.
	}	
}

// Display methods.
void Organization::displayTraversal(Node* node) 
{
	if (node) 
	{
		cout << node->name << endl;
		displayTraversal(node->nextPeer);
		displayTraversal(node->firstSupervisee);
	}
}

void Organization::display() 
{
	if (president)
	{
		displayTraversal(president);
	}
}

// Use pre-order traversal to display employees in an outline
// with indentation based on position in organizational chart.
void Organization::displayInOutline(Node* node) 
{
	if (node) 
	{			
		// Pre-order visit.
		int theDepth = node->getDepth();	// Determine node level or rank.
		string indent = "";					// Create indentation based on rank.
		for (int i = 0; i <= theDepth; i++)	
		{
			indent += "   ";
		}
		cout << indent << node->name << endl;		// Display employee.
		// Recursive traversal calls.
		displayInOutline(node->firstSupervisee);	
		displayInOutline(node->nextPeer);		
	}
}

void Organization::displayInOutline() 
{
	if (president)
	{
		displayInOutline(president);
	}
}

void Organization::displayByRank() 
{
	for (int theDepth = 0; theDepth < height; theDepth++)		
	{
		cout << "***** Level " << (theDepth + 1) << " *****" << endl;
		displayByRank(president, theDepth);		
	}	
}

void Organization::displayByRank(Node* node, int theDepth) 
{
	if (node) 
	{
		if (node->getDepth() == theDepth)
		{
			cout << node->name << endl;
		}
		displayByRank(node->nextPeer, theDepth);
		displayByRank(node->firstSupervisee, theDepth);
	}
}

// Example code for displays.
void Organization::displaySiblings(string theName)
{
	cout << "Team members of " << theName << ":\n";
	find(theName);
	Node* walker = searchNode->supervisor->firstSupervisee;
	while (walker)
	{
		if (walker->name != theName)
		{
			cout << walker->name << endl;
		}
		walker = walker->nextPeer;
	}
}

/*
// Let's code.
void Organization::displayChildren(...
{

}
*/

int Organization::getHeight()
{
	return height;
}

void Organization::setPresident(string thePresidentName)
{
    president->name = thePresidentName;
	if (height < 1)				// Update height of organization tree if needed.
	{
		height = 1;
	}
}

// Let's code (traverse tree for an orderly destruction of the organization tree).
Organization::~Organization()
{
}
