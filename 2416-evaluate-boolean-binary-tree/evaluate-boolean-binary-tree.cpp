class Solution {
public:
    // 0 --> FALSE
    // 1 --> TRUE
    // 2 --> OR
    // 3 --> AND

    bool evaluateTree(TreeNode* root) {
        if(root->val == 0)
            return false;
        else if(root->val == 1)
            return true;
        else if(root->val == 2)
            return evaluateTree(root->left) or evaluateTree(root->right);
        else return evaluateTree(root->left) and evaluateTree (root->right);
            

        return false; // will never be excecuted
    }
};