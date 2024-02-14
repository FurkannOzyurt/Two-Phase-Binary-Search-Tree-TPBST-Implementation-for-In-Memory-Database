#include <iostream>
#include <sstream>
#include <vector>
#include "PrintFuncs.h"

int main(int argc, char* argv[])
{
    MainTree1* main_tree1 = new MainTree1();
    MainTree2* main_tree2 = new MainTree2();
    ifstream input_reader1(argv[1]);
    ifstream input_reader2(argv[1]);
    ofstream output1(argv[2]);
    ofstream output2(argv[3]);
    string line;
    while (getline(input_reader1, line))
    {
        vector<string> command_elements;
        stringstream ss(line);
        string element;
        int i = 0;
        while (!ss.eof()) {
            getline(ss, element, '\t');
            command_elements.push_back(element);
            i++;
        }
        if (command_elements[0] == "insert")
        {
            if (main_tree1->search(main_tree1->root,command_elements[1]) == NULL)
            {
                main_tree1->root = main_tree1->insert(main_tree1->root,command_elements[1]);
                MainNode1* category_node = main_tree1->search(main_tree1->root, command_elements[1]);
                category_node->tree_of_main_node = new AVLTree();
                AVLTree* avl_tree = category_node->tree_of_main_node;
                int price = atoi(command_elements[3].c_str());
                avl_tree->root = avl_tree->insertNode(avl_tree->root,command_elements[2],price);
            }
            else
            {
                MainNode1* category_node = main_tree1->search(main_tree1->root,command_elements[1]);
                AVLTree* avl_tree = category_node->tree_of_main_node;
                int price = atoi(command_elements[3].c_str());
                avl_tree->root = avl_tree->insertNode(avl_tree->root,command_elements[2], price);
            }
        }
        else if (command_elements[0] == "remove")
        {
            MainNode1* category_node = main_tree1->search(main_tree1->root,command_elements[1]);
            AVLTree* avl_tree = category_node->tree_of_main_node;
            avl_tree->root = avl_tree->deleteNode(avl_tree->root,command_elements[2]);
        }
        else if (command_elements[0] == "printAllItems")
        {
            output1 << "command:printAllItems" << endl;
            print_all_levels_Main_AVL(main_tree1, output1);
        }
        else if (command_elements[0] == "printAllItemsInCategory")
        {
            output1 << "command:printAllItemsInCategory" << "\t" << command_elements[1] << endl;
            printAllItemsInCategory_AVL(main_tree1, command_elements[1], output1);
        }
        else if (command_elements[0] == "printItem")
        {
            output1 << "command:printItem" << "\t" << command_elements[1] << "\t" << command_elements[2] << endl;
            printItem_AVL(main_tree1, command_elements[1], command_elements[2], output1);
        }
        else if (command_elements[0] == "find")
        {
            output1 << "command:find" << "\t" << command_elements[1] << "\t" << command_elements[2] << endl;
            printItem_AVL(main_tree1, command_elements[1], command_elements[2], output1);
        }
        else
        {
            AVLTree* tree = main_tree1->search(main_tree1->root, command_elements[1])->tree_of_main_node;
            tree->update_price(command_elements[2], atoi(command_elements[3].c_str()));
        }
    }
    //----------------------------PART2-------------------------------------------------
    while (getline(input_reader2, line))
    {
        vector<string> command_elements;
        stringstream ss(line);
        string element;
        int i = 0;
        while (!ss.eof()) {
            getline(ss, element, '\t');
            command_elements.push_back(element);
            i++;
        }
        if (command_elements[0] == "insert")
        {
            if (main_tree2->search(main_tree2->root, command_elements[1]) == NULL)
            {
                main_tree2->root = main_tree2->insert(main_tree2->root, command_elements[1]);
                MainNode2* category_node = main_tree2->search(main_tree2->root, command_elements[1]);
                category_node->tree_of_main_node = new LLRBTree();
                LLRBTree* llrb_tree = category_node->tree_of_main_node;
                int price = atoi(command_elements[3].c_str());
                llrb_tree->root = llrb_tree->insertNode(llrb_tree->root, command_elements[2], price);
            }
            else
            {
                MainNode2* category_node = main_tree2->search(main_tree2->root, command_elements[1]);
                LLRBTree* llrb_tree = category_node->tree_of_main_node;
                int price = atoi(command_elements[3].c_str());
                llrb_tree->root = llrb_tree->insertNode(llrb_tree->root, command_elements[2], price);
            }
        }
        else if (command_elements[0] == "remove")
        {
            MainNode2* category_node = main_tree2->search(main_tree2->root, command_elements[1]);
            LLRBTree* llrb_tree = category_node->tree_of_main_node;
            llrb_tree->Delete(command_elements[2]);
        }
        else if (command_elements[0] == "printAllItems")
        {
            output2 << "command:printAllItems" << endl;
            print_all_levels_Main_LLRB(main_tree2, output2);
        }
        else if (command_elements[0] == "printAllItemsInCategory")
        {
            output2 << "command:printAllItemsInCategory" << "\t" << command_elements[1] << endl;
            printAllItemsInCategory_LLRB(main_tree2, command_elements[1], output2);
        }
        else if (command_elements[0] == "printItem")
        {
            output2 << "command:printItem" << "\t" << command_elements[1] << "\t" << command_elements[2] << endl;
            printItem_LLRB(main_tree2, command_elements[1], command_elements[2], output2);
        }
        else if (command_elements[0] == "find")
        {
            output2 << "command:find" << "\t" << command_elements[1] << "\t" << command_elements[2] << endl;
            printItem_LLRB(main_tree2, command_elements[1], command_elements[2], output2);
        }
        else
        {
            LLRBTree* tree = main_tree2->search(main_tree2->root, command_elements[1])->tree_of_main_node;
            tree->update_price(command_elements[2], atoi(command_elements[3].c_str()));
        }
    }

    input_reader1.close();
    input_reader2.close();
    output1.close();
    output2.close();

    return 0;
}

