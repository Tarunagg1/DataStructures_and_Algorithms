#include <stdio.h>

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int a[], int low, int mid, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            B[k] = a[i];
            i++;
            k++;
        }
        else
        {
            B[k] = a[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        B[k] = a[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        B[k] = a[j];
        k++;
        j++;
    }

    for (int i = 0; i <= high; i++)
    {
        a[i] = B[i];
    }
}

void mergeSort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(a, mid, high);
        mergeSort(a, mid + 1, high);
        merge(a, mid, low, high);
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int size = 5;
    printArray(arr, size);
    mergeSort(arr, 0, size - 1);
    printArray(arr, size);
}
