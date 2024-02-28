static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int leftSideView(TreeNode* root) {
    vector<int> result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int level_size = q.size();
        for (int i = 0; i < level_size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (i == 0) {
                result.push_back(node->val); // Add the first node value to the result (left side view)
            }
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    return result[result.size()-1];
}
    int findBottomLeftValue(TreeNode* root) {
        return leftSideView(root);
        
    }
};