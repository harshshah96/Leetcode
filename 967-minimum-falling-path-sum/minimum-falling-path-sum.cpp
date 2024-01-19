class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        // Initialize the last row of dp with values from the matrix
        for (int i = 0; i < n; i++) {
            dp[n - 1][i] = matrix[n - 1][i];
        }

        // Build the dp array from bottom to top
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int left = (j > 0) ? dp[i + 1][j - 1] : INT_MAX;
                int right = (j < n - 1) ? dp[i + 1][j + 1] : INT_MAX;
                int down = dp[i + 1][j];

                dp[i][j] = matrix[i][j] + min({left, right, down});
            }
        }

        // Find the minimum value in the first row of dp
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[0][i]);
        }

        return ans;
    }
};
