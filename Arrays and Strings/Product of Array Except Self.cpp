class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // prefix and suffix method

        int len = nums.size();
        vector<int> result(len, 1);
        int prefix = 1;
        int suffix = 1;
        for (int i = 0; i < len; i++) {
            result[i] *= prefix;
            prefix *= nums[i];
        }

        for (int i = len - 1; i >= 0; i--) {
            result[i] *= suffix;
            suffix *= nums[i];
        }

        return result;
    }
};

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
