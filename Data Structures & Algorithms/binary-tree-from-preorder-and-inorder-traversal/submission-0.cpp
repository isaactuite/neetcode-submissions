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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() or inorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        auto it = find(inorder.begin(), inorder.end(), preorder[0]);
        int mid = it-inorder.begin();
        vector<int> preorder_left(preorder.begin()+1, preorder.begin()+mid+1);
        vector<int> inorder_left(inorder.begin(), inorder.begin()+mid);

        root->left = buildTree(preorder_left, inorder_left);

        vector<int> preorder_right(preorder.begin()+mid+1, preorder.end());
        vector<int> inorder_right(inorder.begin()+mid+1, inorder.end());

        root->right = buildTree(preorder_right, inorder_right);

        
        return root;
    }
};
