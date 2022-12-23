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

void printdistance(Node *root, int K)
{
    if (root == NULL)
        return ;
    if (K == 0)
        cout << (root->key) << " ";
    else
    {
        printdistance(root->left, K - 1);
        printdistance(root->right, K - 1);
    }
}

int main()
{
    int K=2;
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    printdistance(root, K);
    return 0;
}