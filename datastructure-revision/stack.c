#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int *arr;
    int top;
    int size;
};

int isEmpty(struct Stack *s){
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct Stack *s, int data)
{
    if (isFull(s))
    {
        printf("Stack is overflow \n");
    }
    s->arr[s->top] = data;
    s->top++;
}

void printStack(struct Stack *s){
    for(int i = 0; i < s->top; i++){
         printf("%d \n", s->arr[i]);
    }
}

int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is underflow \n");
        return -1;
    }
    int ele = s->arr[s->top];
    s->top--;
    return ele;
}

int peek(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is underflow \n");
        return -1;
    }
    return s->arr[s->top];
}

int main()
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 3;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    pop(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    pop(s);
    push(s, 5);
    printStack(s);

    return 0;
}
