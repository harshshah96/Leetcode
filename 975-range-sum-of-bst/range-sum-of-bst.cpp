static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* a=q.front();
            if(a->val <=high && a->val >=low ) sum+=a->val;
            if(a->left) q.push(a->left);
            if(a->right) q.push(a->right);

            q.pop();

        }

        return sum;
    }
};