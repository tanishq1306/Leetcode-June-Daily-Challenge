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
    bool findTarget(TreeNode* root, int k, set<int>& seen) {
        if (root == NULL) {
            return false;
        }
        
        int required = k  - (root -> val);
        if (seen.find(required) != seen.end()) {
            return true;
        }
        
        seen.insert(root -> val);
        return findTarget(root -> left, k, seen) || findTarget(root -> right, k, seen);
    }
    
    bool findTarget(TreeNode* root, int k) {
        set<int> seen;
        return findTarget(root, k, seen);
    }
};
