/* 987 - vertical order traversal of a binary tree
 *
 * Nodes are classified by x-axis value so we can use a hash table or any other
 * dictionary container to put all node with the same x value together.
 *
 * We use preorder to traverse the whole tree so the y-axis increases (decrease)
 * in one direction.
 * However, since there are nodes have same (x, y) position, the one with smaller
 * value should be placed first, which means we need to sort the nodes that have
 * same x position.
 *
 * 1. Use a dictionary to store nodes. The key is x-axis, value is (y, value) pair
 *    because we need both y and value to sort the nodes. (this can be optimized,
 *    since there can be only two nodes at the same position)
 * 2. Traverse the tree and put nodes into the dictionary. If we use sorting,
 *    the traverse order is not matter.
 * 3. Sort each set of nodes that have the same x value, get the result.
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
        vector<vector<int>> verticalTraversal(TreeNode *root)
        {
            map<int, vector<pair<int,int>>> map;
            vector<vector<int>> ret;

            if (!root) return ret;

            traverse(root, 0, 0, map);

            for (auto itr = map.begin(); itr != map.end(); itr++) {
                int x = itr->first;
                vector<pair<int, int>> v = itr->second;
                sort(v.begin(), v.end(), sortVertical);

                vector<int> set;
                for (pair<int, int> p: v) {
                    set.push_back(p.second);
                }
                ret.push_back(set);
            }
            
            return ret;
        }
    
    private:
        void traverse(TreeNode *root, int x, int y, map<int, vector<pair<int, int>>> &map)
        {
            if (!root) return;

            map[x].push_back(pair(y, root->val));
            traverse(root->left, x-1, y-1, map);
            traverse(root->right, x+1, y-1, map);
        }

        static bool sortVertical(pair<int, int> a, pair<int, int> b)
        {
            if (a.first == b.first) {
                return a.second < b.second;  // value of the node
            }
            return a.first > b.first;  // in 4-th quadrant, low levers have smaller y value
        }
};

