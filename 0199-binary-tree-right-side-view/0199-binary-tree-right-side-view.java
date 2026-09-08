import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        dfs(root, 0, result);
        return result;
    }

    private void dfs(TreeNode node, int depth, List<Integer> result) {
        if (node == null) return;

        // If visiting this depth level for the first time, add the node
        if (depth == result.size()) {
            result.add(node.val);
        }

        // Prioritize right child first to capture the rightmost nodes
        dfs(node.right, depth + 1, result);
        dfs(node.left, depth + 1, result);
    }
}