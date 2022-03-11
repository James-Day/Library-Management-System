#ifndef BINTREE_H_
#define BINTREE_H_
#include "media.h"
#include <iostream>
using namespace std;
//---------------------------------------------------------------------------
// BinTree: BinTree is a implementation of a binary search tree
//			without duplicates. There is also no remove function for 
//			this implementation. This tree stores NodeData objects. This 
//			means that the tree does not need to know what type of data it is 
//			storing and can be simply changed by changing the NodeData class.
//			use insert() to add data to the tree and use retrieve to find
//			a specified NodeData in the tree. The tree uses nodes to store
//			its data which have left and right pointers. left of a node is 
//			any data less than that node and right of any node is all data
//			that is greater than that node.
// 
// Implementation and assumptions:
//	 -- duplicates are not allowed in the tree
//   -- getParent and getSibling are implemented without the knowledge
//		of this being a Binary Search Tree, instead it is treated as just a 
//		binary tree
//   -- when using bstreeToArray it is assumed that the given array is big 
//		enough to store all the data from the tree
//   -- the user is responsible for deleting memory when using bstreeToArray
//	 -- NodeData is used for storing data, and operations.

class BinTree {
public:
    /* constructor which creates the root of the binary
    tree and sets it to nullptr */
    BinTree();

    //Constructor for Bintree sets name, and sets root to nullptr
    BinTree(string nameForTree);

    // destructor for deallocating memory when the BinTree falls out of scope
    ~BinTree();

    // inserts the data into the tree, returns true if successful
    bool insert(Media* data);

    /* retrieves data from the tree and updates the second parameter to a
    copy of the data. returns true if the the NodeData is found*/
    bool retrieve(const Media& find, Media*& retrieved) const;

    // empties the tree including data in each node
    void makeEmpty();

    // returns true if the tree is empty (has no nodes)
    bool isEmpty() const;

    //Iostream overload, outputs the tree inorder to the stream.
    friend ostream& operator<<(ostream& stream, const BinTree& rhs);

    string getName() const;
private:
    //Node structure that holds a pointer to data being held as well as
    // left and right pointers
    struct Node {
        Media* data = nullptr;//stored data in each node
        Node* right = nullptr;// pointer to another node which is greater than 
        Node* left = nullptr; // pointer to another node which is less than 
    };
    /* pointer to the root / top of the BinTree.
    Used to find data within the tree*/
    Node* root = nullptr;
    string name;

    // recursive helper for << operator
    void inorderHelper(const Node* node, ostream& stream) const;

    //recursive helper for makeEmpty
    void makeEmptyHelper(Node* current);
};

#endif
