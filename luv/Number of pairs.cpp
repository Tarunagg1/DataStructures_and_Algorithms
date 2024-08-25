// Number of pairs
// Difficulty: MediumAccuracy: 21.82%Submissions: 63K+Points: 4
// Given two positive integer arrays arr and brr, find the number of pairs such that xy > yx (raised to power of) where x is an element from arr and y is an element from brr.

// Examples :

// Input: arr[] = [2, 1, 6], brr[] = [1, 5]
// Output: 3
// Explanation: The pairs which follow xy > yx are: 21 > 12,  25 > 52 and 61 > 16 .
// Input: arr[] = [2 3 4 5], brr[] = [1 2 3]
// Output: 5
// Explanation: The pairs which follow xy > yx are: 21 > 12 , 31 > 13 , 32 > 23 , 41 > 14 , 51 > 15 .
// Expected Time Complexity: O((N + M)log(N)).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ arr.size(), brr.size() ≤ 105
// 1 ≤ brr[i], arr[i] ≤ 103

// Seen this question in a real interview before ?

class Solution
{
public:
    int search(int val, vector<int> &brr)
    {
        int low = 0, high = brr.size() - 1, index = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (brr[mid] <= val)
            {
                index = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return index;
    }

    long long countPairs(vector<int> &arr, vector<int> &brr)
    {
        long long ans = 0;
        long long one = 0, two = 0, threeFour = 0;
        sort(brr.begin(), brr.end());
        int n = brr.size();

        for (auto i : brr)
        {
            if (i == 1)
                one++;
            else if (i == 2)
                two++;
            else if (i == 3 || i == 4)
                threeFour++;
        }
        for (auto i : arr)
        {
            if (i != 1)
            {
                ans += one;
                if (i == 2)
                    ans -= threeFour;
                if (i == 3)
                    ans += two;
                int index = search(i, brr);
                ans += n - index - 1;
            }
        }
        return ans;
    }
};
