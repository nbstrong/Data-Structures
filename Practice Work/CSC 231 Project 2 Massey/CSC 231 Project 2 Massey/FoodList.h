#include "FoodNode.h" //includes FoodNode class

class FoodList //class that holds list properties and functions
{
public:
	FoodList(); //constructor
	~FoodList(); //destructor
	bool headempty() const; //checks if head is empty
	bool tailempty() const; //checks if tail is empty
	void addFront(const Food& e); //adds node to front
	void addBack(const Food& e); //adds node to back
	void searchItem(string food); //searches for node
	void editItem(string food, string name, double price); //edits a node
	void removeItem(string food); //removes a node
	void removeFront(); //deletes front node
	void displayList() const; //displays all nodes in order
private:
	FoodNode* head; //node used to point to other nodes
	FoodNode* tail; //node used to point to other nodes
};