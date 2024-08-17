// Product array puzzle
// Difficulty: EasyAccuracy: 33.46%Submissions: 219K+Points: 2
// Given an array nums[], construct a Product Array nums[] such that nums[i] is equal to the product of all the elements of nums except nums[i].

// Examples:

// Input: nums[] = [10, 3, 5, 6, 2]
// Output: [180, 600, 360, 300, 900]
// Explanation: For i=0, P[i] = 3*5*6*2 = 180.
// For i=1, P[i] = 10*5*6*2 = 600.
// For i=2, P[i] = 10*3*6*2 = 360.
// For i=3, P[i] = 10*3*5*2 = 300.
// For i=4, P[i] = 10*3*5*6 = 900.
// Input: nums[] = [12,0]
// Output: [0, 12]
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 <= nums.size() <= 1000
// 0 <= nums[i] <= 200
// nums[i] may contain duplicates.

// Seen this question in a real interview before ?

class Solution
{
public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int> &nums)
    {

        // code here
        int n = nums.size();
        if (n == 1)
            return {1};

        vector<long long int> left(n);
        vector<long long int> right(n);
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++)
        {
            left[i] = nums[i] * left[i - 1];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = nums[i] * right[i + 1];
        }
        vector<long long int> ans(n);
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                ans[i] = right[i + 1];
            else if (i == (n - 1))
                ans[i] = left[i - 1];
            else
                ans[i] = left[i - 1] * right[i + 1];
        }
        return ans;
    }
};
