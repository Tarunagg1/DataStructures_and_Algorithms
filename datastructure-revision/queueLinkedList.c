#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

struct Node *createNewNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void traversal()
{
    if (f == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node *head = f;
    while (head != NULL)
    {
        printf("%d \n", head->data);
        head = head->next;
    }
}

void enQueue(int data)
{
    struct Node *newNode = createNewNode(data);
    if (newNode == NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (f == NULL)
        {
            f = r = newNode;
        }
        else
        {
            r->next = newNode;
            r = newNode;
        }
    }
}

void deQueue()
{
    if (f == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = f;
    f = temp->next;
    free(temp);
}

int main()
{
    enQueue(10);
    enQueue(20);
    enQueue(30);
    enQueue(40);
    enQueue(50);
    deQueue();
    deQueue();
    traversal();
}
