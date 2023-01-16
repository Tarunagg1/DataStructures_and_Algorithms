#include <iostream>

using namespace std;

void moveZeros(int arr[], int s)
{
    int i = 0;
    int j = 0;

    for (int j = 0; j < s; j++)
    {
        if (arr[j] != 0)
        {
            swap(arr[j], arr[i]);
            i++;
        }
    }
}
