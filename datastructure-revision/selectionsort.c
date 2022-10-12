#include <stdio.h>

void selectionSort(int *arr, int size)
{
    int indexOfMin, temp;
    for (int i = 0; i < size - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[indexOfMin])
            {
                indexOfMin = j;
            }
        }

        // swap arr[i] or min
        temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = temp;
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
    selectionSort(arr, size);
    printArray(arr, size);
}
