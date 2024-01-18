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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val == val) {
            return root;
        }
        // If the target value is smaller, search in the left subtree.
        else if (root->val > val) {
            // Make a recursive call to searchBST with the left subtree as the new root.
            return searchBST(root->left, val);
        }
        // If the target value is larger, search in the right subtree.
        else {
            // Make a recursive call to searchBST with the right subtree as the new root.
            return searchBST(root->right, val);
        }
    }
};

// Example 1:

// Input: root = [4,2,7,1,3], val = 2
// Output: [2,1,3]

// Example 2:

// Input: root = [4,2,7,1,3], val = 5
// Output: []
