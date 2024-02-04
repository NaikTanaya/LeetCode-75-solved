class Solution {
public:
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};

    void solve(vector<vector<int>>& ans, vector<int>& sub, int k, int n,int i) {
        if (sub.size() == k) {
            int sum = 0;
            for (int x : sub) {
                sum += x;
            }
            if (sum == n)
                ans.push_back(sub);
            return;
        }

        for (int j = i; j < 9; j++) {

            sub.push_back(nums[j]);
            solve(ans, sub, k, n, j + 1);
            sub.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if (n > 45 || n == 1)
            return vector<vector<int>>();

        vector<vector<int>> ans;
        vector<int> sub;
        solve(ans, sub, k, n, 0);
        return ans;
    }
};

// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.

// Example 2:

// Input: k = 3, n = 9
// Output: [[1,2,6],[1,3,5],[2,3,4]]
// Explanation:
// 1 + 2 + 6 = 9
// 1 + 3 + 5 = 9
// 2 + 3 + 4 = 9
// There are no other valid combinations.

// Example 3:

// Input: k = 4, n = 1
// Output: []
// Explanation: There are no valid combinations.
// Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
