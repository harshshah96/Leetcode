static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;

        if(!root)
        return result;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int count = q.size();
            vector<int> curr;

            for(int i=0;i<count;i++){
                TreeNode* node= q.front();
                q.pop();
                curr.push_back(node->val);
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);

            }
            result.push_back(curr);
        }
        for(int i=0; i<result.size()/2; i++){
            vector<int> temp;
            temp=result[i];
            result[i]=result[result.size()-i-1];
            result[result.size()-i-1]=temp;
        }
        root->left = nullptr, root->right = nullptr;
        return result;
    }
};