#include <stdio.h>

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }

        while (a[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);

    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void quickSort(int a[], int low, int high)
{
    int partationIndex;
    if (low < high)
    {
        partationIndex = partition(a, low, high);
        quickSort(a, low, partationIndex - 1);
        quickSort(a, partationIndex + 1, high);
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int size = 5;
    printArray(arr, size);
    quickSort(arr, 0, size - 1);
    printArray(arr, size);
}
