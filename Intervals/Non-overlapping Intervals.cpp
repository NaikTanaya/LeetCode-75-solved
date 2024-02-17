class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int ans  = 0 ;
        int prev = 0;
        int n = intervals.size(); 
        for(int curr = 1;curr < n;curr++)
        {
            // overlapping
            if(intervals[curr][0] < intervals[prev][1])
            {
                ans++;
                if(intervals[curr][1] <= intervals[prev][1])
                {
                    prev = curr;   
                }
            }
            else
                {
                    prev = curr;   
                }
        }
        return ans ;
    }
};

// Example 1:

// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

// Example 2:

// Input: intervals = [[1,2],[1,2],[1,2]]
// Output: 2
// Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

// Example 3:

// Input: intervals = [[1,2],[2,3]]
// Output: 0
// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
