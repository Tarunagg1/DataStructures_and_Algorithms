
int binarySearch(int arr[], int key, int size)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        int mid = (start + size) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}