/* 590 - N-ary Tree postorder traversal
 *
 * Recursive version.
 * 1. Access children first
 * 2. Access myself
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

/* post order need two stacks */
class Solution {
  public:
    vector<int> postorder(Node* root) {
            vector<int> ret;
            if (!root)  // edge case: empty input
                return ret;
            
            helper(root, ret);
            
            return ret;
        }
  private:
    void helper(Node *root, vector<int> &ret)
    {
            int size = root->children.size();
            if (size) {
                        for (int i = 0; i < size; i++) {
                                        helper(root->children[i], ret);
                                    }
                    } 
            
            ret.push_back(root->val);
        }
};
