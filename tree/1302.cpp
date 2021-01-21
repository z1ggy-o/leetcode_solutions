/* 1302 - deeptest leaves sum
 * 
 * The problem is how to find the deepest leave nodes.
 * Here is a method that use BFS to find all the deepest leave.
 * 
 * Similar as any other tree BFS, we use a FIFO queue to store the node of current level.
 * The deeptest level do not have any child, which means the queue is empty.
 * We compute the sum of each level, and the last sum while queue is empty is the answer
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
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
    int deepestLeavesSum(TreeNode* root) {
        TreeNode *tmp;
        int sum = 0;
        
        if (!root) return sum;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while (!q.empty()) {
            sum = 0;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                tmp = q.front();
                q.pop();
                
                sum += tmp->val;
                
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            
        }
        
        return sum;
    }
};
