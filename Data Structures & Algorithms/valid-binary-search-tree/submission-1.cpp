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
    bool isValidBST(TreeNode* root) {
        return validate(root, -100000000, 100000000);
    }

    bool validate(TreeNode* node, int min, int max){
        if (!node) return true;

        if (node->val <= min or node->val>=max){
            return false;
        }

        return validate(node->left, min, node->val) && validate(node->right, node->val, max);
    }
};
