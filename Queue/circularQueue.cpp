class circularQueue
{
    int a[];
    int n;
    int front = -1, end = -1;

public:
    circularQueue(int n)
    {
        this.n = n;
    }

    bool isFull()
    {
        if ((rear + 1) % n == front)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }

    void enQueue(int data)
    {
        if (isEmpty())
        {
            return;
        }
        if (front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % n;
        a[rear] = data;
    }

    int deQueue()
    {
        if (isEmpty())
        {
            return;
        }
        int result = a[front];

        if (front == rear)
        {
            front = rear = 0;
        }
        else
        {
            front = (front + 1) % n;
        }
        return result;
    }
}