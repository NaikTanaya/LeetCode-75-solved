class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp = 0, dp1 = 0, dp2 = 0;
        for (int i = 2; i <= n; i++) {
            int oneStep = dp1 + cost[i - 1];
            int twoStep = dp2 + cost[i - 2];
            dp = min(oneStep, twoStep);
            dp2 = dp1;
            dp1 = dp;
        }
        return dp1;
    }
};


// Example 1:

// Input: cost = [10,15,20]
// Output: 15
// Explanation: You will start at index 1.
// - Pay 15 and climb two steps to reach the top.
// The total cost is 15.

// Example 2:

// Input: cost = [1,100,1,1,1,100,1,1,100,1]
// Output: 6
// Explanation: You will start at index 0.
// - Pay 1 and climb two steps to reach index 2.
// - Pay 1 and climb two steps to reach index 4.
// - Pay 1 and climb two steps to reach index 6.
// - Pay 1 and climb one step to reach index 7.
// - Pay 1 and climb two steps to reach index 9.
// - Pay 1 and climb one step to reach the top.
The total cost is 6.
