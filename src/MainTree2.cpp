#include "MainTree2.h"

MainTree2::MainTree2()
{
    this->root = NULL;
}

MainTree2::~MainTree2() {}

int MainTree2::height(MainNode2* node) {
    if (node == NULL)
        return 0;
    else {
        int left_height = height(node->left);
        int right_height = height(node->right);

        if (left_height > right_height) {
            return (left_height + 1);
        }
        else {
            return (right_height + 1);
        }
    }
}

MainNode2* MainTree2::search(MainNode2* r, string category) {
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

MainNode2* MainTree2::insert(struct MainNode2* root, string category) {
    if (root == NULL) return new MainNode2(category);

    if (category < root->key)
        root->left = insert(root->left, category);
    else
        root->right = insert(root->right, category);

    return root;
}

MainNode2* MainTree2::find_inorder_suc(struct MainNode2* node) {
    struct MainNode2* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

MainNode2* MainTree2::deleteNode(struct MainNode2*& root, string category) {
    if (root == NULL) return root;

    if (category < root->key)
        root->left = deleteNode(root->left, category);
    else if (category > root->key)
        root->right = deleteNode(root->right, category);
    else {
        if (root->left == NULL) {
            struct MainNode2* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            struct MainNode2* temp = root->left;
            delete root;
            return temp;
        }

        struct MainNode2* temp = find_inorder_suc(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}