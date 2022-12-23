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

Node *inorderPredecessor(Node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

Node *BST_Delete(Node *root, int x)
{
    struct Node *iPre;
    if (root == NULL)
        return NULL;
    if (root->right == NULL && root->left == NULL)
    {
        free(root);
        return NULL;
    }
    if (x < root->key)
        root->left = BST_Delete(root->left, x);
    else if (x > root->key)
        root->right = BST_Delete(root->right, x);

    else
    {
        iPre = inorderPredecessor(root);
        root->key = iPre->key;
        root->left = BST_Delete(root->left, iPre->key);
    }
    return root;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << (root->key) << " ";
        inorder(root->right);
    }
}

int main()
{
    Node *root = new Node(15);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->left->left = new Node(16);
    root->right->right = new Node(80);
    inorder(root);
    root = BST_Delete(root, 18);
    cout<<endl;
    inorder(root);
}