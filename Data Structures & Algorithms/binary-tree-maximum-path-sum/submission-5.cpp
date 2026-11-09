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
    int maxPathSum(TreeNode* root) {
        pair<int, int> ans = search(root);
        return max(ans.first, ans.second);
    }
    pair<int, int> search(TreeNode* node){
        if (!node) return {-2000, -2000};

        pair<int, int> ans;

        pair<int, int> left = search(node->left);
        pair<int, int> right = search(node->right);
        int max_second = max(left.second, right.second);
        ans.second = max({left.second, right.second, node->val + max(0, left.first) + max(0, right.first)});

        ans.first = node->val + max({0, left.first, right.first});
        return ans;
    }
};
