/* 589. N-ary Tree Preorder Traversal
 *
 * Preorder means depth first. We use stack for depth first traverse.
 * Because we've ready new use which container, the following things
 * are simply add children of each node in reverse order (stack is LIFO).
 */

/*
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

class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node *> s;
        vector<int> ret;
        
        if (!root)  // edge case: empty vector
            return ret;
        
        s.push(root);  // begin state
        
        while (!s.empty()) {  // accessed node is poped out
            Node *tmp = s.top();
            s.pop();
            ret.push_back(tmp->val);
            int size = tmp->children.size();
            for (int i = size-1; i >= 0; i--) {  // reverse order because stack is fifo
                s.push(tmp->children[i]);
            }
        }
        
        return ret;
    }
};
