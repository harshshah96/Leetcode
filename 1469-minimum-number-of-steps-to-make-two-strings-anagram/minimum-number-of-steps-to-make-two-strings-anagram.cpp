static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int minSteps(string s, string t) {
        int  n=s.length();

        unordered_map<char, int> mp;

        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }
        for(int i=0; i<n; i++){
            if(mp[t[i]]>0) mp[t[i]]--;
            if(mp[t[i]]==0) mp.erase(t[i]);
        }
        int ans=0;
        for(auto ele: mp){
            ans+=ele.second;

        }

        return ans;


        
    }
};