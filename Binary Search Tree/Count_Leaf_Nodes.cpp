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

unsigned int getLeafCount(struct Node* Node)
{
  if(Node == NULL)       
    return 0;
  if(Node->left == NULL && Node->right==NULL)      
    return 1;            
  else 
    return getLeafCount(Node->left)+
           getLeafCount(Node->right);      
}


int main()
{
    Node *root = new Node(15);
    root->left = new Node(5);
    root->left->left = new Node(25);
    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->left->left = new Node(16);
    root->right->right = new Node(80);
    printf("Leaf count of the tree is: %d", getLeafCount(root));
    getchar();
}