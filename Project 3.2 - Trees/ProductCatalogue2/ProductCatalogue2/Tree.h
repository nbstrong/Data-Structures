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
	

	//void levelOrder(Node* n);
	//void Inorder(Node* node);
	//void Postorder(Node*);
	//void Preorder(Node* node);
	//void displayNode(Node* node);
private:

};
