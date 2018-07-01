// Code based on http://www.cplusplus.com/forum/beginner/131457/
// Demonstrates tree traversals in a binary tree.

#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Node class
class Node 
{
    string key;
    Node* left;
    Node* right;
	friend class Tree;
public:
    Node() { key = "-1"; left = NULL; right = NULL; };
};

// Tree class
class Tree 
{
    Node* root;	
public:
    Tree();
    ~Tree();
    Node* Root() { return root; };
    void addNode(string theKey);
    void levelOrder(Node* n);
    void Inorder(Node* );
	void Postorder(Node* );
    void Preorder(Node* node);
private:
    void addNode(string theKey, Node* leaf);
    void freeNode(Node* leaf);
};

// Constructor
Tree::Tree() 
{
     root = NULL;
}

// Destructor.
Tree::~Tree() 
{
     freeNode(root);
}

// Free the node.
// What kind of traversal is this? Post-order.
void Tree::freeNode(Node* leaf)
{
    if ( leaf != NULL )
    {
       freeNode(leaf->left);
       freeNode(leaf->right);
       delete leaf;
    }
} 

// Add a node.
void Tree::addNode(string theKey) 
{
     // No elements. Add to the root position.
     if ( root == NULL ) 
	 {
        cout << "Add root node ... " << theKey << endl;
        Node* n = new Node();
        n->key = theKey;
		root = n;
     }
     else // Otherwise traverse to the correct position.
	 {
		cout << "Add new node ... " << theKey << endl;
		addNode(theKey, root);
     }
}

// Add a node using recursion.
void Tree::addNode(string theKey, Node* leaf) 
{
    
	if ( theKey <= leaf->key ) // If less, go left.
	{
       if ( leaf->left != NULL )	// Keep searching recursively until empty node position.
	   {
			addNode(theKey, leaf->left);
	   }
       else							// Add node into empty correct position.
	   {
			Node* n = new Node();
			n->key = theKey;
			leaf->left = n;
       }
    }
    else 
	{
		if ( leaf->right != NULL )	// Keep searching recursively until empty node position.
		{
			addNode(theKey, leaf->right);
		}
		else						// Add node into empty correct position.
		{
			Node* n = new Node();
			n->key = theKey;
			leaf->right = n;
		}
    }
}

// Print the tree level-order assisted by queue
void Tree::levelOrder(Node* n) 
{
   // Create a queue
   queue<Node*> q;

   // Push the root
   q.push(n);

   while ( ! q.empty() )
   {
       // Dequeue a node from front
       Node* v = q.front();
       cout << v->key << endl;

       // Enqueue the left children
       if ( v->left != NULL )
	   {
            q.push(v->left);
	   }

       // Enqueue the right children
       if ( v->right != NULL )
	   {
            q.push(v->right);
	   }

       // Pop the visited node
       q.pop();
   }
}

void Tree::Preorder(Node* node)
{
    if ( node )
    {
        cout << node->key << endl;
        Preorder(node->left);
        Preorder(node->right);
    }
}

void Tree:: Inorder(Node* node)
{
    if(node != NULL)
    {
        Inorder(node->left);
        cout << node->key << endl;
        Inorder(node->right);
    }
}

void Tree:: Postorder(Node* node)
{
    if(node != NULL)
    {
        Postorder(node->left);
        Postorder(node->right);
        cout << node->key << endl;
    }
}

// Test main program
int main() 
{
	Tree* tree = new Tree();
	tree->addNode("F");
	tree->addNode("E");
	tree->addNode("K");
    tree->addNode("J");    
    tree->addNode("L");
	tree->addNode("B");
	tree->addNode("A");    
    tree->addNode("H");
    tree->addNode("I");
    tree->addNode("G");
    tree->addNode("C");
    tree->addNode("D");

	cout << "\nLevel order traversal" << endl;
	tree->levelOrder(tree->Root());
	cout << endl;

	cout << "\nPre order traversal" << endl;
	tree->Preorder(tree->Root());
    cout << endl;
	
	cout << "\nIn order traversal" << endl;
    tree->Inorder(tree->Root());
    cout << endl;

	cout << "\nPost order traversal" << endl;
    tree->Postorder(tree->Root());
    cout << endl;

	system("pause");

	delete tree;
	return 0;
}