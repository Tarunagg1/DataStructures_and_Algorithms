#include <iostream>
#include <stdio.h>
#include <climits>

using namespace std;

void print2largest(int arr[], int arr_size)
{

    int i, first, second;

    if (arr_size < 2)
    {
        printf(" Invalid Input ");
        return;
    }

    first = second = INT_MIN;

    for (i = 0; i < arr_size; i++)
    {
        if (arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] != first)
        {
            second = arr[i];
        }
    }

    cout<<"Second largest element is "<<second<<endl;
}

int main()
{
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    print2largest(arr, n);
    return 0;
}