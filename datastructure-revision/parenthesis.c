#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *s, int data)
{
    if (isFull(s))
    {
        printf("Stack is overflow \n");
    }
    s->arr[s->top] = data;
    s->top++;
}

char pop(struct stack *s)
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

int parenthesisMatch(char *exp)
{
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; i < exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }

    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *exp = "8*(9))";

    if (parenthesisMatch(exp))
    {
        printf("Parenthisis is matching");
    }
    else
    {
        printf("Parenthisis is not matching");
    }
    return 0;
}
