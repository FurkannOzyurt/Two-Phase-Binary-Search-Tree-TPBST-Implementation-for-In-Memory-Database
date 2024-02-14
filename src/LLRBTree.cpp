#include "LLRBTree.h"

LLRBTree::LLRBTree()
{
    this->root = NULL;
}

LLRBTree::~LLRBTree() {}

int LLRBTree::height(LLRBnode* Node) {
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

LLRBnode* LLRBTree::getNode(string new_key, int new_price)
{
    LLRBnode* newNode = new LLRBnode();
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->key = new_key;
    newNode->price = new_price;
    newNode->color = true;
    return newNode;
}

LLRBnode* LLRBTree::rotateRight(LLRBnode* node)
{
    LLRBnode* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    temp->color = node->color;
    node->color = true;
    return temp;
}

LLRBnode* LLRBTree::rotateLeft(LLRBnode* node)
{
    LLRBnode* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    temp->color = node->color;
    node->color = true;
    return temp;
}

LLRBnode* LLRBTree::insertNode(LLRBnode* node, string new_key, int new_price)
{
    if (NULL == node) {
        node = getNode(new_key, new_price);
        return node;
    }
    if (is_red(node->left) && is_red(node->right)) {
        flip_color(node);
    }
    if (new_key == node->key) {
        node->key = new_key;
    }
    else {
        if (new_key < node->key) {
            node->left = insertNode(node->left, new_key, new_price);
        }
        else {
            node->right = insertNode(node->right, new_key, new_price);
        }
    }
    if (is_red(node->right) && (false == is_red(node->left)))
    {
        node = rotateLeft(node);
    }
    if (is_red(node->left) && is_red(node->left->left))
    {
        node = rotateRight(node);
    }
    if (is_red(node->left) && is_red(node->right)) {
        flip_color(node);
    }
    return node;
}

void LLRBTree::flip_color(LLRBnode* node)
{
    node->color = !node->color;
    if (NULL != node->left) {
        node->left->color = !node->left->color;
    }
    if (NULL != node->right) {
        node->right->color = !node->right->color;
    }
}

LLRBnode* LLRBTree::search(LLRBnode* r, string name) {
    if (r == NULL || r->key == name)
        return r;
    else if (name < r->key)
        return search(r->left, name);
    else
        return search(r->right, name);
}

bool LLRBTree::is_red(LLRBnode* node) {
    if (node == NULL)
        return 0;
    return (node->color == true);
}

LLRBnode* LLRBTree::move_red_to_right(LLRBnode* node)
{
    flip_color(node);

    if ((NULL != node->left) && is_red(node->left->left))
    {
        node = rotateRight(node);
        flip_color(node);
    }
    return node;
}

LLRBnode* LLRBTree::move_red_to_left(LLRBnode* node)
{
    flip_color(node);

    if ((NULL != node->right) && is_red(node->right->left))
    {
        node->right = rotateRight(node->right);
        node = rotateLeft(node);
        flip_color(node);
    }
    return node;
}

LLRBnode* LLRBTree::find_min(LLRBnode* node)
{
    while (NULL != node->left) {
        node = node->left;
    }
    return node;
}

LLRBnode* LLRBTree::delete_min(LLRBnode* node)
{
    if (NULL == node->left) {
        delete node;
        return NULL;
    }
    if ((false == is_red(node->left)) && (false == is_red(node->left->left)))
    {
        node = move_red_to_left(node);
    }
    node->left = delete_min(node->left);

    return rotate_recolor(node);
}

LLRBnode* LLRBTree::rotate_recolor(LLRBnode* node)
{
    if (is_red(node->right)) {
        node = rotateLeft(node);
    }
    if (is_red(node->left) && is_red(node->left->left))
    {
        node = rotateRight(node);
    }
    if (is_red(node->left) && is_red(node->right))
    {
        flip_color(node);
    }
    return node;
}

LLRBnode* LLRBTree::delete_rec(LLRBnode* node, string key)
{
    if (key < node->key) {
        if (NULL != node->left) {

            if ((false == is_red(node->left)) && (false == is_red(node->left->left)))
            {
                node = move_red_to_left(node);
            }
            node->left = delete_rec(node->left, key);
        }
    }
    else {

        if (is_red(node->left)) {
            node = rotateRight(node);
        }

        if ((key == node->key) && (NULL == node->right))
        {
            delete node;
            return NULL;
        }

        if (NULL != node->right) {
            if ((false == is_red(node->right)) && (false == is_red(node->right->left)))
            {
                node = move_red_to_right(node);
            }

            if (key == node->key) {
                node->key = find_min(node->right)->key;
                node->right = delete_min(node->right);
            }
            else {
                node->right = delete_rec(node->right, key);
            }
        }
    }
    return rotate_recolor(node);
};

void LLRBTree::Delete(string name)
{
    if (NULL != root) {
        root = delete_rec(root, name);
        if (NULL != root) {
            root->color = false;
        }
    }
}

bool LLRBTree::Insert(string name, int price)
{
    root = insertNode(root, name, price);
    root->color = false;
    return true;
}

void LLRBTree::update_price(string name, int new_price) {
    LLRBnode* updated_node = this->search(this->root, name);
    updated_node->price = new_price;
}