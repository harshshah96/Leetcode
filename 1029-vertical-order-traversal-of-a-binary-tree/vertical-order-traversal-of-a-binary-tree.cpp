static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    void solve(TreeNode* root, map<int,map<int,multiset<int>>> &mp, int vertical , int level){
        if(root==NULL) return;
        
        mp[vertical][level].insert(root->val);
        // minvertical=min(vertical,minvertical);
        // maxvertical=max(vertical,maxvertical);

        solve(root->left, mp, vertical-1, level+1);
        solve(root->right, mp, vertical+1, level+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        vector<vector<int>> ans;
        // minLevel=INT_MAX;
        // maxLevel=INT_MIN;

        solve(root, mp, 0, 0 );

        for (auto& ele : mp) {
        vector<int> temp;
        for (auto& a : ele.second) {
            for (int num : a.second) {
                temp.push_back(num);
            }
        }
        ans.push_back(temp);
    }

        return ans;
        
    }
};