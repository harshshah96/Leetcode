static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    bool isPalindrome(string &a){
        int n=a.length();
        int i=0;
        while(i<=n/2){
            if(a[i]!=a[n-i-1]) return false;
            i++;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        int n=words.size();

        for(int i=0; i<n; ++i){
            string a=words[i];
            if(isPalindrome(a)) return a;
        }

        return "";
        
    }
};