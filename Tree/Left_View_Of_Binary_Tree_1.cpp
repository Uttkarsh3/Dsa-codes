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

int maxlevel = 0;
void printleft(Node *root, int level)
{
    if (root == NULL)
        return;
    if (maxlevel < level)
    {
        cout << (root->key) << " ";
        maxlevel = level;
    }
    printleft(root->left, level + 1);
    printleft(root->right, level + 1);
}

void printleftview(Node *root)
{
    printleft(root, 1);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(50);
    root->right = new Node(60);
    root->right->left = new Node(70);
    root->right->right = new Node(20);
    root->right->left->right = new Node(8);
    printleftview(root);
    return 0;
}