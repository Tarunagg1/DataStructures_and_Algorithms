// Insert Interval
// Difficulty: MediumAccuracy: 50.61%Submissions: 12K+Points: 4
// Geek has an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith event and intervals is sorted in ascending order by starti. He wants to add a new interval newInterval= [newStart, newEnd] where newStart and newEnd represent the start and end of this interval.

// Help Geek to insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

// Examples:

// Input: intervals = [[1,3], [4,5], [6,7], [8,10]], newInterval = [5,6]
// Output: [[1,3], [4,7], [8,10]]
// Explanation: The newInterval [5,6] overlaps with [4,5] and [6,7].
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,9]
// Output: [[1,2], [3,10], [12,16]]
// Explanation: The new interval [4,9] overlaps with [3,5],[6,7],[8,10].
// Constraints:
// 1 ≤ intervals.size() ≤  105
// 0 ≤ start[i], end[i] ≤ 109

class Solution
{
public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval)
    {
        // code here
        // code here
        int s = newInterval[0];
        int e = newInterval[1];

        vector<vector<int>> ansInterval;

        int n = intervals.size();
        bool inserted = false;

        for (int i = 0; i < n; i++)
        {
            if (s > intervals[i][1] && e > intervals[i][0])
                ansInterval.push_back({intervals[i][0], intervals[i][1]});
            else if (s < intervals[i][1] && e < intervals[i][0])
            {

                if (!inserted)
                {
                    ansInterval.push_back({s, e});
                    inserted = true;
                }

                ansInterval.push_back({intervals[i][0], intervals[i][1]});
            }
            else
            {
                s = min(s, intervals[i][0]);
                e = max(e, intervals[i][1]);
            }
        }

        if (!inserted)
        {
            ansInterval.push_back({s, e});
            inserted = true;
        }

        return ansInterval;
    }
};
