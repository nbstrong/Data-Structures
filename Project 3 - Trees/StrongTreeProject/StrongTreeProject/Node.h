// This is the node declaration file

#include "Product.h"

class Node {
	//Product productdata;
	Node* left;
	Node* right;
	friend class Tree;
public:
	string key;
	Product productdata;
	Node() { key = "-1"; left = NULL; right = NULL;};
};