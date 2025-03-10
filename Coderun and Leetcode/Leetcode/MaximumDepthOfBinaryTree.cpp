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
    int maxDepthImpl(TreeNode* root, int depth){
        if(root == nullptr) return depth;
        return std::max(maxDepthImpl(root->left,depth+1), maxDepthImpl(root->right,depth+1));
    }

    int maxDepth(TreeNode* root) {
        return maxDepthImpl(root,0);
    }
};