static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int level(TreeNode* root){
        if(root==NULL) return 0;
        return (1 + max(level(root->right), level(root->left)));
    }
    void preorder(TreeNode* root, vector<int> &ans, int level){
        if(root==NULL) return;
        ans[level]=root->val;
        preorder(root->right, ans,level+1);
        preorder(root->left, ans, level+1);
        
    }
    int findBottomLeftValue(TreeNode* root) {
        vector<int> result(level(root),0);
        preorder(root,result,0);

        return result[result.size()-1];
        
    }
};