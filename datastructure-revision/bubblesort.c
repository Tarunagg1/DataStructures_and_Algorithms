#include <stdio.h>

void bubbleSort(int *arr, int size)
{
    int ele;
    int isSorted = 0;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            isSorted = 1;
            if (arr[j] > arr[j + 1])
            {
                ele = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = ele;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int size = 5;
    printArray(arr, size);
    bubbleSort(arr, size);
    printArray(arr, size);
}
