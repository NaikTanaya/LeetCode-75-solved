class Solution {
    int solve(int i,int j,vector<vector<int>> &dp)
    {
        if(i==0 and j==0) // reaches (0,0) -> destination
        return 1; //(path found return 1)
        if(i<0 or j<0) // out of bound (no path found)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int t=solve(i-1,j,dp); // move up
        int l=solve(i,j-1,dp); //move left
        return dp[i][j]=t+l;
    }
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m+1,vector<int> (n+1,-1)); // memoisation
        return solve(m-1,n-1,dp); // (start from bottom right and move to top left through top and left movements)
    }
};

// Example 1:

// Input: m = 3, n = 7
// Output: 28

// Example 2:

// Input: m = 3, n = 2
// Output: 3
// Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down
