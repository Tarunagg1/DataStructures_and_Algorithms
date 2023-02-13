#include <iostream>

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

Node *reverseLinkedListByKGroup(Node *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    if (next != NULL)
    {
        head->next = reverseLinkedListByKGroup(next, k);
    }
    return prev;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    print(head);
}

