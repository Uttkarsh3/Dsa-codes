#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

// Inorder Traversal
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << (root->key) << " ";
        inorder(root->right);
    }
}

// Preorder Traversal
void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << (root->key) << " ";
        inorder(root->left);
        inorder(root->right);
    }
}

// Postorder Traversal
void postorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        inorder(root->right);
        cout << (root->key) << " ";
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(60);
    root->left->right->left = new Node(70);
    root->left->right->right = new Node(80);
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
}