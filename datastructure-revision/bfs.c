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
        // printf("element inserted %d\n", val);
    }
    else
    {
        printf("Queue is full\n");
    }
}

int deQueue(struct Queue *q)
{
    if (!isEmpty(q))
    {
        q->f++;
        int val = q->arr[q->f];
        return val;
    }
    else
    {
        printf("Queue is empty\n");
        return -1;
    }
}

int main()
{
    struct Queue q;
    q.size = 400;
    q.f = -1;
    q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // BFS implementation

    int u;
    int i = 0;
    int node;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };

    visited[i] = 1;
    printf("%d ", i);
    enQueue(&q, i);

    while (!isEmpty(&q))
    {
        int node = deQueue(&q);

        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 0 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enQueue(&q, i);
            }
        }
    }

    return 0;
}
