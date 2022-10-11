#include <stdio.h>

void selectionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++){
        
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
