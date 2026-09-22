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
    int count = 0;
    int result = 0;

    void inorder(TreeNode* root, int k) {
        if (!root) return;

        // Traverse left subtree
        inorder(root->left, k);

        // Process current node
        count++;
        if (count == k) {
            result = root->val;
            return;
        }

        // Traverse right subtree only if we haven't found k yet
        if (count < k) {
            inorder(root->right, k);
        }
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
};