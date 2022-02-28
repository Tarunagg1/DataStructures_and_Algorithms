#include <iostream>
#include <climits>

using namespace std;

int sum(int arr[], int n)
{
    int maxSum = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
        }

        if (sum >= maxSum)
        {
            maxSum = sum;
        }
    }
    return maxSum;
}

int maximumSum(int arr[], int n)
{
    int maxSum = 0;
    int curSum = 0;

    for (int i = 0; i < n; i++)
    {
        curSum += arr[i];

        if (curSum > maxSum)
            maxSum = curSum;

        if (curSum < 0)
            curSum = 0;
    }
    return maxSum;
}

int main()
{
    int arr[] = {-5, 4, 6, -3, 4, -1};
    cout << maximumSum(arr, 6);
}