#include <iostream>
#include <string>

using namespace std;

#ifndef FCNSTree_H
#define FCNSTree_H

class Node 
{
	friend class Organization;
private:
	string name;
	Node *supervisor;		// Parent, upper level.
	Node *firstSupervisee;	// First child, lower level.
	Node *nextPeer;			// Node that same level, also implementable as singlylinkedlist.	
	Node();
	Node(string theName, Node* theSupervisor);
	bool isPresident() { return supervisor == NULL; };
	int getDepth(); 	
};															

class Organization
{	
private:
	Node* president;		// Highest rank or root node.
	Node* searchNode;		// A node used for finding the supervisor.
	int height;				// The height of the organizational tree.
public:
	Organization();
	Organization(string thePresidentName);
	int getHeight();
	void add(string theSupervisorName, string theName);
	Node* find(string theName);	// Finds an employee's node.
	void findTraversal(string theName, Node* node);
	void display();
	void displayTraversal(Node* node);
	void displayInOutline();
	void displayInOutline(Node* node);	
	void displayByRank();
	void displayByRank(Node* node, int theDepth);	
	void displaySiblings(string theName);
	//void displayChildren(...
	//void displaySupervisors(...
	//void displaySubordinates(...
    void setPresident(string thePresidentName);	
	~Organization();
};

#endif
