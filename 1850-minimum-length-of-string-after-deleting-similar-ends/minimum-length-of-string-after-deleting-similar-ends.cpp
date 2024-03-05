static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int minimumLength(string s) {
        
        int n=s.length();
        // i --> left
        // j --> right
        int i = 0;
        int j = n - 1;

        while (i < j && s[i] == s[j]) {
            char ch = s[i];
            while (i <= j && s[i] == ch) {
                i++;
            }
            while (j >= i && s[j] == ch) {
                j--;
            }
        }

        return j - i + 1;
    }
};