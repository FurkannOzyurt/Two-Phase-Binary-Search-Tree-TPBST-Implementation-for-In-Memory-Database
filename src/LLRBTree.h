#pragma once
#include "LLRBnode.h"

class LLRBTree
{
public:
    LLRBnode* root;

    LLRBTree();

    ~LLRBTree();
    // Create new node with inputs
    LLRBnode* getNode(string new_key, int new_price);
    // If root is NULL, height = 0; if not, height is calculated recursively.
    // height = height_of_subtree + 1
    int height(LLRBnode* Node);
    // Helper for insert
    LLRBnode* rotateRight(LLRBnode* node);
    // Helper for insert
    LLRBnode* rotateLeft(LLRBnode* node);
    // First, flip the color of node.
    // Then, flip the color of childs if they are not NULL.
    void flip_color(LLRBnode* node);
    // Recursively traverse the tree to find the location of new key insertion.
    LLRBnode* insertNode(LLRBnode* node, string new_key, int new_price);
    // If category > key of r, search recursively to right of r
    // If category < key of r, search recursively to left of r
    LLRBnode* search(LLRBnode* r, string name);
    // Returns if the node is red or not.
    bool is_red(LLRBnode* node);
    // Use when node has two red children and its left child is a 3 node.
    // This rearranges the subtree so that the root is a red node and left child is still a 3 node.  
    LLRBnode* move_red_to_right(LLRBnode* node);
    // When given a sub-tree that starts with a red node, we need change the 3 node
    // (the node with the single red child) from being the right child to being the left child.
    // When it is done, the new root of the subtree is still a red node,
    // but the 3 node is now the left child which preserves “leftleaningness”.
    LLRBnode* move_red_to_left(LLRBnode* node);
    // Right leaning nodes will be unbalanced while the code is working.
    // We need to balanced them using this func.
    LLRBnode* rotate_recolor(LLRBnode* node);
    // It finds the name that will be replaced.
    LLRBnode* find_min(LLRBnode* node);
    // It deletes the empty node found by find_min func.
    LLRBnode* delete_min(LLRBnode* node);
    // It does deletions and uses rotate_recolor func.
    LLRBnode* delete_rec(LLRBnode* node, string key);
    // It ensures that the root remains black.
    void Delete(string name);
    // It ensures that the root remains black.
    bool Insert(string name, int price);
    // Use search func to find the node and update it's price.
    void update_price(string name, int new_price);
};