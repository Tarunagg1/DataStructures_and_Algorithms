#include <iostream>

using namespace std;

void insertationSort(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int temp = arr[i];
        int j = i - 1;

        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
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
    insertationSort(arr, 4);
    printArray(arr, 4);
}