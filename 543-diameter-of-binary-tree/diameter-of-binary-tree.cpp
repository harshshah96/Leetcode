static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    
    pair<int, int> calculateDiameterAndHeight(TreeNode* root) {
        if (root == nullptr) return {0, 0};

        auto leftData = calculateDiameterAndHeight(root->left);
        auto rightData = calculateDiameterAndHeight(root->right);

        int currentDiameter = max(leftData.second + rightData.second,max(leftData.first, rightData.first));
        int currentHeight = max(leftData.second, rightData.second) + 1;

        return {currentDiameter, currentHeight};
    }

    int diameterOfBinaryTree(TreeNode* root) {

        return calculateDiameterAndHeight(root).first;
    }
};