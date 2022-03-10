#include "bintree.h"

//--------------------------------------------------------------------------
// BinTree (constructor)
/*Constructor for Bintree doesn't take any values and simply sets the root
of the tree to nullptr*/
BinTree::BinTree() 
{
	root = nullptr;
	name = "";
}
// BinTree (constructor)
//Constructor for Bintree sets name, and sets root to nullptr
BinTree::BinTree(string nameForTree)
{
	root = nullptr;
	name = nameForTree;
}
//--------------------------------------------------------------------------
// destructor
/* destructor for BinTree, deletes all memory in the tree including
all data in each node*/
BinTree::~BinTree()
{
	makeEmpty();
}

//--------------------------------------------------------------------------
// makeEmpty
/* makeEmpty deletes all memory in the tree including the date in each node
through a postorder traversal of the tree*/
void BinTree::makeEmpty()
{
	makeEmptyHelper(root);
	root = nullptr;
}
void BinTree::makeEmptyHelper(Node* current)
{
	if (current == nullptr) 
	{
		return;
	}
	makeEmptyHelper(current->left);
	makeEmptyHelper(current->right);

	//Delete the data then the node itself
	delete current->data;
	current->data = nullptr;
	delete current;
	current = nullptr;
	return;
}

//--------------------------------------------------------------------------
// isEmpty
/* isEmpty returns true if the tree has no nodes in it.
false is returned otherwise*/
bool BinTree::isEmpty() const
{
	return (root == nullptr);
}

string BinTree::getName() const
{
	return name;
}


//--------------------------------------------------------------------------
// insert
/* given a pointer to NodeData, this method creates a new node
in the tree to store the inserted data. A copy is not made of the data
this is an iterative implementation7*/
bool BinTree::insert(Media* ins_data)
{
    if (root == nullptr) //inserting root
	{	
        root = new Node;
		root->data = ins_data;
        return true;
    }

	/*parent is used so that the left or right pointer of the 
	parent can be updated*/
    Node* curr = root;
    Node* parent = nullptr;

	//traverse until insert location is found
	while (curr != nullptr && *(curr->data) != *(ins_data))
	{
		parent = curr;
		if (*(ins_data) < *(curr->data))
		{
			curr = curr->left;
		}
		else
		{
			curr = curr->right;
		}
	}
	
	if (parent == nullptr)
	{
		return false;
	}
	// no duplicates
	else if ((curr != nullptr) && (*(curr->data) == *(ins_data)))
	{
		return false;
	}//insert left
	else if (*(ins_data) < *(parent->data))
	{
		parent->left = new Node;
		parent->left->data = ins_data;
		return true;
	}
	//insert right
	else
	{
		parent->right = new Node;
		parent->right->data = ins_data;
		return true;
	}
}

//--------------------------------------------------------------------------
// retrieve
/* retrieve finds the data you are looking for within the tree. The first
parameter is the data you would like to find. The second paramter is
pass by reference and will update if the data you are looking for is found 
true will be returned if the data is found, and false if the data is not found.
*/
bool BinTree::retrieve(const Media& find, 
	Media*& retrieved) const
{
	Node* current = root;
	//keep searching till data is found
	while (current != nullptr && *(current->data) != find) 
	{
	
		if (find < *(current->data)) //traverse left
		{	
			current = current->left;
		}
		else //traverse right
		{							
			current = current->right;
		}
	}
	if (current == nullptr) 
	{
		return false;
	}
	retrieved = current->data;
	return true;
}

//--------------------------------------------------------------------------
// operator << 
/* performs an inorder traversal of the BinTree and outputs
the data from each node to the given stream.*/
ostream& operator<<(ostream& stream, const BinTree& rhs)
{
	rhs.inorderHelper(rhs.root, stream);
	stream << endl;
	return stream;
}
void BinTree::inorderHelper(const Node* node, ostream& stream) const 
{
	if (node == nullptr) 
	{
		return;		//base case
	}	
	inorderHelper(node->left, stream);	//traverse left
	//stream << *(node->data) << " ";		//output to stream
	(node->data)->displayInLibrary();	//delete this		//I might add something where it prints the num of books from here instead of from the book class.
	stream << endl;				//delete this

	inorderHelper(node->right, stream); //traverse right
}



