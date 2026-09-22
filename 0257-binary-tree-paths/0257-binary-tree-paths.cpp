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
private:
    void dfs(TreeNode* root, string currentPath, vector<string>& result) {
        if (!root) return;

        // Append current node value
        currentPath += to_string(root->val);

        // If leaf node, save the path
        if (!root->left && !root->right) {
            result.push_back(currentPath);
            return;
        }

        // Add arrow and recurse left/right
        currentPath += "->";
        dfs(root->left, currentPath, result);
        dfs(root->right, currentPath, result);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        dfs(root, "", result);
        return result;
    }
};