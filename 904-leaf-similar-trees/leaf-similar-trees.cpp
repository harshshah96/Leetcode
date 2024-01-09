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
    void dfs(TreeNode* root, vector<int> &a){
        if(root==NULL) return;

        if(root->left==NULL && root->right==NULL) a.push_back(root->val);
        else{
            if(root->left) dfs(root->left,a);
            if(root->right) dfs(root->right, a);
        }
        
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a1;
        vector<int> a2;

        dfs(root1,a1);
        dfs(root2,a2);

        return (a1==a2);
        
    }
};