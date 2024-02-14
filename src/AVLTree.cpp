#include "AVLTree.h"

AVLTree::AVLTree()
{
    this->root = NULL;
}

AVLTree::~AVLTree() {}

int AVLTree::height(AVLNode* Node) {
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

AVLNode* AVLTree::newNode(string new_key, int new_price) {
    AVLNode* node = new AVLNode();
    node->key = new_key;
    node->price = new_price;
    node->left = NULL;
    node->right = NULL;
    node->balance_factor = 0;
    return (node);
}

AVLNode* AVLTree::search(AVLNode* r, string name) {
    if (r == NULL || r->key == name)
        return r;

    else if (name < r->key)
        return search(r->left, name);

    else
        return search(r->right, name);
}

int AVLTree::get_balance_factor(AVLNode* Node) {
    if (Node == NULL)
        return 0;
    return height(Node->left) - height(Node->right);
}

AVLNode* AVLTree::rightRotate(AVLNode* node1) { // node1 imbalanced node
    AVLNode* lc_node1 = node1->left;
    AVLNode* rt_lc_node1 = lc_node1->right;
    lc_node1->right = node1;
    node1->left = rt_lc_node1;
    return lc_node1;
}

AVLNode* AVLTree::leftRotate(AVLNode* node1) {
    AVLNode* rc_node1 = node1->right;
    AVLNode* lt_rc_node1 = rc_node1->left;
    rc_node1->left = node1;
    node1->right = lt_rc_node1;
    return rc_node1;
}

AVLNode* AVLTree::insertNode(AVLNode* node, string new_key, int new_price) {
    if (node == NULL)
        return (newNode(new_key, new_price));
    if (new_key < node->key)
        node->left = insertNode(node->left, new_key, new_price);
    else if (new_key > node->key)
        node->right = insertNode(node->right, new_key, new_price);
    else
        return node;

    node->balance_factor = get_balance_factor(node);
    if (node->balance_factor > 1) {
        if (new_key < node->left->key) {
            return rightRotate(node); // LL imbalance
        }
        else if (new_key > node->left->key) { // LR imbalance
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if (node->balance_factor < -1) {
        if (new_key > node->right->key) {
            return leftRotate(node);// RR imbalance
        }
        else if (new_key < node->right->key) { // RL imbalance
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
    return node;
}

AVLNode* AVLTree::node_with_min(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

AVLNode* AVLTree::deleteNode(AVLNode* node, string name) { 
    if (node == NULL) {
        return NULL;
    }
    else if (name < node->key) {
        node->left = deleteNode(node->left, name);
    }
    else if (name > node->key) {
        node->right = deleteNode(node->right, name);
    }
    else {
        if (node->left == NULL) {
            AVLNode* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == NULL) {
            AVLNode* temp = node->left;
            delete node;
            return temp;
        }
        else {
            AVLNode* temp = node_with_min(node->right);
            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }
    }

    int bf = get_balance_factor(node);
    // Left Left Imbalance/Right rotation 
    if (bf == 2 && get_balance_factor(node->left) >= 0)
        return rightRotate(node);
    // Left Right Imbalance/LR rotation 
    else if (bf == 2 && get_balance_factor(node->left) == -1) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Right Imbalance/Left rotation	
    else if (bf == -2 && get_balance_factor(node->right) <= -0)
        return leftRotate(node);
    // Right Left Imbalance/RL rotation 
    else if (bf == -2 && get_balance_factor(node->right) == 1) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void AVLTree::update_price(string name, int new_price) {
    AVLNode* updated_node = this->search(this->root, name);
    updated_node->price = new_price;
}