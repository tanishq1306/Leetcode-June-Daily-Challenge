class Solution {
public:
    int curr = 0;
    unordered_map<int, int> indx;
    
    TreeNode* buildBinaryTree(vector<int>& preorder, int start, int end) {
        if (start > end) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[curr]);
        int pos = indx[preorder[curr]];
        ++curr;
        
        root -> left = buildBinaryTree(preorder, start, pos - 1);
        root -> right = buildBinaryTree(preorder, pos + 1, end);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        curr = 0;
        for (int i = 0; i < (int)inorder.size(); i++) {
            indx[inorder[i]] = i;
        }
        
        TreeNode *root = buildBinaryTree(preorder, 0, preorder.size() - 1);
        return root;
    }
};
