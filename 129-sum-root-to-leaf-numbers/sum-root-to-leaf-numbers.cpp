static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
    int helper(TreeNode* root,int sum,int &ans)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(root->left==NULL&&root->right==NULL)
        {
             sum=sum*10+root->val;
             ans+=sum;
             return sum/10;
        }
        sum=sum*10+root->val;
        helper(root->left,sum,ans);
        helper(root->right,sum,ans);
        return ans;
    }
public:
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
         if(root->left==NULL&&root->right==NULL)
        {
            return root->val;
        }
        int sum=0;
        int ans=0;
        return helper(root,sum,ans);
    }
};