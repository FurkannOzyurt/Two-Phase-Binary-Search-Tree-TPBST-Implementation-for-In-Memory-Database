#pragma once
#include <string>
#include "LLRBTree.h"
using namespace std;

struct MainNode2 {
public:
    string key;
    MainNode2* left;
    MainNode2* right;
    LLRBTree* tree_of_main_node;
    MainNode2(string key) {
        this->key = key;
        left = right = NULL;
    }
};