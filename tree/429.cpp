/* 429. N-ary Tree Level Order Traversal
 *
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/* 
 * The n-ary tree is represented by an array in a breadth-first order.
 * 
 * In this problem, null has two meanings, it separates the parent with children,
 * it also separates the children group in the same level.
 *
 * Breadth first, use queue to store the access node.
 */
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        Node *tmp; 
        
        if(!root)
            return ret;
        
        queue<Node *> q;
        q.push(root); // add root into the queue to start processing
        ret.push_back({root->val});  
        
        while (!q.empty()) {  // keep check children of current node
            vector<int> level;
            int size = q.size();  // how many node in this level
            
            while(size--) {  // traverse current level
                tmp = q.front();     
                q.pop();
                for (int i = 0; i < tmp->children.size(); i++) {
                    level.push_back(tmp->children[i]->val);  // update node of this level
                    q.push(tmp->children[i]);  // push the parent node into queue
                }
            }
            if (level.size())  // the leaf nodes have no children
                ret.push_back(level);
        }
        
        return ret;
    }
};
