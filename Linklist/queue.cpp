#include <iostream>

using namespace std;

class Node
{
    int data;
    int next;

public
    Node(int data)
    {
        this.data = data;
    }
}

class Queue
{
    Node front, rear;

    void enQueue(int data)
    {
        Node newNode = new Node(data);
        if (front == NULL)
        {
            front = rear = newNode;
            return;
        }
        rear.next = newNode;
        rear = newNode;
    }

    void deQueue()
    {
        if (front == NULL)
        {
            return throw new Exception("Queue is empty");
        }
        int result = front.data;
        front = front.next;
        return result;
    }
}