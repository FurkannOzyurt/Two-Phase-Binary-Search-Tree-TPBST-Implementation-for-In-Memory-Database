#pragma once
#include <fstream>
#include "AVLTree.h"
#include "LLRBTree.h"
#include "MainTree1.h"
#include "MainTree2.h"
#include <stdlib.h>
#include <stdio.h>
using namespace std;
// It prints spesific level of avl tree.
void print_spesific_level_AVL(struct AVLNode* root, int level, ofstream& output);
// It prints all levels of avl tree.
void print_all_levels_AVL(AVLTree* tree, ofstream& output);
// It prints spesific level of main tree.
void print_spesific_level_Main_AVL(struct MainNode1* root, int level, ofstream& output);
// It prints all levels of main tree.
void print_all_levels_Main_AVL(MainTree1* tree, ofstream& output);
// Search category and use print_spesific_level_Main_AVL func.
void printAllItemsInCategory_AVL(MainTree1* main_tree, string category, ofstream& output);
// Search for category and name and print it.
void printItem_AVL(MainTree1* main_tree, string category, string name, ofstream& output);
//-------------------------------------PART2---------------------------------------------
// It prints spesific level of llrb tree.
void print_spesific_level_LLRB(struct LLRBnode* root, int level, ofstream& output);
// It prints all levels of llrb tree.
void print_all_levels_LLRB(LLRBTree* tree, ofstream& output);
// It prints spesific level of main tree.
void print_spesific_level_Main_LLRB(struct MainNode2* root, int level, ofstream& output);
// It prints all levels of main tree.
void print_all_levels_Main_LLRB(MainTree2* tree, ofstream& output);
// Search category and use print_spesific_level_Main_LLRB func.
void printAllItemsInCategory_LLRB(MainTree2* main_tree, string category, ofstream& output);
// Search for category and name and print it.
void printItem_LLRB(MainTree2* main_tree, string category, string name, ofstream& output);