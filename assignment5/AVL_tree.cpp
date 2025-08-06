//
//  AVL tree.cpp
//  AVL tree
//
//  Created by Mahmood Moussavi on 2024-05-22.
//

#include "AVL_tree.h"
using namespace std;

AVLTree::AVLTree() : root(nullptr), cursor(nullptr) {}

int AVLTree::height(const Node *N)
{
    if (N == nullptr)
        return 0;

    return N->height;
}

int AVLTree::getBalance(Node *N)
{
    if (N == nullptr)
        return 0;

    int leftHeight = (N->left != nullptr) ? N->left->height : 0;
    int rightHeight = (N->right != nullptr) ? N->right->height : 0;

    return leftHeight - rightHeight;
}

Node *AVLTree::rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    x->parent = y->parent;
    y->parent = x;

    if (T2 != nullptr)
        T2->parent = y;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}

Node *AVLTree::leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    y->parent = x->parent;
    x->parent = y;
    if (T2 != nullptr)
        T2->parent = x;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

void AVLTree::insert(int key, Type value)
{
    root = insert(root, key, value, nullptr);
}

// Recursive function
Node *AVLTree::insert(Node *node, int key, Type value, Node *parent)
{
    if (node == nullptr)
        return new Node(key, value, parent);
    if (key < node->data.key)
    {
        node->left = insert(node->left, key, value, node);
    }
    else if (key > node->data.key)
    {
        node->right = insert(node->right, key, value, node);
    }
    else
    {
        return node;
    }
    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->data.key)

    {
        return rightRotate(node);
    }
    if (balance > 1 && key > node->left->data.key)

    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key > node->right->data.key)

    {
        return leftRotate(node);
    }
    if (balance < -1 && key < node->right->data.key)

    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Recursive function
void AVLTree::inorder(const Node *root)
{

    if (root == nullptr)
        return;

    inorder(root->left);

    cout << root->data.key << " ";
    inorder(root->right);
}

// Recursive function
void AVLTree::preorder(const Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data.key << " ";
    preorder(root->left);

    preorder(root->right);
}

// Recursive function
void AVLTree::postorder(const Node *root)
{
    if (root == nullptr)
        return;

    postorder(root->left);

    postorder(root->right);
    cout << root->data.key << " ";
}

const Node *AVLTree::getRoot()
{
    return root;
}

void AVLTree::find(int key)
{
    go_to_root();
    if (root != nullptr)
        find(root, key);
    else
        cout << "It seems that tree is empty, and key not found." << endl;
}

// Recursive funtion
void AVLTree::find(Node *root, int key)
{
    if (root == nullptr)
    {
        return;
    }
    if (key < root->data.key)
    {
        find(root->left, key);
    }
    else if (key > root->data.key)
    {
        find(root->right, key);
    }
    else
    {
        cursor = root;
    }
}

AVLTree::AVLTree(const AVLTree &other) : root(nullptr), cursor(nullptr)
{
    root = copy(other.root, nullptr);
    cursor = root;
}

AVLTree::~AVLTree()
{
    destroy(root);
}

AVLTree &AVLTree::operator=(const AVLTree &other)
{
    if (this == &other)
        return *this;
    destroy(root);
    root = copy(other.root, nullptr);
    cursor = root;
    return *this;
}

// Recursive funtion
Node *AVLTree::copy(Node *node, Node *parent)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    Node *newNode = new Node(node->data.key, node->data.value, parent);

    newNode->left = copy(node->left, newNode);
    newNode->right = copy(node->right, newNode);
    newNode->height = node->height;

    return newNode;
}

// Recusive function
void AVLTree::destroy(Node *node)
{
    if (node)
    {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

const int &AVLTree::cursor_key() const
{
    if (cursor != nullptr)
        return cursor->data.key;
    else
    {
        cout << "looks like tree is empty, as cursor == Zero.\n";
        exit(1);
    }
}

const Type &AVLTree::cursor_datum() const
{
    if (cursor != nullptr)
        return cursor->data.value;
    else
    {
        cout << "looks like tree is empty, as cursor == Zero.\n";
        exit(1);
    }
}

int AVLTree::cursor_ok() const
{
    if (cursor == nullptr)
        return 0;
    return 1;
}

void AVLTree::go_to_root()
{
    if (!root)
        cursor = root;
    // cursor = nullptr;
}
