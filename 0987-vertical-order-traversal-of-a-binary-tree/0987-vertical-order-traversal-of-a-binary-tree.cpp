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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // map<col, map<row, multiset<val>>>
        map<int, map<int, multiset<int>>> nodes;
        
        // BFS queue storing {node, {col, row}}
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            TreeNode* temp = p.first;
            int col = p.second.first;
            int row = p.second.second;
            
            nodes[col][row].insert(temp->val);
            
            if (temp->left) {
                q.push({temp->left, {col - 1, row + 1}});
            }
            if (temp->right) {
                q.push({temp->right, {col + 1, row + 1}});
            }
        }
        
        vector<vector<int>> result;
        for (auto& [col, rows] : nodes) {
            vector<int> colNodes;
            for (auto& [row, values] : rows) {
                colNodes.insert(colNodes.end(), values.begin(), values.end());
            }
            result.push_back(colNodes);
        }
        
        return result;
    }
};