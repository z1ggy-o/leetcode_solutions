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

/*
 * We need affiliate space to order the entries first.
 * There are several methos: two stack, mark parent node as accessed.
 *
 * Here is the two stack version:
 * 
 * Because the parent node are accessed at the last, nonlike preorder, we need to store the parent node first.
 * Here we use two stack (s1 and s2), we first put the root node into s1.
 * After that we jump into the loop:
 *  1. pop node from s1, and push it (the parent node) into s2.
 *  2. push left and right child of poped node into s1 (they are the new parent node)
 *  Here, we push left first, because when we push them into s2, the order is reversed.
 * After we accssed all the nodes, we simply pop nodes in s2 until empty.
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> s1, s2;
        TreeNode *tmp;
        vector<int> ret;
        
        if (!root)
            return ret;
        
        s1.push(root);
        
        while (!s1.empty()) {
            tmp = s1.top();
            s1.pop();  // s1 is the temp stack for parent node
            
            if (tmp->left)
                s1.push(tmp->left);
            if (tmp->right)
                s1.push(tmp->right);
            
            s2.push(tmp);
        }
        
        while (!s2.empty()) {
            tmp = s2.top();
            s2.pop();
            ret.push_back(tmp->val);
        }
        
        return ret;
     }
};
