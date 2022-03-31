class Queue
{
    int a[];
    int capicity;
    int rear;

public
    Queue(int n)
    {
        capicity = n;
        a = new int[a];
        rear = -;
    }

    void ennQueue(int data)
    {
        if (rear == (capicity - 1))
        {
            throw new Exception("queue is full");
        }
        rear++;
        a[rear] = data;
    }

    int deQueue()
    {
        if (rear == -1)
        {
            throw new Exception("queue is empty");
        }
        int result = 0;
        for (int i = 0; i < rear; i++)
        {
            arr[i] = a[i + 1];
        }
        rear--;
        return result;
    }

    int getFront()
    {
        if (rear == -1)
        {
            throw new Exception("queue is empty");
        }
        return arr[0];
    }
}