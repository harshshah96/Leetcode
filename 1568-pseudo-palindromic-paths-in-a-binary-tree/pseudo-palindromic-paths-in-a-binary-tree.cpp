static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int ans;
    void solve(TreeNode* root, vector<int> &temp){
        if(root==NULL) return;
        temp[root->val]++;
        if(root->left==NULL && root->right==NULL){
            int odd=0;
            for(int i=0; i<10; i++){
                if(temp[i]%2==1) odd++;
            }

            if(odd<=1)ans++;  
            temp[root->val]--;
            return;  
        }
        solve(root->left,temp);
        solve(root->right, temp);
        temp[root->val]--;

        return;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        ans=0;
        vector<int> temp(10,0);
        solve(root, temp);
        
        return ans;
    }
};