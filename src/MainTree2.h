#pragma once
#include "MainNode2.h"
// Primary tree for Part2
class MainTree2
{
public:
    MainNode2* root;

    MainTree2();

    ~MainTree2();
    // If root is NULL, height = 0; if not, height is calculated recursively.
    // height = height_of_subtree + 1
    int height(MainNode2* node);
    // If category > key of r, search recursively to right of r
    // If category < key of r, search recursively to left of r
    MainNode2* search(MainNode2* r, string category);
    // First find where to insert the new node recursively then insert it.
    struct MainNode2* insert(struct MainNode2* root, string category);
    // We need to find the inorder successor, if node that will deleted has two child.
    struct MainNode2* find_inorder_suc(struct MainNode2* node);
    // First find the node that will deleted recusrively. Then, look for how many child it has.
    // Finally, do the deletion according to number of child.
    struct MainNode2* deleteNode(struct MainNode2*& root, string category);
};

