class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;

        for (int l = 0, r = 0; r < nums.size(); ++r) {
            if (nums[r] == 0)
                --k;
            while (k < 0)
                if (nums[l++] == 0)
                    ++k;
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

// Example 1:

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

// Example 2:

// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
