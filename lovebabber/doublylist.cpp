#include <iostream>

using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
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

int getLength(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertHead(Node *&head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertTail(Node *&head, int value)
{
    Node *newNode = new Node(value);
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(Node *&head, int value, int pos)
{
    if (pos == 1)
    {
        insertHead(head, value);
        return;
    }

    Node *temp = head;
    int count = 0;

    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        insertTail(head, value);
        return;
    }

    Node *newNode = new Node(value);

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}

int main()
{
    Node *node1 = new Node(20);
    Node *head = node1;

    insertHead(head, 10);
    insertTail(head, 30);
    insertAtPosition(head, 5, 1);
    insertAtPosition(head, 50, 4);
    insertAtPosition(head, 40, 4);
    print(head);
}