
class Solution {
public:

    void dfs(TreeNode* root, string &ans, string &temp){
        if(root->left==NULL && root->right==NULL){
            temp.push_back(char(root->val+97));
            string a=temp;
            reverse(a.begin(),a.end());
            cout<<a<<endl;
            if(ans==""){
                ans=a;
            }else{
                ans=min(ans,a);
            }
            temp.pop_back();
            return;
        }

        temp.push_back(char(root->val+97));
        if(root->left)dfs(root->left, ans, temp);
        if(root->right)dfs(root->right, ans, temp);
        temp.pop_back();
        
    }

    string smallestFromLeaf(TreeNode* root) {
        string ans="";
        string temp="";
        dfs(root, ans,temp);

        return ans;
        
    }
};