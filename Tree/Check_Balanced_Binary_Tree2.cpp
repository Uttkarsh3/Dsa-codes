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

int isBalanced(Node *root)
{
    if (root == NULL)
        return 0;
    int lh = isBalanced(root->left);
    if (lh == -1)
        return -1;
    int rh = isBalanced(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    else
        return max(lh, rh) + 1;
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