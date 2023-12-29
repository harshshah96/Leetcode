class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int len = jobDifficulty.size();
        if (len < d) {
            return -1;
        }
        int sum = accumulate(jobDifficulty.begin(), jobDifficulty.end(), 0);
        if (sum == 0) {
            return 0;
        }
        vector<vector<int>> memo(d + 1, vector<int>(len, 0));
        helper(jobDifficulty, d, 0, memo);
        
        return memo[d][0];
    }

private:
    void helper(vector<int>& jd, int daysLeft, int idx, vector<vector<int>>& memo) {
        int len = jd.size();
        if (memo[daysLeft][idx] != 0) {
            return;
        }
        if (daysLeft == 1) {
            int num = 0;
            for (int i = idx; i < len; i++) {
                num = max(num, jd[i]);
            }
            memo[daysLeft][idx] = num;
            return;
        }
        int maxDifficulty = jd[idx];
        // daysLeft--;
        int stop = len - idx - (daysLeft -1 ) + 1;

        // i=1 + (idx-1);

        int res = INT_MAX;
        for (int i = idx; i <= len - daysLeft; i++) {
            maxDifficulty = max(maxDifficulty, jd[i]);
            int other = memo[daysLeft-1][i+1];
            if (other == 0) {
                helper(jd, daysLeft-1, i+1, memo);
                other = memo[daysLeft-1][i+1];
            }
            res = min(res, other + maxDifficulty);   
        }
        memo[daysLeft][idx] = res;
    }
};