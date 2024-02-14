#pragma once
#include "MainNode1.h"
// Primary tree for Part1
class MainTree1
{
public:
    MainNode1* root;

    MainTree1();

    ~MainTree1();
    // If root is NULL, height = 0; if not, height is calculated recursively.
    // height = height_of_subtree + 1
    int height(MainNode1* Node);
    // If category > key of r, search recursively to right of r
    // If category < key of r, search recursively to left of r
    MainNode1* search(MainNode1* r, string category);
    // First find where to insert the new node recursively then insert it.
    struct MainNode1* insert(struct MainNode1* root, string category);
    // We need to find the inorder successor, if node that will deleted has two child.
    struct MainNode1* find_inorder_suc(struct MainNode1* node);
    // First find the node that will deleted recusrively. Then, look for how many child it has.
    // Finally, do the deletion according to number of child.
    struct MainNode1* deleteNode(struct MainNode1*& root, string category);
};
