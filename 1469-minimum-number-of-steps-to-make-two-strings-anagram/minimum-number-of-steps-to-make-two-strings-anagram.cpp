static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int minSteps(string s, string t) {
        int occ[26] = {0};
        for (auto it : s) occ[it-'a'] ++;
        for (auto it : t) occ[it-'a']--;

        int res = 0;
        for (int i = 0; i < 26; i++) res += abs(occ[i]);

        return res / 2;
    }
};