/* 590 - N-ary Tree postorder traversal
 *
 * Iterative solution.
 * Use two stacks. One for unaccessed parent nodes, another for store the result.
 */

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

/* post order need two stacks */
class Solution {
  public:
    vector<int> postorder(Node* root) {
            vector<int> ret; 
            stack<Node *> s1, s2;  // s1 for parent, s2 for return order
            Node *tmp;
            
            s1.push(root);
            
            if (!root)  // edge case: empty input
                return ret;
            
            while (!s1.empty()) {
                        tmp = s1.top();
                        s1.pop();
                        s2.push(tmp);  
                        
                        for (int i = 0; i < tmp->children.size(); i++) {
                                        s1.push(tmp->children[i]);
                                    }
                    }
            
            while (!s2.empty()) {
                        tmp = s2.top();
                        s2.pop();
                        ret.push_back(tmp->val);
                    }
            
            return ret;
        }
};
