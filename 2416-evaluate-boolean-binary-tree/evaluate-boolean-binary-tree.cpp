class Solution {
public:
    // 0 --> FALSE
    // 1 --> TRUE
    // 2 --> OR
    // 3 --> AND

    // bool helper(TreeNode* root) {
    //     if(root -> val == 0 || root -> val == 1) {
    //         return root -> val == 1; 
    //     } else if(root -> val == 2) {
    //         return helper(root -> left) || helper(root -> right);
    //     } else if(root -> val == 3) {
    //         return helper(root -> left) && helper(root -> right);
    //     } 

    //     return false;
    // }

    bool evaluateTree(TreeNode* root) {
       if(root->val == 1)
            return true;
        if(root->val == 0)
            return false;
        if(root->val == 2)
            return evaluateTree(root->left) or evaluateTree(root->right);
        
        if(root->val == 3)
            return evaluateTree(root->left) and evaluateTree (root->right);

        return true;
    }
};