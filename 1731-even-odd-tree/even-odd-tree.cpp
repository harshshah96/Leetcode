static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(root==NULL) return false;
        if(root->val % 2 == 0) return false;
        queue<TreeNode*> q;


        q.push(root); // level = 0
        int level=0;
        while(!q.empty()){
            int n=q.size();
            int prev=q.front()->val;
            for(int i=0; i<n; i++){
                TreeNode* temp = q.front();
                if(i>=1) {
                    if(level%2==0){//even
                        if(temp->val <=prev) return false;
                    }else{
                        if(temp->val >= prev) return false;
                    }

                    prev=temp->val;
                }
                if(level%2==0 && temp->val % 2 ==0 || level %2 !=0 && temp->val % 2 !=0) return false;
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                cout<< temp->val<<" ";
            }
            cout<<endl;
            level++;
        }

        return true;
        
    }
};