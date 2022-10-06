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

int isEmpty(struct Node *head)
{
    if (head == NULL)
    {
        return 1;
    }
    return 0;
}

struct Node *push(struct Node *head, int data)
{
    struct Node *newNode = createNewNode(data);
    newNode->next = head;
    return newNode;
}

int pop(struct Node **head)
{
    if (isEmpty(*head))
    {
        printf("Stack underflow");
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    int ele = temp->data;
    free(temp);
    return ele;
}

void stackBottom(struct Node *head)
{
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Bottom is: %d \n", temp->data);
}

void peek(struct Node *head, int pos)
{
    struct Node *temp = head;

    for (int i = 0; (i < pos - 1 && temp != NULL); i++)
    {
        temp = temp->next;
    }

    if (temp != NULL)
    {
        printf("peek is: %d \n", temp->data);
    }
    else
    {
        printf("peek not found");
    }
}

void stackTop(struct Node *head)
{
    if (head == NULL)
    {
        printf("Stack underflow");
    }
    printf("Top is: %d \n", head->data);
}

void printStack(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d \n", head->data);
        head = head->next;
    }
}

int main()
{
    struct Node *top = NULL;
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);
    pop(&top);

    printStack(top);

    stackTop(top);
    stackBottom(top);
    peek(top, 2);
}
