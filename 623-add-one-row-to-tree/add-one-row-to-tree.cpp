
class Solution {
public:

 void dfs(TreeNode* &root, int val, int depth, int currDepth){
        if(root==NULL) return;

        if(currDepth==depth){
            TreeNode* temp=new TreeNode(val);
            temp->left=root;
            root=temp;
            return;
        }

        if(currDepth == depth-1){
            TreeNode* temp1= new TreeNode(val);
            temp1->left = root->left;
            root->left=temp1;
            TreeNode* temp2= new TreeNode(val);
            temp2->right = root->right;
            root->right=temp2;
            return;
        }

        dfs(root->left, val, depth, currDepth+1);
        dfs(root->right, val, depth, currDepth+1);

    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        dfs(root, val, depth , 1);

        return root;

        
    }
};