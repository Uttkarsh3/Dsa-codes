#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int K)
    {
        key = K;
        left = right = NULL;
    }
};

int height(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return (1 + max(height(root->left), height(root->right)));
}

bool isBalanced(Node *root)
{
    if (root == NULL)
        return true;
    int lh = height(root->left);
    int rh = height(root->right);
    return (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right));
}

int main()
{
    Node *root = new Node(30);
    root->left = new Node(40);
    root->right = new Node(80);
    root->left->left = new Node(50);
    root->left->right = new Node(70);
    root->right->right = new Node(90);
    root->left->right->left = new Node(20);
    root->left->right->right = new Node(10);
    cout << isBalanced(root);
    return 0;
}