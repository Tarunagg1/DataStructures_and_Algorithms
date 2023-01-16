#include <iostream>

using namespace std;

void mergeSortedArray(int arr1[], int arr2[], int s1, int s2, int arr3[])
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < s1 && j < s2)
    {

        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
        }
        else
        {
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < s1)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }

    while (j < s2)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }
}