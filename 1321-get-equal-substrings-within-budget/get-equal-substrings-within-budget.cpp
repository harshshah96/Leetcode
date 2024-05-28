class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int start = 0;
        int currCost = 0;
        int maxLen= 0;

        for (int end = 0; end < n; ++end) {
            currCost += abs(s[end] - t[end]);

            while (currCost > maxCost) {
                currCost -= abs(s[start] - t[start]);
                ++start;
            }

            maxLen= max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};