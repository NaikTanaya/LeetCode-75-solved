class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int x = INT_MAX;
        int j = INT_MAX;
        int k = INT_MAX;
        if (nums.size() < 3) {
            return false;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= x) {
                x = nums[i];
            } else if (nums[i] <= j) {
                j = nums[i];
            } else {
                return true;
            }
        }
        return false;
    }
};

// Example 1:

// Input: nums = [1,2,3,4,5]
// Output: true
// Explanation: Any triplet where i < j < k is valid.

// Example 2:

// Input: nums = [5,4,3,2,1]
// Output: false
// Explanation: No triplet exists.

// Example 3:

// Input: nums = [2,1,5,0,4,6]
// Output: true
// Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
