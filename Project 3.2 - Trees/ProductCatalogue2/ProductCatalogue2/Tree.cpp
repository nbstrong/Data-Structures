// This is the tree class implementation file

#include "Tree.h"

// Constructor
Tree::Tree() {
	root = NULL;
}

// Destructor
Tree::~Tree() {
	freeNode(root);
}

// Free the node
void Tree::freeNode(Node* node) {
	if (node != NULL) {
		freeNode(node->left);
		freeNode(node->right);
		delete node;
	}
}