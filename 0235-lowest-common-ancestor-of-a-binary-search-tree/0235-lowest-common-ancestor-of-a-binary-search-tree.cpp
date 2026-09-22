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
        TreeNode* current = root;

        while (current) {
            // If both p and q are greater than current, LCA lies in the right subtree
            if (p->val > current->val && q->val > current->val) {
                current = current->right;
            }
            // If both p and q are smaller than current, LCA lies in the left subtree
            else if (p->val < current->val && q->val < current->val) {
                current = current->left;
            }
            // Split point found (or current is equal to p or q), which is the LCA
            else {
                return current;
            }
        }

        return nullptr;
    }
};