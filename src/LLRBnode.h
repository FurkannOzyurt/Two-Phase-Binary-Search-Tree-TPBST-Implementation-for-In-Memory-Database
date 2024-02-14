#pragma once
#include <string>
using namespace std;

struct LLRBnode
{
    struct LLRBnode* left;
    struct LLRBnode* right;
    string key;
    int price;
    // red = true, black = false
    bool color;
};