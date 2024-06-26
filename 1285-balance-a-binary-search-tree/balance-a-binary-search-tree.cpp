static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    TreeNode* helper(vector<int>& nums, int lo, int hi){
        if(lo>hi) return NULL;
        int mid = lo + (hi-lo)/2;
        TreeNode* root= new TreeNode(nums[mid]);
        root->left = helper(nums,lo,mid-1);
        root->right =helper(nums,mid+1,hi);
        return root;
    }
    void inorder(TreeNode* root , vector <int> & ans){
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector <int> ans;
        inorder(root, ans);
        int n=ans.size();
        return helper(ans,0,n-1);
    }
};