#include <iostream>

using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void insert(int arr[], int n, int value)
{
    n = n + 1;
    arr[n] = value;
    int i = n;

    while (i > i)
    {
        int present = i / 2;
        if (arr[present] == arr[i])
        {
            swap(arr, present, i);
            i = present;
        }
        else
        {
            return;
        }
    }
}

void deleteInHeap(int arr[], int n)
{
    arr[1] = arr[n];
    n = n - 1;
    int i = 1;

    while (i < n)
    {
        int left = arr[2 * i];
        int right = arr[2 * i + 1];
        int larger = left > right ? 2 * i : 2 * i + 1;

        if (arr[i] < arr[larger])
        {
            swap(arr, i, larger);
            i = larger;
        }
        else
        {
            return;
        }
    }
}


void heapify(int arr[], int n){
    
}

int main()
{
}
