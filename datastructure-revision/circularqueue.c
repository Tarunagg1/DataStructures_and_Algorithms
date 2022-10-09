#include <stdio.h>
#include <stdlib.h>

struct CircularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct CircularQueue *q)
{
    if (q->f == q->r)
        return 1;
    return 0;
}

int isFull(struct CircularQueue *q)
{
    if (((q->r + 1) % q->size) == q->f)
    {
        return 1;
    }
    return 0;
}

void enCircularQueue(struct CircularQueue *q, int val)
{
    if (!isFull(q))
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        printf("element inserted %d\n", val);
    }
    else
    {
        printf("CircularQueue is full\n");
    }
}

void deCircularQueue(struct CircularQueue *q)
{
    if (!isEmpty(q))
    {
        q->f = (q->f + 1) % q->size;
        int val = q->arr[q->f];
        printf("pop  element is %d\n", val);
    }
    else
    {
        printf("CircularQueue is empty\n");
    }
}

int main()
{
    struct CircularQueue q;
    q.size = 4;
    q.f = 0;
    q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enCircularQueue(&q, 1);
    enCircularQueue(&q, 2);
    enCircularQueue(&q, 3);
    enCircularQueue(&q, 4);

    deCircularQueue(&q);
    deCircularQueue(&q);
    deCircularQueue(&q);
    deCircularQueue(&q);
    deCircularQueue(&q);
    enCircularQueue(&q, 4);

    return 0;
}
