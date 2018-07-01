// This is the tree class declaration file

#include "Node.h"

class Tree {
	Node* root;
public:
	Tree();
	~Tree();
	void freeNode(Node* leaf);
	Node* Root() { return root; };
	void addNode(const Product& x);
	Node* searchTree(string search, Node* node);
	void Inorder(Node* node);
	void Preorder(Node* node);
	void Postorder(Node* node, ofstream& TxtObject);
	void editTree(Node* node);
	Node* DeleteNode(Node* node, string key);
	void exportTree(Node* node);

	void displayNode(Node* node);
	void displayNode2(Node* node, ofstream& TxtObject);
	Node* Tree::FindMin(Node* root);
private:
	void addNode(const Product& x, Node* leaf);

};