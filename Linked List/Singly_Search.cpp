#include <iostream>
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

int search(Node *head, int x)
{
    int pos = 1;
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == x)
            return pos;
        else
        {
            pos++;
            curr = curr->next;
        }
    }
    return -1;
}

int main()
{
    Node *head = new Node(10);
    Node *t1 = new Node(20);
    Node *t2 = new Node(30);
    head->next = t1;
    t1->next = t2;
    printlist(head);
    cout<<endl;
    cout<<"Position of element in Linked List: "<<search(head,10);
    return 0;
}