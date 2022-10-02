#include <stdio.h>

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", arr[i]);
    }
    printf("-------------------- \n");
}

int indexInsestion(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int deleteElement(int arr[], int index, int size)
{
    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    return 1;
}

int main()
{
    int arr[100] = {1, 2, 3, 76};
    int size = 4;
    display(arr, size);
    int resp = indexInsestion(arr, size, 45, 100, 2);
    if (resp != -1)
    {
        size++;
        display(arr, size);
    }

    int resp1 = deleteElement(arr, 2, size);
    if (resp1 != -1)
    {
        size--;
        display(arr, size);
    }

    return 0;
}