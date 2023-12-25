class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
              int length = nums.size();

        if (length < k) {
            return -1;  // Or another appropriate value to indicate invalid input
        }

        double window_sum = accumulate(nums.begin(), nums.begin() + k, 0.0);
        double max_average = window_sum / k;

        for (int i = k; i < length; i++) {
            window_sum += nums[i] - nums[i - k];
            max_average = max(max_average, window_sum / k);
        }

        return max_average;
    }
};

// Example 1:

// Input: nums = [1,12,-5,-6,50,3], k = 4
// Output: 12.75000
// Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

// Example 2:

// Input: nums = [5], k = 1
// Output: 5.00000
