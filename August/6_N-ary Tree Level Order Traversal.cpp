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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> levelOrderTraversal;
        // Important to check
        if (root == NULL) {
            return levelOrderTraversal;
        }
        
        queue<Node*> q;
        levelOrderTraversal.push_back({root -> val});
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size(); 
            vector<int> level;
            
            for (int i = 0; i < n; i++) {
                Node* temp = q.front();
                q.pop();
                
                int total_children = temp -> children.size();
                for (int j = 0; j < total_children; j++) {
                    if (temp -> children[j] != NULL) {
                        q.push(temp -> children[j]);
                        level.push_back(temp -> children[j] -> val);
                    }
                }        
            }
            
            if (level.size())
                levelOrderTraversal.push_back(level);
        }
        
        return levelOrderTraversal;
    }
};
