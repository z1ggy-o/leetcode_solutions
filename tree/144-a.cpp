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

/* simple recursive solution */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        
        helper(root, ret);
        
        return ret;
    }
    
    void helper(TreeNode* root, vector<int> &ret)
    {
        if (!root)
            return;
        
        ret.push_back(root->val);
        helper(root->left, ret);
        helper(root->right, ret);
        
        return;
        
    }
};
