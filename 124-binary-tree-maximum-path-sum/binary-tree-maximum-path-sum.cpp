static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:

    int maxSum;
    int solve(TreeNode* root){
        if(root==NULL) return 0;

        int l= solve(root->left);
        root->left=NULL;
        int r= solve(root->right);
        root->right=NULL;

        int neche_wala_path = l+r+ root->val;
        int koi_ek_acha = max(l,r) + root->val;
        int koi_acha_nahin = root->val;

        maxSum = max(maxSum, max(neche_wala_path, max(koi_ek_acha, koi_acha_nahin )));

        return max(koi_ek_acha, koi_acha_nahin);
    }

    int maxPathSum(TreeNode* root) {
        
        maxSum=INT_MIN;

        solve(root);

        return maxSum;

    }
};