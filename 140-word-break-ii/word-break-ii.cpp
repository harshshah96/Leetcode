static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return wordBreakHelper(s, 0, dict);
    }

private:
    vector<string> wordBreakHelper(string s, int i, unordered_set<string>& dict) {
        vector<string> ans;
        if (i == s.length())
            ans.push_back("");

        for (int j = i + 1; j <= s.length(); j++) {
            string prefix = s.substr(i, j - i);
            if (dict.count(prefix)) {
                vector<string> suffixes = wordBreakHelper(s, j, dict);
                for (string suffix : suffixes)
                    ans.push_back(prefix + (suffix.empty() ? "" : " ") + suffix);
            }
        }
        return ans;
    }
};