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
    void findRootToLeafPathSum(TreeNode* root, int targetSum, vector<int>& path, int sum, vector<vector<int>>& allPaths) {
        if (root == NULL) {
            return;
        }
        
        sum += root -> val;
        path.push_back(root -> val);
        
        if (sum == targetSum && root -> left == NULL && root -> right == NULL) {
            allPaths.push_back(path);
            path.pop_back();
            return;
        }    
        
        findRootToLeafPathSum(root -> left, targetSum, path, sum, allPaths);
        findRootToLeafPathSum(root -> right, targetSum, path, sum, allPaths);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> allPaths;
        vector<int> path;
        findRootToLeafPathSum(root, targetSum, path, 0, allPaths); 
        return allPaths;
    }
};
