#pragma once
#include <string>
using namespace std;

struct AVLNode {
public:
    string key;
    int price;
    AVLNode* left;
    AVLNode* right;
    int balance_factor;
};