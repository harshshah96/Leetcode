static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.length();
        int m = t.length();
        int i = 0;
        int j = 0;

        while(i<n && j<m ){
            while(i<n && s[i]!=t[j]) i++;
            if(i==n) break;
            while(i<n && j<m && s[i]==t[j]){
                i++;
                j++;
            }
        }

        return (m-j);
    }
};