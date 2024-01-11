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
    int findMaxDiff(TreeNode* root, int mn, int mx){
        if(root==NULL){
            return abs(mx-mn);
        }
        mn=min(mn, root->val);
        mx=max(mx, root->val);

        return max(findMaxDiff(root->left, mn,mx) , findMaxDiff(root->right, mn, mx));

    }
    int maxAncestorDiff(TreeNode* root) {

        return findMaxDiff(root,root->val,root->val);
    }
};