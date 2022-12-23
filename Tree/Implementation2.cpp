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

// Iterative Inorder Traversal
void Iterativeinorder(Node *root)
{
    stack<Node *> st;
    Node *curr = root;
    while (curr != NULL || st.empty() == false)
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        cout << (curr->key) << " ";
        curr = curr->right;
    }
}

// Iterative Preorder Traversal
void Iterativepreorder(Node *root)
{
    if (root != NULL)
        return;
    stack<Node *> st;
    Node *curr = root;
    while (curr != NULL || st.empty() == false)
    {
        while (curr != NULL)
        {
            cout << (curr->key) << " ";
            if (curr->right == NULL)
                st.push(curr->right);
            curr = curr->left;
        }
        if (st.empty() != false)
        {
            curr = st.top();
            st.pop();
        }
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
    Iterativeinorder(root);
    cout << endl;
    Iterativepreorder(root);
    cout << endl;
}