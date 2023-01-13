#include <iostream>

using namespace std;

void bubbleSort(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        bool isSwaped = false;
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwaped = true;
            }
        }
        if (isSwaped == false)
        {
            break;
        }
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
    bubbleSort(arr, 4);
    printArray(arr, 4);
}