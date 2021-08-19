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
    int cntGoodNodes(TreeNode* root, int maxSoFar) {
        if (root == NULL) {
            return 0;
        }    
        
        if (root -> val >= maxSoFar) {
            return 1 + cntGoodNodes(root -> left, root -> val) + cntGoodNodes(root -> right, root -> val);    
        }
        else {
            return cntGoodNodes(root -> left, maxSoFar) + cntGoodNodes(root -> right, maxSoFar);    
        }
    }
    
    int goodNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        return 1 + cntGoodNodes(root -> left, root -> val) + cntGoodNodes(root -> right, root -> val);    
    }
};
