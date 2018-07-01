// This is the catalogue class implementation file

#include "Product.h"

// Function definitions

Product::Product() {

	setName("");
	setPrice(0.00);
	setQuantity(0);
}

Product::Product(string theName, double thePrice) {

	setName(theName);
	setPrice(thePrice);
	setQuantity(0);
}

string Product::getName() const {
	return name;
}

double Product::getPrice() const {
	return price;
}

int Product::getQuantity() const {
	return quantity;
}

void Product::setName(string theName) {
	name = theName;
}

void Product::setPrice(double thePrice) {
	price = thePrice;
}

void Product::setQuantity(int theQuant) {
	quantity = theQuant;
}

ostream &operator << (ostream& out, const Product& theProduct) // this sneaky function! whaaat?
{
	cout << "Name: " << theProduct.name << endl
		<< fixed << setprecision(2)
		<< "Price: $" <<  theProduct.price << endl
		<< "Quantity: " << theProduct.quantity << endl;

	return out;
}