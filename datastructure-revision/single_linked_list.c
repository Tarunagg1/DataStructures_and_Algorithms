#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNewNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void traversal(struct Node *head)
{
    while (head->next != NULL)
    {
        printf("%d \n", head->data);
        head = head->next;
    }
}

struct Node *insertationFront(struct Node *head, int data)
{
    if (head == NULL)
    {
        head = createNewNode(data);
        return head;
    }
    // struct Node *temp = head;
    struct Node *newNode = createNewNode(data);
    newNode->next = head;
    return newNode;
}

struct Node *deleteFront(struct Node *head)
{
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *temp = head;
    struct Node *newNode = createNewNode(data);
    int i = 0;

    while (i != index - 1)
    {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *temp = head;
    int i = 0;

    while (i != index - 1)
    {
        temp = temp->next;
        i++;
    }

    struct Node *mac = temp->next;
    temp->next = mac->next;
    free(mac);

    return head;
}

struct Node *insertationBack(struct Node *head, int data)
{
    struct Node *temp = head;
    struct Node *newNode = createNewNode(data);

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

struct Node *deleteAtBack(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
}

int main()
{
    struct Node *head = createNewNode(1);
    head->next = createNewNode(2);
    head = insertationFront(head, 0);

    head = insertAtIndex(head, 6, 2);
    head = insertationBack(head, 3);
    // head = deleteFront(head);
    // head = deleteAtIndex(head,2);
    head = deleteAtBack(head);

    traversal(head);
    return 0;
}
