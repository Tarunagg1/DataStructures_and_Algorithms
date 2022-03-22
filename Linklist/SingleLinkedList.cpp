#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

/**
 * Create node
 */

Node *createNewNode()
{
    cout << "Enter the number" << endl;
    int n;
    cin >> n;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = n;
    newNode->next = NULL;
    return newNode;
}

/**
 * traverse list
 */

void LinkedListTraversal(struct Node *main)
{
    while (main != NULL)
    {
        cout << main->data << " ";
        main = main->next;
    }
    cout << endl;
}

/**
 * insert at start
 */

Node *insertAtStart(struct Node *main)
{
    if (main == NULL)
    {
        return createNewNode();
    }
    else
    {
        Node *temp = createNewNode();
        temp->next = main;
        return temp;
    }
}

/**
 * insert at last
 */

Node *insertAtLast(struct Node *main)
{
    if (main == NULL)
    {
        return createNewNode();
    }
    else
    {
        Node *temp = main;
        Node *newNode = createNewNode();
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return main;
}

/**
 * insert at after
 */

Node *insertAtAfter(Node *main)
{
    if (main == NULL)
    {
        cout << "Invalide insertion" << endl;
        return main;
    }
    else
    {
        int n;
        cout << "Enter the position which after u want to insert";
        cin >> n;
        int i = 1;
        Node *temp = main;

        while (i < n)
        {
            temp = temp->next;
            i++;
        }
        Node *newNode = createNewNode();
        newNode->next = temp->next;
        temp->next = newNode;
        return main;
    }
}

/**
 * delete start
 */
Node *deleteFirst(Node *main)
{
    if (main == NULL)
    {
        cout << "Invalde deletion" << endl;
        return main;
    }
    else
    {
        Node *temp = main;
        main = main->next;
        free(temp);
        return main;
    }
}

/**
 * delete last
 */

Node *deleteEnd(Node *main)
{
    if (main == NULL)
    {
        cout << "Invalde deletion" << endl;
        return main;
    }
    else
    {
        Node *temp = main;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        free(temp->next);
    }
    return main;
}

/**
 * delete after
 */

Node *deleteAfter(Node *main)
{
    if (main == NULL)
    {
        cout << "Invalid insertion" << endl;
        return main;
    }
    else
    {
        int n;
        cout << "Enter the position which after u want to delete";
        cin >> n;
        int i = 1;
        Node *temp = main;

        while (i < n)
        {
            temp = temp->next;
            i++;
        }
        Node *q = temp->next;

        temp->next = q->next;

        free(q);
    }
    return main;
}

int main()
{
    Node *start = NULL;

    start = insertAtStart(start);
    start = insertAtStart(start);
    start = insertAtStart(start);
    start = insertAtLast(start);
    start = insertAtAfter(start);
    start = deleteFirst(start);
    start = deleteEnd(start);

    LinkedListTraversal(start);
}
