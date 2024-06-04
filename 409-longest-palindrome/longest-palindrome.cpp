static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();

        unordered_map<char,int> freq;

        for(int i = 0 ; i < n ; i++){
            freq[s[i]]++;
        }

        int max_odd = 0;
        int ans = 0;
        bool isOdd = false;

        for(auto ele : freq){
            if(ele.second%2 == 0){
                ans+=ele.second;
            }else{
                ans+=ele.second - 1;
                isOdd = true ; 
            }
        }

        return ans + isOdd;
        
    }
};