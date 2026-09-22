/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base Case: If root is null, or if root is one of p or q
        if (!root || root == p || root == q) {
            return root;
        }

        // Recurse on left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both subtrees returned non-null, current node is the LCA
        if (left && right) {
            return root;
        }

        // Otherwise, return whichever subtree found p or q (or null if neither)
        return left ? left : right;
    }
};