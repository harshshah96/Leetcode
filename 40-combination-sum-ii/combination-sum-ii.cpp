static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int target;

    void dfs(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& temp, int idx, int sum) {
        if (sum == target) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < candidates.size(); ++i) {
            // Skip duplicates
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Check if adding the current candidate exceeds the target
            if (sum + candidates[i] <= target) {
                temp.push_back(candidates[i]);
                dfs(candidates, ans, temp, i + 1, sum + candidates[i]);
                temp.pop_back();
            }else break;
        }

        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int tgt) {
        target = tgt;

        // Sort the candidates to handle duplicates properly
        sort(candidates.begin(), candidates.end());

        vector<int> temp;
        vector<vector<int>> ans;
        dfs(candidates, ans, temp, 0, 0);

        return ans;
    }
};
