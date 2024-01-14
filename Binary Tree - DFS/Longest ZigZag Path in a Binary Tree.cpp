class Solution {
public:
    int ans;
    void dfs(TreeNode* root, bool isLeft, int len) {
        if (!root) return;
        ans = max(ans, len);
        if (isLeft) {
            dfs(root->left, true, 1);
            dfs(root->right, false, len+1);
        } else {
            dfs(root->left, true, len+1);
            dfs(root->right, false, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        dfs(root, false, 0);
        return ans;
    }
};

// Example 1:

// Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
// Output: 3
// Explanation: Longest ZigZag path in blue nodes (right -> left -> right).

// Example 2:

// Input: root = [1,1,1,null,1,null,null,1,1,null,1]
// Output: 4
// Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).

// Example 3:

// Input: root = [1]
// Output: 0
