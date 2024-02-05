class Solution {
public:

    int f(int n, vector<int>&dp){
        if(n==0){
            return 0;
        }
        if(n==1 || n==2){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }

        return dp[n] = f(n-1, dp) + f(n-2, dp) + f(n-3, dp) ;
    }

    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};

// Example 1:

// Input: n = 4
// Output: 4
// Explanation:
// T_3 = 0 + 1 + 1 = 2
// T_4 = 1 + 1 + 2 = 4

// Example 2:

// Input: n = 25
// Output: 1389537
