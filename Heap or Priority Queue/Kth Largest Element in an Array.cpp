class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int x = 1;
        int value = 0;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }

        for (int x = 1; x <= k; x++) {
            if (x == k) {
                value = pq.top();
            } else {
                pq.pop();
            }
        }

        return value;
    }
};

// Example 1:

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5

// Example 2:

// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
// Output: 4
