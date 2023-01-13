#include <iostream>

using namespace std;

void selectionSort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

void printArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

main()
{
    int arr[] = {4, 3, 2, 1};
    selectionSort(arr, 4);
    printArray(arr, 4);
}