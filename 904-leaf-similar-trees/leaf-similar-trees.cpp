static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    void dfs(TreeNode* root, vector<int> &a){
        if(root==NULL) return;

        if(root->left==NULL && root->right==NULL){
            a.push_back(root->val);
            return;
        } 
        if(root->left) dfs(root->left,a);
        if(root->right) dfs(root->right, a);
        
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a1;
        vector<int> a2;

        dfs(root1,a1);
        dfs(root2,a2);

        return (a1==a2);
        
    }
};