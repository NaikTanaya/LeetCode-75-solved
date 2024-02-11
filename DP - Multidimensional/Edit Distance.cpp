class Solution {
public:

    int helper(string &word1, string &word2, int i, int j, vector<vector<int>> &dp){

        //Base case...
        if(i >= word1.length())
            //word1 ki length choti h word2 ki length se...
            return word2.length() - j;

        if(j >= word2.length())
            //word2 ki length choti h word1 ki length se...
            return word1.length() - i;
        if(dp[i][j] != -1) return dp[i][j]; // if dp array mein woh already available h then return it...

        int ans = 0;

        if(word1[i] == word2[j]){
            //match...
            ans = 0 + helper(word1, word2, i + 1, j + 1, dp);
        }
        else{
            //Mismatch...
            int op1 = 1 + helper(word1, word2, i, j + 1, dp);

            int op2 = 1 + helper(word1, word2, i + 1, j, dp);

            int op3 = 1 + helper(word1, word2, i + 1, j + 1, dp);

            ans = min(op1, min(op2, op3));
        }

        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1)); // dp array for memoization...
        int i = 0;
        int j = 0;
        int ans = helper(word1, word2, i, j, dp);
        return ans;
        
    }
};

// Example 1:

// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
// Example 2:

// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')
