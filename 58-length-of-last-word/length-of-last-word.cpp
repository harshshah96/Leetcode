static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int i=n-1;
        while(i>=0 && s[i]==' ') i--;
        int count=0;
        while(i>=0 && s[i]!=' '){
            count++;
            i--;
        }
        return count;

    }
};