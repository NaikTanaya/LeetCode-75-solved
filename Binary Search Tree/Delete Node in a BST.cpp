class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root)
            if (key < root->val)
                root->left = deleteNode(
                    root->left, key); // We frecursively call the function until
                                      // we find the target node
            else if (key > root->val)
                root->right = deleteNode(root->right, key);
            else {
                if (!root->left && !root->right)
                    return NULL; // No child condition
                if (!root->left || !root->right)
                    return root->left
                               ? root->left
                               : root->right; // One child contion -> replace
                                              // the node with it's child Two
                                              // child condition
                TreeNode* temp =
                    root->left; //(or) TreeNode *temp = root->right;
                while (temp->right != NULL)
                    temp = temp->right; //      while(temp->left != NULL) temp =
                                        //      temp->left;
                root->val = temp->val;  //       root->val = temp->val;
                root->left = deleteNode(
                    root->left,
                    temp->val); //        root->right = deleteNode(root->right,
                                //        temp);
            }
        return root;
    }
};

// Example 1:

// Input: root = [5,3,6,2,4,null,7], key = 3
// Output: [5,4,6,2,null,null,7]
// Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
// One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
// Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

// Example 2:

// Input: root = [5,3,6,2,4,null,7], key = 0
// Output: [5,3,6,2,4,null,7]
// Explanation: The tree does not contain a node with value = 0.
