#include <iostream> //allows using input/output
#include <string> //allows using strings

using namespace std;

#ifndef Food_H //protects from multiple declarations
#define Food_H

class Food //class that holds Food properties and functions
{
	friend ostream &operator << (ostream& out, const Food& theFood); //allows cout of Food
public:
	Food(); //constructor
	Food(string food, double price); //constructor
	string getFood() const; //returns food
	void setFood(string food); //sets food
	double getPrice() const; //returns price
	void setPrice(double price); //sets price
	void print(); //displays values
private:
	string food; //food value of objects
	double price; //price value of objects
};
#endif