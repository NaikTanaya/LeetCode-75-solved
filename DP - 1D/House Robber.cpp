class Solution {
public:

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<=n;i++){
            int take=nums[i-1]+dp[i-2];
             int not_take=dp[i-1];
             dp[i]=max(take,not_take);
        }
        return dp[n];
    }
};

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.
