// This is the node declaration file

#include "Product.h"

class Node {
	string key;
	Product productdata;
	Node* left;
	Node* right;
	friend class Tree;
public:
	Node() { key = "-1"; left = NULL; right = NULL; };
};