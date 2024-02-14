#pragma once
#include "AVLNode.h"

class AVLTree
{
public:
    AVLNode* root;

    AVLTree();

    ~AVLTree(); 
    // If root is NULL, height = 0; if not, height is calculated recursively.
    // height = height_of_subtree + 1
    int height(AVLNode* Node);
    // Create new node with inputs
    AVLNode* newNode(string new_key, int new_price);
    // If category > key of r, search recursively to right of r
    // If category < key of r, search recursively to left of r
    AVLNode* search(AVLNode* r, string name);
    // Find left child of node and right child of left child of node.
    // Assign node to right of node's left child
    // Assign right of node's left child to node's left child
    AVLNode* rightRotate(AVLNode* node1);
    // Find right child of node and left child of right child of node.
    // Assign node to left of node's right child
    // Assign left of node's right child to node's right child
    AVLNode* leftRotate(AVLNode* node1);
    // Balance factor is height of left subtree - height of right subtree
    int get_balance_factor(AVLNode* Node);
    // First find where to insert the new node recursively then insert it.
    // Then, calculate balance factor of node
    // Look for balance factor is greater than 1 or less than -1
    // If greater than 1, then do right rotate or left-right rotate
    // If less than -1, then do left rotate or right-left rotate
    AVLNode* insertNode(AVLNode* node, string new_key, int new_price);
    // We need to find the inorder successor, if node that will deleted has two child.
    AVLNode* node_with_min(AVLNode* node);
    // First find the node that will deleted recusrively. Then, look for how many child it has.
    // Next, do the deletion according to number of child.
    // Finally, if tree is imbalanced, balanced it with rotations.
    AVLNode* deleteNode(AVLNode* node, string name);
    // Use search func to find the node and update it's price.
    void update_price(string name, int new_price);
};