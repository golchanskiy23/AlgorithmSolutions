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
    int depthImpl(TreeNode* root, int depth){
        if(root == nullptr) return depth;
        return std::max(depthImpl(root->left, depth+1), depthImpl(root->right, depth+1));
    }

    void impl(TreeNode* root, int currDepth){
        if(root == nullptr) return;
        impl(root->left, currDepth+1);
        tmp[currDepth].first += root->val;
        tmp[currDepth].second++;
        impl(root->right, currDepth+1);
    }

    vector<double> averageOfLevels(TreeNode* root) { 
        int n =  depthImpl(root, 0); 
        v.resize(n);
        tmp.resize(n);
        impl(root, 0);
        for(int i = 0; i < tmp.size(); ++i){
            v[i] = ((tmp[i].first*1.0)/tmp[i].second);
        }
        return v;
    }

private:
    std::vector<pair<long long, long long>> tmp;
    std::vector<double> v;

};