static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
       unordered_map<char,int> mp;
       int n= s.length();
       int ans=INT_MIN;

       for(int i=0; i<n; i++){
           if(mp.find(s[i])!=mp.end()){
               ans=max(ans,abs(i-mp[s[i]]-1));
           }else{
               mp[s[i]]= i;
           }
       }

       return ans == INT_MIN ? -1 : ans;

    }
};