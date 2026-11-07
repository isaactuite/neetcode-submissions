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
    int maxDepth(TreeNode* root) {

        return dfs(root, 0);
    }

    int dfs(TreeNode* node, int h){
        if (!node) return h;
        h++;
        int hleft = dfs(node->left, h);
        int hright = dfs(node->right, h);

        h=max(h, max(hleft, hright));
        return h;
    }
};
