#include "Food.h" //contains function and variable declarations for the class

Food::Food() //simple constructor for an object
{
	setFood(""); //sets food value as blank
	setPrice(0); //sets price as 0
}

Food::Food(string food, double price) //constructor for an object
{
	setFood(food); //sets food value to passed food
	setPrice(price); //sets price value to passed price
}

string Food::getFood() const //returns food value of object
{ 
	return food;
}

void Food::setFood(string thefood) //sets food value of certain object to passed thefood
{
	food = thefood;
}

double Food::getPrice() const //returns price value of object
{
	return price;
}

void Food::setPrice(double theprice) //sets price value of certain object to passed theprice
{
	price = theprice;
}

void Food::print() //prints values of certain object
{
	cout << food << " costs " << price << endl;
}

ostream &operator << (ostream& out, const Food& theFood) //allows using cout << Food Object
{
	out << theFood.food << " costs " << theFood.price;
	return out;
}