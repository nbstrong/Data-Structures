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
	root = NULL;
}

// Add a node. I realized later this function could be combined with
// the one below it but now it's too late baby.
void Tree::addNode(const Product& x) {
	// No elements. Add to the root position.
	if (root == NULL) {
		cout << "<Adding root node " << x.getName() << ">" << endl;
		Node* n = new Node();
		n->productdata = x;
		n->key = x.getName();
		root = n;
	}
	// Otherwise traverse to the correct position.
	else {
		addNode(x, root);
	}
}

// Add a node using recursion.
void Tree::addNode(const Product& x, Node* node) {
	if (x.getName() <= node->key) { // If less go left
		if (node->left != NULL) { // Keep searching recursively until empty
			//cout << "< Traversing left>" << endl;
			addNode(x, node->left);
		}
		else { // Add node into empty correct position.
			cout << "<Adding new node " << x.getName() << " to left>" << endl;
			Node* n = new Node();
			n->productdata = x;
			n->key = x.getName();
			node->left = n;
		}
	}
	else { // Else go right
		if (node->right != NULL) { // Keep searching recursively until empty
			//cout << "<Traversing right>" << endl;
			addNode(x, node->right);
		}
		else { // Add node into empty correct position
			cout << "<Adding new node " << x.getName() << " to right>" << endl;
			Node* n = new Node();
			n->productdata = x;
			n->key = x.getName();
			node->right = n;
		}
	}
}

// Rewrote this function four times until I finally got it right
Node* Tree::searchTree(string search, Node* node) {
	if (node != NULL) {
		if (search < node->key) {
			return searchTree(search, node->left);
		}
		if (search == node->key) {
			return node;
		}
		else {
			return searchTree(search, node->right);
		}
	}
	else return NULL;
}

// Traversal for displaying product tree
void Tree::Inorder(Node* node) {
	if (node != NULL) {
		Inorder(node->left);
		displayNode(node);
		Inorder(node->right);
	}
}

// Traversal for displaying order tree
void Tree::Preorder(Node* node) {
	if (node!= NULL) {
		displayNode(node);
		Preorder(node->left);
		Preorder(node->right);
	}
}

// Prints menu for editing a node
void Tree::editTree(Node* node) {
	if (node == NULL) {
		return;
	}
	bool stop = false;
	while (stop == false) {
		int choice = 0;
		cout << "<Displaying Edit Menu>" << endl;
		cout << "What element would you like to edit?\n"
			<< "---------------------------------------------------------------------\n"
			<< "\t1\t Name\n"
			<< "\t2\t Price\n"
			<< "\t3\t Stop editing\n"
			<< "---------------------------------------------------------------------\n\n"
			<< "Enter your choice : \n\n";
		cin >> choice;
		switch (choice) {
		case 1: {
			string name;
			cout << "Enter new name: " << endl;
			cin >> name;
			node->productdata.setName(name);
			node->key = node->productdata.getName();
			cout << "<New name set: " << name << ">" << endl;
			cout << "<New key set: " << node->key << ">" << endl;
			break;
		}
		case 2: {
			double price;
			cout << "Enter new price: " << endl;
			cin >> price;
			node->productdata.setPrice(price);
			cout << "<New price set: " << price << ">" << endl;
			break;
		}
		default: {
			stop = true;
			break;
		}
		}
	}
}

// This function literally took me 3 days until I decided to just straight
// up take it from Sakai. Im sorry but not really. It was a headache.
Node* Tree::DeleteNode(Node* node, string key) {
	if (node == NULL) return node;
	else if (key < node->key) node->left = DeleteNode(node->left, key);
	else if (key > node->key) node->right = DeleteNode(node->right, key);
	else {
		if (node->left == NULL && node->right == NULL) {
			node = NULL;
			delete node;
		}
		else if (node->left == NULL) {
			Node* temp = node;
			node = node->right;
			delete temp;
		}
		else if (node->right == NULL) {
			Node* temp = node;
			node = node->left;
			delete temp;
		}
		else {
			Node* temp = FindMin(node->right);
			node->productdata = temp->productdata;
			node->key = temp->key;
			node->right = DeleteNode(node->right, temp->key);
		}
	}
	return node;
}



void Tree::displayNode(Node* node) {
	if (node != NULL) {
		cout << node->productdata << endl;
	}
	else if (node == NULL) {
		cout << "Product not found" << endl;
	}
}

Node* Tree::FindMin(Node* node)
{
	while (node->left != NULL) node = node->left;
	return node;
}

// Outputs object data to file
void Tree::displayNode2(Node* node, ofstream& TxtObject) {
	if (node != NULL) {
		if (node == root) {
			TxtObject << node->productdata.getName() << "\t"
				<< node->productdata.getPrice() << "\t"
				<< "0";
		}
		else if (node->productdata.getName() != "") {
			TxtObject << node->productdata.getName() << "\t"
				<< node->productdata.getPrice() << "\t"
				<< "0\n";
		}
	}
}

// traversal for file export
void Tree::Postorder(Node* node, ofstream& TxtObject) {
	if (node != NULL) {
		Postorder(node->left, TxtObject);
		Postorder(node->right, TxtObject);
		displayNode2(node, TxtObject);
	}
}

// runs file operations and calls postorder for output
void Tree::exportTree(Node* node) {
	cout << "<Exporting Catalogue>" << endl;
	ofstream TxtObject("productlist.txt", ios::out);

	if (!TxtObject) {
		cerr << "<File not found>" << endl;
		exit(1); // End program with errors
	}

	if (TxtObject.is_open()) {
		Postorder(node, TxtObject);
	}

	TxtObject.close();

}

