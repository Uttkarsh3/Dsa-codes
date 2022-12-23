#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << (curr->data) << " ";
        curr = curr->next;
    }
}

Node *delbegin(Node *head)
{
    if (head == NULL)
        return NULL;
    else
    {
        Node *temp = head->next;
        delete (head);
        return temp;
    }
}

Node *dellast(Node *head)
{
    if (head == NULL)
        return NULL;
    else if(head->next==NULL)
    {
        delete(head);
        return NULL;
    }
    Node *curr=head;
    while(curr->next->next!=NULL)
    {
        curr=curr->next;
    }
    delete(curr->next);
    curr->next=NULL;
    return head;
}

int main()
{
    int x;
    Node *head = new Node(10);
    Node *t1 = new Node(20);
    Node *t2 = new Node(30);
    Node *t3 = NULL;
    head->next = t1;
    t1->next = t2;
    head = delbegin(head);
    head = dellast(head);
    printlist(head);
    return 0;
}