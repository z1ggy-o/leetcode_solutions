/*
 * leetcode 938
 * 
 * Simply traverse the tree can solve the problem.
 * Because the tree is a BST, we can use the property (smaller on left, greater on right) to avoid unnecessary comparisons
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        
        // base case
        if (!root)
            return 0;
        
        if (low <= root->val && high >= root->val)
            sum = root->val;
        else
            sum = 0;
        
        if (low <= root->val)
            sum += rangeSumBST(root->left, low, high);
        if (root->val <= high)
            sum += rangeSumBST(root->right, low, high);
        
        return sum;
    }
};
