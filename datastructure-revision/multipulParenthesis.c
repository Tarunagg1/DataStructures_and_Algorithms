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

int isparenthsismatch(char pop, char top)
{
    if (top == '(' && pop == ')')
    {
        return 1;
    }
    if (top == '[' && pop == ']')
    {
        return 1;
    }
    if (top == '{' && pop == '}')
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
    char ele = s->arr[s->top];
    s->top--;
    return ele;
}

int peek(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is underflow \n");
        return -1;
    }
    return s->arr[s->top];
}

int multipleParenthesisMatch(char *exp)
{
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; i < exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty(sp))
            {
                printf("1");
                return 0;
            }
            char popch = pop(sp);
            if (!isparenthsismatch(popch, peek(sp)))
            {
                printf("3");
                return 0;
            }
        }
    }

    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        printf("2");
        return 0;
    }
}

int main()
{
    char *exp = "8*(9)";

    if (multipleParenthesisMatch(exp))
    {
        printf("Parenthisis is matching");
    }
    else
    {
        printf("Parenthisis is not matching");
    }
    return 0;
}
