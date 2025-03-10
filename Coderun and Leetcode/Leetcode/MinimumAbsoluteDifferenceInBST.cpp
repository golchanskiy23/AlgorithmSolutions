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
    int getMinimumDifference(TreeNode* root) {
        std::stack<TreeNode*> stack;
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        int minDiff = INT_MAX;

        while (!stack.empty() || curr != nullptr) {
            while (curr != nullptr) {
                stack.push(curr);
                curr = curr->left;
            }

            curr = stack.top();
            stack.pop();

            if (prev != nullptr) {
                minDiff = std::min(minDiff, curr->val - prev->val);
            }

            prev = curr;
            curr = curr->right;
        }

        return minDiff;
    }
};
