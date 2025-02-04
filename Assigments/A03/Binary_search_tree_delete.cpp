/*****************************************************************************
*  Author:           [James Steward]
*  Email:            [jbrigmans@yahoo.com]
*  Label:            Binary Search Tree with Delete Method
*  Title:            BST Implementation with Deletion
*  Course:           [3013]
*  Semester:         [Spring and 2025]
* 
*  Description:
*       This program implements a Binary Search Tree (BST) with insertion, 
*       deletion, and printing functionalities. The deletion method properly 
*       handles all cases, including removing nodes with zero, one, or two children.
* 
*  Usage:
*       - Insert nodes using the insert method.
*       - Remove nodes using the remove method.
*       - Print the tree in an ordered manner.
* 
*  Files:
*       - [Binary_search_tree_delete].cpp
*****************************************************************************/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/**
 * Struct: Node
 * 
 * Description:
 *      Represents a node in the Binary Search Tree, containing an integer
 *      value and pointers to left and right child nodes.
 * 
 * Public Members:
 *      - int data      : Stores the value of the node.
 *      - Node *left    : Pointer to the left child.
 *      - Node *right   : Pointer to the right child.
 */
struct Node {
    int data;
    Node *left;
    Node *right;

    /**
     * Constructor: Node
     * 
     * Description:
     *      Initializes a new node with the given value and null child pointers.
     * 
     * Params:
     *      - int x : The value to store in the node.
     */
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

/**
 * Class: Bst
 * 
 * Description:
 *      Implements a Binary Search Tree (BST) with methods for insertion,
 *      deletion, and printing.
 * 
 * Public Methods:
 *      - void insert(int x)        : Inserts a node with the given value.
 *      - void remove(int key)      : Deletes a node with the specified key.
 *      - void print()              : Prints the tree in order.
 * 
 * Private Methods:
 *      - void _insert(Node*& sub_root, int x) : Helper function for insertion.
 *      - void _print(Node* root)              : Helper function for in-order printing.
 *      - Node* _delete(Node* root, int key)   : Helper function for deletion.
 *      - Node* minValueNode(Node* node)       : Finds the minimum value node.
 */
class Bst {
private:
    Node *root;

    /**
     * Private: _insert
     * 
     * Description:
     *      Recursively inserts a value into the BST.
     * 
     * Params:
     *      - Node*& sub_root : Reference to a subtree root.
     *      - int x           : Value to be inserted.
     */
    void _insert(Node *&sub_root, int x) {
        if (sub_root == nullptr) {
            sub_root = new Node(x);
        } else {
            if (x < sub_root->data) {
                _insert(sub_root->left, x);
            } else {
                _insert(sub_root->right, x);
            }
        }
    }

    /**
     * Private: _print
     * 
     * Description:
     *      Recursively prints the BST in descending order.
     * 
     * Params:
     *      - Node* root : Pointer to the current subtree root.
     */
    void _print(Node *root) {
        if (!root) return;
        _print(root->right);
        cout << root->data << " ";
        _print(root->left);
    }

    /**
     * Private: _delete
     * 
     * Description:
     *      Recursively deletes a node from the BST while maintaining structure.
     * 
     * Params:
     *      - Node* root : Pointer to the current subtree root.
     *      - int key    : Value to be deleted.
     * 
     * Returns:
     *      - Node* : Updated subtree root after deletion.
     */
    Node* _delete(Node* root, int key) {
        if (!root) return root;
        
        if (key < root->data) {
            root->left = _delete(root->left, key);
        } else if (key > root->data) {
            root->right = _delete(root->right, key);
        } else {
            if (!root->left) {
                Node *temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            
            Node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = _delete(root->right, temp->data);
        }
        return root;
    }

    /**
     * Private: minValueNode
     * 
     * Description:
     *      Finds the minimum value node in a subtree.
     * 
     * Params:
     *      - Node* node : Root of the subtree.
     * 
     * Returns:
     *      - Node* : Node with the smallest value in the subtree.
     */
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }

public:
    /**
     * Constructor: Bst
     * 
     * Description:
     *      Initializes an empty BST.
     */
    Bst() { root = nullptr; }
    
    void insert(int x) { _insert(root, x); }
    
    void remove(int key) { root = _delete(root, key); }
    
    void print() { _print(root); }
};

/**
 * Function: main
 * 
 * Description:
 *      Demonstrates BST operations including insertion, deletion, and printing.
 * 
 * Returns:
 *      - int : Program exit status.
 */
int main() {
    Bst tree;
    tree.insert(8);
    tree.insert(3);
    tree.insert(1);
    tree.insert(11);
    tree.insert(7);
    tree.insert(15);
    
    cout << "Tree before deletion: ";
    tree.print();
    
    tree.remove(3);
    
    cout << "\nTree after deletion: ";
    tree.print();
    
    return 0;
}
