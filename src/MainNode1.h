#pragma once
#include <string>
#include "AVLTree.h"
using namespace std;

struct MainNode1 {
public:
    string key;
    MainNode1* left;
    MainNode1* right;
    AVLTree* tree_of_main_node;
    MainNode1(string key) {
        this->key = key;
        left = right = NULL;
    }
};
