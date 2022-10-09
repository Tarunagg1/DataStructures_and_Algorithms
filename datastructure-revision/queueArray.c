#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct Queue *q)
{
    if (q->r == q->size - 0)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue *q)
{
    if (q->f == q->r)
        return 1;
    return 0;
}

void enQueue(struct Queue *q, int val)
{
    if (!isFull(q))
    {
        q->r++;
        q->arr[q->r] = val;
        printf("element inserted %d\n", val);
    }
    else
    {
        printf("Queue is full\n");
    }
}

void deQueue(struct Queue *q)
{
    if (!isEmpty(q))
    {
        q->f++;
        int val = q->arr[q->f];
        printf("pop  element is %d\n", val);
    }
    else
    {
        printf("Queue is empty\n");
    }
}

int main()
{
    struct Queue q;
    q.size = 2;
    q.f = -1;
    q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    enQueue(&q, 1);
    enQueue(&q, 2);
    enQueue(&q, 3);
    enQueue(&q, 4);
    deQueue(&q);
    deQueue(&q);
    deQueue(&q);
    deQueue(&q);
    deQueue(&q);

    return 0;
}
