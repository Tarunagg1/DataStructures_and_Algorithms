#include <iostream>
#include <map>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void solve(Node *first, Node *second)
{
    Node *curr1 = first;
    Node *next1 = curr1->next;
    Node *curr2 = second;

    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            
        }
    }
}

Node *segregateApproch2(Node *first, Node *second)
{
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;

    if (first->data < second->data)
    {
        solve(first, second);
    }
    else
    {
        solve(first, second);
    }
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    print(head);
}
