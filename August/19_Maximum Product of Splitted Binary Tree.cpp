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
    const long long mod = 1e9 + 7;
    long long sumAllNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        long long sum = (root -> val) +
                        sumAllNodes(root -> left)+ 
                        sumAllNodes(root -> right);
        return sum;
    }
    
    long long findMaxProduct(TreeNode* root, long long &sum, long long &maximumProduct) {
        if (root == NULL) {
            return 0;
        }
        
        long long currSum = (root -> val) + 
                             findMaxProduct(root -> left, sum, maximumProduct) + 
                             findMaxProduct(root -> right, sum, maximumProduct);
        
        long long product = max(0LL, (sum - currSum)) * currSum;
        maximumProduct = max(maximumProduct, product);
        
        return currSum;
    }
    
    int maxProduct(TreeNode* root) {
        long long sum = sumAllNodes(root);
        long long maximumProduct = 0;
        findMaxProduct(root, sum, maximumProduct);  
        
        return maximumProduct % mod;
    }
};
