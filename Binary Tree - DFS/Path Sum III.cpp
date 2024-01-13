/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int solve(TreeNode* root, long long x){
        if(root==NULL) return 0;
        long long count=0;
        if(root->val==x) count++;
        count+=solve(root->right, x-root->val);
        count+=solve(root->left, x-root->val);
        return count;
    }

    int pathSum(TreeNode* root, long long x) {
        long long result=0;
        if(!root) return 0;
        return pathSum(root->left,x)+  pathSum(root->right,x) +solve(root,x);

    }
};


// Example 1:
// Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
// Output: 3
// Explanation: The paths that sum to 8 are shown.

// Example 2:

// Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// Output: 3
