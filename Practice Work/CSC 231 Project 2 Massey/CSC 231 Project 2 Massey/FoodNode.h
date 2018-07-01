#include "Food.h" //includes Food class

class FoodNode //class that holds node properties
{
private:
	Food food; //each node has a food data object
	FoodNode* next; //each node has a pointer to the next node
	FoodNode* previous; //each node has a pointer to the previous node
	
	friend class FoodList; //allows friend access to FoodList class
};