// This is the class declaration file

#include <iostream>
#include <queue>
#include <string>

using namespace std;

#ifndef Product_H
#define Product_H

class Product {
	friend ostream &operator << (ostream& out, const Product& theProduct);
public:
	Product();
	Product(string theName, double thePrice);

	string getName() const;
	double getPrice() const;
	int getQuantity() const;
	void setName(string theName);
	void setPrice(double thePrice);
	void setQuantity(int thequant);

private:
	string name;
	double price;
	int quantity;
};

#endif

