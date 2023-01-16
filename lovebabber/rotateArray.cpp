#include <iostream>

using namespace std;

// 1 2 3 4 5  -- 4 5 1 2 3

// 0+2 % 5 == 2
// 1+2 % 5 == 3
// 2+2 % 5 == 4
// 3+2 % 5 == 0
// 4+2 % 5 == 1

int rotateArr(int arr[], int n, int r)
{
    for (int i = 0; i < n; i++)
    {
        arr[(i + r) % n] = arr[i];
    }
}
