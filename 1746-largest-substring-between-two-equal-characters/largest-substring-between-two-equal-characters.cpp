static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n=s.length();
        int i=0;
        int ans=INT_MIN;
        while(i<n){
            int j = n-1;
            while(j<n and s[i]!=s[j]) j--;
            if(j<n){
                ans=max(ans,j-i-1);
            }
            i++;
        }

        return ans == INT_MIN ? -1 : ans ;
        
    }
};