#include <iostream>

#define n 100;

using namespace std;

class Stack
{
    int *arr;
    int top = -1;

public:
    Stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            top++;
            arr[top] = x;
        }
        return;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            top--;
        }
        return;
    }

    int top()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[top];
    }

    bool isFull()
    {
        if (top == n - 1)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        return false;
    }
};