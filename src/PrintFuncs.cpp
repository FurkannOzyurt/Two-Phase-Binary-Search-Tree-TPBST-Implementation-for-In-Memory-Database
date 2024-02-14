#include "PrintFuncs.h"

void print_spesific_level_AVL(struct AVLNode* root, int level, ofstream& output)
{
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        output << '"' << root->key << '"' << ":" << '"' << root->price << '"' << ",";
    }
    else if (level > 1) {
        print_spesific_level_AVL(root->left, level - 1, output);
        print_spesific_level_AVL(root->right, level - 1, output);
    }
}

void print_all_levels_AVL(AVLTree* tree, ofstream& output)
{
    int h = tree->height(tree->root);
    int i;
    if (h == 0)
    {
        output << "{}";
    }
    output << endl;
    for (i = 1; i <= h; i++) {
        output << "\t";
        print_spesific_level_AVL(tree->root, i, output);
        output << endl;
    }
}

void print_spesific_level_Main_AVL(struct MainNode1* root, int level, ofstream& output)
{
    if (root == NULL) { return; }
    if (level == 1) {
        output << '"' << root->key << '"' << ":";
        print_all_levels_AVL(root->tree_of_main_node, output);
    }
    else if (level > 1) {
        print_spesific_level_Main_AVL(root->left, level - 1, output);
        print_spesific_level_Main_AVL(root->right, level - 1, output);
    }
}

void print_all_levels_Main_AVL(MainTree1* tree, ofstream& output)
{
    output << "{" << endl;
    int h = tree->height(tree->root);
    int i;
    for (i = 1; i <= h; i++) {
        print_spesific_level_Main_AVL(tree->root, i, output);
    }
    output << "}" << endl;
}

void printAllItemsInCategory_AVL(MainTree1* main_tree, string category, ofstream& output)
{
    output << "{" << endl;
    MainNode1* main_node = main_tree->search(main_tree->root, category);
    output << '"' << main_node->key << '"' << ":";
    print_all_levels_AVL(main_node->tree_of_main_node, output);
    output << "}" << endl;
}

void printItem_AVL(MainTree1* main_tree, string category, string name, ofstream& output) {
    MainNode1* main_node = main_tree->search(main_tree->root, category);
    if (main_node == NULL)
    {
        output << "{}" << endl;
    }
    else
    {
        AVLNode* avl_node = main_node->tree_of_main_node->search(main_node->tree_of_main_node->root, name);
        if (avl_node == NULL)
        {
            output << "{}" << endl;
        }
        else
        {
            output << "{" << endl;
            output << '"' << main_node->key << '"' << ":" << endl;
            output << "\t" << '"' << avl_node->key << '"' << ":" << '"' << avl_node->price << '"' << endl;
            output << "}" << endl;
        }
    }
}
//-----------------------------------------------------------------------------------
void print_spesific_level_LLRB(struct LLRBnode* root, int level, ofstream& output)
{
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        output << '"' << root->key << '"' << ":" << '"' << root->price << '"' << ",";
    }
    else if (level > 1) {
        print_spesific_level_LLRB(root->left, level - 1, output);
        print_spesific_level_LLRB(root->right, level - 1, output);
    }
}

void print_all_levels_LLRB(LLRBTree* tree, ofstream& output)
{
    int h = tree->height(tree->root);
    int i;
    if (h == 0)
    {
        output << "{}";
    }
    output << endl;
    for (i = 1; i <= h; i++) {
        output << "\t";
        print_spesific_level_LLRB(tree->root, i, output);
        output << endl;
    }
}

void print_spesific_level_Main_LLRB(struct MainNode2* root, int level, ofstream& output)
{
    if (root == NULL) { return; }
    if (level == 1) {
        output << '"' << root->key << '"' << ":";
        print_all_levels_LLRB(root->tree_of_main_node, output);
    }
    else if (level > 1) {
        print_spesific_level_Main_LLRB(root->left, level - 1, output);
        print_spesific_level_Main_LLRB(root->right, level - 1, output);
    }
}

void print_all_levels_Main_LLRB(MainTree2* tree, ofstream& output)
{
    output << "{" << endl;
    int h = tree->height(tree->root);
    int i;
    for (i = 1; i <= h; i++) {
        print_spesific_level_Main_LLRB(tree->root, i, output);
    }
    output << "}" << endl;
}

void printAllItemsInCategory_LLRB(MainTree2* main_tree, string category, ofstream& output)
{
    output << "{" << endl;
    MainNode2* main_node = main_tree->search(main_tree->root, category);
    output << '"' << main_node->key << '"' << ":";
    print_all_levels_LLRB(main_node->tree_of_main_node, output);
    output << "}" << endl;
}

void printItem_LLRB(MainTree2* main_tree, string category, string name, ofstream& output) {
    MainNode2* main_node = main_tree->search(main_tree->root, category);
    if (main_node == NULL)
    {
        output << "{}" << endl;
    }
    else
    {
        LLRBnode* llrb_node = main_node->tree_of_main_node->search(main_node->tree_of_main_node->root, name);
        if (llrb_node == NULL)
        {
            output << "{}" << endl;
        }
        else
        {
            output << "{" << endl;
            output << '"' << main_node->key << '"' << ":" << endl;
            output << "\t" << '"' << llrb_node->key << '"' << ":" << '"' << llrb_node->price << '"' << endl;
            output << "}" << endl;
        }
    }
}