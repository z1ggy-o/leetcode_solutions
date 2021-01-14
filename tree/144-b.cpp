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

/* iteration method
 * need use a stack to store next node that we need to access.
 * 1. put the root into stack
 * 2. if the stack is not empty, pop one entry and put it value into return vector
 * 3. if the poped entry has right child, put its right child into stack
 * 4. if not, push left child
 * We push right side first because stack is FIFO
 */
 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> s;        
        TreeNode *tmp;
        
        if (!root)
            return ret;
        
        s.push(root);
        
        while (!s.empty()) {
            tmp = s.top();
            s.pop();
            ret.push_back(tmp->val);
            
            if (tmp->right)
                s.push(tmp->right);
            if (tmp->left)
                s.push(tmp->left);
        }
        
        return ret;
    }
};
