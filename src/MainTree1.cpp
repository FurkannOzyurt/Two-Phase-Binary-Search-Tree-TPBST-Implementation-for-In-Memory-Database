#include "MainTree1.h"

MainTree1::MainTree1()
{
    this->root = NULL;
}

MainTree1::~MainTree1() {}

int MainTree1::height(MainNode1* Node) {
    if (Node == NULL)
        return 0;
    else {
        int left_height = height(Node->left);
        int right_height = height(Node->right);

        if (left_height > right_height) {
            return (left_height + 1);
        }
        else {
            return (right_height + 1);
        }
    }
}

MainNode1* MainTree1::search(MainNode1* r, string category) {
    if (r == NULL || r->key == category)
        return r;

    else if (category < r->key)
        return search(r->left, category);

    else if (category > r->key)
        return search(r->right, category);
    else
    {
        return NULL;
    }
}

MainNode1* MainTree1::insert(struct MainNode1* root, string category) {
    if (root == NULL) return new MainNode1(category);

    if (category < root->key)
        root->left = insert(root->left, category);
    else
        root->right = insert(root->right, category);

    return root;
}

MainNode1* MainTree1::find_inorder_suc(struct MainNode1* node) {
    struct MainNode1* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

MainNode1* MainTree1::deleteNode(struct MainNode1*& root, string category) {
    if (root == NULL) return root;

    if (category < root->key)
        root->left = deleteNode(root->left, category);
    else if (category > root->key)
        root->right = deleteNode(root->right, category);
    else {
        if (root->left == NULL) {
            struct MainNode1* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            struct MainNode1* temp = root->left;
            delete root;
            return temp;
        }

        struct MainNode1* temp = find_inorder_suc(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}